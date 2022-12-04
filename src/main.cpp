/**
 * @file main.cpp
 * @author Jenisha Khulal
 * @brief This has a main function where generating data and quicksort is implemented.
 * The sorting has been done for data size ranging from 10000 to 6000000.
 * @version 0.1
 * @date 2022-12-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "sorting.h"
#include <fstream>
#include <chrono>
#include <Windows.h>

int main()
{
 
    vector<int> a;
    int i = 10000;
    fstream fout;

    // opens an existing csv file or creates a new file.
    fout.open("quicksortTimeComplexity.csv", ios::out | ios::app);

    fout << "TimeTaken"
         << " ,"
         << "ArraySize" << endl;
    while (i != 6000000)
    {

        genData(a, i);
        auto start = std::chrono::system_clock::now();//marking the start of sorting execution
        quickSort(a, 0, i - 1);
        auto end = std::chrono::system_clock::now();//marking the end of sorting execution

        std::chrono::duration<double> elapsed_seconds = end - start;//calculating the time elapsed
        std::time_t end_time = std::chrono::system_clock::to_time_t(end);
        std::time_t start_time = std::chrono::system_clock::to_time_t(start);

        cout << "\n\n";
        cout << "elapsed time: " << elapsed_seconds.count() << "s"
             << "for a Array Size of :" << i << std::endl;
        fout << elapsed_seconds.count() << " ," << i << endl;
        i = i + 100000;
        a.clear();
    }
    fout.close();

    return 0;
}