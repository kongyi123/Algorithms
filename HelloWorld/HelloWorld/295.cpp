// 매번 정렬 코드 >> Time Limit Exceeded

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

class MedianFinder {
	vector<int> arr;
	int cnt;
public:
	/** initialize your data structure here. */
	MedianFinder() {
		arr.clear();
		arr.push_back(-2000000000);
		cnt = 0;
	}

	void addNum(int num) {
		arr.push_back(num);
		cnt++;
	}

	double findMedian() {
		sort(arr.begin(), arr.end());
		if (cnt % 2 == 0) {
			return (double)(arr[cnt / 2] + arr[cnt / 2 + 1]) / 2;
		}
		else return arr[cnt / 2 + 1];
	}
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main(void) {
	MedianFinder* obj = new MedianFinder();
	obj->addNum(1);
	obj->addNum(2);
	double param_1 = obj->findMedian();
	obj->addNum(3);
	double param_2 = obj->findMedian();
	printf("%lf %lf", param_1, param_2);
	return 0;
}