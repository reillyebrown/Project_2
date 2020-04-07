//initialize colors 
int RedLED = 12;  
int GreenLED = 27;  
int BlueLED = 33; 

int prevMill = 0;
int interval = 10;

 
int sensorPin = A1; //sensor
int sensorValue = 0; 
int delaytime = 100; 
int lastButtonState = 0;
int buttonPin = A0; 
int buttonCounter = 0; // counter for the number of button presses
int buttonState = 0;       // current state of the button
int buttonPushCounter = 0;   // previous state of the button

int buttonCheck = 0;

int state =1; 
int redState = 1;
int greenState =2;
int blueState =3;


 
void setup(){ 
  
  //initialize the LED pin as outputs
  pinMode(RedLED, OUTPUT);
  pinMode(GreenLED, OUTPUT);
  pinMode(BlueLED, OUTPUT);
  
  
  pinMode(buttonPin, INPUT); // initialize the button pin 
  pinMode(sensorPin, INPUT); // initialize the sensor pin 
  
  //initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  
}
 
void loop(){

  
  
  int sensorValue = analogRead(sensorPin); //read input on analog pin 0

  if (sensorValue<500) {
    buttonCheck = 5;
  }else if (sensorValue>500) {
    buttonCheck = 0;
  }
  
  buttonState = digitalRead(buttonPin);
  
  // compare the buttonState to its previous state
  if (buttonState !=lastButtonState) {
    
    // if the state has changed, increment the counter
    
    if (buttonState == HIGH) {
     // if the current state is HIGH then the sensor went from off to on:

     if (buttonCheck == 0) {
    
    buttonPushCounter++; 
    Serial.println("on"); 
    Serial.print("number of button presses: ");
    Serial.println(buttonPushCounter);
    buttonCheck = 1; 
     }
    
   } else {
      
      Serial.println("off");
      buttonCheck = 0;
    }
    }
    
  // save the current state as the last state, for next time through the loop
  lastButtonState = buttonState;
  
    Serial.print("buttonCounter: ");
    Serial.println(buttonCounter);
    


     if (buttonPushCounter == 0) {
     
   
     Red();
     
    } else if (buttonPushCounter == 1) {
  
    Green();
   
    }else if (buttonPushCounter == 2) {
    
   Blue();
   
  } else if (buttonPushCounter == 3) {
   
    buttonPushCounter = 0; 
    
  } else if (buttonPushCounter == 4) {
    
    Off();
  }
}

  

 //Red

   void Red(){
       digitalWrite(GreenLED, LOW);
       digitalWrite(BlueLED, LOW);
       digitalWrite(RedLED, HIGH);
    
   }

//Green

     void Green(){

      digitalWrite(RedLED, LOW);
      digitalWrite(BlueLED, LOW);
      digitalWrite(GreenLED, HIGH);
      
   }

//Blue

     void Blue(){

      digitalWrite(RedLED, LOW);
      digitalWrite(GreenLED, LOW);
      digitalWrite(BlueLED, HIGH);
      
    
   }


   //Off

     void Off(){

      digitalWrite(RedLED, LOW);
      digitalWrite(GreenLED, LOW);
      digitalWrite(BlueLED, LOW);
      
    
   }


 //Alternating
   
//     void Alternating(){
//      int currentMillis = millis();
//
//        if ((currentMillis - prevMill) > interval ) 
//       {
//        state++; 
//
//        if (state == 4) {
//
//          state = 1;
//        }
//       }
//
//       if (state == redState) {
//
//        Red();
//       }
//
//        else if (state == greenState) {
//
//        Green();
//       }
//
//        else if (state == blueState) {
//
//        Blue();
//        }
//    
//   }
//    
//    
//   
//    
//
//  
//  
//  
