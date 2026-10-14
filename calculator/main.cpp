#include "header.hpp"
#include <cctype>
#include <clocale>
#include <cstddef>
#include <iostream>
#include <stack>
#include <stdexcept>
#include <string>
#include <unordered_map>

// инвертированные приоритеты операций
std::unordered_map<char, short> priority_map{
    {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'(', 0}};

std::vector<std::string> parse_exp(std::string exp) {
  std::vector<std::string> res;

  for (size_t i = 0; i < exp.length(); ++i) {
    std::string el = {exp[i]};

    if (std::isdigit(el[0])) {
      std::string number = el;

      // выделение многозначного числа (поддержка дробных)
      // TODO: сделать проверку на корректность записи дробного числа
      for (size_t j = i + 1; j < exp.length(); ++j) {
        if (std::isdigit(exp[j]) || exp[j] == '.') {
          number += exp[j];
          ++i;
        } else {
          break;
        }
      }

      res.push_back(number);
    } else {
      res.push_back(el);
    }
  }

  return res;
};

// перевод в обратную польскую нотацию
std::vector<std::string> to_polish_notation(std::vector<std::string> exp) {
  std::stack<std::string> ops_stack;
  std::vector<std::string> polish_notation;
  polish_notation.reserve(exp.size());

  for (size_t i = 0; i < exp.size(); ++i) {
    std::string el = exp[i];

    // обработка скобок
    if (el[0] == '(') {
      ops_stack.push(el);
    } else if (el[0] == ')') {
      while (!ops_stack.empty() && ops_stack.top()[0] != '(') {
        polish_notation.push_back(ops_stack.top());
        ops_stack.pop();
      }

      if (!ops_stack.empty()) {
        ops_stack.pop();
      }
    } else if (el.length() == 1 && priority_map.count(el[0]) > 0) {
      while (!ops_stack.empty() &&
             priority_map[el[0]] <= priority_map[ops_stack.top()[0]]) {
        polish_notation.push_back(ops_stack.top());
        ops_stack.pop();
      }

      ops_stack.push(el);
    } else {
      polish_notation.push_back(el);
    }
  }
  // вывод оставшихся операций из стека после обхода выражения
  while (!ops_stack.empty()) {
    polish_notation.push_back(ops_stack.top());
    ops_stack.pop();
  }

  return polish_notation;
};

double calc(std::vector<std::string> exp) {
  std::stack<double> res_stack;
  for (size_t i = 0; i < exp.size(); ++i) {
    std::string el = exp[i];

    // проверка является ли элемент оператором
    if (el.length() == 1 && priority_map.count(el[0]) > 0) {
      double b = res_stack.top();
      res_stack.pop();
      double a = res_stack.top();
      res_stack.pop();
      double res;

      switch (el[0]) {
      case '+':
        res = a + b;
        break;
      case '-':
        res = a - b;
        break;
      case '*':
        res = a * b;
        break;
      case '/':
        if (b == 0) {
          throw std::runtime_error("Деление на ноль");
        };
        res = a / b;
        break;
      default:
        throw std::runtime_error("Некорректная запись");
      }

      res_stack.push(res);
    } else {
      res_stack.push(std::stod(el));
    }
  }
  return res_stack.top();
};

int main() {
  std::setlocale(LC_NUMERIC, "C");

  try {
    std::string exp;
    double result;

    std::cin >> exp;
    result = calc(to_polish_notation(parse_exp(exp)));

    std::cout << result;
  } catch (const std::runtime_error &error) {
    std::cerr << "Ошибка вычисления: " << error.what() << '\n';
  }
};