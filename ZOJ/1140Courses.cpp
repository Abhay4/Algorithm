/**
 * ZOJ 1140 Courses
 *
 * 00:00.73 964k
 */

#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

//����ͼ�걸ƥ��,hungary�㷨,�ڽ�����ʽ,���Ӷ�O(m*m*n)
//�����Ƿ����걸ƥ��,�������ͼ��Сm,n���ڽ���mat,����Ԫ�ر�ʾ�б�
//�����,match1,match2����һ���걸ƥ��,δƥ�䶥��matchֵΪ-1,����������
#define MAXN 300
#define _clr(x) memset(x,0xff,sizeof(int)*MAXN)

int hungary(int m,int n,int mat[][MAXN],int* match1,int* match2){
	int s[MAXN],t[MAXN],p,q,ret=0,i,j,k;
	if (m>n) return 0;
	for (_clr(match1),_clr(match2),i=0;i<m&&ret==i;ret+=(match1[i++]>=0))
		for (_clr(t),s[p=q=0]=i;p<=q&&match1[i]<0;p++)
			for (k=s[p],j=0;j<n&&match1[i]<0;j++)
				if (mat[k][j]&&t[j]<0){
					s[++q]=match2[j],t[j]=k;
					if (s[q]<0)
						for (p=j;p>=0;j=p)
							match2[j]=k=t[j],p=match1[k],match1[k]=j;
				}
	return ret==m;
}

int match1[MAXN], match2[MAXN];
int m, n;
int mat[100][300];

int Run() {
	scanf("%d %d", &m, &n);
	memset(mat, 0, sizeof(mat));
	for (int i = 0; i < m; ++i) {
		int num, tmp;
		scanf("%d", &num);
		for (int j = 0; j < num; ++j) {
			scanf("%d", &tmp);
			--tmp;
			mat[i][tmp] = 1;
		}
	}
	if (hungary(m, n, mat, match1, match2))
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}

int main() {
	int kase;
	for (scanf("%d", &kase); kase; --kase) {
		Run();
	}
	return 0;
}
