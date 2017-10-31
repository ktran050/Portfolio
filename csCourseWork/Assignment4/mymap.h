#include <set>
#include <iostream>
using namespace std;

template< typename Key, typename T >
class map_pair { 
public:
  const Key first;
  mutable T second;
  map_pair( Key s, T t ) : first(s), second(t) {}
}; // end of map_pair


template< typename Key, typename T >
struct classcomp {
  typedef map_pair< const Key, T > Pair;                  // short name
  bool operator() ( const Pair& lhs, const Pair& rhs ) const {
    return lhs.first < rhs.first;
  }
}; // end classcomp


template < typename Key, typename T >
class mymap {
public:

  typedef map_pair< const Key, T > Pair;                  // short name
  typedef set< Pair, classcomp< const Key, T> > PairSet;  // short name

  PairSet theSet;

  pair<typename PairSet::iterator, bool> insert( Pair p ) {
    return theSet.insert( p );
  }
    
  T& operator[]( const Key x ) {
    pair<typename PairSet::iterator,bool> i = insert( Pair(x,T()) );
    return i.first->second;
  }

  typename PairSet::iterator find( const Key& x ) const { 
    return theSet.find( Pair( x, T() ) );        
  }
  typename PairSet::iterator end(){
      return theSet.end();
  }

}; // end of mymap