#include <iostream>
using namespace std;

typedef enum token_types {
	DELIMITER,//标示分隔符; | +-
	IDENTIFIER,//标示ID标示符 var hello
	KEYWORD,//关键字
	SSTRING,//字符串
	CHARACTOR,//字符
	NUMBER,//数字常量
	TYPE,//类型 typedef int int32;那么int32就被标示为TYPE

	PRECOMPILE,//预编译行 #define
	TEMP,//保留
	SEMICOLON,//分号。
	COMMA,  //逗号
	ASSIGNOP,//赋值

	SCANEOF,  //文件结尾标记

	LPRAEN,   //左括号
	RPRAEN,   //右括号
	LBLOCK,//块标志 {
	RBLOCK,//块标志 }

	INTLITERAL, //没懂啥意思

	/* 算数运算 */
	OP_plus,  //加
	OP_minus, //减
	OP_multiply,//乘
	OP_divide,//除
	OP_mod,//模

	/* 关系运算 */
	OP_lt,            // 小于
	OP_gt,            // 大于
	OP_eq,            // 等于
	OP_le,            // 小于等于
	OP_ge,            // 大于等于
	OP_ne,            // 不等于

	/* 逻辑运算 */
	OP_and,           // 与
	OP_or,            // 或
	OP_not,           // 非

	//$连接
	OP_link,

	//#删除一个字符
	OP_delete,

	key_in,  // INPUT  
	key_out,      // PRINT  
	key_while,      // WHILE   
	key_if,         // IF  
	key_else,       // ELSE
	key_int,     //int
	key_real,     //实数
	key_string   //字符串


} token;
void clear_buffer();
void buffer_char(char ch);
void lexical_error(char);
token check_reserved();
token get_token(void);
token check_reserved();