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
	 for(a=1; a<=sayi; a++)//girdi�im jeton say�s�na g�re d�ng�m devam edecek..
	 {
	    srand(time(NULL));
	    j=0;
		for(i=0; i<9; i++)	
		{   
			rastgele = rand () % 2;//burada �iviye �arpma durumu var 2 durum var sa�a ya da sola gidecek..
            if(rastgele==1)
            j++;
		}
		hazne[j] = hazne[j] + 1;//d�ng� sa�lan�rsa haznem 1 artacak..
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
          a=hazne[i];//max jeton say�m hazne i�indeki de�ere e�it olmas� gerekiyor..
     }
       printf("\n"); 
       printf("Jetonlarin histogram seklinde dagilimlari:\n");
       
       for(int i=a; i>0; i--)
       {
            printf("\n%d|", i);
            for(int j=0; j<10; j++)
           {
               if(hazne[j]>=i)
                printf(" o |");//de�er sa�lan�rsa al�nacak �ekilleri buradan yapt�m..
                else
                printf("   |");//de�ilse bo� de�er al�cak..
           }
            printf("\n"); 
       }
     
      printf("-+---+---+---+---+---+---+---+---+---+---+\n");   
      printf(" | 1   2   3   4   5   6   7   8   9  10 |\n"); 
   }
