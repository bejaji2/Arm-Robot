#include "meArm.h" 
#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);



//pins for meArm
Servo ServoLengankiri; //servo shoulder
Servo ServoLengankanan; //servo elbow
Servo ServoBawah; //
Servo ServoCapit;
int x;


int s2 = 8; //inisialisasi sensor pin s2 ke pin 8 arduino
int s3 = 10; //inisialisasi sensor pin s3 ke pin 10 arduino
int outPin = 9; //inisialisasi sensor pin s2 ke pin 9 arduino



boolean DEBUG = true;

void setup() {
  
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(outPin, INPUT); 
lcd.init();                      // initialize the lcd 
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("   Kelompok 3");
  // inisialisasi motor servo
  ServoLengankiri.attach(4);    //elbow ke pin 4 arduino
  ServoLengankanan.attach(3);   //shoulder ke pin 3 arduino
  ServoBawah.attach(6); //base servo ke pin 6 arduino
  ServoCapit.attach(5); // griper ke pin 5 arduino
  ServoBawah.write(180); // 
  delay(1000);
  ServoLengankiri.write(170);
  delay(1000);
  ServoLengankanan.write(30);
  delay(1000);
  ServoCapit.write(160);
  delay(1000);
  Serial.begin(9600); 
   }

void loop() {
  //identify color
  char color = get_color();
  switch(color) {
    case 'r':   //red
    delay(1000);
    ServoBawah.write(90); 
    delay(1000);
    ServoLengankiri.write(70); 
    delay(1000);
    ServoLengankanan.write(70); 
    delay(1000);
    ServoCapit.write(90); 
    delay(1000);
    ServoLengankanan.write(70); 
    delay(1000);
    ServoLengankiri.write(120); 
    delay(1000);
    ServoBawah.write(55); 
    delay(1000);
    ServoCapit.write(160); 
    delay(1000);
    delay(1000);
    ServoLengankiri.write(120);
    delay(1000);
    ServoLengankanan.write(70);
    delay(1000);
    ServoBawah.write(180);
    delay(1000);
    ServoCapit.write(160);
      break;
    case 'b': //blue
    delay(1000);
    ServoBawah.write(90);
    delay(1000);
    ServoLengankiri.write(70); 
    delay(1000);
    ServoLengankanan.write(70); 
    delay(1000);
    ServoCapit.write(90); 
    delay(1000);
    ServoLengankanan.write(70); 
    delay(1000);
    ServoLengankiri.write(120); 
    delay(1000);
    ServoBawah.write(30); 
    delay(1000);
    ServoCapit.write(160); 
    delay(1000);
    delay(1000);
    ServoLengankiri.write(120);
    delay(1000);
    ServoLengankanan.write(70);
    delay(1000);
    ServoBawah.write(180);
    delay(1000);
    ServoCapit.write(160);
    break;
    case 'g':

    delay(1000);
    ServoBawah.write(90);
    delay(1000);
    ServoLengankiri.write(70); 
    delay(1000);
    ServoLengankanan.write(70); 
    delay(1000);
    ServoCapit.write(90); 
    delay(1000);
    ServoLengankanan.write(70); 
    delay(1000);
    ServoLengankiri.write(120); 
    delay(1000);
    ServoBawah.write(0); 
    delay(1000);
    ServoCapit.write(160); 
    delay(1000);
   
   ServoLengankiri.write(120);
    delay(1000);
    ServoLengankanan.write(70);
    delay(1000);
    ServoBawah.write(180);
    delay(1000);
    ServoCapit.write(170);
      break;
   case 'u';
    delay(1000);
    ServoLengankiri.write(130);
    delay(1000);
    ServoLengankanan.write(70);
    delay(1000);
    ServoBawah.write(180);
    delay(1000);
    ServoCapit.write(170);
    break;
  }
 delay(500);
  return; 
  }

char get_color() {

  int R;
  int G;
  int B;

  char color;
   
  //read sensor output
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);
  R = pulseIn(outPin, LOW);

 //green sensor output
  digitalWrite(s2, HIGH);
  digitalWrite(s3, HIGH);
  G = pulseIn(outPin, LOW);
  
 //blue sensor output
  digitalWrite(s2, LOW);
  digitalWrite(s3, HIGH);
  
  B = pulseIn(outPin, LOW);
 
  
  if((R>5) && (R<100) && (G>15) && (G<150) && (B>15) && (B<150))    // calibrasi merah
    {
      if (DEBUG) 
       {Serial.print("R = ");
        Serial.print(R);
        Serial.print("  G = ");
        Serial.print(G);
        Serial.print("  B = ");
        Serial.println(B);
        Serial.println("merah");
        lcd.setCursor(3,1);
        lcd.print("warna merah");
        lcd.setCursor(0,0);
        lcd.print("   Kelompok 3");}
      color = 'r';
    }
  else if((R>10) && (R<150) && (G>3) && (G<150) && (B>5) && (B<150) && (B<G))  // calibrasi biru
    {
      if (DEBUG) 
       {Serial.print("R = ");Serial.print(R);
        Serial.print("  G = ");Serial.print(G);
        Serial.print("  B = ");Serial.println(B);
        Serial.println("biru");
        
        lcd.setCursor(3,1);
        lcd.print("warna biru");
        lcd.setCursor(0,0);
        lcd.print("   Kelompok 3");}
      color = 'b';
    }
  else if((R>18) && (R<150) && (G>5) && (G<150) && (B>8) && (B<150) && (B>G))  // kalibrasi hijau
    {
      if(DEBUG)
      { Serial.print("R = ");
        Serial.print(R);
        Serial.print("  G = ");
        Serial.print(G);
        Serial.print("  B = ");
        Serial.println(B);
        Serial.println("hijau");
        
        lcd.setCursor(3,1);
        lcd.print("warna hijau");
        lcd.setCursor(0,0);
        lcd.print("   Kelompok 3");}
      color = 'g';
    }
  else 
    {  
      if (DEBUG) {
        Serial.print("R = ");
        Serial.print(R);
        Serial.print("  G = ");
        Serial.print(G);
        Serial.print("  B = ");
        Serial.println(B);
        
        lcd.setCursor(0,1);
        lcd.print("Masukan Warna");
        lcd.setCursor(0,0);
        lcd.print("   Kelompok 3");
      }
      color = 'u'; //unidentified
      Serial.println("Color is Unidentified");
    }

  return color;
}
