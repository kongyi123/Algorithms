class Solution {
public:
	int trap(vector<int>& height) {
		int* ltor = new int[height.size()];
		int* rtol = new int[height.size()];
		int max = 0;
		for (int i = 0; i < height.size(); i++) {
			if (max < height[i]) max = height[i];
			ltor[i] = max;
		}

		max = 0;
		for (int i = height.size() - 1; i >= 0; i--) {
			if (max < height[i]) max = height[i];
			rtol[i] = max;
		}

		int sum = 0;
		for (int i = 0; i < height.size(); i++) {
			sum += (ltor[i] > rtol[i] ? rtol[i] : ltor[i]) - height[i];
		}
		return sum;
	}
};