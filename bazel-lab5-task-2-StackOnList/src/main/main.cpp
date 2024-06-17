/*3. Разработать шаблон класса для работы со стеком, реализованным на
 основе списка. Для разрабатываемого шаблона обязательно определите:
 o конструктор по умолчанию;
 o конструктор копирования;
 o деструктор;
 o оператор присваивания;
 o оператор [];
 o вставку элемента в стек;
 o удаление элемента из стека;
 o просмотр элемента в вершине стека без его удаления
 o просмотр всех элементов, находящихся в стеке.
 Пользовательский тип – железнодорожный вагон. На станцию подается
 состав из красных и зеленых вагонов. Используя шаблон
переформировать его, чередуя вагоны разных цветов*/


#include "src/Stack/Stack.hpp"


int main() {
 try {
  Stack<RailwayCarriage> carriageStack;

  carriageStack.push(RailwayCarriage(RailwayCarriage::Color::RED));//Добавляю вагон

  //Конструктор копирования
  Stack<RailwayCarriage> copyCarriageStack(carriageStack);
  std::cout << "Top of copy stack: " << copyCarriageStack[0] <<'\n';

  //Оператор присваивания
  Stack<RailwayCarriage> tempStack;
  tempStack = carriageStack;
  std::cout << "Top of stack: " << tempStack[0] <<'\n';

  //Удаление из стека
  carriageStack.pop();
  carriageStack.display(std::cout);

  std::cout<<"========================================================="<<'\n';
  
  carriageStack.push(RailwayCarriage(RailwayCarriage::Color::BLUE));
  carriageStack.push(RailwayCarriage(RailwayCarriage::Color::GREEN));
  carriageStack.display(std::cout);
 }
 catch (std::out_of_range& e)
 {
  std::cerr << e.what();
 }
 return 0;
}