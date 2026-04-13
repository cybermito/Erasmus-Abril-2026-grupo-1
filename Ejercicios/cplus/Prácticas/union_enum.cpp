/* Práctica de uso de las uniones y los enum en c++ */
#include <iostream>
#include <string>

int main(){

    //Declaración de unión. (Los datos ocupan el mismo espacio de memoria)
    union numero_letra {
        int numero;
        char letra;
    };

    numero_letra x = {'A'};
    std::cout << "x como número: " << x.numero << std::endl;
    std::cout << "x como letra: " << x.letra << std::endl;

    //Enum. (comparten espacio de memoria un conjunto de finito de valores)
    /* sintaxis: enum nombre_enumeracion { conjunto, de, valores, separados, por, comas}
        El valor devuelto en la asignación será siempre númerico en base a un índice similar a las listas.
        Se le puede asignar un valor personalizado como en el ejemplo, entonces devolverá el valor númerico ASCII correspondiente
        Realizando casting podemos hacer que nos devuelva el carácter correspondiente.
    */

    enum dias_de_la_semana {lunes = 'L', martes = 'M', miercoles = 'X', jueves = 'J', viernes = 'V', sabado = 'S', domingo = 'D'};

    dias_de_la_semana dia = miercoles;

    std::cout << dia << std::endl; // Devuelve el valor numérico ASCII correspondiente al, en este caso, carácter indicado
    std::cout << (char)dia << std::endl; //Convierte el valor númerico al carácter correspondiente.

}