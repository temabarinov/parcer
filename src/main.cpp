#include "iniparcer.h"

int main() {
  parcer a("/Users/artembarinov61icloud.com/Desktop/parcer/src/test.ini");
  cout << a.getDouble("Audio", "value");

  return 0;
}