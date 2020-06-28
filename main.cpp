#include <iostream> 
#include <queue>

const int N=3,M=10;
int A[N]={-1};
int M_tren=-1,M_duoi=-1,m=-1,f=-1,scout=-1,i=-1;

void print(int k)
{
  for(k=0;k<N;k++)
  std::cout<<A[k]<<" ";
  std::cout<<scout;
}

void TRY(int i)
{
  
if(i==N)
  {
    M_tren=M_duoi=M-f;
  }
  else 
  {
    M_tren=M-f-(N-i);
    M_duoi=1;
  }
  for(int v=M_duoi;v<=M_tren;v++)
    {
      A[i]=v;
      f+=v;
      if(i==N) 
      {
        print(v);
        scout++;
      }
      else TRY(i+1);
      f-=v;
    }
}

int main()
{
  TRY(3);
  return 0;
}