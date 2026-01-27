#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cout<<"Enter the no of input you want to give : ";
    cin >> N;

    vector<char> arr(N);
    for (int i = 0; i < N; i++) {
        cout<<"Give the "<<i<<" input : ";
        cin >> arr[i];
    }
    unordered_map<int, int> mp;
    int sum = 0;
    int maxLen = 0;

    mp[0] = -1;

    for (int i = 0; i < N; i++) {
        if (arr[i] == 'P')
            sum += 1;
        else if (arr[i] == 'A')
            sum -= 1;
        if (mp.find(sum) != mp.end()) {
            int len = i - mp[sum];
            maxLen = max(maxLen, len);
        } else {
            mp[sum] = i;
        }
    }
    cout << maxLen << endl;
    return 0;
}
