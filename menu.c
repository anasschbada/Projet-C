#include <stdio.h>
#include <stdlib.h>
#include <libsx.h>
#include "menu.h"
#include "callback.h"

#include <time.h>
#include <unistd.h>
#include "data.h"


Widget MenuWindow,GameWindow,EndWindow,playgamewindow;


void Init_Menu(void){
	r=0;
	MenuWindow=MakeWindow("Memory Game Menu",NULL, EXCLUSIVE_WINDOW);
	SetCurrentWindow(MenuWindow);

	// Main Buttons Widgets
	Widget MainLabel, Quit, Start, User_name, Cards_Height,Cards_lenght,Score;
	// Label Widgets
	Widget Label1,Cards_HeightLabel,Cards_lenghtLabel,User_nameLabel,Difficulty_Label;
	Widget StartLabel;

	

	Flines=0;
	Widget diffeasy,diffhard,diffmedium,
	chooseLabel,diffexpert,space[5];
	int Red=GetNamedColor("Red");
	int Black=GetNamedColor("Black");
	int Green=GetNamedColor("Green");

	Quit=MakeButton("\n Quit \n\n",quit, NULL);
	Start=MakeButton("\n GO \n\n",startGame,NULL);
	Score=MakeButton("\n Score \n\n",score, NULL);

	diffeasy=MakeToggle("EASY",FALSE, NULL, StartEasy ,NULL);
 	diffmedium=MakeToggle("MEDIUM",FALSE, diffeasy, StartMedium,NULL);
  	diffhard=MakeToggle("HARD",FALSE, diffeasy, StartHard,NULL);
    diffexpert=MakeToggle("EXPERT",FALSE, diffeasy, StartExpert,NULL);

    chooseLabel=MakeLabel("\n choose the difficulty: \n");
    space[0]=MakeLabel(" ");

	///// String Entry
	User_name=MakeTextWidget("", 0, 1, 200, 30);
	infos.ZoneSaisie = User_name;
	//// Labels
	MainLabel=MakeLabel("\n          JEU MEMORY \n ");

	User_nameLabel= MakeLabel("Player:");

	StartLabel=MakeLabel(" \n\n Then click on start \n\n");

	//// Setting Positions
	SetWidgetPos (MainLabel, NO_CARE, NULL, NO_CARE ,NULL);

	SetWidgetPos(User_nameLabel,NO_CARE,NULL,PLACE_UNDER,MainLabel);
	SetWidgetPos(User_name,PLACE_RIGHT,User_nameLabel,PLACE_UNDER,MainLabel);
	SetWidgetPos(space[0],PLACE_UNDER,User_name,NO_CARE,NULL);


	SetWidgetPos (chooseLabel, PLACE_UNDER, space[0], NO_CARE ,NULL);
	SetWidgetPos (diffeasy, PLACE_UNDER, chooseLabel, NO_CARE ,NULL);
	SetWidgetPos (diffmedium, PLACE_UNDER, chooseLabel, PLACE_RIGHT ,diffeasy);
	SetWidgetPos (diffhard, PLACE_UNDER, chooseLabel, PLACE_RIGHT ,diffmedium);
	SetWidgetPos (diffexpert, PLACE_UNDER, chooseLabel, PLACE_RIGHT ,diffhard);

	SetWidgetPos(StartLabel,PLACE_UNDER,diffexpert,NO_CARE,NULL);
	SetWidgetPos (Start,NO_CARE , NULL, PLACE_UNDER ,StartLabel);
	SetWidgetPos (Score,PLACE_RIGHT , Start, PLACE_UNDER ,StartLabel);
	SetWidgetPos (Quit, PLACE_RIGHT, Score, PLACE_UNDER ,StartLabel);

	// Setting Colors

  	SetBgColor(Quit,GetRGBColor(204, 0, 0));
  	SetBgColor(Start,GetRGBColor(102, 255, 51));  	
  	SetBgColor(Score,GetRGBColor(255, 255, 0));
  	
	GetUsername(infos.ZoneSaisie);

  	ShowDisplay();
  	GetStandardColors();

}

void startGameWindow(void){
	r++;

	GetUsername(infos.ZoneSaisie);

	GameWindow=MakeWindow("Memory Game",NULL, EXCLUSIVE_WINDOW);
	SetCurrentWindow(GameWindow);

	Widget UserLabel,HeightWidthLabel,DifficultyLabel,EXIT;
	Widget playername,HeightGame,WidthGame,DifficultyStatus,x;
	Widget score,retry;



	startingtime = time (NULL);

	EXIT=MakeButton("Quit",quit, NULL);
	retry=MakeButton("retry",Retry, NULL);

///////////////////////////////////////////////
	score=MakeLabel(infos.Score);
	/////////////////////////////////////
	x=MakeLabel("x");
	UserLabel=MakeLabel("---Player: ");
	HeightWidthLabel=MakeLabel("---Height x Width :");
	DifficultyLabel=MakeLabel("-----Difficulty :");

	playername=MakeLabel(infos.Username);
	HeightGame=MakeLabel(infos.Height);
	WidthGame=MakeLabel(infos.Width);
	DifficultyStatus=MakeLabel(infos.Difficulty);

	SetWidgetPos(UserLabel,NO_CARE,NULL,NO_CARE,NULL);
	SetWidgetPos(playername,PLACE_RIGHT,UserLabel,NO_CARE,NULL);
	SetWidgetPos(HeightWidthLabel,PLACE_RIGHT,playername,NO_CARE,NULL);
	SetWidgetPos(HeightGame,PLACE_RIGHT,HeightWidthLabel,NO_CARE,NULL);
	SetWidgetPos(x,PLACE_RIGHT,HeightGame,NO_CARE,NULL);
	SetWidgetPos(WidthGame,PLACE_RIGHT,x,NO_CARE,NULL);
	SetWidgetPos(DifficultyLabel,PLACE_RIGHT,WidthGame,NO_CARE,NULL);
	SetWidgetPos(DifficultyStatus,PLACE_RIGHT,DifficultyLabel,NO_CARE,NULL);
	SetWidgetPos(score,PLACE_UNDER,DifficultyStatus,NO_CARE,NULL);
	SetWidgetPos(EXIT,PLACE_UNDER,score,PLACE_RIGHT,score);
	SetWidgetPos(retry,PLACE_UNDER,score,PLACE_RIGHT,EXIT);

	GameWindowinit();
	ENDGameWindow();

	ShowDisplay();
 	GetStandardColors();
 	MainLoop();
}

void ENDGameWindow(void){
	
	Liste *listplayer=&player;

	EndWindow=MakeWindow("End of the Game",NULL, EXCLUSIVE_WINDOW);
	SetCurrentWindow(EndWindow);

	Widget quitScore,TimeScore;

	int t=(time (NULL) - startingtime);

	char score[]="  Time elapsed : ";
	
	sprintf(infos.Score, "%d", t);
	strcat(score,infos.Score);
	printf("%s\n",score );


	TimeScore=MakeTextWidget(score,0,1, 200, 20);
 	quitScore=MakeButton("quitScore",exitWindow, NULL);
	printf("lg=%d r=%d\n name=%s \n",longueur (*listplayer),r,infos.Username );

	inserer (listplayer,r, infos.Username,infos.Score);


	WriteinFile();
	

	SetWidgetPos (TimeScore,NO_CARE , NULL, NO_CARE ,NULL);
	SetWidgetPos (quitScore,PLACE_UNDER , TimeScore, NO_CARE ,NULL);



	ShowDisplay();
  	GetStandardColors();
  	MainLoop();

  }


void GameWindowinit(void){
	Widget FIN;
	playgamewindow=MakeWindow("the Game",NULL, EXCLUSIVE_WINDOW);
	SetCurrentWindow(playgamewindow);

	Carte_Courante *d;
	int nbl=atoi(infos.Height);
	int nbc=atoi(infos.Width);

 // On créé le bouton FIN pour FINIR la partie à tout moment
  	FIN=MakeButton("FIN",exitWindow,NULL);

  //On définit la date *me afin de transmettre le numéro des cartes au callback

  Carte_Courante *me = (Carte_Courante *) d;
  (*me).nbL=nbl;
  (*me).nbC=nbc;

  // carte1 sera la première carte de la ligne, carteligne la carte précédemment placée sur la même ligne que la carte courante 
  // et TabL le tableau recensant les cartes de la ligne précédante afin de pouvoir placer les cartes courantes sous celles au dessus

  Widget carte1,carteligne,TabL[nbc];
  char *s="   ";

  // nb correspond au nombre de carte total et L1 est le tableau contenant les valeurs des cartes ainsi que leur nombre restant d'utilisation
  // Par exemple pour 8 cartes L1 sera {{1,2}, {2,2}, {3,2}, {4,2}}

  int nb=nbc*nbl;
  int L1[nb][2];
  


  for(int i=0;i<nb/2;i++){
  	L1[i][0]=i+1;
  	L1[i][1]=2;
  }
  L1[0][1]=1;

  // La première carte sera toujours associé au numéro 1

  (*me).valeur=1;
  


  carte1=MakeToggle(s,FALSE,NULL,Activ,me);
  (*me).Carte=carte1;
  
  carteligne=carte1;
  
  //On créé la première ligne séparément des autres car elle n'a pas besoin d'une ligne supèrieure
  
  for(int j=1;j<nbc;j++){

    Carte_Courante *mej = (Carte_Courante *) d;
  
    Widget cartei;
    // On choisit un indice de L1 au hasard pour attitrer à la carte son numéro
    int indice=rand()%(nb/2);
    // Si il n'y a plus d'utilisation pour le numéro on se décale vers la droite du tableau jusqu'à trouver un numéro que l'on peut utiliser
    while(L1[indice][1]==0) indice++;
    L1[indice][1]--;
    
    (*mej).valeur=L1[indice][0];
    (*mej).Carte=cartei;

    cartei=MakeToggle("   ",FALSE,NULL,Activ,mej);
    
    
    SetWidgetPos(cartei,PLACE_RIGHT,carte1,NO_CARE,NULL);
    carte1=cartei;
    TabL[j]=cartei;
    
    
  }
   
  // On s'occupe de créer toutes les autres lignes en dessous de la première et des précédentes
  for(int i=2;i<=nbl;i++){ 
    for (int j=1;j<=nbc;j++){

      Carte_Courante *mei = (Carte_Courante *) d;
      Widget cartei;
      int indice=rand()%(nb/2);
      while(L1[indice][1]==0) indice=rand()%(nb/2);
      L1[indice][1]--;
      
      (*mei).valeur=L1[indice][0];
      (*mei).Carte=cartei;
      
      cartei=MakeToggle("   ",FALSE,NULL,Activ,mei);
      
      
      if (j==1){
	SetWidgetPos(cartei,PLACE_UNDER,carteligne,NO_CARE,NULL);
	carteligne=cartei;
	carte1=cartei;
	TabL[0]=cartei;
	
	
      }
      else {
    Widget inter = TabL[j-1];
	SetWidgetPos(cartei,PLACE_RIGHT,carte1,PLACE_UNDER,inter);
	carte1=cartei;
	TabL[j-1]=cartei;
	  	SetWidgetPos(FIN,PLACE_UNDER,cartei,NO_CARE,NULL);

	
      }
      
    }
  }
   

  	ShowDisplay();
  	GetStandardColors();
  	MainLoop();
}