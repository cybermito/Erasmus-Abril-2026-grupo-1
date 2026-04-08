def fibonacci(n):
    if n <= 0:
        return []
    if n == 1:
        return [0]

    series = [0, 1]
    for i in range(2, n):
        series.append(series[i - 1] + series[i - 2])
    return series


def main():
    try:
        n = int(input("Introduce el número de términos de la serie Fibonacci: "))
    except ValueError:
        print("Por favor, introduce un número entero válido.")
        return

    if n <= 0:
        print("Por favor, introduce un número entero positivo.")
        return

    series = fibonacci(n)
    print(f"Serie Fibonacci ({n} términos):")
    print(", ".join(str(x) for x in series))


if __name__ == "__main__":
    main()
