#include <stdio.h>
#include <stdlib.h>
#include <libsx.h>
#include <errno.h>
#include "callback.h"
#include "menu.h"
#include "data.h"
#include <assert.h>
#include <string.h>

void GetUsername(Widget w){
	strcpy(infos.Username, GetTextWidgetText(w));
}

void WriteinFile(void){

	char strscore[100];
	char strplayer[100];
	

	FILE *ftemp;									//ouverture du fichier temporaire
	if((ftemp=fopen(".file_temp","w"))==NULL) {
		perror(".file_temp"); 
		exit(errno);
	}

	for(int j=1; j<=r; j++){	
		strcpy(strscore,iemescore(player, j));
		strcpy(strplayer,iemejoueur(player, j));

		strcat(strscore,"\n");
		strcat(strplayer,"\n");

		fputs(strplayer,ftemp);
		fputs(strscore,ftemp);

	}
	
	fclose(ftemp);							//on ferme le fichier temp
	remove(filename);						//supprime le fichier de scores
	rename(".file_temp",filename);			//renome le fichier temp 

}

void ReadfromFile(char *name,char *score){
	char strname[MAXCAR];
	char strscore[MAXCAR];
	FILE *fs;								//ouverture du fichier score
	if((fs=fopen(filename,"r"))==NULL) {
		perror(filename);
		exit(errno);
	}
	name=malloc(sizeof(char)*MAXCAR);
	score=malloc(sizeof(char)*MAXCAR);
//on parcourt tout le fichier en lisant d'abord le nom puis le score de chaque joueur
	// while(fread(&strname,sizeof(char)*MAXCAR,1,fs)>0) fread(&strscore,sizeof(char),1,fs);
	while (fread(&strname,sizeof(char)*MAXCAR,MAXCAR,fs)>0) {
		// fread(&strscore,sizeof(char),1,fs);
		strcpy(name,strname);
		printf("from file:\n%s\n",name );

	}


	strcpy(name,strname);
	strcpy(score,strscore);

	// printf("from file:\n%s\n",name );
	free(name);
	free(score);
	fclose(fs); 

}
void createFile(char *file){
	FILE *fscore;
	if((fscore=fopen(file,"r"))==NULL) { 	   //si on ne peut pas l'ouvir en lecture, il n'existe pas
			fscore=fopen(file,"w");		   //on le cree
	}
	fclose(fscore);
}

////////////////////////////////////////////////////////////////////////////////////
void *	initForme (char *strplayer,char *strscore){
	struct noeud *lf=malloc(sizeof(struct noeud)); //allocation espace memoire
	strcpy(lf->joueur,strplayer);
	strcpy(lf->score,strscore);

	lf->suivant=NULL;	//pointe vers 'la terre'
	return lf;
}
/*
	renvoie le nombre de formes dans la liste
*/
int longueur (Liste lf){
	int i=0;				//compteur 
	struct noeud *s= lf;	//noeud qui pointe vers la premiere forme
	while(s){				//tant qu'il y a des formes (a la fin ca vaudra NULL)
		i++;				//on incremente le compteur 
		s=s->suivant;		//on passe a la forme suivante
	}
	return i+1;
}

/*
	renvoie la forme a la ieme position
*/
char *iemejoueur (Liste lf, int r){
	assert(r>0 && r<=longueur(lf));		//on verifie que r est valide
	struct noeud *s= lf;			
	while(--r) s=s->suivant;			//on se positionne a la r'ieme position
	return s->joueur;
}
char *iemescore (Liste lf, int r){
	assert(r>0 && r<=longueur(lf));		//on verifie que r est valide
	struct noeud *s= lf;			
	while(--r) s=s->suivant;			//on se positionne a la r'ieme position
	return s->score;
}

/*
	insere forme f au rang r
*/
void inserer (Liste *lf, int r, char *strplayer,char*strscore){
	assert(r>0 && r<=longueur(*lf)+1);		//verfification (longueur+1 pour pouvoir ajouter une forme a la fin)
	struct noeud *newlf = initForme(strplayer,strscore);		//creation d'une nouvelle forme
	while(--r) lf=&(**lf).suivant;			//on pointe sur la r'ieme position avec le pointeur lf
	newlf->suivant=*lf;						//on insere la nouvelle forme
	*lf=newlf;								
}

