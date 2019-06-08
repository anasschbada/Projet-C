#include <stdio.h>
#include <stdlib.h>
#include <libsx.h>
#include <errno.h>
#include "callback.h"
#include "menu.h"
#include "data.h"
#include <string.h>

void GetUsername(Widget w){
	strcpy(infos.Username, GetTextWidgetText(w));
}
char *strcatt(char *chaine1,char *chaine2){
	char *p=chaine1;
	while(*chaine1++) chaine1++;
	while(*chaine1++==*chaine2++);
	return p;
}
void WriteinFile(char *f,Widget w){
	FILE *fd;
	printf("%s\n",infos.Username );
	GetUsername(w);
    if ((fd=fopen(f,"w"))==NULL)
    {
        perror("Username");
        exit(errno);
    }
    
  	fwrite(&(infos.Username),sizeof(char),strlen(infos.Username),fd);
 
    fclose(fd);

	
	fclose(fd);
}
void WriteinFileFromchar(char *f,char *string){
	FILE *fd;

    if ((fd=fopen(f,"w"))==NULL)
    {
        perror("Username");
        exit(errno);
    }
    
  	fwrite(&string,sizeof(char),strlen(string),fd);
 
    fclose(fd);

	
	fclose(fd);
}



char *ReadfromFile(char *f){
	
	FILE *fd;
	char string[MAXCAR];
	char *returnedstr= malloc(sizeof (char)*strlen(string));;

    if ((fd=fopen(f,"r"))==NULL)
    {
        perror("Error Reading");
        exit(errno);
    }
	while(fread(&string,sizeof(char),strlen(string),fd)>0){
    	snprintf(returnedstr, sizeof(returnedstr), "%s", string);
	}
    fclose(fd);
    return returnedstr;
}