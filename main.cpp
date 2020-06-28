#include <iostream> 
#include <queue>
using namespace std;

const int a = 3, b = 4, c = 2;
const int N = a * (b+1) + b + 1;
int parent[N];

int convert(int x, int y){
  return x * (b+1) + y;
}

void revert(int k, int& x, int& y)
{
  x = (int) k / (b+1);
  y = k % (b+1);
}

void traceBack(int k)
{
  if (parent[k] > -1)
  {
    traceBack(parent[k]);
  }
  int x, y;
  revert(k,x,y);
  cout << "(" << x << "," << y << ")->";
}

void waterjug()
{
  bool visisted[N] = {false};
  int x = 0, y = 0;
  int x1, y1, u;
  queue<int> Q;
  int k = convert(x, y); 
  Q.push(k); visisted[k] = true;
  bool hasSolution = false;
  while (!Q.empty())
  {
    k = Q.front(); Q.pop(); // Lay trang thai o dau hang doi 
    revert(k,x,y);
    if ( (x == c) || (y == c) )
    {
      hasSolution = true;
      break;
    }

    x1 = x; y1 = 0;
    u = convert(x1,y1);
    if (!visisted[u]) {
      Q.push(u); visisted[u] = true; parent[u] = k;
    }

    x1 = 0; y1 = y;
    u = convert(x1,y1);
    if (!visisted[u]) {
      Q.push(u); visisted[u] = true; parent[u] = k;
    }

    x1 = a; y1 = y;
    u = convert(x1,y1);
    if (!visisted[u]) {
      Q.push(u); visisted[u] = true; parent[u] = k;
    }

    x1 = x; y1 = b;
    u = convert(x1,y1);
    if (!visisted[u]) {
      Q.push(u); visisted[u] = true; parent[u] = k;
    }

    if (x + y >= a){ // Do tu binh 2 sang binh 1
      x1 = a; y1 = x+y-a;
    } else {
      x1 = x+y; y1 = 0;
    }
    u = convert(x1,y1);
    if (!visisted[u]) {
      Q.push(u); visisted[u] = true; parent[u] = k;
    }

    if (x + y >= b){ // Do tu binh 1 sang binh 2
      x1 = x+y-b; y1 = b;
    } else {
      x1 = 0; y1 = x+y;
    }
    u = convert(x1,y1);
    if (!visisted[u]) {
      Q.push(u); visisted[u] = true; parent[u] = k;
    }
  }

  if (hasSolution) {
    cout << "Tim duoc loi giai \n";
    traceBack(k);
  } else {
    cout << "Khong co loi giai \n";
  }
}

int main(){ 
  for (int i = 0; i < N; i++)
  {
    parent[i] = -1;
  }
  waterjug();
 return 0;  
} 