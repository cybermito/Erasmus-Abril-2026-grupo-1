#include <iostream>
#include <random>

int main(){
    //Inicializamos chispa y arranque
    std::random_device rd;
    std::mt19937 generador(rd());
    //molde generador
    std::uniform_int_distribution<int> rueda(1, 7);
    
    //Creamos las constantes
    const int NUM_RUEDAS = 3;

    //Inicializamos variables
    int valor_ruedas[] = {0, 0, 0};
    bool jackpot = true;
    int valor_jatckpot = 7; //Para comprobar si todos los valores de la lista son 7 y poder escalar el programa con más ruedas.
    

    for (int i = 0; i < NUM_RUEDAS; i++){
        valor_ruedas[i] = rueda(generador);
        std::cout << valor_ruedas[i] << std::endl;
    }

    for (int i = 0; i < NUM_RUEDAS; i++){
        //Comprobamos si todos los valores son 7
        if (valor_ruedas[i] != valor_jatckpot){
            jackpot = false;
            break;
        }
    }

    if (jackpot){
        std::cout << "¡JACKPOT! 💰" << std::endl;
    } else {
        std::cout << "Intentalo de nuevo..." << std::endl;
    }

    /*
    //Esta comparación es valida para 3 ruedas, pero si queremos añadir ruedas, lo grabado es lo ideal. 
    if ((valor_ruedas[0] == 7) && (valor_ruedas[1] == 7) && (valor_ruedas[2] == 7)) {
        std::cout << "¡JACKPOT! 💰" << std::endl;

    } 
    */


}