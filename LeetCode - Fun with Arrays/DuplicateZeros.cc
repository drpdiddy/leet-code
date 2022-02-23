/**
 Given a fixed-length integer array arr, duplicate each occurrence of zero, 
 shifting the remaining elements to the right.

Note that elements beyond the length of the original array are not written. 
Do the above modifications to the input array in place and do not return anything.

Example 1:

Input: arr = [1,0,2,3,0,4,5,0]
Output: [1,0,0,2,3,0,0,4]
Explanation: After calling your function, the input array is modified to: [1,0,0,2,3,0,0,4]
Example 2:

Input: arr = [1,2,3]
Output: [1,2,3]
Explanation: After calling your function, the input array is modified to: [1,2,3]
 
Constraints:

1 <= arr.length <= 104
0 <= arr[i] <= 9
 * 
 */
lass Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        
        auto k = 0;
        auto n = arr.size();
        
        for (auto i=0; i < n; i++)
            if (arr[i]==0) k++;
        
        for (auto i = 0; i < n-k; i++)
            arr[n-i-1] = arr[n-k-i-1];
        
        int j = 0;
        for (auto i=k; i<n; i++) {
            arr[j] = arr[i];
            
            if (arr[j]==0) 
                arr[++j] = 0;
            j++;

        }
            
    }
};