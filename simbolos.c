#include "global.h"
#include <string.h>

#define MAXLEX   999
#define MAXSIMB  100

char lexemas[MAXLEX];
int ultcar = -1;
struct entrada tablasimb[MAXSIMB];
int ultent = 0;

int busca(char s[])
{
    int p;

    for (p = ultent; p > 0; p = p - 1)
    {
        if (strcmp(tablasimb[p].aplex, s) == 0)
            return p;
    }

    return 0;
}

int inserta(char s[], int clex)
{
    int lon;

    lon = strlen(s);

    if (ultent + 1 >= MAXSIMB)
        error("tabla de símbolos llena");

    if (ultcar + lon + 1 >= MAXLEX)
        error("matriz de lexemas llena");

    ultent = ultent + 1;
    tablasimb[ultent].complex = clex;
    tablasimb[ultent].aplex = &lexemas[ultcar + 1];

    ultcar = ultcar + lon + 1;

    strcpy(tablasimb[ultent].aplex, s);

    return ultent;
}
