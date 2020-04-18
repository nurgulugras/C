#include <stdio.h>   
#include <conio.h>   
#include <stdlib.h>  
#include <string.h>

void kisiekle();           
void goruntule();          
void guncelle(char ad[60]);
void sil(char ad[60]);     
void ara();             
int  devam();
void aranan(char isim[60],int bilgi);
int kontrol(char num[12]);		
char cevap, isim[30];
int onay;
FILE *dd1;
struct veriler
{  
    char ad[60];
	char soyad[60];
	char dogum_tarihi[20];
	char evtel[12];
	char ceptel[12];
	char istel[12];
	char eposta[60];
}veri;
struct adresler
{
	char mahalle[100];
	char sokak[100];
	char il[60];
	char ilce[60];
}adres;
int main()
{
    int tercih;
	system("cls");
	printf("\n\n\t\t\t\t\tMENU\n");
	printf("\t\t\t-----------------------------------------\n");
	printf("\t\t--------------------");
	printf("\t\t\t--------------------");
	printf("\n\t\t1.Kisi Ekle");
	printf("\t\t\t\t2.Goruntule\n");
	printf("\t\t--------------------"); 
	printf("\t\t\t--------------------\n"); 
	printf("\t\t--------------------");
	printf("\t\t\t--------------------\n");
	printf("\t\t3.Guncelle");
	printf("\t\t\t\t4.Sil\n");
	printf("\t\t--------------------");
	printf("\t\t\t--------------------\t\n");
	printf("\t\t--------------------");
	printf("\t\t\t--------------------\n");
	printf("\t\t5.Arama yap");
	printf("\t\t\t\t6.Cikis\n");
	printf("\t\t--------------------");
	printf("\t\t\t--------------------\t\n\n\n");
	printf("\t\t\t-----------------------------------------\n");
	printf("\t\t\t\tTercihiniz:\t");scanf("%d", &tercih);
	if (tercih == 1 || tercih == 2 || tercih == 3 || tercih == 4 || tercih == 5 || tercih == 6)
	{
		switch (tercih)
		{
		case 1: 	
		kisiekle();
		break;
		case 2:
		goruntule();
		break; 
		case 3:{
		do
		{
			printf("\n\n\tGuncellenicek ismi giriniz:");
			_flushall();
			gets(isim);
			printf("\n");
			guncelle(isim);
			for(;;)
		  {
			printf("\n");
		    printf("Guncelleme islemine devam icin (G) \n");
			printf("Menuye donmek icin             (M) \n");
			printf("Cikis  yapmak icin             (C) \n\n");
			printf("Tercihiniz: ");
			cevap = _getche(); printf("\n"); system("cls");
			if (cevap == 'g' || cevap == 'G')
			{
			 tercih = 3; break;
			}
			else if (cevap == 'm' || cevap == 'M')
			{
			 main(); break;
			}
			else if (cevap == 'c' || cevap == 'C')
			{
			 exit(1); break;
			}
			else
			printf("\nYanlis secim yaptiniz!Lutfen belirtilen tuslari kullaniniz\n");
		 }
	   }     while (tercih = 3);
			 break;
			}
		 case 4:{
		  do
		  {
			 printf("Silinecek kisinin adi ? :");
			 _flushall();
			 gets (isim);
			 sil(isim);
				
			 for (;;)
				{
			 printf("\n");
			 printf("Silme islemine devam icin      (S) \n");
			 printf("Menuye donmek icin             (M) \n");
			 printf("Cikis  yapmak icin             (C) \n\n");
			 printf("Tercihiniz: ");
			 scanf("%c", &cevap); system("cls");
			 if (cevap == 'S' || cevap == 's')
			 {
				tercih = 4; break;
			 }
			 else if (cevap == 'm' || cevap == 'M')
			 {
				main(); break;
			 }
			 else if (cevap == 'c' || cevap == 'C')
			 {
				exit(1); break;
			 }
			 else
				printf("\nYanlis secim yaptiniz!Lutfen belirtilen tuslari kullaniniz\n");
				}
		    } while (tercih = 4);
			break;
		    }
		    case 5:		
		    ara(); 
		    break;
		    case 6:		
		    exit(1);
		    break;
		    default:
		    printf("Belirtilen tuslari kullaniniz.");
	 	    break;
	   }
   }
	else 
	printf("Yanlis secim yaptiniz!\n"); devam();
	return 0;
}
void kisiekle()
{
	system("cls");
	dd1=fopen("PROJE.txt","a");
	if (dd1 == NULL)
	printf("Surucu bulunamadi"); 
    else
	{
	 	printf("\n\n\n\tKISI EKLE:\n\n");
	 	printf("\n\t*******************************");
	    printf("\n\tAd:");
	    scanf("%s",&veri.ad);
	    printf("\n\t*******************************");
	    fprintf(dd1,"%s\t",veri.ad);
	    printf("\n\tSoyad:");
	    scanf("%s",&veri.soyad);
	    printf("\n\t*******************************");
	    fprintf(dd1,"%s\t",veri.soyad);
	    printf("\n\tDogum Tarihi(gg.aa.yy):");
	    scanf("%s",&veri.dogum_tarihi);
	    printf("\n\t*******************************");
	    fprintf(dd1,"%s\t",veri.dogum_tarihi);
	    printf("\n\tE-posta:");
	    scanf("%s",&veri.eposta);
	    printf("\n\t*******************************");
	    fprintf(dd1,"%s\t",veri.eposta);
        do{
	    printf("\n\tCep Telefonu:");
	    scanf("%s", &veri.ceptel);
	    printf("\n\t*******************************");
        onay=kontrol(veri.ceptel);
	    }while(onay!=1);
	    fprintf(dd1,"%s\t",veri.ceptel);
	    do{
	    printf("\n\tEv Telefonu:");
	    scanf("%s", &veri.evtel);
	    printf("\n\t*******************************");
	    onay=kontrol(veri.evtel);
	    }while(onay!=1);
	    fprintf(dd1,"%s\t",veri.evtel);
	    do{
	    printf("\n\tIs Telefonu:");
	    scanf("%s", &veri.istel);
	    printf("\n\t*******************************");
	    onay=kontrol(veri.istel);
	    }while(onay!=1);
	    fprintf(dd1,"%s\t",veri.istel);
	    printf("\n\tIl:");
	    scanf("%s",&adres.il);
	    printf("\n\t*******************************");
	    fprintf(dd1,"%s\t",adres.il);
	    printf("\n\tIlce:");
	    scanf("%s",&adres.ilce);
	    printf("\n\t*******************************");
	    fprintf(dd1,"%s\t",adres.ilce);
	    printf("\n\tMahalle:");
	    scanf("%s",&adres.mahalle);
	    printf("\n\t*******************************");
	    fprintf(dd1,"%s\t",adres.mahalle);
	    printf("\n\tSokak:");
    	scanf("%s",&adres.sokak);
    	printf("\n\t*******************************");
	    fprintf(dd1,"%s\n",adres.sokak);
	    fclose(dd1);
		printf("\n\tKisi eklendi.\n\n");
		devam();
	}  
	    
}
int kontrol(char num[11])
{
	int karaktermi = 0, dogru = 0, yanlis = 1;
	if (num[11] != NULL || num[10] == NULL || num[9] == NULL || num[8] == NULL || num[7] == NULL || num[6] == NULL || num[5] == NULL || num[4] == NULL || num[3] == NULL || num[2] == NULL || num[1] == NULL)
	{
		printf("\n\tTelefon numaraniz 11 haneli olmali!\n");
		return dogru;
	}
	for (int i = 0; veri.ceptel[i] != '\0'; i++)
	{
		if (num[i] != '1' && num[i] != '2' &&  num[i] != '3' && num[i] != '4' && num[i] != '5' && num[i] != '6' &&  num[i] != '7' && num[i] != '8' && num[i] != '9' && num[i] != '0')
		{
			karaktermi = 1;
		}
		else karaktermi = 0;
	}
	if (karaktermi== 1)
	{
		printf("\n\tLutfen 0 ile 9 arasinda rakam kullaniniz!\n"); 
		 return dogru;
	}
	else return yanlis;
}
void goruntule()
{	
    dd1 = fopen("PROJE.txt", "r");
	int tus;
	if (dd1 == NULL)
	{
		while(1)
		{
        printf("Rehberiniz kimse ekli degil ekleme yapmak icin (E) tusuna basiniz. !");
	    tus = _getche(); system("cls");
	    if (tus == 'e' || tus == 'E') 
		{
		   kisiekle(); break;
		}
	    else
		printf("\nBelirtilen tuslari kullaniniz.\n");
	    }
	}
	else
	{
		system("cls");
		printf("\n\nREHBER:\n");
		while (fscanf(dd1,"%s %s %s %s %s %s %s %s %s %s %s",&veri.ad,&veri.soyad,&veri.dogum_tarihi,&veri.eposta,&veri.ceptel,&veri.evtel,&veri.istel,&adres.il,&adres.ilce,&adres.mahalle,&adres.sokak) != EOF)
		{	printf("*************************************************************\n");
			printf("Ad:%s\nSoyad:%s\nDogumT.:%s\nEposta:%s\nCeptel:%s\nEvtel:%s\nIstel:%s\nAdres:%s Mahallesi %s Sokak %s/%s \n\n", veri.ad, veri.soyad, veri.dogum_tarihi, veri.eposta, veri.ceptel, veri.evtel, veri.istel, adres.mahalle, adres.sokak, adres.il, adres.ilce);
			printf("*************************************************************\n");
		}
		fclose(dd1);
		devam();
	}
}
void guncelle(char ad[60])
{
	FILE *dd1,*dd2;
	int varmi=0;
	system("cls");
	dd1 = fopen("PROJE.txt", "r");
	dd2 = fopen("PROJEYEDEK.txt", "w");
	if (dd1 == NULL)
	{
		printf("\nRehber bos!\n\n");
	}
	else
	{
		rewind(dd1);
		rewind(dd2);
		while (fscanf(dd1,"%s %s %s %s %s %s %s %s %s %s %s",&veri.ad,&veri.soyad,&veri.dogum_tarihi,&veri.eposta,&veri.ceptel,&veri.evtel,&veri.istel,&adres.il,&adres.ilce,&adres.mahalle,&adres.sokak) == EOF);
		{
		   if (strcmp(veri.ad, ad) == 0)
			{
		    varmi= 1;
	       printf("\n\n\n\tGUNCELLEN KISI:\n\n");
	 	   printf("\n\t*******************************");
	       printf("\n\tAd:");
	       scanf("%s",&veri.ad);
	       printf("\n\t*******************************");
	       printf("\n\tSoyad:");
	       scanf("%s",&veri.soyad);
	       printf("\n\t*******************************");
	       printf("\n\tDogum Tarihi(gg.aa.yy):");
	       scanf("%s",&veri.dogum_tarihi);
	       printf("\n\t*******************************");
	       printf("\n\tE-posta:");
	       scanf("%s",&veri.eposta);
	       printf("\n\t*******************************");
         do{
	       printf("\n\tCep Telefonu:");
	       scanf("%s", &veri.ceptel);
	       printf("\n\t*******************************");
           onay=kontrol(veri.ceptel);
	       }while(onay!=1);
	     do{
	        printf("\n\tEv Telefonu:");
	        scanf("%s", &veri.evtel);
	        printf("\n\t*******************************");
	        onay=kontrol(veri.evtel);
	       }while(onay!=1);
	     do{
	        printf("\n\tIs Telefonu:");
	        scanf("%s", &veri.istel);
	        printf("\n\t*******************************");
	        onay=kontrol(veri.istel);
	       }while(onay!=1);
	        printf("\n\tIl:");
	        scanf("%s",&adres.il);
	        printf("\n\t*******************************");
	        printf("\n\tIlce:");
	        scanf("%s",&adres.ilce);
	        printf("\n\t*******************************");
	        printf("\n\tMahalle:");
	        scanf("%s",&adres.mahalle);
	        printf("\n\t*******************************");
	        printf("\n\tSokak:");
    	    scanf("%s",&adres.sokak);
    	    printf("\n\t*******************************");
		    printf("\n\tGuncellendi.\n\n");
		    fprintf(dd2, "%s %s %s %s %s %s %s %s %s %s %s\n",&veri.ad,&veri.soyad,&veri.dogum_tarihi,&veri.eposta,&veri.ceptel,&veri.evtel,&veri.istel,&adres.il,&adres.ilce,&adres.mahalle,&adres.sokak);
		  }
	     else
		 fprintf(dd2, "%s %s %s %s %s %s %s %s %s %s %s\n",&veri.ad,&veri.soyad,&veri.dogum_tarihi,&veri.eposta,&veri.ceptel,&veri.evtel,&veri.istel,&adres.il,&adres.ilce,&adres.mahalle,&adres.sokak);
        }
		_fcloseall();
		remove("PROJE.txt");
		rename("PROJEYEDEK.txt", "PROJE.txt");
		if (varmi == 0)
		printf("Bu kisi rehberde yok..\n"); 
	}
}
void sil(char ad[60])
{
    system("cls");
	FILE *dd1,*dd2;
	int varmi = 0;
	dd1 = fopen("PROJE.txt", "r");
	dd2 = fopen("PROJEYEDEK.txt", "w");
	if (dd1 == NULL)
	{
		printf("Suan rehberinizde hicbir kisi ekli degil!");
	}
	else
	{
		rewind(dd1);
		rewind(dd2);
		printf("\n%s Kisisini silmek istiyormusunuz! (E)-(H)\n", isim);
		cevap = _getch();
		if (cevap == 'E' || cevap == 'e')
		{
			while (fscanf(dd1,"%s %s %s %s %s %s %s %s %s %s %s",&veri.ad,&veri.soyad,&veri.dogum_tarihi,&veri.eposta,&veri.ceptel,&veri.evtel,&veri.istel,&adres.il,&adres.ilce,&adres.mahalle,&adres.sokak)!=EOF)
			{
				
				if (!strcmp(veri.ad, ad))
				{
					printf("\nSilinen Kisi Bilgileri\n");
					printf("------------------------\n");
					printf("Ad:\t%s\nSoyad:  %s\nCepTel:  %s\nDogumT: %s\n\n", veri.ad, veri.soyad, veri.ceptel,veri.dogum_tarihi);
					printf("\nKisi silindi...");
					varmi = 1;
				}
				else
					fprintf(dd2,"%s %s %s %s %s %s %s %s %s %s %s\t  ", veri.ad, veri.soyad, veri.dogum_tarihi, veri.eposta, veri.ceptel, veri.evtel, veri.istel, adres.mahalle, adres.sokak, adres.il, adres.ilce);
			}
			_fcloseall();
			remove("PROJE.txt");	
			rename("PROJEYEDEK.txt", "PROJE.txt");
	   
			if (varmi == 0)
				printf("\nBu kisi rehberde kayitli degil!\n");
	    }
		else if (cevap == 'h' || cevap == 'H')
		{main();}
		else { printf("Yanlis tus kombinasyonu!\n");main(); };
	}
}
void ara()
{
	char isim[30], bilgi;
	int Secim, varmi = 0;
	dd1 = fopen("PROJE.txt", "r");
	if (dd1 == NULL)
	{
		printf("Dosya veya sunucu bulunamadi!\n");
	}
	else
	{
		system("cls");
		printf("1-Ad ile arama\n");
		printf("2-SoyAd ile arama\n");
		printf("3-Dogum Tarihi ile arama\n");
		scanf("%d", &Secim);
		switch (Secim)
		{
		 case 1:
			{
				printf("Aranan kisinin adini giriniz:");
				_flushall();
				gets(isim); printf("\n"); 
				bilgi = 0;
				aranan(isim, bilgi);
				break;
			}
		 case 2:
			{
				printf("Aranan kisinin soyadini giriniz:");
				_flushall();
				gets(isim); printf("%s\n", isim);
				bilgi = 1;
				aranan(isim, bilgi);
				break;
			 }
	     case 3:
			{
				printf("Aranan kisinin eposta adresini giriniz:");
				_flushall();
				gets(isim); printf("%s\n", isim);
				bilgi = 2;
				aranan(isim, bilgi);
				break;
			}
		}
		devam();
	}
}
void aranan(char isim[60],int bilgi)
{
	system("cls");
	int varmi= 0;
	rewind(dd1);
	while (fscanf(dd1, "%s", &veri.ad) != EOF)
	{		
		fscanf(dd1, "%s", &veri.soyad);
		fscanf(dd1, "%s", &veri.dogum_tarihi);	
		fscanf(dd1, "%s", &veri.eposta);
		fscanf(dd1, "%s", &veri.ceptel);
		fscanf(dd1, "%s", &veri.evtel);		
		fscanf(dd1, "%s", &veri.istel);		
		fscanf(dd1, "%s", &adres.mahalle);
		fscanf(dd1, "%s", &adres.sokak);
		fscanf(dd1, "%s", &adres.il);
		fscanf(dd1, "%s", &adres.ilce);
			
		if(bilgi == 0)
	   {
		if (!strcmp(veri.ad, isim))
		{
			printf("Kisi Bilgileri\n");
			printf("--------------\n");
		    printf("Ad:%s\nSoyad:%s\nDogumT.:%s\nEposta:%s\nCeptel:%s\nEvtel:%s\nIstel:%s\nAdres:%s/%s %s Mahallesi %s Sokak \n\n", veri.ad, veri.soyad, veri.dogum_tarihi, veri.eposta, veri.ceptel, veri.evtel, veri.istel, adres.mahalle, adres.sokak, adres.il, adres.ilce);
			varmi = 1;
		}
       }
       	if(bilgi == 1)
	   {
		if (!strcmp(veri.soyad, isim))
		{
			printf("Kisi Bilgileri\n");
			printf("--------------\n");
			printf("Ad:%s\nSoyad:%s\nDogumT.:%s\nEposta:%s\nCeptel:%s\nEvtel:%s\nIstel:%s\nAdres:%s Mahallesi %s Sokak %s/%s \n\n", veri.ad, veri.soyad, veri.dogum_tarihi, veri.eposta, veri.ceptel, veri.evtel, veri.istel, adres.mahalle, adres.sokak, adres.il, adres.ilce);
			varmi = 1;
		}
       }
       	if(bilgi == 2)
	   {
		if (!strcmp(veri.dogum_tarihi, isim))
		{
			printf("Kisi Bilgileri\n");
			printf("--------------\n");
			printf("Ad:%s\nSoyad:%s\nDogumT.:%s\nEposta:%s\nCeptel:%s\nEvtel:%s\nIstel:%s\nAdres:%s Mahallesi %s Sokak %s/%s \n\n", veri.ad, veri.soyad, veri.dogum_tarihi, veri.eposta, veri.ceptel, veri.evtel, veri.istel, adres.mahalle, adres.sokak, adres.il, adres.ilce);
			varmi = 1;
		}
       } 
   }
	if (varmi == 0)
	{
		printf("\nBu kisi rehberde kayitli degil!\n\n");
	}
}
int devam()
{
		printf("Yeni bir kisi eklemek icin    (E)\n");
		printf("Menuye donmek icin            (M)\n");
		printf("Arama yapmak icin             (A)\n");
		printf("Rehber goruntulemesi icin     (G)\n");
		printf("Cikis  yapmak icin            (C)\n\n");
		printf("Tercihiniz: ");
		cevap = _getche(); system("cls");
		if (cevap == 'e' || cevap == 'E')
		{
			kisiekle();
		}
		else if (cevap == 'm' || cevap == 'M')
		{
			main(); 
		}
		else if (cevap == 'g' || cevap == 'G')
		{
			goruntule(); 
		}
		else if (cevap == 'a' || cevap == 'A')
		{
			ara(); 
		}
		else if (cevap == 'c' || cevap == 'C')
		{
			exit(1); 
		}
		else printf("\nYanlis secim yaptiniz!\n");
}
