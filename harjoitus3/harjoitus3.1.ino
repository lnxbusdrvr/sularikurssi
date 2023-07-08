// C++ code
// C++ code

/* ep 20230708 harjoitus3.1.ino */
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
#define NAPPI1 3

void setup() {
  pinMode(LED, OUTPUT); /* LED ulostulo */
  pinMode(NAPPI1, INPUT); /* NAPPI1 on sisääntulo (INPUT) */

  /* Ensiksi annetaan virtaa 0V (LOW)
   * Eli aloitetaan ledi
   * sammutettuna
   */
  digitalWrite(LED, LOW); 
}

void loop() {
  /* Nappi = HIGH = ei painettu
   * Nappi = LOW  = painettu alas
   */
  if ( digitalRead(NAPPI1) == LOW) /*  Jos NAPPI1 on pinettu */
    digitalWrite(LED, HIGH);         /* laita LED palamaan    */

  digitalWrite(LED, LOW); /* muuten pitä LED sammutettuna */
}
/******************************************************************/
/* eof */ 
