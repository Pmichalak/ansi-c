#include <stdio.h>
#include <stdlib.h>
#include <conio.h>  

struct Node
	{
		char dane;
		struct Node *next;
	};
typedef struct Node *NodePtr;

int dlugosc(Node *root)
{
	Node *tmp=root;
	int dlugosc=0;
	while(tmp)
	{
		dlugosc++;
		tmp=tmp->next;
	}
	return dlugosc;
}

/* Deklaracja funkcji dodajacej element do nieuporz�dkowanej
   listy jednokierunkowej */
int DodajElm (NodePtr *startPtr, char WstZnak) {
	struct Node *newPtr, *currPtr;
/* Utw�rz element Node */
    newPtr = (struct Node *)malloc(sizeof(struct Node));
	if (newPtr == NULL)  /* weryfikacja przydzielonej pami�ci*/ 
		return 1;
	else 
	{   /* Ustal dane elementarne w Node */
		newPtr -> dane = WstZnak;
		newPtr -> next = NULL;

        if (*startPtr == NULL)
		/* Wstaw element jako pierwszy w li�cie */
       			*startPtr = newPtr;
        else
        {
           currPtr = *startPtr;   /* ustaw wska�nik na g�ow� listy */
 		   // Wstaw element na ko�cu listy
		   while (currPtr->next != NULL)
   				currPtr = currPtr -> next;
            currPtr->next = newPtr;
         }
     }
		return 0;
}


int main(void)
{
NodePtr poczListy; char Znak;
struct Node *biezacyPtr, *elementPtr;	

 // Tworzenie listy
	poczListy=NULL;
	printf("Wprowadz znak\n");
	Znak=getche();
	while (Znak!='/') {
		DodajElm(&poczListy, Znak);
		printf("\nWprowadz kolejny znak\n");
		Znak=getche();
	}
	printf("\nKoniec tworzenia listy");

//Przegl�danie listy
		biezacyPtr=poczListy;
 	printf("\nPrzegladanie listy\n");
	while (biezacyPtr!=NULL) {
        Znak=biezacyPtr->dane;
		printf("%c\n",Znak);
		biezacyPtr=biezacyPtr->next;
	}

	int dlg=dlugosc(poczListy);
	printf("\nDlugosc listy to: %d\n", dlg);
	
	printf("\nKoniec przegladania listy");
    getche();
	return 0;
}

