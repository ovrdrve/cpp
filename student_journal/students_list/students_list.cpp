#include "./students_list.hpp"
#include <algorithm>

const std::vector<Student> &StudentsList::get_list() const {
  return students_;
};

void StudentsList::add_student(const Student &student) {
  students_.push_back(student);
};

void StudentsList::remove_student_by_id(int target_id) {
  std::vector<Student>::iterator it = std::find_if(
      students_.begin(), students_.end(),
      [target_id](Student &student) { return target_id == student.id(); });

  if (it != students_.end()) {
    students_.erase(it);
  }
};