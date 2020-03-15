// 단순 stack 구현, 다시 안봐도 될 듯.

class CustomStack {
public:
	int capacity;
	int top;
	int arr[1002];
	CustomStack(int maxSize) {
		capacity = maxSize;
		top = 0;
	}

	void push(int x) {
		if (top < capacity) {
			arr[top++] = x;
		}
	}

	int pop() {
		if (top == 0) return -1;
		else return arr[--top];
	}

	void increment(int k, int val) {
		for (int i = 0; i < k; i++) {
			if (i >= top) break;
			arr[i] += val;
		}
	}
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */