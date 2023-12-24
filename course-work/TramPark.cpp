#include "TramPark.hpp"
#include "Program.hpp"

TramPark::TramPark(int number) {
    this->number = number;
    left = nullptr;
    right = nullptr;
    top = 0;
    tail = 0;
    count = 0;
}

bool TramPark::isEmpty() {
    return count == 0;
}

Tram* TramPark::findTram(std::string brand, int year) {
    int i = top;
    do {
        if (array[i].getBrand() == brand && array[i].getYear() == year) {
            return &array[i];
        }
        i = (i + 1) % MAX_SIZE;
    } while (i != tail);
    return nullptr;
}

bool TramPark::addTram(std::string brand, int year) {
    if (count == MAX_SIZE) {
        return false;
    }

    array[tail] = Tram(brand, year);
    tail = (tail + 1) % MAX_SIZE; //используем операцию % (остаток от деления) для переноса указателя tail на начало массива, обеспечивая кольцевую структуру.
    count++;
    return true;
}

bool TramPark::delTram() {
    if (count == 0) {
        return false;
    }
    top = (top + 1) % MAX_SIZE;
    count--;
    return true;
}

void TramPark::show(int mode) {
    int i = top;
    do {
        if (array[i].getBrand() != "") {
            Tram tmp = array[i];
            if (i != top)
                std::cout << "|" << std::setw(16) << "|";
            std::cout << std::setw(13) << tmp.getBrand() << std::setw(8) << " "
                << std::setw(10) << tmp.getYear();
            if ((i + 1) % MAX_SIZE != tail)
                std::cout << std::endl;
        }
        i = (i + 1) % MAX_SIZE;
    } while (i != tail);
}

std::string TramPark::getString() {
    int temp;
    std::string str = "";
    for (int i = top; i != tail; i = (i + 1) % MAX_SIZE) {
        if (array[i].getBrand() != "") {
            std::stringstream ss;
            temp = array[i].getYear();
            str += " ";
            ss << temp;
            str += ss.str();
            str += " ";
            str += array[i].getBrand();
        }
    }
    return str;
}

bool TramPark::isFull() {
    return count == MAX_SIZE;
}

int TramPark::getNumber() {
    return number;
}

void TramPark::setNumber(int number) {
    this->number = number;
}

TramPark* TramPark::getLeft() {
    return left;
}

void TramPark::setLeft(TramPark* left) {
    this->left = left;
}

TramPark* TramPark::getRight() {
    return right;
}

void TramPark::setRight(TramPark* right) {
    this->right = right;
}