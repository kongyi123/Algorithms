// merge 소트를 거침없이 확신있게 짤 수 있어야. 아직도 껄끄럽다
// min heap, max heap 사용법 암기할 것.
// 시간이 촉박하보니... 설계를 누가봐도 그걸 보고 코딩을 할 수 있도록. 설계를 마무리 해놓고 코딩했어야하는데
// 그러지 않았다가 촉박한시간에 침착하게 대응을 못함.

// 솔루션은 맞는데 효율성은 떨어지는 듯.
// 최적화 및 좋은 코드를 살펴볼 것.


class Node {
public:
	int a, b;
	bool operator>(const Node t) {
		if (b > t.b) return 1;
		return 0;
	}
};

Node buf[100010];

void msort(Node rank[], int s, int e) {
	if (s < e) {
		int mid = (s + e) / 2;
		msort(rank, s, mid);
		msort(rank, mid + 1, e);

		int i = s, j = mid + 1, count = 0;
		while (i <= mid && j <= e) {
			if (rank[i] > rank[j]) buf[count++] = rank[i++];
			else buf[count++] = rank[j++];
		}

		while (i <= mid) buf[count++] = rank[i++];
		while (j <= e) buf[count++] = rank[j++];

		for (int i = s; i <= e; i++) rank[i] = buf[i - s];
	}
	else return;
}



class Solution {
public:
	int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
		Node* arr = new Node[n];
		for (int i = 0; i < n; i++) {
			arr[i].a = speed[i];
			arr[i].b = efficiency[i];
		}

		msort(arr, 0, n - 1);

		priority_queue< int, vector<int>, greater<int> > pq;

		long long sum = 0;
		long long max = 0;

		for (int i = 0; i < k; i++) {
			sum += arr[i].a;
			pq.push(arr[i].a);
			if (max < sum * arr[i].b) {
				max = sum * arr[i].b;
			}

			printf("%lld ", max);
		}

		for (int i = k; i < n; i++) {
			if (pq.top() < arr[i].a) {
				sum -= pq.top();
				pq.pop();
				sum += arr[i].a;
				pq.push(arr[i].a);
				//if (max < sum * arr[i].b) max = sum * arr[i].b;  // 안에 들어가는거랑 바깥에 들어가는게 다른데, 안에 넣는걸로 착각을 했다. 시간이 촉박한나머지..
			}
			if (max < sum * arr[i].b) max = sum * arr[i].b; 


		}



		return max % 1000000007;
	}
};