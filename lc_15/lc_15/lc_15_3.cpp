/*
	# 순서
	기존에 풀던 방식 : 2개 선택 -> 1개 확인
	새로 풀어볼 방식 : 1개 선택 -> 2개 착기

	동일해 보이지만 확실히 위 둘은 다르다. (순서를 바꿔볼줄 알아야한다.)

	무엇이다른지 모듈을 나눠 생각해보면 보인다.
	
		- 두개를 세는 법 (input x일때)
		1. 2중 for + x와 비교 (후보를 만들어서 filter하는 방식)
		2. x값을 맞추는 형태의 투 포인터 (입력이 반드시 필요, 값을 찾을 때 입력값에 맞는 값을 추적하는 방식)

		- 한개를 세는 법 (input x일때)
		1. map (자료구조를 형성한 후 입력에 맞는 값을 추적하는 방식)
		2. for + x와 비교 (후보를 만들어서 filter하는 방식)

	위를 보면, 한개 세는법과 두개를 세는법의 순서를 무엇을 전후로 두느냐에 따라 조금더 빠를 수 있는 '값을 추적하는 방식'을 쓸 수도 있고 쓸 수 없을 수도 있게 된다.


	# 중복 없이 찾는 방법
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
					while (s < e && nums[s] == t[1]) s++;			// 이미 채택 된 것과 다른 값이 나올때 까지 피벗을 변경
					
					//s++;										
					//while (s < e && nums[s] == nums[s+1]) s++;	// 가장 아래 있는 while문처럼 착각할 수 있는데. 이건 틀리다., 바로 윗줄 s++ 넣어줘도 틀리다. 아예 다르다.
						
																	// 자세히 보면, 윗줄은 최소 한번 이상 s++ 해주는데, 아랫줄은 아예 s++을 수행 안할수도 있다. 다른 의미임에 주의하자.
					//while (s < e && nums[e] == nums[e-1]) e--;		

					while (s < e && nums[e] == t[2]) e--;			// 중복을 피하는 코드 스킬이니까 주의해서 기억해둘 것.

				}

			}

			while (i + 1 < n && nums[i + 1] == nums[i]) i++; // 이걸 for문 바로 밑에 쓰면 process를 한번도 안거치는거고
															// for문 아래 지금 위치에 쓰면 process를 한번 이상 거치겠다는 것이다.
															// 두 번 이상진행하지 않으려할때는 이러한 형태의 코드를 쓸 수 있겠다.
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




