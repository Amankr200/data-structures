#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findClosestIndex(vector<int>& arr, int x) {
        int n = arr.size();
        int low = 0, high = n - 1;
        
        // standard binary search
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == x) return mid;
            else if (arr[mid] < x) low = mid + 1;
            else high = mid - 1;
        }

        // Now arr[high] < x < arr[low], OR out of bounds
        if (low == 0) return 0;             // x smaller than all elements
        if (low == n) return n - 1;         // x larger than all elements
        
        // pick the smaller element (just before x)
        return high;
    }
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int pos = findClosestIndex(arr, x);
        
        int left = pos, right = pos + 1; // start with pos and expand
        vector<int> ans;

        while (k--) {
            if (left < 0) {
                ans.push_back(arr[right++]);
            } else if (right >= n) {
                ans.push_back(arr[left--]);
            } else {
                // choose closer element
                if (abs(arr[left] - x) <= abs(arr[right] - x)) {
                    ans.push_back(arr[left--]);
                } else {
                    ans.push_back(arr[right++]);
                }
            }
        }
        
        sort(ans.begin(), ans.end()); // final result should be sorted
        return ans;
    }
};
