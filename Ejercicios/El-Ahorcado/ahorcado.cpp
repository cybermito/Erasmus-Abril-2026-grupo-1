#include "ahorcado.h"

#include <algorithm>
#include <cctype>
#include <iostream>
#include <random>
#include <set>
#include <string_view>

// Constante para el número máximo de intentos (basado en el tamaño de las imágenes ASCII)
constexpr int MAX_ATTEMPTS = 6;

/**
 * @brief Obtiene la lista de palabras disponibles para el juego del ahorcado.
 * @return Vector de strings con las palabras del juego.
 */
std::vector<std::string> obtenerPalabras() {
    return {
        "uno", "vino", "pera", "verano", "palabra", "diccionario",
        "extraño", "mariposa", "programa", "elefante", "computadora",
        "ciencia", "estrella", "música", "amigos"
    };
}

/**
 * @brief Obtiene las representaciones ASCII del ahorcado para cada estado.
 * @return Vector de strings con los dibujos ASCII.
 */
std::vector<std::string> obtenerAhorcado() {
    return {
        "  +---+\n"
        "  |   |\n"
        "      |\n"
        "      |\n"
        "      |\n"
        "      |\n"
        "=========\n",

        "  +---+\n"
        "  |   |\n"
        "  O   |\n"
        "      |\n"
        "      |\n"
        "      |\n"
        "=========\n",

        "  +---+\n"
        "  |   |\n"
        "  O   |\n"
        "  |   |\n"
        "      |\n"
        "      |\n"
        "=========\n",

        "  +---+\n"
        "  |   |\n"
        "  O   |\n"
        " /|   |\n"
        "      |\n"
        "      |\n"
        "=========\n",

        "  +---+\n"
        "  |   |\n"
        "  O   |\n"
        " /|\\  |\n"
        "      |\n"
        "      |\n"
        "=========\n",

        "  +---+\n"
        "  |   |\n"
        "  O   |\n"
        " /|\\  |\n"
        " /    |\n"
        "      |\n"
        "=========\n",

        "  +---+\n"
        "  |   |\n"
        "  O   |\n"
        " /|\\  |\n"
        " / \\  |\n"
        "      |\n"
        "=========\n"
    };
}

/**
 * @brief Crea una cadena oculta con guiones bajos del tamaño especificado.
 * @param longitud Longitud de la cadena oculta.
 * @return String con guiones bajos.
 */
std::string crearOculto(std::size_t longitud) {
    return std::string(longitud, '_');
}

/**
 * @brief Actualiza la cadena oculta revelando las letras encontradas.
 * @param palabra La palabra secreta.
 * @param letra La letra a buscar.
 * @param oculto La cadena oculta a actualizar (modificada por referencia).
 * @return true si la letra fue encontrada y actualizada, false en caso contrario.
 */
bool actualizaOculto(std::string_view palabra, char letra, std::string& oculto) {
    bool encontrada = false;
    for (std::size_t i = 0; i < palabra.size(); ++i) {
        if (palabra[i] == letra && oculto[i] == '_') {
            oculto[i] = letra;
            encontrada = true;
        }
    }
    return encontrada;
}

/**
 * @brief Verifica si un carácter es una letra válida (alfabética).
 * @param letra El carácter a verificar.
 * @return true si es una letra, false en caso contrario.
 */
bool esLetraValida(char letra) {
    return std::isalpha(static_cast<unsigned char>(letra)) != 0;
}

/**
 * @brief Verifica si la palabra oculta está completa (igual a la palabra original).
 * @param palabra La palabra secreta.
 * @param oculto La cadena oculta.
 * @return true si están completas, false en caso contrario.
 */
bool palabraCompleta(std::string_view palabra, std::string_view oculto) {
    return palabra == oculto;
}

/**
 * @brief Selecciona una palabra aleatoria de la lista proporcionada.
 * @param palabras Lista de palabras disponibles.
 * @param rng Generador de números aleatorios.
 * @return La palabra seleccionada.
 */
std::string seleccionarPalabraAleatoria(const std::vector<std::string>& palabras, std::mt19937& rng) {
    std::uniform_int_distribution<std::size_t> distribucion(0, palabras.size() - 1);
    return palabras[distribucion(rng)];
}

#ifndef UNIT_TEST
/**
 * @brief Función principal del juego del ahorcado.
 * @return Código de salida (0 para éxito).
 */
int main() {
    // Inicialización de datos del juego
    const auto palabras = obtenerPalabras();
    const auto ahorcado = obtenerAhorcado();

    // Generador de números aleatorios
    std::random_device rd;
    std::mt19937 generador(rd());
    const std::string palabraSecreta = seleccionarPalabraAleatoria(palabras, generador);

    // Estado del juego
    auto palabraOculta = crearOculto(palabraSecreta.size());
    std::set<char> letrasUsadas;
    int intentosRestantes = MAX_ATTEMPTS;
    bool juegoCompletado = false;

    // Mensaje de bienvenida
    std::cout << "Bienvenido al juego del Ahorcado!" << std::endl;
    std::cout << "Adivina la palabra letra a letra. Usa solo letras minusculas." << std::endl;
    std::cout << std::endl;

    // Bucle principal del juego
    while (intentosRestantes > 0 && !juegoCompletado) {
        // Mostrar estado actual
        const int indiceImagen = MAX_ATTEMPTS - intentosRestantes;
        std::cout << ahorcado[indiceImagen] << std::endl;

        std::cout << "Palabra: ";
        for (const char c : palabraOculta) {
            std::cout << c << ' ';
        }
        std::cout << std::endl;

        if (!letrasUsadas.empty()) {
            std::cout << "Letras usadas: ";
            for (const char c : letrasUsadas) {
                std::cout << c << ' ';
            }
            std::cout << std::endl;
        }

        std::cout << "Intentos restantes: " << intentosRestantes << std::endl;
        std::cout << "Introduce una letra: ";

        // Leer entrada del usuario
        char letra;
        std::cin >> letra;
        letra = static_cast<char>(std::tolower(static_cast<unsigned char>(letra)));

        // Validar entrada
        if (!esLetraValida(letra)) {
            std::cout << "Por favor, introduce una letra valida." << std::endl;
            continue;
        }

        if (letrasUsadas.count(letra)) {
            std::cout << "Ya has intentado la letra '" << letra << "'. Prueba con otra." << std::endl;
            continue;
        }

        letrasUsadas.insert(letra);

        // Procesar intento
        if (!actualizaOculto(palabraSecreta, letra, palabraOculta)) {
            --intentosRestantes;
            std::cout << "La letra '" << letra << "' no esta en la palabra." << std::endl;
        } else {
            std::cout << "¡Bien! La letra '" << letra << "' esta en la palabra." << std::endl;
        }

        juegoCompletado = palabraCompleta(palabraSecreta, palabraOculta);
        std::cout << std::endl;
    }

    // Resultado final
    if (juegoCompletado) {
        std::cout << ahorcado[MAX_ATTEMPTS - intentosRestantes] << std::endl;
        std::cout << "¡Felicidades! Has adivinado la palabra: " << palabraSecreta << std::endl;
    } else {
        std::cout << ahorcado[MAX_ATTEMPTS] << std::endl;
        std::cout << "Se han agotado los intentos. La palabra era: " << palabraSecreta << std::endl;
    }

    return 0;
}
#endif

