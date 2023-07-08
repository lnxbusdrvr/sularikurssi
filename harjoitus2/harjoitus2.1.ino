// C++ code
//

/* ep 20230703 harjoitus2.1.ino */
/******************************************************************/
/* Alustetaan muuttujat
 * jotta ledejä olisi 
 * helpompaa käsitellä
 */
int punainenLedi = 2; // Punainenledi osoittaa Arduino pinniin -> 2
int keltainenLedi = 3; // Keltainen ledi osoittaa Arduino pinniin -> 3
int vihreaLedi = 4; // Vihreä ledi osoittaa Arduino pinniin -> 4

/* setup() ajetaan vain kerran alussa, kun
 * Arduino käynnistetään
 *
 * Tämän jälkeen käynnistetään loop()
 */
void setup() {
  /* asetetaan pinnit ulostuloiksi 
   * jotka osoittaa ledeihin
   */
  pinMode(punainenLedi, OUTPUT);
  pinMode(keltainenLedi, OUTPUT);
  pinMode(vihreaLedi, OUTPUT);

  /* Ensiksi annetaan virtaa 0V (LOW)
   * Eli aloitetaan ledit
   * sammutettuna
   */
  digitalWrite(punainenLedi, LOW);
  digitalWrite(keltainenLedi, LOW);
  digitalWrite(vihreaLedi, LOW);
}

/* tämä loop() pyörii kokoajan: 
 * Ikuisesti alusta loppuun ja taas alusta loppuun...
 *
 * kunnes Arduino sammutetaan
 */
void loop() {
  /* Punainen ledi */
  digitalWrite(punainenLedi, HIGH); // Annetaan ledille virtaa 5V (HIGH), eli ledi palaa
  delay(300); // Odotetaan 300 millisekunttia
  digitalWrite(punainenLedi, LOW); // Annetaan virtaa 0V (LOW), eli sammutetaan ledi

  /* Keltainen ledi */
  digitalWrite(keltainenLedi, HIGH); // Annetaan ledille virtaa 5V (HIGH), eli ledi palaa
  delay(300); // Odotetaan 300 millisekunttia (ms)
  digitalWrite(keltainenLedi, LOW); // Annetaan virtaa 0V (LOW), eli sammutetaan ledi

  /* Vihrea ledi */
  digitalWrite(vihreaLedi, HIGH); // Annetaan ledille virtaa 5V (HIGH), eli ledi palaa
  delay(300); // Odotetaan 300 millisekunttia
  digitalWrite(vihreaLedi, LOW); // Annetaan virtaa 0V (LOW), eli sammutetaan ledi

}
/******************************************************************/
/* eof */ 
