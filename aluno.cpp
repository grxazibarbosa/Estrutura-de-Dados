#include <iostream>
#include <iomanip>

struct Aluno{
    char nome [100];
    int matricula{};
    char disciplina[120];
    float nota{};
};

void avalia(Aluno *p1){
    if(p1->nota >= 7){
        std:: cout << p1->nome << " aprovado(a) em " << p1->disciplina << std::endl;
    }

    if(p1->nota < 7){
         std:: cout << p1->nome << " reprovado(a) em " << p1->disciplina << std::endl;
    }
}

int main(){

    Aluno a1;

    std::cin >> a1.nome;
    std::cin.ignore();
    std::cin >> a1.matricula;
    std::cin.ignore();
    std::cin >> a1.disciplina;
    std::cin.ignore();
    std::cin >> a1.nota;

    avalia(&a1);

    return 0;

}