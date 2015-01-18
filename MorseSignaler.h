#include <stdint.h>
#ifndef ARDUINO
  // we'll be writing output to the console, presumably for debugging
  #define OUTPUT_CONSOLE 1
#endif
#define ALPHABET_LENGTH 36

class MorseSignaler{

  public:
    MorseSignaler(uint8_t outputPin=1);
    int signal(char[]);
    void
      dot(),
      dash(),
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
    const uint8_t outputPin;
    void (MorseSignaler::*alphabet[ALPHABET_LENGTH])();
  
};
