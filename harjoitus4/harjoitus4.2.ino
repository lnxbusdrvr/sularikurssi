/* ep 20230720 harjoitus4.2.ino */
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

  Serial.begin(9600);  /* Alusta sarjaportti */
  /* Tämä aiheuttaa ainakin TINKERCAD:ssa EEPROM.h kanssa header not found:in */
  EEPROM.begin(EEPROM_KOKO); /* Alusta EEPROM-muisti 1 kilotavun (kt) (Engl. kB) kokoiseksi */

  /* Asetetaan LED sammutetuksi alussa */
  digitalWrite(LED, LOW); 
}

void loop() {
  if (digitalRead(NAPPI3) == LOW) { /* Jos nappi 3 on painettu */ 
    kirjoitaEepromMuistiin(); /* kutsu aliohjelmaa */
  }
  if (digitalRead(NAPPI1) == LOW) { /* Jos nappi 1 on painettu */
    lueEepromJaTulosta();
  }
  if (digitalRead(NAPPI2) == LOW) { /* Jos nappi 2 on painettu */
    tyhjennaEeprom();
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

void tyhjennaEeprom() {
  Serial.println("Tyhjennetään EEPROM ....");
  /* EEPROM.length() antaaa EEPROM koon */
  for (int i = 0;i < EEPROM.length();i++) {
    EEPROM.write(i, 0); /* EEPROM tyhjennetään ylikirjoittamalla
                         * HUOM! EEPROMiin kirjoittaminen lyhentää
                         * sen käyttöikää
                         * Normaalisti EEPROM elinikä on
                         * että se kestää 
                         * noin 100 000 kertaista 
                         * kirjoitusta, jolloin se on käyttäkelvoton
                         */

  }
  muistipaikka = 0;
  Serial.println("EEPROM on tyhjä"); 
}

void lueEepromJaTulosta() {
  Serial.println("Luetaan EEPROM ...");
  /* EEPROM Antaa dataksi vain tavuja (byte) 
   * joudumme muuntamaan tavut kokonaisluvuiksi
   */

  /* EEPROM.length() antaa EEPROM-koon */
  int eepromSize = EEPROM.length();

  // Varmistetaan, että eepromSize on parillinen, jotta voimme lukea tavupareittain
  eepromSize -= eepromSize % 2;

  for (int i = 0; i < eepromSize; i += 2) {
    byte aArvo1 = EEPROM.read(i); // Ensimmäinen tavu
    delay(200); /* odotetaan hetki */
    byte bArvo2 = EEPROM.read(i + 1); // Toinen tavu

    /* Kootaan kaksi tavua yhdeksi int-tyyppiseksi arvoksi
     * Siirretään bittiä (bit shift) 8x vasemmalle:
     * bArvo << 8
     */
    int iArvo = (bArvo1 << 8) | bArvo2;

    /* Tulostetaan alkuperäinen (int) arvo
     * sarjaporttiin
     */
    Serial.print("arvo: ");
    Serial.println(iArvo);
  }
}
