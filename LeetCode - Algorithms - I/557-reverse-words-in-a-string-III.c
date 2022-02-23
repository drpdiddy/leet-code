/*Given a string s, reverse the order of characters in each
word within a sentence while still preserving whitespace and initial word order.

Example 1:

Input: s = "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Example 2:

Input: s = "God Ding"
Output: "doG gniD"


Constraints:

1 <= s.length <= 5 * 104
s contains printable ASCII characters.
s does not contain any leading or trailing spaces.
There is at least one word in s.
All the words in s are separated by a single space.
*/

void reverseString(char *s, int sSize) {
   int i = 0;
   int j = sSize -1;

   while (i < j) {
       char temp = s[i];
       s[i] = s[j];
       s[j] = temp;
       i++;
       j--;
   }

}

/*"an an"*/
char * reverseWords(char * s) {
    int i = 0;
    int j = 0;

    do {
        j++;
        if (s[j]==' ' || s[j]=='\0') {
            reverseString(s+i, j-i);
            i = j+1;
        }

    } while(s[j] !='\0');

    return s;
}