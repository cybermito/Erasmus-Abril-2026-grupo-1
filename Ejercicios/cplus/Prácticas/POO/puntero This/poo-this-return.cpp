//Puntero this.
//El puntero this permite e indica que el objeto y datos puedan acceder a si mismos.

#include <iostream>
#include <string>

class Persona{
    //Hacemos los atributos privados y solo se pueden modificar desde dentro de la clase con los métodos
    std::string nombre;
    int edad;

    public:

        //Constructor de clase
        Persona(std::string nombre, int edad){ //Evitamos la desambiguación de las variables.
            this->nombre = nombre;
            this->edad = edad;
        }

        //Constructor de clase con asignación inline
        //Persona(std::string name, int age) : nombre(this->nombre), edad(this->edad) {}

        //Destructor de clase, liberar la memoria.
        //Se ejecuta al finalizar un bloque de código delimitado por {} o
        //si no está el bloque delimitado, se ejecuta al finalizar el main.
        ~Persona(){
            std::cout << "Liberando memoria del objeto indicado" << std::endl;
        }

        //Podemos retornar el puntero this y de ese modo encadenar llamadas a métodos.
        Persona &establecerNombre(std::string nuevoNombre){ //Indicamos que el tipo de dato que devuelve es un objeto Persona
            this->nombre = nuevoNombre;
            return *this;
        }

        Persona &establecerEdad(int nuevaEdad){ //Indicamos que el tipo de dato que devuelve es un objeto Persona
            this->edad = nuevaEdad;
            return *this;
        }

        //Acciones / métodos del objeto, con un solo método puedo usarlo en todos los objetos que cree.
        void saludar(){
            std::cout << "Hola, mi nombre es " << nombre << " y tengo " << edad << " años. " << std::endl;
        }

};

int main(){
    //Instanciación objeto persona usando memoria estática y sin punteros.
    //Se reserva la memoria en tiempo en la compilación
    Persona persona = Persona("Antonio", 51);

    //Al tener de retorno el valor del objeto, podemos encadenar llamadas a métodos
    persona.saludar();
    persona.establecerNombre("Luna").establecerEdad(5).saludar();

    //Instanciación objeto persona usando memoria dinámica con punteros
    //Se reserva la memoria en tiempo de ejecución.
    Persona *p2 = new Persona("Amore", 48);

    p2->saludar();

}