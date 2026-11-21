#ifndef HEADER_HPP
#define HEADER_HPP

#include <string>

class Product {
public:
  Product(std::string name, int price, int count)
      : name_(std::move(name)), price_(price), count_(count) {};

  int total() const;
  void sell(int n);
  void restock(int n);

private:
  std::string name_;
  int price_;
  int count_;
};

#endif