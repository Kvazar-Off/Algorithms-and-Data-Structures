#define _CRT_SECURE_NO_WARNINGS
#ifndef STORAGE_HPP
#define STORAGE_HPP

#include "Company.hpp"
#include "Program.hpp"

class Storage {
private:
  std::string address;

public:
  Storage(std::string address);
  bool InputData(Company *_comp);
  bool OutputData(Company *_comp, int mode);
  ~Storage();
};

#endif
