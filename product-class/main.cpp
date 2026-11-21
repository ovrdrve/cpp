#include "header.hpp"
#include <iostream>
#include <string>

int Product::total() const { return price_ * count_; }

void Product::sell(int n) {
  if (n <= count_ && n > 0) {
    count_ -= n;
    std::cout << "Success sale\n"
              << count_ << " left\n"
              << count_ * price_ << " cost\n";
  } else {
    std::cout << "Error: cannot sell\n";
  }
}

void Product::restock(int n) {
  if (n > 0) {
    count_ += n;
    std::cout << "Success restock\n";
  } else {
    std::cout << "Error: cannot restock\n";
  }
}

int main() {
  Product product_1("Продукт 1", 1200, 12);

  product_1.sell(7);
  product_1.total();
  product_1.sell(6);
  product_1.restock(2);
  product_1.sell(6);
}