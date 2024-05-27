#include <iostream>
#include <memory>
#include <utility>

template <typename T>

class Stack
{
public:
    Stack() : top(nullptr), size(0)
    {
    }

    Stack(const Stack &rhs) : top(nullptr), size(rhs.size)
    {
        if (!rhs.isEmpty())
        {
            Node *current = rhs.top.get();
            top = std::make_unique<Node>(current->data);
            Node *thisCurrent = top.get();
            while (current->next)
            {
                current = current->next.get();
                thisCurrent->next = std::make_unique<Node>(current->data);
                thisCurrent = thisCurrent->next.get();
            }
        }
    };

    ~Stack() = default;

    const T &operator[](const size_t index)
    {
        if (index > size)
        {
            throw std::out_of_range("Out of range");
        }
        std::shared_ptr<Node> current = top;
        for (size_t i = 0; i < index; i++)
        {
            current = current->next;
        }
        return current->data;
    }

    bool isEmpty() const
    {
        return top == nullptr;
    }

    void pop()
    {
        if (isEmpty())
        {
            std::cout << "Stack is empty";
        }
        std::shared_ptr<Node> tempNode = top;
        top = std::move(top->next);
        --size;
    }

    std::ostream &display(std::ostream &out)
    {
        std::shared_ptr<Node> current = top;
        while (current != nullptr)
        {
            out << current->data << ' ';
            current = current->next;
        }
        return out;
    }

    void push(const T &info)
    {
        std::unique_ptr<Node> newNode = std::make_unique<Node>(info);
        newNode->next = std::move(top);
        top = std::move(newNode);
        ++size;
    }
    
    Stack &operator=(const Stack &rhs)
    {
        if (this != &rhs)
        {
            Stack temp(rhs);
            std::swap(top, temp.top);
        }
        return *this;
    }

private:
    struct Node
    {
        T data;
        std::shared_ptr<Node> next;
        Node(T data) : data(data), next(nullptr)
        {
        }
    };
    std::shared_ptr<Node> top;
    size_t size;
};

struct RailwayCarriage
{
    enum class Color
    {
        RED,
        BLUE,
        PURPLE,
        PINK,
        BROWN,
        WHITE,
        YELLOW,
        GREEN,
        OTHER
    };
    Color color;
    RailwayCarriage(Color color_ = Color::OTHER) : color(color_)
    {
        if (color == Color::OTHER)
        {
            throw std::invalid_argument("Please choose color");
        }
    };
    friend std::ostream &operator<<(std::ostream &out, const RailwayCarriage &col)
    {
        switch (col.color)
        {
        case Color::RED:
            out << "RailwayCarriage color: Red" << '\t';
            break;
        case Color::BLUE:
            out << "RailwayCarriage color: Blue" << '\t';
            break;
        case Color::PURPLE:
            out << "RailwayCarriage color: Purple" << '\t';
            break;
        case Color::PINK:
            out << "RailwayCarriage color: Pink" << '\t';
            break;
        case Color::BROWN:
            out << "RailwayCarriage color: Brown";
            break;
        case Color::WHITE:
            out << "RailwayCarriage color: White" << '\t';
            break;
        case Color::YELLOW:
            out << "RailwayCarriage color: Yellow" << '\t';
            break;
        case Color::GREEN:
            out << "RailwayCarriage color: Green" << '\t';
            break;
        default:
            break;
        }
        return out;
    }
};
