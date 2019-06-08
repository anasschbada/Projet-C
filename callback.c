#include <stdio.h>
#include <stdlib.h>
#include <libsx.h>
#include "callback.h"
#include "data.h"
#include <errno.h>
#include <string.h>
#include "menu.h"
#include <time.h>


void quit(Widget w, void *d){
	exit(EXIT_SUCCESS);
}
void  exitWindow(Widget w, void *d){
	CloseWindow();
	ExitMainLoop();
}
void score(Widget w, void *d){
	Widget ScoreWindow;
	ScoreWindow=MakeWindow("Score",NULL, NONEXCLUSIVE_WINDOW);
	SetCurrentWindow(ScoreWindow);
	Widget quitScore;
	quitScore=MakeButton("quitScore",exitWindow, NULL);
	
	ShowDisplay();
  	GetStandardColors();
  	MainLoop();
}

void startGame(Widget w, void *d){

 }
void exitWindowGame(Widget w, void *d){

	CloseWindow();
	ExitMainLoop();
}
void endgame(Widget w, void *d){
	Widget ENDGAME;
	ENDGAME=MakeWindow("ENDGAME",NULL, EXCLUSIVE_WINDOW);
	SetCurrentWindow(ENDGAME);
	Widget quitScore,TimeScore;

	int t=(time (NULL) - startingtime);

	char score[]="  score is : ";
	char str[100];
	sprintf(str, "%d", t);
	strcat(score,str);
	printf("%s\n",score );

	TimeScore=MakeTextWidget(score,0,1, 200, 20);
	// printf ("Duree = %ds\n", (int) (time (NULL) - startingtime));
	quitScore=MakeButton("quitScore",exitWindow, NULL);

	WriteinFile("./Username",infos.ZoneSaisie);
	WriteinFileFromchar("./Username",score);

	SetWidgetPos (TimeScore,NO_CARE , NULL, NO_CARE ,NULL);
	SetWidgetPos (quitScore,PLACE_UNDER , TimeScore, NO_CARE ,NULL);



	ShowDisplay();
  	GetStandardColors();
  	MainLoop();
}

void StartEasy(Widget w, void *d){

	GetUsername(infos.ZoneSaisie);
	strcpy(infos.Height,"4");
	strcpy(infos.Width,"4");
	strcpy(infos.Difficulty,"Easy");

	startGameWindow();

}