import random
def unico(x,L):
  esUnico=True
  for i in range(len(L)):
    if x==L[i]:
      esUnico=False
      break
  return esUnico

def maximo(L,n,count):
    mayor=L[0]
    for i in range(n):
        if L[i] > mayor :
            mayor = L[i]
            count=count+1
    return count


n=int(input("cantidad ? "))

promedio=0
count=0
for i in range (200):
    L=[]*n
    j=0
    while j<n:
        x=random.randint(0,n)
        while (unico(x,L)):
            L.append(x)
            j+=1
    count=count+maximo(L,n,0)
print(count)
promedio=count/200
print(promedio)