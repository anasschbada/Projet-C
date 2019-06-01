#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <libsx.h>

// Main Buttons Widgets
Widget MainLabel, Quit, Start, User_name, Cards_Height,Cards_lenght,Score;
// Label Widgets
Widget Label1,Cards_HeightLabel,Cards_lenghtLabel,User_nameLabel,Difficulty_Label;
Widget StartLabel;

Widget ScoreWindow,Gameon;



extern void Init_Menu(int argc,char *argv[], void *d);




// remeber to use strdup