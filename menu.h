#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <libsx.h>
#include "data.h"


time_t startingtime ;

typedef struct {
	int valeur;
	Widget Carte;
	int nbL;
	int nbC;

} Carte_Courante;

Widget menuwidg,gameon;
extern void Init_Menu(void);
extern void startGameWindow();
extern void ENDGameWindow(void);
extern void GameWindowinit(void);
