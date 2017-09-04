//#include <map>
//map<string, string> VariableName;

typedef enum
{
	var_null,
	var_double,
	var_string
}variant_type;

typedef char STRING[128];

typedef struct
{
	variant_type type;
	union{
		double i;
		STRING s;
	};
}VARTANT;
extern char token_buffer[200];
extern VARTANT memory[2000];//内存设多大合适