/*Given an integer array nums sorted in non-decreasing order,
 return an array of the squares of each number sorted in non-decreasing order.

Example 1:

Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].
Example 2:

Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]


Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums is sorted in non-decreasing order.

Follow up: Squaring each element and sorting the new array is very trivial, could you find an O(n) solution
using a different approach?*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/**
nums = []
nums = [-1]
nums = [-4,-1,0,3,10]
*/
int* sortedSquares(int* arr, int n, int* returnSize){

    int pos_idx = 0;

    while (pos_idx < n) {
       if (arr[pos_idx] >= 0)
          break;
       pos_idx++;
    }
    int neg_idx = pos_idx - 1;

    int sorted_idx = 0;
    int *sorted_arr = (int *) malloc(n*sizeof(int));
    *returnSize = n;

    for (sorted_idx = 0; sorted_idx < n; sorted_idx++) {
       /*n=5, sorted_idx=[], pos_idx=2, arr[pos_idx]=0, neg_idx=1, arr[neg_idx]=-1*/
       /*n=5, sorted_idx=[0], pos_idx=3, arr[pos_idx]=3, neg_idx=1, arr[neg_idx]=-1*/
       /*n=5, sorted_idx=[0,1], pos_idx=3, arr[pos_idx]=3, neg_idx=0, arr[neg_idx]=-4*/
       /*n=5, sorted_idx=[0,1,9], pos_idx=4, arr[pos_idx]=10, neg_idx=0, arr[neg_idx]=-4*/
       /*n=5, sorted_idx=[0,1,9, 16], pos_idx=4, arr[pos_idx]=10, neg_idx=-1, arr[neg_idx]=NaN*/
       /*n=5, sorted_idx=[0,1,9, 16, 100], pos_idx=4, arr[pos_idx]=10, neg_idx=-1, arr[neg_idx]=NaN*/

       sorted_arr[sorted_idx] = -1;

       if ((neg_idx >= 0 && pos_idx < n && -1*arr[neg_idx] <= arr[pos_idx])
       ||  (neg_idx >= 0 && pos_idx >= n)) {
           sorted_arr[sorted_idx] = arr[neg_idx]*arr[neg_idx];
           neg_idx--;
           continue;
       }

       if ((neg_idx >= 0 && pos_idx < n && -1*arr[neg_idx] >= arr[pos_idx])
       || (neg_idx < 0 && pos_idx < n)){
           sorted_arr[sorted_idx] = arr[pos_idx]*arr[pos_idx];
           pos_idx++;
           continue;
       }

    }

    return sorted_arr;
}