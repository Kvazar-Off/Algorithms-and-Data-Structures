#include "Company.hpp"
#include "Program.hpp"
#include "TramPark.hpp"

Company::Company() {
  pHead = new TramPark(-1);
  pHead->setRight(pHead);
  pHead->setLeft(pHead);
  name = "";
}

Company::Company(std::string name) {
  pHead = new TramPark(-1);
  pHead->setRight(pHead);
  pHead->setLeft(pHead);
  this->name = name;
}

Company::~Company() {
  TramPark *pPrev;
  TramPark *pCurrent;

  pCurrent = pHead->getRight();
  while (pCurrent != pHead) {
    pPrev = pCurrent;
    pCurrent = pCurrent->getRight();
    delete pPrev;
  }
  delete pHead;
}

bool Company::isTramParkListEmpty() {
  return (pHead->getRight() == pHead && pHead->getLeft() == pHead);
}

bool Company::isTramParkPresent(int mode, int number) {
  TramPark *tmp = (mode == FORWARD ? pHead->getRight() : pHead->getLeft());
  while (tmp != pHead) {
    if (tmp->getNumber() == number)
      return (true);
    tmp = (mode == FORWARD ? tmp->getRight() : tmp->getLeft());
  }
  return (false);
}

TramPark *Company::findTramPark(int mode, int number) {
  TramPark *tmp = (mode == FORWARD ? pHead->getRight() : pHead->getLeft());
  while (tmp != pHead) {
    if (tmp->getNumber() == number)
      return (tmp);
    tmp = (mode == FORWARD ? tmp->getRight() : tmp->getLeft());
  }
  return (nullptr);
}

bool Company::addTramPark(int number) {
  TramPark *pNew = new TramPark(number);
  pNew->setRight(pHead);
  pNew->setLeft(pHead->getLeft());
  pHead->getLeft()->setRight(pNew);
  pHead->setLeft(pNew);
  return (true);
}

bool Company::addTramParkBefore(int mode, int target, int number) {
  TramPark *pCurrent = (mode == FORWARD ? pHead->getRight() : pHead->getLeft());
  while (pCurrent != pHead) {
    if (pCurrent->getNumber() == target) {
      TramPark *pNew = new TramPark(number);
      pNew->setLeft(pCurrent->getLeft());
      pNew->setRight(pCurrent);
      pCurrent->getLeft()->setRight(pNew);
      pCurrent->setLeft(pNew);
      return (true);
    }
    pCurrent = (mode == FORWARD ? pCurrent->getRight() : pCurrent->getLeft());
  }
  return (false);
}

bool Company::addTramParkAfter(int mode, int target, int number) {
  TramPark *pCurrent = (mode == FORWARD ? pHead->getRight() : pHead->getLeft());
  while (pCurrent != pHead) {
    if (pCurrent->getNumber() == target) {
      TramPark *pNew = new TramPark(number);
      pNew->setRight(pCurrent->getRight());
      pNew->setLeft(pCurrent);
      pCurrent->getRight()->setLeft(pNew);
      pCurrent->setRight(pNew);
      return (true);
    }
    pCurrent = (mode == FORWARD ? pCurrent->getRight() : pCurrent->getLeft());
  }
  return (false);
}

bool Company::delTramPark(int mode, int number) {
  TramPark *pCurrent = (mode == FORWARD ? pHead->getRight() : pHead->getLeft());
  while (pCurrent != pHead) {
    if (pCurrent->getNumber() == number) {
      pCurrent->getLeft()->setRight(pCurrent->getRight());
      pCurrent->getRight()->setLeft(pCurrent->getLeft());
      delete pCurrent;
      return (true);
    }
    pCurrent = (mode == FORWARD ? pCurrent->getRight() : pCurrent->getLeft());
  }
  return (false);
}

void Company::show(int mode) {
  if (!isTramParkListEmpty()) {
    TramPark *tmp = (mode == FORWARD ? pHead->getRight() : pHead->getLeft());
    while (tmp != pHead) {
      std::cout << "----------------------------------------------------\n";
      std::cout << "|" << std::setw(8) << tmp->getNumber() << std::setw(8) // setw() используется для установки ширины поля
                << "|";
      tmp->show(0);
      std::cout << "\n";
      tmp = (mode == FORWARD ? tmp->getRight() : tmp->getLeft());
    }
  }
}

std::string Company::getString(int mode) {
  std::string str = "";
  TramPark *tmp = (mode == FORWARD ? pHead->getRight() : pHead->getLeft());
  while (tmp != pHead) {
    std::stringstream ss;
    ss << tmp->getNumber();
    str += ss.str();
    str += tmp->getString();
    str += '\n';
    tmp = mode == FORWARD ? tmp->getRight() : tmp->getLeft();
  }
  return str;
}

std::string Company::getName() { return name; }

void Company::setName(std::string name) { this->name = name; }

TramPark *Company::getPHead() { return pHead; }

void Company::setPHead(TramPark *pHead) { this->pHead = pHead; }
