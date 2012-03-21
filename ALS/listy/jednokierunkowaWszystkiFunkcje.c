 #include <stdio.h>
 #include <stdlib.h>
 
 typedef struct element {
   struct element *next;
   unsigned long val;
 } el_listy;
 
 el_listy *first;
 
 void dodaj_do_listy (el_listy *lista, unsigned long liczba)
 {
   el_listy *wsk, *nowy;
   wsk = lista;
   while (wsk->next != NULL)
     { 
     wsk = wsk->next; /* przesuwamy wsk aż znajdziemy ostatni element */
     }
   nowy = malloc (sizeof(el_listy));
   nowy->val = liczba;
   nowy->next = NULL;
   wsk->next = nowy; /* podczepiamy nowy element do ostatniego z listy */
 }
 
 void wypisz_liste(el_listy *lista)
 {
   el_listy *wsk=lista;
   while( wsk != NULL )
     {
     printf ("%lu\n", wsk->val);
     wsk = wsk->next;
     }
 }
 void usun_z_listy(el_listy *lista, int element)
 {
   el_listy *wsk=lista;
   while (wsk->next != NULL)
     {
     if (wsk->next->val == element) /* musimy mieć wskaźnik do elementu poprzedzającego */
       {
       el_listy *usuwany=wsk->next; /* zapamiętujemy usuwany element */
       wsk->next = usuwany->next;   /* przestawiamy wskaźnik next by omijał usuwany element */
       free(usuwany);               /* usuwamy z pamięci */
       } else
         {
         wsk = wsk->next;           /* idziemy dalej tylko wtedy kiedy nie usuwaliśmy */
         }                          /* bo nie chcemy zostawić duplikatów */
       }
 }
 
 int main ()
 {

   first = malloc (sizeof(el_listy));
   first->val = 2;
   first->next = NULL;

dodaj_do_listy(first,3);
   wypisz_liste(first);
   return 0;
 }
