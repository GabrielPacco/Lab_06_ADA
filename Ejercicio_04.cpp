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

// Función básica de swap
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

// Generar numeros aleatorios 
void generarNumeros(int *A, int n)
{
    srand((unsigned int)time(NULL));
    for (int i = 0; i < n; i++)
    {
        A[i] = rand() % 10000;
    }
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
        QuickSort(A, p, pivot - 1);
        QuickSort(A, pivot + 1, r);
    }
}

void insertionSort(int *A, int n)
{
    int j, key, i;
    for (j = 1; j < n; j++)
    {
        key = A[j];
        i = j - 1;

        // Diferencia: A[i] > key cambia a A[i] < key
        while (i >= 0 && A[i] < key)
        {
            A[i + 1] = A[i];
            i--;
        }
        A[i + 1] = key;
    }
}

void tiempo_insertionSort(int *A, int n)
{
    Timer t;
    insertionSort(A, n);
    t.~Timer();
}

int main()
{
    int n = 10000;
    int *A = new int[n];
    generarNumeros(A, n);


    cout << "tiempo de ejecucion del algoritmo insertionSort: " << endl;
    tiempo_insertionSort(A, n);
    

    /*
    for (int j = 0; j < n; j++)
        std::cout << A[j] << " ";
    std::cout << std::endl;
    */
    return 0;
}