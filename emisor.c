#include "global.h"

void emite(t, tval)		/* genera la salida */
int t, tval;
{
	switch(t){
		case '+': case '-': case '*': case '/':
			printf("%c\n", t); break;
		case DIV:
			printf("DIV\n"); break;
		case MOD:
			printf("MOD\n"); break;
		case NUM:
			printf("%d\n"); break;
		case ID:
			printf("%s\n", tval); break;
		default:
			printf("complex %d, valcomplex %d\n", t, tval);
	}
}
