// wkbre - WK (Battles) recreated game engine
// Copyright (C) 2015-2016 Adrien Geets
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include "../global.h"

#define RANDZEROTOONE ((rand()%32768)/32768.0f)

struct ValueUnknown : public CValue
{
	valuetype get(SequenceEnv *env)
		{ferr("Cannot determinate a value of unknown type."); return 0;}
};

struct ValueConstant : public CValue
{
	valuetype c;
	ValueConstant(valuetype a) {c = a;}
	valuetype get(SequenceEnv *env) {return c;}
};

struct ValueItemValue : public CValue
{
	int index; CFinder *finder;
	ValueItemValue(int a, CFinder *b) : index(a), finder(b) {}
	valuetype get(SequenceEnv *env)
	{
		finder->begin(env);
		GameObject *o = finder->getnext();
		if(!o) return 0;
		return o->getItem(index);
	}
};

struct ValueNumObjects : public CValue
{
	CFinder *f;
	ValueNumObjects(CFinder *a) : f(a) {}
	valuetype get(SequenceEnv *env)
	{
		f->begin(env);
		int i = 0;
		while(f->getnext()) i++;
		return i;
	}
};

// NOTE: Only looks after one object in the finder!
struct ValueEquationResult : public CValue
{
	uint x; CFinder *f;
	ValueEquationResult(int a, CFinder *b) : x(a), f(b) {}
	valuetype get(SequenceEnv *env)
	{
		SequenceEnv n;
		env->copyAll(&n);
		GameObject *o = f->getfirst(env);
		if(o) n.self = o;
		else n.self.deref();
		return equation[x]->get(&n);
	}
};

struct ValueObjectClass : public CValue
{
	uint c; CFinder *f;
	ValueObjectClass(uint a, CFinder *b) : c(a), f(b) {}
	valuetype get(SequenceEnv *env)
	{
		f->begin(env);
		GameObject *o = f->getnext();
		if(!o) return 0;
		do {
			if(o->objdef->type != c)
				return 0;
		} while(o = f->getnext());
		return 1;
	}
};

struct ValueObjectType : public CValue
{
	CObjectDefinition *c; CFinder *f;
	ValueObjectType(CObjectDefinition *a, CFinder *b) : c(a), f(b) {}
	valuetype get(SequenceEnv *env)
	{
		f->begin(env);
		GameObject *o = f->getnext();
		if(!o) return 0;
		do {
			if(o->objdef != c)
				return 0;
		} while(o = f->getnext());
		return 1;
	}
};

struct ValueValueTagInterpretation : public CValue
{
	int t; CFinder *f;
	ValueValueTagInterpretation(int a, CFinder *b) : t(a), f(b) {}
	valuetype get(SequenceEnv *env)
	{
		SequenceEnv c; goref z;
		GameObject *o = f->getfirst(env);
		if(!o) goto deftag;

		env->copyAll(&c);
		c.self = o;
		if(o->objdef->valueTagInterpret[t])
			return o->objdef->valueTagInterpret[t]->get(&c);

deftag:		if(defValueTag[t])
			return defValueTag[t]->get(&c);
		return 0;
	}
};

struct ValueObjectID : public CValue
{
	CFinder *f;
	ValueObjectID(CFinder *a) : f(a) {}
	valuetype get(SequenceEnv *env)
	{
		GameObject *o = f->getfirst(env);	// Only first object.
		if(o)
			return o->id;
		else
			return 0;
	}
};

struct ValueIsSubsetOf : public CValue
{
	CFinder *x, *y;
	ValueIsSubsetOf(CFinder *a, CFinder *b) : x(a), y(b) {}
	valuetype get(SequenceEnv *env)
	{
		GrowList<GameObject*> a, b; GameObject *o;
		x->begin(env); y->begin(env);
		while(o = x->getnext()) a.add(o);
		while(o = y->getnext()) b.add(o);

		// OGE returns 0 when the first finder returns 0 objects.
		if(!a.len) return 0;

		for(uint i = 0; i < a.len; i++)
		{
			for(uint j = 0; j < b.len; j++)
				if(a[i] == b[j])
					goto isoc;
			return 0;
		isoc:	;
		}
		return 1;
	}
};

struct ValueWaterBeneath : public CValue
{
	CFinder *f;
	ValueWaterBeneath(CFinder *a) : f(a) {}
	valuetype get(SequenceEnv *env)
	{
		// TODO: Rewrite when water implemented.
		return 0;
	}
};

// DEFINED_VALUE will use ValueConstant.

CValue *ReadValue(char ***wpnt)
{
	char **word = *wpnt; CValue *cv;
	switch(stfind_cs(VALUE_str, VALUE_NUM, word[0]))
	{
		case VALUE_CONSTANT:
			cv = new ValueConstant(atof(word[1]));
			*wpnt += 2; return cv;
		case VALUE_DEFINED_VALUE:
			cv = new ValueConstant(defvalue[strDefValue.find(word[1])]);
			*wpnt += 2; return cv;
		case VALUE_ITEM_VALUE:
			{int x = strItems.find(word[1]);
			if(x == -1) x = 0; //mustbefound(x); // TODO: WARNING
			*wpnt += 2;
			return new ValueItemValue(x, ReadFinder(wpnt));}
		case VALUE_NUM_OBJECTS:
			*wpnt += 1;
			return new ValueNumObjects(ReadFinder(wpnt));
		case VALUE_EQUATION_RESULT:
			{int x = strEquation.find(word[1]); mustbefound(x);
			*wpnt += 2;
			return new ValueEquationResult(x, ReadFinder(wpnt));}
		case VALUE_OBJECT_CLASS:
			{int d = stfind_cs(CLASS_str, CLASS_NUM, word[1]); mustbefound(d);
			*wpnt += 2; return new ValueObjectClass(d, ReadFinder(wpnt));}
		case VALUE_OBJECT_TYPE:
			{int d = FindObjDef(stfind_cs(CLASS_str, CLASS_NUM, word[1]), word[2]);
			mustbefound(d); *wpnt += 3;
			return new ValueObjectType(&objdef[d], ReadFinder(wpnt));}
		case VALUE_OBJECT_ID:
			{*wpnt += 1;
			return new ValueObjectID(ReadFinder(wpnt));}
		case VALUE_IS_SUBSET_OF:
			{*wpnt += 1;
			CFinder *f = ReadFinder(wpnt);
			return new ValueIsSubsetOf(f, ReadFinder(wpnt));}
		case VALUE_WATER_BENEATH:
			{*wpnt += 1;
			return new ValueWaterBeneath(ReadFinder(wpnt));}
	}
	//ferr("Unknown value type."); return 0;
	*wpnt += 1;
	return new ValueUnknown();
};

struct Enode1V : public CValue
{
	CValue *x;
	Enode1V(CValue *a) {x = a;}
};

struct Enode2V : public CValue
{
	CValue *x, *y;
	Enode2V(CValue *a, CValue *b) {x = a; y = b;}
};

struct Enode3V : public CValue
{
	CValue *x, *y, *z;
	Enode3V(CValue *a, CValue *b, CValue *c) {x = a; y = b; z = c;}
};

struct EnodeAbsoluteValue : public Enode1V
{
	// using Enode1V::Enode1V; (only works in C++11)
	EnodeAbsoluteValue(CValue *a) : Enode1V(a) {}
	valuetype get(SequenceEnv *env) {valuetype a = x->get(env); if(a>=0) return a; return -a;}
};

struct EnodeNot : public Enode1V
{
	EnodeNot(CValue *a) : Enode1V(a) {}
	valuetype get(SequenceEnv *env) {return !stpo(x->get(env));}
};

struct EnodeIsZero : public Enode1V
{
	EnodeIsZero(CValue *a) : Enode1V(a) {}
	valuetype get(SequenceEnv *env) {return x->get(env) == 0;}
};

// NOTE: strictly or not?
// FOUND: yes, it is strictly
struct EnodeIsPositive : public Enode1V
{
	EnodeIsPositive(CValue *a) : Enode1V(a) {}
	valuetype get(SequenceEnv *env) {return x->get(env) > 0;}
};

// NOTE: strictly or not?
// IS_POSITIVE yes, but IS_NEGATIVE?
struct EnodeIsNegative : public Enode1V
{
	EnodeIsNegative(CValue *a) : Enode1V(a) {}
	valuetype get(SequenceEnv *env) {return x->get(env) < 0;}
};

struct EnodeRandomUpTo : public Enode1V
{
	EnodeRandomUpTo(CValue *a) : Enode1V(a) {}
	valuetype get(SequenceEnv *env) {return RANDZEROTOONE * x->get(env);}
};

struct EnodeAddition : public Enode2V
{
	EnodeAddition(CValue *a, CValue *b) : Enode2V(a, b) {}
	valuetype get(SequenceEnv *env) {return x->get(env) + y->get(env);}
};

struct EnodeSubtraction : public Enode2V
{
	EnodeSubtraction(CValue *a, CValue *b) : Enode2V(a, b) {}
	valuetype get(SequenceEnv *env) {return x->get(env) - y->get(env);}
};

struct EnodeMultiplication : public Enode2V
{
	EnodeMultiplication(CValue *a, CValue *b) : Enode2V(a, b) {}
	valuetype get(SequenceEnv *env) {return x->get(env) * y->get(env);}
};

struct EnodeDivision : public Enode2V
{
	EnodeDivision(CValue *a, CValue *b) : Enode2V(a, b) {}
	valuetype get(SequenceEnv *env) {return x->get(env) / y->get(env);}
};

struct EnodeAnd : public Enode2V
{
	EnodeAnd(CValue *a, CValue *b) : Enode2V(a, b) {}
	valuetype get(SequenceEnv *env) {return stpo(x->get(env)) && stpo(y->get(env));}
};

struct EnodeOr : public Enode2V
{
	EnodeOr(CValue *a, CValue *b) : Enode2V(a, b) {}
	valuetype get(SequenceEnv *env) {return stpo(x->get(env)) || stpo(y->get(env));}
};

struct EnodeEquals : public Enode2V
{
	EnodeEquals(CValue *a, CValue *b) : Enode2V(a, b) {}
	valuetype get(SequenceEnv *env) {return x->get(env) == y->get(env);}
};

struct EnodeLessThan : public Enode2V
{
	EnodeLessThan(CValue *a, CValue *b) : Enode2V(a, b) {}
	valuetype get(SequenceEnv *env) {return x->get(env) < y->get(env);}
};

struct EnodeLessThanOrEqualTo : public Enode2V
{
	EnodeLessThanOrEqualTo(CValue *a, CValue *b) : Enode2V(a, b) {}
	valuetype get(SequenceEnv *env) {return x->get(env) <= y->get(env);}
};

struct EnodeGreaterThan : public Enode2V
{
	EnodeGreaterThan(CValue *a, CValue *b) : Enode2V(a, b) {}
	valuetype get(SequenceEnv *env) {return x->get(env) > y->get(env);}
};

struct EnodeGreaterThanOrEqualTo : public Enode2V
{
	EnodeGreaterThanOrEqualTo(CValue *a, CValue *b) : Enode2V(a, b) {}
	valuetype get(SequenceEnv *env) {return x->get(env) >= y->get(env);}
};

struct EnodeMin : public Enode2V
{
	EnodeMin(CValue *a, CValue *b) : Enode2V(a, b) {}
	valuetype get(SequenceEnv *env)
	{
		valuetype a = x->get(env), b = y->get(env);
		return (a<b)?a:b;
	}
};

struct EnodeMax : public Enode2V
{
	EnodeMax(CValue *a, CValue *b) : Enode2V(a, b) {}
	valuetype get(SequenceEnv *env)
	{
		valuetype a = x->get(env), b = y->get(env);
		return (a>b)?a:b;
	}
};

struct EnodeRandomInteger : public Enode2V
{
	EnodeRandomInteger(CValue *a, CValue *b) : Enode2V(a, b) {}
	valuetype get(SequenceEnv *env)
	{
		valuetype a = x->get(env), b = y->get(env);
		//if(a == b) return (int)a;
		return (rand()%(int)(b-a+1)) + (int)a;
	}
};

struct EnodeRandomRange : public Enode2V
{
	EnodeRandomRange(CValue *a, CValue *b) : Enode2V(a, b) {}
	valuetype get(SequenceEnv *env)
	{
		valuetype a = x->get(env);
		return RANDZEROTOONE * (y->get(env) - a) + a;
	}
};

struct EnodeIfThenElse : public Enode3V
{
	EnodeIfThenElse(CValue *a, CValue *b, CValue *c) : Enode3V(a, b, c) {}
	valuetype get(SequenceEnv *env)
	{
		if(stpo(x->get(env)))
			return y->get(env);
		else
			return z->get(env);
	}
};

struct EnodeIsBetween : public Enode3V
{
	EnodeIsBetween(CValue *a, CValue *b, CValue *c) : Enode3V(a, b, c) {}
	valuetype get(SequenceEnv *env)
	{
		// NOTE: x included in ]y;z[ (y and z not included)
		//	 y must be < z, otherwise it doesn't work
		valuetype a = x->get(env);
		return (a > y->get(env)) && (a < z->get(env));
	}
};

CValue *ReadEqLine(char **pntfp)
{
	char wwl[MAX_LINE_SIZE], *word[MAX_WORDS_IN_LINE]; int nwords;
	CValue *cv, *u, *v, *w;
	while(**pntfp)
	{
		*pntfp = GetLine(*pntfp, wwl);
		nwords = GetWords(wwl, word);
		if(!nwords) continue;
		if(!strcmp(word[0], "END_EQUATION"))
			return 0;
		if(nwords < 2) ferr("You need to put something after ENODE!");
		switch(stfind_cs(ENODE_str, ENODE_NUM, word[1]))
		{
			case ENODE_ABSOLUTE_VALUE:
				return new EnodeAbsoluteValue(ReadEqLine(pntfp));
			case ENODE_RANDOM_UP_TO:
				return new EnodeRandomUpTo(ReadEqLine(pntfp));
			case ENODE_ADDITION:
				u = ReadEqLine(pntfp); v = ReadEqLine(pntfp);
				return new EnodeAddition(u, v);
			case ENODE_SUBTRACTION:
				u = ReadEqLine(pntfp); v = ReadEqLine(pntfp);
				return new EnodeSubtraction(u, v);
			case ENODE_MULTIPLICATION:
				u = ReadEqLine(pntfp); v = ReadEqLine(pntfp);
				return new EnodeMultiplication(u, v);
			case ENODE_DIVISION:
				u = ReadEqLine(pntfp); v = ReadEqLine(pntfp);
				return new EnodeDivision(u, v);

			case ENODE_NOT:
				return new EnodeNot(ReadEqLine(pntfp));
			case ENODE_IS_ZERO:
				return new EnodeIsZero(ReadEqLine(pntfp));
			case ENODE_IS_POSITIVE:
				return new EnodeIsPositive(ReadEqLine(pntfp));
			case ENODE_IS_NEGATIVE:
				return new EnodeIsNegative(ReadEqLine(pntfp));
			case ENODE_AND:
				u = ReadEqLine(pntfp); v = ReadEqLine(pntfp);
				return new EnodeAnd(u, v);
			case ENODE_OR:
				u = ReadEqLine(pntfp); v = ReadEqLine(pntfp);
				return new EnodeOr(u, v);
			case ENODE_EQUALS:
				u = ReadEqLine(pntfp); v = ReadEqLine(pntfp);
				return new EnodeEquals(u, v);
			case ENODE_MIN:
				u = ReadEqLine(pntfp); v = ReadEqLine(pntfp);
				return new EnodeMin(u, v);
			case ENODE_MAX:
				u = ReadEqLine(pntfp); v = ReadEqLine(pntfp);
				return new EnodeMax(u, v);
			case ENODE_RANDOM_INTEGER:
				u = ReadEqLine(pntfp); v = ReadEqLine(pntfp);
				return new EnodeRandomInteger(u, v);
			case ENODE_RANDOM_RANGE:
				u = ReadEqLine(pntfp); v = ReadEqLine(pntfp);
				return new EnodeRandomRange(u, v);
			case ENODE_LESS_THAN:
				u = ReadEqLine(pntfp); v = ReadEqLine(pntfp);
				return new EnodeLessThan(u, v);
			case ENODE_GREATER_THAN:
				u = ReadEqLine(pntfp); v = ReadEqLine(pntfp);
				return new EnodeGreaterThan(u, v);
			case ENODE_LESS_THAN_OR_EQUAL_TO:
				u = ReadEqLine(pntfp); v = ReadEqLine(pntfp);
				return new EnodeLessThanOrEqualTo(u, v);
			case ENODE_GREATER_THAN_OR_EQUAL_TO:
				u = ReadEqLine(pntfp); v = ReadEqLine(pntfp);
				return new EnodeGreaterThanOrEqualTo(u, v);
			case ENODE_IF_THEN_ELSE:
				u = ReadEqLine(pntfp); v = ReadEqLine(pntfp); w = ReadEqLine(pntfp);
				return new EnodeIfThenElse(u, v, w);
			case ENODE_IS_BETWEEN:
				u = ReadEqLine(pntfp); v = ReadEqLine(pntfp); w = ReadEqLine(pntfp);
				return new EnodeIsBetween(u, v, w);
		}
		char **pw = &word[1];
		return ReadValue(&pw);
	}
	ferr("UEOF"); return 0;
}