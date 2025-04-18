const byte LEFT1 = 8; //IN1
const byte LEFT2 = 9; //IN2
const byte LEFT_PWM = 10;
//右馬達控制設定
const byte RIGHT1 = 7; //IN3
const byte RIGHT2 = 6; //IN4
const byte RIGHT_PWM = 5;
//設定PWM輸出值(代表的是車子的速度)
byte rightspeed = 60;
byte leftspeed = 60;
byte motorspeed = 50;

void backward(){
  digitalWrite(LEFT1, HIGH);
  digitalWrite(LEFT2, LOW);
  analogWrite(LEFT_PWM, leftspeed);
  //右輪·因在小車上馬達安装方向左右兩個是相
  digitalWrite(RIGHT1, LOW);
  digitalWrite (RIGHT2, HIGH);
  analogWrite(RIGHT_PWM, rightspeed);
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
  analogWrite(RIGHT_PWM, 90);
  digitalWrite(RIGHT1, HIGH);
  digitalWrite (RIGHT2, LOW);
}

void turnright(){//右轉
  //右輪不動,左輪動(速度為0)
  analogWrite(LEFT_PWM, leftspeed);
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
  Serial.begin(9600);


  pinMode(4,INPUT); //右側红外線威測器
  pinMode(11,INPUT);//中間红外線威測器
  pinMode(12,INPUT);//左側红外線威測器
}
void loop() {

  Serial.print("右"); Serial.println(digitalRead(4));
  Serial.print("左"); Serial.println(digitalRead(12));
  Serial.print("中"); Serial.println(digitalRead(11));
  delay(2000);

  //0-> 非黑線 1-> 黑線
  // 空-> 111

  //正直走 010
  if((digitalRead(12)==0 && digitalRead(11)==1 && digitalRead(4)==0) || (digitalRead(12)==1 && digitalRead(11)==0 && digitalRead(4)==1)){
    forward();
    delay(100);
  }
  //小左轉 011
  else if(digitalRead(12)==0 && digitalRead(11)==1 && digitalRead(4)==1){
    turnleft();
    delay(10);
  }
  //大左轉 100
  else if(digitalRead(12)==1 && digitalRead(11)==0 && digitalRead(4)==0){
    turnleft();
    delay(50);
  }
  //小右轉 110
  else if(digitalRead(12)==1 && digitalRead(11)==1 && digitalRead(4)==0){
    turnright();
    delay(10);
  }
  //大右轉 001
  else if(digitalRead(12)==0 && digitalRead(11)==0 && digitalRead(4)==1){
    turnright();
    delay(50);
  }
  //停下 000
  else if(digitalRead(12)==0 && digitalRead(11)==0 && digitalRead(4)==0){
    stopMotor();
    delay(2000);
  }
}