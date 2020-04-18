#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
main ()
{
    int x,i,j,t=0,hazne[10]={0},jeton, temp=0;
    printf("Jeton Sayisini Giriniz:");
    scanf("%d",&jeton);
    while(t<jeton)
    {
        j=0;
        for(i=0;i<9;i++)
        {
            x = rand () % 2;
            if(x==1)
                j++;       
        }
        hazne[j] = hazne[j] + 1;
        printf("%d. Jetonu atmak icin bir tusa basiniz ->",t+1);
        getch();
        printf("%d. jeton %d. hazneye dustu.\n",t+1,j+1);
        t++;
    }
   
    printf("\n");
    for(i=0;i<10;i++)
    {
        printf("%d . Haznedeki jeton sayisi: %d\n",i+1, hazne[i]);
    }
   
    for(j=0;j<9;j++)
    {
        if(hazne[j+1]>temp)
            temp=hazne[j+1];
    }
   
    j=0;
    printf("\n");
    printf("Jetonlarin histogram seklinde dagilimlari:\n\n");   
    for(i=temp;i>0;i--)
    {       
        printf("%d|",i);
        for(t=0;t<10;t++)
        {
        if(hazne[t]>=i)       
            printf(" o |");
        else
            printf("   |");
        }
        printf("\n");       
    }
    printf("-+---+---+---+---+---+---+---+---+---+---+\n");   
    printf(" | 1   2   3   4   5   6   7   8   9   10|\n");   
}




