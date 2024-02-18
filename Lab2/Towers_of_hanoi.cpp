#include <iostream>
#include <vector>
#include <iomanip> // setprecision()
#include <cstdlib> // clock_t
using namespace std;

void towerOfHanoi(int n, char source, char destination, char spare)
{
    if (n >= 1)
    {
        towerOfHanoi(n - 1, source, spare, destination);
        // cout << "Move disc " << n << " from " << source << " to " << destination << endl;
        towerOfHanoi(n - 1, spare, destination, source);
    }
}

int main()
{

    for (int i = 1; i < 100; i++)
    {
        clock_t start, end;

        start = clock();
        for (int j = 0; j < 10; j++)
        {
            towerOfHanoi(i, 'A', 'C', 'B');
        }
        end = clock();

        // total time taken for running an algorithm 100 times for a specific input
        double time_taken = double(end - start) / CLOCKS_PER_SEC;

        // avearge time time_taken/100
        double average_time = time_taken / 10;

        cout << "\nAverage Time taken by for input size " << i << " is : " << fixed
             << time_taken << setprecision(5);
        cout << " sec " << endl;
    }
    return 0;
}
