#pragma once
#define filename "scorefile"
#define MAXCAR 200
#define maxlines 100

int Flines;

typedef struct 
{
	char Username[MAXCAR];
	char Height[MAXCAR];
	char Width[MAXCAR];
	char Difficulty[MAXCAR];
	char Score[MAXCAR];

	Widget ZoneSaisie;
	
}data;



typedef struct noeud {
	char joueur[MAXCAR];
	char score[MAXCAR];
	struct noeud *suivant;	//pointeur vers forme suivante
} *Liste;


Liste player;


int r;

data infos;

extern char *strcatt(char *chaine1,char *chaine2);
extern void WriteinFile(void);
extern void ReadfromFile(char *name,char *score);
extern void GetUsername(Widget w);
extern void createFile(char *file);
extern void *	initForme (char *strplayer,char *strscore);
extern int longueur (Liste lf);
extern char *iemejoueur (Liste lf, int r);
extern char *iemescore (Liste lf, int r);
extern void inserer (Liste *lf, int r, char *strplayer,char*strscore);