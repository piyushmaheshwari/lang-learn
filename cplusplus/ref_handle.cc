#include "ref_handle.h"

template <class T>
Ref_handle<T>& Ref_handle<T>::operator=(const Ref_handle& rhs) {
  ++*rhs.refptr;
  if (--*refptr == 0){
    delete p;
    delete refptr;
  }
  refptr = rhs.refptr;
  p = rhs.p;
  return *this;
}

template <class T> Ref_handle<T>::~Ref_handle () {
  if (--*refptr == 0) {
    delete p;
    delete refptr;
  }
}

int main () {
  return 0;
}
