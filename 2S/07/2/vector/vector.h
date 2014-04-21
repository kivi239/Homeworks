#include <iostream>

using namespace std;

template <typename T, int size>
class Vector
{
public:
  Vector();
  Vector(const Vector &);
  ~Vector();

  Vector<T, size> operator +(Vector &);
  Vector operator - (Vector &);
  T operator * (Vector &);
  bool isZero();
  void print();

  T *array;
};

template <typename T, int size>
Vector<T, size>::Vector() : array(new T[size])
{
  for (int i = 0; i < size; i++)
    array[i] = 0;
}

template <typename T, int size>
Vector<T, size>::Vector(const Vector &vec)
{
  array = new T[size];
  for (int i = 0; i < size; i++)
    array[i] = vec.array[i];
}

template <typename T, int size>
Vector<T, size>::~Vector()
{
  delete array;
}

template <typename T, int size>
Vector<T, size> Vector<T, size>::operator + (Vector &vec)
{
  Vector<T, size> result;
  for (int i = 0; i < size; i++)
    result.array[i] = array[i] + vec.array[i];

  return result;
}

template <typename T, int size>
void Vector<T, size>::print()
{
  for (int i = 0; i < size; i++)
    cout << array[i] << ' ';
  cout << endl;
}

template <typename T, int size>
Vector<T, size> Vector<T, size>::operator - (Vector &vec)
{
  Vector<T, size> result;
  for (int i = 0; i < size; i++)
    result.array[i] = array[i] - vec.array[i];

  return result;
}

template <typename T, int size>
T Vector<T, size>::operator * (Vector &vec)
{
  T result = 0;
  for (int i = 0; i < size; i++)
    result += (array[i] * vec.array[i]);

  return result;
}

template <typename T, int size>
bool Vector<T, size>::isZero()
{
  for (int i = 0; i < size; i++)
    if (array[i] != 0)
      return false;

  return true;
}
