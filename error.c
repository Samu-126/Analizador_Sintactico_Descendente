/* error.c */ 
#include "global.h" 
/* Genera todos los mensajes de error e interrumpe la ejecucion */ 
void error(const char *m)
{ 
        fprintf(stderr, "línea %d: %s\n", numlinea, m);
        exit(1); /* terminación sin éxito \*/ 
}
