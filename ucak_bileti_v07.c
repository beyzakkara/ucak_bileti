#include <stdio.h>
#include <stdlib.h>
#include <time.h>


    
int main()
{
    extern void srand (unsigned int __seed) __THROW;
    
    int biletFiyat = 300;
    
    int biletTarihi, koltukNo, bagaj, temp1, temp2;
    
    int max = 5, min = 1; // rastgele sayilarin secilecegi aralik
    
    char ad[30],soyad[30];


     int biletIndirim (int biletTarihi) {
        
         if (biletTarihi >=14 && biletTarihi < 21) {
    
             biletFiyat = biletFiyat-30;

      }
    
       else if (biletTarihi >=21 && biletTarihi < 28) {
           
             biletFiyat = biletFiyat-60;
          
       }

       else if (biletTarihi >=28) {
       
             biletFiyat = biletFiyat-90;
        }
    
    return biletFiyat;

    }
    
    void biletBilgileri() {
                
          printf("\n*** Bilet Bilgileri ***\n");
          printf("\nAd: %s", ad);
          printf("\nSoyad: %s", soyad);
          printf("\nKoltuk No: %d", koltukNo);
          printf("\nBilet Fiyati: %d", biletFiyat);
    }
    
    void koltukNoKontrol () {
        
    srand(time(0));
	int random = (rand() % (max + 1 - min)) + min; // 5 ile 2 arai rastgele sayi 
	
    if (random%2==0) {
        
        temp1 = koltukNo;

        printf("\n*** HATA NO: 1 (Bu koltuk dolu!) *** Lutfen baska bir koltuk seciniz. Koltuk No: ");
        scanf("%d", &koltukNo);
        temp2 = koltukNo;

     while (temp1==temp2) {
        
        printf("\n*** HATA NO: 2 (Dolu Olan Ayni Koltuk No Sectiniz!) *** Lutfen baska bir koltuk seciniz. Koltuk No: ");
        scanf("%d", &koltukNo); 
        temp1 = koltukNo;
    
         } 
        
      } 
        
    }
    
    int bagajAgirlikKontrol (int bagaj) {
        
         // bagaj siniri 15 kg. Siniri asan her 1 kg basina 5 TL ek ucret eklenir
        if (bagaj>15) {
    
                 for (int i=15; i<bagaj; i++) {
                 biletFiyat = biletFiyat + 5;
              }
          }
         return biletFiyat;
    }
    
    
    int menu=0;

    printf("Yapmak Istediginiz Islemi Seciniz: \n1-Bilet Bilgileri Girisi \n2-Bilet Bilgileri\n");
    scanf("%d", &menu);

    switch(menu)
    {
        case 1:
            printf("Adiniz: ");
            scanf("%s", ad);  
    
            printf("\nSoyadiniz: ");
            scanf("%s", soyad);  
            
            printf("\nBagaj Agirligi (kg): ");
            scanf("%d", &bagaj);  
            bagajAgirlikKontrol (bagaj);
            
   
            printf("\nKoltuk No: ");
            scanf("%d", &koltukNo); 
            
             while (koltukNo < 1 || koltukNo > 100) {
                
                  printf("\n***HATA NO: 0*** Lutfen 1-99 arasi bir numara seciniz!");
                  printf("\nKoltuk No: ");
                  scanf("%d", &koltukNo); 
            }
            
            koltukNoKontrol ();
            
            printf("\nBileti kac gun oncesinden almak isteriniz?: ");
            scanf("%d", &biletTarihi);
            biletIndirim (biletTarihi);
            printf("Kaydiniz Basari ile Tamamlanmistir!\n");
            biletBilgileri();
            break;

        case 2:
            
            break;
            
        default:
            printf("Lutfen 1-2 arasi bir secim yapiniz!");
    }
    
    
/*    
    printf("Adiniz: ");
    scanf("%s", ad);  
    
    printf("\nSoyadiniz: ");
    scanf("%s", soyad);  
    
    printf("\nBagaj Agirligi (kg): ");
    scanf("%d", &bagaj);  

*/
   
    return 0;
}