#include <DHT.h>

#define DHTPIN 2 
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
float hum;
float temp;



int groundpin;            
int powerpin;             
const int xpin = A0;                 
const int ypin = A1;                 
const int zpin = A2; 
int sensorReading = 0;     
int ledState = LOW; 
     
const int knockSensor = A3;
const int threshold = 100;                 

const String XREADING = "X: ";
const String YREADING = "Y: ";
const String ZREADING = "Z: ";
const String TAB = "\t";
float converted = 0.00;

void setup()
{
    
    Serial.begin(9600);
     Serial.println("CLEARSHEET");
      //Serial.println("LABEL,Date,Time,XREADING,YREADING,ZREADING,sensorReading,temp,hum");

    pinMode(groundpin, OUTPUT);
    pinMode(powerpin, OUTPUT);
    digitalWrite(groundpin, LOW);
    digitalWrite(powerpin, HIGH);
    dht.begin(); 
     Serial.println("LABEL,Date,Time,blank,XREADING,YREADING,ZREADING,sensorReading,temp,hum");
}

void loop()
{
 // Serial.println();
      sensorReading = analogRead(knockSensor);
  //if (sensorReading >= threshold) {
 
    //Serial.println("Vibe!");
    //Serial.println(sensorReading);
    //Serial.print(XREADING + analogRead(xpin) + TAB);
    //Serial.print(YREADING + analogRead(ypin) + TAB);
    //Serial.print(ZREADING + analogRead(zpin));
    //Serial.println();
    hum = dht.readHumidity();
   temp= dht.readTemperature();
//
//   // Serial.print("Celsius = ");
//    //Serial.print(temp);
//    
//    Serial.write(176); 
//    //Serial.println("C");
//
    converted = ( temp * 1.8 ) + 32;
//    //Serial.print("Fahrenheit = ");
//    //Serial.print(converted);
//   
//      Serial.write(176); 
//    //Serial.println("F");
//
//    //Serial.print("Humidity =");
//    //Serial.println(hum);
//    
    Serial.print("DATA,DATE,TIME,");
    Serial.print(",");
    Serial.print(analogRead(xpin));
    Serial.print(",");
    Serial.print(analogRead(ypin));
    Serial.print(",");
    Serial.print(analogRead(zpin));
    Serial.print(",");
    Serial.print(sensorReading);
   Serial.print(",");
   Serial.print(converted);
    Serial.print(",");
   Serial.print(hum);
   Serial.println("\n");
    delay(600);
  
  
}
