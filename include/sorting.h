/**
 * @file sorting.h
 * @author Jenisha Khulal
 * @brief this file contains function declaraions.
 * @version 0.1
 * @date 2022-12-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<iostream>
using namespace std;
#include<vector>

void quickSort(vector<int>&, int, int);
int Partition(vector<int>&, int, int);
void swap(int &, int &);
void genData(vector<int> &,int);
