/**** analizsint.c *************************************************/
#include "analizsint.h"
#include "analizlex.h"
#include "emisor.h"
#include "_error.h"
#include "global.h"

int preanalisis;

/* Funcion principal que arranca el analisis sintactico */
void analsint(struct entrada *tablasimb)
{
    int valcomplex;
    preanalisis = analex(tablasimb, &valcomplex);

    while (preanalisis != FIN)
    {
        expr(tablasimb, valcomplex);
        parea(';', tablasimb, valcomplex);
    }
}

/* Reconoce terminos separados por suma (+) o resta (-) */
void expr(struct entrada *tablasimb, int valcomplex)
{
    int t;

    termino(tablasimb, valcomplex);

    while (1)
    {
        switch (preanalisis)
        {
            case '+':
            case '-':
                t = preanalisis;
                parea(preanalisis,tablasimb, valcomplex);
                termino(tablasimb, valcomplex);
                emite(t, NINGUNO);
                continue;

            default:
                return;
        }
    }
}

/* Reconoce factores separados por multiplicacion (*), division (/), DIV o MOD */
void termino(struct entrada *tablasimb, int valcomplex)
{
    int t;

    factor(tablasimb, valcomplex);

    while (1)
    {
        switch (preanalisis)
        {
            case '*':
            case '/':
            case DIV:
            case MOD:
                t = preanalisis;
                parea(preanalisis, tablasimb, valcomplex);
                factor(tablasimb, valcomplex);
                emite(t, NINGUNO);
                continue;

            default:
                return;
        }
    }
}

/* Reconoce expresiones entre parentesis, numeros o identificadores */
void factor(struct entrada *tablasimb, int valcomplex)
{
    switch (preanalisis)
    {
        case '(':
            parea('(', tablasimb, valcomplex);
            expr(tablasimb, valcomplex);
            parea(')', tablasimb, valcomplex);
            break;

        case NUM:
            emite(NUM, valcomplex);
            parea(NUM, tablasimb, valcomplex);
            break;

        case ID:
            emite(ID, valcomplex);
            parea(ID, tablasimb, valcomplex);
            break;

        default:
            error("Error de sintaxis");
            break;
    }
}

/* Comprueba el token actual y avanza */
void parea(int t, struct entrada *tablasimb, int valcomplex)
{
    if (preanalisis == t)
        preanalisis = analex(tablasimb, &valcomplex);
    else
        error("Error de sintaxis");
}