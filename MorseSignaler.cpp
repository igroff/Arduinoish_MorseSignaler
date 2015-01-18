#include "MorseSignaler.h"

#ifdef OUTPUT_CONSOLE
  #ifdef ARDUINO
    #error console handling should not be generated for arduino
  #endif
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

void MorseSignaler::zero(){ dash(); elementPause(); dash(); elementPause(); dash(); elementPause(); dash(); elementPause(); dash(); }
void MorseSignaler::one(){ dot(); elementPause(); dash(); elementPause(); dash(); elementPause(); dash(); elementPause(); dash(); }
void MorseSignaler::two(){ dot(); elementPause(); dot(); elementPause(); dash(); elementPause(); dash(); elementPause(); dash(); }
void MorseSignaler::three(){ dot(); elementPause(); dot(); elementPause(); dot(); elementPause(); dash(); elementPause(); dash(); }
void MorseSignaler::four(){ dot(); elementPause(); dot(); elementPause(); dot(); elementPause(); dot(); elementPause(); dash(); }
void MorseSignaler::five(){ dot(); elementPause(); dot(); elementPause(); dot(); elementPause(); dot(); elementPause(); dot(); }
void MorseSignaler::six(){ dash(); elementPause(); dot(); elementPause(); dot(); elementPause(); dot(); elementPause(); dot(); }
void MorseSignaler::seven(){ dash(); elementPause(); dash(); elementPause(); dot(); elementPause(); dot(); elementPause(); dot(); }
void MorseSignaler::eight(){ dash(); elementPause(); dash(); elementPause(); dash(); elementPause(); dot(); elementPause(); dot(); }
void MorseSignaler::nine(){ dash(); elementPause(); dash(); elementPause(); dash(); elementPause(); dash(); elementPause(); dot(); }

void MorseSignaler::a() { dot(); elementPause(); dash(); }
void MorseSignaler::b() { dash(); elementPause(); dot(); elementPause(); dot(); elementPause(); dot(); }
void MorseSignaler::c() { dash(); elementPause(); dot(); elementPause(); dash(); elementPause(); dot(); }
void MorseSignaler::d() { dash(); elementPause(); dot(); elementPause(); dot(); }
void MorseSignaler::e() { dot(); }
void MorseSignaler::f() { dot(); elementPause(); dot(); elementPause(); dash(); elementPause(); dot(); }
void MorseSignaler::g() { dash(); elementPause(); dash(); elementPause(); dot(); }
void MorseSignaler::h() { dot(); elementPause(); dot(); elementPause(); dot(); elementPause(); dot(); }
void MorseSignaler::i() { dot(); elementPause(); dot(); }
void MorseSignaler::j() { dot(); elementPause(); dash(); elementPause(); dash(); elementPause(); dash(); }
void MorseSignaler::k() { dash(); elementPause(); dot(); elementPause(); dash(); }
void MorseSignaler::l() { dot(); elementPause(); dash(); elementPause(); dot(); elementPause(); dot(); }
void MorseSignaler::m() { dash(); elementPause(); dash(); }
void MorseSignaler::n() { dash(); elementPause(); dot(); }
void MorseSignaler::o() { dash(); elementPause(); dash(); elementPause(); dash(); }
void MorseSignaler::p() { dot(); elementPause(); dash(); elementPause(); dash(); elementPause(); dot(); }
void MorseSignaler::q() { dash(); elementPause(); dash(); elementPause(); dot(); elementPause(); dash(); }
void MorseSignaler::r() { dot(); elementPause(); dash(); elementPause(); dot(); }
void MorseSignaler::s() { dot(); elementPause(); dot(); elementPause(); dot(); }
void MorseSignaler::t() { dash(); }
void MorseSignaler::u() { dot(); elementPause(); dot(); elementPause(); dash(); }
void MorseSignaler::v() { dot(); elementPause(); dot(); elementPause(); dot(); elementPause(); dash(); }
void MorseSignaler::w() { dot(); elementPause(); dash(); elementPause(); dash(); }
void MorseSignaler::x() { dash(); elementPause(); dot(); elementPause(); dot(); elementPause(); dash(); }
void MorseSignaler::y() { dash(); elementPause(); dot(); elementPause(); dash(); elementPause(); dash(); }
void MorseSignaler::z() { dash(); elementPause(); dash(); elementPause(); dot(); elementPause(); dot(); }

MorseSignaler::MorseSignaler(int outputPin): outputPin(outputPin){
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
}

int MorseSignaler::signal(char chars[]){
  void (MorseSignaler::*fp)();
  // for each character in the stirng
  for (int i = 0; ; i++){
    // get ordinal value of the character
    int ordv = chars[i]; 
    if (ordv == 0) {
      break;
    }
#ifdef OUTPUT_CONSOLE
    printf("%c:%d", chars[i], ordv);
#endif
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
      alphabetIndex = ordv - 48;
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

#ifdef OUTPUT_CONSOLE
#ifdef ARDUINO
  #error we shouldn't be generating console stuff for tharduino
#endif
int main(int argc, char** argv){
  if (argc != 2){
    printf("\t\tYou need to tell me what to encode!\n");
    return 1;
  }
  MorseSignaler m(3);
  return m.signal(argv[1]);
}
#endif
