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

struct CCommand
{
	char *name;
	texture buttonEnabled, buttonWait, buttonImpossible, buttonDepressed, buttonHighlighted;
	texture cursor;
	COrder *order;
	ActionSeq *startSeq;
	CCommand() : name(0), order(0), startSeq(0) {}
};

/*
struct CCondition
{
	CValue *test;
	char *hintstr;
	GrowList<CValue*> hintvalues;
};
*/

void ReadCCommand(char **pntfp, char **fstline);
int CanExecuteCommand(CObjectDefinition *od, CCommand *cc);
void ExecuteCommand(GameObject *o, CCommand *c, GameObject *tg);
//void ReadCCondition(char **pntfp, char **fstline);