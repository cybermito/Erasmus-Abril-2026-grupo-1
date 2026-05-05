#include <iostream>
#include <string>

//Creamos la clase principal de la que heredarán las siguientes
class Animal{
    protected: //Son datos privados innaccesibles desde fuera de la clase, salvo por herencia.
        static int numeroAnimales; //Para llevar la cuenta y control del número de instancias creadas.
        std::string alimento; // = "vegetales"; //Podemos indicar valores por defecto.
    public:
        //Construcctor de clase estático, se define fuera de la clase
        Animal();
        //Desctructor
        ~Animal();
        //Método para controlar y visualizar el número de instancias creadas.
        static int obtenerNumeroAnimales();
        //Método compartido en la herencia
        std::string obtenerAlimento(){
            return alimento;
        }
        //Hacemos que comer reciba un objeto de tipo Animal para practicar otra forma de polimorfísmo.
        void comer(Animal *animal){
            std::cout << "Este animal está comiendo " << animal->alimento << " ...ñam ñam." << std::endl;
        }
};

//Clase que hereda de Animal
//Por defecto en la herencia, si no se indica lo contrario, los datos son privados.
class Herbivoro : public Animal{
    public:
        //creamos los modificadores
        //Constructor, a la hora de crearlo, también tenemos que indicar la herencia del constructor de la clase principal.
        //Para poder acceder a los atributos privados de la clase principal, debemos, en esta, indicar protected.
        Herbivoro() : Animal(){
            this->alimento = "vegetales";
        }

        void pastar(){
            std::cout << "Este animal está pastando en el campo..." << std::endl;
        }
};

class Carnivoro : public Animal{
    public:
        Carnivoro() : Animal(){
            this->alimento = "carne";
        }

        void cazar(){
            std::cout << "Este animal caza otros animales..." << std::endl;
        }
};

//Herencia multiple, heredar de dos o más clases
class Omnivoro : public Carnivoro, public Herbivoro{
    public:
        //El constructor debemos declararlo de la misma manera, haciendo referencia a las dos clases de las que hereda.
        Omnivoro() : Carnivoro(), Herbivoro(){}

        //Reescribimos el método comer() para que se comporte de otra manera.
        void comer(){
            std::cout << "Este animal come casi de todo..." << std::endl;
        }
};

//Definimos los atributos y métodos static para poder acceder a los valores private o protected
int Animal::numeroAnimales = 0;

Animal::Animal(){
    //Constructor
    std::cout << "Creando un nuevo Animal..." << std::endl;
    numeroAnimales += 1;
}

Animal::~Animal(){
    //Destructor
    std::cout << "Borrando instancia del Animal seleccionado..." << std::endl;
    numeroAnimales -= 1;
}

int Animal::obtenerNumeroAnimales(){
    return numeroAnimales;
}

//Fin declaración atributos y métodos static de la clase Animal.

int main(){

    //Creamos una nueva instancia de la clase Animal.
    Animal *animal = new Animal();
    Herbivoro *vaca = new Herbivoro();
    Carnivoro *tigre = new Carnivoro();
    Omnivoro *humano = new Omnivoro();

    std::cout << "Número de animales: " << Animal::obtenerNumeroAnimales() << std::endl;

    //animal->comer(); //Llámamos al método de clase de nuestra instancia, en este caso daría error, porque hemos modificado la
    //estructura del método de la clase base.
    //Al modificar el método base, cambia la forma de usarlo y/o llamar a dicho método
    vaca->pastar();
    //vaca->comer();
    animal->comer(vaca);//Le pasamos al método comer la instancia del objeto a utilizar.
    tigre->cazar();
    //tigre->comer();
    animal->comer(tigre);

    std::cout << "Humano: " << std::endl;
    //humano->comer(); //Lanza error porque no sabe cuál de los dos métodos comer puede usar en esta herencia múltiple.
    //Hay ambigüedad, sin embargo podemos especificar como queremos que se comporte
    //Esta sería una forma:
    //humano->Herbivoro::comer(); //Devuelve que come vegetales.
    //humano->Carnivoro::comer(); //Devuelve que come carne.
    //La forma siguiente, sería reescribiendo el método comer en la clase Omnívoro.
    humano->comer(); //Ahora lo podemos usar sin ambigüedad.


    delete animal; //Eliminamos la instancia creada, hace que se ejecute el destructor.
    std::cout << "Número de Animales: " << Animal::obtenerNumeroAnimales() << std::endl;
}