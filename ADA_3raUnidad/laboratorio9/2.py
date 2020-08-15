aux, fib = 1, 0, 

def fib(n):
    if n <= 1:
        return n
    else:
        return fib(n - 1) + fib(n - 2)



for i in range(0,1000):
	print(fib(50))
