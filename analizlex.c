#include "global.h"
#include "analizlex.h"
#include "_error.h"
#include "simbolos.h"

char buflex[TAMBUFF];
int numlinea = 1;
int valcomplex = NINGUNO;

int analex(struct entrada *tablasimb, int *vp){ /* analizador léxico */
	int t;
	while(1) {
		t = getchar();
		if (t == ' ' || t == '\t')
			;			/* elimina espacio en blanco */
		else if (t == '\n')
			numlinea = numlinea + 1;
		else if (isdigit(t)){		/* t es una dígito */
			ungetc(t, stdin);
			scanf("%d", &valcomplex);
			return NUM;
		}
		else if (isalpha(t)){		/* t es una letra */
			int p, b = 0;
			while (isalnum(t)){	/* t es alfanumérico */
				buflex[b] = t;
				t = getchar();
				b = b + 1;
				if (b >= TAMBUFF)
					error("error del compilador");
			}
			buflex[b] = FDC;
			if(t != EOF)
				ungetc(t, stdin);
			p = busca(buflex, tablasimb);
			if (p == 0)
				p = inserta(buflex, ID, tablasimb);
			valcomplex = p;
			*vp = valcomplex;
			return tablasimb[p].complex;
		}
		else if (t == EOF)
			return FIN;
		else {
			valcomplex = NINGUNO;
			return t;
		}
	}
}
