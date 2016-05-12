#include <stdexcept>
#include "handle.h"

template <class T>
Handle<T>& Handle<T>::operator= (const Handle& rhs) {
  if (&rhs != this) { //avoid self assignment
      delete p;
      if (rhs.p)
        p = rhs.p->clone();
      else
        p = 0;
      return *this;
  }
}

template <class T>
T& Handle<T>::operator*() const {
  if (p)
    return *p;
  else
    throw std::runtime_error ("unbound handle");
}

template <class T>
T* Handle<T>::operator-> () const {
  if (p)
    return p;
  else
    throw std::runtime_error ("unbound handle");
}

int main (){
  return 0;
}
