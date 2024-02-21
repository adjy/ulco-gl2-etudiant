import myfibo
if __name__ == '__main__':

    n = 10
    for i in range(n + 1):
        print("fibo_naive({}) = {}".format(i, myfibo.fibo_naive(i)))
    
    for i in range(n + 1):
        print("fibo_iterative({}) = {}".format(i, myfibo.fibo_iterative(i)))
    

