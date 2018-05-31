#include <stdio.h>
#include <stdlib.h>

void personelEkle();
void personelListele();
void personelKaldir();
void KayitDuzenle();
void TCKayitBul();
void IsimKayitBul();
void Hakkinda();

    typedef struct {     /* Personel Struct*/
    char isim[30];
    char  TC[20];
    char Tel[20];
    char eposta[30];
    char adres[30];
    int personelNo;
    }personel;

    /* ----------------------------------------------------------------------------------------------*/
     /* personelEkle FONKSIYONU */

    void personelEkle() {
    personel p;
    char x;
    FILE *fp;
    if((fp=fopen("personel.txt","ab+")) == NULL)
        {
                printf("Dosya Olusturulamadi \n");
                exit(1);
        }
    while(1==1){

            printf("Personel No giriniz : ");
            scanf("%d",&p.personelNo);
            if(p.personelNo==0){
                break;
            }

        printf("Isim :");scanf("%s",&p.isim);
        printf("TC No :");scanf("%s",&p.TC);
        printf("TEL No :");scanf("%s",&p.Tel);
        printf("E-posta Adresi :");scanf("%s",&p.eposta);
        printf("Adresi :");scanf("%s",&p.adres);

        if(fwrite(&p,sizeof(p),1,fp) != 1){
            printf("Dosyaya Yazma Hatasi !\n");
            exit(1);
        }
    }
    fclose(fp);
    printf("Kayit Basariyla Eklendi !!\n\n");
    rewind(fp);   /* REWIND KULLANIMI */
    printf("Cikis icin C'ye basin ,Ana Menuye donmek icin Bir tusa Basin !!");
    scanf("%c",&x);
    if(x=='c'||x=='C'){
        system("CLS");
        exit(1);
    }
    else{
        system("CLS");
         main();
    }
   }

    /* -------------------------------------------------------------------------------------------------------------*/
     /*  personelListele FONKSIYONU */

    void personelListele() {
    system("CLS");
    personel p1;
    FILE *fp;
   if((fp=fopen("personel.txt","rb"))== NULL)
   {
       printf("Dosya Okunamadi \n");
       main();
   }
    while(fread(&p1,sizeof(p1),1,fp)==1){
        printf("ID: %d\t",p1.personelNo);
        printf("Isim:%s\t",p1.isim);
        printf("TC No:%s\t",p1.TC);
        printf("TEL No :%s\t",p1.Tel);
        printf("E-Posta:%s\t",p1.eposta);
        printf("Adresi :%s\t\n",p1.adres);

    }
    fclose(fp);
    main();


}

    /*-----------------------------------------------------------------------------------*/
    /* KAYIT SIL FONKSIYONU */



    void personelKaldir(){
    system("CLS");
    personel p1;
    FILE *fp;
    FILE *fp1;
    int bulundu=0;
    char aranan[20];

    printf("Silmek isteginiz kaydin TC No'su :");
    scanf("%s",&aranan);

	fp=fopen("personel.txt","rb");
	if(fp==NULL){
	printf("Dosya Okunamadi!");
	exit(1);
	}

    rewind(fp);  /* Rewind */
    fp1=fopen("yeni.txt","wb");
	if(fp1==NULL){
	printf("Dosya Olusturulamadi !");
	exit(1);
	}

	while (fread(&p1,sizeof(personel),1,fp) != NULL) {
		if (strcmp (aranan, p1.TC) == 0) {
			printf("Aranan kayit bulundu ve silindi !\n\n");
			bulundu=1;

		}
		else {
			fwrite(&p1, sizeof(personel), 1, fp1);
		}
	}
	if (! bulundu) {
		printf("Aranan kayit bulunamadi ! %s\n\n", aranan);
	}

	fclose(fp);
	fclose(fp1);

	remove("personel.txt");
	rename("yeni.txt", "personel.txt");

	main();

}

/* KAYIT DUZENLEME FONKSIYONU */

void KayitDuzenle(){
    system("CLS");
   personel p1;
   FILE *fp;
   char isim[10];
   int bulundu=0;
   printf("Degistirilecek kayidin ismini giriniz :");
   scanf("%s",&isim);
   fp=fopen("personel.txt","rb+");
   if(fp==NULL){
    printf("Dosya Okunamadi !");
    exit(1);
   }

   while(fread(&p1,sizeof(p1),1,fp)==1){
    if(strcmp(isim,p1.isim)==0){
        printf("Yeni isim giriniz : \n");scanf("%s",&p1.isim);
        printf("Yeni TC no giriniz : \n");scanf("%s",&p1.TC);
        printf("Yeni Tel no giriniz : \n");scanf("%s",&p1.Tel);
        printf("Yeni Eposta giriniz : \n");scanf("%s",&p1.eposta);
        printf("Yeni adres giriniz : \n");scanf("%s",&p1.adres);

        fseek(fp,-sizeof(p1),SEEK_CUR);
        fwrite(&p1,sizeof(p1),1,fp);
        bulundu=1;
        break;
    }


}
 if(!bulundu){
    printf("Kayit bulunamadi !");
   }
   fclose(fp);
   return main();
}
/* TC NO ILE KAYIT BULMA FONKSIYONU*/

void TCKayitBul(){
    system("CLS");
    personel p2;
    FILE *fp;
    if((fp=fopen("personel.txt","rb+"))==NULL){
        printf("Dosya Okunamadi ! \n");
        exit(1);
    }
    char TcNo[20];
    int kayit=0;
    printf("TC No ile kayit bul : ");
    scanf("%s",&TcNo);
    while(fread(&p2,sizeof(p2),1,fp)==1){

        if(strcmp(TcNo,p2.TC)==0){
            kayit=1;
            break;
        }

    }
    if(kayit==1){
        printf("\n\nKayit bulundu !!\n\n");
        printf("Isim : %s\t",p2.isim);
        printf("TC No : %s\t",p2.TC);
        printf("Tel No: %s\t",p2.Tel);
        printf("E-Posta  : %s\t",p2.eposta);
        printf("Adresi : %s\t\n",p2.adres);
    }
    else{
        printf("Kayit Bulunamadi !!\n");
    }
    fclose(fp);
    return main();

}

/* ISIM ILE KAYIT BULMA FONKSIYONU*/

void IsimKayitBul(){
    system("CLS");
    personel p2;
    FILE *fp;
    fp=fopen("personel.txt","rb+");
    if(fp==NULL){
        printf("Dosya okunamadi\n");
        exit(1);
    }
    char isim[15];
    int kayit=0;
    printf("Aramak istediginiz kayidin ismini giriniz :\n");
    scanf("%s",&isim);
    while(fread(&p2,sizeof(p2),1,fp)==1){
        if(strcmp(isim,p2.isim)==0){
            kayit=1;
            break;
        }
    }
    if(kayit==1){
        printf("Kayit Bulundu :\n\n");
        printf("Isim : %s\t",p2.isim);
        printf("TC No : %s\t",p2.TC);
        printf("Tel No: %s\t",p2.Tel);
        printf("E-Posta  : %s\t",p2.eposta);
        printf("Adresi : %s\t\n",p2.adres);
    }
    else
    {
        printf("Kayit Bulunamadi !\n");

    }
    fclose(fp);
    return main();

}

/* ILETISIM */
void Hakkinda(){
    system("CLS");
    printf("\t\t\t----->ISA TOLTAR<------\n");
    printf("\n\t\t\t----->Celal Bayar Universitesi Yazilim Muhendisligi<------\n ");
    printf("\n\t\t\t----->github.com/toltarisa<------\n");
    printf("\n\t\t\t----->codepen.io/jesusfellas<------");
    return main();
}

   int main(){
       system("color 1E");
     FILE *fp;
   if(fp == NULL)
   {
       printf("Dosya Olusturulamadi \n");
       exit(1);
   }

   int i,secim;
   printf("\n\n\n\n\n\n");
   printf("\t\t\t\t\t\t________MENU________\n\n");
   printf("\t\t\t\t\t\t[1]-KAYIT EKLE\n\n");
   printf("\t\t\t\t\t\t[2]-KAYITLARI LISTELE\n\n");
   printf("\t\t\t\t\t\t[3]-KAYDI SIL\n\n");
   printf("\t\t\t\t\t\t[4]-KAYIT DUZENLE\n\n");
   printf("\t\t\t\t\t\t[5]-TC NO ILE KAYIT BUL\n\n");
   printf("\t\t\t\t\t\t[6]-ISIM ILE KAYIT BUL\n\n");
   printf("\t\t\t\t\t\t[7]-HAKKINDA\n\n");
   printf("\t\t\t\t\t\t[8]-CIKIS\n\n");
   printf("Tercih Ettiginiz Islem Numarasi ");  scanf("%d",&secim);

   switch(secim)
   {
       case 1:personelEkle();break;
       case 2:personelListele();break;
       case 3:personelKaldir();break;
       case 4:KayitDuzenle();break;
       case 5:TCKayitBul();break;
       case 6:IsimKayitBul();break;
       case 7:Hakkinda();break;
       case 8: printf("\n\nPROGRAMI KAPATMAK ICIN HERHANGI BIR TUSA BASINIZ  !!\n\n\n");return;
       default:printf("\n\n\nYanlis Secim !! [1-7 ARALIGINDA ISLEM YAPINIZ]\n\n\n");
   }

   }
