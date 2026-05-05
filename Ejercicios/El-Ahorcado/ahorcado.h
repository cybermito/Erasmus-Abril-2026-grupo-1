#ifndef AHORCADO_H
#define AHORCADO_H

#include <random>
#include <string>
#include <vector>

/**
 * @brief Obtiene la lista de palabras disponibles para el juego del ahorcado.
 * @return Vector de strings con las palabras del juego.
 */
std::vector<std::string> obtenerPalabras();

/**
 * @brief Obtiene las representaciones ASCII del ahorcado para cada estado.
 * @return Vector de strings con los dibujos ASCII.
 */
std::vector<std::string> obtenerAhorcado();

/**
 * @brief Crea una cadena oculta con guiones bajos del tamaño especificado.
 * @param longitud Longitud de la cadena oculta.
 * @return String con guiones bajos.
 */
std::string crearOculto(std::size_t longitud);

/**
 * @brief Actualiza la cadena oculta revelando las letras encontradas.
 * @param palabra La palabra secreta.
 * @param letra La letra a buscar.
 * @param oculto La cadena oculta a actualizar (modificada por referencia).
 * @return true si la letra fue encontrada y actualizada, false en caso contrario.
 */
bool actualizaOculto(std::string_view palabra, char letra, std::string& oculto);

/**
 * @brief Verifica si un carácter es una letra válida (alfabética).
 * @param letra El carácter a verificar.
 * @return true si es una letra, false en caso contrario.
 */
bool esLetraValida(char letra);

/**
 * @brief Verifica si la palabra oculta está completa (igual a la palabra original).
 * @param palabra La palabra secreta.
 * @param oculto La cadena oculta.
 * @return true si están completas, false en caso contrario.
 */
bool palabraCompleta(std::string_view palabra, std::string_view oculto);

/**
 * @brief Selecciona una palabra aleatoria de la lista proporcionada.
 * @param palabras Lista de palabras disponibles.
 * @param rng Generador de números aleatorios.
 * @return La palabra seleccionada.
 */
std::string seleccionarPalabraAleatoria(const std::vector<std::string>& palabras, std::mt19937& rng);

#endif // AHORCADO_H
