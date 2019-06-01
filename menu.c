#include <stdio.h>
#include <stdlib.h>
#include <libsx.h>
#include "menu.h"
#include "callback.h"
#include "data.h"

void Init_Display(int argc,char *argv[], void *d){

	/* Creation et assemblage des widgets*/
//MainLabel, Quit, Start, User_name, Cards_Height,Cards_lenght; Label1
/*	value *data;
	data->Height=2;*/
	//// Buttons
	Quit=MakeButton("Quit",quit, NULL);
	Start=MakeButton("Start",start, NULL);
	Score=MakeButton("Score",score, NULL);

	///// String Entry
	User_name=MakeStringEntry(NULL,200,NULL,NULL);
	Cards_Height=MakeStringEntry(NULL,100,NULL,NULL);
	Cards_lenght=MakeStringEntry("",100,NULL,NULL);

	//// Labels
	MainLabel= MakeLabel("Test Menu");
	Cards_HeightLabel= MakeLabel("  Cards_Height  ");
	Cards_lenghtLabel= MakeLabel("  Cards_lenght  ");
	User_nameLabel= MakeLabel("  Player  :");
	Label1= MakeLabel(" x ");
	Difficulty_Label= MakeLabel("\n\t Please insert the Height and the Lenght of the Cards: \n\n");
	StartLabel=MakeLabel(" \n\tClick here to start \n");

	//// Setting Positions
	SetWidgetPos (MainLabel, NO_CARE, NULL, NO_CARE ,NULL);

	SetWidgetPos(User_nameLabel,NO_CARE,NULL,PLACE_UNDER,MainLabel);
	SetWidgetPos(User_name,PLACE_RIGHT,User_nameLabel,PLACE_UNDER,MainLabel);

	SetWidgetPos(Difficulty_Label,PLACE_UNDER,User_name,NO_CARE,NULL);
	SetWidgetPos(Cards_HeightLabel,NO_CARE,NULL,PLACE_UNDER,Difficulty_Label);
	SetWidgetPos(Cards_lenghtLabel,PLACE_RIGHT,Cards_HeightLabel,PLACE_UNDER,Difficulty_Label);
	SetWidgetPos(Cards_Height,NO_CARE,NULL,PLACE_UNDER,Cards_HeightLabel);
	SetWidgetPos(Label1,PLACE_RIGHT,Cards_Height,PLACE_UNDER,Cards_lenghtLabel);
	SetWidgetPos(Cards_lenght,PLACE_RIGHT,Label1,PLACE_UNDER,Cards_lenghtLabel);
	SetWidgetPos(StartLabel,PLACE_UNDER,Cards_lenght,NO_CARE,NULL);

	SetWidgetPos (Start,NO_CARE , NULL, PLACE_UNDER ,StartLabel);
	SetWidgetPos (Score,PLACE_RIGHT , Start, PLACE_UNDER ,StartLabel);
	SetWidgetPos (Quit, NO_CARE, NULL, PLACE_UNDER ,Start);

	int Red=GetNamedColor("Red");
	int Black=GetNamedColor("Black");
	int Green=GetNamedColor("Green");


	// Setting Colors
  	//SetColor(Red);
  	SetBgColor(Quit,Red);
  	SetBgColor(Start,Green);
  	

  	ShowDisplay();
  	GetStandardColors();

}

