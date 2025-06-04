/*#include <iostream>

int Cont_caract(char F[], char letra){
    int cont{};
    if()
}

int main(){
    char frase[100];
    std::cin.getline(frase, 100);
    char caractere;
    std::cin >> caractere;

    Cont_caract(frase, caractere);

}*/

#include <iostream>
#include <string>

using namespace std;

//using namespace std;

// Retorna o números de ocorrências do caractere 'c' na string 'str' (com 'n' caracteres).
// Algoritmo deve ser recursivo e sem comandos de repetição.
int contaCaracteres(string str, int n, char c)
{
   // int cont{};
    if(n == 0){
        return 0;
    }else{
        if(str[n-1] == c){
            return 1 + contaCaracteres(str, n-1, c);
        }else{
            return contaCaracteres(str, n-1, c);
        }
    }
}

int main() 
{
    std::string frase;
    std::getline(std::cin, frase);
    char caractere;
    std::cin >> caractere;

    int tam = frase.size();

    //contaCaracteres(frase, tam, caractere);

    cout << contaCaracteres(frase, tam, caractere) << endl;
}