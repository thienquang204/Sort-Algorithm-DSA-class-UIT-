#include <bits/stdc++.h>
using namespace std;

const int N=1e6+10;

int n;
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
double A[N];

void MAX_HEAPIFY(double a[], int i, int n)
{
  int l,r,largest;
  double loc;
  l=2*i;
  r=(2*i+1);
  if((l<=n)&&a[l]>a[i])
    largest=l;
  else
    largest=i;
  if((r<=n)&&(a[r]>a[largest]))
    largest=r;
  if(largest!=i)
    {
      loc=a[i];
      a[i]=a[largest];
      a[largest]=loc;
      MAX_HEAPIFY(a, largest,n);
    }
}
void BUILD_MAX_HEAP(double a[], int n)
{
  for(int k = n/2; k >= 1; k--)
    {
      MAX_HEAPIFY(a, k, n);
    }
}
void HEAPSORT(double a[], int n)
{

  BUILD_MAX_HEAP(a,n);
  int i;
  double temp;
  for (i = n; i >= 2; i--)
    {
      temp = a[i];
      a[i] = a[1];
      a[1] = temp;
      MAX_HEAPIFY(a, 1, i - 1);
    }
}





int main(int argc, char *argv[]) {
    using namespace std::chrono;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    assert(argc == 2);

    char parameterStr[1000];

    string instanceFile;
    
    sscanf(argv[1],"%s", parameterStr); instanceFile = string(parameterStr);
    freopen(instanceFile.c_str(), "r", stdin);

    for(int i=0; i<1e6; i++) cin>>A[i];

    
    auto start = std::chrono::high_resolution_clock::now();
    
    HEAPSORT(A,N);

    auto end = std::chrono::high_resolution_clock::now();

    duration<double> exec_time = end - start; 
    cout << exec_time.count() << endl;   
}