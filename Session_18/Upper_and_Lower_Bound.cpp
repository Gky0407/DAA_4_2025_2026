#include <bits/stdc++.h>
using namespace std;


int lowerBound(vector<int>& arr, int target) {
    int f=0,l=arr.size()-1;
    int ans=arr.size();

    while (f<= l){
        int m=f+(l-f)/2;
        if (arr[m]>= target) {
            ans= m;
            l =m- 1;
        } else {
            f=m+1;
        }
    }
    return ans;
}
int upperBound(vector<int>& arr,int target) {
    int f=0,l=arr.size()- 1;
    int ans =arr.size();

    while (f<=l) {
        int m=f+(l -f) /2;
        if (arr[m]> target) {
            ans=m;
            l=m-1;
        } else {
            f=m+1;
        }
    }
    return ans;
}

int main() {


    return 0;
}
