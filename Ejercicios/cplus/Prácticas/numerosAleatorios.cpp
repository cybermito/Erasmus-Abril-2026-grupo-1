/* Prácticas de generación de números aleatorios */
/* Imagina que estás programando un videojuego de rol (RPG). Tienes un personaje que ataca y:

- Un golpe normal hace entre 10 y 20 de daño.

- Pero hay una probabilidad crítica: a veces el motor debe decidir si el golpe es especial.

- Aquí va un ejercicio para ti. Intenta escribir (o explicarme la lógica) de cómo harías lo siguiente:

        - Crea un motor mt19937.

        - Crea un molde para el daño (de 10 a 20).

El reto: Necesito que generes 5 ataques seguidos usando un bucle for.

Pregunta de examen de maestro: ¿Qué pasaría si en lugar de usar std::uniform_int_distribution<int>, intentáramos usar el viejo
 truco de C de hacer motor() % 10? (Pista: Piensa en si todos los números tendrían la misma oportunidad de salir, como en una
 fila de niños donde los últimos se quedan sin caramelos).*/

#include <iostream>
#include <random>

int main(){

    int fuerzaAtaque = 0;
    //1. El chispazo (se llama rd)
    std::random_device rd;

    //2. El motor (le pasamos el chispazo para que arranque)
    std::mt19937 motor(rd());

    // El molde (queremos números entre 1 y 10 por ejemplo)
    std::uniform_int_distribution<int> ataque(10, 20);

    /* //¡A generar! Usamos el molde con nuestro motor generador de números aleatorios
    int randomNumber = molde(motor);

    std::cout << "Tú número es: " << randomNumber << std::endl; */

    // Reto: Generar 5 números aleatorios usando un bucle

    for (int i = 0; i < 5 ; i++){
        fuerzaAtaque = ataque(motor);
        std::cout << "Ataque número " << i + 1 << std::endl;
        std::cout << "Fuerza de ataque: " << fuerzaAtaque << std::endl;
        std::cout << std::endl;
    }
}