/**** analizsint.c *************************************************/
#include "analizsint.h"
#include "analizlex.h"
#include "emisor.h"
#include "_error.h"
#include "global.h"

int preanalisis;

/* Funcion principal que arranca el analisis sintactico */
void analsint()
{
    preanalisis = analex();

    while (preanalisis != FIN)
    {
        expr();
        parea(';');
    }
}

/* Reconoce terminos separados por suma (+) o resta (-) */
void expr()
{
    int t;

    termino();

    while (1)
    {
        switch (preanalisis)
        {
            case '+':
            case '-':
                t = preanalisis;
                parea(preanalisis);
                termino();
                emite(t, NINGUNO);
                continue;

            default:
                return;
        }
    }
}

/* Reconoce factores separados por multiplicacion (*), division (/), DIV o MOD */
void termino()
{
    int t;

    factor();

    while (1)
    {
        switch (preanalisis)
        {
            case '*':
            case '/':
            case DIV:
            case MOD:
                t = preanalisis;
                parea(preanalisis);
                factor();
                emite(t, NINGUNO);
                continue;

            default:
                return;
        }
    }
}

/* Reconoce expresiones entre parentesis, numeros o identificadores */
void factor()
{
    switch (preanalisis)
    {
        case '(':
            parea('(');
            expr();
            parea(')');
            break;

        case NUM:
            emite(NUM, valcomplex);
            parea(NUM);
            break;

        case ID:
            emite(ID, valcomplex);
            parea(ID);
            break;

        default:
            error("Error de sintaxis");
            break;
    }
}

/* Comprueba el token actual y avanza */
void parea(int t)
{
    if (preanalisis == t)
        preanalisis = analex();
    else
        error("Error de sintaxis");
}