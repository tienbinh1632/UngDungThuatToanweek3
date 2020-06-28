#include <iostream> 
#include <queue>
using namespace std;

 class Ckn {
 private: int M[][];
 public: int C( int k , int n ){
 if(k == 0 || k == n ) M[ k ][ n ] = 1;
 else if(M [k ][ n] < 0){
 M[k ][ n] = C(k -1 ,n -1) + C(k ,n -1);
 }
return M[k ][ n ];
 }
  void test (){
 M = new int [100][100];
 for ( int i = 0; i < 100; i ++)
 for ( int j = 0; j < 100; j ++)
 M[ i ][ j ] = -1;

 System . out . println (C (15 ,30));
 }
 }