#include "../List/List.hpp"




int main() {
    LinkedList<int32_t> list;
    list.insertBegin(3);
    list.insertEnd(5);
    list.insertEnd(7);
    list.insertBegin(1);

    std::cout << "List after insertions: ";
    list.printList();

    list.deleteBegin();
    std::cout << "List after deleting first element: ";
    list.printList();

    list.deleteEnd();
    std::cout << "List after deleting last element: ";
    list.printList();

    list.deleteByValue(5);
    std::cout << "List after deleting value 5: ";
    list.printList();

    int searchValue = 7;
    int comparisons = list.searchByValue(searchValue);
    std::cout << "Searched for value " << searchValue << ". Comparisons made: " << comparisons << std::endl;

    std::cout << "List after traversal with callback: ";
    list.traverseWithCallback([](int val) { std::cout << val << " "; });
    std::cout << std::endl;

    return 0;
}
