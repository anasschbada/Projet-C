#include <stdio.h>
#include <stdlib.h>
#include <libsx.h>
#include "menu.h"
#include "callback.h"

void Init_Display(int argc,char *argv[], void *d){

	/* Creation et assemblage des widgets*/
//MainLabel, Quit, Start, User_name, Cards_Height,Cards_lenght; Label1
	
	//// Buttons
	Quit=MakeButton("Quit",quit, NULL);
	Start=MakeButton("Start",NULL, NULL);
	Score=MakeButton("Score",score, NULL);

	///// String Entry
	User_name=MakeStringEntry(NULL,200,NULL,NULL);
	Cards_Height=MakeStringEntry(NULL,100,NULL,NULL);
	Cards_lenght=MakeStringEntry(NULL,100,NULL,NULL);

	//// Labels
	MainLabel= MakeLabel("Test Menu");
	Cards_HeightLabel= MakeLabel("  Cards_Height  ");
	Cards_lenghtLabel= MakeLabel("  Cards_lenght  ");
	User_nameLabel= MakeLabel("  Player  :");
	Label1= MakeLabel(" x ");

	//// Setting Positions
	SetWidgetPos (MainLabel, NO_CARE, NULL, NO_CARE ,NULL);

	SetWidgetPos(User_nameLabel,NO_CARE,NULL,PLACE_UNDER,MainLabel);
	SetWidgetPos(User_name,PLACE_RIGHT,User_nameLabel,PLACE_UNDER,MainLabel);

	SetWidgetPos(Cards_HeightLabel,NO_CARE,NULL,PLACE_UNDER,User_name);
	SetWidgetPos(Cards_lenghtLabel,PLACE_RIGHT,Cards_HeightLabel,PLACE_UNDER,User_name);
	SetWidgetPos(Cards_Height,NO_CARE,NULL,PLACE_UNDER,Cards_HeightLabel);
	SetWidgetPos(Label1,PLACE_RIGHT,Cards_Height,PLACE_UNDER,Cards_lenghtLabel);
	SetWidgetPos(Cards_lenght,PLACE_RIGHT,Label1,PLACE_UNDER,Cards_lenghtLabel);

	SetWidgetPos (Start,NO_CARE , NULL, PLACE_UNDER ,Cards_lenght);
	SetWidgetPos (Score,PLACE_RIGHT , Start, PLACE_UNDER ,Cards_lenght);
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

int main(int argc, char *argv[])
{
	if (OpenDisplay(argc,argv)==0){
			fprintf(stderr, "can't open display\n" );
			return EXIT_FAILURE;
		}

		Init_Display(argc,argv,NULL);
		MainLoop();




		return EXIT_SUCCESS;
}
