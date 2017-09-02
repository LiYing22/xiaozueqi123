#include <iostream>
#include "token.h"
#include "define.h"
using namespace std;
char out_s[100];
void do_out()
{
	int out_temp,out_num=0,i_out;//out_num代表循环次数
	char c_out;
	while (1)
	{
		switch (get_token())
		{
		case SEMICOLON:
			{
			break;
			}
		case DELIMITER:
     		{
			if ((c_out = getchar()) == '"')
			{
				for (i_out = 0; i_out < out_num; i_out++)
				{
					while ((c_out = getchar()) != '"')
					{
						if (c_out == '\\' && (c_out = getchar()) == 'n')
							cout << endl;
						else cout << c_out;
					}
				}
			}
			else cout << out_num;
	    	}//case end
		case Double_quotes:
    		{
			 
			while ((c_out = getchar()) != '"')
			  {
				if (c_out == '\\' && (c_out = getchar()) == 'n')
					cout << endl;
				else cout << c_out;
			  }
			 if ((c_out = getchar()) != ';')
			 {
				get_token();
				cout << out_num;
			 }
    		}//case end
		case INTLITERAL:
     		{
			out_temp = 0;
			if ((c_out = getchar()) == '"')
			{
				int o_num = 0;//字符串长度表示。
				out_num = 3;
					while ((c_out = getchar()) != '"')
					{
						if (c_out == '\\' )
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
					for (i_out = 0; i_out < out_num; i_out++)
					{
						if (out_temp == 1) cout << out_s << endl;
						else cout << out_s;
					}
			}
	     	}//case end
		}

	}
}