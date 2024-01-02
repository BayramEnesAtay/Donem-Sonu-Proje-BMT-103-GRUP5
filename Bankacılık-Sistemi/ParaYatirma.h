//Bayram Enes Atay 23181616059
//ParaYatirma Fonksıyonu

#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>


void ParaYatirma(char kullanici[])
{
    FILE *dosya;
    int i;
    char satir5[30];
    int bakiye;
    int para;

    dosya=fopen(strcat(kullanici,".txt"),"r");

    if(dosya==NULL)
    {
        perror("Error");


        printf("Error number:%d",errno);
    }
    else
    {
        for(i=0;i<5;i++)
        {
            fgets(satir5,sizeof(satir5)+1,dosya);
        }
        fseek(dosya, 0, SEEK_CUR);
        sscanf(satir5,"%*s%*c%*c%*c%d%*c%*s",&bakiye);
        printf("Yatirmak istediginiz parayi giriniz:");
        scanf("%d",&para);

        bakiye+=para;
        printf("Toplam bakiyeniz: %d",bakiye);

        fseek(dosya,0,SEEK_SET);
        char cumle[30],cumle2[30],cumle3[30],cumle4[30];

        fgets(cumle,30,dosya);
        cumle[strcspn(cumle,"\n")]=0;
        fgets(cumle2,30,dosya);
        cumle2[strcspn(cumle2,"\n")]=0;
        fgets(cumle3,30,dosya);
        cumle3[strcspn(cumle3,"\n")]=0;
        fgets(cumle4,30,dosya);
        cumle4[strcspn(cumle4,"\n")]=0;
        fclose(dosya);

        FILE *dosya2;
        dosya2=fopen(kullanici,"w");
        if(kullanici==NULL)
        {
            perror("Error");
            printf("Error number : %d",errno);
        }
        else
        {
            fprintf(dosya2,"%s\n",cumle);
            fprintf(dosya2,"%s\n",cumle2);
            fprintf(dosya2,"%s\n",cumle3);
            fprintf(dosya2,"%s\n",cumle4);
            fprintf(dosya2,"Bakiye : %d TL",bakiye);
            fclose(dosya2);
        }
    }
}
