#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
  int age;
  int mark;
  char name[121];
};

int main() {
  int count = 5;

  struct Student *students = malloc(count * sizeof(struct Student));

  if (students == NULL) {
    printf("Memory allocation error");
    return 0;
  }

  students[0].age = 20;
  students[0].mark = 2;
  strcpy(students[0].name, "Vasiliy Petrov");

  students[1].age = 21;
  students[1].mark = 5;
  strcpy(students[1].name, "Alexandr Petrov");

  students[2].age = 22;
  students[2].mark = 4;
  strcpy(students[2].name, "Ivan Smirnov");

  students[3].age = 19;
  students[3].mark = 2;
  strcpy(students[3].name, "Ulia Maksimova");

  students[4].age = 18;
  students[4].mark = 3;
  strcpy(students[4].name, "Valeriy Drozdov");

  double avg = 0;
  struct Student *highest_grade_student = &students[0];

  for (size_t i = 0; i < count; ++i) {
    if (students[i].mark > highest_grade_student->mark) {
      highest_grade_student = &students[i];
    }

    avg += students[i].mark;
  }
  avg = avg / count;

  printf("Average grade: %.2f\n", avg);
  printf("Student with highest grade: %s", highest_grade_student->name);

  free(students);

  return 0;
}