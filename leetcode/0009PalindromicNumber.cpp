#include "stdafx.h"

/*
Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:

Input: x = 121
Output: true
Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

*/
class Solution9
{
public:
    /*
    Covert half of the integer can compare it with the other half
    */
    bool isPalindrome(int x)
    {
        // Special cases:
        // As discussed above, when x < 0, x is not a palindrome.
        // Also if the last digit of the number is 0, in order to be a palindrome,
        // the first digit of the number also needs to be 0.
        // Only 0 satisfy this property.
        if (x < 0 || (x % 10 == 0 && x != 0))
            return false;
        int res = 0;
        while (x > res)
        {
            res = res * 10 + x % 10;
            x /= 10;
        }

        // When the length is an odd number, we can get rid of the middle digit by revertedNumber/10
        // For example when the input is 12321, at the end of the while loop we get x = 12, revertedNumber = 123,
        // since the middle digit doesn't matter in palidrome(it will always equal to itself), we can simply get rid of it.
        return res == x || res / 10 == x;
    }

    /*
    My Dummy Solution
    */
    bool isPalindrome_bad(int x)
    {
        if (x < 0)
            return false;
        int res = 0, temp = x;
        while (x)
        {
            int pop = x % 10;
            x /= 10;
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && pop > 7))
                return false;
            if (res < INT_MIN / 10 || (res == INT_MIN / 10 && pop < -8))
                return false;
            res = res * 10 + pop;
        }
        return res == temp;
    }
};

//void main()
//{
//    Solution9 s;
//    s.isPalindrome(121);
//}