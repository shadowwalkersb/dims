#include <vector>
#include <iostream>

using namespace std;

template <int D, class T>
class Dim {
  public:
    Dim()    : dim(T()), dims()  {}
    Dim(T v) : dim(v),   dims(v-1) {
    }

    T& operator[](int d) {
      return const_cast<T &>(static_cast<const Dim<D,T>& >(*this)[d]);
    }
    
    const T& operator[](int d) const {
      return d==D ? dim : dims[d];
    }

    T dim;
    Dim<D-1,T> dims;
};

template <int D, class T>
ostream& operator<<(ostream& out, const Dim<D,T> &obj){
    out<<obj.dims
	<<" "<<obj.dim;
  
  return out;
}

template <class T>
class Dim<1,T> {
  public:
    Dim()    : dim(T()) {}
    Dim(T v) : dim(v)   {
    }

    T& operator[](int d) {
      return const_cast<T &>(static_cast<const Dim<1,T>& >(*this)[d]);
    }

    const T& operator[](int d) const {
      return d==1 ? dim : throw out_of_range("Out of range");
    }

    T dim;
};

template <class T>
ostream& operator<<(ostream& out, const Dim<1,T> &obj){
    out<<obj.dim;
  
  return out;
}
