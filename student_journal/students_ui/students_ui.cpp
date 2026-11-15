#include "./students_ui.hpp"
#include "../student/student.hpp"
#include "../students_list/students_list.hpp"
#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <ios>
#include <iostream>
#include <limits>
#include <ostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>


namespace {
constexpr int w_number = 3;
constexpr int w_name = 31;
constexpr int w_avr_grade = 11;
constexpr int w_bad_grades_count = 9;
constexpr int w_min_grade = 7;
constexpr int w_max_grade = 7;
constexpr int w_id = 5;

constexpr int w_total = w_number + w_name + w_avr_grade + w_bad_grades_count +
                        w_min_grade + w_max_grade + w_id + 15;

} // namespace

void StudentsUI::run() {
  while (true) {
    std::system("cls");
    render_list();
    render_menu();

    std::cout << "Enter an action (1-4): ";
    int action = 0;
    if (!(std::cin >> action) || action < 1 || action > 4) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      continue;
    };

    handle_action(action);
  }
}

void StudentsUI::render_list() {
  auto print_separator = [](int width) {
    std::cout << std::string(width, '-') << '\n';
  };

  auto print_cell = [](auto align, int width, const auto &value) {
    std::cout << "| " << align << std::setw(width) << value;
  };

  // Заголовок таблицы
  print_separator(w_total);
  print_cell(std::left, w_number, "N#");
  print_cell(std::left, w_name, "Student name");
  print_cell(std::left, w_avr_grade, "Average");
  print_cell(std::left, w_bad_grades_count, "Retakes");
  print_cell(std::left, w_min_grade, "Min");
  print_cell(std::left, w_max_grade, "Max");
  print_cell(std::left, w_id, "ID");
  std::cout << "|\n";
  print_separator(w_total);

  // Таблица
  if (!list_.get_list().empty()) {
    const auto &list = list_.get_list();
    int start_i = current_page_ * students_per_page_;
    int end_i =
        std::min(static_cast<int>(list.size()), start_i + students_per_page_);

    for (int i = start_i; i < end_i; ++i) {
      print_cell(std::left, w_number, std::to_string(i + 1) + '.');
      print_cell(std::left, w_name, list[i].get_name());
      print_cell(std::right, w_avr_grade, list[i].get_average_grade());
      print_cell(std::right, w_bad_grades_count,
                 list[i].get_bad_grades_count());
      print_cell(std::right, w_min_grade, list[i].get_min_grade());
      print_cell(std::right, w_max_grade, list[i].get_max_grade());
      print_cell(std::left, w_id, list[i].get_id());
      std::cout << "|\n";
      print_separator(w_total);
    }
  } else {
    std::string message = "LIST IS EMPTY";
    int left_padding = w_total / 2 - message.length() / 2;
    std::cout << std::left << std::setw(w_total - 1)
              << ("|" + std::string(left_padding, ' ')) + message << "|\n";
    print_separator(w_total);
  }
}

void StudentsUI::render_menu() {
  std::cout << '\n'
            << "1. Add student\n"
            << "2. Delete student\n"
            << "3. Previous page\n"
            << "4. Next page\n";
}

void StudentsUI::handle_action(int action) {
  std::system("cls");
  render_list();

  switch (action) {
  case 1:
    on_add();
    break;
  case 2:
    on_delete();
    break;
  case 3:
    on_previous();
    break;
  case 4:
    on_next();
    break;
  default:
    break;
  }
}

void StudentsUI::on_add() {
  // очистка после предыдущего cin перед getline
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  std::string name;
  std::vector<int> grades;

  while (true) {
    std::cout << "Enter name:\n";
    std::getline(std::cin, name);

    if (name.empty()) {
      std::cout << "Error: empty name\n";
    } else {
      break;
    }
  }

  while (true) {
    std::cout << "Enter grades (2-5) separated by space\n";
    std::string line;
    std::getline(std::cin, line);

    std::istringstream iss(line);
    std::vector<int> input_grades;
    std::string token;
    bool isValid = true;

    while (iss >> token) {
      if (token.length() == 1 && token[0] > '1' && token[0] < '6') {
        int grade = token[0] - '0';
        input_grades.push_back(grade);
      } else {
        isValid = false;
        break;
      }
    }

    if (isValid && !input_grades.empty()) {
      grades = std::move(input_grades);
      break;
    } else {
      std::cout << "Error: invalid format\n";
      input_grades.clear();
    }
  }

  Student student(name, grades);
  list_.add_student(student);
}

void StudentsUI::on_delete() {
  std::cout << "Enter student's ID to delete:\n";
  int id = 0;
  while (true) {
    if (!(std::cin >> id) || id < 1) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      continue;
    } else {
      break;
    }
  }

  list_.remove_student_by_id(id);
}

void StudentsUI::on_next() {
  if (list_.get_list().size() > (current_page_ + 1) * students_per_page_) {
    current_page_++;
  }
}

void StudentsUI::on_previous() {
  if (current_page_ > 0) {
    current_page_--;
  }
}