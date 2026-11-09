#include "./header.hpp"
#include <iostream>
#include <string>

Battery::Battery(std::string model, int charge) : model_(std::move(model)) {
  if (charge > 100) {
    charge_ = 100;
  } else if (charge < 0) {
    charge_ = 0;
  } else {
    charge_ = charge;
  }
}

void Battery::charge(int n) {
  if (n > 100 - charge_) {
    charge_ = 100;
  } else {
    charge_ += n;
  }
}

void Battery::use(int n) {
  if (n > charge_) {
    charge_ = 0;
  } else {
    charge_ -= n;
  }
}

bool Battery::isEmpty() const { return charge_ == 0; }

int Battery::print() const { return charge_; }

int main() {
  Battery battery("model_1", 110);
  battery.charge(20);
  std::cout << "Battery charge: " << battery.print() << "\n";
  battery.use(40);
  std::cout << "Battery charge: " << battery.print() << "\n";
  std::cout << "Is battery empty? - " << (battery.isEmpty() ? "Yes" : "No") << "\n";
}