#include <stdio.h>
#include <stdlib.h>
#include <libsx.h>
#include <errno.h>
#include "menu.h"
#include "callback.h"
#include "data.h"

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
