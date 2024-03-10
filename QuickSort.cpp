#include <bits/stdc++.h>
using namespace std;

const int N=1e6+10;

int n;
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
double A[N];

int get(int a,int b){
    if(a==b) return a;
    int t=rd();
    t=abs(t);
    return a+ t%(b-a+1);
}

void quick_sort(int l,int r){
    if(l>=r) return;
    int chot=get(l,r);
    swap(A[chot],A[r]);
    chot=r;
    int lefft=l;
    int right=r-1;
    while(lefft<=right){
        while(lefft<=right && A[lefft]<=A[chot]) lefft++;
        while(lefft<=right && A[right]>A[chot]) right--;
        if(lefft<=right){
            swap(A[lefft],A[right]);
            lefft++;
            right--;
        }
    }
    swap(A[chot],A[lefft]);
    quick_sort(l,lefft-1);
    quick_sort(lefft+1,r);
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

    for(int i=1; i<=1e6+1; i++) cin>>A[i];

    
    auto start = std::chrono::high_resolution_clock::now();
    
    quick_sort(1,N);

    auto end = std::chrono::high_resolution_clock::now();

    duration<double> exec_time = end - start; 

    cout << exec_time.count() << endl;   
}