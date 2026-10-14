#ifndef HEADER_HPP
#define HEADER_HPP

#include <string>
#include <vector>

std::vector<std::string> parse_exp(std::string exp);
std::vector<std::string> to_polish_notation(std::vector<std::string> exp);
double calc(std::vector<std::string> exp);

#endif
