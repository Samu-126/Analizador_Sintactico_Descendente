#include "global.h"

void emite(int t, int tval)		/* genera la salida */
{
	switch(t){
		case '+': case '-': case '*': case '/':
			printf("%c\n", t); break;
		case DIV:
			printf("DIV\n"); break;
		case MOD:
			printf("MOD\n"); break;
		case NUM:
			printf("%d\n", tval); break;
		case ID:
			printf("%s\n", tablasimb[tval].aplex); break;
		default:
			printf("complex %d, valcomplex %d\n", t, tval);
	}
}
