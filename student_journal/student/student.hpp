#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>
#include <vector>

class Student {
public:
  std::string name;

  Student(std::string name, std::vector<int> grades);

  float get_average_grade();
  int get_bad_grades_count();
  int get_max();
  int get_min();

  int id() const;
  const std::vector<int> &grades() const;
  void set_grades(std::vector<int>);

private:
  static int next_id;
  int id_;
  std::vector<int> grades_;
};

#endif