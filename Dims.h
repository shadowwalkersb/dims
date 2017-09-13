#include <vector>
#include <iostream>
#include <type_traits>

using namespace std;

template <int D, class T>
class Dim {
  public:
    Dim()    : dim(T()), dims()  {}
    template<class... Args>
    Dim(T v, Args... args)
        : dim(v),   dims(args...)
    {
            static_assert(sizeof...(Args)+1==D, "Wrong number of arguments");
    }

    T& operator[](int d) {
      return const_cast<T &>(static_cast<const DimBase<D,T>& >(*this)[d]);
    }
    
    const T& operator[](int d) const {
      return d==D ? dim : dims[d];
    }

    T dim;
    Dim<D-1,T> dims;
};

template <int D, class T>
ostream& operator<<(ostream& out, const DimBase<D,T> &obj){
    out<<obj.dims
	<<" "<<obj.dim;
  
  return out;
}

template <class T>
class Dim<1,T> {
  public:
    Dim()    : dim(T()) {}

    Dim(T v)
    : dim(v)
    {
    }

    T& operator[](int d) {
      return const_cast<T &>(static_cast<const DimBase<1,T>& >(*this)[d]);
    }

    const T& operator[](int d) const {
      return d==1 ? dim : throw out_of_range("Out of range");
    }

    T dim;
};

template <class T>
ostream& operator<<(ostream& out, const DimBase<1,T> &obj){
    out<<obj.dim;
  
  return out;
}
