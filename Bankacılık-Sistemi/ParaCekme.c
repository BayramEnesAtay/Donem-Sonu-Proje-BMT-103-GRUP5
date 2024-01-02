//Bayram Enes Atay 23181616059
//Para cekme foonksıyonu.
void ParaCekme(char kullanici2[]);

int main()
{
    char kullanici2[50];

    printf("Kullanici degerini giriniz(isi,soyisim kucuk harfle ve bitisik olarak):");
    fgets(kullanici2,sizeof(kullanici2)+1,stdin);
    kullanici2[strcspn(kullanici2,"\n")]=0;
    ParaCekme(kullanici2);
    return 0;

}
void ParaCekme(char kullanici2[])
{
    FILE *belge;
    int i;
    char sira[30];
    int bakiye2;
    int cekilenpara;


    belge=fopen(strcat(kullanici2,".txt"),"r");

    if(belge==NULL)
    {
        perror("Error");
        printf("Error number:%d",errno);
    }
    else
    {
        for(i=0;i<5;i++)
        {
            fgets(sira,sizeof(sira)+1,belge);
            sira[strcspn(sira,"\n")]=0;
        }
        fseek(belge, 0, SEEK_CUR);
        sscanf(sira,"%*s%*c%*c%*c%d%*c%*s",&bakiye2);

        printf("Cekmek istediginiz toplam parayi giriniz:");
        scanf("%d",&cekilenpara);

        if(cekilenpara>bakiye2)
        {
            printf("Yetersiz Bakiye!!");

        }
        else if(cekilenpara<=bakiye2)
        {
            bakiye2 -=cekilenpara;
            printf("Yeni Bakiye:%d",bakiye2);

            char cumlee[30],cumlee2[30],cumlee3[30],cumlee4[30];
            fseek(belge,0,SEEK_SET);

            fgets(cumlee,30,belge);
            cumlee[strcspn(cumlee,"\n")]=0;
            fgets(cumlee2,30,belge);
            cumlee2[strcspn(cumlee2,"\n")]=0;
            fgets(cumlee3,30,belge);
            cumlee3[strcspn(cumlee3,"\n")]=0;
            fgets(cumlee4,30,belge);
            cumlee4[strcspn(cumlee4,"\n")]=0;
            fclose(belge);

            FILE *yenibelge;

            yenibelge=fopen(kullanici2,"w");

            if(kullanici2==NULL)
            {
                perror("Error");
                printf("Error number:%d",errno);
            }
            else
            {
                fprintf(yenibelge,"%s\n",cumlee);
                fprintf(yenibelge,"%s\n",cumlee2);
                fprintf(yenibelge,"%s\n",cumlee3);
                fprintf(yenibelge,"%s\n",cumlee4);
                fprintf(yenibelge,"Bakiye : %d TL",bakiye2);
                fclose(yenibelge);

            }
        }
    }

}
