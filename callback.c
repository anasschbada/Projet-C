#include <stdio.h>
#include <stdlib.h>
#include <libsx.h>
#include "callback.h"
#include "menu.h"
#include "data.h"

void quit(Widget w, void *d){
	exit(EXIT_SUCCESS);

}
void  exitWindow(Widget w, void *d){
	CloseWindow();
	ExitMainLoop();
}
void score(Widget w, void *d){
	
	ScoreWindow=MakeWindow("Score",NULL, NONEXCLUSIVE_WINDOW);
	SetCurrentWindow(ScoreWindow);
	Widget quitScore;
	quitScore=MakeButton("quitScore",exitWindow, NULL);
	ShowDisplay();
  	GetStandardColors();
  	MainLoop();
}
void Beeping(Widget w, void *d){
	Beep();
}
void start(Widget w, void *d){
	value *data;
	//GetHeight(w,&data);
	
	if (((data->Height)%2)!=0)
	{
	Gameon=MakeWindow("Gameon",NULL, NONEXCLUSIVE_WINDOW);
	SetCurrentWindow(Gameon);
	Widget QuitGame;
	QuitGame=MakeButton("Quit The Game",exitWindow, NULL);
	ShowDisplay();
  	GetStandardColors();
  	MainLoop();
	}
}