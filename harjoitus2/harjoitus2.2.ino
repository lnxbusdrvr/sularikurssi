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
int keltainenLedi = 3; // Keltainen ledi, Aurduino pinn -> 3
int vihreaLedi = 4; // Vihreä ledi, Aurduino pinni -> 4

/* Aseta halumasi tempo bpm-muuttujaan */
int bpm = 120; // Beats per minute
/* aika joka tulee dela():hiin
 * kaava:
 * https://cboard.cprogramming.com/c-programming/81717-metronome.html
 */
int ms = (60.0f / (float)bpm) * 1000;

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

void loop() {
  /* silmukka kiertää kolme kertaa
   * ts. laskee kolmeen
   * alkaen nollasta (0)
   * yy  = 0
   * kaa = 1
   * koo = 2
   * Lopettaa silmukan
   */
  for (int i = 0;i <= 2; i++) {
    digitalWrite(punainenLedi, HIGH); // Punainen ledi saa virtaa 5V, eli se palaa
    delay(ms); // Odottaa ms ms
    digitalWrite(punainenLedi, LOW); // Punainen ledille asetetaan virtaa 0V, eli se sammuu
    delay(ms); // Odottaa ms ms
  }
  /* neljänellä kerralla */
  digitalWrite(punainenLedi, HIGH); // Punainen ledi saa virtaa 5V, eli se palaa
  digitalWrite(keltainenLedi, HIGH); // Keltainen ledi saa virtaa 5V, eli se palaa
  digitalWrite(vihreaLedi, HIGH); // Vihreä ledi saa virtaa 5V, eli se palaa
  delay(ms); // Odota ms ms
  digitalWrite(punainenLedi, LOW); // Punainen ledille asetetaan virtaa 0V, eli se sammuu
  digitalWrite(keltainenLedi, LOW); // Keltainen ledille asetetaan virtaa 0V, eli se sammuu
  digitalWrite(vihreaLedi, LOW); // Vihreälle ledille asetetaan virtaa 0V, eli se sammuu
  delay(ms);
}
/******************************************************************/
/* eof */ 
