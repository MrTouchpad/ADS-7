// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

void Train::addCar(bool light) {
  Car *car = new Car{light, nullptr, nullptr};
  if (!first) {
    car->next = car;
    car->prev = car;
    first = car;
  } else {
    Car *last = first->prev;
    last->next = car;
    car->prev = last;
    car->next = first;
    first->prev = car;
  }
}

int Train::getLength() {
  if (!first) return 0;
  countOp = 0;
  bool startWasOn = first->light;
  first->light = false;
  Car *cur = first;
  int len = 1;
  while (cur->next != first) {
    countOp++;
    cur = cur->next;
    if (!cur->light)
      cur->light = true;
    len++;
  }
  cur = first;
  while (cur->next->light) {
    countOp++;
    cur = cur->next;
  }
  first->light = startWasOn;
  return len;
}

int Train::getOpCount() {
  return countOp;
}
