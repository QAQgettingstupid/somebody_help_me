const byte LEFT1 = 8; //IN1
const byte LEFT2 = 9; //IN2
const byte LEFT_PWM = 10;
//右馬達控制設定
const byte RIGHT1 = 7; //IN3
const byte RIGHT2 = 6; //IN4
const byte RIGHT_PWM = 5;
//設定PWM輸出值(代表的是車子的速度)
byte rightspeed = 120;
byte leftspeed = 100;
byte motorspeed = 100;

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

  pinMode(13,INPUT); //右側红外線威測器
  pinMode(12,INPUT);//左側红外線威測器
}
void loop() {
  Serial.println(digitalRead(12));
  if(digitalRead(12)==1){
    forward();
    delay(2000);
  }
  else{
    stopMotor();
    delay(9000);
  }
}