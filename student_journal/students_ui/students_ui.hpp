#ifndef STUDENTS_UI_HPP
#define STUDENTS_UI_HPP

#include "../students_list/students_list.hpp"

class StudentsUI {
public:
  StudentsUI(const StudentsList &list) : list_(list) {};
  
  void run();
  void display_list();
  void display_actions();
  void handle_action();
  void on_add();
  void on_delete();

private:
  const StudentsList &list_;
  int current_page_;
  int students_per_page_;
};

#endif