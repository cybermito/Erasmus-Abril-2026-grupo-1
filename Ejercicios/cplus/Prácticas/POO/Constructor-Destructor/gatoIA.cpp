/* Este ejemplo / práctica esta realizada como seguimiento de los ejercicios marcados por Gemini Gem */
#include <iostream>
#include <string>

class Gato{

    public:
        //Constructor
        Gato(){
            std::cout << "¡Miau! He nacido" << std::endl;
        }
        //Destructor
        ~Gato(){

            std::cout << "Me voy a dormir la siesta... zzz" << std::endl;

        }

};

int main(){
    std::cout << "--- Inicio del día ---" << std::endl;
    
    {// Esto es un bloque, como una habitación pequeña
        Gato miGato;
        // Aquí el gato vive y juega...
    }// <-- ¿Qué crees que pasa con el gato justo en este cierre de llave? Respuesta: se ejecuta el destructor y finaliza el objeto
    // liberando la memoria.
    
    std::cout << "--- Fin del día ---" << std::endl;
    return 0;
}