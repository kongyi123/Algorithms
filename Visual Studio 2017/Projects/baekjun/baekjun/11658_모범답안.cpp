// 2D fenwick tree

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int n,m;
int psum[1025][1025];

void swap(int& a, int& b) {
	int t = a;
	a = b;
	b = t;
}

void update(int x, int y, int val) {
    for(int i= x ;i<= n ;i = i + (i&-i)    ){
        for(int j= y ;j<= n ;j = j + (j&-j)		){
            psum[i][j] = psum[i][j] + val;
        }
    }
}
 
int sum(int x, int y) {
    int ret=0;
    for(int i= x ;i; i= i & (i-1)   ){
        for(int j= y ;j; j = j & (j-1) ){
            ret = ret + psum[i][j];
        }
    }
    return ret;
}
 
int main() {
    fscanf(stdin, "%d%d",&n,&m);
    for(int i=1;i<=n;++i){		// 데이터 입력부 &  fenwick tree update
        for(int j=1;j<=n;++j){
            int x;
            scanf("%d",&x);
            update(i,j,x);
        }
    }

    for(int i=0;i<m;++i){		// 쿼리 입력부
        int k;
        fscanf(stdin, "%d",&k);
        if(k){
            int x1,y1,x2,y2;
            fscanf(stdin, "%d%d%d%d",&x1,&y1,&x2,&y2);
            if(x1>x2 || x1==x2 && y1>y2){
                swap(x1,x2);
                swap(y1,y2);
            }
            printf("%d",sum(x2,y2)-sum(x1-1,y2)-sum(x2,y1-1)+sum(x1-1,y1-1));
        }else{
            int x,y,z;
            fscanf(stdin,"%d%d%d",&x,&y,&z);
            int q=sum(x,y)-sum(x-1,y)-sum(x,y-1)+sum(x-1,y-1); //	 빼고 더하지 않고 차등을 구한 후
            update(x,y,z-q);	// x, y, val						 update에서 증가시켜줌
        }
    }
}
