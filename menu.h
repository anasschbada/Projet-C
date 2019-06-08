#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <libsx.h>
#include "data.h"


time_t startingtime ;

// Main Buttons Widgets
Widget MainLabel, Quit, Start, User_name, Cards_Height,Cards_lenght,Score;
// Label Widgets
Widget Label1,Cards_HeightLabel,Cards_lenghtLabel,User_nameLabel,Difficulty_Label;
Widget StartLabel;

Widget ScoreWindow,Difficulty_Menu;



extern void Init_Menu(int argc,char *argv[], void *d);
extern void customsettingsInit(Widget w, void *d);
extern  void startGameInit(Widget w, void *d);
extern void startGameWindow();



// remeber to use strdup