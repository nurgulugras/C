#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>
main()
   { 
  	 int i,j,sayi,a;
	 int rastgele;
	 int hazne[10]={0,0,0,0,0,0,0,0,0,0};
	 printf("Jeton sayisi:");
	 scanf("%d",&sayi);
	 printf("\n");
	 for(a=1; a<=sayi; a++)//girdiðim jeton sayýsýna göre döngüm devam edecek..
	 {
	    srand(time(NULL));
	    j=0;
		for(i=0; i<9; i++)	
		{   
			rastgele = rand () % 2;//burada çiviye çarpma durumu var 2 durum var saða ya da sola gidecek..
            if(rastgele==1)
            j++;
		}
		hazne[j] = hazne[j] + 1;//döngü saðlanýrsa haznem 1 artacak..
        printf("%2d. Jetonu atmak icin bir tusa basiniz ->",a);
        getch();
        printf("%2d. hazneye dustu.\n",j+1);
	 }
	 printf("\n");
     for(i=0;i<10;i++)
     {
        printf("%2d . Haznedeki jeton sayisi: %d\n",i+1, hazne[i]);
     }
     for (int j=0; i<9; j++)
     {
       if(a<hazne[i])
          a=hazne[i];//max jeton sayým hazne içindeki deðere eþit olmasý gerekiyor..
     }
       printf("\n"); 
       printf("Jetonlarin histogram seklinde dagilimlari:\n");
       
       for(int i=a; i>0; i--)
       {
            printf("\n%d|", i);
            for(int j=0; j<10; j++)
           {
               if(hazne[j]>=i)
                printf(" o |");//deðer saðlanýrsa alýnacak þekilleri buradan yaptým..
                else
                printf("   |");//deðilse boþ deðer alýcak..
           }
            printf("\n"); 
       }
     
      printf("-+---+---+---+---+---+---+---+---+---+---+\n");   
      printf(" | 1   2   3   4   5   6   7   8   9  10 |\n"); 
   }
