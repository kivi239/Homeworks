#include <cstdio>

template <typename T>
///Class for shared pointer
class SharedPointer
{
public:
  SharedPointer() {}
  SharedPointer(T *ptr);
  SharedPointer(SharedPointer &sPtr);
  SharedPointer& operator = (SharedPointer &sPtr);
  ~SharedPointer();
  int getCount();
  T *getPointer();

private:
  struct Pointer
  {
    T *pointer;
    int count;
    Pointer() : pointer(nullptr), count(0) {}
    Pointer(T *_pointer) : pointer(_pointer), count(1) {}
  };

  Pointer *pointer;
};

template <typename T>
SharedPointer<T>::SharedPointer(T *ptr) : pointer(new Pointer(ptr)) {}

template <typename T>
SharedPointer<T>::SharedPointer(SharedPointer<T> &sPtr)
{
  pointer = sPtr.pointer;
  pointer->count++;
}

template <typename T>
SharedPointer<T>& SharedPointer<T>::operator = (SharedPointer &sPtr)
{
  if (pointer != sPtr.pointer)
  {
    pointer->count--;
    if (pointer->count == 1)
      delete pointer->ptr;
    pointer = sPtr.pointer;
    pointer->count++;
  }

  return *this;
}

template <typename T>
SharedPointer<T>::~SharedPointer()
{
  pointer->count--;
  if (pointer->count == 0)
    delete pointer->pointer;
}

template <typename T>
int SharedPointer<T>::getCount()
{
  return pointer->count;
}

template <typename T>
T* SharedPointer<T>::getPointer()
{
  return pointer->pointer;
}
