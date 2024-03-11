#include <fstream>
#include <functional>
#include <iostream>

using logFunc_t = std::function<void(const std::string &)>;


int add3(int n) {
    return n+3;
}

int mul2(int n) {
    return n*2;
}

int mycompute(logFunc_t logF, int v0) {
    logF("add3 " + std::to_string(v0) + "\n");
    const int v1 = add3(v0);
    logF( "mul2 " + std::to_string(v1) + "\n");
    const int v2 = add3(v1);
    return v2;
}




int main() {
    std::cout << "this is log-cpp" << std::endl;

    logFunc_t print = [](const std::string &contenu){
        std::cout<<contenu;
    };

    std::ofstream ofs("log2.txt");
    logFunc_t print2 = [&ofs](const std::string &contenu){
        ofs <<contenu;
    };
    
    std::cout<<mycompute(print, 2);

    return 0;
}

