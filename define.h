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

extern VARTANT memory[2000];//�ڴ��������