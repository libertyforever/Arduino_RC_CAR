void setup() {
  // put your setup code here, to run once:
  remote_setup();
  motor_setup();
}

void loop() {
  // put your main code here, to run repeatedly:
  remote_loop();
  motor_loop();
}

void remote_setup(){
  Serial.begin(9600);
}

void remote_loop(){
  check_remote_input();
  distributed_remote_input();
  // 원격입력 분배
}

char remote_input;
bool remote_input_changed = false;

void check_remote_input(){
  if(Serial.available()){
    remote_input=Serial.read();
    remote_input_changed = true;
  }
}

enum{
  GOFWD = 'f',
  GOBWD = 'b',
  TURNL = 'l',
  TURNR = 'r',
  STOP = 's',
  GOFWDL = 'g',
  GOFWDR = 'i',
  GOBWDL = 'h',
  GOBWDR = 'j'  
}; /*SERIAL*/

char driving_action = STOP;
bool driving_action_changed = false;

void distributed_remote_input(){
  if(remote_input_changed){
    remote_input_changed=false;

    if(remote_input == GOFWD || remote_input == GOBWD ||
    remote_input == TURNL || remote_input == TURNR || 
    remote_input == STOP || remote_input == GOFWDL ||
    remote_input == GOFWDR || remote_input == GOBWDL ||
    remote_input == GOBWDR ){
      driving_action = remote_input;
      driving_action_changed = true;
    }
    
    
  }
}
