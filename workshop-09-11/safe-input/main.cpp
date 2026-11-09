#include <iostream>
#include <string>

int main() {
  std::string name;
  std::string course_name;
  int class_number;
  int counter = 0;

  std::cout << "Enter your name\n";
  while (counter < 3) {
    std::getline(std::cin, name);
    counter++;
    if (!name.empty()) {
      break;
    }
  }
  counter = 0;

  std::cout << "Enter course name\n";
  while (counter < 3) {
    std::getline(std::cin, course_name);
    counter++;
    if (!course_name.empty()) {
      break;
    }
  }
  counter = 0;

  std::cout << "Enter number of classes (1-40)\n";
  while (counter < 3) {
    counter++;
    if (!(std::cin >> class_number)) {
      std::cout << "Error, enter a number (1-40)\n";
      std::cin.clear();
      std::cin.ignore(1000, '\n');
    } else if (class_number > 0 && class_number <= 40) {
      std::cout << "Success\n";
      break;
    }
  }

  std::cout << "Name: " << name << "\n";
  std::cout << "Course name: " << course_name << "\n";
  std::cout << "Number of classes: " << class_number << "\n";
}
