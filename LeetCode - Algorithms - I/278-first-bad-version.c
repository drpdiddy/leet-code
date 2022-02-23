/*
You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest
version of your product fails the quality check. Since each version is developed based on the previous version,
all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the
following ones to be bad.

You are given an API bool isBadVersion(version) which returns whether version is bad. Implement a
function to find the first bad version. You should minimize the number of calls to the API.

Example 1:

Input: n = 5, bad = 4
Output: 4
Explanation:
call isBadVersion(3) -> false
call isBadVersion(5) -> true
call isBadVersion(4) -> true
Then 4 is the first bad version.
Example 2:

Input: n = 1, bad = 1
Output: 1


Constraints:

1 <= bad <= n <= 2^31 - 1
*/

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) {

   /*n = 0*/
   /*[B], 1*/
   /*[G], -1*/
   /*[BB]*/
   /*[GB], 2*/
   /*[GG], 2*/
   /*[GBB], 2*/
   /*[GGB], 2*/

   if (isBadVersion(1))
      return 1;

   int lower_bound = 1;
   int upper_bound = n;

   /*lower_bound=2, upper_bound=3, middle = 3*/

   while (lower_bound < upper_bound) {


      int range = upper_bound - lower_bound;

      if (range % 2 != 0)
         range += 1;

      int middle = lower_bound + range/2;

      if (!isBadVersion(middle)) /**go right*/
         lower_bound = middle;
      else if (isBadVersion(middle) && isBadVersion(middle-1))
         upper_bound = middle;
      else if (isBadVersion(middle) && !isBadVersion(middle-1)) /*go left*/
         return middle;
   }

   return -1;

}