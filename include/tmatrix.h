// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
//

#ifndef __TDynamicMatrix_H__
#define __TDynamicMatrix_H__

#include <iostream>

using namespace std;

const int MAX_VECTOR_SIZE = 100000000;
const int MAX_MATRIX_SIZE = 10000;

// Динамический вектор - 
// шаблонный вектор на динамической памяти
template<typename T>
class TDynamicVector
{
protected:
  size_t sz;
  T* pMem;
public:
  TDynamicVector(size_t size = 1) : sz(size)
  {
    if (sz <= 0)
      throw out_of_range("Vector size should be greater than zero");
    pMem = new T[sz]();// {}; // У типа T д.б. констуктор по умолчанию
  }
  TDynamicVector(T* arr, size_t s) : sz(s)
  {
    assert(arr != nullptr && "TDynamicVector ctor requires non-nullptr arg");
    pMem = new T[sz];
    std::copy(arr, arr + sz, pMem);
  }
  TDynamicVector(const TDynamicVector& v)
  {
      sz = v.sz;
      pMem = new T[v.sz];
      for(int i = 0;i<sz;i++){
          pMem[i] = v.pMem[i];
      }
  }
  TDynamicVector(TDynamicVector&& v) noexcept
  {
      pMem = v.pMem;
      sz = v.sz;
      v.sz = 0;
      v.pMem = nullptr;
  }
  ~TDynamicVector()
  {
      if(pMem != nullptr)
          delete []pMem;
  }
  TDynamicVector& operator=(const TDynamicVector& v)
  {
      if(pMem != nullptr)
          delete []pMem;
      sz = v.sz;
      pMem = new T[sz];
      for(int i = 0;i<sz;i++){
          pMem[i] = v.pMem[i];
      }
      return *this;
  }
  TDynamicVector& operator=(TDynamicVector&& v) noexcept
  {
      pMem = v.pMem;
      sz = v.sz;
      v.sz = 0;
      v.pMem = nullptr;
      return *this;
  }

  size_t size() const noexcept { return sz; }

  // индексация
  T& operator[](size_t ind)
  {
      return pMem[ind];
  }
  const T& operator[](size_t ind) const
  {
      //?
  }
  // индексация с контролем
  T& at(size_t ind)
  {
      //?
  }
  const T& at(size_t ind) const
  {
      //?
  }

  // сравнение
  bool operator==(const TDynamicVector& v) const noexcept
  {
      if(v.sz != sz)
          return false;
      for(int i = 0;i<sz;i++){
          if(pMem[i] != v.pMem[i])
              return false;
      }
      return true;
  }
  bool operator!=(const TDynamicVector& v) const noexcept
  {
      if(*this == v)
          return false;
      return true;
  }

  // скалярные операции
  TDynamicVector operator+(T val)
  {
      TDynamicVector t(sz);
      for(int i = 0;i<sz;i++){
          t.pMem[i]=pMem[i] + val;
      }
      return t;
  }
  TDynamicVector operator-(double val)
  {
      TDynamicVector t(sz);
      for(int i = 0;i<sz;i++){
          t.pMem[i]=pMem[i] - val;
      }
      return t;
  }
  TDynamicVector operator*(double val)
  {
      TDynamicVector t(sz);
      for(int i = 0;i<sz;i++){
          t.pMem[i]=pMem[i] * val;
      }
      return t;
  }

  // векторные операции
  TDynamicVector operator+(const TDynamicVector& v)
  {
      TDynamicVector t(max(sz, v.sz));
      for(int i = 0;i<t.sz;i++){
          if(i < sz && i<v.sz)
            t.pMem[i] = pMem[i] + v.pMem[i];
          else if(i < sz)
              t.pMem[i] = pMem[i];
          else if(i < v.sz)
              t.pMem[i] = v.pMem[i];
      }
      return t;
  }
  TDynamicVector operator-(const TDynamicVector& v)
  {
      TDynamicVector t(max(sz, v.sz));
      for(int i = 0;i<t.sz;i++){
          if(i < sz && i<v.sz)
            t.pMem[i] = pMem[i] - v.pMem[i];
          else if(i < sz)
              t.pMem[i] = pMem[i];
          else if(i < v.sz)
              t.pMem[i] = v.pMem[i];
      }
      return t;
  }
  T operator*(const TDynamicVector& v) noexcept(noexcept(T()))
  {
      T ans{};
      int size = min(sz, v.sz);
      for(int i = 0;i<size;i++){
          ans += pMem[i] * v.pMem[i];
      }
      return ans;
  }

  friend void swap(TDynamicVector& lhs, TDynamicVector& rhs) noexcept
  {
    std::swap(lhs.sz, rhs.sz);
    std::swap(lhs.pMem, rhs.pMem);
  }

  // ввод/вывод
  friend istream& operator>>(istream& istr, TDynamicVector& v)
  {
    for (size_t i = 0; i < v.sz; i++)
      istr >> v.pMem[i]; // требуется оператор>> для типа T
    return istr;
  }
  friend ostream& operator<<(ostream& ostr, const TDynamicVector& v)
  {
    for (size_t i = 0; i < v.sz; i++)
      ostr << v.pMem[i] << ' '; // требуется оператор<< для типа T
    return ostr;
  }
};


// Динамическая матрица - 
// шаблонная матрица на динамической памяти
template<typename T>
class TDynamicMatrix : private TDynamicVector<TDynamicVector<T>>
{
  using TDynamicVector<TDynamicVector<T>>::pMem;
  using TDynamicVector<TDynamicVector<T>>::sz;
public:
  TDynamicMatrix(size_t s = 1) : TDynamicVector<TDynamicVector<T>>(s)
  {
    for (size_t i = 0; i < sz; i++)
      pMem[i] = TDynamicVector<T>(sz);
  }

  using TDynamicVector<TDynamicVector<T>>::operator[];

  // сравнение
  bool operator==(const TDynamicMatrix& m) const noexcept
  {
     if(sz != m.sz){
         return false;
     }
     for(int i = 0;i<sz;i++){
         if(pMem[i] != m.pMem[i])
             return false;
     }
     return true;
  }

  // матрично-скалярные операции
  TDynamicMatrix<T> operator*(const T& val)
  {
      TDynamicMatrix t(sz);
      for(int i = 0;i<sz;i++){
          t.pMem[i]=pMem[i] * val;
      }
      return t;
  }

  // матрично-векторные операции
  TDynamicVector<T> operator*(const TDynamicVector<T>& v)
  {
      TDynamicVector t(sz);
      for(int i = 0;i<sz;i++){
          T tmp{};
          for(int j = 0;j<sz;j++){
              tmp+= v[i] * pMem[i][j];
          }
          t[i] = tmp;
      }
      return t;
  }

  // матрично-матричные операции
  TDynamicMatrix operator+(const TDynamicMatrix& m)
  {
      TDynamicMatrix t(sz);
      for(int i = 0;i<sz;i++){
          t[i] = pMem[i] + m.pMem[i];
      }
      return t;
  }
  TDynamicMatrix operator-(const TDynamicMatrix& m)
  {
      TDynamicMatrix t(sz);
      for(int i = 0;i<sz;i++){
          t[i] = pMem[i] - m.pMem[i];
      }
      return t;
  }
  TDynamicMatrix operator*(const TDynamicMatrix& m)
  {
      TDynamicMatrix t(sz);
      for(int i = 0;i<sz;i++){
          for(int j = 0;j<sz;j++){
              T tmp{};
              for(int k = 0;k<sz;k++){
                  tmp+= pMem[i][k] * m.pMem[j][k];
              }
              t[i][j] = tmp;
          }
      }
      return t;
  }

  // ввод/вывод
  friend istream& operator>>(istream& istr, TDynamicMatrix& v)
  {
      for(int i = 0;i<sz;i++){
          istr>>v.pMem[i];
      }
      return istr;
  }
  friend ostream& operator<<(ostream& ostr, const TDynamicMatrix& v)
  {
      for(int i = 0;i<v.sz;i++){
          ostr<<v.pMem[i]<<'\n';
      }
      return ostr;
  }
};

#endif
