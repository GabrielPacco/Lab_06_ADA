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

void threeWayPartition(int *A, int l, int r, int& i, int& j)
{
	i = l - 1, j = r;
	int p = l - 1, q = r;
	int v = A[r];

	while (true)
	{
		while (A[++i] < v);

		while (v < A[--j])
			if (j == l)
				break;

		// Si i y j se cruzan, entonces hemos terminado 
		if (i >= j) break;

		// Intercambio, de manera que lo más pequeño va a la izquierda lo más grande va a la derecha  
		swap(A[i], A[j]);

		// Mover todas las ocurrencias de la misma izquierda del pivote al principio de 
		// matriz y mantener la cuenta usando p 
		if (A[i] == v)
		{
			p++;
			swap(A[p], A[i]);
		}

		// Mover todas las ocurrencias de la derecha del pivote al final del array 
		// y mantener la cuenta usando q 
		if (A[j] == v)
		{
			q--;
			swap(A[j], A[q]);
		}
	}

	// Mover el elemento pivote a su índice correcto 
	swap(A[i], A[r]);

	// Mover todas las ocurrencias iguales a la izquierda desde el principio 
	// a las adyacentes a A[i] 
	j = i - 1;
	for (int k = l; k < p; k++, j--)
		swap(A[k], A[j]);

	// Mover todas las ocurrencias iguales a la derecha desde el final 
	// a adyacentes a A[i] 
	i = i + 1;
	for (int k = r - 1; k > q; k--, i++)
		swap(A[i], A[k]);
}

void threeWayQuicksort(int *A, int l, int r)
{
	if (r <= l) return;

	int i, j;
    /*
	cout << "Orden actual de los valores: \n";
	cout << "\t\t";
	for (int i = 0; i < r; i++)
        cout << A[i] << " ";
	cout << endl << endl;
    */
	threeWayPartition(A, l, r, i, j);

	threeWayQuicksort(A, l, j);
	threeWayQuicksort(A, i, r);
}

void quicksort1(int *A, int n)
{
    generarNumeros(A, n);
    Timer t;
    QuickSort(A, 0, n-1);
    t.~Timer();
}

void quicksort2(int *A, int n)
{
    generarNumeros(A, n);
    Timer t;
    threeWayQuicksort(A, 0, n-1);
    t.~Timer();
}

int main()
{
    int *A;
    int n = 2000000;
    A = new int[n];

    generarNumeros(A, n);

    std::cout << "tiempo de ordenamiento con QuickSort para " << n << " Elementos \n";
    quicksort1(A, n);
    std::cout << "tiempo de ordenamiento con ThreewayQuickSort para " << n << " Elementos \n";
    quicksort2(A, n);

    /*
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    */

    /*
    auto start = std::chrono::system_clock::now();
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<float, std::milli> duration = end - start;
    std::cout << "Tiempo de ejecucion: " << duration.count() << " ms" << std::endl;
    
    */
    return 0;
}