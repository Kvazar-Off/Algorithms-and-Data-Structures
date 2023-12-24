#include "Tram.hpp"

Tram::Tram() {
  this->brand = "";
  this->year = 0;
}

Tram::Tram(std::string brand, int year) {
  this->brand = brand;
  this->year = year;
}

std::string Tram::getBrand() { return brand; }

void Tram::setBrand(const std::string brand) { this->brand = brand; }

int Tram::getYear() { return year; }

void Tram::setYear(int year) { this->year = year; }
