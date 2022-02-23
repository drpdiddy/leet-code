/*Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.



Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]


Constraints:

1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1


Follow up: Could you minimize the total number of operations done?*/
//[0]
//[1]
//[1,0]
//[0,1,1]
void moveZeroes(int* nums, int numsSize) {

    int j = 0;

    while (j < numsSize && nums[j]!=0)
       j++;

    for (int i=j+1; i < numsSize; i++) {
       /*j=0, i=1, [0,1,1]*/
       /*j=1, i=2, [1,0,1]*/
       /*j=1, i=2, [1,1,0]*/
       if (nums[i]!=0) {
           int temp = nums[i];
           nums[i] = nums[j];
           nums[j] = temp;
           j++;
       }
    }
}