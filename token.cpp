#include <iostream>
#include <string>
#include "token.h"
#include "define.h"
using namespace std;

int p_ = 0,token_i;
extern char token_buffer[200];
void clear_buffer()
{
	for (token_i = 0; token_i < 100; token_i++)
	{
		token_buffer[token_i] = 0;
	}
}

void buffer_char(char ch)
{
	token_buffer[p_] = ch;
	p_++;
}

void lexical_error(char)
{
	cout << "lexical_error!" << endl;
}

token check_reserved();

token get_token(void)
{
	int in_char, c;
	clear_buffer();
	if (feof(stdin))
		return SCANEOF;

	while ((in_char = getchar()) != EOF)
	{
		if (isspace(in_char))
			continue;
		else if (isalpha(in_char))//判断字符ch是否为英文字母，若为英文字母，返回非0（小写字母为2，大写字母为1）。若不是字母，返回0。
		{
			buffer_char(in_char);
			for (c = getchar(); isalnum(c) ; c = getchar())//判断字符变量c是否为字母或数字，若是则返回非零，否则返回零。
				buffer_char(c);
			ungetc(c, stdin);//将c退回到输入流。
			return check_reserved();
		}
		else if (isdigit(in_char))
		{
			buffer_char(in_char);
			for (c = getchar(); isdigit(c); c = getchar());
			buffer_char(c);
			ungetc(c, stdin);
			return INTLITERAL;
		}
		else if (in_char == '(')
			return LPRAEN;
		else if (in_char == ')')
			return RPRAEN;
		else if (in_char == ';')
			return SEMICOLON;
		else if (in_char == ',')
			return COMMA;
		else if (in_char == '+')
			return OP_plus;
		/*	else if (in_char == ':')
		{
		ungetc(c, stdin);
		lexical_error(in_char);
		*/
		else if (in_char == '=')
		{
			c = getchar();
			if (c == '=')
				return OP_eq;
			else
			{
				ungetc(c, stdin);
				return ASSIGNOP;
			}

		}
		else if (in_char == '-')
		{
			return OP_minus;
		}
		else if (in_char == '/')
		{
			c = getchar();
			if (c == '/')
			{
				while ((in_char = getchar()) != '\n');
			}
		}
		else if (in_char == '"')
		{
			return Double_quotes;
		}
		else if (in_char == '*')
		{
			return OP_multiply;
		}
		else if (in_char == '/')
		{
			return OP_divide;
		}
		else if (in_char == '%')
		{
			return OP_mod;
		}
		else if (in_char == '<')
		{
			c = getchar();

			if (c == '=')
				return OP_le;
			else if (c == '>')
			{
				return OP_ne;
			}
			else
			{
				ungetc(c, stdin);
				return OP_lt;
			}
		}
		else if (in_char == '>')
		{
			c = getchar();
			if (c == '=')
			{
				return OP_ge;
			}
			else
			{
				ungetc(c, stdin);
				return OP_gt;
			}
		}
		else if (in_char == '&')
		{
			c = getchar();
			if (c == '&')
			{
				return OP_and;
			}
			else lexical_error(in_char);
		}
		else if (in_char == '|')
		{
			c = getchar();
			if (c == '|')
			{
				return OP_or;
			}
			else lexical_error(in_char);
		}
		else if (in_char == '!')
		{
			return OP_not;
		}
		else if (in_char == '$')
		{
			return OP_link;
		}
		else if (in_char == '#')
		{
			return OP_delete;
		}
		else lexical_error(in_char);
	}
}
token check_reserved()
{
	if (!strcmp(token_buffer, "in"))
	{
		return key_in;
	}
	else if (!strcmp(token_buffer, "out"))
	{
		return key_out;
	}
	else if (!strcmp(token_buffer, "while"))
	{
		return key_while;
	}
	else if (!strcmp(token_buffer, "if"))
	{
		return key_if;
	}
	else if (!strcmp(token_buffer, "else"))
	{
		return key_else;
	}
	else if (!strcmp(token_buffer, "int"))
	{
		return key_int;
	}
	else if (!strcmp(token_buffer, "real"))
	{
		return key_real;
	}
	else if (!strcmp(token_buffer, "string"))
	{
		return key_string;
	}
	else 
	{
		return DELIMITER;
	}
}