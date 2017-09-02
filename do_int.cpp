#include <iostream>
#include "token.h"
#include "define.h"
using namespace std;
void do_int()
{

	while (1)
	{
		switch (get_token())
		{
		case IDENTIFIER:
		{
			
		}
		case COMMA: continue;
		default: break;
		}
	}
}