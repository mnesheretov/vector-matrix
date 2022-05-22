#include "Vectors.h"
#include "Matrix.h"

using namespace std;



int main()
{
  setlocale(LC_ALL, "Russian");
  TVector<int> v1;
  TVector<int> v2(4, 2);
  TVector<int> v3(v2);
  v1.Resize(4);
  cin >> v2;
  for (int i = 0; i < v1.GetLength(); i++)
    v1[i] = rand() % 50 + 10;
  cout << "\n\n\n\n----------------------------------\n\n\n\n";

  v3 = v1 + v2;

  cout << "Вектор 3 = Вектор 1 + Вектор 2 =\n" << v1 << "+  " << v2 << "=  " << v3 << "\n";

  cout << "\n\n\n\n__________________________________\n\n\n\n";

  v3 = v1 - v2;

  cout << "Вектор 3 = Вектор 1 - Вектор 2 =\n" << v1 << "-  " << v2 << "=  " << v3 << "\n";

  cout << "\n\n\n\n__________________________________\n\n\n\n";

  v1 = v2 * v3;

  cout << "Вектор 1 = Вектор 2 * Вектор 3 =\n" << v2 << "*  " << v3 << "=  " << v1 << "\n";

  cout << "\n\n\n\n__________________________________\n\n\n\n";

  v3 = v1 / v2;

  cout << "Вектор 3 = Вектор 1 / Вектор 2 =\n" << v1 << "/  " << v2 << "=  " << v3 << "\n";

  cout << "\n\n\n\n__________________________________\n\n\n\n";

  TMatrix<int> m1;
  TMatrix<int> m2(2, 3);
  TMatrix<int> m3(m2);
  TMatrix<int> m4(4, 5);
  int** indexs;
  cin >> m2;
  cout << m2;

  cout << "\n\n\n\n__________________________________\n\n\n\n";

  for (int i = 0; i < m3.GetWidth(); i++)
    for (int j = 0; j < m3.GetLength(); j++)
      m3[i][j] = rand();
  cout << "Матрица 3 = \n" << m3;

  cout << "\n\n\n\n__________________________________\n\n\n\n";

  m1 = m2 + m3;
  cout << "Матрица 1 = Матрица 2 + Матрица 3 =\n"
    << m2 << "\n + \n\n" << m3 << "\n = \n\n" << m1 << "\n";

  cout << "\n\n\n\n__________________________________\n\n\n\n";

  m2 = m3 - m1;
  cout << "Матрица 2 = Матрица 3 - Матрица 1 =\n"
    << m3 << "\n - \n\n" << m1 << "\n = \n\n" << m2 << "\n";

  cout << "\n\n\n\n__________________________________\n\n\n\n";

  m1.Resize(2, 2);
  m2.Resize(2, 2);
  m3.Resize(2, 2);
  m3 = m2 * m1;
  cout << "Матрица 3 = Матрица 2 * Матрица 1 =\n"
    << m2 << "\n * \n\n" << m1 << "\n = \n\n" << m3 << "\n";

  cout << "\n\n\n\n__________________________________\n\n\n\n";

  for (int i = 0; i < m4.GetWidth(); i++)
    for (int j = 0; j < m4.GetLength(); j++)
      m4[i][j] = rand() % 50;
  v1 = m4 * v2;
  cout << "Вектор 1 = Матрица 4 * Вектор 2 = \n" << m4 << "\n *\n\n" << v2 << "\n\n =\n\n" << v1;

  cout << "\n\n\n\n__________________________________\n\n\n\n";


 

  TMatrix<int> m5(v2.GetLength(), m4.GetLength());
  m4.Resize(1, m4.GetLength());
  m5 = v2 * m4;
  cout << "Матрица 5 = Вектор 2 * Матрица 4 = \n" << v2 << "\n *\n\n" << m4
    << "\n\n = \n\n" << m5;

  cout << "\n\n\n\n__________________________________\n\n\n\n";

  return 0;
}