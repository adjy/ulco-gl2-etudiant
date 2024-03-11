#include <cassert>

int fiboNaive(int n) {
    assert(n => 0);
    return n < 2 ? n : fiboNaive(n-1) + fiboNaive(n-2);
}

int fiboIterative(int n) {
    assert(n => 0);
    
    int fibo1 = 0, fibo = 1;

    for( int i = 2; i < n+1; i++){
        int fibo2 = fibo1 + fibo;
        fibo1 = fibo;
        fibo =  fibo2;
    }   
    return fibo  ;

}
 


#include <pybind11/pybind11.h>

PYBIND11_MODULE(myfibo, m) {
    m.def("fibo_naive", &fiboNaive);
    m.def("fibo_iterative", &fiboIterative);


}

