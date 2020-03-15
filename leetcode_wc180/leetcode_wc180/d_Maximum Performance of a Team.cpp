// merge ��Ʈ�� ��ħ���� Ȯ���ְ� © �� �־��. ������ ��������
// min heap, max heap ���� �ϱ��� ��.
// �ð��� �˹��Ϻ���... ���踦 �������� �װ� ���� �ڵ��� �� �� �ֵ���. ���踦 ������ �س��� �ڵ��߾���ϴµ�
// �׷��� �ʾҴٰ� �˹��ѽð��� ħ���ϰ� ������ ����.

// �ַ���� �´µ� ȿ������ �������� ��.
// ����ȭ �� ���� �ڵ带 ���캼 ��.


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
				//if (max < sum * arr[i].b) max = sum * arr[i].b;  // �ȿ� ���°Ŷ� �ٱ��� ���°� �ٸ���, �ȿ� �ִ°ɷ� ������ �ߴ�. �ð��� �˹��ѳ�����..
			}
			if (max < sum * arr[i].b) max = sum * arr[i].b; 


		}



		return max % 1000000007;
	}
};