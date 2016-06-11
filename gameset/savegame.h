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

#define MAX_GAMEOBJECTS 1048576

#define FGO_RECONNAISSANCE	1
#define FGO_FOG_OF_WAR		2
#define FGO_TERMINATED		4
#define FGO_PLAYER_TERMINATED	8
#define FGO_SELECTED		16
#define FGO_SELECTABLE		32
#define FGO_TARGETABLE		64

#define WKVER_UNKNOWN		0
#define WKVER_ORIGINAL		1
#define WKVER_BATTLES		2

struct GameObject;

struct GameObjAndListEntry
	{GameObject *o;
	DynList<GameObjAndListEntry> *l;
	DynListEntry<GameObjAndListEntry> *e;};
struct GOAssociation
	{uint category;
	DynList<GameObjAndListEntry> associates;
	DynList<GameObjAndListEntry> associators;};
struct GOItem
{
	int num;
	valuetype value;
};

struct GOParamBlock
{
	COrder *order; goref obj; Vector3 dest, face;
};

struct COrder;

struct GameObject
{
	uint id, handle;
	GameObject *parent;
	DynListEntry<GameObject> *palste; DynList<GameObject> children;

	CObjectDefinition *objdef;
	Vector3 position, orientation, scale;
	int subtype, appearance;
	DynList<GOItem> item; 			// individual items
	int color, renderable;
	int flags; GrowList<int> *rects;
	DynList<GOAssociation> association;	// one GOAssociation for one ass. category.
	SOrderConfiguration ordercfg;
	uint disableCount;
	DynList<uint> iReaction;
	GameObject *player;
	wchar_t *name;
	GOParamBlock *param;
	GrowList<couple<uint> > *tiles;

	valuetype getItem(int x);
	void setItem(int x, valuetype v);
};

struct DelayedSequenceEntry
{
	float time;
	uint actseq; goref executor;
	uint numobj; goref *obj; uint unk;
};

struct SequenceOverPeriodEntry
{
	uint actseq; goref executor;
	float time, period;	// (?)
	uint unk1, unk2;
	uint numobj; goref *obj;
};

extern GameObject *gameobj[MAX_GAMEOBJECTS];
extern GameObject *levelobj;
extern uint wkver;

extern float current_time, previous_time, elapsed_time;

GameObject *SubFindObjID(int id, GameObject *p);
GameObject *FindObjID(int id);

inline goref::goref() {handle = -1;}
inline int goref::valid()
{
	if(handle != -1) if(gameobj[handle]) if(gameobj[handle]->id == id) return 1;
	return 0;
}
inline GameObject *goref::get()
{
	if(!valid()) return 0;
	return gameobj[handle];
}
inline void goref::deref() {handle = -1;}
inline void goref::set(GameObject *a)
{
	if(!a) {handle = -1; return;}
	handle = a->handle;
	id = a->id;
}
inline goref &goref::operator=(uint a) {set(FindObjID(a)); return *this;}

void LoadSaveGame(char *fn);
void SaveSaveGame(char *fn);

void RemoveObject(GameObject *o);
void SetObjectParent(GameObject *c, GameObject *p);
void AssociateObjToObj(GameObject *a, uint cat, GameObject *b);
void AliasObj(GameObject *a, uint c);
GameObject *CreateObject(CObjectDefinition *def, GameObject *parent, int id = -1);
void SetRandomSubtypeAndAppearance(GameObject *o);
GameObject *DuplicateObject(GameObject *a);