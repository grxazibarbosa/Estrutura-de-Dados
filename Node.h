// NAO MEXA NESTE ARQUIVO, ELE JA ESTA PRONTO PARA SER USADO PELO MOODLE
#ifndef NODE_H
#define NODE_H
#include <iostream>

struct Node {
    int value; // variavel que guarda o valor
    Node *next; // ponteiro para o proximo elemento

    // construtor do node
    Node(int value, Node* next) {
        this->value = value;
        this->next = next;
    }
};

#endif