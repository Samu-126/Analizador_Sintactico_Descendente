#include "global.h"

struct entrada palsclave[] = {
    {"div", DIV},
    {"mod", MOD},
    {NULL, 0}
};

void inic(void)
{
    struct entrada *p;

    for (p = palsclave; p->complex; p++)
    {
        inserta(p->aplex, p->complex);
    }
}
