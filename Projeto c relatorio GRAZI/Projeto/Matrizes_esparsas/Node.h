#ifndef NODE_H
#define NODE_H

//Struct Node. Nó que representa o campo da matriz;
struct Node{
    Node* direita; // próximo elemento da linha
    Node* abaixo; // próximo elemento da coluna
    int linha; // número da linha
    int coluna; // número da coluna;
    double valor; // valor guardado dentro do campo especificado por linha e coluna na matriz;

    Node(Node* direita, Node* abaixo, int linha, int coluna, double valor){
        //aponta para o ponteiro recebido
        if(direita != nullptr){
            this->direita = direita;
        }else{
            this->direita = this; //senão, aponta pra si mesmo
        }
        if(abaixo != nullptr){
            this->abaixo = abaixo;
        }else{
            this->abaixo = this;
        }
        this->linha = linha;
        this->coluna = coluna;
        this->valor = valor;
    }

};

#endif