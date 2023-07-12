// C++ code
// C++ code

/* ep 20230712 harjoitus3.2.ino */
/******************************************************************/
/******************************************************************/
/* Alustetaan muuttujat
 * jotta ledejä olisi 
 * helpompaa käsitellä
 */
//
/* LED on ARDUINO pin 13:ssa   */
#define LED 12
/* NAPPI1 on Arduino pin 3:ssa */

int laskuri = 0; /*^laskurin austus)*/
#define NAPPI1 3

void setup() {
  pinMode(LED, OUTPUT); /* LED ulostulo */
  pinMode(NAPPI1, INPUT); /* NAPPI1 on alustettu */
  /*
   * Kutsutaan sisäänrakennettu funktio:attachInterrupt()
   * ja sen sisällä digitalPinToInterrupt()
   * Jotka heittää keskeytyksen NAPPI1:een, 
   * ja kutsu keskeytys()-proseduuri/aliohjelma
   * HUOM: keskeytys()-proseduuri/aliohjelma
   * kutsutaan ilman sulkeita,
   * kun painetaan (FALLING) NAPPI1:stä
   * FALLING on laukaisutapa,
   * millä tavalla keskeytys() kutsutaan 
   */
  attachInterrupt(digitalPinToInterrupt(NAPPI1), keskeytys, FALLING);
  Serial.begin(9600);  // Aloita sarjaportti

  /* Ensiksi annetaan virtaa 0V (LOW)
   * Eli aloitetaan ledi
   * sammutettuna
   */
  digitalWrite(LED, LOW); 
}

void loop() {
}

void keskeytys() {
  /*
  if (digitalRead(LED) == HIGH)
    digitalWrite(LED, LOW);
  if (digitalRead(LED) == LOW)
    digitalWrite(LED, HIGH);
  */

  laskuri++;
  Serial.print("Laskuri: ");
  Serial.println(laskuri);

  if (laskuri % 2 == 0) /* jakojäännös = 0 = Parillinen */
    digitalWrite(LED, HIGH);
  if (laskuri % 2 == 1) /* jakojäännös = 1 = Pariton */
    digitalWrite(LED, LOW);

}
/******************************************************************/
/* eof */ 
