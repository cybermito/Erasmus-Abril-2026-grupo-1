# Juego Adivina el Número

## Descripción

En este juego, el programa generará un número aleatorio entre 1 y 100, y el jugador tendrá que adivinarlo. El programa proporcionará pistas indicando si el número ingresado por el jugador es demasiado alto, demasiado bajo o correcto.

## Reglas del juego

1. El programa generará un número aleatorio entre 1 y 100 al inicio del juego.
2. El jugador ingresará un número para intentar adivinar el número generado por el programa
3. El programa responderá con una pista:
   - Si el número ingresado es menor que el número generado, el programa dirá "Demasiado bajo".
   - Si el número ingresado es mayor que el número generado, el programa dirá "Demasiado alto".
   - Si el número ingresado es igual al número generado, el programa dirá "¡Correcto! Has adivinado el número en X intentos", donde X es el número de intentos realizados.
4. El juego continuará hasta que el jugador adivine el número correcto.

## Requisitos técnicos

- El programa debe estar escrito en C++.
- El programa debe utilizar funciones para organizar el código.
- El programa debe manejar la entrada del usuario y validar que sea un número válido entre 1 y 100.
- El programa debe contar el número de intentos realizados por el jugador.

## Ejemplo de ejecución

```bash
¡Bienvenido al juego Adivina el Número!
Estoy pensando en un número entre 1 y 100. ¿Puedes adivinarlo?
Ingresa tu número: 50
Demasiado bajo. Intenta de nuevo.
Te quedan 9 intentos.
Ingresa tu número: 75
Demasiado alto. Intenta de nuevo.
Te quedan 8 intentos.
Ingresa tu número: 63
¡Correcto! Has adivinado el número en 3 intentos.
```

## Instrucciones para la implementación

1. Generar un número aleatorio entre 1 y 100.

2. Registrar el número del intento en el que el jugador se encuentre. Empezando en 1.

3. Darle al jugador una forma de adivinar cuál es el número.

4. Una vez que se ha introducido el número, registrarlo en alguna parte para que el jugador pueda ver sus intentos previos.

5. A continuación, comprobar si el número es correcto.

6. Si es correcto:
   1. Mostrar un mensaje de felicitaciones.
   2. Hacer que el jugador no pueda introducir más intentos (esto arruinaría el juego).
   3. Mostrar un control que permita al jugador volver a empezar el juego.

7. Si es incorrecto y al jugador todavía le quedan intentos:
   1. Decirle al jugador que ha fallado.
   2. Dejar que el jugador lo intente de nuevo.
   3. Incrementa el número de intentos en 1.

8. Si el jugador falla y no le quedan turnos:
   1. Decirle al jugador que el juego se ha terminado.
   2. Hacer que el jugador no pueda introducir más intentos (esto arruinaría el juego).
   3. Mostrar un control que permita al jugador volver a empezar el juego.

9. Una vez que el juego se reinicia, asegúrate de que la lógica del juego y la IU (interfaz de usuario) se restablezcan por completo, luego vuelve al paso 1.

¡Diviértete creando, jugando y adivinando el número!
