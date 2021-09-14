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
  } else if(driving_action == GOFWDL){
    go_fwd_l();
  } else if(driving_action == GOFWDR){
    go_fwd_r();
  } else if(driving_action == GOBWDL){
    go_bwd_l();
  } else if(driving_action == GOBWDR){
    go_bwd_r();
  }
}
}

void go_fwd(){
  // FWD
  // Left FWD
  digitalWrite(DIRFL, LOW);
  analogWrite(PWMFL, 255);
  digitalWrite(DIRRL, LOW);
  analogWrite(PWMRL, 255);
  // Right FWD
  digitalWrite(DIRFR, LOW);
  analogWrite(PWMFR, 255);
  digitalWrite(DIRRR, LOW);
  analogWrite(PWMRR, 255);
}
void go_bwd(){
    // BWD
  // Left BWD
  digitalWrite(DIRFL, HIGH);
  analogWrite(PWMFL, 0);
  digitalWrite(DIRRL, HIGH);
  analogWrite(PWMRL, 0);
  // Right BWD
  digitalWrite(DIRFR, HIGH);
  analogWrite(PWMFR, 0);
  digitalWrite(DIRRR, HIGH);
  analogWrite(PWMRR, 0);
}
void turn_l(){
      // Turn Left
  // Left BWD
  digitalWrite(DIRFL, HIGH);
  analogWrite(PWMFL, 0);
  digitalWrite(DIRRL, HIGH);
  analogWrite(PWMRL, 0);
  // Right FWD
  digitalWrite(DIRFR, LOW);
  analogWrite(PWMFR, 255);
  digitalWrite(DIRRR, LOW);
  analogWrite(PWMRR, 255);
}
void turn_r(){
      // Turn Right
  // Left FWD
  digitalWrite(DIRFL, LOW);
  analogWrite(PWMFL, 255);
  digitalWrite(DIRRL, LOW);
  analogWrite(PWMRL, 255);
  // Right BWD
  digitalWrite(DIRFR, HIGH);
  analogWrite(PWMFR, 0);
  digitalWrite(DIRRR, HIGH);
  analogWrite(PWMRR, 0);
}
void stop_driving(){
      // STOP
  // Left Stop
  digitalWrite(DIRFL, LOW);
  analogWrite(PWMFL, 0);
  digitalWrite(DIRRL, LOW);
  analogWrite(PWMRL, 0);
  // Right Stop
  digitalWrite(DIRFR, LOW);
  analogWrite(PWMFR, 0);
  digitalWrite(DIRRR, LOW);
  analogWrite(PWMRR, 0);
}

void go_fwd_l(){
  // Go FWD Left
  // Left Half 
  digitalWrite(DIRFL, LOW);
  analogWrite(PWMFL, 40);
  digitalWrite(DIRRL, LOW);
  analogWrite(PWMRL, 40);
  // Right Full
  digitalWrite(DIRFR, LOW);
  analogWrite(PWMFR, 255);
  digitalWrite(DIRRR, LOW);
  analogWrite(PWMRR, 255);
}

void go_fwd_r(){
    // Go FWD Right
  // Left Full
  digitalWrite(DIRFL, LOW);
  analogWrite(PWMFL, 255);
  digitalWrite(DIRRL, LOW);
  analogWrite(PWMRL, 255);
  // Right Half
  digitalWrite(DIRFR, LOW);
  analogWrite(PWMFR, 40);
  digitalWrite(DIRRR, LOW);
  analogWrite(PWMRR, 40);
}

void go_bwd_l(){
  // Go BWD Left
  // Left Half
  digitalWrite(DIRFL, HIGH);
  analogWrite(PWMFL, 210);
  digitalWrite(DIRRL, HIGH);
  analogWrite(PWMRL, 210);
  // Right Full
  digitalWrite(DIRFR, HIGH);
  analogWrite(PWMFR, 0);
  digitalWrite(DIRRR, HIGH);
  analogWrite(PWMRR, 0);
}

void go_bwd_r(){
  // Go BWD Right
  // Left Full
  digitalWrite(DIRFL, HIGH);
  analogWrite(PWMFL, 0);
  digitalWrite(DIRRL, HIGH);
  analogWrite(PWMRL, 0);
  // Right Half
  digitalWrite(DIRFR, HIGH);
  analogWrite(PWMFR, 210);
  digitalWrite(DIRRR, HIGH);
  analogWrite(PWMRR, 210);
}
