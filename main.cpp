#include <iostream>
#include "queue.h"

int main(){
    
    int operacao;
    std::cin >> operacao;

    Fila fila;

    for(int i = 0; i < operacao; i++){
        
        int op;
        std:: cin>>op;

        if(op== 1){
            int op2;
            std::cin >> op2;
            fila.enfeileirar(op2);

        }

        if(op == 2){
            fila.remove();
        }

        if(op == 3){
            fila.mostrar_um();
        }
    }
}