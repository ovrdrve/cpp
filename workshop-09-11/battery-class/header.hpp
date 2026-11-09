#ifndef HEADER_HPP
#define HEADER_HPP

#include <string>
class Battery {
public:
  Battery(std::string model, int charge);

  void charge(int n);
  void use(int n);
  bool isEmpty() const;
  int print() const;

private:
  std::string model_;
  int charge_;
};

#endif