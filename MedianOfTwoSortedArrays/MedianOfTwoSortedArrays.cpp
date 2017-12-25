double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int m = nums1.size();
		int n = nums2.size();
		if(m > n){
			vector<int> Temp = nums1;
			nums1 = nums2;
			nums2 = Temp;
			
			int temp = m;
			m = n;
			n = temp;
		}
		if(n == 0)
			return -1;

		int imin = 0, imax = m, half_len = (m+n+1)>>1;
		while(imin <=imax){
			int i = (imin + imax)/2;
			int j = half_len - i;
			if((i < m) && (nums2[j-1] > nums1[i]))
				imin = i+1;
			else if ((i > 0 && (nums1[i-1] > nums2[j])))
				imax = i-1;
			else{
				int max_of_left;
				if(i==0)
					max_of_left = nums2[j-1];
				else if(j==0)
					max_of_left = nums1[i-1];
				else
					max_of_left = max(nums1[i-1], nums2[j-1]);

				if((m+n)%2 == 1)
					return max_of_left;

				int min_of_right;
				if(i==m)
					min_of_right = nums2[j];
				else if(j==n)
					min_of_right = nums1[i];
				else
					min_of_right = min(nums1[i], nums2[j]);

				return (max_of_left + min_of_right)/2.0;
			}
		}
	}

/*
https://leetcode.com/problems/median-of-two-sorted-arrays/discuss/

分别从 i 和 j 处将数组 A 和 B 分为两边，然后将两者组合

      left_part          |        right_part
A[0], A[1], ..., A[i-1]  |  A[i], A[i+1], ..., A[m-1]
B[0], B[1], ..., B[j-1]  |  B[j], B[j+1], ..., B[n-1]
需要同时满足以下2个条件：
1）len(left_part) == len(right_part)
2）max(left_part) <= min(right_part)

即：
1）i+j == m-i+n-j (偶数) m-i+n-j+1（奇数）
   如果 n>=m ，那么依次取（程序使用二分法搜索） i=0~m，j=(m+n+1)/2-i
2）B[j-1] <= A[I] and A[i-1] <= B[j]
*/