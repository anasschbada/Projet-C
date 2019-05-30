#include <stdio.h>
#include <stdlib.h>
#include <libsx.h>
#include "callback.h"
#include "menu.h"

void quit(Widget w, void *d){
	exit(EXIT_SUCCESS);

}
void  exitWindow(Widget w, void *d){
	CloseWindow();
}
void score(Widget w, void *d){
	
	ScoreWindow=MakeWindow("Score","1", NONEXCLUSIVE_WINDOW);
	SetCurrentWindow(ScoreWindow);
	Widget quitScore;
	//MakeWindow("Score","1", NONEXCLUSIVE_WINDOW);
	quitScore=MakeButton("quitScore",exitWindow, NULL);

	ShowDisplay();
  	GetStandardColors();

}