//Smart Timer For Liquid Electronic Mosquito Repellents

// Date and time functions using a DS1307 RTC connected via I2C and Wire lib
#include <Wire.h>
#include "RTClib.h"
RTC_DS1307 RTC;
const int RlyPin =  11;      // the number of the RELAY pin
const int Buzz_Pin =  12;      // the number of the buzzer
//int RelayState = 0;

int pushButton1 = 2;
int pushButton2 = 3;
int pushButton3 = 4;
//int even = now.hour();

RTC_DS1307 rtc;
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

void setup () {
  pinMode(RlyPin, OUTPUT);// initialize the RELAY pin as an output:
  pinMode(Buzz_Pin, OUTPUT);// initialize the  buzzer as an output:

  pinMode(pushButton1, INPUT);
  pinMode(pushButton2, INPUT);
  pinMode(pushButton3, INPUT);

  while (!Serial); // for Leonardo/Micro/Zero
  Serial.begin(9600);
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }
  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // july 21, 2021 at 10:00 am )
    //rtc.adjust(DateTime(2021, 7, 21, 10, 0, 0));
  }
}

void loop () {
  DateTime now = rtc.now();

  int buttonState1 = digitalRead(pushButton1); // print out the state of the button:
  int buttonState2 = digitalRead(pushButton2); // print out the state of the button:
  int buttonState3 = digitalRead(pushButton3); // print out the state of the button:


  if (buttonState1 == LOW  && buttonState2 ==  LOW && buttonState3 == LOW) {
    Serial.print("mode ONE ACTIVATED : ");
  }
  if (buttonState1 == LOW  && buttonState2 ==  LOW && buttonState3 == HIGH) {
    Serial.print("mode TWO  ACTIVATED : ");
  }
  if (buttonState1 == LOW  && buttonState2 ==  HIGH && buttonState3 == LOW) {
    Serial.print("mode THREE   ACTIVATED : ");
  }
  if (buttonState1 == LOW && buttonState2 ==  HIGH && buttonState3 == HIGH) {
    Serial.print("mode FOUR  ACTIVATED : ");
  }
  if (buttonState1 == HIGH  && buttonState2 ==  LOW && buttonState3 == LOW) {
    Serial.print("mode FIVE   ACTIVATED : ");
  }
  if (buttonState1 == HIGH  && buttonState2 ==  LOW && buttonState3 == HIGH) {
    Serial.print("mode SIX   ACTIVATED : ");
  }
  if (buttonState1 == HIGH  && buttonState2 ==  HIGH && buttonState3 == LOW) {
    Serial.print("mode SEVEN   ACTIVATED : ");
  }                                                
                                              // / / / ///   mode 1 // 6AM -6PM OFF   ///6PM-6AM ON //// NIGHT MODE

  int even = now.hour();
  even %= 2;
  if (((( now.hour()) >= 18 ) &&  ( now.hour()) <= 23 )  && (buttonState1 == LOW  && buttonState2 ==  LOW && buttonState3 == LOW)) ////
  {
    digitalWrite(RlyPin, HIGH);
    delay(500);
    Serial.print("mode ONE  RUNNING : ");
  }
  if (((( now.hour()) >= 0 ) &&  ( now.hour()) <= 6 )  && (buttonState1 == LOW  && buttonState2 ==  LOW && buttonState3 == LOW)) //
  {

    digitalWrite(RlyPin, HIGH);
    delay(500);
    Serial.print("mode ONE  RUNNING : ");
  }

  // / / / ///   mode 2 //6AM -6PM OFF   ///6PM-23:59pM ON ////00:00 to 6am toggle for every hour//// NIGHT MODE TOGGLE

  if (((( now.hour()) >= 18 ) &&  ( now.hour()) <= 23 )  && (buttonState1 == LOW  && buttonState2 ==  LOW && buttonState3 == HIGH)) ////
  {

    digitalWrite(RlyPin, HIGH);
    delay(500);
    Serial.print("mode TWO  RUNNING : ");
  }

  if (((( now.hour()) >= 00 ) &&  ( now.hour()) <= 6 )  && (buttonState1 == LOW  && buttonState2 ==  LOW && buttonState3 == HIGH && (even == 0  ))) //
  {
    digitalWrite(RlyPin, HIGH);
    delay(500);
    Serial.print("mode TWO  RUNNING : ");
  }
  // / / / ///   mode 3 ////6AM -6PM OFF   ///6PM-23:59pM ON ////00:00 to 6am toggle for every hour//// NIGHT MODE TOGGLE with buzzer at 05:59:55 sec

  if (((( now.hour()) >= 18 ) &&  ( now.hour()) <= 23 )  && (buttonState1 == LOW  && buttonState2 ==  HIGH && buttonState3 == LOW)) //
  {
    digitalWrite(RlyPin, HIGH);
    delay(500);
    Serial.print("mode THREE  RUNNING : ");
  }


  if (((( now.hour()) >= 00 ) &&  ( now.hour()) <= 6 )  && (buttonState1 == LOW  && buttonState2 ==  HIGH && buttonState3 == LOW && (even == 0  ))) ///
  {

    digitalWrite(RlyPin, HIGH);
    delay(500);
    Serial.print("mode THREE  RUNNING : ");
  }
  if (((((( now.second()) >= 55 ) &&  ( now.second()) <= 60 ) &&  ( now.hour()) == 5 ) &&  ( now.minute()) == 59 )  && (buttonState1 == LOW  && buttonState2 ==  HIGH && buttonState3 == LOW  )) //
  {

    digitalWrite(Buzz_Pin, HIGH);
    delay(500);
    Serial.print("mode THREE  RUNNING : ");
  }
  // / / / ///   mode 4 // office mode// 10AM -18PM on   ///18PM-10AM off ////

  if (((( now.hour()) >= 10 ) &&  ( now.hour()) <= 18 )  && (buttonState1 == LOW  && buttonState2 ==  HIGH && buttonState3 == HIGH)) ///
  {

    digitalWrite(RlyPin, HIGH);
    delay(500);
    Serial.print("mode FOUR  RUNNING: ");
  }
  // / / / ///   mode 5 // office toggle mode//   / toggle  each hour between 10AM -18PM //18PM-10AM off ////

  if (((( now.hour()) >= 10 ) &&  ( now.hour ()) <= 18 )  && (buttonState1 == HIGH  && buttonState2 ==  LOW && buttonState3 == LOW && (even == 0  ))) //
  {
    digitalWrite(RlyPin, HIGH);
    delay(500);
    Serial.print("mode FIVE   RUNNING : ");
  }
  // / / / ///   mode 6 //hall mode //

  if (((( now.hour()) >= 17 ) &&  ( now.hour()) <= 22 )  && (buttonState1 == HIGH  && buttonState2 ==  LOW && buttonState3 == HIGH   )) //
  {
    digitalWrite(RlyPin, HIGH);
    delay(500);
    Serial.print("mode SIX   RUNNING : ");
  }
  // / / / ///   mode 7 //all day toggle

  if (((( now.hour()) >= 0 )  )  && (buttonState1 == HIGH  && buttonState2 ==  HIGH && buttonState3 == LOW && (even == 0  )))  ///
  {
    digitalWrite(RlyPin, HIGH);
    delay(500);
    Serial.print("mode SEVEN   RUNNING : ");
  }

  Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.day(), DEC);
  Serial.print(" (");
  Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
  Serial.print(") ");
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.println();
  delay(500);

  digitalWrite(RlyPin, LOW);
  digitalWrite(Buzz_Pin, LOW);
}
