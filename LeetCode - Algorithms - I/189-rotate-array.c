/*
Given an array, rotate the array to the right by k steps, where k is non-negative.


Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation:
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]


Constraints:

1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
0 <= k <= 105
*/
//"Obvious way" with an extra array: copy k,...n to 0..n-k, copy 0..k to n-k to n.
//Without an extra array: swap every kth element
//nums = [0, 1, 2, 3], k = 2
//nums = [0, 1], k = 3

void rotate(int* nums, int numsSize, int k) {

  if (k==0)
    return;

  if (k > numsSize)
     k = k % numsSize;

  int *buffer = (int *) malloc(numsSize*sizeof(int));

  for (int i=0; i < numsSize; i++)
     /*n=4, k=2, [2,3,0,1] [3,2,0,1]*/
     buffer[(i + k) % numsSize] = nums[i];

  for (int i=0; i < numsSize; i++)
     nums[i] = buffer[i];

  free(buffer);

}