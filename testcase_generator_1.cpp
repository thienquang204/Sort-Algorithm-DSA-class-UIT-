#include <bits/stdc++.h>
#include "MTRand.h"
MTRand rng;

using namespace std;
int main() {
    freopen("testcase_02.input", "w", stdout);
    vector<double> output_result;
    for (int i = 1; i <= 1000000; i++) {
        double x = rng.randDblExc();
        output_result.push_back(x);
    }
    sort(output_result.begin(),output_result.end());
    std::reverse(output_result.begin(),output_result.end());
    for (auto x: output_result) {
        cout << x << " ";
    }
    
}