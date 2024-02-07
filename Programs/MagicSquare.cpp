#include <iostream>
#include <vector>
#include <iomanip>
#include <chrono>

using namespace std;

void generateMagicSquare(int n)
{
    vector<vector<int>> magicSquare;
    magicSquare = vector<vector<int>>(n, vector<int>(n, 0));

    int i = n / 2;
    int j = n - 1;

    for (int num = 1; num <= n * n;)
    {
        if (i == -1 && j == n)
        {
            j = n - 2;
            i = 0;
        }
        else
        {
            if (j == n)
                j = 0;
            if (i < 0)
                i = n - 1;
        }
        if (magicSquare[i][j])
        {
            j -= 2;
            i++;
            continue;
        }
        else
            magicSquare[i][j] = num++;

        j++;
        i--;
    }
}

void displayMagicSquare(int n)
{
    cout << "Magic Square for " << n << "x" << n << ":\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << setw(4) << magicSquare[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{

    int input_size = 3;

    while (input_size < 9999)
    {
        // to calculate time if an algorithm runs 100 times for a specific input
        clock_t start, end;

        start = clock();

        for (int i = 0; i < 100; i++)
            generateMagicSquare(input_size);

        end = clock();

        // total time taken for running an algorithm 100 times for a specific input
        double time_taken = double(end - start) / CLOCKS_PER_SEC;

        // avearge time time_taken/100
        double average_time = time_taken / 100;

        cout << "\nAverage Time taken by for input size " << input_size << " is : " << fixed
             << time_taken << setprecision(5);
        cout << " sec " << endl;
        input_size = input_size + 200;
    }
    return 0;
}


