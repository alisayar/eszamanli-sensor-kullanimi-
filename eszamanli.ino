#include "DHT.h"

#define DHTPIN 3

#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE, 6);


const int PIR=2;
int hareketdegeri=0;

int isik(){
  int LDR = A0;
  int isikdegeri = analogRead(LDR);
   /*
       Serial.print("Isik Degeri:");
       Serial.println(isikdegeri);
       */
  return map(isikdegeri,0,1023,0,100);
}
int gaz(){
  int gazdegeri = analogRead(A2);
/*
    Serial.print("Gaz Degeri");
    Serial.println(gazdegeri);
    */
  return map(gazdegeri,0,1023,0,100);

}
int su(){  
  int sudegeri = analogRead(A1);
    /*
    Serial.print("Su Seviyesi:");
    Serial.println(sudegeri);
    */
  return map(sudegeri,0,1023,100,0); //su sensörü ters çalışıyor
    
}
int hareket(){
  hareketdegeri = digitalRead(PIR);
  pinMode(PIR, INPUT);
      /*
      Serial.println(hareketdegeri);
      */
  return map(hareketdegeri,0,1,0,100);
      
}



int sicaklik(){ //seref
  
  int t = dht.readTemperature();
  return t;
}
int nem(){  //seref
 
  int h = dht.readHumidity(); 
  return h;
}

void setup(){
  Serial.begin(9600);
  dht.begin();
}

void loop()
{
  
  Serial.println(String(isik())+","+String(gaz())+","+String(su())+","+String(hareket())+","+String(sicaklik())+","+String(nem()));
  delay(1000);
}


