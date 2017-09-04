#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "do_int.h"
#include <map>
extern map<string, string> VariableName;
char str1[10];
char name[10];
char LEFT[10];
char RIGHT[10];
char do_int_c;
int str1_p = 0;
void get_int_name()
{
	int name_p = 0;
	memset(name, 0, sizeof(name));
	do_int_c = getchar();
	while (!isalpha(do_int_c))//消除空格 
		do_int_c = getchar();
	for (; isalnum(do_int_c); do_int_c = getchar())
		name[name_p++] = do_int_c;
	ungetc(do_int_c, stdin);//将do_int_c退回到输入流。
}

int get_int_val()
{
	char do_int_num[10];
	int do_int_num_p = 0;
	memset(do_int_num, 0, sizeof(do_int_num));
	while ((do_int_c = getchar()) != ';')
	{
		if (isdigit(do_int_c))
		{
			do_int_num[do_int_num_p++] = do_int_c;
		}
	}
	ungetc(do_int_c, stdin);
	return atoi(do_int_num);
}

void do_int()
{
	while ((do_int_c = getchar()) != ';')
	{
		ungetc(do_int_c, stdin);
		get_int_name();
		VariableName[name] = " int";

		while ((do_int_c = getchar()) == ' ');
		if (do_int_c == ',') continue;
		else if (do_int_c == '=')
		{
			strcpy(LEFT, name);
			memset(RIGHT, 0, sizeof(RIGHT));
			_itoa(get_int_val(), RIGHT, 10);
			strcat(RIGHT, " int");
			VariableName[LEFT] = RIGHT;
		}
		else if (do_int_c == ';') break;
	}
}