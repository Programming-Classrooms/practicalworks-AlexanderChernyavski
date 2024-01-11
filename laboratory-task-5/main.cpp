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
    ычисляется новое значение s 2 . Процесс удвоения number of approximations и вычисления s 2 надо продолжать до тех пор,
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


double formuleNumber1(double x)
{
   const double formule = 1 / (1 + sqrt(2 * x));
    return  formule;
}

double formuleNumber2(double x)
{
    const double formule = pow(x, 3) * pow(exp(x),2);
    return formule;
}

double formuleNumber3(double x)
{
    const double formule = sqrt(pow(2, x) - 1);
    return formule;
}

 double simpsonMethodFormule
 (double (*formule)(double), const double lowerBoundIntegration, const double upperBoundIntegration, uint32_t numberOfSplits, double height, double& result2)
{
    for (size_t i = 0; i < numberOfSplits; ++i)
    {
         double x1 = lowerBoundIntegration + i * height;
         double x2 = lowerBoundIntegration + (i + 1) * height;
         result2 += (x2 - x1) / 6.0 * (formule(x1) + 4.0 * formule(0.5 * (x1 + x2)) + formule(x2));
    }
    return result2;
}

void calcIntegralSimpson(double (*formule)(double), const double lowerBoundIntegration, const double upperBoundIntegration, double accuracy)
{
    uint32_t numberOfSplits = 4;
    double height = (upperBoundIntegration - lowerBoundIntegration) / numberOfSplits, result1 = 0.0, result2 = 0.0;

    simpsonMethodFormule(formule, lowerBoundIntegration, upperBoundIntegration, numberOfSplits, height, result2);

    while (abs(result1 - result2) > accuracy)
    {
        result1 = result2;
        result2 = 0;
        numberOfSplits *= 2;
        height /= 2;

        simpsonMethodFormule(formule, lowerBoundIntegration, upperBoundIntegration, numberOfSplits, height, result2);
    }
    std::cout << "Result of calculating the integral using Simpson's method: " << result2 << "\nNumber of splits: " << numberOfSplits << '\n';
}

double leftRectangleMethodFormule
(double (*formule)(double), const double lowerBoundIntegration, const double upperBoundIntegration, uint32_t numberOfSplits, double& height, double& result)
{
    for (size_t i = 1; i <= numberOfSplits; ++i)
    {
        result += formule(lowerBoundIntegration + height * i - height / 2);
    }
    result *= height;
    return result;
}
void calcIntegralLeftRectangle(double (*formule)(double), const double lowerBoundIntegration, const double upperBoundIntegration,  double accuracy)
{
    uint32_t numberOfSplits = 4;
    double result1=0.0, result2=0.0, height = (upperBoundIntegration - lowerBoundIntegration) / numberOfSplits;

    leftRectangleMethodFormule(formule, lowerBoundIntegration, upperBoundIntegration, numberOfSplits, height, result2);
   
    while (abs(result1 - result2) > accuracy)
    {
        result1 = result2;
        result2 = 0;
        numberOfSplits *= 2;
        height /= 2;
        
        leftRectangleMethodFormule(formule, lowerBoundIntegration, upperBoundIntegration, numberOfSplits, height, result2);
    }
    std::cout << "Result of calculating the integral using left rectangle method: " << result2 << "\nNumber of splits: " << numberOfSplits << '\n';
}

void selectCalcMethod(double (*formule)(double), const double lowerBoundIntegration, const double upperBoundIntegration, double accuracy)
{
    size_t choise;
    std::cout << "Select the integral formula you want to calculate";
    std::cout << "Choose an option:\n";
    std::cout << "1. Calculation of the integral using the left rectangle method\n";
    std::cout << "2. Calculation of the integral using the simpson method\n";
    std::cout << "What did you choose: ";
    std::cin >> choise;
    switch (choise)
    {
    case 1:
    {
        calcIntegralLeftRectangle((*formule), lowerBoundIntegration, upperBoundIntegration, accuracy);
        break;
    }
    case 2:
    {
        calcIntegralSimpson((*formule), lowerBoundIntegration, upperBoundIntegration, accuracy);
        break;
    }
    default:
        throw std::runtime_error("Please, to select you need to enter either 1 or 2 or 3");
        break;
    }
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
        double accuracy;
        size_t choise;
        std::cout << "Enter accuracy (0 < accuracy < 1 and accuracy > 0.000000000000000001): ";
        std::cin >> accuracy;
        checkAccuracy(accuracy);
        std::cout << std::endl;
        std::cout << "Select the integral formula you want to calculate";
        std::cout << "Choose an option:\n";
        std::cout << "1. Formule No.1 (1 / (1 + sqrt(2 * x)))\n";
        std::cout << "2. Formule No.2 pow(x, 3) * exp(x)\n";
        std::cout << "3. Formule No.3 sqrt(pow(2, x) - 1)\n";
        std::cout << "What did you choose: ";
        std::cin >> choise;
        switch (choise)
        {
        case 1:
        {
            std::cout << "For this formule:\n";
            std::cout << "lowerBoundIntegration = 0.0\n";
            std::cout << "upperBoundIntegration = 1.0\n";
            const double lowerBoundIntegration = 0.0;
            const double upperBoundIntegration = 1.0;
            selectCalcMethod(formuleNumber1, lowerBoundIntegration, upperBoundIntegration, accuracy);
            break;
        }
        case 2:
        {
            std::cout << "For this formule:\n";
            std::cout << "lowerBoundIntegration = 0.0\n";
            std::cout << "upperBoundIntegration = 0.8\n";
            const double lowerBoundIntegration = 0.0;
            const double upperBoundIntegration = 0.8;
            selectCalcMethod(formuleNumber2, lowerBoundIntegration, upperBoundIntegration, accuracy);
            break;
        }
        case 3:
        {
            std::cout << "For this formule:\n";
            std::cout << "lowerBoundIntegration = 0.3\n";
            std::cout << "upperBoundIntegration = 1.0\n";
            const double lowerBoundIntegration = 0.3;
            const double upperBoundIntegration = 1.0;
            selectCalcMethod(formuleNumber3, lowerBoundIntegration, upperBoundIntegration, accuracy);
            break;
        }

        default:
            throw std::runtime_error("Please, to select you need to enter either 1 or 2 or 3");
            break;
        }
    }
    catch (const std::exception& is)
    {
        std::cerr << is.what();
    }
    return 0;
}

