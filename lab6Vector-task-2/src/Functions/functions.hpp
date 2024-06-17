#ifndef VECTOR_OPERATIONS_HPP
#define VECTOR_OPERATIONS_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <iomanip>


void addNumber(std::vector<int32_t>& vectorOfIntNum, int32_t value);

int32_t calculate(const std::vector<int32_t>& vectorOfIntNum);
int32_t calculateSum(const std::vector<int32_t>& vectorOfIntNum);

void replaceZerosWithAverage(std::vector<int32_t>& vectorOfIntNum);
void replaceEvenNumbers(std::vector<int32_t>& vectorOfIntNum);

void addToInterval(std::vector<int32_t>& vectorOfIntNum, int32_t leftBoard, int32_t rightBoard);
void removeDuplicates(std::vector<int32_t>& vectorOfIntNum);

size_t countGreaterThan(std::vector<int32_t>& vectorOfIntNum, int32_t value);
size_t numberOfEqual(std::vector<int32_t>& vectorOfIntNum, int32_t value);


#endif // VECTOR_OPERATIONS_HPP
