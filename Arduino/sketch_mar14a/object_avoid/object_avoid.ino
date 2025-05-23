const byte LEFT1 = 8; //IN1
const byte LEFT2 = 9; //IN2
const byte LEFT_PWM = 10;
//右馬達控制設定
const byte RIGHT1 = 7; //IN3
const byte RIGHT2 = 6; //IN4
const byte RIGHT_PWM = 5;
//設定PWM輸出值(代表的是車子的速度)
byte rightspeed = 150;
byte leftspeed = 150;
byte motorspeed = 90;
bool front = false;

//超音波
const byte trigPin = 2; //觸發
const int echoPin = 3; //接收
unsigned long int d;

unsigned long int ping(){
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  return pulseIn(echoPin, HIGH, 23200);
}

void backward(){
  digitalWrite(LEFT1, HIGH);
  digitalWrite(LEFT2, LOW);
  analogWrite(LEFT_PWM, leftspeed-40);
  //右輪·因在小車上馬達安装方向左右兩個是相
  digitalWrite(RIGHT1, LOW);
  digitalWrite (RIGHT2, HIGH);
  analogWrite(RIGHT_PWM, rightspeed-40);
}

void forward(){ //
  digitalWrite(LEFT1, LOW);
  digitalWrite (LEFT2, HIGH);
  analogWrite(LEFT_PWM, leftspeed);
  digitalWrite(RIGHT1, HIGH);
  digitalWrite(RIGHT2, LOW);
  analogWrite(RIGHT_PWM, rightspeed);
}

void turnleft(){//左轉
  //左輪不動,右輪動(速度為0)
  analogWrite(LEFT_PWM, 0);
  analogWrite(RIGHT_PWM, motorspeed);
  digitalWrite(RIGHT1, HIGH);
  digitalWrite (RIGHT2, LOW);

}
void bigturnleft(){//大左轉
  //左輪不動,右輪動(速度為0)
  analogWrite(LEFT_PWM, 0);
  analogWrite(RIGHT_PWM, motorspeed+20);
  digitalWrite(RIGHT1, HIGH);
  digitalWrite (RIGHT2, LOW);
}

void turnright(){//右轉
  //右輪不動,左輪動(速度為0)
  analogWrite(LEFT_PWM, motorspeed);
  analogWrite(RIGHT_PWM, 0);
  digitalWrite(LEFT1, LOW);
  digitalWrite(LEFT2, HIGH);
}

void bigturnright(){//大右轉
  //右輪不動,左輪動(速度為0)
  analogWrite(LEFT_PWM, motorspeed+20);
  analogWrite(RIGHT_PWM, 0);
  digitalWrite(LEFT1, LOW);
  digitalWrite(LEFT2, HIGH);
}
void stopMotor() {
  analogWrite(LEFT_PWM, 0);
  analogWrite(RIGHT_PWM, 0);
}

void setup(){ 
  //設定每一個PIN的模式
  pinMode(LEFT1, OUTPUT);
  pinMode(LEFT2, OUTPUT);
  pinMode(LEFT_PWM, OUTPUT);
  pinMode(RIGHT1, OUTPUT);
  pinMode(RIGHT2, OUTPUT);
  pinMode(RIGHT_PWM, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);


  pinMode(4,INPUT); //中間红外線威測器
  pinMode(11,INPUT);//右側红外線威測器
  pinMode(12,INPUT);//左側红外線威測器
}
void loop() {

  //Serial.print("right"); Serial.println(digitalRead(11));
  //Serial.print("left"); Serial.println(digitalRead(12));
  //Serial.print("middle"); Serial.println(digitalRead(4));

  
  d = ping() / 58;

  Serial.println(String("") + d + " cm");
  delay(100);

  //避障

  if(d && d<=40){

    bigturnright();
    delay(280);

    stopMotor();
    delay(1000);

    forward();
    delay(300);
    
    stopMotor();
    delay(1000);

    bigturnleft();
    delay(600);

    stopMotor();
    delay(1000);
    Serial.println("hi");
    
    while(!(digitalRead(12) + digitalRead(4) + digitalRead(11))){
      forward();
      delay(300);
      stopMotor();
      delay(1000);
      Serial.println("here");
    }
    
  }
  else{
    forward();
    delay(300);
  }
  //0-> 非黑線 1-> 黑線
  // 空->

  /*

  //正直走 010 111 101 
  if((digitalRead(12)==0 && digitalRead(4)==1 && digitalRead(11)==0) || (digitalRead(12)==1 && digitalRead(4)==1 && digitalRead(11)==1) || (digitalRead(12)==1 && digitalRead(4)==0 && digitalRead(11)==1)){
    forward();
    front = true;
  }
  //小右轉 011
  if(digitalRead(12)==0 && digitalRead(4)==1 && digitalRead(11)==1){
    turnright();
    front = false;
  }
  //大左轉 100
  if(digitalRead(12)==1 && digitalRead(4)==0 && digitalRead(11)==0 ){
    bigturnleft();
    front = false;
  }
  //小左轉 110
  if(digitalRead(12)==1 && digitalRead(4)==1 && digitalRead(11)==0){
    turnleft();
    front = false;
  }
  //大右轉 001
  if(digitalRead(12)==0 && digitalRead(4)==0 && digitalRead(11)==1){
    bigturnright();
    front = false;
  }
  //停下 000
  if(digitalRead(12)==0 && digitalRead(4)==0 && digitalRead(11)==0){
    if(front){
      delay(80);
      while(digitalRead(12)==0 && digitalRead(4)==0 && digitalRead(11)==0){
        backward();
      }
      front = false;
    }
    else
      backward();
  }

  */
}