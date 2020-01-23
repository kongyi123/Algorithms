#include <vector>

using namespace std;

class Solution {
public:
	int n, m;
	int x;
	int half;
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		n = nums1.size();
		m = nums2.size();

		if (n == 0) {
			if (m % 2 == 0) {
				return (double)(nums2[(m - 1) / 2] + nums2[(m - 1) / 2 + 1]) / 2;
			}
			else return nums2[(m - 1) / 2];
		}
		else if (m == 0) {
			if (n % 2 == 0) {
				return (double)(nums1[(n - 1) / 2] + nums1[(n - 1) / 2 + 1]) / 2;
			}
			else return nums1[(n - 1) / 2];
		}
		half = (n + m) / 2; // 개수의 반
		return bsearch(nums1, nums2, 0, n);
	}

	double bsearch(vector<int>& nums1, vector<int>& nums2, int s, int e) { // s, e는 idx
		int left_max, right_min;

		while (s <= e) {
			int left_nums1_cnt = (s + e) / 2;
			int a, b, c, d;

			int left_cnt = 0;
			int right_cnt = 0;
			if (0 < left_nums1_cnt && left_nums1_cnt <= n) {
				a = nums1[left_nums1_cnt - 1];
				left_cnt += left_nums1_cnt;
			}
			else a = -2000000000;

			if (half - left_nums1_cnt <= m && half - left_nums1_cnt > 0) {
				c = nums2[half - left_nums1_cnt - 1];
				left_cnt += half - left_nums1_cnt;
			}
			else c = -2000000000;

			if (left_nums1_cnt + 1 <= n) {
				b = nums1[left_nums1_cnt];
				right_cnt += n - left_nums1_cnt;
			}
			else b = 2000000000;
			
			if (m - (half - left_nums1_cnt) <= m && m - (half - left_nums1_cnt) > 0) {
				d = nums2[half - left_nums1_cnt];
				right_cnt += m - (half - left_nums1_cnt);
			}
			else d = 2000000000;

			left_max = a;
			if (left_max < c) left_max = c;

			right_min = b;
			if (right_min > d) right_min = d;

			if (a > d || left_cnt > right_cnt) {
				e = left_nums1_cnt;
				continue;
			}
			if (c > b || left_cnt < right_cnt - 1) {
				s = left_nums1_cnt + 1;
				continue;
			}

			if (left_max <= right_min) {
				if ((n + m) % 2 == 0) {
					return (double)(left_max + right_min) / 2;
				}
				else return right_min;
			}
		}
		return 0;
};

int main() {
	Solution s;
	vector<int> nums1, nums2;

	nums1.push_back(1);
	nums1.push_back(3);

	
	nums2.push_back(2);


	printf("dap = %lf", s.findMedianSortedArrays(nums1, nums2));
	return 0;
}