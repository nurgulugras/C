#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>
void islemler(void)
{
	int i,j,toplam=0,fark,sayac=0,dizi[3],rastgele,ort;
	char cevap;
	printf("Oyuna baslamak icin bir tusa basiniz..\n");
	getch();
	cevap='e';	
		
    while(cevap=='e'|| cevap=='E') 
  {
	srand(time(0));
	for(i=0; i<3; i++)
	{
	dizi[i]=rand()%98+1;
	printf("Pul %d = %d\n",i+1,dizi[i]);
    toplam=dizi[0]+dizi[1]+dizi[2];
    }
   int mak=dizi[0];
   int min=dizi[0];
	for(i=0; i<3; i++)
    {
    	if(min>dizi[i])
    	min=dizi[i];
        if(mak<dizi[i])
    	mak=dizi[i];
    	fark=mak-min;
    }
    for(i=0; i<3; i++)
	{
    	if(dizi[i]!=mak && dizi[i]!=min)
    	ort=dizi[i];
    }
    for(j=1;j<toplam;j++)
	{
	      if(toplam%j==0)
	    {
		   sayac=1;
		   break;
		}  else
		   sayac=0;
	}
    if(toplam<150)
		printf("Tebrikler,kazandiniz.(1.kural)");
	else if(fark>ort)
	    printf("Tebrikler,kazandiniz.(3.kural)");
	else if(sayac==0)
	    printf("Tebrikler,kazandiniz.(2.kural)");
	else
	    printf("Maalesef kaybettiniz..!");
	    printf("\n");

        printf("Oyuna devam icin [e/E]?");
	    cevap=getche();	printf("\n");
	  
 }
} 

int main(void)
{
	islemler();
	return 0;
}
	
