unsigned long time;
//Initialising the dc motor inputs
int speedPin =5;
int dir1 =4;
int dir2 =3;
int mSpeed;

void setup() {
  Serial.begin(9600);
  pinMode(speedPin,OUTPUT);
  pinMode(dir1,OUTPUT);
  pinMode(dir2,OUTPUT);
  
}

void loop() {
  //Converted into minutes
  time = micros()/60000000;

  Serial.println(time); //prints time since program started
  delay(1000);          // wait a second so as not to send massive amounts of data
//Delays calculated based on the angle of the figurine with respect to the original position of Expression 1 figurine (Happy figurine)
//Expression 1: Happy eyes figurine 
  if(time >= 0 || time <= 10){
    //Healthy Screen Time
    mSpeed = 74;
    digitalWrite(dir1, LOW);
    digitalWrite(dir2, HIGH);
    analogWrite(speedPin, 200);
    delay(100);
    analogWrite(speedPin, mSpeed); 
     delay(5000);
    }
//Expression 2: Strained eyes
    else if(time >=11 || time <= 16){
    mSpeed = 117;
    digitalWrite(dir1, LOW);
    digitalWrite(dir2, HIGH);
    analogWrite(speedPin, 255);
    delay(30);
    analogWrite(speedPin, mSpeed); 
     delay(5000);  
    }
//Expression 3: Baggy Eyes
    else if(time >=17 || time <= 24){
    mSpeed = 140;
    digitalWrite(dir1, LOW);
    digitalWrite(dir2, HIGH);
    analogWrite(speedPin, 255);
    delay(300);
    analogWrite(speedPin, mSpeed); 
    delay(5000);  
    }
//Expression 4: Tired Eyes
     else if(time >=25 || time <= 30){
    mSpeed = 156;
    digitalWrite(dir1, LOW);
    digitalWrite(dir2, HIGH);
    analogWrite(speedPin, 255);
    delay(100);
    analogWrite(speedPin, mSpeed); 
    delay(5000);  
    }
    //Expression 5: Red eyes figurine, Reached the screemtime limit and exceeding it by 5 mins (warning)
     else if(time >=30 || time <= 35){
    mSpeed = 160;
    digitalWrite(dir1, LOW);
    digitalWrite(dir2, HIGH);
    analogWrite(speedPin, 255);
    delay(100);
    analogWrite(speedPin, mSpeed); 
    delay(5000);  
    }
//Exceeded screen time > than 5 mins over the limit rotate 2 mins
else if(time >=36 || time <= 37){
    mSpeed = 255;
    analogWrite(speedPin, mSpeed); 
    delay(5000);  
    }
    else{
      mSpeed = 0;
      analogWrite(speedPin, mSpeed); 
      delay(5000);  
      }
    
}
