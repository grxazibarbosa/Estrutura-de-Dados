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
            return largura * comprimento * largura;
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