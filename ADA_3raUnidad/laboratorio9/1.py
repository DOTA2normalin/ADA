aux, fib, init = 1, 0, 1

print(_INFO)
lim = int(input("Ingrese un numero para la sucesion de fibonacci: "))
if lim > 0:
    while init <= lim:
        print(fib, end=" ")
        aux += fib 
        fib = aux - fib
        init += 1
    print()
else:
    print("El numero debe ser mayor a cero!!")