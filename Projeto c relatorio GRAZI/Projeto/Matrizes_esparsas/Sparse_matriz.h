#ifndef SPARSE_MATRIZ
#define SPARSE_MATRIZ
#include "Node.h"
#include <iostream>


class Sparse_matriz{
    private:
        Node* m_head;
        int linha; //linha
        int coluna; //coluna

        //função que apaga uma linha do nó passado
        //apenas as células guardadas na matriz 
        void apagar_linha(Node* sentinela_linha) {
            Node* aux_direita = sentinela_linha->direita;
            while (aux_direita != sentinela_linha) {
                Node* aux_del = aux_direita;
                aux_direita = aux_direita->direita;
                delete aux_del;
            }
            delete sentinela_linha;
        }

    public:
        //construtor default (lista vazia)
        Sparse_matriz(){
            m_head = new Node(nullptr, nullptr, 0, 0, 0);
            linha = 0;
            coluna = 0;
        }

        //construtor que constrói os nós sentinelas do tipo Node de linha e coluna
        //se linha e coluna forem maiores que zero
        Sparse_matriz(int linha, int coluna){
            this->linha = linha;
            this->coluna = coluna;

            //Vverifica se coluna e linha são maiores que zero
            if(linha > 0 && coluna > 0){
                m_head = new Node(nullptr, nullptr, 0, 0, 0);

                Node* aux = m_head;

                //estrutura para criar os nós sentinelas da coluna
                for(int i = 1; i <= coluna; i++){
                    Node* newNode = new Node(nullptr, nullptr, 0, 0, 0);
                    newNode->coluna = i;
                    aux->direita = newNode;
                    aux = newNode;
                    //se for o ultimo nó, ele apontará para o m_head (lista circular)
                    if(i == coluna){
                        newNode->direita = m_head;
                    }
                }

                Node* aux_abaixo = m_head;
                //estrutura para criar os nós senitinelas da linha
                for(int i = 1; i <= linha; i++){
                    Node* newNode = new Node(nullptr, nullptr, 0, 0, 0);
                    newNode->linha = i;
                    aux_abaixo->abaixo = newNode;
                    aux_abaixo = newNode;
                    //se for o ultimo nó, o abaixo dele aponta para o m_head
                    if(i == linha){
                        newNode->abaixo = m_head;
                    }

                }
            }
            else throw "linha ou coluna igual ou menor a 0";
        }

        //função que insere um elemento do tipo Node no espaço especificado 
        //passado como parametro. 
        //restrições: linha e coluna precisam estar no intervalo certo,
        //linha e coluna devem ser maiores que zero,
        //valor 0 não deve ser guardado na matriz (não obedece a regra).
        void inserir(int linha, int coluna, double valor){

            if((linha <= 0 || linha > this->linha) || (coluna <=0 || coluna > this->coluna)){
                throw "indices invalidos. inserção invalida!";
            }
            //preencher apenas com valores diferentes de zero
            //se valor passado for zero, a função acaba aqui.
            if(valor == 0){
                return;
            }
            
            //auxiliares de linha 
            Node* aux_coluna = m_head->direita;
            Node* aux_linha = m_head->abaixo;

            while(aux_coluna->coluna != coluna){
                aux_coluna = aux_coluna->direita; //chega até a coluna passada como parâmetro
            }
            while(aux_linha->linha != linha){
                aux_linha = aux_linha->abaixo; //chega até a linha passada como parâmetro
            }
           
            //auxiliares para os proximos
            //aux_coluna_next ou é o próximo Node (aux_linha ou aux_coluna)->direita / abaixo
            //ou é o próprio aux_linha ou aux_coluna, se não tiver elemento
            Node* aux_coluna_next = aux_coluna->abaixo;
            Node* aux_linha_next = aux_linha->direita;

            ///////////////////////////////////////////////////////////////
            //começo da inserção

            //caso em que a coluna está vazia 
            if(aux_coluna_next == aux_coluna){
               Node* newNode = new Node(nullptr, aux_coluna, linha, coluna, valor);
                aux_coluna->abaixo = newNode;

               //laço para ligar na linha
               while(true){
                    if(aux_linha_next->coluna > coluna){ // se tiver no meio
                        aux_linha->direita = newNode; 
                        newNode->direita = aux_linha_next;
                        break;
                    }
                    if(aux_linha_next == aux_linha){ //se for o primeiro
                        aux_linha->direita = newNode;
                        newNode->direita = aux_linha;
                        break;
                    }
                    if(aux_linha_next->coluna == 0){ // se é o ultimo 
                        aux_linha->direita = newNode;
                        newNode->direita = aux_linha_next;
                        break;
                    }
                    aux_linha = aux_linha->direita;
                    aux_linha_next = aux_linha_next->direita;
               }

            }else{
                //caso que a coluna possui elemento
                Node* guarda_newNode;
                while(true){
                    if(aux_coluna_next->linha == linha){ // se o elemento existir
                        aux_coluna_next->valor = valor;
                        return; 
                    }
                    if(aux_coluna_next->linha > linha){ // se for no meio
                        Node* newNode = new Node(nullptr, aux_coluna_next, linha, coluna, valor);
                        aux_coluna->abaixo = newNode;
                        guarda_newNode = newNode;
                        break;
                    }
                    if(aux_coluna_next == aux_coluna){ //se for o primeiro do primeiro
                        Node* newNode = new Node(nullptr, aux_coluna, linha, coluna, valor);
                        newNode->abaixo = aux_coluna;
                        guarda_newNode = newNode;
                        break;
                    }
                    if(aux_coluna_next->linha == 0){ // caso que é o ultimo da coluna
                        Node* newNode = new Node(nullptr, aux_coluna_next, linha, coluna, valor);
                        aux_coluna->abaixo = newNode;
                        guarda_newNode = newNode;
                        break;
                    }
                    aux_coluna = aux_coluna->abaixo;
                    aux_coluna_next = aux_coluna_next->abaixo;
                }
                
                //laço para ligar na linha
                while(true){
                    if(aux_linha_next->coluna == coluna){ //se tiver elemento
                        aux_linha_next->valor = valor;
                        break;
                    }
                    if(aux_linha_next->coluna > coluna){ //se for no meio
                        aux_linha->direita = guarda_newNode;
                        guarda_newNode->direita = aux_linha_next;
                        break;
                    }
                    if(aux_linha_next == aux_linha){ // se for o primeiro
                        aux_linha->direita = guarda_newNode;
                        guarda_newNode->direita = aux_linha;
                        break;
                    }
                    if(aux_linha_next->coluna == 0){ //se for o ultimo
                        aux_linha->direita = guarda_newNode;
                        guarda_newNode->direita = aux_linha_next;
                        break;
                    }
                    aux_linha = aux_linha->direita;
                    aux_linha_next = aux_linha_next->direita;
                }
            }
        }

        //função que acessa o elemento da linha e coluna
        //passado como parâmetro e retorna o valor do Node.
        //Só faz algo se linha e coluna estiverem no intervalo correto
        double get(int linha, int coluna){
            if((linha > 0 && linha <= this->linha) && (coluna > 0 && coluna <= this->coluna)){  
                Node* aux = m_head->direita;
                while(aux->coluna != coluna){
                    aux = aux->direita; //chego até a coluna desejada
                }

                Node* aux_linha = aux->abaixo;
                while(aux_linha != aux){
                    if(aux_linha->linha == linha){
                        return aux_linha->valor; //se for o espaço especificado retorno o valor
                    }
                    if(aux_linha->linha > linha){ //se passou da linha é porque o elemento nao existe
                        return 0;
                    }
                    aux_linha = aux_linha->abaixo;
                }
                return 0;
            }else{
                throw "indices invalidos";
            }

        }

        //função que imprime a matriz
        void print(){
            Node* aux_linha = m_head->abaixo; 
            for(int i = 1; i <= this->linha; i++){
                Node* aux_p = aux_linha->direita; // aux_p caminha pela coluna
                for(int j = 1; j <= this->coluna; j++){
                    if(aux_p->coluna == j){ //se tiver elemento 
                        std::cout << aux_p->valor << '\t'; //imprime o valor do elemento
                        aux_p = aux_p->direita;
                    }else std::cout << "0\t"; //printa zero se não tiver
                }
                std::cout << '\n';
                aux_linha = aux_linha->abaixo; //próxima linha
            }
        }
       
        //destrutor
        ~Sparse_matriz() {
            Node* aux = m_head->abaixo;
            while (aux != m_head) {
                Node* aux_abaixo = aux->abaixo;
                apagar_linha(aux);
                aux = aux_abaixo;
            }
            apagar_linha(m_head);
        }

        //função que reconstrói a matriz com novas dimensões 
        //deleto a matriz e no mesmo espaço do endereço da memoria coloco a 'nova' matriz
        void redimensiona(int linha, int coluna){
            this->~Sparse_matriz();
            new (this) Sparse_matriz(linha, coluna);
        }

        //get linha
        int get_linha(){
            return this->linha;
        }

        //get coluna
        int get_coluna(){
            return this->coluna;
        }

};

#endif