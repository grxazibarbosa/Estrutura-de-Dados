/*Essa atividade define uma função recursiva chamada degraus que calcula o número de maneiras de subir uma escada com n degraus,
onde só é permitido subir 1 ou 3 degraus por vez. A lógica é: para chegar no degrau n, 
você pode ter vindo do degrau n-1 (subindo 1 degrau) ou do n-3 (subindo 3 degraus), 
então a função retorna a soma dessas duas possibilidades. A base da recursão é:

Se n == 0, há 1 forma válida (ficar parado no chão).

Se n < 0, há 0 formas válidas (passou do limite).

*/


#include <iostream>

int degraus(int n) {
    if (n == 0) {
        return 1;
    }
    if (n < 0) {
        return 0;
    }
    return degraus(n - 1) + degraus(n - 3);
}

int main() {
    int n;
    std::cin >> n; 

    std::cout << degraus(n) << std::endl;
}
//procurar entendera
