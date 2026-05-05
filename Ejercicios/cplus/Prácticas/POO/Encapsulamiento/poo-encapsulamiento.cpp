//Encapsulamiento

#include <iostream>
#include <string>

class Persona{
    private:
    //Hacemos los atributos privados y solo se pueden modificar desde dentro de la clase con los métodos
    //atributos / propiedades del objeto, por defecto son privadas
    //con public: las hacemos accesibles al exterior.
    std::string nombre;
    int edad;

    public:

        //Constructor de clase
        //Asignación básica o normal
        /* Persona(std::string name, int age){
            nombre = name;
            edad = age;
        } */

        //Constructor de clase con asignación inline
        Persona(std::string name, int age) : nombre(name), edad(age) {}

        //Destructor de clase, liberar la memoria.
        //Se ejecuta al finalizar un bloque de código delimitado por {} o
        //si no está el bloque delimitado, se ejecuta al finalizar el main.

        ~Persona(){
            std::cout << "Liberando memoria del objeto indicado" << std::endl;
        }

        void cambiarNombre(std::string nuevoNombre){
            nombre = nuevoNombre;
        }

        void cambiarEdad(int nuevaEdad){
            edad = nuevaEdad;
        }

        //Acciones / métodos del objeto, con un solo método puedo usarlo en todos los objetos que cree.
        void saludar(){
            std::cout << "Hola, mi nombre es " << nombre << " y tengo " << edad << " años. " << std::endl;
        }

};

int main(){
    //Instanciación objeto persona usando memoria estática y sin punteros.
    //Se reserva la memoria en tiempo en la compilación
    Persona p = Persona("Antonio", 51);
    //p.nombre = "Antonio"; //No se puede modificar estos atributos ya que son privados
    //p.edad = 51; //Debemos usar los métodos modificadores creados.
    //std::cout << p.nombre << std::endl; 
    //std::cout << p.edad << std::endl; 
    p.saludar();
    p.cambiarNombre("Luna");
    p.cambiarEdad(5);
    p.saludar();

    //Instanciación objeto persona usando memoria dinámica con punteros
    //Se reserva la memoria en tiempo de ejecución.
    Persona *p2 = new Persona("Amore", 48);
    //p2->nombre = "Amore";
    //p2->edad = 48;
    //delete p2; //Elimina el objeto p2 liberando así la memoria de manera manual, no espera a finalizar el bloque
    //std::cout << p2->nombre << std::endl;
    //std::cout << p2->edad << std::endl;
    p2->saludar();

}