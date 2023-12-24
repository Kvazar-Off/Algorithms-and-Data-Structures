#ifndef COMPANY_HPP_
#define COMPANY_HPP_

#include "Tram.hpp"
#include "TramPark.hpp"
#include <iostream>

class Company {
private:
  std::string name;
  TramPark *pHead;

public:
  Company();
  Company(std::string name);
  ~Company();

  bool isTramParkListEmpty();
  bool isTramParkPresent(int mode, int number);
  bool addTramPark(int number);
  bool addTramParkAfter(int mode, int target, int number);
  bool addTramParkBefore(int mode, int target, int number);
  bool delTramPark(int mode, int number);
  TramPark *findTramPark(int mode, int number);

  void show(int mode);
  std::string getString(int mode);

  std::string getName();
  void setName(std::string name);

  TramPark *getPHead();
  void setPHead(TramPark *pHead);
};

#endif
