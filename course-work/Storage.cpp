#include "Storage.hpp"
#include "Program.hpp"

Storage::Storage(std::string address) { this->address = address; };

bool Storage::InputData(Company *comp) {
  std::string name, fuel;
  int number, number1;
  char buffer[100];
  char *f;

  std::ifstream file(address); //поток для чтения

  if (!file.is_open())
    return false;
  file.getline(buffer, 100); // Извлекает строки из входного потока, последовательно по одной строке.
  if (buffer != " ") {
    name = buffer;
    comp->setName(name);
  } else {
    std::cout << "error" << std::endl;
    return false;
  }
  while (!file.eof()) { //eof возвращает значение 1, если текущая позиция является концом файла, или 0, если это не так
    file.getline(buffer, 100);
    f = strtok(buffer, " ");
    if (f == NULL)
      continue;
    number = atoi(f);
    comp->addTramPark(number);
    while (f) {
      f = strtok(NULL, " "); // идет разбиение строки на токены с использованием разделителя " "
      if (!f) {
        break;
      }
      number1 = atoi(f); // с помощью atoi() преобразуется токен f в целое число и сохраняется в переменную number
      f = strtok(NULL, " ");
      fuel = f; // получение марки трамвая
      comp->findTramPark(0, number)->addTram(fuel, number1);
    }
  }
  file.close();
  return true;
}

bool Storage::OutputData(Company *comp, int mode) {
  std::ofstream file(address); // поток для вывода
  if (!file.is_open())
    return false;
  file << comp->getName() + '\n' + comp->getString(mode);
  file.close();
  return true;
}

Storage::~Storage(){};
