/*
	# ����
	������ Ǯ�� ��� : 2�� ���� -> 1�� Ȯ��
	���� Ǯ� ��� : 1�� ���� -> 2�� ����

	������ �������� Ȯ���� �� ���� �ٸ���. (������ �ٲ㺼�� �˾ƾ��Ѵ�.)

	�����̴ٸ��� ����� ���� �����غ��� ���δ�.
	
		- �ΰ��� ���� �� (input x�϶�)
		1. 2�� for + x�� �� (�ĺ��� ���� filter�ϴ� ���)
		2. x���� ���ߴ� ������ �� ������ (�Է��� �ݵ�� �ʿ�, ���� ã�� �� �Է°��� �´� ���� �����ϴ� ���)

		- �Ѱ��� ���� �� (input x�϶�)
		1. map (�ڷᱸ���� ������ �� �Է¿� �´� ���� �����ϴ� ���)
		2. for + x�� �� (�ĺ��� ���� filter�ϴ� ���)

	���� ����, �Ѱ� ���¹��� �ΰ��� ���¹��� ������ ������ ���ķ� �δ��Ŀ� ���� ���ݴ� ���� �� �ִ� '���� �����ϴ� ���'�� �� ���� �ְ� �� �� ���� ���� �ְ� �ȴ�.


	# �ߺ� ���� ã�� ���
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <ctime>
#define MAIN_DEBUG 1
using namespace std;


class Solution {

public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> result;
		vector<int> t;
		int i, j, k;
		int n = nums.size();
		if (n == 0) return result;
		sort(nums.begin(), nums.end());

		int s, e;
		for (i = 0; i < n; i++) {
			s = i + 1;
			e = n - 1;
			while (s < e) {
				if (nums[s] + nums[e] + nums[i] < 0) s++;
				else if (nums[s] + nums[e] + nums[i] > 0) e--;
				else {
					t.clear();
					t.push_back(nums[i]);
					t.push_back(nums[s]);
					t.push_back(nums[e]);
					result.push_back(t);
					while (s < e && nums[s] == t[1]) s++;			// �̹� ä�� �� �Ͱ� �ٸ� ���� ���ö� ���� �ǹ��� ����
					
					//s++;										
					//while (s < e && nums[s] == nums[s+1]) s++;	// ���� �Ʒ� �ִ� while��ó�� ������ �� �ִµ�. �̰� Ʋ����., �ٷ� ���� s++ �־��൵ Ʋ����. �ƿ� �ٸ���.
						
																	// �ڼ��� ����, ������ �ּ� �ѹ� �̻� s++ ���ִµ�, �Ʒ����� �ƿ� s++�� ���� ���Ҽ��� �ִ�. �ٸ� �ǹ��ӿ� ��������.
					//while (s < e && nums[e] == nums[e-1]) e--;		

					while (s < e && nums[e] == t[2]) e--;			// �ߺ��� ���ϴ� �ڵ� ��ų�̴ϱ� �����ؼ� ����ص� ��.

				}

			}

			while (i + 1 < n && nums[i + 1] == nums[i]) i++; // �̰� for�� �ٷ� �ؿ� ���� process�� �ѹ��� �Ȱ�ġ�°Ű�
															// for�� �Ʒ� ���� ��ġ�� ���� process�� �ѹ� �̻� ��ġ�ڴٴ� ���̴�.
															// �� �� �̻��������� �������Ҷ��� �̷��� ������ �ڵ带 �� �� �ְڴ�.
		}
		return result;
	}

};

/*


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <ctime>
#define MAIN_DEBUG 1
using namespace std;


class Solution {

public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> result;
		vector<int> t;
		int i, j, k;
		int n = nums.size();
		if (n == 0) return result;
		sort(nums.begin(), nums.end());

		int s, e;
		for (i = 0; i < n; i++) {
			s = i + 1;
			e = n-1;
			while (s < e) {
				if (nums[s] + nums[e] + nums[i] < 0) s++;
				else if (nums[s] + nums[e] + nums[i] > 0) e--;
				else {
					t.clear();
					t.push_back(nums[i]);
					t.push_back(nums[s]);
					t.push_back(nums[e]);
					if (result.empty() || (!result.empty() && result.back() != t)) {
						result.push_back(t);
					}
					s++;
				}
			}

			while (i+1 < n && nums[i + 1] == nums[i]) i++;
		}
		return result;
	}

};

*/


int main(void) {
	srand(time(0));
	int val;
	int n, i, tc;
	vector<vector<int>> ans;
	Solution sol;
	clock_t start = clock();

	vector<int> nums;
	nums.push_back(0);
	nums.push_back(0);
	nums.push_back(0);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(-1);
//	nums.push_back(4);
//	nums.push_back(2);
	ans = sol.threeSum(nums);

#if MAIN_DEBUG==1
	printf("print ans ans.size() : %d\n", ans.size());
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			printf("%d ", ans[i][j]);
		}
		printf("\n");
	}
	printf("\n\n\n");
#endif

	//	}

	printf("%0.5f", (float)(clock() - start) / CLOCKS_PER_SEC);
	return 0;
}




