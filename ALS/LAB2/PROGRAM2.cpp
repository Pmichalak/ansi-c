#include <stdio.h>
#include <stdlib.h>
struct Node {
  int dane;
  struct Node *next;
};
typedef struct Node *NodePtr; //wlasny typ dla zamieszania
// Deklaracje funkcji
//**********************************
void wstaw(Node **root, int wartosc);
void wyswietl(Node **root);
void odwroc1 (Node *head);
void rotate1(Node** head);
void usun(Node **listP, int value);
// Deklaracje funkcji
//**********************************
int main(void)
{
NodePtr poczListy; int PodanaCyfra;
struct Node *biezacyPtr, *elementPtr;
 // Tworzenie listy
 poczListy=NULL;
 printf("Wprowadz Cyfre: ");
 scanf("%d", &PodanaCyfra);
 while (PodanaCyfra!=-1) {
  wstaw(&poczListy, PodanaCyfra);
  printf("Wprowadz kolejna Cyfre: ");
  scanf("%d", &PodanaCyfra);
 }
 printf("Koniec tworzenia listy\n");
 wyswietl(&poczListy);
 printf("\nPodaj element do usuniecia: ");
 scanf("%d", &PodanaCyfra);
 usun(&poczListy, PodanaCyfra);
 //usun(&poczListy, PodanaCyfra);
    wyswietl(&poczListy);
    odwroc1(poczListy);
    rotate1(&poczListy);
   // zamiendwa(&poczListy);
    wyswietl(&poczListy);
    system("PAUSE");
 return 0;
}
// Definicje funkcji
void wstaw(Node **root, int wartosc) {

      struct Node *tymczasowy;
      struct Node *newPtr;
      newPtr = (struct Node *)malloc(sizeof(Node));
      //malokowanie pamieci na nowy wsk
      newPtr->dane = wartosc;
      newPtr->next = NULL;
      //takie przeslanie jak w konstruktorze
      //jak w normalnym jezyku
      if (!*root) *root=newPtr; //jak roocik jest pusty
      else {//inaczej
           tymczasowy = *root;
           if (wartosc <= tymczasowy->dane) {
              //jak mi wpasnie na korzen to mam prosto
              //dodaje na korzen a stary tylko sobie przesune
              newPtr->next = *root;
              *root = newPtr;
           } else {
               //shody musze w dobry punkt wpasc
             while ((tymczasowy->next)&&(tymczasowy->next->dane <= wartosc)){
                 //przesuwam w celu dobrego punktu
                tymczasowy = tymczasowy->next;
             }
             if (!tymczasowy->next){
                 //jak przejrzalem cala liste i nie bylo mniejszego od mojego
                 //to musze dodac sobie na koniec nowy
                  tymczasowy->next = newPtr;
             }
             else {
                //podpinam do roota,tymczasowy = root
                //dzieki przesuwaniu mam pewnosc iz w dobrym punkcje jestem
                  newPtr->next = tymczasowy->next;
                  tymczasowy->next = newPtr;
             }
           }
      }
}
void wyswietl(Node **root) {

    struct Node *tymczasowy;
    tymczasowy = *root;
  printf("\nPrzegladanie listy\n--------------------------\n");
 while (tymczasowy) {
  printf("%d\n",tymczasowy->dane);
  tymczasowy=tymczasowy->next;
 }
 printf("------------------------------\nKoniec przegladania listy\n");

}

void odwroc1 (Node *head){
    Node *a=head->next; // aktualny
    Node *p=NULL; // poprzedni
    Node *n=NULL; // nastepny
    
    while (a!=NULL){
        n=a->next;
        a->next=p;
        p=a;
        a=n;    
    } 
    head->next=p;
}
void rotate1(Node** head){      
      Node* walk= (*head);     
      Node* walk1= (*head);    
      Node* prev= (*head);     
      int temp= walk->dane;      
      while(walk->next!=NULL){          
      walk->dane=walk->next->dane;          
      walk= walk->next;         }      
       walk->dane=temp;
       } 
void usun(Node **listP, int value)
{
  Node *currP, *prevP;

  /* For 1st node, indicate there is no previous. */
  prevP = NULL;

  /*
   * Visit each node, maintaining a pointer to
   * the previous node we just visited.
   */
  for (currP = *listP;
 currP != NULL;
 prevP = currP, currP = currP->next) {

    if (currP->dane == value) {  /* Found it. */
      if (prevP == NULL) {
        /* Fix beginning pointer. */
        *listP = currP->next;
      } else {
        /*
         * Fix previous node's next to
         * skip over the removed node.
         */
        prevP->next = currP->next;
      }

      /* Deallocate the node. */
      free(currP);

      /* Done searching. */
      return;
    }
  }
}

