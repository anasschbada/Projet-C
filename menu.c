#include <stdio.h>
#include <stdlib.h>
#include <libsx.h>
#include "menu.h"
#include "callback.h"
#include "data.h"
#include <time.h>
#include <unistd.h>


void Init_Display(int argc,char *argv[], void *d){


	int Red=GetNamedColor("Red");
	int Black=GetNamedColor("Black");
	int Green=GetNamedColor("Green");

	Quit=MakeButton("\n Quit \n\n",quit, NULL);
	Start=MakeButton("\n Start \n\n",startGameInit,NULL);
	Score=MakeButton("\n Score \n\n",score, NULL);

	///// String Entry
	User_name=MakeTextWidget("", 0, 1, 200, 30);
	infos.ZoneSaisie = User_name;
	//// Labels
	MainLabel= MakeLabel("\n          JEU MEMORY \n ");

	User_nameLabel= MakeLabel("Player:");

	StartLabel=MakeLabel(" \nClick here to start \n");

	//// Setting Positions
	SetWidgetPos (MainLabel, NO_CARE, NULL, NO_CARE ,NULL);

	SetWidgetPos(User_nameLabel,NO_CARE,NULL,PLACE_UNDER,MainLabel);
	SetWidgetPos(User_name,PLACE_RIGHT,User_nameLabel,PLACE_UNDER,MainLabel);
	SetWidgetPos(StartLabel,PLACE_UNDER,User_name,NO_CARE,NULL);
	SetWidgetPos (Start,NO_CARE , NULL, PLACE_UNDER ,StartLabel);
	SetWidgetPos (Score,PLACE_RIGHT , Start, PLACE_UNDER ,StartLabel);
	SetWidgetPos (Quit, PLACE_RIGHT, Score, PLACE_UNDER ,StartLabel);

	// Setting Colors
  	//SetColor(Red);
  	SetBgColor(Quit,GetRGBColor(204, 0, 0));
  	SetBgColor(Start,GetRGBColor(102, 255, 51));  	
  	SetBgColor(Score,GetRGBColor(255, 255, 0));
  	

  	ShowDisplay();
  	GetStandardColors();

}

 void startGameInit(Widget w, void *d){

 	Widget Easy,Medium,Hard,Expert,Start,Quit,Custom,Difficulty_Label;

	Difficulty_Menu=MakeWindow("Difficulty_Menu",NULL, EXCLUSIVE_WINDOW);
	SetCurrentWindow(Difficulty_Menu);

	Easy=MakeButton("\n Easy \n",StartEasy, NULL);
	Medium=MakeButton("\n Medium \n",startGameWindow, NULL);
	Hard=MakeButton("\n Hard \n",NULL, NULL);
	Expert=MakeButton("\n Expert \n",NULL, NULL);
	Quit=MakeButton("\n Quit \n",exitWindow, NULL);
	Custom=MakeButton("\n Custom \n",customsettingsInit, NULL);

	Difficulty_Label= MakeLabel("\nDifficulty: \n\n");
	

	SetWidgetPos(Difficulty_Label,NO_CARE,NULL,NO_CARE,NULL);
	SetWidgetPos(Easy,PLACE_UNDER,Difficulty_Label,PLACE_RIGHT,Difficulty_Label);
	SetWidgetPos(Medium,PLACE_UNDER,Easy,PLACE_RIGHT,Difficulty_Label);
	SetWidgetPos(Hard,PLACE_UNDER,Medium,PLACE_RIGHT,Difficulty_Label);
	SetWidgetPos(Expert,PLACE_UNDER,Hard,PLACE_RIGHT,Difficulty_Label);
	SetWidgetPos(Custom,PLACE_UNDER,Expert,PLACE_RIGHT,Difficulty_Label);

	SetWidgetPos(Quit,PLACE_UNDER,Custom,NO_CARE,NULL);


	SetBgColor(Easy,GetRGBColor(0, 255, 255));
	SetBgColor(Medium,GetRGBColor(102, 255, 102));
	SetBgColor(Hard,GetRGBColor(255, 153, 0));
	SetBgColor(Expert,GetRGBColor(153, 0, 0));

	
	printf("%s\n", infos.Username);
	ShowDisplay();
 	GetStandardColors();
 	MainLoop();
	
}
void customsettingsInit(Widget w, void *d){
	
	Widget Difficulty_custom,Cards_Height,Cards_lenght,Cards_HeightLabel,Cards_lenghtLabel;
 	Widget Label1,Difficulty_Label,CustomDifficulty_Label,OKbutton,Quit;

 	Difficulty_custom=MakeWindow("Difficulty_custom",NULL,EXCLUSIVE_WINDOW);
	SetCurrentWindow(Difficulty_custom);

	Quit=MakeButton("Quit",exitWindow, NULL);
	OKbutton=MakeButton("OK",exitWindow, NULL);

 	Cards_Height=MakeStringEntry("",MAXCAR,NULL,&d);
	Cards_lenght=MakeStringEntry("",MAXCAR,NULL,NULL);

	Cards_HeightLabel= MakeLabel("  Cards_Height  ");
	Cards_lenghtLabel= MakeLabel("  Cards_lenght  ");
	Label1= MakeLabel(" x ");
	Difficulty_Label= MakeLabel("\n        Difficulty: \n\n");
	CustomDifficulty_Label= MakeLabel("\n\n Insert the Height and the Lenght of the Cards: \n\n");

	SetWidgetPos(Difficulty_Label,NO_CARE,NULL,NO_CARE,NULL);
	SetWidgetPos(CustomDifficulty_Label,PLACE_UNDER,Difficulty_Label,NO_CARE,NULL);
	SetWidgetPos(Cards_HeightLabel,PLACE_UNDER,CustomDifficulty_Label,NO_CARE,NULL);
	SetWidgetPos(Cards_lenghtLabel,PLACE_RIGHT,Cards_HeightLabel,PLACE_UNDER,CustomDifficulty_Label);
	SetWidgetPos(Cards_Height,PLACE_UNDER,Cards_lenghtLabel,NO_CARE,NULL);
	SetWidgetPos(Label1,PLACE_RIGHT,Cards_Height,PLACE_UNDER,Cards_lenghtLabel);
	SetWidgetPos(Cards_lenght,PLACE_RIGHT,Label1,PLACE_UNDER,Cards_lenghtLabel);
	SetWidgetPos(Quit,PLACE_UNDER,Cards_lenght,NO_CARE,NULL);
	SetWidgetPos(OKbutton,PLACE_UNDER,Quit,NO_CARE,NULL);

	ShowDisplay();
 	GetStandardColors();
 	MainLoop();
	

}

void startGameWindow(void){


	Widget GameOn,UserLabel,HeightWidthLabel,DifficultyLabel,EXIT,TIMEelapsed;
	Widget playername,H,W,DifficultyStatus,x;
	Widget test,fin;

	GameOn=MakeWindow("GameOn",NULL,EXCLUSIVE_WINDOW);
	SetCurrentWindow(GameOn);

	startingtime = time (NULL);

	EXIT=MakeButton("Quit",exitWindowGame, NULL);
	fin=MakeButton("ENDOFGAME",endgame, NULL);

///////////////////////////////////////////////
	test=MakeLabel("---------la il doit y avoir des cartes \n");
	/////////////////////////////////////
	x=MakeLabel("x");
	UserLabel=MakeLabel("---Player: ");
	HeightWidthLabel=MakeLabel("---Height x Width :");
	DifficultyLabel=MakeLabel("-----Difficulty :");
	TIMEelapsed=MakeLabel("----TIMEelapsed----");

	playername=MakeLabel(infos.Username);
	H=MakeLabel(infos.Height);
	W=MakeLabel(infos.Width);
	DifficultyStatus=MakeLabel(infos.Difficulty);
	// char str[12];
	
	// while((time (NULL) - start)<5){
	// 	int t=(time (NULL) - start);
	// 	sprintf(str, "%d", t);
	// 	SetLabel(TIMEelapsed,str);
	// 	printf ("Duree = %d",t);
	// }

	SetWidgetPos(UserLabel,NO_CARE,NULL,NO_CARE,NULL);
	SetWidgetPos(playername,PLACE_RIGHT,UserLabel,NO_CARE,NULL);

	SetWidgetPos(HeightWidthLabel,PLACE_RIGHT,playername,NO_CARE,NULL);
	SetWidgetPos(H,PLACE_RIGHT,HeightWidthLabel,NO_CARE,NULL);
	SetWidgetPos(x,PLACE_RIGHT,H,NO_CARE,NULL);
	SetWidgetPos(W,PLACE_RIGHT,x,NO_CARE,NULL);

	SetWidgetPos(DifficultyLabel,PLACE_RIGHT,W,NO_CARE,NULL);
	SetWidgetPos(DifficultyStatus,PLACE_RIGHT,DifficultyLabel,NO_CARE,NULL);

	SetWidgetPos(TIMEelapsed,PLACE_RIGHT,DifficultyStatus,NO_CARE,NULL);
	SetWidgetPos(TIMEelapsed,PLACE_RIGHT,DifficultyStatus,NO_CARE,NULL);

	SetWidgetPos(test,PLACE_UNDER,UserLabel,NO_CARE,NULL);

	SetWidgetPos(EXIT,PLACE_UNDER,test,PLACE_RIGHT,test);
	SetWidgetPos(fin,PLACE_UNDER,EXIT,PLACE_RIGHT,EXIT);

	

	ShowDisplay();
 	GetStandardColors();
 	MainLoop();




}
