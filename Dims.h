#include <vector>
#include <iostream>

using namespace std;

template <int D, class T>
class Dim {
  public:
    Dim()
	    : vals(D, T())
      {}
    
    template<class... Args>
    Dim(Args... args)
            : vals({args...})
    {
            static_assert(sizeof...(args)==D, "Wrong number of arguments");
    }
    
    T& operator[](int d) {
      return const_cast<T &>(static_cast<const Dim<D,T>& >(*this)[d]);
    }

    const T& operator[](int d) const {
      return vals[d-1];
    }

    vector<typename enable_if<is_arithmetic<T>::value,T>::type> vals;
};

template <int D, class T>
ostream& operator<<(ostream& out, const Dim<D,T> &obj){
  for(typename vector<T>::const_iterator it=obj.vals.begin();
		  it!=obj.vals.end();
		  ++it
     )
    out<<" "<<*it;
  
  return out;
}
