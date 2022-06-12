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

void insertionSort(int *A, int l, int r)
{
    int j, key, i;
    for (j = l+1; j < r; j++)
    {
        key = A[j];
        i = j - 1;

        // Diferencia: A[i] > key cambia a A[i] < key
        while (i >= l && A[i] > key)
        {
            A[i + 1] = A[i];
            i--;
        }
        A[i + 1] = key;
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
    if (p >= r){
        return;
    }
    if (r - p <= 30){
        insertionSort(A, p, r + 1);
        return;
    }
    int pivot = Partition(A, p, r);
    QuickSort(A, p, pivot - 1);
    QuickSort(A, pivot + 1, r);  
}

void tiempo_QuickSort(int *A, int n)
{
    Timer t;
    QuickSort(A, 0, n - 1);
    t.~Timer();
}

int main()
{
    int n1= 1000;
    int n2= 10000;
    int n3= 1000000;

    int *A = new int[n1];
    generarNumeros(A, n1);
    cout << "tiempo de ejecucion del algoritmo quicksort: " << endl;
    tiempo_QuickSort(A, n1);
    
    int *B = new int[n2];
    generarNumeros(B, n2);
    cout << "tiempo de ejecucion del algoritmo quicksort: " << endl;
    tiempo_QuickSort(B, n2);

    int *C = new int[n3];
    generarNumeros(C, n3);
    cout << "tiempo de ejecucion del algoritmo quicksort: " << endl;
    tiempo_QuickSort(C, n3);

    /*
    for (int j = 0; j < n1; j++)
        std::cout << A[j] << " ";
    std::cout << std::endl;
    */
    return 0;
}