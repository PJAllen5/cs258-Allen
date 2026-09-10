// Example assignment

#include <ctime>
#include "code.hpp"

/* What is the Big O of each loop?
    Design and implement an experiment to find a value of n for which
    Loop C is faster than Loop A.
    Design and implement an experiment to find a value of n for which
    Loop B is faster than Loop A.
    */

int loopA(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= 10000; j++)
            sum = sum + j;
    return sum;
}

int loopB(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            sum = sum + j;
    return sum;
}

int loopC(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= j; k++)
                sum = sum + k;
    return sum;
}

int main()
{
    clock_t start = clock();

    clock_t finish = clock();
    double overallTime = static_cast<double>(finish - start) / CLOCKS_PER_SEC;
}
