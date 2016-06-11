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

#include "..\global.h"

GrowStringList alf;

GrowStringList strItems;
GrowStringList strDefValue; GrowList<valuetype> defvalue;
GrowStringList strAppearTag;
GrowStringList strDiplomaticStatus;
GrowStringList strObjDef; GrowList<int> typeObjDef; GrowList<GrowStringList*> pstObjDef;
GrowStringList strAssociateCat, strAlias;
GrowStringList strOrder, strTask; COrder *gsorder; CTask *gstask;
GrowStringList strActionSeq; ActionSeq **actionseq;
GrowStringList strFinderDef; CFinder **finderdef;
GrowStringList strEquation; CValue **equation;
GrowStringList strTypeTag;
GrowStringList strObjCreation; CObjectCreation *cobjcr;
GrowStringList strGameEvent;
GrowStringList strReaction; CReaction *reaction;
GrowStringList strPRTrigger; CPRTrigger *prtrigger;
GrowStringList strValueTag; CValue **defValueTag;
GrowStringList strOrderAssign; COrderAssignment *orderAssign;
GrowStringList strCommand; CCommand *gscommand;

CObjectDefinition *objdef;
DynList<goref> *alias;
GrowStringList glone;

char *SkipClass(char *fp, char *end)
{
	char wwl[MAX_LINE_SIZE], *word[MAX_WORDS_IN_LINE]; int nwords;
	while(*fp)
	{
		fp = GetLine(fp, wwl);
		nwords = GetWords(wwl, word);
		if(!nwords) continue;
		if(!strcmp(word[0], end)) return fp;
	}
	ferr("UEOF"); return fp;
}

char *LookObjDefP0(char *fp, char **fline, int type)
{
	char wwl[MAX_LINE_SIZE], *word[MAX_WORDS_IN_LINE]; int nwords;

	if(FindObjDef(type, fline[1]) != -1)
	{
		char es[64] = "END_\0";
		strcat(es, CLASS_str[type]);
		return SkipClass(fp, es);
	}
	strObjDef.add(fline[1]);
	typeObjDef.add(type);

	//GrowStringList *gl = new GrowStringList();
	//gl->add("Default");
	GrowStringList *gl = &glone;
	while(*fp)
	{
		fp = GetLine(fp, wwl);
		nwords = GetWords(wwl, word);
		if(!nwords) continue;
		if(*(int*)word[0] == '_DNE')
		{
			/*printf("[DBG] gl->len = %i\n", gl->len);*/
			//if(!gl->has("Default")) {gl->add("Default"); printf("%s \"%s\": %i subtypes\n", fline[0], fline[1], gl->len);}
			pstObjDef.add(gl);
			return fp;
		}
		if(!strcmp(word[0], "PHYSICAL_SUBTYPE"))
		{
			if(gl == &glone)
			{
				if(strcmp(word[1], "Default"))
				{
					gl = new GrowStringList();
					gl->add("Default");
					gl->add(word[1]);
				}
			}
			else	if(!gl->has(word[1])) gl->add(word[1]);
			fp = SkipClass(fp, "END_PHYSICAL_SUBTYPE");
		}
		if(!strcmp(word[0], "MOVEMENT_BAND"))
			fp = SkipClass(fp, "END_MOVEMENT_BAND");
	}
	ferr("UEOF"); return fp;
}

char *LookDiplomaticLadderP0(char *fp)
{
	char wwl[MAX_LINE_SIZE], *word[MAX_WORDS_IN_LINE]; int nwords;
	while(*fp)
	{
		fp = GetLine(fp, wwl);
		nwords = GetWords(wwl, word);
		if(!nwords) continue;
		if(!strcmp(word[0], "END_DIPLOMATIC_LADDER"))
			return fp;
		if(!strcmp(word[0], "STATUS"))
			strDiplomaticStatus.add(word[1]);
	}
	ferr("UEOF"); return fp;
}

void LookAtFile(char *filename, int ipass)
{
	FILE *file; char *fcnt, *fp; int fsize, nwords; WIN32_FIND_DATA wfd; HANDLE hfind;
	char line[MAX_LINE_SIZE], wwl[MAX_LINE_SIZE], *word[MAX_WORDS_IN_LINE], sarg[MAX_LINE_SIZE];

	alf.add(filename);

	LoadFile(filename, &fcnt, &fsize, 1);

	fcnt[fsize] = 0;
	fp = fcnt;
	while(*fp)
	{
		fp = GetLine(fp, line);
		//printf("--> %s\n", line);
		//printf("%i\r", ++gline);
		strcpy(wwl, line);
		nwords = GetWords(wwl, word);
		if(!nwords) continue;

		if(nwords >= 2)
		if(!strcmp(word[0], "LINK_GAME_SET"))
		{
			char *star = strchr(word[1], '*');
			if(!star)
			{
				char nlaf[512] = "Warrior Kings Game Set\\\0";
				strcat(nlaf, word[1]);
				if(!alf.has(nlaf))
					LookAtFile(nlaf, ipass);
			}
			/*else
			{
				hfind = FindFirstFile(word[1], &wfd);
				if(hfind == INVALID_HANDLE_VALUE)
					continue;
				do {
					if(!alf.has(wfd.cFileName))
						LookAtFile(wfd.cFileName, ipass);
				} while(FindNextFile(hfind, &wfd));
				FindClose(hfind);
			}*/
			else if(star[1] == '.')
			{
				//printf("Multiple includes: \"%s\"\n", word[1]);
				*star = 0;
				char dirstr[512] = "Warrior Kings Game Set\\\0";
				strcat(dirstr, word[1]);
				//printf("dirstr = %s\n", dirstr);
				GrowStringList *sl = ListFiles(dirstr);
				for(int i = 0; i < sl->len; i++)
				{
					//printf(" - %s\n", sl->getdp(i));
					if(!_stricmp(strrchr(sl->getdp(i), '.'), star+1))
					{
						char dpff[512];
						strcpy(dpff, dirstr);
						strcat(dpff, sl->getdp(i));
						//printf(" O %s\n", dpff);
						if(!alf.has(dpff))
							LookAtFile(dpff, ipass);
					}
				}
				delete sl;
			}
			continue;
		}

/*******************************************************************/

switch(ipass)
{
	int z;
	// The first pass "converts strings to numbers".
	case 0:
		switch(z = stfind_cs(CLASS_str, CLASS_NUM, word[0]))
		{
			/*case CLASS_VERSION:
			case CLASS_NAME:
			case CLASS_CREATED_BY:
			case CLASS_FILE_TYPE:
				break;*/
			case CLASS_DECLARE_ITEM:
				strItems.add(word[1]); break;
			case CLASS_DEFINE_VALUE:
				strDefValue.add(word[1]);
				defvalue.add(atov(word[2])); break;
			case CLASS_APPEARANCE_TAG:
				strAppearTag.add(word[1]); break;
			case CLASS_USER:
			case CLASS_LEVEL:
			case CLASS_PLAYER:
			case CLASS_BUILDING:
			case CLASS_CHARACTER:
			//
			case CLASS_CITY:
			case CLASS_TOWN:
			case CLASS_CONTAINER:
			case CLASS_FORMATION:
			case CLASS_MARKER:
			case CLASS_MISSILE:
			case CLASS_PROP:
			case CLASS_ARMY:
			case CLASS_TERRAIN_ZONE:
				fp = LookObjDefP0(fp, word, z); break;
			case CLASS_CHARACTER_LADDER:
				fp = SkipClass(fp, "END_CHARACTER_LADDER"); break;
			case CLASS_DECLARE_ALIAS:
				strAlias.add(word[1]); break;
			case CLASS_ASSOCIATE_CATEGORY:
			case CLASS_DECLARE_ASSOCIATE_CATEGORY:
				strAssociateCat.add(word[1]); break;
			case CLASS_ORDER:
				strOrder.add(word[1]);
				fp = SkipClass(fp, "END_ORDER"); break;
			case CLASS_TASK:
				strTask.add(word[1]);
				fp = SkipClass(fp, "END_TASK"); break;
			case CLASS_REACTION:
				strReaction.add(word[1]);
				fp = SkipClass(fp, "END_REACTION"); break;
			case CLASS_DIPLOMATIC_LADDER:
				fp = LookDiplomaticLadderP0(fp); break;
			case CLASS_EQUATION:
			case CLASS_INDEV_EQUATION:
				strEquation.add(word[1]);
				fp = SkipClass(fp, "END_EQUATION"); break;
			case CLASS_OBJECT_FINDER_DEFINITION:
			case CLASS_INDEV_OBJECT_FINDER_DEFINITION:
				strFinderDef.add(word[1]);
				fp = SkipClass(fp, "END_OBJECT_FINDER_DEFINITION"); break;
			case CLASS_ACTION_SEQUENCE:
			case CLASS_INDEV_ACTION_SEQUENCE:
				strActionSeq.add(word[1]);
				fp = SkipClass(fp, "END_ACTION_SEQUENCE"); break;
			case CLASS_TYPE_TAG:
				strTypeTag.add(word[1]); break;
			case CLASS_OBJECT_CREATION:
				strObjCreation.add(word[1]);
				fp = SkipClass(fp, "END_OBJECT_CREATION"); break;
			case CLASS_GAME_EVENT:
				strGameEvent.add(word[1]); break;
			case CLASS_PACKAGE_RECEIPT_TRIGGER:
				strPRTrigger.add(word[1]);
				fp = SkipClass(fp, "END_PACKAGE_RECEIPT_TRIGGER"); break;
			case CLASS_VALUE_TAG:
				strValueTag.add(word[1]); break;
			case CLASS_ORDER_ASSIGNMENT:
				strOrderAssign.add(word[1]);
				fp = SkipClass(fp, "END_ORDER_ASSIGNMENT"); break;
			case CLASS_COMMAND:
				strCommand.add(word[1]);
				fp = SkipClass(fp, "END_COMMAND"); break;
		} break;

/*******************************************************************/

	// The second pass will allocate the classes/blueprints.
	// Strings are replaced through indices in the string lists.
	case 1:
		switch(z = stfind_cs(CLASS_str, CLASS_NUM, word[0]))
		{
			// Classes not defined here should be ignored.
			case CLASS_USER:
			case CLASS_LEVEL:
			case CLASS_PLAYER:
			case CLASS_BUILDING:
			case CLASS_CHARACTER:
			//
			case CLASS_CITY:
			case CLASS_TOWN:
			case CLASS_CONTAINER:
			case CLASS_FORMATION:
			case CLASS_MARKER:
			case CLASS_MISSILE:
			case CLASS_PROP:
			case CLASS_ARMY:
			case CLASS_TERRAIN_ZONE:
				fp = CreateObjDef(fp, word, nwords, filename, z, 0);
				break;
			case CLASS_CHARACTER_LADDER:
				fp = SkipClass(fp, "END_CHARACTER_LADDER"); break;
			case CLASS_USER_EXTENSION:
			case CLASS_LEVEL_EXTENSION:
			case CLASS_PLAYER_EXTENSION:
			case CLASS_BUILDING_EXTENSION:
			case CLASS_CHARACTER_EXTENSION:
			//
			case CLASS_CITY_EXTENSION:
			case CLASS_TOWN_EXTENSION:
			case CLASS_CONTAINER_EXTENSION:
			case CLASS_FORMATION_EXTENSION:
			case CLASS_MARKER_EXTENSION:
			case CLASS_MISSILE_EXTENSION:
			case CLASS_PROP_EXTENSION:
			case CLASS_ARMY_EXTENSION:
				strchr(word[0], '_')[0] = 0;
				z = stfind_cs(CLASS_str, CLASS_NUM, word[0]);
				mustbefound(FindObjDef(z, word[1]));
				fp = CreateObjDef(fp, word, nwords, filename, z, 1);
				break;
			case CLASS_ORDER:
				//fp = SkipClass(fp, "END_ORDER"); break;
				ReadCOrder(&fp, word); break;
			case CLASS_TASK:
				//fp = SkipClass(fp, "END_TASK"); break;
				ReadCTask(&fp, word); break;
			case CLASS_DEFAULT_DIPLOMATIC_STATUS:
				defaultDiploStat = strDiplomaticStatus.find(word[1]); break;
			case CLASS_EQUATION:
			case CLASS_INDEV_EQUATION:
				equation[strEquation.find(word[1])] = ReadEqLine(&fp); break;
			case CLASS_OBJECT_FINDER_DEFINITION:
			case CLASS_INDEV_OBJECT_FINDER_DEFINITION:
				finderdef[strFinderDef.find(word[1])] = ReadOFDLine(&fp); break;
			case CLASS_ACTION_SEQUENCE:
			case CLASS_INDEV_ACTION_SEQUENCE:
				actionseq[strActionSeq.find(word[1])] = ReadActSeq(&fp); break;
			case CLASS_OBJECT_CREATION:
				ReadCObjectCreation(&fp, word); break;
			case CLASS_REACTION:
				ReadCReaction(&fp, word); break;
			case CLASS_PACKAGE_RECEIPT_TRIGGER:
				ReadCPRTrigger(&fp, word); break;
			case CLASS_DEFAULT_VALUE_TAG_INTERPRETATION:
				{char **wp = word + 2;
				int i = strValueTag.find(word[1]);
				if(i != -1) // TODO: WARNING
					defValueTag[i] = ReadValue(&wp);
				break;}
			case CLASS_ORDER_ASSIGNMENT:
				ReadCOrderAssignment(&fp, word); break;
			case CLASS_COMMAND:
				ReadCCommand(&fp, word); break;
		} break;

/*******************************************************************/
}

	}
	free(fcnt);
}

void AllocateCL()
{
	//objdef = (CObjectDefinition*)malloc(strObjDef.len * sizeof(CObjectDefinition));
	//memset(objdef, 0, strObjDef.len * sizeof(CObjectDefinition));
	objdef = new CObjectDefinition[strObjDef.len];
}

PhysicalSubtype *nullPS;

void BeginLooking()
{
	alf.clear(); gline = 0;
}

void LoadGameSet(char *filename)
{
	strAppearTag.add("Default");
	glone.add("Default");

	// Put engine-declared game events (like "On Stampdown")
	for(uint i = 0; i < PDEVENT_NUM; i++)
		strGameEvent.add(PDEVENT_tab0[i]);

	BeginLooking();
	loadinginfo("Gameset pass 0\n"); LookAtFile(filename, 0);

	int xStdOd = strObjDef.len;
	for(int i = 0; i < OBJTYPE_NUM; i++)
	if(FindObjDef(stfind_cs(CLASS_str, CLASS_NUM, OBJTYPE_str[i]), "Standard") == -1)
	{
		strObjDef.add("Standard");
		typeObjDef.add(stfind_cs(CLASS_str, CLASS_NUM, OBJTYPE_str[i]));
		GrowStringList *gl = new GrowStringList(); gl->add("Default");
		pstObjDef.add(gl);
	}

	AllocateCL();
	nullPS = new PhysicalSubtype;
	nullPS->appear = (Mesh**)calloc(strAppearTag.len, sizeof(Mesh*));
	for(int j = 0; j < OBJTYPE_NUM; j++)
	{
		int i = FindObjDef(stfind_cs(CLASS_str, CLASS_NUM, OBJTYPE_str[j]), "Standard");
		if(i < xStdOd) continue;
		//memset(&objdef[i], 0, sizeof(CObjectDefinition));
		objdef[i].type = typeObjDef[i];
		objdef[i].startItems = (valuetype*)calloc(strItems.len, sizeof(valuetype));
		objdef[i].tooltip = 0; objdef[i].shadowtype = 0;
		objdef[i].subtypes = nullPS;
		objdef[i].name = "Standard";
	}

	equation = (CValue**)malloc(sizeof(CValue*) * strEquation.len);
	finderdef = (CFinder**)malloc(sizeof(CFinder*) * strFinderDef.len);
	actionseq = (ActionSeq**)malloc(sizeof(ActionSeq*) * strActionSeq.len);
	cobjcr = (CObjectCreation*)malloc(sizeof(CObjectCreation) * strObjCreation.len);
	memset(cobjcr, 0, sizeof(CObjectCreation) * strObjCreation.len);
	reaction = new CReaction[strReaction.len];
	prtrigger = new CPRTrigger[strPRTrigger.len];
	defValueTag = new CValue*[strValueTag.len];
	gsorder = new COrder[strOrder.len];
	gstask = new CTask[strTask.len];
	orderAssign = new COrderAssignment[strOrderAssign.len];
	gscommand = new CCommand[strCommand.len];

	BeginLooking();
	loadinginfo("Gameset pass 1\n"); LookAtFile(filename, 1);
	alf.clear();

	alias = new DynList<goref>[strAlias.len];

	loadinginfo("Game set loaded!\n");
}