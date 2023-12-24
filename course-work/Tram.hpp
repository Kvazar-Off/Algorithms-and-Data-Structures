#ifndef TRAM_HPP_
#define TRAM_HPP_

#include <iostream>
#include <string>

class Tram {
private:
  std::string brand;
  int year;

public:
  Tram();
  Tram(std::string brand, int year);

  std::string getBrand();
  void setBrand(std::string brand);

  int getYear();
  void setYear(int year);
};

#endif
