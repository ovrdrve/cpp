#include "./student.hpp"
#include <algorithm>
#include <cstddef>
#include <stdexcept>
#include <vector>

int Student::next_id = 1;

Student::Student(std::string name, std::vector<int> grades)
    : name_(std::move(name)), grades_(std::move(grades)) {
  id_ = next_id;
  next_id++;
}

float Student::get_average_grade() const {
  float avg = 0;
  for (size_t i = 0; i < grades_.size(); i++) {
    avg += grades_[i];
  }
  return avg / grades_.size();
}

int Student::get_bad_grades_count() const {
  int matches = std::count(grades_.begin(), grades_.end(), 2);
  return matches;
}

int Student::get_max_grade() const {
  if (grades_.size() == 0) {
    throw std::runtime_error("Students has no grades");
  }

  std::vector<int>::const_iterator it =
      std::max_element(grades_.begin(), grades_.end());
  return *it;
}

int Student::get_min_grade() const {
  if (grades_.size() == 0) {
    throw std::runtime_error("Students has no grades");
  }

  std::vector<int>::const_iterator it =
      std::min_element(grades_.begin(), grades_.end());
  return *it;
}

int Student::get_id() const { return id_; }

const std::string &Student::get_name() const { return name_; }

const std::vector<int> &Student::get_grades() const { return grades_; }

// void Student::set_grades(std::vector<int> new_grades) {
//   grades_ = std::move(new_grades);
// }