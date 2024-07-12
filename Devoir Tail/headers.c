#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include "headers.h"
int liat (int nb_option, char *option3 ,char *option1, char *option2 ,char **option)
{
	if(nb_option==3 && (strcmp(option1,"-q")==0 || strcmp(option1,"--quiet")==0 || strcmp(option1,"--silent")==0))
			option_q(nb_option, option1, option2);
	else if(nb_option==3 && (strcmp(option1,"-v")==0|| strcmp(option1,"--verbose")==0))
			option_v(nb_option, option1, option2);
	else if(nb_option==3 && (strcmp(option1,"-f")==0 || strcmp(option1,"--follow")==0))
			option_f(nb_option, option1, option2);
	else if(nb_option==2 && strcmp(option1,"--version")==0)
			option__version(nb_option ,option1 );
	else if(nb_option==2 && strcmp(option1,"--help")==0)
			option__help(nb_option ,option1 );
	else if(nb_option==4 && (strcmp(option1,"-c")==0 ||  strcmp(option1,"--bytes")==0))
			option_c(nb_option, option3 ,option1, option2 );
	else if(nb_option==4 && (strcmp(option1,"-n")==0 || strcmp(option1,"--lines")==0))
			option_n(nb_option, option3 ,option1, option2 );
	else if(nb_option>0)
			option_vide(nb_option, option);
	else 
		printf("entrer :./tail --help\n");
	return 0;
}
int option_q(int nb_option ,char *option1, char *option2 )
{	
	char mot[300],phrase[300];
	int i=0,j=0,entier=0;
	FILE *fichier=NULL;
	fichier=fopen (option2,"r");
	if (fichier==NULL)
		{
			return -1;
		}
	while(!feof(fichier))
	{
		fgets(phrase,300,fichier);
		entier++;
	}
	rewind(fichier);
	
	if (strcmp(option1,"-q")==0 && nb_option==3)
		{
			while(!feof(fichier))
				{
					fgets(mot,300,fichier);
					if (i>=entier-10)
							printf("%s",mot);
					i++;
				}
		}
	fclose(fichier);
	return 0;
}
int option_n(int nb_option, char *option3 ,char *option1, char *option2 )
{
	char mot[300],phrase[300];
	int i=0,j=0,entier=0;
	FILE *fichier=NULL;
	fichier=fopen (option3,"r");
	if (fichier==NULL)
		{
			return -1;
		}
	while(!feof(fichier))
	{
		fgets(phrase,300,fichier);
		entier++;
	}
	rewind(fichier);
			if(strcmp(option1,"-n")==0 && atoi(option2)>=0 && nb_option==4)
				{
					while(!feof(fichier))
						{
							fgets(mot,300,fichier);
							if (i>=entier-atoi(option2)-2)
									printf("%s",mot);
							i++;
						}

				}
				
	fclose(fichier);
return 0;
}
int option_v(int nb_option ,char *option1, char *option2 )
{
	char mot[300],phrase[300];
	int i=0,j=0,entier=0;
	printf("==>  %s  <==\n",option2);
	FILE *fichier=NULL;
	fichier=fopen (option2,"r");
	if (fichier==NULL)
			return -1;
	while(!feof(fichier))
	{
		fgets(phrase,300,fichier);
		entier++;
	}
	rewind(fichier);
			if (strcmp(option1,"-v")==0 && nb_option==3)
				{
					while(!feof(fichier))
						{
							fgets(mot,300,fichier);
							if (i>=entier-10)
									printf("%s",mot);
							i++;
						}
				}
	fclose(fichier);
	return 0;
}
int option_f(int nb_option ,char *option1, char *option2 )
{	
	bool running=1;
	while(running)
		{
			char mot[300],phrase[300];
			int i=0,j=0,entier=0;
			FILE *fichier=NULL;
			fichier=fopen (option2,"r");
			if (fichier==NULL)
				{
					return -1;
				}
			while(!feof(fichier))
				{
					fgets(phrase,300,fichier);
					entier++;
				}
			rewind(fichier);
			if (strcmp(option1,"-f")==0 && nb_option==3)
				{
					while(!feof(fichier))
						{
							fgets(mot,300,fichier);
							printf("%s",mot);
							i++;
						}
				}
			fclose(fichier);
			sleep(1);	
			system("clear");

	}
	return 0;
}
void option__version(int nb_option ,char *option1 )
{
	printf("tail GNU 0.0\nCopyright (C) 2024 Free Software Foundation, Inc.\nThis is free software: you are free to change and redistribute it.\nThere is NO WARRANTY, to the extent permitted by law.\nWritten by Niaina Gilbert.\n");
}
int option_c(int nb_option, char *option3 ,char *option1, char *option2 )
{
char mot[300],phrase[300];
	int i=0,j=0,entier=0;
	FILE *fichier=NULL;
	fichier=fopen (option3,"r");
	if (fichier==NULL)
		{
			return -1;
		}
	while(!feof(fichier))
	{
		fgets(phrase,300,fichier);
		entier++;
	}
	rewind(fichier);
			if(strcmp(option1,"-c")==0 && atoi(option2)>=0 && nb_option==4)
				{
					while(!feof(fichier))
						{
							fgets(mot,300,fichier);
							if (i>=entier-atoi(option2)-2)
							i++;
						}
					for (i=strlen(mot)-atoi(option2);i<strlen(mot);i++)
						{
							printf("%c",mot[i]);
						}

				}
	fclose(fichier);
}
void option__help(int nb_option ,char *option1 )
{
	printf("Usage: tail [OPTION]... [FILE]...\nPrint the last 10 lines of each FILE to standard output.\nWith more than one FILE, precede each with a header giving the file name.\nMandatory arguments to long options are mandatory for short options too.\n  -c, --bytes      output the last NUM bytes\n  -f, --follow[={name|descriptor}]\n                           output appended data as the file grows;\n                             an absent option argument means 'descriptor'\n  -n, --lines      output the last NUM lines, instead of the last 10\n  -q, --quiet, --silent    never output headers giving file names\n  -v, --verbose            always output headers giving file names\n      --help     display this help and exit\n      --version  output version information and exit\n");
}
int option_vide(int nb_option, char **option)
{
	
	char mot[300],phrase[300];
	int i=0,j=0,entier=0;
	for (i=1;i<nb_option;i++)
	{
	FILE *fichier=NULL;
	fichier=fopen (option[i],"r");
	if (fichier==NULL)
		{
			return -1;
		}
	while(!feof(fichier))
	{
		fgets(phrase,300,fichier);
	}
	rewind(fichier);
					while(!feof(fichier))
						{
							fgets(mot,300,fichier);
						}

				
	fclose(fichier);
	}
return 0;
}
