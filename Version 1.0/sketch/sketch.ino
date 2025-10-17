#define BUZZER 22
#define D_GAS 16
#define A_GAS 4
#define A3_LLAMA 32
#define D1_LLAMA 13
#define D2_LLAMA 14
#define D3_LLAMA 26
#define D4_LLAMA 25
#define D5_LLAMA 33

int selector=0;
int a_llama;
int a_gas;

void setup() {

  pinMode(BUZZER, OUTPUT); 
  pinMode(D_GAS, INPUT);  
  pinMode(A_GAS, INPUT);  
  pinMode(A3_LLAMA, INPUT); 
  pinMode(D1_LLAMA, INPUT);
  pinMode(D2_LLAMA, INPUT);
  pinMode(D3_LLAMA, INPUT);
  pinMode(D4_LLAMA, INPUT);
  pinMode(D5_LLAMA, INPUT);

  Serial.begin(115200);

  attachInterrupt(digitalPinToInterrupt(D_GAS), ISR_interrupcion, FALLING);
  attachInterrupt(digitalPinToInterrupt(D1_LLAMA), ISR_interrupcion, RISING);
  attachInterrupt(digitalPinToInterrupt(D2_LLAMA), ISR_interrupcion, RISING);
  attachInterrupt(digitalPinToInterrupt(D3_LLAMA), ISR_interrupcion, RISING);
  attachInterrupt(digitalPinToInterrupt(D4_LLAMA), ISR_interrupcion, RISING);
  attachInterrupt(digitalPinToInterrupt(D5_LLAMA), ISR_interrupcion, RISING);  

}

void loop() {
  
  digitalRead(D1_LLAMA);    //Lectura digital
  digitalRead(D2_LLAMA);    //Lectura digital
  digitalRead(D3_LLAMA);    //Lectura digital
  digitalRead(D4_LLAMA);    //Lectura digital
  digitalRead(D5_LLAMA);    //Lectura digital (LLAMA)

  a_llama=analogRead(A3_LLAMA);     //Lectura analogica (LLAMA)

  a_gas=analogRead(A_GAS);        //Lectura digital (GAS)
  digitalRead(D_GAS);       //Lectura analogica (GAS)

  if(selector==1) {         //Si en las entradas se detecta un 1
    Serial.print(a_llama);
    Serial.print("  |  ");
    Serial.println(a_gas);

    sonido_buzzer();

  }

}

void ISR_interrupcion() {
  selector=1;

}

void sonido_buzzer() {

  tone(BUZZER, 2000, 1000);
  noTone(BUZZER);
}
