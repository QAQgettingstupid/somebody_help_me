const byte LEFT1 = 8;  //IN1
const byte LEFT2 = 9;  //IN2
const byte LEFT_PWM = 10;
//右馬達控制設定
const byte RIGHT1 = 7;  //IN3
const byte RIGHT2 = 6;  //IN4
const byte RIGHT_PWM = 5;
//設定PWM輸出值(代表的是車子的速度)
byte rightspeed = 100;
byte leftspeed = 100;
byte motorspeed = 80;
bool status = 0;  //1->小右轉,2->大右轉,3->小左轉,4->大左轉,5->直走 (數字指上一動)

//超音波
const byte trigPin = 2;  //觸發
const int echoPin = 3;   //接收
unsigned long int d;

unsigned long int ping() {
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  return pulseIn(echoPin, HIGH, 23200);
}

void backward() {
  digitalWrite(LEFT1, HIGH);
  digitalWrite(LEFT2, LOW);
  analogWrite(LEFT_PWM, leftspeed);
  //右輪·因在小車上馬達安装方向左右兩個是相
  digitalWrite(RIGHT1, LOW);
  digitalWrite(RIGHT2, HIGH);
  analogWrite(RIGHT_PWM, rightspeed);
}

void forward() {  //
  digitalWrite(LEFT1, LOW);
  digitalWrite(LEFT2, HIGH);
  analogWrite(LEFT_PWM, leftspeed);
  digitalWrite(RIGHT1, HIGH);
  digitalWrite(RIGHT2, LOW);
  analogWrite(RIGHT_PWM, rightspeed);
  status = 5;
}

void turnleft() {  //左轉
  //左輪不動,右輪動(速度為0)
  analogWrite(LEFT_PWM, 0);
  analogWrite(RIGHT_PWM, motorspeed);
  digitalWrite(RIGHT1, HIGH);
  digitalWrite(RIGHT2, LOW);
  status = 3;
}
void bigturnleft() {  //大左轉
  //左輪不動,右輪動(速度為0)
  analogWrite(LEFT_PWM, 0);
  analogWrite(RIGHT_PWM, motorspeed + 20);
  digitalWrite(RIGHT1, HIGH);
  digitalWrite(RIGHT2, LOW);
  status = 4;
}

void turnright() {  //右轉
  //右輪不動,左輪動(速度為0)
  analogWrite(LEFT_PWM, motorspeed);
  analogWrite(RIGHT_PWM, 0);
  digitalWrite(LEFT1, LOW);
  digitalWrite(LEFT2, HIGH);
}

void bigturnright() {  //大右轉
  //右輪不動,左輪動(速度為0)
  analogWrite(LEFT_PWM, motorspeed + 20);
  analogWrite(RIGHT_PWM, 0);
  digitalWrite(LEFT1, LOW);
  digitalWrite(LEFT2, HIGH);
  status = 2;
}
void stopMotor() {
  analogWrite(LEFT_PWM, 0);
  analogWrite(RIGHT_PWM, 0);
}

void setup() {
  //設定每一個PIN的模式
  pinMode(LEFT1, OUTPUT);
  pinMode(LEFT2, OUTPUT);
  pinMode(LEFT_PWM, OUTPUT);
  pinMode(RIGHT1, OUTPUT);
  pinMode(RIGHT2, OUTPUT);
  pinMode(RIGHT_PWM, OUTPUT);
  Serial.begin(9600);


  pinMode(4, INPUT);   //中間红外線威測器
  pinMode(11, INPUT);  //右側红外線威測器
  pinMode(12, INPUT);  //左側红外線威測器
}
void loop() {

  //Serial.print("left"); Serial.println(digitalRead(12));
  //Serial.print("middle"); Serial.println(digitalRead(4));
  //Serial.print("right"); Serial.println(digitalRead(11));
  Serial.print(digitalRead(12));
  Serial.print(digitalRead(4));
  Serial.println(digitalRead(11));

  d = ping() / 58;

  Serial.println(String("") + d + " cm");

  if (d >= 1 && d <= 40) {

    stopMotor();
    delay(700);

    if (d >= 1 && d <= 25) {
      Serial.println("why?????????");
      backward();
      delay(1200);
    }

    stopMotor();
    delay(1000);

    bigturnright();
    delay(300);

    stopMotor();
    delay(1000);

    forward();
    delay(700);

    stopMotor();
    delay(1000);

    bigturnleft();
    delay(700);

    stopMotor();
    delay(1000);

    while (!(digitalRead(12) + digitalRead(4) + digitalRead(11))) {
      forward();
    }
  }

  //0-> 非黑線 1-> 黑線
  // 空->
  //小右轉 011
  if (digitalRead(12) == 0 && digitalRead(4) == 1 && digitalRead(11) == 1) {
    turnright();
    status = 1;
    return;
  }
  //大左轉 100
  if (digitalRead(12) == 1 && digitalRead(4) == 0 && digitalRead(11) == 0) {
    bigturnleft();
    return;
  }
  //小左轉 110
  if (digitalRead(12) == 1 && digitalRead(4) == 1 && digitalRead(11) == 0) {
    turnleft();
    return;
  }
  //大右轉 001
  if (digitalRead(12) == 0 && digitalRead(4) == 0 && digitalRead(11) == 1) {
    bigturnright();
    return;
  }
  //正直走 010 111 101
  if ((digitalRead(12) == 0 && digitalRead(4) == 1 && digitalRead(11) == 0) || (digitalRead(12) == 1 && digitalRead(4) == 1 && digitalRead(11) == 1) || (digitalRead(12) == 1 && digitalRead(4) == 0 && digitalRead(11) == 1)) {
    forward();
  }


  //停下 000
  if (status && (digitalRead(12) == 0 && digitalRead(4) == 0 && digitalRead(11) == 0)) {
    switch (status) {
      case 1:
        turnleft();
        break;

      case 2:
        bigturnleft();
        break;

      case 3:
        turnright();
        break;

      case 4:
        bigturnright();
        break;
      default:
        while ((digitalRead(12) == 0 && digitalRead(4) == 0 && digitalRead(11) == 0))
          forward();
        break;
    }
  }
}