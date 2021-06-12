//Lab6_section2_timer0_starter.ino
#define DIM_GREEN_BLUE_COLOR 0x001F1F;
#define LED_CLOCK_PIN 11
#define LED_DATA_PIN 12
#define DIM_RED_COLOR 0x1F0000;
#define DIM_BLUE_COLOR 0x001F00;
#define DIM_GREEN_COLOR 0x00001F;

enum directionState_t {stopped, forward, backward, turn_left, turn_right};

int directionState = stopped;
int previousDirectionState = -1;
boolean isNewState;
int stateTimer = 0;
unsigned long timeStampStartOfLoopMs = 0;



void setup() {
  Serial.begin(9600);
  Serial.println(F("Testing motor A and B using Timer0 in fast PWM mode 3."));
  Serial.println(F("Requires external 9V battery pack.")); 
  Serial.println(TCCR0B);
  Serial.println(TCCR0A);

  configureTimer0RegisterForPWMtoDriveMotor();
  //go_backward(120);
  //go_forward(120);
  //turn_clockwise(120);
  //turn_counterclockwise(120);

  //display_color_on_RGB_led(0xFF0000); //red
  //display_color_on_RGB_led(0x00FF00); //blue
  //display_color_on_RGB_led(0x0000FF); //green
  DDRB |= 0x18;
  PORTB &= 0xE7;
}
void loop() {
  //timeStampStartOfLoopMs = millis();
  isNewState = (directionState != previousDirectionState);
  previousDirectionState = directionState;
  
  switch (directionState) {
    case forward: 
      if (isNewState) {
        go_forward(120);
        stateTimer = 0;
        Serial.println(F("new State is FORWARD"));
      }
      Serial.println(stateTimer);
      stateTimer++;
      Serial.println(stateTimer);
      if (stateTimer >= 500){
         directionState = backward;
      }
      break;
      
    case backward:
      if (isNewState) {
        go_backward(120);
        stateTimer = 0;
        Serial.println(F("new State is BACKWARD"));
      }
      Serial.println(stateTimer);
      stateTimer++;
      if (stateTimer >= 500){
         directionState = turn_right;
      }
      break;

    case turn_right:
      if (isNewState) {
        turn_clockwise(120);
        stateTimer = 0;
        Serial.println(F("new State is TURN RIGHT"));
      }
      Serial.println(stateTimer);
      stateTimer++;
      if (stateTimer >= 500){
         directionState = turn_left;
      }
      break;

    case turn_left:
      if (isNewState) {
        turn_counterclockwise(120);
        stateTimer = 0;
        Serial.println(F("new State is TURN LEFT"));
      }
      Serial.println(stateTimer);
      stateTimer++;
      if (stateTimer >= 500){
         directionState = stopped;
      }
      break;
    case stopped:
      Serial.println(isNewState);
      if (isNewState) {
        stop(0);
        stateTimer = 0;
        Serial.println(F("new State is STOPPED"));
      }
      stateTimer++;
      Serial.println(stateTimer);
      if (stateTimer >= 500){
         directionState = forward;
      }
      break;

      default: directionState = forward;
  }
  delay(10);
  //delay(10 - (millis() - timeStampStartOfLoopMs));
}

void configureTimer0RegisterForPWMtoDriveMotor() {
  TCCR0A |= 0xA3; //0b10100011 7, 5, 1, and 0 are high
  TCCR0A &= 0xAF; //0b10101111 4 and 6 go low
  TCCR0B &= 0xF7; //0b11110111 3 is low
  OCR0A = 120;
  OCR0B = 120;
  DDRB |= 0x07; //set PD0-2 as outputs
  DDRD |= 0xE0; //set PB5-7 as outputs
  PORTB &= 0xFA; //set PB0 and PB2 low
  PORTB |= 0x02; //set PB1 high
  PORTD |= 0x80; //set PD7 high
}

//===================================================================
void go_backward(int rate) {
  PORTD &= 0x7F; 
  PORTB |= 0x03;
  PORTB &= 0xFB;
  OCR0A = rate;
  OCR0B = rate;
  display_color_on_RGB_led(0x1F1F1F); //white
}

void go_forward(int rate) {
  PORTD |= 0x80;
  PORTB |= 0x04;
  PORTB &= 0xFC;
  OCR0A = rate;
  OCR0B = rate;
  display_color_on_RGB_led(0x00001F); //green
}

void turn_clockwise(int rate) {
  PORTD &= 0x7F; 
  PORTB |= 0x01;
  PORTB &= 0xFD;
  PORTB |= 0x04;
  OCR0A = rate;
  OCR0B = rate;
  display_color_on_RGB_led(0x001F1F); //green + blue
}

void turn_counterclockwise(int rate) {
  PORTD |= 0x80;
  PORTB &= 0xFA;
  PORTB |= 0x02;
  OCR0A = rate;
  OCR0B = rate;
  display_color_on_RGB_led(0x1F1F00); //red + blue
}

void stop(int rate) {
  OCR0A = rate;
  OCR0B = rate;
  display_color_on_RGB_led(0x1F0000); //red
}

//====================================================
// void display_color_on_RGB_led(unsigned long color) {
//  unsigned long bitmask=0UL; // UL unsigned long literal (forces compiler to use long data type)
//  unsigned long masked_color_result=0UL;
//  
//    PORTB &= 0xF7; //start with clock low.
//  
//  for(int i=23; i>=0; i--) { // clock out one data bit at a time, starting with the MSB first
//    bitmask= (1UL<<i);    // build bit mask. Note must use "1UL" unsigned long literal, not "1"
//    masked_color_result = color & bitmask; // reveals just one bit of color at time
//    boolean data_bit=!(masked_color_result==0); // this is the bit of data to be clocked out.
//    if (data_bit==1) {
//    PORTB |= 0x10;
//    }
//    else PORTB &= 0xEF;
//    PORTB |= 0x08;
//    PORTB &= 0xF7; 
//  }
//    PORTB |= 0x08;  
//  delay(1); // after writing data to LED driver, must hold clock line  
//            // high for 1 ms to latch color data in led shift register.
//}//display_color_on_RGB_led()

void display_color_on_RGB_led(unsigned long color) {
  unsigned long bitmask=0UL; // UL unsigned long literal (forces compiler to use long data type)
  unsigned long masked_color_result=0UL;
  
  digitalWrite(LED_CLOCK_PIN,LOW); //start with clock low.
  
  for(int i=23; i>=0; i--) { // clock out one data bit at a time, starting with the MSB first
    bitmask= (1UL<<i);    // build bit mask. Note must use "1UL" unsigned long literal, not "1"
    masked_color_result = color & bitmask; // reveals just one bit of color at time
    boolean data_bit=!(masked_color_result==0); // this is the bit of data to be clocked out.
    digitalWrite(LED_DATA_PIN,data_bit);
    digitalWrite(LED_CLOCK_PIN,HIGH);  
    digitalWrite(LED_CLOCK_PIN,LOW);  
  }
  digitalWrite(LED_CLOCK_PIN,HIGH);  
  delay(1); // after writing data to LED driver, must hold clock line  
            // high for 1 ms to latch color data in led shift register.
}//display_color_on_RGB_led()
