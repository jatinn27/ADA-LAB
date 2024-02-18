#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

int Power(int x, int n)
{
    if (n == 0)
    {
        return 1;
    }

    if (n == 1)
    {
        return x;
    }

    int res = Power(x, n / 2);

    if (n % 2 == 0)
    {
        return res * res;
    }
    else
    {
        return x * res * res;
    }
}

int main()
{

    int i = 100000;
    do
    {
        int x = 2;

        int n = i; 


        clock_t start, end;

        start = clock();

        for (int i = 0; i < 100; i++)
            Power(x, n);

        end = clock();

        double time_taken = double(end - start) / CLOCKS_PER_SEC;

        double average_time = time_taken / 100;

        cout << "\nAverage Time taken by Power function is : " << fixed
             << average_time << setprecision(5) << " sec" << endl;
        i = i + 10;
    } while (i != 10000000);

    return 0;
}
