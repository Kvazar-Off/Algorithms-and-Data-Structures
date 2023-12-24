#include "Storage.hpp"
#include "Program.hpp"

Storage::Storage(std::string address) { this->address = address; };

bool Storage::InputData(Company *comp) {
  std::string name, fuel;
  int number, number1;
  char buffer[100];
  char *f;

  std::ifstream file(address); //����� ��� ������

  if (!file.is_open())
    return false;
  file.getline(buffer, 100); // ��������� ������ �� �������� ������, ��������������� �� ����� ������.
  if (buffer != " ") {
    name = buffer;
    comp->setName(name);
  } else {
    std::cout << "error" << std::endl;
    return false;
  }
  while (!file.eof()) { //eof ���������� �������� 1, ���� ������� ������� �������� ������ �����, ��� 0, ���� ��� �� ���
    file.getline(buffer, 100);
    f = strtok(buffer, " ");
    if (f == NULL)
      continue;
    number = atoi(f);
    comp->addTramPark(number);
    while (f) {
      f = strtok(NULL, " "); // ���� ��������� ������ �� ������ � �������������� ����������� " "
      if (!f) {
        break;
      }
      number1 = atoi(f); // � ������� atoi() ������������� ����� f � ����� ����� � ����������� � ���������� number
      f = strtok(NULL, " ");
      fuel = f; // ��������� ����� �������
      comp->findTramPark(0, number)->addTram(fuel, number1);
    }
  }
  file.close();
  return true;
}

bool Storage::OutputData(Company *comp, int mode) {
  std::ofstream file(address); // ����� ��� ������
  if (!file.is_open())
    return false;
  file << comp->getName() + '\n' + comp->getString(mode);
  file.close();
  return true;
}

Storage::~Storage(){};
