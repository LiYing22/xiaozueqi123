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

char do_real_c;

extern void get_int_name();

void get_real()
{
	int RIGHT_p = 0;
	memset(RIGHT, 0, sizeof(RIGHT));
	
	while ((do_real_c = getchar()) != ';')
	{
		if(isdigit(do_real_c)||do_real_c=='.')
			RIGHT[RIGHT_p++] = do_real_c;
	}
	ungetc(do_real_c, stdin);
}

void do_real()
{
	while ((do_real_c = getchar()) != ';')
	{
		ungetc(do_real_c, stdin);
		get_int_name();
		VariableName[name] = " real";

		while ((do_real_c = getchar()) == ' ');
		if (do_real_c == ',') continue;
		else if (do_real_c == '=')
		{
			strcpy(LEFT, name);
			memset(RIGHT, 0, sizeof(RIGHT));
			get_real();
			strcat(RIGHT, " real");
			VariableName[LEFT] = RIGHT;
		}
		else if (do_real_c == ';') break;
	}
}