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

void usun(Node** root, char Znak)
{
	Node *szukanie=*root;
	Node *poprzedni=*root;
	while(szukanie!=NULL && szukanie->dane!=Znak)
	{
		poprzedni=szukanie;
		szukanie=szukanie->next;
	}
	if (szukanie!=NULL)
	{
		if(szukanie==poprzedni)
		{
			Node* kasuj=*root;
			*root=(*root)->next;
			free(kasuj);
			return;
		}
		Node* kasuj=szukanie;
		poprzedni->next=kasuj->next;
		free(kasuj);
	}
	else
		printf("element nie wystapil lub lista jest pusta\n");	
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
	
    char x;
    printf("podaj znak do usuniecia: ");
	scanf("%c", &x);
	usun(&poczListy, x);

	dlg=dlugosc(poczListy);
	printf("\nDlugosc listy po usunieciu znaku to: %d\n", dlg);

	biezacyPtr=poczListy;
 	printf("\nPrzegladanie listy\n");
	while (biezacyPtr!=NULL) {
        Znak=biezacyPtr->dane;
		printf("%c\n",Znak);
		biezacyPtr=biezacyPtr->next;
	} 
	printf("\nKoniec przegladania listy");
    getche();
	return 0;
}

