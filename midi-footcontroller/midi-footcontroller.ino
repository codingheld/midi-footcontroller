//  Arduino Footcontroller for Behringer V-Amp Pro
//
//  Created by Florian Spies
//  Copyright (c) 2017 Florian Spies. All rights reserved.
//

#include <MIDI.h>
#include <Bounce2.h>

Bounce button2 = Bounce(2, 10);
Bounce button3 = Bounce(3, 10);
Bounce button4 = Bounce(4, 10);
Bounce button5 = Bounce(5, 10);
Bounce button6 = Bounce(6, 10);
Bounce button7 = Bounce(7, 10);
Bounce button8 = Bounce(8, 10);

int bank = 0;
int patch = 0;
int program = 0;
char charPatch[5] = "ABCDE";

//MIDI_CREATE_DEFAULT_INSTANCE();

void setup() {
  Serial.begin(9600);
  //MIDI.begin(MIDI_CHANNEL_OFF);

  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);

  Serial.println("Hallo, i bims de Footkontrolleur!");
  calculateProgramChange();
}

void loop() {
  button2.update();
  button3.update();
  button4.update();
  button5.update();
  button6.update();
  button7.update();
  button8.update();

 if (button2.fallingEdge()) {
    if (bank < 24) {
      bank++;
    }
    calculateProgramChange();
 }
 
 if (button3.fallingEdge()) {
  if (bank > 0) {
    bank--; 
  }
  calculateProgramChange();
 }
 
 if (button4.fallingEdge()) {
  patch = 0;
  calculateProgramChange();
 }
 
 if (button5.fallingEdge()) {
  patch = 1;
  calculateProgramChange();
 }
 
 if (button6.fallingEdge()) {
  patch = 2;
  calculateProgramChange();
 }
 
 if (button7.fallingEdge()) {
  patch = 3;
  calculateProgramChange();
 }
 
 if (button8.fallingEdge()) {
  patch = 4;
  calculateProgramChange();
 }
}

void calculateProgramChange() {
  program = 5 * bank + patch;
  //MIDI.sendProgramChange(program,1);
  Serial.print("Bank ");
  Serial.print(bank + 1);
  Serial.print(" Patch ");
  Serial.println(charPatch[patch]); 
  Serial.print("PC ");
  Serial.println(program);
  
}

