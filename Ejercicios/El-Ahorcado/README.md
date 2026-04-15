# Juego del Ahorcado

## Descripción

El Juego del Ahorcado es una implementación en C++ de un clásico juego de palabras donde el jugador debe adivinar una palabra letra por letra antes de que se complete el dibujo del ahorcado. El juego selecciona aleatoriamente una palabra de una lista predefinida y proporciona pistas visuales a través de representaciones ASCII.

## Características

- Selección aleatoria de palabras de una lista integrada.
- Representación visual del ahorcado con 6 intentos.
- Validación de entrada para asegurar letras válidas.
- Seguimiento de letras usadas.
- Mensajes de retroalimentación para cada intento.
- Código modular y testeable con funciones separadas.

## Requisitos

- Compilador C++ que soporte C++17 o superior (por ejemplo, g++ 7.0 o superior).
- Sistema operativo Linux, macOS o Windows con MinGW.

## Instalación

1. Clona o descarga el repositorio en tu máquina local.

2. Navega al directorio del proyecto:

   ```bash
   cd /ruta/al/proyecto/Ejercicios/El-Ahorcado
   ```

3. Compila el juego:

   ```bash
   g++ -Wall -Wextra -g3 ahorcado.cpp -o ahorcado
   ```

4. (Opcional) Compila y ejecuta los tests:
   ```bash
   g++ -Wall -Wextra -g3 -DUNIT_TEST ahorcado.cpp ahorcado_test.cpp -o ahorcado_test
   ./ahorcado_test
   ```

## Cómo Jugar

1. Ejecuta el juego:

   ```bash
   ./ahorcado
   ```

2. El juego mostrará un mensaje de bienvenida y comenzará con la palabra oculta representada por guiones bajos (\_).

3. Introduce una letra minúscula cuando se te pida. Solo se aceptan letras del alfabeto.

4. Si la letra está en la palabra, se revelará en su posición correspondiente.

5. Si la letra no está en la palabra, perderás un intento y se actualizará el dibujo del ahorcado.

6. El juego continúa hasta que adivines la palabra completa o se agoten los 6 intentos.

7. Al final, se mostrará si ganaste o perdiste, junto con la palabra secreta.

### Ejemplo de Juego

```
Bienvenido al juego del Ahorcado!
Adivina la palabra letra a letra. Usa solo letras minusculas.

  +---+
  |   |
      |
      |
      |
      |
=========

Palabra: _ _ _ _ _
Intentos restantes: 6
Introduce una letra: a
¡Bien! La letra 'a' esta en la palabra.

Palabra: _ a _ a _
...
```

## Estructura del Código

- `ahorcado.h`: Declaraciones de funciones y constantes.
- `ahorcado.cpp`: Implementación del juego principal.
- `ahorcado_test.cpp`: Tests unitarios para validar la funcionalidad.

## Contribuir

Si deseas contribuir al proyecto:

1. Asegúrate de que los tests pasen.
2. Añade nuevas palabras a la lista en `obtenerPalabras()`.
3. Mejora la documentación o añade nuevas características.

## Licencia

Este proyecto es de uso educativo y no tiene licencia específica. Siéntete libre de usarlo y modificarlo para fines de aprendizaje.

## Autor

Proyecto creado como parte del curso Erasmus Abril 2026 - Grupo 1.
