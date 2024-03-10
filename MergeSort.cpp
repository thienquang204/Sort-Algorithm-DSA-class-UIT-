#include <bits/stdc++.h>
using namespace std;

const int N=1e6+10;

int n;
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
double A[N];

void merge(double array[], int const left, 
           int const mid, int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;
 
    // Create temp arrays
    auto *leftArray = new double[subArrayOne],
         *rightArray = new double[subArrayTwo];
 
    // Copy data to temp arrays leftArray[] 
    // and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
 
    // Initial index of first sub-array
    // Initial index of second sub-array
    auto indexOfSubArrayOne = 0, 
         indexOfSubArrayTwo = 0; 
 
    // Initial index of merged array
    int indexOfMergedArray = left; 
 
    // Merge the temp arrays back into 
    // array[left..right]
    while (indexOfSubArrayOne < subArrayOne && 
           indexOfSubArrayTwo < subArrayTwo) 
    {
        if (leftArray[indexOfSubArrayOne] <= 
            rightArray[indexOfSubArrayTwo]) 
        {
            array[indexOfMergedArray] = 
            leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else
        {
            array[indexOfMergedArray] = 
            rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
     
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) 
    {
        array[indexOfMergedArray] = 
        leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
 
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) 
    {
        array[indexOfMergedArray] = 
        rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}
 
// begin is for left index and end is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(double array[], 
               int const begin, 
               int const end)
{
    // Returns recursively
    if (begin >= end)
        return; 
 
    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
    return;
}






int main(int argc, char *argv[]) {
    using namespace std::chrono;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    assert(argc == 2);

    char parameterStr[1000];

    string instanceFile;
    
    sscanf(argv[1],"%s", parameterStr); 
    instanceFile = string(parameterStr);
    freopen(instanceFile.c_str(), "r", stdin);

    for(int i = 0; i < 1e6; i++) 
        cin >> A[i];

    auto start = std::chrono::high_resolution_clock::now();
    
    mergeSort(A, 0, N - 1);

    auto end = std::chrono::high_resolution_clock::now();

    duration<double> exec_time = end - start; 

    cout << exec_time.count() << endl;

    return 0;
}