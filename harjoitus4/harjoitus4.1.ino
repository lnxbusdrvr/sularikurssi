/* ep 20230716 harjoitus4.1.ino */
/******************************************************************/

/* Otetaan käyttöön
 * eeprom-kirjasto (EEPROM.h)
 */
#include <EEPROM.h>

/* Alustetaan muuttujat jotta ledejä olisi helpompaa käsitellä */
/* LED on ARDUINO pin 13:ssa */
#define LED 12
/* NAPPI1 on Arduino pin 3:ssa */
#define NAPPI1 3
/* NAPPI3 on ARDUINO pinni 4:ss */
#define NAPPI2 2
/* NAPPI3 (vasemmanpuolisin) 
 * on ARDUINO pinni 4:ss */
#define NAPPI3 4
/* lämpösensori (SENSOR) on ARDUINO pinni A0:ssa */
#define SENSOR A0
/* EEPROMin koko 1 kt/kB */
#define EEPROM_KOKO 1024

/* Alustetaan muistipaikkalaskuri */
int muistipaikka = 0;

void setup() {
  pinMode(LED, OUTPUT); /* LED ulostulo */
  pinMode(NAPPI1, INPUT); /* NAPPI1 on alustettu */
  pinMode(NAPPI2, INPUT); /* NAPPI2 on alustettu */
  pinMode(NAPPI3, INPUT); /* NAPPI3 on alustettu */
  /* Jos DEBUGgaa */
  //Serial.begin(9600);  /* Alusta sarjaportti */
  /* Tämä aiheuttaa ainakin TINKERCAD:ssa EEPROM.h kanssa header not found:in */
  //EEPROM.begin(EEPROM_KOKO); /* Alusta EEPROM-muisti 1 kilotavun (kt) (Engl. kB) kokoiseksi */
  /* Nämä aiheuttaa TINKERCAD:ssa EEPROM.h kanssa header not found:in */
  //attachInterrupt(digitalPinToInterrupt(NAPPI1), keskeytys, FALLING);

  /* Asetetaan LED sammutetuksi alussa */
  digitalWrite(LED, LOW); 
}

void loop() {
  if (digitalRead(NAPPI3) == LOW) { /* Jos nappi 3 on painettu */ 
    kirjoitaEepromMuistiin(); /* kutsu aliohjelmaa */
  }
}

void kirjoitaEepromMuistiin() {
   /*
   * random(1, 100)
   * valitsee pseudosatunnaisesti 
   * numeron 1:stä 100 asti
   */
  int satunnaisluku = random(1, 100);
  /* Kirjoita EEPROM-muistiin
   * EEPROM.write(muistopaikka, numero)
   * Eli kirjoittaa muistipaikka-muuttujan
   * arvon määritelmään osoitteseen.
   * numero = joku numero, tässä tapauksessa
   * pseudosatunnaisluku (satunnaisluku-muuttuja) 
   */
  EEPROM.write(muistipaikka, satunnaisluku);
  delay(200); /* Odota kaksi sekuntia, jotta EEPROM:iin ehditään kirjoittaa */
    /* DEBUG
    Serial.print("Muistipaikka: ");
    Serial.print(muistipaikka);
    Serial.print(" nro: ");
    Serial.println(satunnaisluku);
    */
  muistipaikka++; /* kasvattaa muistipaikka-muuttujan yhdellä numerolla */
}
