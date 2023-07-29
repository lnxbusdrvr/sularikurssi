 /* ep 20230729 harjoitus5.3.ino */
/******************************************************************/



/* Määrittele kaiuttimen pinni */
#define SUMMERI 8
/* Määrittele liiketunnistinmen (PIR) pinni */
#define PIR 9
/* Määrittele potentiometrin pinni */
#define POTENTIOMETRI A0
/* Määrittele RGB punainen pinni */
#define PUNAINEN 13
/* Määrittele RGB sininen pinni */
#define SININEN 12
/* Määrittele RGB vihreä pinni */
#define VIHREA 11
/* Määrittele liukukytkimen (slide switch) pinni */
#define KYTKIN 2

/* Alustetaan muuttuja PIR-tilan tallentamiseen */
int liikkeenTila = 0;
/* Alustetaan muuttuja kytkimen tilan tallentamiseen */
int kytkimenTila = 0;

/* alustetaan muuttuja
 * joka kirjaa 
 * liiketunnistimimen tilan */
int viimeisinLiikkeenTila = 0;

/* alustetaan muuttuja
 * joka kirjaa 
 * kytkimen viimeisimmän tilan */
int viimeisinKytkimenTila = 0;

void setup() {
  /* Debuggausta varten sarjaportin alustus */
  Serial.begin(9600);

  /* Asetetaan liiketunnistiin inputiksi */
  pinMode(PIR, INPUT);
  /* Asetetaan liiketunnistiin inputiksi */
  pinMode(KYTKIN, INPUT);

  /* Asetetaan ledit ulostuloiksi */
  pinMode(PUNAINEN, OUTPUT);
  pinMode(SININEN, OUTPUT);
  pinMode(VIHREA, OUTPUT);

  /* Asetetaan ledit alusta sammuksiin */
  digitalWrite(PUNAINEN, LOW);
  digitalWrite(SININEN, LOW);
  digitalWrite(VIHREA, LOW);
}

void loop() {
  /* Debuggausta varten */
  Serial.print("Potentiometri ");
  Serial.println(analogRead(POTENTIOMETRI));
  Serial.print("Liiketunnistin ");
  Serial.println(digitalRead(PIR));
  Serial.print("kytin ");
  Serial.println(digitalRead(KYTKIN));
  Serial.print("Kaiutin ");
  Serial.println(digitalRead(SUMMERI));
  /* sijoitetaan-muuttujaan liiketunnistimen tila */ 
  liikkeenTila = digitalRead(PIR);
  kytkimenTila = digitalRead(KYTKIN);

  /* jos ensimmäinen tila ja viimeisin tila eivät ole samoja*/
  if (liikkeenTila != viimeisinLiikkeenTila) {
    /* Vilkuta valoja */
    while (kytkimenTila != viimeisinKytkimenTila ) {
      /* Soita speakeria */
      soitaHalytys();
      /* Vilkuta valoja */
      vilkutaValoja();
      /* Tallenna kytkimen tila */
      viimeisinKytkimenTila = kytkimenTila ;
    }

  }
  /* Tallenna liiketunnistimen tila muuttujaan*/
  viimeisinLiikkeenTila = liikkeenTila;
}

void vilkutaValoja() {
  digitalWrite(PUNAINEN, HIGH);
  delay(200);
  digitalWrite(PUNAINEN, LOW);
  delay(500);
  digitalWrite(SININEN, HIGH);
  delay(200);
  digitalWrite(SININEN, LOW);
  delay(500);
  digitalWrite(VIHREA, HIGH);
  delay(200);
  digitalWrite(VIHREA, LOW);
  delay(500);
}

void soitaHalytys() {
  tone(SUMMERI, 700, 100);
  delay(500);
}

