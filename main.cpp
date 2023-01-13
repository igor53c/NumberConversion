#include <iostream>

using namespace std;

char getChar(uint8_t number) {
  char c = number + (number < 10 ? 48 : 55);

  return c;
}

std::string toBin(uint32_t decimalNumber) {
  std::string retValue = "";
  uint8_t numberOfRepetitions = 32;

  while (numberOfRepetitions--) {
    retValue = ((decimalNumber & 1) == 1 ? "1" : "0") + retValue;

    decimalNumber = decimalNumber >> 1;

    if (decimalNumber == 0) break;
  }

  return retValue;
}

std::string toHex(uint32_t decimalNumber) {
  std::string retValue = "";
  uint8_t numberOfRepetitions = 8;

  while (numberOfRepetitions--) {
    retValue = getChar(decimalNumber & 0xF) + retValue;

    decimalNumber = decimalNumber >> 4;

    if (decimalNumber == 0) break;
  }

  return retValue;
}

std::string toBase(uint32_t decimalNumber, uint32_t base) {
  std::string retValue = "";

  if (base < 2 || base > 32) return retValue;

  while (true) {
    if (decimalNumber < base) {
      retValue = getChar(decimalNumber) + retValue;

      break;
    } else {
      uint32_t lastDecimalNumber = decimalNumber;

      decimalNumber /= base;

      retValue = getChar(lastDecimalNumber - decimalNumber * base) + retValue;
    }
  }

  return retValue;
}

int main() {
  cout << "toBin: " << toBin(15) << endl;
  cout << "toHex: " << toHex(43981) << endl;
  cout << "toHex: " << toBase(89122, 23) << endl;

  return 0;
}
