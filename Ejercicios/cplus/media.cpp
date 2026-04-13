#include <iostream>

int main() {
    int n;
    std::cout << "¿Cuántos números vas a introducir? ";
    std::cin >> n;

    if (n <= 0) {
        std::cerr << "El número de valores debe ser positivo.\n";
        return 1;
    }

    double suma = 0.0;
    double valor;

    std::cout << "Introduce los " << n << " números:\n";
    for (int i = 0; i < n; ++i) {
        std::cin >> valor;
        suma += valor;
    }

    double media = suma / static_cast<double>(n);
    std::cout << "La media es: " << media << '\n';

    return 0;
}
