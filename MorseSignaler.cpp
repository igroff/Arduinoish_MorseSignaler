#include <stdio.h>
#include <string.h>
#include "MorseSignaler.h"

#ifdef OUTPUT_CONSOLE
// the basis for timings in morse code is the length of the dot
void MorseSignaler::dot(){ printf("."); }
// dash length is 3x dot length
void MorseSignaler::dash(){ printf("-"); }
// pause between elements is equal to the dot length
void MorseSignaler::elementPause() { printf(" "); }
// pause between words is 7x dot length
void MorseSignaler::wordPause() { printf("|"); }
// pause between characters is 3x dot length
void MorseSignaler::characterPause() { printf("   "); }
#else
#define DOT_LENGTH 250
void MorseSignaler::dot(){
  digitalWrite(outputPin, HIGH);
  delay(DOT_LENGTH);
  digitalWrite(outputPin, LOW);  
}
void MorseSignaler::dash(){
  digitalWrite(outputPin, HIGH);
  delay(DOT_LENGTH * 3);
  digitalWrite(outputPin, LOW);
}
void MorseSignaler::characterPause(){ delay(DOT_LENGTH * 3); }
void MorseSignaler::elementPause(){ delay(DOT_LENGTH); }
void MorseSignaler::wordPause(){ delay(DOT_LENGTH * 7); }
#endif

void (*fp)();
void MorseSignaler::zero(){ this->dash(); this->elementPause(); this->dash(); this->elementPause(); this->dash(); this->elementPause(); this->dash(); this->elementPause(); this->dash(); }
void MorseSignaler::one(){ this->dot(); this->elementPause(); this->dash(); this->elementPause(); this->dash(); this->elementPause(); this->dash(); this->elementPause(); this->dash(); }
void MorseSignaler::two(){ this->dot(); this->elementPause(); this->dot(); this->elementPause(); this->dash(); this->elementPause(); this->dash(); this->elementPause(); this->dash(); }
void MorseSignaler::three(){ this->dot(); this->elementPause(); this->dot(); this->elementPause(); this->dot(); this->elementPause(); this->dash(); this->elementPause(); this->dash(); }
void MorseSignaler::four(){ this->dot(); this->elementPause(); this->dot(); this->elementPause(); this->dot(); this->elementPause(); this->dot(); this->elementPause(); this->dash(); }
void MorseSignaler::five(){ this->dot(); this->elementPause(); this->dot(); this->elementPause(); this->dot(); this->elementPause(); this->dot(); this->elementPause(); this->dot(); }
void MorseSignaler::six(){ this->dash(); this->elementPause(); this->dot(); this->elementPause(); this->dot(); this->elementPause(); this->dot(); this->elementPause(); this->dot(); }
void MorseSignaler::seven(){ this->dash(); this->elementPause(); this->dash(); this->elementPause(); this->dot(); this->elementPause(); this->dot(); this->elementPause(); this->dot(); }
void MorseSignaler::eight(){ this->dash(); this->elementPause(); this->dash(); this->elementPause(); this->dash(); this->elementPause(); this->dot(); this->elementPause(); this->dot(); }
void MorseSignaler::nine(){ this->dash(); this->elementPause(); this->dash(); this->elementPause(); this->dash(); this->elementPause(); this->dash(); this->elementPause(); this->dot(); }

void MorseSignaler::a() { this->dot(); this->elementPause(); this->dash(); }
void MorseSignaler::b() { this->dash(); this->elementPause(); this->dot(); this->elementPause(); this->dot(); this->elementPause(); this->dot(); }
void MorseSignaler::c() { this->dash(); this->elementPause(); this->dot(); this->elementPause(); this->dash(); this->elementPause(); this->dot(); }
void MorseSignaler::d() { this->dash(); this->elementPause(); this->dot(); this->elementPause(); this->dot(); }
void MorseSignaler::e() { this->dot(); }
void MorseSignaler::f() { this->dot(); this->elementPause(); this->dot(); this->elementPause(); this->dash(); this->elementPause(); this->dot(); }
void MorseSignaler::g() { this->dash(); this->elementPause(); this->dash(); this->elementPause(); this->dot(); }
void MorseSignaler::h() { this->dot(); this->elementPause(); this->dot(); this->elementPause(); this->dot(); this->elementPause(); this->dot(); }
void MorseSignaler::i() { this->dot(); this->elementPause(); this->dot(); }
void MorseSignaler::j() { this->dot(); this->elementPause(); this->dash(); this->elementPause(); this->dash(); this->elementPause(); this->dash(); }
void MorseSignaler::k() { this->dash(); this->elementPause(); this->dot(); this->elementPause(); this->dash(); }
void MorseSignaler::l() { this->dot(); this->elementPause(); this->dash(); this->elementPause(); this->dot(); this->elementPause(); this->dot(); }
void MorseSignaler::m() { this->dash(); this->elementPause(); this->dash(); }
void MorseSignaler::n() { this->dash(); this->elementPause(); this->dot(); }
void MorseSignaler::o() { this->dash(); this->elementPause(); this->dash(); this->elementPause(); this->dash(); }
void MorseSignaler::p() { this->dot(); this->elementPause(); this->dash(); this->elementPause(); this->dash(); this->elementPause(); this->dot(); }
void MorseSignaler::q() { this->dash(); this->elementPause(); this->dash(); this->elementPause(); this->dot(); this->elementPause(); this->dash(); }
void MorseSignaler::r() { this->dot(); this->elementPause(); this->dash(); this->elementPause(); this->dot(); }
void MorseSignaler::s() { this->dot(); this->elementPause(); this->dot(); this->elementPause(); this->dot(); }
void MorseSignaler::t() { this->dash(); }
void MorseSignaler::u() { this->dot(); this->elementPause(); this->dot(); this->elementPause(); this->dash(); }
void MorseSignaler::v() { this->dot(); this->elementPause(); this->dot(); this->elementPause(); this->dot(); this->elementPause(); this->dash(); }
void MorseSignaler::w() { this->dot(); this->elementPause(); this->dash(); this->elementPause(); this->dash(); }
void MorseSignaler::x() { this->dash(); this->elementPause(); this->dot(); this->elementPause(); this->dot(); this->elementPause(); this->dash(); }
void MorseSignaler::y() { this->dash(); this->elementPause(); this->dot(); this->elementPause(); this->dash(); this->elementPause(); this->dash(); }
void MorseSignaler::z() { this->dash(); this->elementPause(); this->dash(); this->elementPause(); this->dot(); this->elementPause(); this->dot(); }

MorseSignaler::MorseSignaler(uint8_t outputPin): outputPin(outputPin){
  alphabet[0] = &MorseSignaler::zero; 
  alphabet[1] = &MorseSignaler::one; 
  alphabet[2] = &MorseSignaler::two; 
  alphabet[3] = &MorseSignaler::three; 
  alphabet[4] = &MorseSignaler::four; 
  alphabet[5] = &MorseSignaler::five; 
  alphabet[6] = &MorseSignaler::six; 
  alphabet[7] = &MorseSignaler::seven; 
  alphabet[8] = &MorseSignaler::eight; 
  alphabet[9] = &MorseSignaler::nine; 

  alphabet[10] = &MorseSignaler::a; 
  alphabet[11] = &MorseSignaler::b; 
  alphabet[12] = &MorseSignaler::c; 
  alphabet[13] = &MorseSignaler::d; 
  alphabet[14] = &MorseSignaler::e; 
  alphabet[15] = &MorseSignaler::f; 
  alphabet[16] = &MorseSignaler::g; 
  alphabet[17] = &MorseSignaler::h; 
  alphabet[18] = &MorseSignaler::i; 
  alphabet[19] = &MorseSignaler::j; 
  alphabet[20] = &MorseSignaler::k; 
  alphabet[21] = &MorseSignaler::l; 
  alphabet[22] = &MorseSignaler::m; 
  alphabet[23] = &MorseSignaler::n; 
  alphabet[24] = &MorseSignaler::o; 
  alphabet[25] = &MorseSignaler::p; 
  alphabet[26] = &MorseSignaler::q; 
  alphabet[27] = &MorseSignaler::r; 
  alphabet[28] = &MorseSignaler::s; 
  alphabet[29] = &MorseSignaler::t; 
  alphabet[30] = &MorseSignaler::u; 
  alphabet[31] = &MorseSignaler::v; 
  alphabet[32] = &MorseSignaler::w; 
  alphabet[33] = &MorseSignaler::x; 
  alphabet[34] = &MorseSignaler::y; 
  alphabet[35] = &MorseSignaler::z; 
  printf("outputpin: %d\n", outputPin);
}

int MorseSignaler::signal(char chars[]){
  void (MorseSignaler::*fp)();
  // for each character in the stirng
  for (int i = 0; i < strlen(chars); i++){
    // get ordinal value of the character
    int ordv = chars[i]; 
    // this will be used to store our index into the alphabet
    int alphabetIndex = -1;
    // convert the ordinal value into an alphabet array index
    // or the appropriate output (spaces and EOL's are handled directly)
    if ((ordv == 10) || (ordv == 13)){
      // morse code doesn't have the concept of EOL, so skip 'em
      continue;
    } else if (ordv == 32){
      // if it's a space we issue a word pause and then move on
      wordPause();
      continue;
    } else if (ordv >= 97){
      // case sensitive, lower case only, if it's greater than 97 
      // we have an alpha character
      // since our alphabet starts with numeric values we'll skip those
      // by subtracting 10 less than the ordinal value of a
      alphabetIndex = ordv - 87;
    } else {
      // else we assume it's a numeric character
      alphabetIndex = ordv - 49;
    }
    // blow chunks if we got something out of bounds
    if ((alphabetIndex < 0) || (alphabetIndex > ALPHABET_LENGTH)){
      return 1;
    }
    // fetch our function pointer for the index calculated
    fp = this->alphabet[alphabetIndex];
    // if we've reached this location, and we're not at the very begining
    // of our string, then we've already output a character and thus
    // will output a character pause
    characterPause();
    // execute!
    (this->*fp)();  
  }
  return 0;
}

int main(int argc, char** argv){
  MorseSignaler m(3);
  m.signal("pants");
}
