/* Algoritmo que pida una palabra y te devuelva el número de letras que tiene */

#include <iostream>
#include <string>

using namespace std;

int main(){
    string palabra = " ";
    int totalLetras = 0;

    // Solicitamos la palabra al usuario
    cout << "Escribe una palabra: ";
    cin >> palabra;
    cout << "La palabra ";
    cout << palabra;
    cout << " tiene: ";
    totalLetras = palabra.length();
    cout << totalLetras;
    cout << " letras." << endl;
}