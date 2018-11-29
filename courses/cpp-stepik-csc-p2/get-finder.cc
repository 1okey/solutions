#include <functional>

// Определите переменную gen_finder, хранящую безымянную функцию, которая принимает массив значений
// типа int через два указателя и возвращает безымянную функцию, которая в свою очередь принимает значение
// типа int и проверяет, есть ли это значение в переданном массиве.

template<class F>
int * find_if(int * p, int * q, F f)
{
    for ( ; p != q; ++p )
        if (f(*p))
            return p;
    return q;
}

std::function<std::function<bool(int)> (int*,int*)> gen_finder = [](int* p, int* q){
    return [p,q](int i){
        for (size_t ind = 0; ind < q - p; ind++)
            if (p[ind] == i) return true;
        return false;
    };
};


int main(){
    int primes[5] = {2,3,5,7,11};

    int m[10] = {0,0,1,1,4,6,7,8,9,10};

    // first_prime будет указывать на число 7
    int * first_prime = find_if(m, m + 10, gen_finder(primes, primes + 5));
}



