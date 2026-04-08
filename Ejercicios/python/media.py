n = int(input("¿Cuántos números vas a introducir? "))

if n <= 0:
    print("El número de valores debe ser positivo.")
else:
    suma = 0.0
    
    print(f"Introduce los {n} números:")
    for i in range(n):
        valor = float(input())
        suma += valor
    
    media = suma / n
    print(f"La media es: {media}")
