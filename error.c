/* error.c */ 
#include <stdlib.h>
#include "global.h" 
#include "_error.h"

/* Genera todos los mensajes de error e interrumpe la ejecucion */ 
void error(char *m) 
{ 
        fprintf(stderr, "línea %d: %s\\n", numlinea, m); 
        exit(1); /* terminación sin éxito \*/ 
}