// Roomba Scheduler

// Roomba port 7 (GND) onto Arduino GND
// Roomba port 3 (RXD) onto Arduino D4
// Roomba port 4 (TXD) onto Arduino D3
// Roomba port 5 (BRC) onto Arduino D5

#include <SoftwareSerial.h>

int rxPin = 3 ;
int txPin = 4 ;
int ddPin = 5 ;
int ledPin = 13 ;

SoftwareSerial Roomba(rxPin, txPin) ;

void setup()
{

  // Arduino pins setup

  pinMode(ddPin,  OUTPUT) ;
  pinMode(ledPin, OUTPUT) ;
  
  digitalWrite(ledPin, HIGH) ;
  digitalWrite(ddPin, LOW) ;
  
  delay(2000) ;

  // Changing Roomba baud rate to 19200
  
  digitalWrite(ddPin, HIGH) ;
  delay(100) ;
  digitalWrite(ddPin, LOW) ;
  delay(200) ;
  digitalWrite(ddPin, HIGH) ;
  delay(100) ;
  digitalWrite(ddPin, LOW) ;
  delay(200) ;
  digitalWrite(ddPin, HIGH) ;
  delay(100) ;
  digitalWrite(ddPin, LOW) ;
  delay(200) ;
  digitalWrite(ddPin, HIGH) ;
  delay(100) ;

  // Serial communication setup

  Serial.begin(19200) ;
  Roomba.begin(19200) ;

  // Roomba Open Interface setup

  Serial.println("Roomba Open Interface setup...") ;
  delay (1000) ;
 
  Roomba.write(128) ;  // START
  delay(150) ;
  Serial.println("Sending Safe Mode command...") ;
  delay (1000) ;
  
  Roomba.write(131) ;  // CONTROL
  delay(150) ;
  digitalWrite(ledPin, LOW) ;
  delay (500) ;

  // Sing a song

  sing() ;

  // Set current time
  
  setCurrentTime(5, 19, 03) ;

  // Set schedule

  setSchedule() ;

  // Finishing

  Serial.println("Roomba Open Interface stopping...") ;

  Roomba.write((byte)173) ; // Stop the OI

  Serial.println ("All Done Baby!") ;

}

void loop()
{

}

void sing ()
{

  Serial.println("Singing...") ;

  Roomba.write((byte)140) ;
  Roomba.write((byte)0) ;
  Roomba.write((byte)7) ;
  delay(500) ;

  Roomba.write((byte)76) ;
  Roomba.write((byte)16) ;
  Roomba.write((byte)76) ;
  Roomba.write((byte)32) ;
  Roomba.write((byte)79) ;
  Roomba.write((byte)16) ;
  Roomba.write((byte)79) ;
  Roomba.write((byte)16) ;
  Roomba.write((byte)77) ;
  Roomba.write((byte)16) ;
  Roomba.write((byte)74) ;
  Roomba.write((byte)16) ;
  Roomba.write((byte)72) ;
  Roomba.write((byte)32) ;
  delay(500) ;

  Roomba.write((byte)141) ;
  delay(50) ;
  Roomba.write((byte)0) ;
  delay(50) ;

  delay(500) ;

  Serial.println("Singing [OK]") ;

}

void setCurrentTime (int aDayOfWeek, int anHourCount, int aMinuteCount)
{

  Serial.println("Setting current time...") ;

  Roomba.write((byte)168) ; // Command code
  Roomba.write((byte)aDayOfWeek) ; // Day (0: Sunday, 1: Monday, 2:Tuesday, 3:Wednesday, 4: Thursday, 5: Friday, 6: Saturday)
  Roomba.write((byte)anHourCount) ; // Hour
  Roomba.write((byte)aMinuteCount) ; // Minute

  delay(500) ;

  Serial.println("Setting current time [OK]") ;

}

void setSchedule ()
{

  Serial.println("Setting schedule...") ;

  Roomba.write((byte)167) ; // Command code
  Roomba.write((byte)127) ; // Days (127 (dec) = 01111111 (binary) = 0(Sat)(Fri)(Thu)(Wed)(Tue)(Mon)(Sun) -> schedule everyday)
  Roomba.write((byte)0) ; // Sunday Hour
  Roomba.write((byte)0) ; // Sunday Minute
  Roomba.write((byte)18) ; // Monday Hour
  Roomba.write((byte)0) ; // Monday Minute
  Roomba.write((byte)18) ; // Tuesday Hour
  Roomba.write((byte)0) ; // Tuesday Minute
  Roomba.write((byte)0) ; // Wednesday Hour
  Roomba.write((byte)0) ; // Wednesday Minute
  Roomba.write((byte)18) ; // Thursday Hour
  Roomba.write((byte)0) ; // Thursday Minute
  Roomba.write((byte)0) ; // Friday Hour
  Roomba.write((byte)0) ; // Friday Minute
  Roomba.write((byte)12) ; // Saturday Hour
  Roomba.write((byte)0) ; // Saturday Minute

  delay(500) ;

  Serial.println("Setting schedule [OK]") ;
  
}
