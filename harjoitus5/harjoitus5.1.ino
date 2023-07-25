/* ep 20230725 harjoitus5.1.ino */
/******************************************************************/

/* Otetaan käyttöön
 * lcd-kirjasto (LiquidCrystal.h)
 */
#include <LiquidCrystal.h>

/* 
 * Alusta kirjasto lcd:n pinneillä
 *initialize the library with the numbers of the interface pins
 */
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

/* Alusta liikeanturi, joka on pinnissa 6 */
const int liiketunnistin = 6;

/* variable to hold the value of the liiketunnistin */
int liikkeenTila = 0;

/* alustetaan muuttuja
 * joka kirjaa 
 * liiketunnistimimen tilan */
int viimeisinLiikkeenTila = 0;

// a variable to choose which vastaus from the crystal ball
int vastaus;

void setup() {
  /* 16x2lcd, eli sarakkeet x rivit */
  lcd.begin(16, 2);

  /* Asetetaan liiketunnistiin inputiksi */
  pinMode(liiketunnistin, INPUT);

  /* Tulostaa "Ask the" teksti näytölle */
  lcd.print("Ask the");
  /* Aseta kursori asentoon: sarake 0, rivi 1 */
  /* rivi 1 on toinen rivi, koska 0 on eka rivi */
  lcd.setCursor(0, 1);
  /* tulosta "Crystal Ball" toinen rivi */
  lcd.print("Crystal Ball!");
}

void loop() {
  /* sijoitetaan-muuttujaan liiketunnistimen tila */ 
  liikkeenTila = digitalRead(liiketunnistin);

  /* jos ensimmäinen tila ja viimeisin tila eivät ole samoja*/
  if (liikkeenTila != viimeisinLiikkeenTila) {
    /* jos liikeantorin tila on LOW */
    if (liikkeenTila == LOW) {
      /* niin generoit satunnainen (random()) vastaus */ 
      vastaus = random(8);
      /* tyhjennä näyttö ennen vastausta */
      lcd.clear();
      // aseta kursori kohtaan sarake 0, rivi 0 */
      lcd.setCursor(0, 0);
      /* tulosta:"the ball says" */  
      lcd.print("the ball says:");
      /* siirrä kursori seraavalle riville */
      lcd.setCursor(0, 1);

      /* valite vaihtoehto vastaus-muuttujan antamasta arvosta */
      switch (vastaus) {
        /* jos vastaus-muuttuja oli 0 */
        case 0:
          /* Tulosta "Yes" */
          lcd.print("Yes");
          /* switch-case syntaxi vaati break:in case:n lopussa */
          break;

        /* jos vastaus-muuttuja oli 1 */
        case 1:
          /* Tulosta "Most likely" */
          lcd.print("Most likely");
          /* switch-case syntaxi vaati break:in case:n lopussa */
          break;

        /* jos vastaus-muuttuja oli 2 */
        case 2:
          /* Tulosta "Certainly" */
          lcd.print("Certainly");
          /* switch-case syntaxi vaati break:in case:n lopussa */
          break;

        /* jos vastaus-muuttuja oli 3 */
        case 3:
          /* Tulosta "Outlook good" */
          lcd.print("Outlook good");
          /* switch-case syntaxi vaati break:in case:n lopussa */
          break;

        /* jos vastaus-muuttuja oli 4 */
        case 4:
          /* Tulosta "Unsure" */
          lcd.print("Unsure");
          /* switch-case syntaxi vaati break:in case:n lopussa */
          break;

        /* jos vastaus-muuttuja oli 5 */
        case 5:
          /* Tulosta "Ask again" */
          lcd.print("Ask again");
          /* switch-case syntaxi vaati break:in case:n lopussa */
          break;

        /* jos vastaus-muuttuja oli 6 */
        case 6:
          /* Tulosta "Doubtful" */
          lcd.print("Doubtful");
          /* switch-case syntaxi vaati break:in case:n lopussa */
          break;

        /* jos vastaus-muuttuja oli 7 */
        case 7:
          /* Tulosta "No" */
          lcd.print("No");
          /* switch-case syntaxi vaati break:in case:n lopussa */
          break;
      }
    }
  }
  /* Tallenna liiketunnistimen tila muuttujaan*/
  viimeisinLiikkeenTila = liikkeenTila;
}
