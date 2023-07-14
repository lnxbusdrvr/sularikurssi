// C++ code

/* ep 20230713 harjoitus3.3.ino */
/******************************************************************/
/******************************************************************/
/* Alustetaan muuttujat jotta ledejä olisi helpompaa käsitellä */

/* LED on ARDUINO pin 13:ssa */
#define LED 12
/* NAPPI1 on Arduino pin 3:ssa */
#define NAPPI1 3
/* NAPPI2 on ARDUINO pinni 2:ss */
#define NAPPI2 2
/* lämpösensori (SENSOR) on ARDUINO pinni A0:ssa */
#define SENSOR A0

/* Alustetaan LT-muuttuja lämpöanturin arvoille */
float lt = 0; 
/* Alustetaan ADC-muuttuja */ 
//float adc = 0;
int adc = 0;
/* ADC keskiarvo */
int avgADC = 0;

void setup() {
  pinMode(LED, OUTPUT); /* LED ulostulo */
  pinMode(NAPPI1, INPUT); /* NAPPI1 on alustettu */
  pinMode(NAPPI2, INPUT); /* NAPPI2 on alustettu */
  /*
   * Kutsutaan sisäänrakennettu funktio: attachInterrupt()
   * ja sen sisällä digitalPinToInterrupt()
   * Jotka liittyvät keskeytyksen käsittelyyn NAPPI1:llä,
   * ja kutsuvat keskeytys()-proseduuria/aliohjelmaa
   * HUOM: keskeytys()-proseduuri/aliohjelma
   * kutsutaan ilman sulkeita,
   * kun NAPPI1:n tila muuttuu (FALLING) 
   * FALLING on laukaisutapa,
   * millä tavalla keskeytys() kutsutaan 
   */
  attachInterrupt(digitalPinToInterrupt(NAPPI1), keskeytys, FALLING);
  attachInterrupt(digitalPinToInterrupt(NAPPI2), keskeytys, FALLING);
  Serial.begin(9600);  // Aloita sarjaportti

  /* Asetetaan LED sammutetuksi alussa */
  digitalWrite(LED, LOW); 
}

void loop() {
}

void keskeytys() {
  // Luetaan lämpötila-anturin arvo
  adc = analogRead(SENSOR);

  /* lasketaan 50x */
  for (int i = 0;i < 50;i++) {
    /* Lisätään arvo keskiarvon laskentaan */
    avgADC += adc;
    /* Odota 20 ms ennen seuraavaa lukemista*/
    delay(20);
  }
  /* Lasketaan keskiarvo */
  avgADC /= 50;
  /* Muunnetaan lämpötila vastaavaksi arvoksi */ 
  lt = 0.7 * avgADC - 77.4;

  /* Tulostetaan tulokset */
  Serial.print("ADC: ");
  Serial.print(avgADC);
  Serial.print(" lt: ");
  Serial.println(lt);

  /* Nollataan keskiarvon laskentaan liittyvät muuttujat */
  avgADC = 0;
}
