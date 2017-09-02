#include <iostream>
#include "token.h"
#include "define.h"
#include "do_out.h"
#define stack_size 500;
using namespace std;
token get_token();
char hang_[20];
char c_;
int weightmax; //���Ȩֵ��
int weight;   //��ǰʶ���ַ���Ȩֵ��

typedef enum
{
	left2right,
	right2left
}associativity;
typedef struct
{
	int  number_;//������
	int  icp;    //���ȼ�
	int  isp;    //���ȼ�
	associativity ass;   //�����
	token op;  //������
}OPERATOR;
static const OPERATOR operators[] =
{
	{ 2, 17, 1, left2right, LPRAEN },     // ������  
	{ 2, 17, 17, left2right, RPRAEN },    // ������  
	{ 2, 12, 12, left2right, OP_plus },      // ��  
	{ 2, 12, 12, left2right, OP_minus },     // ��  
	{ 2, 13, 13, left2right, OP_multiply },  // ��  
	{ 2, 13, 13, left2right, OP_divide },    // ��  
	{ 2, 13, 13, left2right, OP_mod },       // ģ  
	{ 2, 10, 10, left2right, OP_lt },        // С��  
	{ 2, 10, 10, left2right, OP_gt },        // ����  
	{ 2, 9, 9, left2right, OP_eq },          // ����  
	{ 2, 9, 9, left2right, OP_ne },          // ������  
	{ 2, 10, 10, left2right, OP_le },        // С�ڵ���
	{ 2, 10, 10, left2right, OP_ge },        // ���ڵ���  
	/* �߼����� */
	{ 2, 5, 5, left2right, OP_and },         // �� 
	{ 2, 4, 4, left2right, OP_or },          // ��  
	{ 1, 15, 15, right2left, OP_not },       // ��  
	/* ��ֵ */
	// BASIC �и�ֵ��䲻���ڱ��ʽ��  
	//{ 2, 2, 2, right2left, oper_assignment },  // ��ֵ  
	/* ��С���ȼ� */
	//{ 2, 0, 0, right2left, oper_min }      // ջ��  
};
char token_buffer[200];
void do_int();
int main()
{
    freopen("in.txt", "r", stdin);
	while (!feof(stdin))
	{
		weightmax = 0;
		while ((c_ = getchar()) !=EOF)
		{
			ungetc(c_, stdin);
			switch (get_token())
			{
			case key_out:
			{
				do_out();
				break;
			}
			case key_in:
			{
				//do_in();
				break;
			}
			case key_if:
			{
				//do_if();
				break;
			}
			case key_while:
			{
				//do_while();
				break;
			}
			case key_int:
			{
				//do_int();
				break;
			}
			case key_real:
			{
				//do_real();
				break;
			}
			case key_string:
			{
				//do_string();
				break;
			}
			}

		}
	}
	system("pause");
	return 0;
}
