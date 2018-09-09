#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define dbg //printf

using namespace std;

template <typename T>
void swap(T& a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
struct Heap {
	T heap[1000010];
	int size;
	Heap() {
		size = 0;
	}

	void add(T val);
	T pop();
	int empty();
};

template <typename T>
void Heap<T>::add(T val) {
	size++;
	heap[size] = val;
	int cur = size;
	while (cur / 2 > 0) {
		if (heap[cur] < heap[cur / 2]) {
			swap(heap[cur], heap[cur / 2]);
			cur = cur / 2;
		}
		else break;
	}
}

template <typename T>
T Heap<T>::pop() {
	if (size == 0) return 0;
	T tmp = heap[1];
	heap[1] = heap[size];
	size--;
	int cur = 1;
	while (1) {
		if (cur * 2 + 1 <= size) {
			if (heap[cur * 2] < heap[cur * 2 + 1]) {
				if (heap[cur] > heap[cur * 2]) {
					swap(heap[cur], heap[cur * 2]);
					cur = cur * 2;
				}
				else break;
			}
			else {
				if (heap[cur] > heap[cur * 2 + 1]) {
					swap(heap[cur], heap[cur * 2 + 1]);
					cur = cur * 2 + 1;
				}
				else break;
			}
		}
		else if (cur * 2 <= size && heap[cur] > heap[cur * 2]) {
			swap(heap[cur], heap[cur * 2]);
			cur = cur * 2;
		}
		else break;
	}
	return tmp; // value type
}

template <typename T>
int Heap<T>::empty() {
	if (size == 0) return 1;
	return 0;
}



int T, N, M;
int A[1010], B[1010];
long long C[1000000][2], ccnt;

long long search(int val) {
	int s, e;
	int mid;
	s = 1; e = ccnt;
	while (s <= e) {
		mid = (s + e) / 2;
		if (C[mid][0] < val) s = mid + 1;
		else if (C[mid][0] > val) e = mid - 1;
		else return C[mid][1];		
	}

	return 0;
}

long long process() {
	// 일단 N^2 의 시간 복잡도로 A수열에서 만들 수 있는 부분합의 경우를 다 구한 후
	long long cnt = 0;
	long long sum;
	Heap<long long> h;
	for (int i = 1;i <= N;i++) {
		sum = 0;
		for (int j = i;j <= N;j++) {
			sum += A[j];
			h.add(sum);
		}		
	}

	if (h.empty()) return 0;

	// 정렬하고 중복되는 것들은 솎아내서 갯수와 함께 오름차순으로 별도의 배열에 저장.

	ccnt = 1;
	C[ccnt][0] = h.pop();
	C[ccnt][1] = 1;
	long long temp;
	while (!h.empty()) {
		temp = h.pop();
		if (temp == C[ccnt][0]) {
			C[ccnt][1] ++;
		}
		else {
			ccnt++;
			C[ccnt][0] = temp;
			C[ccnt][1] = 1;
		}
	}

	// M^2 시간 복잡도를 이용하여 B수열에서 만들 수 있는 부분합의 경우들을
	
	for (int i = 1;i <= M;i++) {
		sum = 0;
		for (int j = i;j <= M;j++) {
			sum += B[j];
			cnt += search(T-sum);
			// [T-B수열의 부분합]을 아까의 솎아 낸 리스트에서 이분검색으로 찾는다.
		}
	}


	// 그 갯수를 누적해서 출력
	return cnt;
}

int main(void) {
	scanf("%d", &T);
	scanf("%d", &N);
	for (int i = 1;i <= N;i++) {
		scanf("%d", &A[i]);
	}

	scanf("%d", &M);
	for (int i = 1;i <= M;i++) {
		scanf("%d", &B[i]);
	}

	printf("%lld", process());
	return 0;
}