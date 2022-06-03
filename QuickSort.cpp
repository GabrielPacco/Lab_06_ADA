#include <iostream>
#include <chrono>
using namespace std;

struct Timer
{
std::chrono::system_clock::time_point m_start;
Timer()
{
    m_start = std::chrono::system_clock::now();
}
~Timer()
{
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<float, std::milli> duration = end - m_start;
    std::cout << duration.count() << " milisegundos" << std::endl;
}};

int Partition(int *A, int p, int r)
{
    int pivot = A[r];
    int i = p - 1;
    for (int j = p; j < r; j++)
    {
        if (A[j] <= pivot)
        {
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[i + 1], A[r]);
    return i + 1;
}

void QuickSort(int *A, int p, int r)
{
    if (p < r)
    {
        int pivot = Partition(A, p, r);
        QuickSort(A, p, pivot - 1);
        QuickSort(A, pivot + 1, r);
    }
}

int main()
{
    int A[] = {23,5,3,1,2,4,6,7,8,92};
    int n = sizeof(A) / sizeof(A[0]);

    QuickSort(A, 0, n - 1);
    Timer t;
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;

    /*
    auto start = std::chrono::system_clock::now();
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<float, std::milli> duration = end - start;
    std::cout << "Tiempo de ejecucion: " << duration.count() << " ms" << std::endl;
    
    */
    return 0;
}