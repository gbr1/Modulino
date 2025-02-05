#include <Modulino.h>


char notes[] = "EE E CE G g C g e a h bagEG AFG E CDh C g e a h bagEG AFG E CDh  GJFS E taC aCD GJFS E V VV  GJFS E taC aCD U D C  GJFS E taC aCD GJFS E V VV  GJFS E taC aCD U D C ";
int beats[] = {1,1,1,1,1,1,1,1,2,2,2,2,2,1,1,2,2,1,1,1,1,1,1,2,1,1,1,1,2,1,1,1,1,1,1,1,1,2,2,1,1,2,2,1,1,1,1,1,1,2,1,1,1,1,2,1,1,1,1,1,1,1,1,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,1,1,2,2,6,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,1,1,2,2,6};
int songLength = sizeof(notes);
int tempo = 100;

ModulinoMotors motors;


void setup() {
  Modulino.begin();
  motors.begin();
  motors.setSpeed(2048,2048);   // 50% duty cycle
  playSong();
}

void loop() {
}

int frequency(char note) {  
  int i;
  const int numNotes = 19; 

  char names[] = { 'c', 'd', 'e', 'f', 'g', 't', 'a', 'b', 'h', 'C' , 'D' , 'S' , 'E', 'F' , 'J', 'G' , 'A' , 'V' , 'U'};
  int frequencies[] = {262, 294, 330, 349, 392, 415 , 440, 466 , 494, 523, 587, 622 , 659, 698, 740, 784, 880 , 1047 , 622};
  
  for (i = 0; i < numNotes; i++){
    if (names[i] == note){
      return(frequencies[i]);
    }
  }
  return(0);
}


void playSong(){
  int i, duration;
  for (i = 0; i < songLength; i++){
    duration = beats[i] * tempo;
    if (notes[i] == ' '){
      delay(duration); 
    } else {
      motors.setFrequency(frequency(notes[i]));
      delay(duration);
    }
    delay(tempo/10);
  }
}