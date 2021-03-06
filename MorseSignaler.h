#ifndef MORSE_SIGNALER_H
#define MORSE_SIGNALER_H

#ifndef ARDUINO
  // we'll be writing output to the console, presumably for debugging
  #define OUTPUT_CONSOLE 1
  #include <stdio.h>
#else 
  #include <Arduino.h>
#endif
#define ALPHABET_LENGTH 36

class MorseSignaler{

  public:
    MorseSignaler(int outputPin=1);
    int signal(char[]);
    void
      characterPause(),
      wordPause(),
      elementPause();
    void
      a(),b(),c(),d(),e(),f(),g(),h(),i(),j(),k(),l(),m(),n(),o(),p(),q(),r(),
      s(),t(),u(),v(),w(),x(),y(),z();
    void
      zero(), one(), two(), three(), four(), five(), six(), seven(), eight(),
      nine();


  private:
    const int outputPin;
    void
      dot(),
      dash();
    void (MorseSignaler::*alphabet[ALPHABET_LENGTH])();
  
};

#endif //MORSE_SINGALER_H
