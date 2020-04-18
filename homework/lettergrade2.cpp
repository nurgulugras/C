#include <stdio.h>
#include<string.h>
#include <math.h>
void giris(int no[], int notu[], int N);
float ortalama(int notu[], int N);
void goruntule(int no[], int notu[], int N);
void otele(int no[], int notu[], int N,float ort);
void NotaGore(int no[],int notu[],int N);
void NumGore(int no[],int notu[],int N);
float sapma(int notu[],int N,float ort);
void dikeyYatay(int notu[],int N);
main()
{ 
int N;
int OgrNo[BUFSIZ], BNotu[BUFSIZ];
float ort,standart;
printf("Ogrenci sayisini giriniz: ");
scanf("%d", &N);
giris(OgrNo, BNotu, N);
ort = ortalama(BNotu, N);
otele(OgrNo, BNotu, N,ort);
goruntule(OgrNo, BNotu, N);
ort = ortalama(BNotu, N);
standart=sapma(BNotu,N,ort);
printf("Not ortalamasi: %5.2f\n", ort);
printf("Standart Sapma: %f\n", standart);
NotaGore(OgrNo, BNotu, N);
NumGore(OgrNo, BNotu, N);
dikeyYatay(BNotu, N);
}
void giris(int no[], int notu[], int N)
{
int i;
for (i=0; i<N; i++)
{ printf("Ogrenci no gir: ");
scanf("%d", &no[i]);
printf("%d numarali ogrencinin basari notunu gir : ", no[i]);
scanf("%d", &notu[i]);
}
}
void goruntule(int no[], int notu[], int N)
{
printf("Ogrenci#\tNotu\n");
for (int i=0; i<N; i++)
printf("%8d\t%3d\n", no[i], notu[i]);
}
float ortalama(int notu[], int N)
{ 
float t;
int i;
t = 0;
for (i=0; i<N; i++)
t = t + notu[i];
float ort = t / N;
return ort;

}
void otele(int no[],int notu[], int N, float ort) 
{
float fark;
int ekle=0,i;
int OgrNo[BUFSIZ], BNotu[BUFSIZ];

for(i=0; i<N; i++)	
{
ekle=0;
if(notu[i]>=20 && ort<50)
{
fark=50-ort;
ekle=ekle+fark;
}
if(notu[i]>=30)
notu[i]+=ekle;
}
}
void NotaGore(int no[],int notu[],int N)
{
	int t,n;
	printf("--------------Otelenmis Nota Gore Kucukten Buyuye Siralama------------\n");
	printf("Ogrenci#\tNotu\n");
	for(int i=0; i<N; i++){
	for(int j=i+1; j<N; j++){
   if(notu[i]>notu[j])
	{
		t=notu[i];
		notu[i]=notu[j];
		notu[j]=t;
		n=no[i];
		no[i]=no[j];
		no[j]=n;
	}
	
  }
   printf("%8d\t",no[i]);
   printf("%3d\n",notu[i]);
  }
}
    

void NumGore(int no[],int notu[],int N)
{
	int z,r;
	printf("--------------Ogrenci Numaralarina Gore Kucukten Buyuye Siralama------------\n");
	printf("Ogrenci#\tNotu\n");
	for(int i=0; i<N; i++){
		for(int j=i+1; j<N; j++){
     if(no[i]>no[j])
	{
		z=no[i];
		no[i]=no[j];
		no[j]=z;
		r=notu[i];
		notu[i]=notu[j];
		notu[j]=r;
	
	}
}
  printf("%8d\t",no[i]);
  printf("%3d\n",notu[i]);
 }
}
float sapma(int notu[],int N,float ort)
{
int top=0;
for(int i=0; i<N; i++)
{
	top=top+pow(ort-notu[i],2);
}
return sqrt(top/N);
}

void dikeyYatay(int notu[],int N)
{
int hazne[10]={0,0,0,0,0,0,0,0,0,0};	
for(int i=0; i<N; i++)
{
if(90<=notu[i])
hazne[0]++;
if(80<=notu[i] && notu[i]<89)
hazne[1]++;
if(75<=notu[i] && notu[i]<79)
hazne[2]++;
if(70<=notu[i] && notu[i]<74)
hazne[3]++;
if(65<=notu[i] && notu[i]<69)
hazne[4]++;
if(60<=notu[i] && notu[i]<64)
hazne[5]++;
if(55<=notu[i] && notu[i]<59)
hazne[6]++;
if(50<=notu[i] && notu[i]<54)
hazne[7]++;
if(40<=notu[i] && notu[i]<49)
hazne[8]++;
if(0<=notu[i] && notu[i]<39)
hazne[9]++;
}
       printf("\n"); 
       printf("Dikey Histogram:\n");
       
       for(int i=N; i>0; i--)
       {
            printf("\n%d|", i);
            for(int j=0; j<10; j++)
           {
               if(hazne[j]>=i)
                printf(" ** |");
                else
                printf("    |");
           }
            printf("\n"); 
       }
      printf(" +----+----+----+----+----+----+----+----+----+----+ \n");   
      printf(" | A1   A2   B1   B2   C1   C2   D1   D2    E    F | \n"); 
      
       printf("\n"); 
       printf("Yatay Histogram:\n");
       char const *cdizi[10] = { "A1", "A2", "B1","B2","C1","C2","D1","D2","E","F" };
   
       for(int j=0; j<10; j++)
       {
	   
            printf("\n%2s|", cdizi[j]);
           
           if(hazne[j]>0)
           for(int k=0;k<hazne[j];k++)
              printf(" **  ");
            else
              printf("     ");
            printf("\n");
            
       }
       printf("\n-----------------------------------------------\n");
       for(int i=0; i<N; i++)
       printf("    %d",i+1);
     
   }




    
	




