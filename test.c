#include <stdio.h>
#include <string.h>

#ifdef Arduino_h
#define DOT_LENGTH 250
void dot(){
  digitalWrite(PIN1_LED, HIGH);
  delay(DOT_LENGTH);
  digitalWrite(PIN1_LED, LOW);  
}
void dash(){
  digitalWrite(PIN1_LED, HIGH);
  delay(DOT_LENGTH * 3);
  digitalWrite(PIN1_LED, LOW);
}
void characterPause(){ delay(DOT_LENGTH * 3); }
void elementPause(){ delay(DOT_LENGTH); }
void wordPause(){ delay(DOT_LENGTH * 7); }
#endif 

#ifndef Arduino_h
// the basis for timings in morse code is the length of the dot
void dot(){ printf("."); }
// dash length is 3x dot length
void dash(){ printf("-"); }
// pause between elements is equal to the dot length
void elementPause() { printf(" "); }
// pause between words is 7x dot length
void wordPause() { printf("|"); }
// pause between characters is 3x dot length
void characterPause() { printf("   "); }
#endif

void (*fp)();
void a() { dot(); elementPause(); dash(); }
void b() { dash(); elementPause(); dot(); elementPause(); dot(); elementPause(); dot(); }
void c() { dash(); elementPause(); dot(); elementPause(); dash(); elementPause(); dot(); }
void d() { dash(); elementPause(); dot(); elementPause(); dot(); }
void e() { dot(); }
void f() { dot(); elementPause(); dot(); elementPause(); dash(); elementPause(); dot(); }
void g() { dash(); elementPause(); dash(); elementPause(); dot(); }
void h() { dot(); elementPause(); dot(); elementPause(); dot(); elementPause(); dot(); }
void i() { dot(); elementPause(); dot(); }
void j() { dot(); elementPause(); dash(); elementPause(); dash(); elementPause(); dash(); }
void k() { dash(); elementPause(); dot(); elementPause(); dash(); }
void l() { dot(); elementPause(); dash(); elementPause(); dot(); elementPause(); dot(); }
void m() { dash(); elementPause(); dash(); }
void n() { dash(); elementPause(); dot(); }
void o() { dash(); elementPause(); dash(); elementPause(); dash(); }
void p() { dot(); elementPause(); dash(); elementPause(); dash(); elementPause(); dot(); }
void q() { dash(); elementPause(); dash(); elementPause(); dot(); elementPause(); dash(); }
void r() { dot(); elementPause(); dash(); elementPause(); dot(); }
void s() { dot(); elementPause(); dot(); elementPause(); dot(); }
void t() { dash(); }
void u() { dot(); elementPause(); dot(); elementPause(); dash(); }
void v() { dot(); elementPause(); dot(); elementPause(); dot(); elementPause(); dash(); }
void w() { dot(); elementPause(); dash(); elementPause(); dash(); }
void x() { dash(); elementPause(); dot(); elementPause(); dot(); elementPause(); dash(); }
void y() { dash(); elementPause(); dot(); elementPause(); dash(); elementPause(); dash(); }
void z() { dash(); elementPause(); dash(); elementPause(); dot(); elementPause(); dot(); }

void one(){ dot(); elementPause(); dash(); elementPause(); dash(); elementPause(); dash(); elementPause(); dash(); }
void two(){ dot(); elementPause(); dot(); elementPause(); dash(); elementPause(); dash(); elementPause(); dash(); }
void three(){ dot(); elementPause(); dot(); elementPause(); dot(); elementPause(); dash(); elementPause(); dash(); }
void four(){ dot(); elementPause(); dot(); elementPause(); dot(); elementPause(); dot(); elementPause(); dash(); }
void five(){ dot(); elementPause(); dot(); elementPause(); dot(); elementPause(); dot(); elementPause(); dot(); }
void six(){ dash(); elementPause(); dot(); elementPause(); dot(); elementPause(); dot(); elementPause(); dot(); }
void seven(){ dash(); elementPause(); dash(); elementPause(); dot(); elementPause(); dot(); elementPause(); dot(); }
void eight(){ dash(); elementPause(); dash(); elementPause(); dash(); elementPause(); dot(); elementPause(); dot(); }
void nine(){ dash(); elementPause(); dash(); elementPause(); dash(); elementPause(); dash(); elementPause(); dot(); }
void zero(){ dash(); elementPause(); dash(); elementPause(); dash(); elementPause(); dash(); elementPause(); dash(); }

#define ALPHABET_LENGTH 36
void (*alphabet[ALPHABET_LENGTH])() = {
  &zero, &one, &two, &three, &four, &five, &six, &seven, &eight, &nine// numbers
  // alpha characters
  ,&a, &b, &c, &d, &e, &f, &g, &h, &i, &j, &k, &l, &m, &n, &o, &p
  ,&q, &r, &s, &t, &u, &v, &w, &x, &y, &z
};

int morseCodeFor(char chars[]){
  void (*fp)();
  // for each character in the stirng
  for (int i = 0; i < strlen(chars); i++){
    // get ordinal value of the character
    int ordv = chars[i]; 
    printf("%c:%d", chars[i], chars[i]);
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
    fp = alphabet[alphabetIndex];
    // if we've reached this location, and we're not at the very begining
    // of our string, then we've already output a character and thus
    // will output a character pause
    characterPause();
    // execute!
    fp();  
  }
  return 0;
}
int main(int argc, char** argv){
  return morseCodeFor("word");
}
