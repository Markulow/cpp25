#include <iostream>
#include <map>

class CachingFibonacciNumberCalculator
{
public:
    unsigned long long
    operator()(int n)
    {
            auto it = cache_.find(n);
        if ( it != cache_.end() )
        {
            return it->second;
        }

        unsigned long long result;
        if ( n < 2 )
        {
            result = n;
        }
        else
        {
            result = (*this)(n - 1) + (*this)(n - 2);
        }

        cache_[n] = result;
        return result;
    }


    std::map<int, unsigned long long> cache_
            {
                    { 0, 0 },
                    { 1, 1 }
            };
};

int main()
{
    CachingFibonacciNumberCalculator fib;
    std::cout << fib(1) << std::endl;
    std::cout << fib(1) << std::endl;
    std::cout << fib(2) << std::endl;
    std::cout << fib(2) << std::endl;
    std::cout << fib(3) << std::endl;
    std::cout << fib(4) << std::endl;
    std::cout << fib(5) << std::endl;
    std::cout << fib(6) << std::endl;
    return 0;
}
