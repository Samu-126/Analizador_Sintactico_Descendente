#ifndef GLOBAL_H
#define GLOBAL_H

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define TAMBUFF 128
#define NINGUNO -1
#define FDC     '\0'

#define NUM     256
#define DIV     257
#define MOD     258
#define ID      259
#define FIN     260

extern int valcomplex;
extern int numlinea;

struct entrada {
    char *aplex;
    int complex;
};

extern struct entrada tablasimb[];

int analex(void);
void analsint(void);
void inic(void);
int busca(const char *s);
int inserta(const char *s, int clex);
void emite(int t, int tval);
void error(const char *m);

#endif
