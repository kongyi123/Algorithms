#if 1
#define _CRT_SECURE_NO_WARNINGS
 
#include<iostream>
 
using namespace std;
 
#define MAX(a, b) a > b ? a : b
 
#define MAX_N 20
 
int N;
 
struct Box_s
{
    int x, y, z;
};
 
Box_s Box[MAX_N];
 
int visit = 0;
int cache[1 << MAX_N][MAX_N][3];
int c1[1 << MAX_N + 1];
int c2[1 << MAX_N + 1];
int c3[1 << MAX_N + 1];
int cnt;
 
int stack(int x, int y, int height, int n, int k)
{
    if (cache[visit][n][k]) return cache[visit][n][k];
 
    int max = 0;
 
    for (int i = 0; i < N; i++)
    {
        if (visit & (1 << i)) continue;
         
        visit |= (1 << i);
 
        if ((Box[i].x <= x && Box[i].y <= y) || 
            (Box[i].y <= x && Box[i].x <= y))
            max = MAX(max, stack(Box[i].x, Box[i].y, Box[i].z, i, 0));
 
 
        if ((Box[i].y <= x && Box[i].z <= y) || 
            (Box[i].z <= x && Box[i].y <= y))
            max = MAX(max, stack(Box[i].y, Box[i].z, Box[i].x, i, 1));
 
 
        if ((Box[i].x <= x && Box[i].z <= y) || 
            (Box[i].z <= x && Box[i].x <= y))
            max = MAX(max, stack(Box[i].x, Box[i].z, Box[i].y, i, 2));
 
        visit &= ~(1 << i);
    }
     
    c1[cnt] = visit;
    c2[cnt] = n;
    c3[cnt] = k;
    cnt++;
     
    cache[visit][n][k] = max + height;
 
    return cache[visit][n][k];
}
 
 
int start()
{
    for (int i = 0; i < cnt; i++)
    {
        cache[c1[i]][c2[i]][c3[i]] = 0;
    }
 
    visit = 0;
    cnt = 0;
    int max = 0;
 
    for (int i = 0; i < N; i++)
    {
        visit |= (1 << i);
        max = MAX(max, stack(Box[i].x, Box[i].y, Box[i].z, i, 0));
        max = MAX(max, stack(Box[i].y, Box[i].z, Box[i].x, i, 1));
        max = MAX(max, stack(Box[i].x, Box[i].z, Box[i].y, i, 2));
        visit &= ~(1 << i);
    }
 
    return max;
}
 
int main(int argc, char** argv)
{
    int test_case;
    int T;
 
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    cin >> T;
    /*
    여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
    */
 
    for (test_case = 1; test_case <= T; ++test_case)
    {
        cin >> N;
 
        for (int i = 0; i < N; i++)
        {
            cin >> Box[i].x >> Box[i].y >> Box[i].z;
        }
 
        int max = start();
 
        cout << "#" << test_case << " " << max << endl;
    }
 
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
 
#endif