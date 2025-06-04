#ifndef QUEUE_H
#define QUEUE_H

struct Node{
    Node* next;
    int value;

    Node(Node* next, int value){
        this->next = next;
        this->value = value;
    }

    ~Node(){
        delete next;
    }
};

//impementar uma pilha
//como se a interface é uma fila

class Stacck{
    private:
    Node* topo;
    int tamanho;

    public:

    Stacck(){
        topo = nullptr;
        tamanho = 0;
    }

    void pop(){
        if(this->tamanho > 0){
            Node* aux = topo->next;
            topo->next = nullptr;
            delete topo;
            topo = aux;
            tamanho--;
        }
    }

    void inserir(int valor){
        Node* aux = new Node(topo,valor);
        topo = aux;
        tamanho++;
    }

    bool vazia_sim_or_no(){
        if(tamanho == 0){
            return true; 
        }else return false;
    }
    int mostra_topo(){
        if(this->tamanho > 0){
            return topo->value;
        }
    }

    int get_tamanho(){
        return tamanho;
    }

    ~Stacck(){
        delete topo;
    }
};

class Fila{
    private:
    Stacck* prateleira;
    Stacck* deposito;

    public:
    Fila();

    void enfeileirar(int value);

    void remove();

    int mostrar_um();

    
};




#endif