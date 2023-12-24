#include "Company.hpp"
#include "Program.hpp"
#include "Storage.hpp"
#include "Tram.hpp"
#include "TramPark.hpp"
#include <Windows.h>

Company *comp = NULL;
Storage file("text.txt");

int getNumber() {
  int number;

  std::cin >> number;
  while (!std::cin || number < 0) {
    std::cout << "Введено некорректное число, повторите: ";
    std::cin.clear();
    std::cin.ignore(100500, '\n');
    std::cin >> number;
  }
  std::cin.ignore(100500, '\n');
  return (number);
}

int getMode() {
  int number;

  std::cin >> number;
  while (!std::cin || (number != 0 && number != 1)) {
    std::cout << "Введено некорректное число, повторите: ";
    std::cin.clear();
    std::cin.ignore(100500, '\n');
    std::cin >> number;
  }
  std::cin.ignore(100500, '\n');
  return (number);
}

void Add() {
  int number, mode = 0;
  std::cout << "Введите номер Трампаркa: ";
  number = getNumber();
  if (!comp->isTramParkListEmpty()) {
    std::cout << "Проход по списку прямой(0)/обратный(1):";
    mode = getMode();
  }
  if (comp->isTramParkListEmpty()) {
    if (comp->addTramPark(number))
      std::cout << "Добавление успешно!\n";
  } else if (!comp->findTramPark(mode, number)) {
    std::cout << "Добавить до(0)/после(1):";
    int pos = getMode();
    std::cout << "Введите около какого элемента добавить? ";
    int target = getNumber();
    if (pos == 1 ? comp->addTramParkAfter(mode, target, number)
                 : comp->addTramParkBefore(mode, target, number)) {
      std::cout << "Добавление успешно!\n";
    } else
      std::cout << "не добавлено!\n";
  } else
    std::cout << "Такой трампарк уже есть в списке!";
}

void AddL() {
  int number, number1, mode;
  std::cout << "Введите номер Трампарка: ";
  number = getNumber();
  std::cout << "Проход по списку прямой(0)/обратный(1):";
  mode = getMode();

  TramPark *tramParkToFind = comp->findTramPark(mode, number);
  if (tramParkToFind != nullptr) {

    if (tramParkToFind->isFull()) {
      std::cout << "Достигнут лимит массива" << std::endl;
    } else {
      std::cout << "Введите год : ";
      number1 = getNumber();
      std::string mark;
      std::cout << "Введите марку : ";
      std::getline(std::cin, mark);
      if (mark.length() == 0) {
        std::cout << "Плохие данные" << std::endl;
      } else {
        if (tramParkToFind->findTram(mark, number1) == nullptr) {
          bool res = tramParkToFind->addTram(mark, number1);
          if (res) {
            std::cout << "Трамвай добавлен!\n";
          } else {
            std::cout << "Трамвай не добавлен!\n";
          }
        } else
          std::cout << "Такой трамвай уже есть в списке!\n";
      }
    }
  } else
    std::cout << "Такого отдела нет!\n";
}

void Del() {
  int number, mode;
  std::cout << "Введите номер трампарка: ";
  number = getNumber();
  std::cout << "Проход по списку прямой(0)/обратный(1):";
  mode = getMode();
  if (comp->delTramPark(mode, number))
    std::cout << "Удаление успешно!\n";
  else
    std::cout << "Не удалено!\n";
}

void DelL() {
  int number, numberL, mode;
  std::string brand;
  std::cout << "Введите номер Трампарка, в котором требуется удалить Трамвай ";
  number = getNumber();
  std::cout << "Проход по списку прямой(0)/обратный(1):";
  mode = getMode();

  TramPark *tramParkToFind = comp->findTramPark(mode, number);
  if (tramParkToFind != nullptr) {
    if (!tramParkToFind->isEmpty()) {
      std::cout << "Удаление успешно!\n";
      tramParkToFind->delTram();
    } else {
      std::cout << "Нет записей.\n";
    }
  } else
    std::cout << "Такого трампарка нет!\n";
}

void Find() {
  int number, mode;
  std::cout << "Введите номер Трампарка: ";
  number = getNumber();
  std::cout << "Проход по списку прямой(0)/обратный(1):";
  mode = getMode();
  if (comp->findTramPark(mode, number))
    std::cout << "Трампарк найден!\n";
  else
    std::cout << "Трампарк не найден!";
}

void FindL() {
  int number, mode, number1;
  std::cout << "Введите номер Трампарка: ";
  number = getNumber();
  std::cout << "Проход по списку прямой(0)/обратный(1):";
  mode = getMode();
  if (comp->findTramPark(mode, number)) {
    std::string brand;
    std::cout << "Трампарк найден!\n";
    std::cout << "Введите марку травмая, который требуется найти: ";
    std::getline(std::cin, brand);
    std::cout << "Введите год травмая, который требуется найти: ";
    int numberL = getNumber();
    if (comp->findTramPark(mode, number)->findTram(brand, numberL)) {
      std::cout << "Трамвай найден!" << std::endl;
    } else {
      std::cout << "Трамвай не найден!" << std::endl;
    }
  } else
    std::cout << "Трампарк не найден!" << std::endl;
  ;
}

void Show() {
  {
    int mode;
    std::cout << "\nПроход по списку прямой(0)/обратный(1):";
    mode = getMode();
    system("cls");
    std::cout << "\n----------------------------------------------------\n";
    std::cout << "|        Горэлектротранс'" << comp->getName() << "'";
    std::cout << "\n----------------------------------------------------";
    std::cout << "\n|     Номер     |"
              << "         Марка     |      Год          ";
    std::cout << "\n|      депо     |"
              << "                   |\n";
    comp->show(mode);
    std::cout << "----------------------------------------------------\n";
  }
}

int main() {
  SetConsoleCP(65001);
  SetConsoleOutputCP(65001); // данные функции для установки консоли в режим работы с кодировкой UTF-8
  int n;
  comp = new Company();
  while (true) {
    Show();
    std::cout << "\n Выберите действие:\n";
    std::cout << " 1. Добавить Трампарк\n";
    std::cout << " 2. Добавить Трамвай\n";
    std::cout << " 3. Удалить Трампарк\n";
    std::cout << " 4. Удалить Трамвай\n";
    std::cout << " 5. Найти Трампарк\n";
    std::cout << " 6. Найти Трамвай\n";
    std::cout << " 7. Переименовать компанию\n";
    std::cout << " 8. Удалить и создать пустую компанию\n";
    std::cout << " 9. Загрузить из файла\n";
    std::cout << " 10. Выгрузить в файл\n";
    std::cout << " 0. Выход\n";
    n = getNumber();
    if (n == 1)
      Add();
    else if (n == 2)
      AddL();
    else if (n == 3)
      Del();
    else if (n == 4)
      DelL();
    else if (n == 5)
      Find();
    else if (n == 6)
      FindL();
    else if (n == 7) {
      std::string newName;
      std::cout << "Введите название компании: ";
      std::cin >> newName;
      comp->setName(newName);
    } else if (n == 8) {
      delete (comp);
      comp = new Company();
    } else if (n == 9) {
      delete (comp);
      comp = new Company();
      if (file.InputData(comp))
        std::cout << "Загрузка успешна!";
      else {
        std::cout << "Ошибка!";
        delete (comp);
        comp = new Company();
      }
    } else if (n == 10) {
      if (comp != NULL) {
        if (file.OutputData(comp, 0))
          std::cout << "Выгрузка успешна!";
        else
          std::cout << "Ошибка";
      } else
        std::cout << "Ошибка!";
    } else if (n == 0) {
      delete (comp);
      break;
    }
  }
}
