#include "./student.hpp"
#include <algorithm>
#include <cstddef>
#include <stdexcept>
#include <vector>

int Student::next_id = 1;

Student::Student(std::string name, std::vector<int> grades)
    : name(std::move(name)), grades_(std::move(grades)) {
  id_ = next_id;
  next_id++;
};

float Student::get_average_grade() {
  float avg = 0;
  for (size_t i = 0; i < grades_.size(); i++) {
    avg += grades_[i];
  }
  return avg / grades_.size();
};

int Student::get_bad_grades_count() {
  int matches = std::count(grades_.begin(), grades_.end(), 2);
  return matches;
};

int Student::get_max() {
  if (grades_.size() == 0) {
    throw std::runtime_error("Students has no grades");
  }

  std::vector<int>::iterator iter =
      std::max_element(grades_.begin(), grades_.end());
  return *iter;
};

int Student::get_min() {
  if (grades_.size() == 0) {
    throw std::runtime_error("Students has no grades");
  }

  std::vector<int>::iterator iter =
      std::min_element(grades_.begin(), grades_.end());
  return *iter;
};

int Student::id() const { return id_; }

const std::vector<int> &Student::grades() const { return grades_; };

void Student::set_grades(std::vector<int> new_grades) {
  grades_ = std::move(new_grades);
}