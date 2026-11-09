#include <iostream>

void reserve_ref(int &tickets, int n) {
  if (n < 1 || n > tickets) {
    std::cout << "Incorrect number of seats\n";
  } else {
    tickets -= n;
  }
}

int reserve_copy(int tickets, int n) {
  if (n < 1 || n > tickets) {
    std::cout << "Incorrect number of seats\n";
    return 0;
  } else {
    return tickets -= n;
  }
}

int main() {
  int tickets_left = 30;
  int n = 0;

  std::cout << "Enter the number of seats you want to book\n";
  std::cin >> n;
  std::cout << "Reserved: " << n << "\n";
  reserve_copy(tickets_left, n);
  std::cout << "Tickets left: " << tickets_left << "\n";

  std::cout << "Enter the number of seats you want to book\n";
  std::cin >> n;
  reserve_ref(tickets_left, n);
  std::cout << "Reserved: " << n << "\n";
  std::cout << "Tickets left: " << tickets_left << "\n";
}