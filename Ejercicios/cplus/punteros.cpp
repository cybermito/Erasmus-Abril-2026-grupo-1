/* Algoritmo para entender los punteros */
/* Este enlace es un vídeo donde explican los punteros:
    https://www.youtube.com/watch?v=s8T7cPnYrz0
*/

#include <iostream>

using namespace std;

int main(){
    int number = 2021; //Creamos una variable de tipo int con valor 2021
    int *puntero = &number; //Creamos un puntero al que le asignamos la dirección de memoria
    // de la variable number.

    cout << "Valor de la variable number: " << number << endl;
    cout << "Dirección de memoria de la variable number: " << &number << endl;
    cout << "Dirección de la variable puntero: " << &puntero << endl;
    cout << "Dirección de memoria a la que apunta el puntero: " << puntero << endl;
    cout << "Valor del contenido de la dirección de memoria a la que apunta el puntero: " << *puntero << endl;

    // cambiando el valor del contenido de la variable desde el puntero
    *puntero = 1974;

    //Mostrando el nuevo valor
    cout << "Nuevo valor de la variable number: " << number;
}