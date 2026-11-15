#ifndef STUDENTS_UI_HPP
#define STUDENTS_UI_HPP

#include "../students_list/students_list.hpp"

class StudentsUI {
public:
  StudentsUI(StudentsList &list) : list_(list) {};

  void run();

private:
  StudentsList &list_;
  int current_page_ = 0;
  int students_per_page_;

  void render_list();
  void render_menu();
  void handle_action(int action);
  void on_add();
  void on_delete();
  void on_next();
  void on_previous();
};

#endif