// 입력할때마다 O(k)씩 돌면서 배열에 정렬된 형태로 추가해줌.

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
		int p = 1;
		arr.push_back(2000000000);
		while (arr[p] < num) p++;
		for (int i = cnt; i >= p; i--) {
			arr[i + 1] = arr[i];
		}
		arr[p] = num;
		cnt++;
	}
		
	double findMedian() {
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
	double param;
	param = obj->findMedian(); printf("%lf\n", param);
	obj->addNum(-1);
	param = obj->findMedian(); printf("%lf\n", param);
	obj->addNum(-2);
	param = obj->findMedian(); printf("%lf\n", param);
	obj->addNum(-3);
	param = obj->findMedian(); printf("%lf\n", param);
	obj->addNum(-4);
	param = obj->findMedian(); printf("%lf\n", param);
	obj->addNum(-5);
	param = obj->findMedian(); printf("%lf\n", param);
	return 0;
}