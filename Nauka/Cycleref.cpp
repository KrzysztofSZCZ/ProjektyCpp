#include <iostream>
#include <memory>

class Node{
    public:

    std::shared_ptr<Node> next;
    std::shared_ptr<Node> parent;

    Node(){std::cout << "Created" << std::endl;}
    ~Node(){std::cout << "Destroyed" << std::endl;}
};

class NodeWeak{
    public:

    std::shared_ptr<NodeWeak> next;
    std::weak_ptr<NodeWeak> parent;

    NodeWeak(){std::cout << "Created weak" << std::endl;}
    ~NodeWeak(){std::cout << "Destroyed weak" << std::endl;}
};


int main(){

    auto root = std::shared_ptr<Node>(new Node);
    auto next = std::shared_ptr<Node>(new Node);

    root->next = next;
    next->parent = root;

    auto rootWeak = std::shared_ptr<NodeWeak>(new NodeWeak);
    auto nextWeak = std::shared_ptr<NodeWeak>(new NodeWeak);

    rootWeak->next = nextWeak;
    nextWeak->parent = rootWeak;

    return 0;   
}