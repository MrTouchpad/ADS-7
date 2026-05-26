// Copyright 2022 NNTU-CS
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "train.h"
int main() {
  Train train;
  int count = 60;
  std::srand(time(nullptr));
  while (count--)
    train.addCar(false);
  std::cout << "n\tfalse\t\ttrue\t\trndom\n";
  for (int n = 2; n <= 100; n++) {
    int opFalse;
    int opTrue;
    int opRandom;
    {
      Train t;
      for (int i = 0; i < n; i++)
        t.addCar(false);
      t.getLength();
      opFalse = t.getOpCount();
    }
    {
      Train t;
      for (int i = 0; i < n; i++)
        t.addCar(true);
      t.getLength();
      opTrue = t.getOpCount();
    }
    {
      Train t;
      for (int i = 0; i < n; i++)
        t.addCar(std::rand() % 2);
      t.getLength();
      opRandom = t.getOpCount();
    }
    std::cout << n << "\t" << opFalse << "\t\t" << opTrue << "\t\t"
              << opRandom << "\n";
  }
  std::cout << train.getLength() << std::endl;
  std::cout << train.getOpCount() << std::endl;
  return 0;
}
