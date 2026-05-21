// Copyright 2022 NNTU-CS
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "train.h"

static int runTrain(int n, bool lightOn) {
  Train t;
  for (int i = 0; i < n; ++i)
    t.addCar(lightOn);
  t.getLength();
  return t.getOpCount();
}

static int runTrainRandom(int n) {
  Train t;
  for (int i = 0; i < n; ++i)
    t.addCar(rand() % 2 == 0);
  t.getLength();
  return t.getOpCount();
}

int main() {
  {
    Train train;
    int count = 60;
    while (count--)
      train.addCar(false);
    std::cout << train.getLength() << std::endl;
    std::cout << train.getOpCount() << std::endl;
  }
  srand(static_cast<unsigned>(time(nullptr)));
  const int N_MIN = 2;
  const int N_MAX = 500;
  const int STEP = 2;
  const int TRIALS = 10;
  std::ofstream csv("result/experiment.csv");
  csv << "n,ops_off,ops_on,ops_rand\n";
  for (int n = N_MIN; n <= N_MAX; n += STEP) {
    int opsOff = runTrain(n, false);
    int opsOn = runTrain(n, true);
    long long sumRand = 0;
    for (int t = 0; t < TRIALS; ++t)
      sumRand += runTrainRandom(n);
    int opsRand = static_cast<int>(sumRand / TRIALS);
    csv << n << "," << opsOff << "," << opsOn << "," << opsRand << "\n";
  }
  csv.close();
  return 0;
}
