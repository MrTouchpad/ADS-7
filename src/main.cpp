// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

Train::~Train() {
  if (!first) return;
  Car *cur = first;
  Car *nxt = cur->next;
  while (nxt != first) {
    Car *tmp = nxt->next;
    delete cur;
    cur = nxt;
    nxt = tmp;
  }
  delete cur;
  first = nullptr;
}

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
  Car *cur = first->next;
  int len = 1;
  while (cur != first) {
    countOp++;
    if (!cur->light)
      cur->light = true;
    len++;
    cur = cur->next;
  }
  first->light = startWasOn;
  return len;
}

int Train::getOpCount() {
  return countOp;
}
