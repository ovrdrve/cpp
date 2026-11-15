#include "./students_list/students_list.hpp"
#include "./students_ui/students_ui.hpp"

int main() {
  StudentsList list;
  StudentsUI ui(list);

  ui.run();
  return 0;
}