//Muhammed Ali Atik 23181616601
//Para yatirma,cekme, bakiye sorgulama.

#include<stdio.h>
#include<stdlib.h>

void BakiyeSorgulama(char kullanici[50]) {
    char dosya_adi[100];


    snprintf(dosya_adi, sizeof(dosya_adi), "%s", kullanici);
    FILE *dosya = fopen(dosya_adi, "r");
    if (dosya == NULL) {
        printf(dosya_adi);
        printf("------------------\nDosya acilamadi!\n");

    }

    int bakiye;
    char satir6[30];
    for (int i = 1; i <= 5; i++) {
        fgets(satir6, 30, dosya);
        if (i == 5) {
            printf("------------------\n%s\n", satir6);
            break;
        }
    }
    fclose(dosya);


}
