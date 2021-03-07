/**
 * Nearly every one have used the Multiplication Table. But could you find out the k-th smallest number quickly from the multiplication table?
 * Given the height m and the length n of a m * n Multiplication Table, and a positive integer k,
 * you need to return the k-th smallest number in this table.
 *
 * The m and n will be in the range [1, 30000].
 * The k will be in the range [1, m * n]
 */

 //binary search
class Solution
{
private:
	int findKthPos(int m, int n, int k)
	{
		int count = 0;
		for (int i = 1; i <= n; i++)
			count += m > k / i ? k / i : m;
		return count;
	}
public:
	int findKthNumber(int m, int n, int k)
	{
		int l = 1, r = m * n;	//l, r are the left and right bounder of multiplication table
		while (l < r)
		{
			int mid = (l + r) / 2;
			int ele = findKthPos(m, n, mid);	//find the pos of mid 
			if (ele >= k)
			{
				r = mid;
			}
			else
			{
				l = mid + 1;
			}
		}
		return r;
	}
};
