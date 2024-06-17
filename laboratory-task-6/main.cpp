/*
    Разработать шаблон функции для обработки массивов с элементами простого арифметического типа и массивов, элементы которых – строки типа char* .
    Продемонстрировать использование этого шаблона для конкретных динамических массивов типа int, double, char* .
    Для получения входных данных иметь три варианта :
    непосредственный ввод и запись в текстовый файл;
    генерирование с помощью датчика случайных чисел и запись в текстовый файл;
    ввод из текстового файла, а вывод - в консоль.
    Вариант 14.
    Разработать шаблон функции, позволяющей сжать массив, удалив из него все элементы, равные заданному числу number.
    Освободившиеся в конце массива элементы заполнить первым не удалённым.
*/

#include <iostream>
#include <fstream>
#include <ctime>
#include <memory>
#include <iomanip>
#include <string>

void checkSize(int32_t size)
{
    if (size <= 0)
    {
        throw std::exception("The array length must be natural");
    }
}

size_t countElementsInFIle()
{
    std::string temp;
    size_t counter = 0;
    std::ifstream fin("file.txt");
    while (fin >> temp)
    {
        ++counter;
    }
    return counter;
}

template <typename T>
void compressArray(std::shared_ptr<T[]> array, size_t size, T number)
{
    T writeIndex = 0;
    size_t elementOfSecondArray = 0;
    size_t counter = 0;
    for (size_t readIndex = 0; readIndex < size; ++readIndex)
    {
        if (fabs(number - array[readIndex]) > 0.0001)
        {
            array[elementOfSecondArray++] = array[readIndex];
        }
        else if (counter == 0)
        {
            writeIndex = array[readIndex + 1];
            ++counter;
        }
    }
    for (size_t i = elementOfSecondArray; i < size; ++i)
    {
        array[i] = writeIndex;
    }
}

void randomForArray(std::shared_ptr<int32_t[]> array, size_t size)
{
    int32_t leftBorder, rightBorder;
    std::cout << "Initial value from = \n";
    std::cin >> leftBorder;
    std::cout << "to = \n";
    std::cin >> rightBorder;
    if (leftBorder > rightBorder)
    {
        std::swap(leftBorder, rightBorder);
    }
    for (size_t i = 0; i < size; ++i)
    {
        array[i] = rand() % (rightBorder - leftBorder) + leftBorder;
    }
}

void randomForArray(std::shared_ptr<double[]> array, size_t size)
{
    double leftBorder, rightBorder;
    std::cout << "Initial value from = \n";
    std::cin >> leftBorder;
    std::cout << "to = \n";
    std::cin >> rightBorder;
    if (leftBorder > rightBorder)
    {
        std::swap(leftBorder, rightBorder);
    }
    for (size_t i = 0; i < size; ++i)
    {
        array[i] = rand() * (rightBorder - leftBorder) / RAND_MAX + leftBorder;
    }
}

void randomForArray(std::shared_ptr<char[]> array, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        array[i] = '0' + (rand() % 20);
    }
}

template <typename T>
void writeToFile(std::shared_ptr<T[]> array, size_t size)
{
    std::ofstream fout("file.txt");
    if (fout.is_open())
    {
        for (size_t i = 0; i < size; ++i)
        {
            fout << array[i] << " ";
        }
        fout.close();
        std::cout << "Resuls is written to file.txt\n";
    }
    else
    {
        throw std::exception("File cannot be opened\n");
    }
}

template <typename T>
void writeFromFile(std::shared_ptr<T[]> array, uint32_t size)
{
    std::ifstream fin("file.txt");

    if (fin.is_open())
    {
        for (size_t i = 0; i < size; ++i)
        {
            fin >> array[i];
        }

        if (countElementsInFIle() == 0)
        {
            throw std::exception("There is no data into file");
        }
        else if (countElementsInFIle() != size)
        {
            throw std::exception("The size of the array you entered does not match the number of elements in the file");
        }

        fin.close();
    }
    else
    {
        throw std::exception("File cannot be opened\n");
    }
}

template <typename T>
void inputByHands(std::shared_ptr<T[]> array, size_t size)
{
    std::cout << "Enter " << size << " elements: \n";
    for (size_t i = 0; i < size; ++i)
    {
        std::cout << "Write " << i << "element" << '\n';
        std::cin >> array[i];
    }
}

template <typename T>
void outputArray(std::shared_ptr<T[]> array, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        std::cout << std::setw(3) << array[i] << ' ';
    }
    std::cout << '\n';
}

template <typename T>
void fourFunctions(std::shared_ptr<T[]> array, size_t size)
{
    T numberToDelete = 0;

    std::cout << "Generated array: ";
    outputArray(array, size);

    std::cout << "Write element to delete: ";
    std::cin >> numberToDelete;
    compressArray(array, size, numberToDelete);

    std::cout << "Converted array: ";
    outputArray(array, size);
    writeToFile(array, size);
}

template <typename T>
void enterArrayFillingOption(std::shared_ptr<T[]> array, size_t size)
{
    uint32_t choice;
    std::cout << "Enter array filling option:\n";
    std::cout << "1. Manual filling and write to file.txt\n";
    std::cout << "2. Random generation and write to file.txt\n";
    std::cout << "3. Reading from a file and write to file.txt\n";
    std::cout << "Yours choise: ";
    std::cin >> choice;
    std::cout << '\n';
    switch (choice)
    {
    case 1:
        inputByHands(array, size);

        fourFunctions(array, size);
        break;
    case 2:
        randomForArray(array, size);

        fourFunctions(array, size);
        break;
    case 3:
        writeFromFile(array, size);

        fourFunctions(array, size);
        break;
    default:
        throw std::runtime_error("Invalid choice. Choose between 1, 2, and 3.\n");
    }
}

int main()
{
    srand(time(NULL));
    try
    {
        int32_t size;
        std::cout << "Enter the size of the array:\n";
        std::cin >> size;
        checkSize(size);

        std::shared_ptr<int32_t[]> intArray(new int32_t[size]);
        std::shared_ptr<double[]> doubleArray(new double[size]);
        std::shared_ptr<char[]> charArray(new char[size]);

        uint32_t choice;
        std::cout << "Select what type of array you want to create:\n";
        std::cout << "1. Integer array\n";
        std::cout << "2. Fractional array\n";
        std::cout << "3. Character array\n";
        std::cout << "Yours choise: ";
        std::cin >> choice;
        std::cout << '\n';
        switch (choice)
        {
        case 1:
            enterArrayFillingOption(intArray, size);
            break;
        case 2:
            enterArrayFillingOption(doubleArray, size);
            break;
        case 3:
            enterArrayFillingOption(charArray, size);
            break;
        default:
            throw std::runtime_error("Invalid choice. Choose between 1, 2, and 3.\n");
        }
    }
    catch (std::exception e)
    {
        std::cerr << e.what();
    }
    return 0;
}

