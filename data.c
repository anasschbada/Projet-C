#include <stdio.h>
#include <stdlib.h>
#include <libsx.h>
#include "callback.h"
#include "menu.h"
#include "data.h"

void GetHeight(Widget w, void *d){
	value *data;
	char str[100];
	strcpy(str,GetStringEntry(((value*)data)->w));
	data->Height=atof(str);
}
