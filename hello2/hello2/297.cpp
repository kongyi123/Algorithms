// Trash Code.
/*
	직접 parsing을 했다는 것에서 충분히 어려운건 인정하겠으나
	(0과 음수 까지 들어가는 줄 몰랐다.)
	모듈화 하여 코드 최적화를 해볼 필요가 있다.
*/

#include <string>
#include <queue>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#define NUL 9999
class Codec {
public:

	string serialize(TreeNode* root) {
		char num[5]; // 이게 그렇게 많이 차이나??? while 안에 들어있으면 훨씬 느려진다.
		string str("[");
		string buf;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			TreeNode* cur = q.front();
			if (cur != 0) {
				q.push(cur->left);
				q.push(cur->right);
				str += buf;
				buf.clear();
				sprintf(num, "%d", cur->val);
				str += num;
				str += ',';
			}
			else buf += "null,";
			q.pop();
		}

		str[str.size() - 1] = ']';
		return str;
	}


	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		vector<int> arr;
		int num;
		int buho, nul;
		for (int i = 1; i < data.size(); i++) {
			if (data[i] == ']') break;
			if (data[i] == ',') continue;
			num = 0; buho = 1;
			if (data[i] == '-') {
				buho = -1; i++;
			}
			while ('0' <= data[i] && data[i] <= '9') {
				num = num * 10 + (data[i] - '0'); i++;
			}

			nul = 0;
			while ('a' <= data[i] && data[i] <= 'z') {
				nul = 1; i++;
			}

			if (nul) arr.push_back(NUL);
			else arr.push_back(num * buho);
		}

		if (arr.size() == 0) return 0;

		TreeNode* tn = new TreeNode(arr[0]);
		queue<TreeNode*> q;
		q.push(tn);
		TreeNode* cur;

		for (int i = 1; i < arr.size(); i++) {
			if (q.empty()) break;
			cur = q.front();
			if (arr[i] != NUL) {
				cur->left = new TreeNode(arr[i]);
				q.push(cur->left);
			}
			else cur->left = 0;
			if (i + 1 < arr.size() && arr[i + 1] != NUL) {
				cur->right = new TreeNode(arr[i + 1]);
				q.push(cur->right);
			}
			else cur->right = 0;
			i++;

			if (q.empty()) continue;
			q.pop();
		}

		return tn;
	}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));