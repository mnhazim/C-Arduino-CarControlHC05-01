#define enA 9
#define enB 10
#define in1 2
#define in2 3
#define in3 4
#define in4 5
#define led 11
#define kipas 8

int trigPin = 12;
int echoPin = 11;
long duration;
int distance;

int t_kiri = 100;
int t_kanan = 100;


void setup() {
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  pinMode(kipas, OUTPUT);
  Serial.begin(9600);
}

void loop() {
 while(Serial.available()>0){
    Serial.println("device connected");
    char modecontrol = Serial.read();
    if(modecontrol == 'F'){
        depan(250);
    }
    
    if(modecontrol == 'B'){
        belakang(250);
    }
    
    if(modecontrol == 'L') {
        kiri(200);
    }
      
    if(modecontrol == 'R'){
        kanan(200);
    }

    if(modecontrol == 'G'){
        depan(250);
        kiri(200);
    }

    if(modecontrol == 'I'){
        depan(250);
        kanan(200);
    }

    if(modecontrol == 'H'){
        belakang(250);
        kiri(200);
    }

    if(modecontrol == 'J'){
        belakang(250);
        kanan(200);
    }
    
    if(modecontrol == 'S'){
        berhenti(0,0);
    }
    Serial.println(modecontrol);
  }

  Serial.println("device disconnected");
}

void ultrasensor(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
}
void belakang(int e_belakang){
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, e_belakang);
}

void depan(int e_belakang){

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, e_belakang);
}

void kanan(int e_depan){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, e_depan);
}

void kiri(int e_depan){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, e_depan);
}

void berhenti(int e_depan, int e_belakang){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, e_depan);

  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, e_belakang);
}
