#include <iostream>
#include <string>

using namespace std;

//Definición de estructura

struct Persona
{
    string nombre;
    int edad;
};


int main(){
    //Hay dos formas de instanciar la estructura, puede ser como variable
    //o como punteros. La primera reserva la memoria en compilación,
    //la segunda forma (con punteros), reserva la memoria dinámicamente.

    /* Forma 1: como variable, memoria reservada en compilación */
    Persona yo = Persona();
    yo.nombre = "Antonio"; //Accedo a los valores con la notación "."
    yo.edad = 51;

    cout << yo.nombre << endl;
    cout << yo.edad << endl;

    /* Forma 2: con punteros, memoria reservada dinámicamente en ejecución. */

    Persona *amore = new Persona();
    amore->nombre = "Nuria"; //Accedo a los campos con la notación flecha "->"
    amore->edad = 48;

    cout << amore->nombre << endl;
    cout << amore->edad << endl;

    
}