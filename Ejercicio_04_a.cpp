#include <iostream>
#include <vector>
#include <chrono>
using std::cout, std::endl;

void mostrar(std::vector<int> A)
{
    for (int value : A)
    {
        cout << value << " ";
    }
    cout << endl;
}
void insertionSort(std::vector<int> &vec, int left, int right)
{
    int i, key, j;
    for (i = left + 1; i < right; i++)
    {
        key = vec[i];
        j = i - 1;
        while (j >= left && vec[j] > key)
        {
            vec[j + 1] = vec[j];
            j = j - 1;
        }
        vec[j + 1] = key;
    }
}
int Partition(std::vector<int> &A, int p, int r)
{
    int x = A[r];
    int i = p - 1;
    for (int j = p; j <= r - 1; j++)
    {
        if (A[j] <= x)
        {
            i = i + 1;
            std::swap(A[i], A[j]);
        }
    }
    std::swap(A[i + 1], A[r]);
    return i + 1;
}
void Quicksort(std::vector<int> &A, int p, int r)
{
    if (p >= r)
    {
        return;
    }
    if (r - p <= 30)
    {
        insertionSort(A, p, r + 1);
        return;
    }
    int q = Partition(A, p, r);
    Quicksort(A, p, q - 1);
    Quicksort(A, q + 1, r);
}

int main()
{
    srand(time(0));
    std::vector<int> A;
    int cant = 10;
    cout << "Insertion-Quick Sort" << endl;
    for (int n = 0; n < 6; n++)
    {
        for (int i = 1; i <= cant; i++)
        {
            A.push_back(rand() % 60);
        }
        cout << cant << endl;
        auto start = std::chrono::system_clock::now();
        Quicksort(A, 0, A.size() - 1);
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<float, std::milli> duration = end - start;
        cout << "Arreglo ordenado --QuickSort-- \n";
        cout << "Tiempo de ejecucion: " << duration.count() << " ms" << std::endl;
        cout << endl;
        A.clear();
        cant *= 10;
    }
}