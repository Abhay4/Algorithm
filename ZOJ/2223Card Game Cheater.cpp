/**
 * ZOJ 2223 Card Game Cheater
 *
 * 2005/05/04 By adai
 */

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>
#include <set>
using namespace std;

#ifdef WIN32
#define for if(0); else for
#endif

//����ͼ���ƥ��,kuhn munkras�㷨,�ڽ�����ʽ,���Ӷ�O(m*m*n)
//�������ƥ��ֵ,�������ͼ��Сm,n���ڽ���mat,��ʾȨֵ
//match1,match2����һ�����ƥ��,δƥ�䶥��matchֵΪ-1
//һ��ע��m<=n,����ѭ���޷���ֹ
//��СȨƥ��ɽ�Ȩֵȡ�෴��
#include <string.h>
#define MAXN 26
#define inf 1000000000
#define _clr(x) memset(x,0xff,sizeof(int)*n)

int kuhn_munkras(int m,int n,int mat[][MAXN],int* match1,int* match2){
	int s[MAXN],t[MAXN],l1[MAXN],l2[MAXN],p,q,ret=0,i,j,k;
	for (i=0;i<m;i++)
		for (l1[i]=-inf,j=0;j<n;j++)
			l1[i]=mat[i][j]>l1[i]?mat[i][j]:l1[i];
	for (i=0;i<n;l2[i++]=0);
	for (_clr(match1),_clr(match2),i=0;i<m;i++){
		for (_clr(t),s[p=q=0]=i;p<=q&&match1[i]<0;p++)
			for (k=s[p],j=0;j<n&&match1[i]<0;j++)
				if (l1[k]+l2[j]==mat[k][j]&&t[j]<0){
					s[++q]=match2[j],t[j]=k;
					if (s[q]<0)
						for (p=j;p>=0;j=p)
							match2[j]=k=t[j],p=match1[k],match1[k]=j;
				}
		if (match1[i]<0){
			for (i--,p=inf,k=0;k<=q;k++)
				for (j=0;j<n;j++)
					if (t[j]<0&&l1[s[k]]+l2[j]-mat[s[k]][j]<p)
						p=l1[s[k]]+l2[j]-mat[s[k]][j];
			for (j=0;j<n;l2[j]+=t[j]<0?0:p,j++);
			for (k=0;k<=q;l1[s[k++]]-=p);
		}
	}
	for (i=0;i<m;i++)
		ret+=mat[i][match1[i]];
	return ret;
}

int adam[MAXN], eve[MAXN];
int mat[MAXN][MAXN];
int match1[MAXN], match2[MAXN];
int n;

int Run() {
	scanf("%d", &n);
	char in[2];
	for (int i = 0; i < n; ++i) {
		int a, b;
		scanf("%s", in);
		
		if (in[0] >= '2' && in[0] <= '9') a = in[0] - '0';
		else if (in[0] == 'T') a = 10;
		else if (in[0] == 'J') a = 11;
		else if (in[0] == 'Q') a = 12;
		else if (in[0] == 'K') a = 13;
		else if (in[0] == 'A') a = 14;
		
		if (in[1] == 'C') b = 1;
		else if (in[1] == 'D') b = 2;
		else if (in[1] == 'S') b = 3;
		else if (in[1] == 'H') b = 4;
		
		adam[i] = a * 100 + b;
	}
	
	for (int i = 0; i < n; ++i) {
		int a, b;
		scanf("%s", in);
		
		if (in[0] >= '2' && in[0] <= '9') a = in[0] - '0';
		else if (in[0] == 'T') a = 10;
		else if (in[0] == 'J') a = 11;
		else if (in[0] == 'Q') a = 12;
		else if (in[0] == 'K') a = 13;
		else if (in[0] == 'A') a = 14;
		
		if (in[1] == 'C') b = 1;
		else if (in[1] == 'D') b = 2;
		else if (in[1] == 'S') b = 3;
		else if (in[1] == 'H') b = 4;
		
		eve[i] = a * 100 + b;
	}
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (eve[i] > adam[j]) mat[i][j] = 1;
			else mat[i][j] = -1;
		}
	}
	
	int ret = kuhn_munkras(n, n, mat, match1, match2);
	ret += (n - ret) / 2;
	printf("%d\n", ret);
	return 0;
}

int main() {
	int kase;
	scanf("%d", &kase);
	while (kase--) {
		Run();
	}
	return 0;
}
