/*
Given a sorted array of distinct integers and a target value, return the index if the target is found.
If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1
Example 3:

Input: nums = [1,3,5,6], target = 7
Output: 4
Example 4:

Input: nums = [1,3,5,6], target = 0
Output: 0
Example 5:

Input: nums = [1], target = 0
Output: 0


Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums contains distinct values sorted in ascending order.
-104 <= target <= 104
*/
/*arr = []*/
/*arr = [1], target = 0*/
/*arr = [1], target = 2*/
/*arr = [1], target = 1*/
/*arr = [1, 3], target = 2*/
/*arr = [1,3,5], target = 3*/
/*arr = [1,3,5,7], target = 4*/
/*arr = [1,3,5,6], target = 5*/
/*arr = [1,3,5,7,9], target = 3*/

int searchInsert(int* arr, int n, int target) {

   if (n==0)
      return 0;

   if (n >= 1 && arr[0] >= target)
       return 0;

   if (n>=1 && arr[n-1] < target)
      return n;

   int lower_bound = 0;
   int upper_bound = n;

   while (lower_bound < upper_bound) {

      int range = upper_bound-lower_bound;
      int middle = lower_bound + (range % 2 ? range+1 : range)/2;

      /*arr = [1,3,5,6], n = 4, target = 2*/
      /*lower_bound==0, upper_bound==4, middle==2, arr[middle-1]=3, arr[middle]=5*/
      /*lower_bound==0, upper_bound==2, middle==1, arr[middle-1]=1, arr[middle]=3*/

      if (arr[middle]==target || (target < arr[middle]  && target > arr[middle-1]))
          return middle;
      else if (arr[middle] > target)
          upper_bound = middle;
      else
          lower_bound = middle;
   }

   return -1;

}