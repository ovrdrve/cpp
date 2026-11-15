#include "./student/student.hpp"
#include "./students_list/students_list.hpp"
#include "./students_ui/students_ui.hpp"
#include <vector>

namespace {
std::vector<Student> create_mock_data() {
  return {Student("Ivan Ivanov", {5, 4, 5, 5}),
          Student("Anna Petrova", {5, 5, 5, 4, 5, 5}),
          Student("Alexey Sidorov", {3, 4, 3, 2, 4}),
          Student("Maria Smirnova", {4, 5, 4, 4, 5, 3, 4}),
          Student("Dmitry Kuznetsov", {2, 3, 2}),
          Student("Elena Popova", {5, 5, 4, 5, 5}),
          Student("Sergey Vasiliev", {4, 4, 3, 4, 4, 3}),
          Student("Olga Sokolova", {5, 4, 5}),
          Student("Andrey Mikhailov", {3, 3, 4, 2, 3, 3, 4, 2}),
          Student("Natalia Novikova", {4, 5, 5, 4, 5}),
          Student("Maxim Fedorov", {3, 4, 4}),
          Student("Tatiana Morozova", {5, 5, 5, 5, 5, 5, 5}),
          Student("Vladimir Volkov", {2, 2}),
          Student("Ekaterina Alekseeva", {4, 4, 5, 3, 4, 5}),
          Student("Pavel Lebedev", {3, 5, 4, 3}),
          Student("Ivan Smirnov", {5, 4, 5, 3, 5})};
}
} // namespace

int main() {
  StudentsList list(create_mock_data());
  StudentsUI ui(list);

  ui.run();
  return 0;
}