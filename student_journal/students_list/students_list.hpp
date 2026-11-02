#ifndef STUDENTS_LIST_HPP
#define STUDENTS_LIST_HPP

#include "../student/student.hpp"
#include <vector>

class StudentsList {
public:
  const std::vector<Student> &get_list() const;
  void add_student(const Student &student);
  void remove_student_by_id(int target_id);

private:
  std::vector<Student> students_ = {};
};

#endif