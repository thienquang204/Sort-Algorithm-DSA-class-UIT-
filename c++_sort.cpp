#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
double A[N];

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

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    
    auto start = std::chrono::high_resolution_clock::now();
    
    sort(A+1,A+1+N);

    auto end = std::chrono::high_resolution_clock::now();

    duration<double> exec_time = end - start; 

    cout << exec_time.count() << endl;   
}