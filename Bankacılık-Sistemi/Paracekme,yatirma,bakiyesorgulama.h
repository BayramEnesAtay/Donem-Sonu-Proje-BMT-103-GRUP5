//Muhammed Ali Atik 23181616601
//Para yatirma,cekme, bakiye sorgulama.

int BakiyeSorgulama(int*aptr) {
    char dosya_adi[100];
    snprintf(dosya_adi, sizeof(dosya_adi), "%s.txt", *aptr);
    FILE *dosya = fopen(dosya_adi, "r");
    if (dosya == NULL) {
        printf("Dosya acilamadi!\n");
        return 0;
    }

    int bakiye;
    fscanf(dosya, "%*s %*s %*d %d", &bakiye);
    fclose(dosya);

    return bakiye;
}
void Paracekme(int*aptr) {
    int para;
    int secim;

    printf("Para Yatirma/Cekme islemlerinden hangisini yapmak istiyorsaniz giriniz(Yatirma icin 1,Cekme icin 0):");
    scanf("%d", &secim);
    switch (secim) {
        case 1: {
            printf("Yatirmak istediginiz parayi giriniz:");
            scanf("%d", &para);
            *aptr += para;
            printf("Paraniz basarili bir sekilde yatirilmistir.\n");
            printf("Hesabinizda %d toplam para vardir.", *aptr);
            break;
        }
        case 0: {
            printf("Cekmek istediginiz parayi giriniz:");
            scanf("%d", &para);

            // Bakiye sorgulama fonksiyonu
            int bakiye = BakiyeSorgulama(aptr);

            // Bakiye kontrolü
            if (bakiye >= para) {
                *aptr -= para;
                printf("Paraniz basarili bir sekilde cekilmistir!\n");
                printf("Hesabinizda %d kadar toplam para vardir", *aptr);
            } else {
                printf("Hesabinizda yeterli bakiye bulunmamaktadir!\n");
            }
            break;

            default:
                printf("Gecersiz secim yaptiniz lutfen 0 veya 1 giriniz!:\n");
        }
    }
}
