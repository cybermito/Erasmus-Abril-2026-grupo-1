/* Juego Adivina el número */

#include <iostream>
#include <string>
#include <random> //librería para generar números aleatorios

std::string guesses = "Intentos anteriores: "; //Inicializamos la cadena para presentar los valores ingresados por el usuario. 

/* Función presentación*/
void presentation(void){
    std::cout << "*********************" << std::endl;
    std::cout << "* ADIVINA EL NÚMERO *" << std::endl;
    std::cout << "*********************" << std::endl;
    std::cout << std::endl;

    std::cout << "Tengo un número del 1 al 100." << std::endl;
    std::cout << "Intenta adivinarlo en 10 intentos." << std::endl;
    std::cout << "Se ayudará indicando si el número es mayor o menor al escrito.";
    std::cout << std::endl;
    std::cout << std::endl;

}

int main(){
        
    int initialNumber = 1; //Rango de valores para número aleatorio
    int finalNumber = 100;
    int randomNumber = 0; //Número aleatorio generado posteriormente. 
    int userGuess = -1; //Número introducido por el usuario.
    int guessCount = 1; //Número de intentos.


    // Inicializamos el contacto para arrancar y el arranque para los números aleatorios
    // Damos el contacto y lo llamamos rd.
    std::random_device rd;

    // Le pasamos el chispazo de arranque al motor
    std::mt19937 motor(rd());

    // Creamos el rango de números a utilizar en el azar
    std::uniform_int_distribution<int> rango(initialNumber, finalNumber);

    // Generamos el número aleatorio
    randomNumber = rango(motor);

    presentation();

    /*
    //Esta parte es para comprobar que se está generando el número aleatorio
    std::cout << "El rango de números aleatorios está entre " << initialNumber;
    std::cout << " y " << finalNumber << std::endl;
    std::cout << "El número aleatorio es: " << randomNumber << std::endl;
    std::cout << std::endl;
    //fin comprobación
    */

    
    while(userGuess != 0){
        std::cout << "Introduce un número (0 para finalizar juego): ";
        std::cin >> userGuess;
        std::cout << std::endl;

        //Sacamos por pantalla los números escritos y los intentos
        guesses.append(std::to_string(userGuess) + " ");
        std::cout << guesses << std::endl;
        std::cout << "Intento número: " << guessCount << std::endl;
        std::cout << std::endl;

        if (userGuess == randomNumber){
            std::cout << "*********************" << std::endl;
            std::cout << "*    ¡ACERTASTE!    *" << std::endl;
            std::cout << "*********************" << std::endl;
            break;
        } else if(guessCount == 10){
            std::cout << "**********************" << std::endl;
            std::cout << "*  Ohh, ¡GAME OVER!  *" << std::endl;
            std::cout << "**********************" << std::endl;
            break;
        } else if (userGuess > randomNumber){
            std::cout << "El número es menor..." << std::endl;
        } else {
            std::cout << "El número es mayor..." << std::endl;
        }      

        //Incrementamos intentos para el siguiente turno
        guessCount++;
        
    }

    std::cout << "Juego finalizado, ¡Hasta luego!";
    std::cout << std::endl << std::endl;


}