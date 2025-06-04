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
