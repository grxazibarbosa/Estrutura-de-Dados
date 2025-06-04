// NAO MEXA NESTE ARQUIVO, ELE JA ESTA PRONTO PARA SER USADO PELO MOODLE
#ifndef CONST_ITERATOR_H
#define CONST_ITERATOR_H
#include "ForwardList.h"
#include "Node.h"

// Classe que implementa um iterador constante para uma ForwardList.
// Este iterador nao permite modificar o valor do node apontado.
// A unica diferenca desta classe para a classe Iterator eh na
// sobrecarga do operator*(). Aqui, esse operador retorna uma copia do inteiro. 
class ConstIterator {
private:
    Node* m_pointer; // ponteiro para nó

    // ForwardList eh uma classe amiga de ConstIterator.
    // Logo, ela pode acessar todos os dados privados de um ConstIterator
    friend class ForwardList;

public:
    // Construtor default
    ConstIterator() : m_pointer{nullptr} {}

    // Construtor que recebe um ponteiro para Node
    ConstIterator(Node *ptr) : m_pointer{ptr} {}
    
    // Sobrecarga do operator*: retorna o valor
    // que está guardado no nó apontado
    int operator*() const {
        return m_pointer->value;
    }

    // Sobrecarga do operador de pre-incremento
    ConstIterator& operator++() {
        m_pointer = m_pointer->next;
        return *this;
    }

    // Sobrecarga do operador de pós-incremento
    ConstIterator operator++(int) {
        ConstIterator temp(m_pointer);
        m_pointer = m_pointer->next;
        return temp;
    }

    // Sobrecarga do operador==
    // Retorna true se e somente se dois iteradores forem iguais
    // Quando eles são iguais? Quando o m_pointer dos dois forem iguais
    bool operator==(const ConstIterator& it) const {
        return m_pointer == it.m_pointer;
    }

    // Retorna true se e somente se são diferentes
    bool operator!=(const ConstIterator& it) const {
        return m_pointer != it.m_pointer;
    }
};


#endif