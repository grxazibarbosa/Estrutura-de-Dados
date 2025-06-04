/******************************************************************************
 *      GRAZIELE FERREIRA BARBOSA
 *      MATRÍCULA : 554184
 ******************************************************************************
 */

#include <iostream>
#include "Sparse_matriz.h"
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

//função que recebe duas matrizes e gera uma terceira matriz com o
//resultado da soma das duas matrizes
Sparse_matriz somar(Sparse_matriz& A, Sparse_matriz& B){
    if((A.get_linha() != B.get_linha()) || (A.get_coluna() != B.get_coluna())){
        throw "linha ou coluna diferente";
    }

    Sparse_matriz C(A.get_linha(), A.get_coluna());

    for(int i = 1; i <= A.get_linha(); i++){
        for(int j = 1; j <= A.get_coluna(); j++){
            C.inserir(i, j, A.get(i, j) + B.get(i, j));
        }
    }

    return C;
          
}
//função que recebe duas mattrizes e gera uma terceira matriz com o
//resultado da multiplicaçãodas duas matrizes
Sparse_matriz multiplicar(Sparse_matriz& A, Sparse_matriz& B){
    if(A.get_coluna() != B.get_linha()){
        throw "nao da pra multiplicar '-'";
    }

    Sparse_matriz C(A.get_linha(), B.get_coluna());

    for(int i = 1; i <= A.get_linha(); i++){
        for(int j = 1; j <= B.get_coluna(); j++){
            for(int k = 1; k <= A.get_coluna(); k++){
                double result = C.get(i, j);
                result += A.get(i, k) * B.get(k, j);

                C.inserir(i, j, result);
            }
        }
    }

    return C;

}

//função que le arquivo
void ler(Sparse_matriz& m, std::string nome_arquivo){
    std::ifstream arquivo(nome_arquivo);

    if (!arquivo) {
        std::cerr << "Erro ao abrir o arquivo!\n";
        return;
    }

    std::string linha_arquivo;
    //ler primeira linha do arquivo
    std::getline(arquivo, linha_arquivo);

    std::stringstream ss(linha_arquivo);

    int linha, coluna;
    ss >> linha >> coluna;
    m.redimensiona(linha, coluna);

    while (std::getline(arquivo, linha_arquivo)) { // Lê linha por linha
        std::stringstream grazi(linha_arquivo);

        double valor;
        grazi >> linha >> coluna >> valor;

        m.inserir(linha, coluna, valor);
    }
    arquivo.close();
}

int main() {

    std::string line;
    while(true){
        
        std::cout << "\nescolhas as opcoes de operacao: " << std::endl;
        std::cout << "1.inserir \n2.pegar \n3.somar \n4.multiplicar \n5.imprimir\n5.end(para encerrar)" << std::endl;
        std::cout << "\n ******** formatos de entrada *********\n" << std:: endl;
        std::cout << "Para inserir, escreva o seguinte formato de entrada: 'inserir nome_do_arquivo.txt' \n " << std::endl;
        std::cout << "Para pegar o elemento da matriz, escreva o seguinte formato de entrada:'pegar nome_do_arquivo.txt linha coluna' \n " << std::endl;
        std::cout << "Para somar duas matrizes, escreva dois arquivos com matriz:'somar nome_do_arquivo.txt nome_do_arquivo_2.txt' \n " << std::endl;
        std::cout << "Para multiplicar duas matrizes, escreva dois arquivos com matriz:'somar nome_do_arquivo.txt nome_do_arquivo_2.txt' \n " << std::endl;
        std::cout << "Para exibir a matriz no terminal, escreva o seguinte formato de entrada: 'imprimir nome_do_arquivo.txt' \n " << std::endl;
        std::cout << "Para encerrar o programa, escreva o seguinte formato de entrada: 'end' \n " << std::endl;

        getline(std::cin, line);
        std::stringstream ss(line);
        std::string grazi; 
        ss >> grazi;

        if(grazi == "end"){
            return 0;
        }
        //Ex de entrada:
        //Inserir nome_do_arquivo.txt
        else if(grazi == "inserir"){
            std::string grazi_2;
            ss >> grazi_2;

            Sparse_matriz matriz;
            ler(matriz, grazi_2);

            matriz.print();
            std::cout << "\n";
        }
        //ex de entrada:
        //pegar nome_do_arquivo.txt linha coluna 
        //pegar m4.txt 1 1
        else if(grazi == "pegar"){
            int linha, coluna;
            std::string arq_mat;
            ss >> arq_mat >> linha >> coluna;
    
            Sparse_matriz new_matriz;
            ler(new_matriz, arq_mat);
            try{
                std::cout << "\nresultado: ";
                std::cout << new_matriz.get(linha, coluna) << std::endl;
                std::cout << "\n";
            }catch (const char* e) {
                std::cerr << "Erro: " << e << "\n "<< std::endl;
            } 
            
        }
        //ex de entrada:
        //somar nome_do_arquivo.txt nome_do_arquivo.txt
        //somar m1.txt m1.txt
        else if(grazi == "somar"){
            std::string arq_mat1, arq_mat2;
            ss >> arq_mat1 >> arq_mat2;

            Sparse_matriz mat1, mat2;
            ler(mat1, arq_mat1);
            ler(mat2, arq_mat2);

            try{
                Sparse_matriz new_matriz = somar(mat1, mat2);
                std::cout << "\nresultado:\n"<<std::endl;
                new_matriz.print();
                std::cout << "\n";
            }catch (const char* e) {
                std::cerr << "Erro: " << e << "\n "<< std::endl;
            } 
        }
        //ex de entrada:
        //somar nome_do_arquivo.txt nome_do_arquivo.txt
        //multiplicar m2.txt m2.txt
        else if(grazi == "multiplicar"){
            std::string arq_mat1, arq_mat2;
            ss >> arq_mat1 >> arq_mat2;

            Sparse_matriz mat1, mat2;
            ler(mat1, arq_mat1);
            ler(mat2, arq_mat2);
            try{
                Sparse_matriz new_matriz = multiplicar(mat1, mat2);
                std::cout << "\nresultado:\n"<<std::endl;
                new_matriz.print();
                std::cout << "\n";
            }catch (const char* e) {
                std::cerr << "Erro: " << e << "\n "<< std::endl;
            } 
        }
        //ex de entrada:
        //imprimir nome_do_arquivo.txt
        else if(grazi == "imprimir"){
            std::string arq_mat;
            ss >> arq_mat;

            Sparse_matriz new_matriz;
            ler(new_matriz, arq_mat);

            new_matriz.print();
            std::cout << "\n";
        }
        else {
            std::cout << "comando invalido\n";
        }
    }

    return 0;
}


