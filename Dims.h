#include <vector>
#include <iostream>

using namespace std;

template <int D, class T>
class Dim {
  public:
    Dim()    : dim(T()), dims()  {}
    Dim(T v) : dim(v),   dims(v-1) {
    }

    T dim;
    Dim<D-1,T> dims;
};

template <class T>
class Dim<1,T> {
  public:
    Dim()    : dim(T()) {}
    Dim(T v) : dim(v)   {
    }

    T dim;
};
