/* error.c */ 
#include "global.h" 
/* Genera todos los mensajes de error e interrumpe la ejecucion */ 
error(m) 
    char *m; 
{ 
        fprintf(stderr, "línea %d: %s\\n", numlínea, m); 
        exit(1); /* terminación sin éxito \*/ 
}