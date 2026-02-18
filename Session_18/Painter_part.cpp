class Solution {
  public:
    bool canPaint(vector<int>& arr, int k, long long maxTime) {
        long long curr = 0;
        int painters = 1;

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > maxTime) return false;
            if (curr + arr[i] <= maxTime) {
                curr += arr[i];
            } 
            else {
                painters++;
                curr = arr[i];
            }
        }
        return painters <= k;
    }
    int minTime(vector<int>& arr, int k) {
        long long low = 0, high = 0;
        for (int x : arr) {
            low = max(low, (long long)x);
            high += x;
        }
        long long ans = high;
        while (low<=high) {
            long long mid=(low+high)/2;

            if (canPaint(arr, k, mid)) {
                ans = mid;
                high = mid-1;
            } 
            else {
                low = mid+1; 
            }
        }

        return (int)ans;
    }
};
