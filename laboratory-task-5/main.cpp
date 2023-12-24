/*
  Вычислить значение определенного интеграла с аналитически заданной подынтегральной
  функцией с заданной точностью eps.

  Б) по формуле правых прямоугольников;
  Г) по формуле трапеций;

  где n–число точек деления отрезка [a, b]. Для вычисления первого приближения можно взять
  number of approximations=4. Чтобы оценить точность, с которой вычислено значение интеграла, необходимо найти второе
  приближение. Для этого можно увеличить number of approximations в два раза. Если s 1 и s 2 – два соседних приближения и |s 1
  – s 2 |&lt;eps, то точность считается достигнутой и s 2 принимается за искомое значение интеграла. В
  противном случае надо положить s 1 = s 2 и удвоить число точек деления отрезка [a, b]. После этого
  вычисляется новое значение s 2 . Процесс удвоения number of approximations и вычисления s 2 надо продолжать до тех пор,
  пока модуль разности s 1 и s 2 не станет меньше eps. Остальные формулы посмотреть самим.
  Разработать функции, реализующие методы вычислений интеграла, входными параметрами
  которых должны быть функция для вычисления значения подынтегрального выражения, пределы
  интегрирования и точность вычислений. Головная программа должна вывести результат вычислений
  для записанных в задании интегралов по заданным формулам и значение number of approximations, при котором достигнута
  заданная точность. Для проверки вычислений в таблице приведены значения интегралов.
  Номер задания равен вашему индивидуальному номеру.
*/



#include <iostream>
#include <cmath>


double integral1(double x) 
{
    long double function = 1 / (1 + sqrt(2 * x));
    return  function;
}

double integral2(double x)
{
    long double function  = pow(x, 3) * exp(x);
    return function;
}

double integral3(double x)
{
    long double function = sqrt(pow(2,x)-1);
    return function;
}

void leftRectangleMethod(double (*metod)(double) ,double a, double b,double eps) {
    uint32_t numberOfSplits = 4;
    long double height = (b - a) / numberOfSplits, result1 = 0, result2 = 0;
    for (size_t step = 0; step <= numberOfSplits; ++step)
    {
        result2 += height * metod(a + height * step);
    }
    while (abs(result1 - result2) > eps)
    {
        result1 = result2;
        result2 = 0;
        numberOfSplits *= 2; height /= 2;
        for (size_t i = 0; i <= numberOfSplits; ++i)
        {
            result2 += height * metod(a + height * i);
        }
    }
    std::cout << "Counting by left rectangle method: " << result2 << "\nNumber of sections: " << numberOfSplits << '\n' ;
}

void simpsonMethod(double (*metod)(double), double a, double b, double eps)
{
    uint32_t numberOfSplits = 4;
    long double height = (b - a) / numberOfSplits, result1 = 0.0, result2 = 0.0;
    for (size_t i = 0; i < numberOfSplits; i++)
    {
        const double x1 = a + i * height;
        const double x2 = a + (i + 1) * height;
        result2 += (x2 - x1) / 6.0 * (metod(x1) + 4.0 * metod(0.5 * (x1 + x2)) + metod(x2));
    }
    while (abs(result1 - result2) > eps)
    {
        result1 = result2;
        result2 = 0;
        numberOfSplits *= 2; height /= 2;
        for (int i = 0; i < numberOfSplits; i++) 
        {
            const double x1 = a + i * height;
            const double x2 = a + (i + 1) * height;
            result2 += (x2 - x1) / 6.0 * (metod(x1) + 4.0 * metod(0.5 * (x1 + x2)) + metod(x2));
        }
    }
    std::cout << "Counting by simpson method: " << result2 << "\nNumber of sections: " << numberOfSplits << '\n';
}

void outputTwoMethods(double (*metod)(double), double a, double b, double eps)
{
    leftRectangleMethod((*metod), a, b, eps);
    simpsonMethod((*metod), a, b, eps);
 }

void checkAccuracy(double accuracy)
{
    if (accuracy > 1 || accuracy <= 0 || accuracy < 0.000000000000000001)
    {
        throw std::exception("The accuracy you entered does not satisfy the conditions described above");
    }
}

int main() {
    try {
        double a, b, accuracy;
        std::cout << "Enter a lower bound for integration: ";
        std::cin >> a;
        std::cout << "Enter an upper bound for integration: ";
        std::cin >> b;
        std::cout << "Enter accuracy (0 < accuracy < 1 and accuracy > 0.000000000000000001): ";
        std::cin >> accuracy;
        std::cout << std::endl;
        std::cout << "Function 1: 1 / (1 + sqrt(2 * x))" << '\n';
        outputTwoMethods(integral1, a, b, accuracy);
        std::cout << std::endl;
        std::cout << "Function 2: pow(x, 3) * exp(x)" << '\n';
        outputTwoMethods(integral2, a, b, accuracy);
        std::cout << std::endl;
        std::cout << "Function 3: pow(x, 3) * exp(x)" << '\n';
        outputTwoMethods(integral3, a, b, accuracy);
    }
    catch (const std::exception& is)
    {
        std::cerr << is.what();
    }
    return 0;
}