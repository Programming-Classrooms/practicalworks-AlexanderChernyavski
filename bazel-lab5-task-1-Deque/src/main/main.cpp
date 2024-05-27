#include <iostream>

template <typename Info>
class TDeque {
private:
    struct DeqItem {
        Info Inf;//данные
        DeqItem* next;//ук на следующий
        DeqItem* prev;//ук на предыдущий
    };

    DeqItem* front;//ук на первый
    DeqItem* rear;//ук на последний
    size_t size;

    void Erase() { //удаление всех элементов
        while (front) {//пока сущ ук на первый (не указывает на ноль)
            DeqItem* temp = front;//вр значению присваиваем ук на первый
            front = front->next;
            delete temp;
        }
        rear = nullptr;//удаляю ук на последний
        size = 0;
    }

    void Clone(const TDeque& other) { //оператор =
        DeqItem* temp = other.front;
        while (temp) {
            InsertRear(temp->Inf);//начиная с конца дека
            temp = temp->next;//заполняем ел-тами
        }
    }

    void DeleteItem(DeqItem* item) {
        if (!item) 
        {
          throw std::runtime_error("Item was deleted");
        }

        if (item->prev)
        {
          item->prev->next = item->next;
        } 
        else front = item->next;

        if (item->next) item->next->prev = item->prev;
        else rear = item->prev;

        delete item;
        size--;
    }

    DeqItem* PtrByIndex(size_t index) const {// указатель на элемент с заданным индексом
        if (index >= size) 
        {throw std::out_of_range("because index >= size");}

        DeqItem* current = front;//начинаю с головы тк будет лично для меня полудобнее чем начинать перебор с конца
        for (size_t i = 0; i < index; ++i) {
            current = current->next;
        }
        return current;
    }

public:
    TDeque() : front(nullptr), rear(nullptr), size(0) {
    }

    TDeque(const TDeque& other) : front(nullptr), rear(nullptr), size(0) {
        Clone(other);
    }

    virtual ~TDeque() {
        Erase();
    }

    void InsFront(Info info) {
        DeqItem* newDeqItem = new DeqItem { info, front, nullptr };
        if (front)
        {
          front->prev = newDeqItem;//из головы указываем на предыдущий и соотв вставляем в начало
        } 
        front = newDeqItem;//если голова не nullptr просто присваиваем
        if (!rear)
        {
          rear = front;// если длина дека была 0
        } 
        size++;
    }

    void InsertRear(Info info) {
        DeqItem* newItem = new DeqItem{ info, nullptr, rear };
        if (rear)
        {
         rear->next = newItem;//the sasme as выше
        } 
        rear = newItem;
        if (!front) 
        {
            front = rear;
        }
        size++;
    }

    bool DelFront(Info& info) {

        if (!front)
        {
            return false;
        } 
        DeqItem* temp = front;
        info = front->Inf;//чтобы потом посмотреть что удалили
        front = front->next;//из головы указываем на следующий элемент в моём случае на 1
        if (front){ // 
          front->prev = nullptr;
        } 
        else rear = nullptr;
        delete temp;
        size--;
        return true;
    }

    bool DelRear(Info& info) {// исключить элемент из хвоста дека
        if (!rear)
        {
          throw std::runtime_error("Rear is empty");
        }
        DeqItem* temp = rear;
        info = rear->Inf;
        rear = rear->prev;
        if (rear) rear->next = nullptr;
        else front = nullptr;
        delete temp;
        size--;
        return true;
    }

    const TDeque& operator=(const TDeque& other) {//перегрузка =
        if (this != &other) {
            Erase();
            Clone(other);// только отличается то что не удаляем
        }
        return *this;
    }

    const Info& GetByIndex(unsigned index) const {//геттер все то же самое что и ниже
        DeqItem* item = PtrByIndex(index);
         return item->Info;
    }

    void SetByIndex(Info info, unsigned index) {// изменить элемент по индексу
        DeqItem* item = PtrByIndex(index);// возвратил констю указатель на эл-t
        item->Info = info;//ну и присвоил
    }

    void Browse(void (*func)(Info&)) {
        DeqItem* current = front;
        while (current) {
            func(current->Inf);
            current = current->next;
        }
    }

    void Browse(void (*func)(const Info&)) const {
        DeqItem* current = front;
        while (current) {
            func(current->Inf);
            current = current->next;
        }
    }
};

int main() {
    TDeque<int32_t> deque;
    deque.InsFront(1);
    deque.InsertRear(2);
    deque.InsFront(0);

    int val;
    deque.DelFront(val);
    std::cout << "Deleted from front: " << val << std::endl;

    deque.DelRear(val);
    std::cout << "Deleted from rear: " << val << std::endl;

    deque.Browse([](const int& item) {
        std::cout << item << " ";
        });
    std::cout << std::endl;

    return 0;
}
