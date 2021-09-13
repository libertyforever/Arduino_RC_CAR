//Left Wheel - go FWD BWD

const int DIRFL = 2;
const int PWMFL = 3;
const int DIRRL = 7;
const int PWMRL = 6;

//Right Wheel - go FWD BWD

const int DIRFR = 4;
const int PWMFR = 5;
const int DIRRR = 19;
const int PWMRR = 10;

void motor_setup(){
  // initialization Left Wheel
  pinMode(DIRFL, OUTPUT);
  pinMode(DIRRL, OUTPUT);

  digitalWrite(DIRFL, LOW);
  analogWrite(PWMFL, 0);
  digitalWrite(DIRRL, LOW);
  analogWrite(PWMRL, 0);

  // initialization Right Wheel
  pinMode(DIRFR, OUTPUT);
  pinMode(DIRRR, OUTPUT);

  digitalWrite(DIRFR, LOW);
  analogWrite(PWMFR, 0);
  digitalWrite(DIRRR, LOW);
  analogWrite(PWMRR, 0);
}

void motor_loop(){
  process_driving_action();
}

void process_driving_action(){
  if(driving_action_changed){
    driving_action_changed = false;

  if(driving_action == GOFWD){
    go_fwd();
  } else if(driving_action == GOBWD){
    go_bwd();
  } else if(driving_action == TURNL){
    turn_l();
  } else if(driving_action == TURNR){
    turn_r();
  } else if(driving_action == STOP){
    stop_driving();
  }
}
}
