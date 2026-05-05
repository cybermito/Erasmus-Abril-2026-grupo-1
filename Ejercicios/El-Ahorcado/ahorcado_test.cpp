#include "ahorcado.h"
#include <algorithm>
#include <cassert>
#include <iostream>
#include <random>

int main() {
    // Pruebas para crearOculto
    assert(crearOculto(0).empty());
    assert(crearOculto(5) == "_____");

    // Pruebas para actualizaOculto
    std::string oculto = crearOculto(4);
    bool encontrado = actualizaOculto("casa", 'a', oculto);
    assert(encontrado);
    assert(oculto == "_a_a");

    oculto = crearOculto(4);
    encontrado = actualizaOculto("hola", 'x', oculto);
    assert(!encontrado);
    assert(oculto == "____");

    // Pruebas para esLetraValida
    assert(esLetraValida('a'));
    assert(esLetraValida('z'));
    assert(!esLetraValida('1'));
    assert(!esLetraValida(' '));

    // Pruebas para palabraCompleta
    assert(palabraCompleta("hola", "hola"));
    assert(!palabraCompleta("hola", "h_la"));

    // Pruebas para seleccionarPalabraAleatoria
    std::vector<std::string> palabras = obtenerPalabras();
    std::mt19937 rng(123);
    std::string palabraElegida = seleccionarPalabraAleatoria(palabras, rng);
    assert(std::find(palabras.begin(), palabras.end(), palabraElegida) != palabras.end());

    std::cout << "Todos los tests han superado correctamente." << std::endl;
    return 0;
}
