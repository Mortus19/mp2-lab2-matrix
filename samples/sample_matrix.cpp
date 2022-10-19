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

    TDynamicVector<int>aa(5),bb(5);
    for(int i = 0;i<5;i++){
        aa[i] = i+1;
        bb[i] = i+2;
    }
    cout<<aa<<'\n';
    cout<<bb<<'\n';
    TDynamicVector<int>cc = aa - bb;
    cout<<cc<<'\n';
    int ans = aa*bb;
    cout<<ans<<'\n';
    return 0;
  TDynamicMatrix<int> a(5), b(5), c(5);
  int i, j;

  setlocale(LC_ALL, "Russian");
  cout << "Тестирование класс работы с матрицами"
    << endl;
  for (i = 0; i < 5; i++)
    for (j = i; j < 5; j++ )
    {
      a[i][j] =  i * 10 + j;
      b[i][j] = (i * 10 + j) * 100;
    }
  c = a + b;
  cout << "Matrix a = " << endl << a << endl;
  cout << "Matrix b = " << endl << b << endl;
  cout << "Matrix c = a + b" << endl << c << endl;
  return 0;
}
//---------------------------------------------------------------------------
