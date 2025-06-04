/*Essa atividade define uma classe caixa que representa um objeto tridimensional com 
atributos privados: largura, altura e comprimento. A classe possui um construtor que exibe uma mensagem 
ao criar um objeto. Tem métodos get e set para acessar e modificar os atributos, com validações para 
garantir que os valores sejam positivos. Também há um método volume quecalcula o volume da caixa.

*/

#include <iostream>
class caixa{
    private:
        int largura;
        int altura;
        int comprimento;

    public:
        caixa(){
            std::cout<<"caixa foi criada"<<std::endl;
        }

        int volume(int largura, int comprimento, int altura){
            return largura * comprimento * altura;
        }

        int get_largura(){
            return largura;
        }
        int get_comprimento(){
            return comprimento;
        }
        int get_altura(){
            return altura;
        }

        void set_largura(int largura){
            if(largura > 0){
                this->largura = largura;
            }
        }
        void set_comprimento(int comprimento){
            if(comprimento > 0){
                this->comprimento = comprimento;
            }
        }

        void set_altura(int altura){
            if(altura > 0){
                this->altura = altura;
            }
        }

};
