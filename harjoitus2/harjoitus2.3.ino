// C++ code
//

/* lnxbusdrvr 20230703 harjoitus2.2.ino */
/******************************************************************/

/* Asetetaan pinnien taakse 
 * muuttujat, jotta koodia
 * olisi helpompaa
 * käsitellä
 */
int punainenLedi = 2; // Punainen ledi, Aurduino pinni -> 2
int keltainenLedi = 3;// Keltainen ledi, Aurduino pinn -> 3
int vihreaLedi = 4;   // Vihreä ledi, Aurduino pinni -> 4

void setup() {
  /* asetetaan ulostuloksi ledit */
  pinMode(punainenLedi, OUTPUT);
  pinMode(keltainenLedi, OUTPUT);
  pinMode(vihreaLedi, OUTPUT);
  Serial.begin(9600); /* alustaa sarjaportti */

  /* Ensiksi annetaan virtaa 0V (LOW)
   * Eli aloitetaan ledit
   * sammutettuna
   */
  digitalWrite(punainenLedi, LOW);
  digitalWrite(keltainenLedi, LOW);
  digitalWrite(vihreaLedi, LOW);
}

void loop() {
  digitalWrite(punainenLedi, HIGH);  /* Ledit saa       */
  digitalWrite(keltainenLedi, HIGH); /* virtaa ->  5V   */
  digitalWrite(vihreaLedi, HIGH);    /* eli ledit palaa */
  /* Tulostaa sarjaporttiin
   * tekstin -> LED ON */
  Serial.println("LED ON");
  delay(2000); /* Odottaa 2 sek */
    
  digitalWrite(punainenLedi, LOW);  /* Ledit saa        */
  digitalWrite(keltainenLedi, LOW); /* virtaa ->  0V    */
  digitalWrite(vihreaLedi, LOW);    /* eli ledit sammuu */
  /* Tulostaa sarjaporttiin
   * tekstin -> LED OFF */
  Serial.println("LED OFF");
  delay(2000); /* Odottaa 2 sek */
}
/******************************************************************/
/* eof */ 
