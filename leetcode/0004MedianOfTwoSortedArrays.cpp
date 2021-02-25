#include "stdafx.h"

using namespace my_util;

/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.
Find the median of the two sorted arrays. The overall run time complexity should be O(log(m+n)).
You may assume num1 and nums2 cannot be both empty.

fn(A, B)
1. make sure the size of A is not greater than that of B
2. binary search index i in A and j in B
    left_part                |  right_part
    A[0], A[1], ..., A[i-1]  |  A[i], A[i+1], ..., A[m-1]
    B[0], B[1], ..., B[j-1]  |  B[j], B[j+1], ..., B[n-1]
    so that
    1. len(left_part) = len(right_part)
    2. max(left_part) < min(right_part)
3. if we meet this condition i and j. we can get the median based on different conditions

Some Important Notes:
1. the reason of j = (m+n+1)/2, why it is "+1"
when the sum length of A and B is even then, we have i + j = m - i + n - j
when the sum length of A and B is odd then, we have i + j = m - i + n - j + 1
because of int casting, when m + n is even, then i + j = (m + n) / 2 = (m + n + 1)/2
which helps to uniform the condition between odd and even
2. the reason of i<imax in front of nums1[i] < nums2[j-1]
prevent index overflow in the array
*/

class Solution4
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size(), n = nums2.size();
        if (m > n) //makes sure always m <= n
        {
            nums1.swap(nums2);
            swap(m, n);
        }
        int min_i = 0, max_i = m, half_length = (m + n + 1) / 2;
        while (min_i <= max_i)
        {
            int i = (min_i + max_i) / 2;
            int j = half_length - i;
            if (i < max_i && nums1[i] < nums2[j - 1]) // needs to judge i and imax first!
                min_i = i + 1;
            else if (i > min_i && nums1[i - 1] > nums2[j])
                max_i = i - 1;
            else
            {
                int left_max = 0;
                if (i == 0)
                    left_max = nums2[j - 1];
                else if (j == 0)
                    left_max = nums1[i - 1];
                else
                    left_max = find_max(nums1[i - 1], nums2[j - 1]);
                if ((m + n) % 2 == 1) // add condition only return left_max value
                    return left_max;
                int right_min = 0;
                if (i == m)
                    right_min = nums2[j];
                else if (j == n)
                    right_min = nums1[i];
                else
                    right_min = find_min(nums1[i], nums2[j]);
                return (left_max + right_min) / 2.0;
            }
        }
        return 0.0;
    }
};

//void main()
//{
//    vector<int> a { 1, 3 };
//    vector<int> b{ 2 };
//    Solution4 s;
//    cout << s.findMedianSortedArrays(a, b) << endl;
//}