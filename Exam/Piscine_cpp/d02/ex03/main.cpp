/* evaluation d'une formule arithmetique (+, -, * et entiers) et sans vraies parentheses */

#include <stdio.h>

/* à cause de strtol() */
#include <stdlib.h>

#define Base 10

/* a est la chaine à évaluer, les nombres sont écrits en base 10 */
int calcul (char *a)
{
	char *p = a;
	char *r = a;
	char **q = &r;
	/*
	 * La chaine est vue comme une grande somme/différence de termes qui sont des produits.
	 * Chaque produit est placé dans P et une fois complètement calculé, il est ajouté à S.
	 * La chaine  est supposée bien construite ie elle représente une formule mathématique valide.
	 * */
	int P = 1, S = 0;
	char signe = '+';
	/* tant qu'on a pas examiné toute la chaine */
	while (**q != '\0')
	{
		do /* Evaluation du produit courant */
		{
			if (*p == '(')
			{
				p++;
				P *= strtol (p, q, Base);
				*q = *q + 1;
				p = *q + 1;
			}
			else
				P *= strtol (p, q, Base);
			p = *q + 1;
		}
		while (**q == '*');
		/* On ajoute ou on retranche le produit au S courant */
		if (signe == '+')
			S += P;
		else
			S -= P;
		/* on réinitialise */
		signe = **q;
		P = 1;
	}
	return S;
}

int main (void)
{/* Exemple illustratif */
	char a[] = "2 *3+8*2*4-8*4*2+8*(-9)*(-7)-8*(-10)*5-9*(-7)*(-9)*11+(-2)*3+5555";

	printf ("%s =\n%d\n", a, calcul (a));
	return 0;
}
