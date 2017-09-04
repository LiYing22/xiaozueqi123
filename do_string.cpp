#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

#include "do_int.h"	
#include "do_string.h"
#include <map>
extern map<string, string> VariableName;

extern char str1[10];
extern char name[10];
extern char LEFT[10];
extern char RIGHT[10];

char do_string_c;

extern void get_int_name();

void get_string()
{	
	int RIGHT_p= 0;
	memset(RIGHT, 0, sizeof(RIGHT));
	while ((do_string_c = getchar()) != '"');
	while ((do_string_c = getchar()) != '"')
	{
		RIGHT[RIGHT_p++] = do_string_c;
	}
	while ((do_string_c = getchar()) != ';');
	ungetc(do_string_c, stdin);
}

void do_string()
{
	while ((do_string_c = getchar()) != ';')
	{
		ungetc(do_string_c, stdin);
		get_int_name();
		VariableName[name] = " string";

		while ((do_string_c = getchar()) == ' ');
		if (do_string_c == ',') continue;
		else if (do_string_c == '=')
		{
			strcpy(LEFT, name);
			memset(RIGHT, 0, sizeof(RIGHT));
			get_string();
			strcat(RIGHT, " string");
			VariableName[LEFT] = RIGHT;
		}
		else if (do_string_c == ';') break;
	}
}