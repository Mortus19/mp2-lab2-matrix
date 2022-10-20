// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
// Тестирование матриц
#include <iostream>
#include "tmatrix.h"
//---------------------------------------------------------------------------

int main()
{
  TDynamicMatrix<int> a(3), b(3), c(3);
  int i, j;
  setlocale(LC_ALL, "RUS");
//  cout << "Тестирование класс работы с матрицами"<< endl;
  for (i = 0; i < 3; i++)
    for (j = i; j < 3; j++ )
    {
//      a[i][j] =  i * 10 + j;
//      b[i][j] = (i * 10 + j) * 100;
        a[i][j] = i + j;
        b[i][j] = i + j + 1;
    }
  c = a * b;
  cout << "Matrix a = " << endl << a << endl;
  cout << "Matrix b = " << endl << b << endl;
  cout << "Matrix c = a + b" << endl << c << endl;
  return 0;
}
//---------------------------------------------------------------------------
