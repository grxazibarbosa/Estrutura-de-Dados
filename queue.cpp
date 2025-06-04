#include "queue.h"


    Fila::Fila(){
        Stacck* prateleira = new Stacck;
        Stacck* deposito = new Stacck;
    }

    void Fila::enfeileirar(int value){
        deposito->inserir(value);
    }

    void Fila::remove(){
       if(prateleira->vazia_sim_or_no()){
            while(!deposito->vazia_sim_or_no()){
                int aux = deposito->mostra_topo();
                deposito->pop();
                prateleira->inserir(aux);
            }
       }
    }

    int Fila::mostrar_um(){
        return prateleira->mostra_topo();
    }