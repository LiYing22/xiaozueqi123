#include <iostream>
#include "token.h"
#include "define.h"
using namespace std;
char out_s[100];
void do_out()
{
	int out_temp,out_num=0,i_out;//out_num����ѭ������
	char c_out;
		switch (get_token())
		{
		case SEMICOLON:
			{
			break;
			}
		case DELIMITER:
     		{
			while ((c_out = getchar()) == ' ');
			if (c_out  == '"')
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
				while ((c_out = getchar()) != ';');
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
			while ((c_out = getchar()) == ' ');
			 if (c_out!= ';')
			 {
				get_token();
				cout << out_num;
			 }
			 break;
    		}//case end
		case INTLITERAL:
     		{
			out_temp = 0;
			out_num = atoi(token_buffer);
			while ((c_out = getchar()) == ' ');
			if (c_out  == ',')
			{
				while ((c_out = getchar()) == ' ');
				if (c_out== '"')
				{
					int o_num = 0;//�ַ������ȱ�ʾ��

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