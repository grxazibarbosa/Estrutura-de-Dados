//struct que define Node 
/*#ifndef NODE_H
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

*/

#ifndef LIST_H
#define LIST_H
#include "Node.h" //para usar Node

/*   classe que implementa uma lista dupplamente encadeada 
     circlar com nó sentinela
*/

/*  funcionalidades

    1. construtor default
    2. construtor que inicia lista já com elementos 
    3. construtor de cópia
    4. inserir no início
    5. remover do inicio
    6. inserir no final 
    7. remover do final
    8. comparar duas listas
    9. imprimir na tela
    10. copiar um elemento em outra
    11. limpar lista
    12. destrutor
*/

class List{
    private: 
        Node* m_head; //ponteiro para a cabeça da lista
        int m_size; //numero de elementos da lista
    public:

    //1.
    List(){
        m_size = 0;
        m_head = new Node(0, nullptr, nullptr);//cria vazio
        m_head->next = m_head;//faz apontar pra si mesmo
        m_head->anterior = m_head;//faz apontar pra si mesmo
    }

    //que coisa maluca
    //funcion para lista vazia e nao vazia
    void push_front(int value){
        Node * newNode = new Node(value, nullptr, nullptr);

        newNode->anterior = m_head;
        newNode->next = m_head->next;
        m_head->next = newNode;
        newNode->next->anterior = newNode;
        m_size ++;
    }

    //remover um elemento do inicio da lista
    void pop_front(int value){
        if(m_size != 0){
            Node *aux = m_head->next;
            m_head->next = aux->next;
            aux->next->anterior = m_head;
            delete aux;
            m_size--;
        }
    }
    //inserir no final
    void push_back(int value){
        Node * newNode = new Node(value, nullptr, nullptr);
        newNode->next = m_head;
        newNode->anterior = m_head->anterior;

        m_head->anterior = newNode;
        m_head->anterior->next = newNode;

        m_size++;
    }
    
    //remover do final
    void pop_back(){
        if(m_size != 0){
            Node * aux = m_head->anterior;
            m_head->anterior = m_head->anterior->anterior;
            aux->anterior->next = m_head;
            delete aux; 
            m_size--;
        }
    }

    //funcção que verifica se a lista está vazia
    bool empty(){
        if(m_size == 0){
            return true;
        }else return true;
    }

    //função para limpar a lista
    void clear(){
        while( ! empty()){
            pop_back();
        }
    }

    //destrutor
    ~List(){
        clear();
        delete m_head;
    }

//pesquisar a diferença entre
// Node* atual = lst.m_head->next;
// Node* aux = new Node(atual->value,

    //função que sobrecarrega o operador de atribuição
    List& operator=(const List& lst){
        clear();//limpar a lista pra ela ficar so com o m_head sozinho
        Node* atual = lst.m_head->next; //pegar o nó sentinela da nova lista
        while(atual != lst.m_head){
            Node* aux = new Node(atual->value, nullptr, nullptr);
            Node* ultimo = m_head->anterior;
            aux->next = m_head;
            aux->anterior = ultimo;
            ultimo->next = aux;
            m_head->anterior = aux;

            //caminha
            atual = atual->next;

        }
        m_size = lst.m_size;
        return *this;
    }

    //essa função sobrecarrega o operador == e retorna true se as duas listas forem identicass
    bool operator==(const List& lst){
        if(m_size != lst.m_size){
            return false;
        }
        Node* atual1 = lst.m_head->next;
        Node* atual2 = m_head->next;
        while(atual1 != m_head){
            if(atual2->value != atual2->value){
                return false;
            }
            atual1 = atual1->next;
            atual2 = atual2->next;
        }
        return true;
    }
};


#endif
