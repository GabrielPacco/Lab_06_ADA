#include <iostream>
#include <chrono>
#include <time.h>
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


// Generar numeros aleatorios 
void generarNumeros(int *A, int n)
{
    srand((unsigned int)time(NULL));
    for (int i = 0; i < n; i++)
    {
        A[i] = rand() % 10000;
    }
}

// Verificar si el arreglo esta ordenado
bool estaOrdenado(int *A, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (A[i] > A[i + 1])
        {
            return false;
        }
    }
    return true;
}

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
        //estaOrdenado(A, pivot);
        QuickSort(A, p, pivot - 1);
        QuickSort(A, pivot + 1, r);
    }
}

int main()
{
    int *A;
    int n = 100;
    A = new int[n];

    generarNumeros(A, n);

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