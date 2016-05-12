#include <cstddef>

template <class T> class Ref_handle {
 public:
  Ref_handle (): p(0), refptr (new std::size_t (1)) { }
  Ref_handle (T* t): p (t), refptr (new std::size_t (1)) { }
  Ref_handle (const Ref_handle& h): p (h.p), refptr (h.refptr) {
    ++*refptr;
  }

  Ref_handle& operator=(const Ref_handle&);
  ~Ref_handle ();

 private:
  T* p;
  std::size_t* refptr;
};
