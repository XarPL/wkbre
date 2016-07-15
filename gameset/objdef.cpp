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

#define dd putchar(1);
#define oddbg(...) 

int FindObjDef(int t, char *s)
{
	for(int i = 0; i < typeObjDef.len; i++)
		if(typeObjDef[i] == t)
			if(!_stricmp(strObjDef.getdp(i), s))
				return i;
	return -1;
}

void FindModel(char *checkfile, int &ff, int &m)
{
	ff = 1; m = 0;
	int si = strlen(checkfile);
	strcpy(checkfile+si, "Default.ANIM3");
	if(!FileExists(checkfile))
	{
		strcpy(checkfile+si, "Default1.ANIM3");
		if(!FileExists(checkfile))
		{
			m = 1;
			strcpy(checkfile+si, "Default.MESH3");
			if(!FileExists(checkfile))
			{
				strcpy(checkfile+si, "Default1.MESH3");
				if(!FileExists(checkfile))
					ff = 0;
			}
		}
	}
}

char *LookPSt(char *fp, char **fline, int fwords, char *path1, int x, char *cppname)
{
	char wwl[MAX_LINE_SIZE], *word[MAX_WORDS_IN_LINE]; int nwords;
	char finalfile[512], checkfile[512]; int foundfile;
	int y = pstObjDef[x]->find(fline[1]); mustbefound(y);
	//objdef[x].subtypes[y].name = pstObjDef[x]->getdp(y);
	//objdef[x].subtypes[y].path = GetStrCopy(fline[2]);
	while(*fp)
	{
		fp = GetLine(fp, wwl);
		nwords = GetWords(wwl, word);
		if(!nwords) continue;
		if(!strcmp(word[0], "END_PHYSICAL_SUBTYPE"))
		{
			// Load default appearance if not specified but available.
			// "Default" appear tag is expected to be 0 (first declared).
			if(!objdef[x].subtypes[y].appear[0])
			{
				int si; int ff = 0, m = 0;
				// Anim path: path1 + fline[2]
				strcpy(checkfile, cppname);
				char *bs = strrchr(checkfile, '\\');
				if(bs)	*(bs+1) = 0;
				else	*checkfile = 0;
				strcat(checkfile, path1);
				if(fwords >= 3)
					strcat(checkfile, fline[2]);
				oddbg("[DBG] DEF checkfile = %s\n", checkfile);
				FindModel(checkfile, ff, m);
				if(ff) {
					if(!m)	objdef[x].subtypes[y].appear[0] = LoadAnim(checkfile);
					else	objdef[x].subtypes[y].appear[0] = new Mesh(checkfile);
				}
					
			}
			return fp; // Load mesh here?
		}
		if(!strcmp(word[0], "APPEARANCE"))
		{
			foundfile = 0;
			int z = strAppearTag.find(word[1]); mustbefound(z);
			int fm;
			while(*fp)
			{
				fp = GetLine(fp, wwl);
				nwords = GetWords(wwl, word);
				if(!nwords) continue;
				if(!strcmp(word[0], "END_APPEARANCE"))
					goto appearend;
				if(!strcmp(word[0], "LOAD_ANIMATIONS_FROM"))
				{
					int si; int ff = 0, m = 0;
					// Anim path: path1 + fline[2] + word[1]
					strcpy(checkfile, cppname);
					char *bs = strrchr(checkfile, '\\');
					if(bs)	*(bs+1) = 0;
					else	*checkfile = 0;
					strcat(checkfile, path1);
					if(fwords >= 3)
						strcat(checkfile, fline[2]);
					strcat(checkfile, word[1]);
					oddbg("[DBG] checkfile = %s\n", checkfile);
					FindModel(checkfile, ff, m);
					if(ff)
						{strcpy(finalfile, checkfile); foundfile = 1; fm = m;}
				}
			}
			ferr("UEOF");
appearend:		if(foundfile)
			{
				oddbg("[DBG] Final ANIM3 file: %s\n", finalfile);
				if(!fm)	objdef[x].subtypes[y].appear[z] = LoadAnim(finalfile);
				else	objdef[x].subtypes[y].appear[z] = new Mesh(finalfile);
			}
			else	{oddbg("[DBG] No ANIM3\n"); objdef[x].subtypes[y].appear[z] = 0;}
		}
	}
	ferr("UEOF"); return fp;
}

char *CreateObjDef(char *fp, char **fstline, int fwords, char *cppname, int t, int e)
{
	char wwl[MAX_LINE_SIZE], *word[MAX_WORDS_IN_LINE]; int nwords;
	int x = FindObjDef(t, fstline[1]); mustbefound(x);

	if(!objdef[x].life)
	{
		objdef[x].life = 1;
		objdef[x].id = x;
		objdef[x].type = typeObjDef[x];
		objdef[x].startItems = (valuetype*)calloc(strItems.len, sizeof(valuetype));
		objdef[x].tooltip = 0;
		objdef[x].shadowtype = 0;
		objdef[x].numsubtypes = pstObjDef[x]->len;
		objdef[x].subtypes = (PhysicalSubtype*)malloc(pstObjDef[x]->len * sizeof(PhysicalSubtype));
		for(int i = 0; i < pstObjDef[x]->len; i++)
		{
			objdef[x].subtypes[i].appear = (Mesh**)calloc(strAppearTag.len, sizeof(Mesh*));
			objdef[x].subtypes[i].name = pstObjDef[x]->getdp(i);
		}
		if((objdef[x].type == CLASS_BUILDING) || (objdef[x].type == CLASS_CHARACTER) ||
		   (objdef[x].type == CLASS_CONTAINER) || (objdef[x].type == CLASS_MISSILE) ||
		   (objdef[x].type == CLASS_PROP))
			objdef[x].renderable = 1;
		else	objdef[x].renderable = 0;
		objdef[x].scale = Vector3(1,1,1);
		objdef[x].name = strObjDef.getdp(x);
		objdef[x].mappedType = new CObjectDefinition*[strTypeTag.len];
		memset(objdef[x].mappedType, 0, strTypeTag.len * sizeof(CObjectDefinition*));
		objdef[x].valueTagInterpret = new CValue*[strValueTag.len];
		memset(objdef[x].valueTagInterpret, 0, strValueTag.len * sizeof(CValue*));
		objdef[x].representation = 0;
	}

	while(*fp)
	{
		fp = GetLine(fp, wwl);
		nwords = GetWords(wwl, word);
		if(nwords < 1) continue;
		if(*(int*)(word[0]) == '_DNE')
		{
			// Load default subtype and appearance if not specified but available.
			if(!e && (objdef[x].life==1))
			if(!objdef[x].subtypes[0].appear[0])
			{
				int si; int ff = 0, m = 0;
				// Anim path: path1
				char checkfile[512];
				strcpy(checkfile, cppname);
				char *bs = strrchr(checkfile, '\\');
				if(bs)	*(bs+1) = 0;
				else	*checkfile = 0;
				if(fwords >= 3)
					strcat(checkfile, fstline[2]);
				oddbg("[DBG] DEFSB checkfile = %s\n", checkfile);
				FindModel(checkfile, ff, m);
				if(ff) {
					if(!m)	objdef[x].subtypes[0].appear[0] = LoadAnim(checkfile);
					else	objdef[x].subtypes[0].appear[0] = new Mesh(checkfile);
				}
				objdef[x].life = 2;
			}
			return fp;
		}
		int y;
		switch(stfind_cs(CBLUEPRINT_str, CBLUEPRINT_NUM, word[0]))
		{
			case CBLUEPRINT_STARTS_WITH_ITEM:
			case CBLUEPRINT_ITEM:
				//printf("(!) %s\n", word[1]);
				if(nwords < 3) break;
				y = strItems.find(word[1]); //mustbefound(y);
				if(y == -1) break;
				objdef[x].startItems[y] = atov(word[2]);
				break;
			case CBLUEPRINT_BLUEPRINT_TOOLTIP:
				objdef[x].tooltip = GetLocText(word[1]); break;
			case CBLUEPRINT_HAS_DYNAMIC_SHADOW:
				objdef[x].shadowtype = SHADOWTYPE_DYNAMIC; break;
			case CBLUEPRINT_HAS_STATIC_SHADOW:
				objdef[x].shadowtype = SHADOWTYPE_STATIC; break;
			case CBLUEPRINT_PHYSICAL_SUBTYPE:
				fp = LookPSt(fp, word, nwords, (fwords>=3)?fstline[2]:"", x, cppname); break;
			case CBLUEPRINT_SCALE_APPEARANCE:
				objdef[x].scale.x = atov(word[1]);
				objdef[x].scale.y = atov(word[2]);
				objdef[x].scale.z = atov(word[3]);
				break;
			case CBLUEPRINT_MOVEMENT_BAND:
				fp = SkipClass(fp, "END_MOVEMENT_BAND"); break;
			case CBLUEPRINT_INHERITS_FROM:
				y = FindObjDef(objdef[x].type, word[1]); mustbefound(y);
				memcpy(objdef[x].startItems, objdef[y].startItems, strItems.len * sizeof(valuetype));
				break;
			case CBLUEPRINT_MAP_TYPE_TAG:
				{y = FindObjDef(stfind_cs(CLASS_str, CLASS_NUM, word[2]), word[3]); mustbefound(y);
				int z = strTypeTag.find(word[1]); mustbefound(z);
				objdef[x].mappedType[z] = &objdef[y]; break;}
			case CBLUEPRINT_INTRINSIC_REACTION:
				{y = strReaction.find(word[1]);
				if(y != -1) objdef[x].ireact.add(&(reaction[y])); break;}
			case CBLUEPRINT_INTERPRET_VALUE_TAG_AS:
				{char **wp = word + 2;
				int i = strValueTag.find(word[1]); mustbefound(i);
				objdef[x].valueTagInterpret[i] = ReadValue(&wp);
				break;}
			case CBLUEPRINT_REPRESENT_AS:
				{char mn[512];
				strcpy(mn, "Warrior Kings Game Set\\");
				strcat(mn, word[1]);
				if(FileExists(mn))
					objdef[x].representation = LoadAnim(mn);
				break;}
			case CBLUEPRINT_OFFERS_COMMAND:
				{uint i = strCommand.find(word[1]);
				if(i != -1)
					objdef[x].offeredCmds.add(&(gscommand[i]));
				break;}
		}
	}
	ferr("Unexpected end of file in class definition.");
	return fp;
}