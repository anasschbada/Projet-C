#include <stdio.h>
#include <stdlib.h>
#include <libsx.h>
#include <errno.h>
#include "menu.h"
#include "callback.h"
#include "data.h"



int main(int argc, char *argv[])
{
	if (OpenDisplay(argc, argv)==0){                      //cree la fenetre libsx
		fprintf(stderr, "Can't open display\n");
		return EXIT_FAILURE;
	}
	createFile(filename);
	Init_Menu();
	MainLoop();

	return EXIT_SUCCESS;
}
