#ifndef NODE_H
#define NODE_H

struct Node{
    int value;
    Node * next {nullptr};
    Node * anterior {nullptr};

    Node(int value, Node* next = nullptr, Node* anterior = nullptr){
        int value = value;
        next = next;
        anterior = anterior;
    }

};

#endif

