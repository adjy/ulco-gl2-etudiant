
def fibo_naive(n: int):
    assert n >= 0
    return n if n < 2 else fibo_naive(n-1) + fibo_naive(n-2)

  

def printFibo_naive(n):
    print(5*"*" + "naive" + 5*"*")
    for i in range(n + 1):
        print("fibo_naive({}) = {}".format(i, fibo_naive(i)))
    print()

def printFibo_iteratif(n):
    print(5*"*" + "iteratif" + 5*"*")
    for i in range(n + 1):
        print("fibo_naive({}) = {}".format(i, fibo_iteratif(i)))
    print()


def fibo_iteratif(n):
    assert n >= 0
    
    fibo1 = 0
    fibo = 1

   
    for i in range(2, n + 1):
        fibo2 = fibo1 + fibo
        fibo1, fibo = fibo, fibo2
    return fibo  
