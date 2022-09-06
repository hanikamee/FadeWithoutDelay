// FadeWithoutDelay
// This Project shows how to fade an LED on pin 9 using the analogWrite()function.


int led = 9;           // the PWM pin the LED is attached to
int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by

unsigned long previousMillis = 0;        // will store last time LED was updated

const long interval = 30;    

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(led, OUTPUT);
}


// the loop routine runs over and over again forever:
void loop() {
  // set the brightness of pin 9:
  analogWrite(led, brightness);
  
  unsigned long currentMillis = millis();

  
  
   if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;
   // change the brightness for next time through the loop:
    brightness = brightness + fadeAmount;
  
  // reverse the direction of the fading at the ends of the fade:
    if (brightness <= 0 || brightness >= 255) {
      fadeAmount = -fadeAmount;
  }
  }
}
