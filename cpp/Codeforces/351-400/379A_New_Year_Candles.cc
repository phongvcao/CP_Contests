#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <memory>
#include <tr1/memory>


namespace CF {
    class Node {
        public:
            Node();
            Node(int n);
            virtual ~Node();

            std::tr1::shared_ptr<Node> getNext();
            void setNext(std::tr1::shared_ptr<Node> next);

            int getData();
            void setData(int data);

        private:
            int data;
            std::tr1::shared_ptr<Node> next;
    };

    class Queue {
        public:
            Queue();
            virtual ~Queue();

            void enqueue(int data);
            int dequeue();

            int getSize();
            bool empty();

        private:
            std::tr1::shared_ptr<Node> head;
            std::tr1::shared_ptr<Node> tail;
            int size;
    };
}


// CF::Node class
CF::Node::Node() {

}

CF::Node::Node(int n) :
    data(n)
{

}

CF::Node::~Node() {

}

std::tr1::shared_ptr<CF::Node> CF::Node::getNext() {
    return this->next;
}

void CF::Node::setNext(std::tr1::shared_ptr<CF::Node> next) {
    this->next = next;
}

int CF::Node::getData() {
    return this->data;
}

void CF::Node::setData(int data) {
    this->data = data;
}


// CF::Queue class
CF::Queue::Queue() {

}

CF::Queue::~Queue() {

}

void CF::Queue::enqueue(int data) {
    std::tr1::shared_ptr<CF::Node> node(new CF::Node(data));

    if (this->tail.get() == NULL) {
        this->tail = node;
        this->head = node;
    }

    else {
        this->tail->setNext(node);
        this->tail = this->tail->getNext();
    }

    ++size;
}

int CF::Queue::dequeue() {
    std::tr1::shared_ptr<CF::Node> temp = this->head;
    this->head = this->head->getNext();
    int tempData = temp->getData();
    temp.reset();

    if (this->head.get() == NULL) {
        this->tail = this->head;
    }

    --size;

    return tempData;
}

int CF::Queue::getSize() {
    return this->size;
}

bool CF::Queue::empty() {
    return this->size <= 0;
}

// Implement a Queue


int main(int argc, char **argv) {
    int a = 0;
    int b = 0;
    std::cin >> a;
    std::cin >> b;

    // 1 means living
    // 0 means burned
    // -1 means empty slots
    std::tr1::shared_ptr<CF::Queue> queue(new CF::Queue());
    for (int i = 0; i != a; ++i) {
        queue->enqueue(1);
    }

    int hoursCount = 0;
    int burnedCandles = 0;

    while (!queue->empty()) {
        int candle = queue->dequeue();

        if (candle == 0) {
            ++burnedCandles;

            if (burnedCandles == b) {
                queue->enqueue(1);
                burnedCandles = 0;
            }
        }

        else if (candle == 1) {
            queue->enqueue(0);
            ++hoursCount;
        }
    }

    std::cout << hoursCount;

    return 0;
}
