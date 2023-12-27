/*Разработать шаблон функции для обработки массивов с элементами простого арифметического типа и массивов, элементы которых – строки типа char* .
Продемонстрировать использование этого шаблона для конкретных динамических массивов типа int, double, char* .
Для получения входных данных иметь три варианта :
непосредственный ввод и запись в текстовый файл;
генерирование с помощью датчика случайных чисел и запись в текстовый файл;
ввод из текстового файла, а вывод - в консоль.
Вариант 14.
Разработать шаблон функции, позволяющей сжать массив, удалив из него все элементы, равные заданному числу number.
Освободившиеся в конце массива элементы заполнить первым не удалённым.*/


#include <iostream>
#include <fstream>
#include <ctime>
#include <memory>
#include <iomanip>
#include <string>


size_t countByteOfFile()
{
    size_t counter = 0;
    std::ifstream fin("file.txt");
    while (!fin.eof()) {
        fin.get();
        ++counter;
    }
    fin.close();
    counter--;
    return counter;
}

template <typename T>
void directInput(std::shared_ptr<T[]> array, size_t size)
{
    std::cout << "Enter " << size << " elements: \n";
    for (size_t i = 0; i < size; ++i) {
        std::cin >> array[i];
    }
}

template <typename T>
void arrayOutput(std::shared_ptr<T[]> array, size_t size)
{
    for (int i = 0; i < size; ++i) {
        std::cout << std::setw(5) << array[i] << ' ';
    }
    std::cout << '\n';
}

template <typename T>
void compressArray(std::shared_ptr<T[]> array, size_t size, T number)
{
    T writeIndex = 0;
    size_t j = 0;
    size_t counter = 0;
    for (size_t readIndex = 0; readIndex < size; ++readIndex) {
        if (fabs(number - array[readIndex]) > 0.0001) {
            array[j++] = array[readIndex];
        }
        else if (counter == 0) {
            writeIndex = array[readIndex + 1];
            ++counter;
        }
    }
    for (size_t i = j; i < size; ++i) {
        array[i] = writeIndex;
    }
}

// Рандом для инта (я определил от 0 до 100)
void arrayRand(std::shared_ptr<int32_t[]> array, size_t size)
{
    for (size_t i = 0; i < size; ++i) {
        array[i] = rand() % 100;
    }
}

// Рандом длявещественных значений
void arrayRand(std::shared_ptr<double[]> array, size_t size)
{
    for (size_t i = 0; i < size; ++i) {
        array[i] = 10 + (static_cast<double>(rand()) * 90 / RAND_MAX);
    }
}

// Рандом для символов(генерирует цифрыот 0 до 10, и ещё несколько символов )
void arrayRand(std::shared_ptr<char[]> array, size_t size)
{
    for (size_t i = 0; i < size; ++i) {
        array[i] = '0' + (rand() % 20);
    }
}

template <typename T>
void writeToFile(std::shared_ptr<T[]> array, size_t size)
{
    std::ofstream fout("file.txt");
    if (fout.is_open()) {
        for (size_t i = 0; i < size; ++i)
        {
            fout << array[i] << " ";
        }
        fout.close();
        std::cout << "Data written to file.txt\n";
    }
    else {
        throw std::exception("Unable to open file!\n");
    }
}

template <typename T>
void writeOutOfFile(std::shared_ptr<T[]> array, uint32_t size)
{
    if (countByteOfFile() != size) {
        throw std::exception("The size of the array you entered does not match the number of elements in the file");
    }
    std::ifstream fin("file.txt");
    uint32_t countSymbol = 0;
    fin.seekg(0, std::ios_base::end);
    countSymbol = fin.tellg();
    fin.close();
    std::ifstream finArrayOutput("file.txt");
    if (countSymbol >= size) {
        if (finArrayOutput.is_open()) {
            for (size_t i = 0; i < size && i < countSymbol; ++i) {
                finArrayOutput >> array[i];
            }
            finArrayOutput.close();
        }
        else {
            throw std::exception("Unable to open file!");
        }
    }
    else {
        throw std::exception("There is too little data in the file!");
    }
}

template <typename T>
void selectInputOption(std::shared_ptr<T[]> array, size_t size)
{
    uint32_t choiceForTask;
    T numberToDelete = 0;
    std::cout << "Choose an option:\n";
    std::cout << "1. Direct input and write to file\n";
    std::cout << "2. Generate and write to file\n";
    std::cout << "3. Read from file and print\n";
    std::cout << "What did you choose: ";
    std::cin >> choiceForTask;
    std::cout << "\n";
    switch (choiceForTask)
    {
    case 1:
        directInput(array, size);
        std::cout << "Generated array: ";
        arrayOutput(array, size);
        std::cout << "Write element to delete: ";
        std::cin >> numberToDelete;
        compressArray(array, size, numberToDelete);
        std::cout << "Converted array: ";
        arrayOutput(array, size);
        writeToFile(array, size);
        break;
    case 2:
        arrayRand(array, size);
        std::cout << "Generated array: ";
        arrayOutput(array, size);
        std::cout << "Write element to delete: ";
        std::cin >> numberToDelete;
        compressArray(array, size, numberToDelete);
        std::cout << "Converted array: ";
        arrayOutput(array, size);
        writeToFile(array, size);
        break;
    case 3:
        writeOutOfFile(array, size);
        std::cout << "Generated array: ";
        arrayOutput(array, size);
        std::cout << "Write element to delete: ";
        std::cin >> numberToDelete;
        compressArray(array, size, numberToDelete);
        std::cout << "Converted array: ";
        arrayOutput(array, size);
        writeToFile(array, size);
        break;
    default:
        throw std::runtime_error("Invalid choice. Choose between 1, 2, and 3.\n");
    }
}

void checkSize(int32_t size)
{
    if (size <= 0) {
        throw std::exception("The array length must be natural");
    }
}

int main()
{
    srand(time(NULL));
    try {
        int32_t size;
        std::cout << "Enter the size of the array:\n";
        std::cin >> size;
        checkSize(size);
        std::shared_ptr<int32_t[]> arrayInt(new int32_t[size]);
        std::shared_ptr<double[]> arrayDouble(new double[size]);
        std::shared_ptr<char[]> arrayChar(new char[size]);
        uint32_t choiceForArray;
        std::cout << "Choose which array you want:\n";
        std::cout << "1. With integer\n";
        std::cout << "2. With fractions\n";
        std::cout << "3.With symbols\n";
        std::cout << "What did you choose: ";
        std::cin >> choiceForArray;
        std::cout << '\n';
        switch (choiceForArray)
        {
        case 1:
            selectInputOption(arrayInt, size);
            break;
        case 2:
            selectInputOption(arrayDouble, size);
            break;
        case 3:
            selectInputOption(arrayChar, size);
            break;
        default:
            throw std::runtime_error("Invalid choice. Choose between 1, 2, and 3.\n");
        }
    }
    catch (std::exception &is) {
        std::cerr << is.what();
    }
    return 0;
}
