#include <iostream>
using namespace std;

float ponderado(int *A, int n)
{
    float suma = 0;
    for (int i = 0; i < n; i++)
    {
        suma += A[i];
    }
    return suma / n;
}

int main()
{
    // Obtener el promedio de un arreglo de enteros
       
    int A[26] = {20, 18, 16, 16, 13, 11, 18, 13, 14, 13, 17, 16, 16, 15, 13, 18, 17, 12, 17, 16, 15, 13, 18, 14, 16, 13};
    int B[13] = {20, 18, 16, 16, 13, 11, 18, 13, 14, 13, 17, 16, 16};

    float suma1 = 0.0;
    for (int i = 0; i < 13; i++)
    {
        suma1 += B[i];
    }

    float promedio1 = suma1 / 13;
    cout << "El promedio del 1er año es: " << promedio1 << endl;
    
    float suma = 0.0;
    for (int i = 0; i < 26; i++)
    {
        suma += A[i];
    }
    float promedio = suma / 26;
    cout << "El promedio del 2do año es: " << promedio << endl;

    return 0;    
}