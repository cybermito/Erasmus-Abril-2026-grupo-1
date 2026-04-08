
# Cómo instalar MinGW-w64 en Windows 11 (Noviembre 2025)

* **Autor:** Prabhat Shrestha
* **Fecha de publicación:** 3 de noviembre de 2025 (Actualizado el 9 de noviembre de 2025)
* **Etiquetas:** #cpp #mingw
* **[Enlace](https://dev.to/prastha/install-mingw-w64-on-windows-11-2025-november-acg)


## Introducción
Aunque Visual Studio Community es una herramienta potente y gratuita para uso personal, requiere una licencia de pago para uso comercial en equipos. Si deseas crear programas comerciales de forma gratuita, una excelente alternativa es utilizar la combinación de **MinGW-w64, CMake y Visual Studio Code**.

Dado que los métodos de instalación de MinGW-w64 cambian con el tiempo, esta guía documenta el proceso probado en **noviembre de 2025**.


## 1. Descarga
Debes descargar MinGW-w64 desde el sitio oficial:
* **Sitio web:** [https://www.mingw-w64.org](https://www.mingw-w64.org)

Al hacer clic en **w64devkit**, serás redirigido al repositorio de GitHub:
* **GitHub:** [https://github.com/skeeto/w64devkit](https://github.com/skeeto/w64devkit)

Descarga el archivo de instalación desde la sección **"Releases"** (ubicada en la esquina inferior derecha).


## 2. Instalación
1. Ejecuta el instalador (doble clic en el archivo `.exe` descargado).
2. Se te preguntará dónde instalarlo. Elige una carpeta de tu preferencia.
3. En este ejemplo, la ruta utilizada es: `C:\Tools\w64devkit`.
    * *Nota: Si eliges otra ubicación, asegúrate de reemplazar "C:\Tools" por tu ruta personalizada en los siguientes pasos.*

## 3. Configuración de Variables de Entorno (PATH)
Para poder compilar C++ desde el "Símbolo del sistema" (CMD), debes añadir el directorio de MinGW-w64 a la variable de entorno Path.

1. Presiona `Windows + R`, escribe `sysdm.cpl` y presiona **Enter**.
2. En la ventana **Propiedades del sistema**, ve a la pestaña **Opciones avanzadas** -> **Variables de entorno**.
3. En la sección **Variables del sistema**, busca y selecciona **Path**, luego haz clic en **Editar**.
4. Haz clic en **Nuevo** y pega la siguiente ruta (ajustada a tu ubicación):
   `C:\Tools\w64devkit\bin`
5. Haz clic en **Aceptar** en todas las ventanas abiertas.
6. **Reinicia tu PC** para que los cambios surtan efecto.


## 4. Verificar la Instalación
Abre el Símbolo del sistema y ejecuta el siguiente comando:
```bash
g++ --version
```
Si la instalación fue exitosa, verás una salida similar a esta:
`g++ (GCC) 15.2.0 Copyright (C) 2025 Free Software Foundation, Inc.`


## 5. Ejecutar Código de Prueba
Guarda el siguiente código de ejemplo en un archivo llamado `hello.cpp`:

```cpp
#include <iostream>

int main() {
    std::cout << "Hello, World!\n";
    return 0;
}
```

### Compilación:
Abre una terminal en la carpeta donde guardaste el archivo (puedes escribir "cmd" en la barra de direcciones de la carpeta) y ejecuta:
```bash
g++ hello.cpp -o hello.exe
```

### Ejecución:
Para correr el programa, simplemente escribe:
```bash
hello
```
**Resultado esperado:**
`Hello, World!`
