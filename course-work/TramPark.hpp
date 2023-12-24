#ifndef TRAMPARK_HPP_
#define TRAMPARK_HPP_

#include "Tram.hpp"

const int MAX_SIZE = 4;

class TramPark {
private:
  int number;
  TramPark *left;
  TramPark *right;
  Tram array[MAX_SIZE];
  int top;
  int tail;
  int count;

public:
  TramPark(int number);

  bool isEmpty();
  Tram *findTram(std::string brand, int year);
  bool addTram(std::string brand, int year);
  bool delTram();
  bool isFull();

  void show(int mode);
  std::string getString();

  int getNumber();
  void setNumber(int number);

  TramPark *getLeft();
  void setLeft(TramPark *left);

  TramPark *getRight();
  void setRight(TramPark *right);
};

#endif
