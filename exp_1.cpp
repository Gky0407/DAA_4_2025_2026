#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

long long operations = 0;     
int maxDepth = 0;            

void complexRec(int n, int depth) {

   
    maxDepth = max(maxDepth, depth);
    operations++;   

    if (n <= 2) {
        return;
    }

    int p = n;
    while (p > 0) {
        vector<int> temp(n);
        operations += n;   

        for (int i = 0; i < n; i++) {
            temp[i] = i ^ p;
        }
        p >>= 1;
        operations++;     
    }

    vector<int> small(n);
    operations += n;

    for (int i = 0; i < n; i++) {
        small[i] = i * i;
    }

    reverse(small.begin(), small.end());
    operations += n;   


    complexRec(n / 2, depth + 1);
    complexRec(n / 2, depth + 1);
    complexRec(n / 2, depth + 1);
}

int main() {

    auto start = high_resolution_clock::now();

    complexRec(800, 1);

    auto end = high_resolution_clock::now();

    cout << "Time (ms): " 
         << duration_cast<milliseconds>(end - start).count() << endl;

    cout << "Total operations: " << operations << endl;
    cout << "Max recursion depth: " << maxDepth << endl;
}
