
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <vector>
#define IN in
#define OUT out

#define MAXN 100

FILE *in = fopen("input.txt", "r");
FILE *out = fopen("output.txt", "w");

using namespace std;

int n;
bool row[MAXN], col[MAXN], diag1[MAXN * 2 - 1], diag2[MAXN * 2 - 1];

int crossSol[MAXN][MAXN], plusSol[MAXN][MAXN];

void placeCrosses() { // x�� ���� ���� �Ϳ� ���Ͽ�...
	// �� �ڸ��� �̹� ���������� ���̳� ���� �ƴϸ�
	for (int i = 0; i < n; i++) {
		if (row[i]) continue;
		for (int j = 0; j < n; j++) {
			if (col[j]) continue;

			crossSol[i][j] = 1; // x�� ���� �� �ִ� �ڸ��� ã�Ƽ� �� ��ġ�� üũ
			col[j] = true;		// ���� ���� ������ ���� �� ������ üũ
			break;	// break�� �����ν� ���� row�� �������� ���� ����� �Ѵ�.
					// �׷��� ���� row[i] = true;�� �� �ʿ� ���� break; �Ѱ���.
		}
	}

	// ��, ���� �� �ִ� ��� �ٷιٷ� �� �־��ٰ� ����.
	// �̰� ��°�� ������ �����Ѱ���?? �׸����ݾ�.
	// ��� �ȴٴ� ���� �� �� �־�������??
}

int placePluses() { // +�� �η����� �� �ٿ� 2�� �̻� �����ؾ� �ϰ�, +�� �����ؾ��Ѵ�.
	vector<int> ds;
	for (int i = 0; i < n - 1; i++) {
		ds.push_back(i);
		ds.push_back(n * 2 - i - 2);
	}
	ds.push_back(n - 1); // �¹� ���� �밢�� üũ�� �Ҷ� ������ �ٱ��ʿ������� �߾� ������� �ϱ����� ����
	// n == 3, ds = 0,4,1,3,2
	
/*
	for (int i = 0;i <= n * 2 - 2;i++) {
		ds.push_back(i);
	}
	*/


 	int points = 0;
	for (int d : ds) {
		if (diag1[d]) {  // �¹ؿ��� �밢�� �̹� ���� �Ǿ������� �׳� ����Ʈ�� ���ϰ� �Ѿ?
			points++;	// ����Ʈ�� �� ���ϴµ�. ����Ʈ�� ���� plusPoint���µ�.... 
			continue; 
		}  

		// ���� �ȵǰ� ������ �¹� ���� �밢�� ���� �ִ� 
		// ���ڸ� ��ȸ�ϸ鼭   �� ������ ������� �밢�� üũ
		int i = d < n ? d : n - 1;
		int j = d < n ? 0 : d - n + 1;
		
		for (; i >= 0 && j < n; i--, j++) { 
			if (diag2[i - j + n - 1]) continue; // ������� �밢�� �̹� ���� �Ǿ������� ��ŵ
			
			// ��� �밢���̵� ��� �ִ� ���� +�� �д�.
			plusSol[i][j] = 1;
			diag2[i - j + n - 1] = true;
			// ������� �밢�� üũ�� ����.
			// diag1�� ���� �ʿ䰡 ���� ���� �ٽ� �ڷ� ���ư� ���� ���� ���̱�
			// �����̴�.
			points++;
			break;
		}
	}

	// ����Ʈ�� ī�����ϴ� ���� �ΰ���.
	// 1. �¹ؿ��� �밢���� �������� ���. (�� �밢������ �̹� +�� 1�� �ִٴ� ��)
	// 2. 

	// points�� ������ +�� �������ٰ� �߰��� +�� �θ鼭 ���� �� �ִ� ����
	return points;
}

int main() {
	int t; 
	fscanf(IN, "%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		int m; fscanf(IN, "%d %d", &n, &m); // n x n ũ���� ����, m���� �� �Է�

		// �ʱ�ȭ	
		memset(row, 0, sizeof(row));							// ��
		memset(col, 0, sizeof(col));							// ��
		memset(diag1, 0, sizeof(diag1));					    // �밢1
		memset(diag2, 0, sizeof(diag2));						// �밢2
		memset(crossSol, 0, sizeof(crossSol));					
		memset(plusSol, 0, sizeof(plusSol));

		char buf[100];
		for (int i = 0; i < m; i++) {
			fgets(buf, 10, IN);
			char ch; int r, c; fscanf(IN, "%c %d %d", &ch, &r, &c); 
			r--; c--;
			if (ch != '+') { 
				crossSol[r][c] = -1;
				row[r] = col[c] = true;	
			}
			if (ch != 'x') { 
				plusSol[r][c] = -1;
				diag1[r + c] = diag2[r - c + n - 1] = true;
			}
		}

		

		placeCrosses(); // x���� �߰��� ���´�. (���� ����� ����)
		int plusPoints = placePluses(); // +���� �߰��� ���´�. (+�� ����� �� �ִ� ���� ���)

		int pieces = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (crossSol[i][j] > 0 || plusSol[i][j] > 0) pieces++;
				// crossSol�� plusSol ���� ���� ���� ���� ǥ�õǾ��ִ�.
				// x�� +�� ���� �� �� �ִ� �ڸ��� piece�� ī���.

			}
		}



		// n+plusPoints�� ���� �ΰ� �ű� ����
		// piece�� ���� �δ� ���� ��
		fprintf(OUT, "Case #%d: %d %d\n", tc, n + plusPoints, pieces);

		// crossSol�� üũ�� �ȴٴ� ���� x�� �� �� �ִ� �ڸ���� ���̰�
		// (��, x�� �ϳ��� �ΰų� ���� �࿡ x�ϳ��� �ٸ� +���� �дٴ� ��)
		// plusSol�� üũ�� �ȴٴ� ���� +�� �� �� �ִ� �ڸ���� ���̴�.
		// (�װ��� ��, +�� �ϳ��� �ΰų� +�ϳ��� �ٸ� x���� �дٴ� ��)
		// x�� +��ſ� o�� �� �� �ִ�.
		// ���� �δ� ���̶�� ������ �Ǿ�� �ϴ� �� �ƴѰ�??

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (crossSol[i][j] > 0 || plusSol[i][j] > 0) {
					char ch = crossSol[i][j] ? (plusSol[i][j] ? 'o' : 'x') : '+';
					// if (crossSol[i][j] == 1 && plusSol[i][j] == 1) ch = 'o';
					// if (crossSol[i][j] == 1 && plusSol[i][j] == 0) ch = 'x';
					// if (crossSol[i][j] == 0 && plusSol[i][j] == 1) ch = '+';


					// ���࿡ +�� �� �� ������ 'o'�� ����
					// �׷��� ������ x�� �ΰ�
					// �� �� 

					fprintf(OUT, "%c %d %d\n", ch, i + 1, j + 1);
				}
			}
		}
	}
	return 0;
}