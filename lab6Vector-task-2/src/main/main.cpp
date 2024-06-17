#include "src/Functions/functions.hpp"


int main()
{
	uint32_t choice;
	std::vector<int32_t> vectorOfIntNum;

	
	while (true) {
        std::cout << "\n1. Add a number to the vector\n"
                     "2. Count total number of numbers in the vector\n"
                     "3. Count the qual numbers\n"
                     "4. Count the numbers greater than a given number\n"
                     "5. Replace zeros with the average of non-zero elements\n"
                     "6. Add to each element of the vector the sum of all numbers from a given interval\n"
                     "7. Replace all numbers whose modulus is an even number with the difference between the maximum and minimum element\n"
                     "8. Remove duplicates except the first occurrence\n"
                     "9. Display all elements of the vector\n"
                     "10. Exit\n"
                     "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int32_t value;
                std::cout << "Enter a number to add to the vector: ";
                std::cin >> value;
                addNumber(vectorOfIntNum, value);
                break;
            }
            case 2: {
                int32_t sum = calculate(vectorOfIntNum);
                std::cout << "Sum of numbers in the vector: " << sum << std::endl;
                break;
            }
            case 3: {
                int32_t naprimerN;
                std::cout << "Enter the number to count equal numbers: ";
                std::cin >> naprimerN;
                size_t count = numberOfEqual(vectorOfIntNum,naprimerN);
                std::cout << "Equal of " << naprimerN << " in the vector: " << count << std::endl;
                break;
            }
            case 4: {
                int32_t naprimerN;
                std::cout << "Enter the threshold number: ";
                std::cin >> naprimerN;
                int32_t count = countGreaterThan(vectorOfIntNum, naprimerN);
                std::cout << "Numbers greater than " << naprimerN << " in the vector: " << count << std::endl;
                break;
            }
            case 5: {
                replaceZerosWithAverage(vectorOfIntNum);
                std::cout << "Zeros replaced with the average of non-zero elements." << std::endl;
                break;
            }
            case 6: {
                std::cout << "Enter the left and right bounds of the interval: ";
                int32_t left, right;
                std::cin >> left >> right;
                addToInterval(vectorOfIntNum, left, right);
                std::cout << "Added sum of interval to each element." << std::endl;
                break;
            }
            case 7: {
                replaceEvenNumbers(vectorOfIntNum);
                std::cout << "Replaced numbers whose modulus is even." << std::endl;
                break;
            }
            case 8: {
                removeDuplicates(vectorOfIntNum);
                std::cout << "Removed duplicates except the first occurrence." << std::endl;
                break;
            }
            case 9: {
                std::cout << "All elements of the vector: ";
                for (int32_t num : vectorOfIntNum) {
                    std::cout << num << " ";
                }
                std::cout << std::endl;
                break;
            }
            case 10: {
                std::cout << "Exiting the program." << std::endl;
                return 0;
            }
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}