#include <stdio.h>
#include <math.h>
#include <string.h>
struct ogrTip
{ 
unsigned long ogrNo;
char ad[15];
char soyad[15];
unsigned vize;
unsigned final;
unsigned proje;
unsigned short devam;
float bNotu;
char harf[2];
};
struct ogrTip o[BUFSIZ];
float bNotuHesaplama(int vize, int final,int proje);
void ortalama();
void ssapma();
int N;
FILE *dd2=fopen("17253601+NURGULUGRAS.txt","w");

main()
{
	int vize,final,proje;
	float standart,ort;
	FILE *dd1;
	int i=0;
	int sayac[11]={0,0,0,0,0,0,0,0,0,0,0};
	if((dd1=fopen("CENG101_IN.txt","r"))!=NULL)   
	{
		printf("OGRENCI#\tAD\tSOYAD\tVIZE\tFINAL\tPROJE\tB.NOTU\tHARF\n");
		printf("==========================================================================\n");
		fprintf(dd2,"OGRENCI#\tAD\t\tSOYAD\t\tVIZE\tFINAL\tPROJE\tB.NOTU\tHARF\n");
		fprintf(dd2,"==========================================================================\n");
		while(!feof(dd1))
		{
			fscanf(dd1,"%d%s%s%d%d%d%d",&o[i].ogrNo, &o[i].ad, &o[i].soyad, &o[i].vize, &o[i].final, &o[i].proje, &o[i].devam);
			o[i].bNotu = bNotuHesaplama(o[i].vize, o[i].final, o[i].proje);
			if(o[i].devam==0)
   			{
			   	strcpy(o[i].harf,"F2");	
			   	sayac[10]++;
			}
			else if(89.50<=o[i].bNotu)
			{
				strcpy(o[i].harf,"A1");	
			    sayac[0]++;
		    } 
		    else if(79.50<=o[i].bNotu)
			{
			    strcpy(o[i].harf,"A2");	
			    sayac[1]++;
		    }
		    else if(74.50<=o[i].bNotu)
			{
			    strcpy(o[i].harf,"B1");	
			    sayac[2]++;
		    }
		    else if(69.50<=o[i].bNotu)
			{
			    strcpy(o[i].harf,"B2");	
			    sayac[3]++;
		    }
		    else if(64.50<=o[i].bNotu)
			{
			    strcpy(o[i].harf,"C1");	
			    sayac[4]++;
		    }
		    else if(59.50<=o[i].bNotu)
			{
			    strcpy(o[i].harf,"C2");	
			    sayac[5]++;
		    }
		    else if(54.50<=o[i].bNotu)
			{
			    strcpy(o[i].harf,"D1");	
			    sayac[6]++;
		    }
		    else if(49.50<=o[i].bNotu)
			{
			    strcpy(o[i].harf,"D2");	
			    sayac[7]++;
		    }
		    else if(39.50<=o[i].bNotu)
			{
			    strcpy(o[i].harf,"E ");	
			    sayac[8]++;
		    }  
		    else
			{
			    strcpy(o[i].harf,"F1");	
			    sayac[9]++;
		    }  
	        printf("%d\t%s\t%s\t%d\t%d\t%d\t%3.0f\t%s\n",o[i].ogrNo,o[i].ad,o[i].soyad,o[i].vize,o[i].final,o[i].proje, o[i].bNotu, o[i].harf);
	        fprintf(dd2,"%d\t%-5s\t%-5s\t%6d\t%6d\t%6d\t\t%3.0f\t%7s\n",o[i].ogrNo,o[i].ad,o[i].soyad,o[i].vize,o[i].final,o[i].proje, o[i].bNotu, o[i].harf);
			i++;
        }
        N=i;
        printf("Ogrenci Sayisi:%d\n", N);
        fprintf(dd2,"Ogrenci Sayisi:%d\n", N);
		ortalama();
		ssapma();
		printf("\nHarf Notlari Dagilimlari:\n");
		printf("A1:%d\n",sayac[0]);
		printf("A2:%d\n",sayac[1]);
		printf("B1:%d\n",sayac[2]);
		printf("B2:%d\n",sayac[3]);
		printf("C1:%d\n",sayac[4]);
		printf("C2:%d\n",sayac[5]);
		printf("D1:%d\n",sayac[6]);
		printf("D2:%d\n",sayac[7]);
		printf("E:%2d\n",sayac[8]);
		printf("F1:%d\n",sayac[9]);
		printf("F2:%d\n",sayac[10]);
		fprintf(dd2,"\nHarf Notlari Dagilimlari:\n");
		fprintf(dd2,"A1:%d\n",sayac[0]);
		fprintf(dd2,"A2:%d\n",sayac[1]);
		fprintf(dd2,"B1:%d\n",sayac[2]);
		fprintf(dd2,"B2:%d\n",sayac[3]);
		fprintf(dd2,"C1:%d\n",sayac[4]);
		fprintf(dd2,"C2:%d\n",sayac[5]);
		fprintf(dd2,"D1:%d\n",sayac[6]);
		fprintf(dd2,"D2:%d\n",sayac[7]);
		fprintf(dd2,"E:%2d\n",sayac[8]);
		fprintf(dd2,"F1:%d\n",sayac[9]);
		fprintf(dd2,"F2:%d\n",sayac[10]);
    }
    else
			printf("Dosya Bulunamadý.");
}

float bNotuHesaplama(int vize, int final,int proje)
   {
	float bNotu=0;
	bNotu=bNotu + vize*0.3+final*0.4+proje*0.3;
	return bNotu;
   }
void ortalama()
   {
   	float toplam=0;
	float ort;
   	for(int i=0; i<N; i++)
   		toplam= toplam + o[i].bNotu;
    ort=toplam/N;
    printf("Basari Notlari Ortalamasi:%5.2f\n",ort);
    fprintf(dd2,"Basari Notlari Ortalamasi:%5.2f\n",ort);
   } 
void ssapma()
   {
   	float ort,sapma;
   	float top=0;
   	for(int i=0; i<N; i++)
   {
	top=top+pow(bNotuHesaplama(o[i].vize,o[i].final,o[i].proje)-ort,2);
   }
    sapma=sqrt(top/(N-1));
    printf("Basari Notlari Standart Sapmasi:%5.2f",sapma);
    fprintf(dd2,"Basari Notlari Standart Sapmasi:%5.2f",sapma);
   }

 


   

	
    


