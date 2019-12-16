#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <stdlib.h>
#include <tr1/memory>


class Node {
    public:
        Node();
        virtual ~Node();
        Node& operator=(const Node& node);

        std::string name;
        std::string nextName;
};


Node::Node() :
    name(""),
    nextName("")
{

}

Node::~Node() {

}


Node& Node::operator=(const Node& node) {
    this->name = node.name;
    this->nextName = node.nextName;

    return *this;
}


int main(int argc, char **argv) {
    int n = 0;
    // Read the first line
    std::string line = "";
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);

        ss >> n;
    }

    std::vector<Node> nodeVector;
    int nodeArrIdx = 0;
    int m = n;
    int peopleCount = 0;
    // Read the next n lines
    while (std::getline(std::cin, line)) {
        std::stringstream ss(line);

        Node node;

        std::string curName = "";
        std::string nextName = "";

        ss >> curName >> nextName;

        node.name = curName;
        node.nextName = nextName;

        bool isFound = false;

        for (unsigned int i = 0; i != nodeVector.size(); ++i) {
            if (nodeVector[i].nextName.compare(curName) == 0) {
                nodeVector[i].nextName = nextName;
                isFound = true;
            }
        }

        if (!isFound) {
            nodeVector.push_back(node);
            ++peopleCount;
        }

        --n;
        if (n == 0) break;
    }

    std::cout << peopleCount << std::endl;
    for (unsigned int i = 0; i != nodeVector.size(); ++i) {
        std::cout << nodeVector[i].name << " " << nodeVector[i].nextName << std::endl;
    }

    return 0;
}
