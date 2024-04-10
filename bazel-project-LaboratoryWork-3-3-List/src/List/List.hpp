#include <iostream>
#include <functional>

template<typename T>
struct ListNode {
    T data;
    ListNode<T>* next;
    ListNode(T val) : data(val), next(nullptr) {}
};

template<typename T>
class LinkedList {
private:
    ListNode<T>* head;
    size_t size;

public:
    LinkedList() : head(nullptr), size(0) {}


    LinkedList(const LinkedList<T>& other) {
        head = nullptr;
        size = 0;
        ListNode<T>* current = other.head;
        while (current) {
            insertEnd(current->data);
            current = current->next;
        }
    }

    LinkedList<T>& operator=(const LinkedList<T>& other) {
        if (this == &other) // self-assignment check
            return *this;

        // Clear existing elements
        clear();

        // Copy elements
        ListNode<T>* current = other.head;
        while (current) {
            insertEnd(current->data);
            current = current->next;
        }

        return *this;
    }

    ~LinkedList() {
        clear();
    }

    void insertBegin(T val) {
        ListNode<T>* newNode = new ListNode<T>(val);
        newNode->next = head;
        head = newNode;
        size++;
    }

    void insertEnd(T val) {
        ListNode<T>* newNode = new ListNode<T>(val);
        if (!head) {
            head = newNode;
        }
        else {
            ListNode<T>* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
        size++;
    }

    void deleteBegin() {
        if (!head) {
            std::cout << "List is empty. Nothing to delete.\n";
            return;
        }
        ListNode<T>* temp = head;
        head = head->next;
        delete temp;
        size--;
    }

    void deleteEnd() {
        if (!head) {
            std::cout << "List is empty. Nothing to delete.\n";
            return;
        }
        if (!head->next) {
            delete head;
            head = nullptr;
            size--;
            return;
        }
        ListNode<T>* current = head;
        while (current->next->next) {
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
        size--;
    }

    void deleteByValue(T val) {
        if (!head) {
            std::cout << "List is empty. Nothing to delete.\n";
            return;
        }
        if (head->data == val) {
            deleteBegin();
            return;
        }
        ListNode<T>* current = head;
        while (current->next) {
            if (current->next->data == val) {
                ListNode<T>* temp = current->next;
                current->next = current->next->next;
                delete temp;
                size--;
                return;
            }
            current = current->next;
        }
        std::cout << "Value not found in the list.\n";
    }

    int searchByValue(T val, std::function<bool(T)> callback = nullptr) {
        int comparisons = 0;
        ListNode<T>* current = head;
        while (current) {
            comparisons++;
            if (current->data == val) {
                if (callback) {
                    callback(current->data);
                }
                return comparisons;
            }
            current = current->next;
        }
        return -1; // Not found
    }

    void traverseWithCallback(std::function<void(T)> callback) {
        ListNode<T>* current = head;
        while (current) {
            callback(current->data);
            current = current->next;
        }
    }

    void printList() {
        ListNode<T>* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    void clear() {
        while (head) {
            ListNode<T>* temp = head;
            head = head->next;
            delete temp;
        }
        size = 0;
    }

    int32_t getSize() const {
        return size;
    }
};