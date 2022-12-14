/**
 * @file sorting.cpp
 * @author Jenisha Khulal
 * @brief this contains definitions of functions declared in sorting.h 
 * @version 0.1
 * @date 2022-12-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "sorting.h"

/**
 * @brief this function sorts the given list in ascending order recursively
 * 
 * @param a list to be sorted
 * @param low index from where sorting should start
 * @param high index upto which sorting is done 
 */
void quickSort(vector<int> &a, int low, int high)
{
    if (low < high)
    {
        int pivot = Partition(a, low, high);
        quickSort(a, low, pivot - 1);
        quickSort(a, pivot + 1, high);
    }
}

/**
 * @brief this function generates the pivot
 *
 * @param a list for which pivot is to be found
 * @param low index from where sorting should start
 
 * @param high index upto which sorting is done
 * @return int
 */
int Partition(vector<int> &a, int low, int high)
{
    int pi = a[low];
    int i = low;
    int j = high;
    while (i < j)
    {
        while ((a[j]>=pi)&&j>low)
        {
            j = j - 1;
        }
        while ((a[i]<=pi)&&i<high)
        {
            i = i + 1;
        }
        if (i < j)
        {
            swap(a[i], a[j]);
        }
    }
    swap(a[low], a[j]);
    return j;
}
/**
 * @brief this function swaps the data 
 * 
 * @param a 1st data
 * @param b 2nd data
 */
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

/**
 * @brief this function generates random data to be sorted
 * 
 * @param a list which holds the data generated
 * @param size 
 */
void genData(vector<int> &a, int size)
{
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        a.push_back(rand() % 1000);
    }
}
