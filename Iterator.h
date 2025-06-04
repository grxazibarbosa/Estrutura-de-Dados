// NAO MEXA NESTE ARQUIVO, ELE JA ESTA PRONTO PARA SER USADO PELO MOODLE
#ifndef ITERATOR_H
#define ITERATOR_H
#include "ForwardList.h"
#include "Node.h"

// Classe que implementa um iterador para uma ForwardList
// Um iterator é um objeto que aponta para um nó da lista.
class Iterator {
private:
    Node* m_pointer; // ponteiro para nó

    // ForwardList eh uma classe amiga de Iterator.
    // Logo, ela pode acessar todos os dados privados de um Iterator
    friend class ForwardList;

public:
    // Construtor default
    Iterator() : m_pointer{nullptr} {}

    // Construtor que recebe um ponteiro para Node
    Iterator(Node *ptr) : m_pointer{ptr} {}
    
    // Sobrecarga do operator*: retorna o valor
    // que está guardado no nó apontado
    int& operator*() const {
        return m_pointer->value;
    }

    // Sobrecarga do operador de pre-incremento
    Iterator& operator++() {
        m_pointer = m_pointer->next;
        return *this;
    }

    // Sobrecarga do operador de pós-incremento
    Iterator operator++(int) {
        Iterator temp(m_pointer);
        m_pointer = m_pointer->next;
        return temp;
    }

    // Sobrecarga do operador==
    // Retorna true se e somente se dois iteradores forem iguais
    // Quando eles são iguais? Quando o m_pointer dos dois forem iguais
    bool operator==(const Iterator& it) const {
        return m_pointer == it.m_pointer;
    }

    // Sobrecarga do operador!=
    // Retorna true se e somente se os iteradores são diferentes
    bool operator!=(const Iterator& it) const {
        return m_pointer != it.m_pointer;
    }
};

#endif