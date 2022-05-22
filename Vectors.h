#pragma once
#include <iostream>

template <class T>
class TVector
{
public:
  TVector();
  TVector(int c, T d);
  TVector(const TVector<T>& p);
  ~TVector();

  void SetLen(int l);
  int GetLength();
  void Resize(int newLength);

  TVector<T> operator +(const TVector<T>& p);
  TVector<T> operator -(const TVector<T>& p);
  TVector<T> operator *(const TVector<T>& p);
  TVector<T> operator /(const TVector<T>& p);
  TVector<T>& operator =(const TVector<T>& p);
  bool operator ==(const TVector<T>& p);
  bool operator !=(const TVector<T>& p);

  T& operator [](int i);

  template <class T>
  friend std::ostream& operator << (std::ostream& B, TVector<T>& A);
  template <class T>
  friend std::istream& operator >> (std::istream& B, TVector<T>& A);

protected:
  T* data;
  int length;
};

template<class T>
inline TVector<T>::TVector()
{
  length = 0;
  data = nullptr;
}

template<class T>
inline TVector<T>::TVector(int c, T d)
{
  if (c > 0)
  {
    data = new T[c];
    length = c;
    for (int i = 0; i < length; i++)
      data[i] = d;
  }
  else throw "Ошибка!";
}

template<class T>
inline TVector<T>::TVector(const TVector<T>& p)
{
  if (p.data == nullptr)
  {
    data = nullptr;
    length = 0;
  }
  else
  {
    length = p.length;
    data = new T[length];
    for (int i = 0; i < length; i++)
      data[i] = p.data[i];
  }
}

template<class T>
inline TVector<T>::~TVector()
{
  if (data != nullptr)
  {
    delete[] data;
    data = nullptr;
  }
  length = 0;
}

template<class T>
inline void TVector<T>::SetLen(int l)
{
  this->Resize(l);
}

template<class T>
inline int TVector<T>::GetLength()
{
  return length;
}

template<class T>
inline void TVector<T>::Resize(int newLength)
{
  if (newLength <= 0) throw "Ошибка!";
  T* mas = new T[newLength];
  if (data != nullptr)
  {
    int index = 0;
    if (length > newLength) index = newLength;
    else index = length;
    for (int i = 0; i < index; i++)
      mas[i] = data[i];
    delete[] data;
  }
  data = mas;
  length = newLength;
}



template<class T>
inline TVector<T> TVector<T>::operator+(const TVector<T>& p)
{
  if (length == 0) throw "Ошибка";
  if (length != p.length) throw "Ошибка";
  TVector<T> A(length, 0);
  for (int i = 0; i < length; i++)
    A[i] = data[i] + p.data[i];
  return A;
}

template<class T>
inline TVector<T> TVector<T>::operator-(const TVector<T>& p)
{
  if (length == 0) throw "Ошибка";
  if (length != p.length) throw "Ошибка!";
  TVector<T> A(length, 0);
  for (int i = 0; i < length; i++)
    A[i] = data[i] - p.data[i];
  return A;
}

template<class T>
inline TVector<T> TVector<T>::operator*(const TVector<T>& p)
{
  if (length == 0) throw "Ошибка!";
  if (length != p.length) throw "Ошибка!";
  TVector<T> A(length, 0);
  for (int i = 0; i < length; i++)
    A[i] = data[i] * p.data[i];
  return A;
}

template<class T>
inline TVector<T> TVector<T>::operator/(const TVector<T>& p)
{
  if (length == 0) throw "Ошибка!";
  if (length != p.length) throw "Ошибка!";
  TVector<T> A(length, 0);
  for (int i = 0; i < length; i++)
    if (p.data[i] == 0) A[i] = 0;
    else A[i] = data[i] / p.data[i];
  return A;
}

template<class T>
inline TVector<T>& TVector<T>::operator=(const TVector<T>& p)
{
  if (this == &p) return *this;
  if (data != nullptr) delete[] data;
  if (p.data == nullptr)
  {
    length = 0;
    data = nullptr;
  }
  else
  {
    length = p.length;
    data = new T[length];
    for (int i = 0; i < length; i++)
      data[i] = p.data[i];
  }
  return *this;
}

template<class T>
inline bool TVector<T>::operator==(const TVector<T>& p)
{
  if (length != p.length) return false;
  for (int i = 0; i < length; i++)
    if (data[i] != p.data[i]) return false;
  return true;
}

template<class T>
inline bool TVector<T>::operator!=(const TVector<T>& p)
{
  if (length != p.length) return true;
  for (int i = 0; i < length; i++)
    if (data[i] != p.data[i]) return true;
  return false;
}

template<class T>
inline T& TVector<T>::operator[](int i)
{
  if (data == nullptr)
    throw "Ошибка!";
  if (i < 0 || i >= length)
    throw "Ошибка!";
  return data[i];
}

template<class T>
inline std::ostream& operator<<(std::ostream& B, TVector<T>& A)
{
  for (int i = 0; i < A.GetLength(); i++)
    B << A[i] << "  ";
  return B;
}

template<class T>
inline std::istream& operator>>(std::istream& B, TVector<T>& A)
{
  std::cout << "Введите " << A.length << " значения вектора: \n";
  for (int i = 0; i < A.length; i++)
    B >> A[i];
  return B;
}
