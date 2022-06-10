#include <iostream>
#include <algorithm>
#include <time.h>

// Generar numeros aleatorios 
void generarNumeros(int *A, int n)
{
    srand((unsigned int)time(NULL));
    for (int i = 0; i < n; i++)
    {
        A[i] = rand() % 10;
    }
}

bool is_sorted(int * A, int n, bool ord = true)
{
    for (int i = 1; i < n; ++i)
    {
        if (A[i] < A[i - 1] == ord)
            return false;
    }
    return true;
}
int partition(int * A, int p, int r)
{
    int x = A[r];
    int i = p - 1;
    for (int j = p; j < r; j++)
    {
        if (A[j] <= x)
        {
            i++;
            std::swap(A[i],A[j]);
        }

    }
    std::swap(A[i + 1],A[r]);

    return i + 1;
}
void quicksort(int * A, int p, int r)
{
    if (p < r)
    {
        int q = partition(A,p,r);
        quicksort(A,p,q-1);
        quicksort(A,q+1,r);
    }
}

void quicksort_opt(int * A, int p, int r)
{
    if (is_sorted(A,r+1)){
        std::cout << "El arreglo esta ordenado" << std::endl;
        return;
    }
    if (is_sorted(A,r+1,false))
    {
        int tmp;
        for (int i = 1; i < r/2 + 1; ++i)
        {
            tmp = A[i];
            A[i] = A[r - i];
            A[r - i] = tmp;
        }
        return;
    }
    quicksort(A,p,r);
}

int main()
{
    int *A;
    int n = 10;
    A = new int[n];


    A = new int [n] { 7, 8, 9, 10, 1, 2, 3, 4, 5, 6};
    //generarNumeros(A, n);
    quicksort_opt(A,0,9);
    
    for (int i = 0; i < 10; i++)
    {

        std::cout << A[i] << ' ';
    }

    return 0;
}