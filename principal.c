#include <stdlib.h>
#include "inic.h"
#include "analizsint.h"
#include "simbolos.h"
#include "global.h"

int main()
{
    struct entrada tablasimb[MAXSIMB];
    inic();
    analsint(tablasimb);
    exit(0);    /* terminación con éxito */
}
