/*Essa atividade declara uma estrutura Aluno com matrícula, nome e nota. 
Na main, o programa lê a quantidade de alunos e armazena suas informações em um array.
Depois, lê uma matrícula e busca no array o aluno correspondente. Se encontrar, 
imprime o nome e a nota com uma casa decimal, se não encontrar, exibe a mensagem "NAO ENCONTRADA".*/

#include <iostream>
#include <iomanip>

struct Aluno{
    int matricula;
    char nome[100];
    float nota{};
};

int main(){
    

    int qtd{};
    std::cin>> qtd;

    Aluno alun [50];

    for(int i = 0; i < qtd; i++){
        
        std::cin >> alun[i].matricula;
        std::cin.ignore();
        std::cin.getline(alun[i].nome, 100);
        std::cin >> alun[i].nota;
        std::cin.ignore();
        
    }

    int matricula;
    std::cin >> matricula;
    //std::string guardar_aluno;

    for(int i = 0; i < qtd; i++){
        if(alun[i].matricula == matricula){
           std::cout<< alun[i].nome << "\n" << std::fixed << std::setprecision(1) << alun[i].nota << std::endl;
           return 0;
        }
    }
    
    std::cout<<"NAO ENCONTRADA"<< std::endl;

    


}
