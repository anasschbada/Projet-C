#include <stdio.h>
#include <stdlib.h>
#include <libsx.h>
#include "callback.h"
#include "data.h"
#include <errno.h>
#include <string.h>
#include "menu.h"
#include <time.h>
#include <assert.h>

void quit(Widget w, void *d){
	exit(EXIT_SUCCESS);
}
void  exitWindow(Widget w, void *d){
	SetCurrentWindow(w);
	CloseWindow();
}
void score(Widget w, void *d){
	char name[MAXCAR];
	char score[MAXCAR];

	Widget ScoreWindow;
	ScoreWindow=MakeWindow("Score",NULL, EXCLUSIVE_WINDOW);
	SetCurrentWindow(ScoreWindow);
	// char *name,*score;
	ReadfromFile(name,score);

	printf("%s\n",name );
	Widget quitScore;
	quitScore=MakeButton("quitScore",exitWindow, NULL);
	
	ShowDisplay();
  	GetStandardColors();
  	MainLoop();
}

void startGame(Widget w, void *d){
	CloseWindow();
	startGameWindow();

 }
void Retry(Widget w, void *d){
	CloseWindow();
	startGameWindow();

 }

void endgame(Widget w, void *d){
	CloseWindow();
	ENDGameWindow();
}

void StartEasy(Widget w, void *d){
	GetUsername(infos.ZoneSaisie);
	strcpy(infos.Height,"2");
	strcpy(infos.Width,"2");
	strcpy(infos.Difficulty,"Easy");



}

void StartMedium(Widget w, void *d){
	GetUsername(infos.ZoneSaisie);
	strcpy(infos.Height,"4");
	strcpy(infos.Width,"4");
	strcpy(infos.Difficulty,"Medium");


}
void StartHard(Widget w, void *d){
	GetUsername(infos.ZoneSaisie);
	strcpy(infos.Height,"8");
	strcpy(infos.Width,"8");
	strcpy(infos.Difficulty,"Hard");


}
void StartExpert(Widget w, void *d){
	GetUsername(infos.ZoneSaisie);
	strcpy(infos.Height,"16");
	strcpy(infos.Width,"16");
	strcpy(infos.Difficulty,"Expert");


}

int nbtour = 1;
int valeur_courante;
Widget W_Courant1;
Widget W_Courant2;
int DejaJoue=0;

int nbpairesDecouvertes = 0;
int ValeurPrec;

//Callback de toutes les cartes 
void Activ(Widget w,void *data){

	// Le numéro de chaque carte sera transmis par la donné data de type Carte_Courante contenant la carte, son numéro ainsi que le nombre de lignes et colonnes  

  Carte_Courante *me = (Carte_Courante *) data;
  int nbpaires=((*me).nbL * (*me).nbC)/2;

  int ind = (*me).valeur;
  // Le numéro de chaque carte correspond ainsi à une couleur du tableau Colors 
  char *Colors[50][100] = {{"red"},{"black"},{"azure"},{"white"},{"navy"},{"blue"},{"SteelBlue"},{"cyan"},{"dark green"},{"sea green"},{"green"},{"lime green"},{"yellow},{khaki"},{"gold"},{
  "rosy brown"},{"beige"},{"chocolate"},{"orange"},{"salmon"},{"coral"},{"wheat"},{"pink"},{"maroon"},{"violet"},{"magenta"},{"moccasin"},{"cadet blue"},{"gray78"},{"gray20"},{"dark red"},{"tomato"},{
  "chartreuse"},{"yellow green"},{"olive"},{"aquamarine"},{"lavender"},{"misty rose"},{"navajo white"},{"linen"},{"honeydew"},{"medium blue"},{"lawn green"},{"pale goldenrod"},{
  "indian red"},{"orchid"},{"plum"},{"thistle"},{"hotpink"},{"burlywood"}};
  

  
  // W_Courant 1 et 2 correspondent aux cartes successivement retournées
  // Correspond au premier tour, c'est-à-dire lorsque la première carte des deux est retournée
  if (nbtour==1){
  		//Dans le cas où le tout premier tour a été joué
	  	if (DejaJoue){
	  		assert(w!=W_Courant1 && w!=W_Courant2);
	  		// Cas ou les deux cartes précédentes sont égales, on les laisse alors retournées et on augmente le nombre de paires découvertes
	  		if (ind==ValeurPrec){
	  			SetWidgetState(W_Courant1,FALSE);
	  			SetWidgetState(W_Courant2,FALSE);
	  			nbpairesDecouvertes++;

	  		}
	  		// Si les cartes étaient différentes on les retournes face cachées
	  		else {
	  			SetWidgetState(W_Courant1,TRUE);
	  			SetWidgetState(W_Courant2,TRUE);
	  			SetBgColor(W_Courant1,GetNamedColor("white"));
	  			SetBgColor(W_Courant2,GetNamedColor("white"));

	  		}
	  		// Quoi qu'il arrive on retourne la carte qui vient d'être cliquée 
	  		SetWidgetState(w,FALSE);
	  		SetBgColor(w,GetNamedColor(*Colors[ind-1]));
	  		W_Courant1=w;
	  		nbtour++;
	  		ValeurPrec=ind;


  	}
  	// Cas du tout premier tour de la partie 
  	else {
  		ValeurPrec=ind;
  		SetWidgetState(w,FALSE);
  		SetBgColor(w,GetNamedColor(*Colors[ind-1]));
  		W_Courant1=w;
  		nbtour++;
  		DejaJoue++;
  	}
  
  }
  // Cas où l'on est au deuxième tour, la deuxième carte est donc retournée et le test d'égalité se fera au début du prochain tour
  else {
  	SetWidgetState(w,FALSE);
  	SetBgColor(w,GetNamedColor(*Colors[ind-1]));
  	W_Courant2=w;
  	nbtour--;

  }
  // Si on a découvert toutes les paires la partie s'arrête 
  if (nbpairesDecouvertes==nbpaires) exit(EXIT_SUCCESS);
}