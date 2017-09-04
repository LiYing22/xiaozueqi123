#include <stdio.h>
#include <map>
#include <string>
#include "token.h"
#include "define.h"
using namespace std;
char out_s[100];

extern map<string, string> VariableName;

void do_out()
{
	int out_temp, out_num = 0, i_out;//out_num代表循环次数
	char c_out;
	char *c_out_place=NULL;
	const char *out_num_temp;
	char out_num_string[100];//数字字符串。
	char out_num_str[100];
	switch (get_token())
	{
	case SEMICOLON:
	{
		break;
	}
	case IDENTIFIER:
	{
		while ((c_out = getchar()) == ' ');
		if (c_out == ',')
		{
			out_temp = 0;
			memset(out_num_str, 0, sizeof(out_num_str));
			map<string, string>::iterator iter;
			iter = VariableName.find(token_buffer);
			if (iter != VariableName.end())
			{
				out_num_temp = iter->second.c_str();
				strcpy(out_num_string, out_num_temp);
				while (out_num_string[out_temp] != ' ')
				{
					out_num_str[out_temp] = out_num_string[out_temp];
					out_temp++;
				}
				out_num = atoi(out_num_str);
			}
			out_temp = 0;
			memset(out_s, 0, sizeof(out_s));
			while ((c_out = getchar()) == ' ');
			if (c_out == '"')
			{
				int o_num = 0;//字符串长度表示。
				while ((c_out = getchar()) != '"')
				{
					if (c_out == '\\')
					{
						if ((c_out = getchar()) == 'n')
						{
							out_temp = 1;
						}
					}
					else
					{
						out_s[o_num] = c_out;
						o_num++;
					}

				}
				while ((c_out = getchar()) != ';');
				for (i_out = 0; i_out < out_num; i_out++)
				{
					if (out_temp == 1) cout << out_s << endl;
					else cout << out_s;
				}
			}
		}
		else 
		{
			out_temp = 0;
			memset(out_num_str, 0, sizeof(out_num_str));
			map<string, string>::iterator iter;
			iter = VariableName.find(token_buffer);
			if (iter != VariableName.end())
			{
				out_num_temp = iter->second.c_str();
				strcpy(out_num_string, out_num_temp);
				while (out_num_string[out_temp] != ' ')
				{
					out_num_str[out_temp] = out_num_string[out_temp];
					out_temp++;
				}
				out_num = atoi(out_num_str);
				cout << out_num;
				while (c_out != ';')
				{
					if (c_out == '\\' && (c_out = getchar()) == 'n');
					cout << endl;
					c_out = getchar();
				}
			}

		}
		break;
	}//case end
	case Double_quotes:
	{
		out_temp = 0;
		while ((c_out = getchar()) != '"')
		{
			if (c_out == '\\' && (c_out = getchar()) == 'n')
				cout << endl;
			else cout << c_out;
		}
		while ((c_out = getchar()) == ' ');
		if (c_out != ';')
		{
			get_token(); 
			memset(out_num_str, 0, sizeof(out_num_str));
			map<string, string>::iterator iter;
			iter = VariableName.find(token_buffer);
			if (iter != VariableName.end())
			{
				out_num_temp = iter->second.c_str();
				strcpy(out_num_string, out_num_temp);
				while (out_num_string[out_temp] != ' ')
				{
					out_num_str[out_temp] = out_num_string[out_temp];
					out_temp++;
				}
				out_num=atoi(out_num_str);
				cout << out_num;
				while ((c_out = getchar()) != ';')
				{
					if (c_out == '\\' && (c_out = getchar()) == 'n');
					cout<<endl;
				}
			}
		 }
		break;
	}//case end
	case INTLITERAL:
	{
		out_temp = 0;
		out_num = atoi(token_buffer);
		while ((c_out = getchar()) == ' ');
		if (c_out == ',')
		{
			while ((c_out = getchar()) == ' ');
			if (c_out == '"')
			{
				int o_num = 0;//字符串长度表示。

				while ((c_out = getchar()) != '"')
				{
					if (c_out == '\\')
					{
						if ((c_out = getchar()) == 'n')
						{
							out_temp = 1;
						}
					}
					else
					{
						out_s[o_num] = c_out;
						o_num++;
					}

				}
				while ((c_out = getchar()) != ';');
				for (i_out = 0; i_out < out_num; i_out++)
				{
					if (out_temp == 1) cout << out_s << endl;
					else cout << out_s;
				}
			}
		}
		break;
	}//case end
	}
}