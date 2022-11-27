#include <fstream>
#include <iostream>
#include <algorithm>    
#include <array>        
#include <random>       
#include <chrono>
#include <vector> 
using namespace std;

void insertionSort(vector <int> &arr,int ArraySize)
{
    int i, key, j;
    for (i = 1; i < ArraySize; i++)
    {
        key = arr[i];
        j = i - 1;
 
                while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
 

void printArray(vector <int> arr,int ArraySize)
{
    int i;
    for (i = 0; i < ArraySize; i++)
        cout << arr[i] << " ";
    cout << endl;
}
void populate(vector <int> &arr,int ArraySize){
    srand(time(0));
    for(int i;i<=ArraySize;i++){
        arr.push_back(i);
    }
     

}
 

int main()
{
    vector <int> arr;
    int ArraySize=10000;
    fstream fout;
  
    // opens an existing csv file or creates a new file.
    fout.open("timecomplexitydataWCS.csv", ios::out | ios::app);
   
    fout<<"TimeTaken"<<" ,"<<"ArraySize"<<endl;
    while(ArraySize!=10000000){

        populate(arr,ArraySize);
        auto start = std::chrono::system_clock::now();
        //insertionSort(arr,ArraySize);
        auto end = std::chrono::system_clock::now();
 
        std::chrono::duration<double> elapsed_seconds = end-start;
        std::time_t end_time = std::chrono::system_clock::to_time_t(end);
        std::time_t start_time = std::chrono::system_clock::to_time_t(start);
        
        cout<<"\n\n\n";
        cout<< "Started computation at " << std::ctime(&start_time) 
        << "finished computation at " << std::ctime(&end_time)
        << "elapsed time: " << elapsed_seconds.count() << "s"<<"for a Array Size of :"<<ArraySize
        << std::endl;
        fout<<elapsed_seconds.count()<<" ,"<<ArraySize<<endl;
        ArraySize=ArraySize+10000;
    }
    
     
    return 0;
}