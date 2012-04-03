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

void bubble_sort ( int n )
{
    int i, j, k, temp ;
    el_listy *p, *q ;

    k = n ;
    for ( i = 0 ; i < n - 1 ; i++, k-- )
    {
        p = first ;
        q = p -> next ;

        for ( j = 1 ; j < k ; j++ )
        {
            if ( p -> val > q -> val )
            {
                temp = p -> val ;
                p -> val = q -> val ;
                q -> val = temp ;
            }
            p = p -> next ;
            q = q -> next ;
        }
    }
}
 
 int main ()
 {
   first = malloc (sizeof(el_listy));
   first->val = 4;
   first->next = NULL;
   dodaj_do_listy(first,3);
   bubble_sort(2);
   wypisz_liste(first);
   //free(first);
   return 0;
 }
