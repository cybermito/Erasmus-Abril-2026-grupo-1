/*
 * ¿Preparad@ para aprender o repasar el lenguaje de programación que tú quieras?
 * - Recuerda que todas las instrucciones de participación están en el
 *   repositorio de GitHub.
 *
 * Lo primero... ¿Ya has elegido un lenguaje?
 * - No todos son iguales, pero sus fundamentos suelen ser comunes.
 * - Este primer reto te servirá para familiarizarte con la forma de participar
 *   enviando tus propias soluciones.
 *
 * EJERCICIO:
 * - Crea un comentario en el código y coloca la URL del sitio web oficial del
 *   lenguaje de programación que has seleccionado.
 * - Representa las diferentes sintaxis que existen de crear comentarios
 *   en el lenguaje (en una línea, varias...).
 * - Crea una variable (y una constante si el lenguaje lo soporta).
 * - Crea variables representando todos los tipos de datos primitivos
 *   del lenguaje (cadenas de texto, enteros, booleanos...).
 * - Imprime por terminal el texto: "¡Hola, [y el nombre de tu lenguaje]!"
 *
 * ¿Fácil? No te preocupes, recuerda que esta es una ruta de estudio y
 * debemos comenzar por el principio.
 */

 #include <iostream>
 #include <string>

 using namespace std;

 int main(){
    //En C/C++ esto es un comentario de una sola línea
    /*
    * De esta manera se hace un comentario 
    * de varias líneas.
    * El lenguaje seleccionado como se podrá ver es C/C++
    * URL: https://isocpp.org/
    */

    //La variables se crean indicando el tipo de dato, nombre de la variable = valor de la variable;
    // int number = 0;
    //Las constantes se crean primero indicando const tip de dato y nombre de variable asignando su valor. 
    const float PI = 3.1416;
    cout << "Variable constante PI: " << PI << endl;

    //tipos de datos principales, ya que C/C** tiene bastantes
    int entero = 10;
    cout << "Variable tipo int: " << entero << endl;

    float decimal = 2.654;
    cout << "Variable tipo float: " << decimal << endl;

    double decimalPrecisionDoble = 3.1415942523525262;
    cout << "Variable tipo double (es un decimal de doble precisión, capaz de contener mayor número de decimales): " << decimalPrecisionDoble << endl;

    bool boolean = true;
    cout << "Variable tipo Boolean (true, false): " << boolean << endl;

    char letra = 'A';
    cout << "Variable de tipo char (un solo carácter): " << letra << endl;

    //Una cadena de texto como tipo de dato no exite directamente en C/C++
    // Se podría crear, generando una lista de caracteres
    char cadena[] = { 'H', 'o', 'l', 'a'};
    cout << "Cadena generada con una variable tipo lista: " << cadena << endl;

    // Para representar una cadena de texto hay que usar una librería llamada string
    string cadena2 = "Hola, C/C++";
    cout << "Variable tipo string: \n" << cadena2 << endl;

    /*
    Notas finales:

    El lenguaje C++ tiene una gran cantidad de tipos de datos elementales, yo he puesto los más
    utilizados, pero aquí hago un resumen de los que he encontrado en un libro y documentación.

    char, bool, signed char, unsigned char, int, signed int, unsigned int, short, signed short,
    unsigned short, log, signed long, unsigned long, long long, signed long long, unsigned long long,
    float, double, long double.
    */
 }