/* Reto: Realizar el juego del ahorcado */

#include <iostream>
#include <string>
#include <random>

std::string PALABRAS[] = { "uno","vino","pera","verano","enemigo","palabra","diccionario","extraño","starwars", "supercalifragilisticoespialidoso" };
std::string IMAGES[] = {"******\n|\n|\n|\n|\n=======\n", "******\n|   |\n|\n|\n|\n=======\n", "******\n|   |\n|   o\n|\n|\n=======\n", "******\n|   |\n|   o\n|  /\n|\n=======\n", "******\n|   |\n|   o\n|  /O\n|\n=======\n", "******\n|   |\n|   o\n|  /O\\\n|\n=======\n", "******\n|   |\n|   o\n|  /O\\\n|  /\n=======\n", "******\n|   |\n|   o\n|  /O\\\n|  / \\\n=======\n"};

int main(){
    
    //Calculo el tamaño de la lista PALABRAS
    int sizelista = (sizeof(PALABRAS)/sizeof(std::string));
    /* //test que recorre toda la lista de palabras
    for (int i = 0; i < sizelista; i++){
        std::cout << PALABRAS[i] << std::endl;
    }
    */
    /* Comprobación de los dibujos para el juego.
    for (int i = 0; i < 9; i++){
        std::cout << IMAGES[i] << std::endl;
    }
    */

    int randomNumber = 0;
    std::string palabra = " ";
    int sizeWord = 0;
    int intentos = (sizeof(IMAGES)/sizeof(std::string)-1);
    int aciertos = 0;
    std::cout << "Número de intentos: " << intentos << std::endl;
    char letra = ' ';
    bool letterFound = false;

    //Inicializamos el cálculo del valor aleatorio
    std::random_device rd; //recordamos que es la llave de contacto
    std::mt19937 generador(rd()); //La chispa que enciende el motor generador de números
    std::uniform_int_distribution<int> molde(0, (sizelista - 1)); //Creamos el molde para limitar el rango de números
    //Fin inicialización molde generador de números aleatorios

    //Seleccionamos la palabra aleatoria de la lista
    randomNumber = molde(generador);
    palabra = PALABRAS[randomNumber];
    std::cout << "Número aleatorio: " << randomNumber << std::endl;
    std::cout << "Palabra aleatoria: " << palabra << std::endl;

    //Dibujamos el tamaño de la palabra con "_";
    sizeWord = palabra.length(); //Tomamos el tamaño de la palabra seleccionada.
    std::cout << "Tamaño de la palabra en caracteres: " << sizeWord << std::endl << std::endl;
    std::string palabraOculta(sizeWord, '_'); //inicializa el string con el tamaño de la palabra y rellena con el símbolo indicado. 

    //Dibujamos el primer elemento de las imágenes
    std::cout << IMAGES[0] << std::endl;
    std::cout << "La palabra es: " << palabraOculta << std::endl;
    std::cout << std::endl;
    //Fin dibujar palabra oculta


    /* Lógica para adivinar la palabra */
    /*
        ToDo:
        - Comprobar si hemos completado la palabra para felicitarnos
        - Comprobar si se han acabado los intentos "Game Over"

        Avanzado:
        - Dar la opción de si se sabe la palabra, escribirla entera y compararla.

        Ya comprueba y añade las letras que vamos encontrando.
    */
    while (intentos != 0){

        letterFound = false;
        std::cout << "Escribe una letra: ";
        std::cin >> letra;

        for (int i = 0; i < sizeWord; i++){
            if (letra == palabra[i]){
                palabraOculta[i] = letra;
                letterFound = true;
                aciertos++;
            }            
        }
        std::cout << "Letras acertadas: " << aciertos << std::endl;

        //ToDo: Intentar hacer la comparación, no por tamaño, si no por igualdad en las dos palabras, la oculta y la seleccionada.
        if (aciertos == sizeWord){
            std::cout << "Acertaste la palabra " << palabraOculta << std::endl;
            break;
        }

        if (!letterFound){
            intentos--;
            std::cout << "Número de intentos: " << intentos << std::endl;
        }
        std::cout << "La palabra es: " << palabraOculta << std::endl;
    }

}/* Reto: Realizar el juego del ahorcado */

#include <iostream>
#include <string>
#include <random>

std::string PALABRAS[] = { "uno","vino","pera","verano","eñe","palabra","diccionario","extraño","starwars" };
std::string IMAGES[] = {"******\n|\n|\n|\n|\n=======\n", "******\n|   |\n|\n|\n|\n=======\n", "******\n|   |\n|   o\n|\n|\n=======\n", "******\n|   |\n|   o\n|  /\n|\n=======\n", "******\n|   |\n|   o\n|  /O\n|\n=======\n", "******\n|   |\n|   o\n|  /O\\\n|\n=======\n", "******\n|   |\n|   o\n|  /O\\\n|  /\n=======\n", "******\n|   |\n|   o\n|  /O\\\n|  / \\\n=======\n"};

int main(){
    
    //Calculo el tamaño de la lista PALABRAS
    int sizelista = (sizeof(PALABRAS)/sizeof(std::string));
    /* //test que recorre toda la lista de palabras
    for (int i = 0; i < sizelista; i++){
        std::cout << PALABRAS[i] << std::endl;
    }
    */
    /* Comprobación de los dibujos para el juego.
    for (int i = 0; i < 9; i++){
        std::cout << IMAGES[i] << std::endl;
    }
    */

    int randomNumber = 0;
    std::string palabra = " ";
    int sizeWord = 0;
    int intentos = (sizeof(IMAGES)/sizeof(std::string)-1);
    std::cout << "Número de intentos: " << intentos << std::endl;
    char letra = ' ';
    bool letterFound = false;

    //Inicializamos el cálculo del valor aleatorio
    std::random_device rd; //recordamos que es la llave de contacto
    std::mt19937 generador(rd()); //La chispa que enciende el motor generador de números
    std::uniform_int_distribution<int> molde(0, (sizelista - 1)); //Creamos el molde para limitar el rango de números
    //Fin inicialización molde generador de números aleatorios

    //Seleccionamos la palabra aleatoria de la lista
    randomNumber = molde(generador);
    palabra = PALABRAS[randomNumber];
    std::cout << "Número aleatorio: " << randomNumber << std::endl;
    std::cout << "Palabra aleatoria: " << palabra << std::endl;

    //Dibujamos el tamaño de la palabra con "_";
    sizeWord = palabra.length(); //Tomamos el tamaño de la palabra seleccionada.
    std::cout << "Tamaño de la palabra en caracteres: " << sizeWord << std::endl << std::endl;
    std::string palabraOculta(sizeWord, '_'); //inicializa el string con el tamaño de la palabra y rellena con el símbolo indicado. 

    //Dibujamos el primer elemento de las imágenes
    std::cout << IMAGES[0] << std::endl;
    std::cout << "La palabra es: " << palabraOculta << std::endl;
    std::cout << std::endl;
    //Fin dibujar palabra oculta


    /* Lógica para adivinar la palabra */
    /*
        Pendiente:
        - Comprobar si hemos completado la palabra para felicitarnos
        - Comprobar si se han acabado los intentos "Game Over"

        Ya comprueba y añade las letras que vamos encontrando.
    */
    while (intentos != 0){

        letterFound = false;
        std::cout << "Escribe una letra: ";
        std::cin >> letra;

        for (int i = 0; i < sizeWord; i++){
            if (letra == palabra[i]){
                palabraOculta[i] = letra;
                letterFound = true;
            }            
        }

        if (!letterFound){
            intentos--;
            std::cout << "Número de intentos: " << intentos << std::endl;
        }
        std::cout << "La palabra es: " << palabraOculta << std::endl;
    }

}