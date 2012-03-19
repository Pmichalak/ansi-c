#include<stdlib.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
    
    unsigned char bufor_wejscia[999];
    int indeks = 0;
    int n,lwz;
    char *nazwa_pliku_in;
    char *nazwa_pliku_out;
    nazwa_pliku_in=argv[1]; 
    nazwa_pliku_out=argv[2]; 
    FILE *wskaznik_pliku=NULL;
    wskaznik_pliku=fopen(nazwa_pliku_in,"r"); 
    printf( "Czytanie pliku %s do wyznaczenia liczbyznakow. \n", nazwa_pliku_in); 	
    while(n=fread(bufor_wejscia,sizeof(unsigned char),300,wskaznik_pliku)) 
    {
            lwz+=n;
    }
    printf("liczba wszystkich znakow w pliku: %d\n", lwz);
    FILE *fp;
    fp = fopen (nazwa_pliku_out, "w");
if( fp == NULL )
  {
  printf("błąd otwarcia pliku");
  exit(-10);
  }
  fprintf (fp, "%d", lwz-1); /* zapisz nasz ³añcuch w pliku */
}

