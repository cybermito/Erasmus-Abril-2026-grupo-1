#include <iostream>
#include <vector>

int main() {
    int n;
    std::cout << "Introduce el número de términos de la serie Fibonacci: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Por favor, introduce un número entero positivo." << std::endl;
        return 1;
    }

    std::vector<long long> fib(n);
    fib[0] = 0;

    if (n > 1) {
        fib[1] = 1;
    }

    for (int i = 2; i < n; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    std::cout << "Serie Fibonacci (" << n << " términos):" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << fib[i];
        if (i + 1 < n) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;

    return 0;
}
