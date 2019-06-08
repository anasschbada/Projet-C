#pragma once

#define MAXCAR 200


typedef struct 
{
	char Username[MAXCAR];
	char Height[MAXCAR];
	char Width[MAXCAR];
	char Difficulty[MAXCAR];
	int Score;

	Widget ZoneSaisie;
	
}data;

data infos;
//Widget wid;
extern char *strcatt(char *chaine1,char *chaine2);
extern void WriteinFile(char *f,Widget w);
extern char *ReadfromFile(char *f);
extern void GetUsername(Widget w);
extern void WriteinFileFromchar(char *f,char *string);


