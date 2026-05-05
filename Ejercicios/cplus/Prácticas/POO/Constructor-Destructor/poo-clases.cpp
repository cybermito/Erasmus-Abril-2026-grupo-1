#include <iostream>
#include <string>

class Persona{
    public:
        //atributos / propiedades del objeto, por defecto son privadas
        //con public: las hacemos accesibles al exterior.
        std::string nombre;
        int edad;

        //Constructor de clase
        Persona(std::string name, int age){
            nombre = name;
            edad = age;
        }

        //Destructor de clase, liberar la memoria.
        //Se ejecuta al finalizar un bloque de código delimitado por {} o
        //si no está el bloque delimitado, se ejecuta al finalizar el main.

        ~Persona(){
            std::cout << "Liberando memoria del objeto indicado" << std::endl;
        }

        //Acciones / métodos del objeto
        void saludar(){
            std::cout << "Hola, mi nombre es " << nombre << std::endl;
        }

};

int main(){
    //Instanciación objeto persona usando memoria estática y sin punteros.
    //Se reserva la memoria en tiempo en la compilación
    Persona p = Persona("Antonio", 51);
    //p.nombre = "Antonio";
    //p.edad = 51;
    std::cout << p.nombre << std::endl;
    std::cout << p.edad << std::endl;
    p.saludar();

    //Instanciación objeto persona usando memoria dinámica con punteros
    //Se reserva la memoria en tiempo de ejecución.
    Persona *p2 = new Persona("Amore", 48);
    //p2->nombre = "Amore";
    //p2->edad = 48;
    //delete p2; //Elimina el objeto p2 liberando así la memoria de manera manual, no espera a finalizar el bloque
    std::cout << p2->nombre << std::endl;
    std::cout << p2->edad << std::endl;
    p2->saludar();

}