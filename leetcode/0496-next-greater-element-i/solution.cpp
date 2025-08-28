class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;

        // For each element in nums1
        for (int i = 0; i < nums1.size(); i++) {
            int num = nums1[i];
            int nextGreater = -1; // default if no greater element found
            bool found = false;

            // Find num in nums2
            for (int j = 0; j < nums2.size(); j++) {
                if (nums2[j] == num) {
                    found = true; // element found
                }
                // Once found, check elements to the right
                if (found && nums2[j] > num) {
                    nextGreater = nums2[j];
                    break; // stop at first greater element
                }
            }

            ans.push_back(nextGreater);
        }

        return ans;
    }
};

