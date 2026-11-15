#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>
#include <vector>

class Student {
public:
  Student(std::string name, std::vector<int> grades);

  float get_average_grade() const;
  int get_bad_grades_count() const;
  int get_max_grade() const;
  int get_min_grade() const;

  int get_id() const;
  const std::string &get_name() const;
  const std::vector<int> &get_grades() const;

private:
  static int next_id;
  std::string name_;
  int id_;
  std::vector<int> grades_;
};

#endif