#include <iostream>
/*
 * ZJU 1203 Swordfish
 * 00:00.00 928k
 */

#include <string>
#include <cstdio>
#include <cmath>
using namespace std;

//����ͼ��С������,prim�㷨,�ڽ�����ʽ,���Ӷ�O(n^2)
//������С�������ĳ���,����ͼ�Ĵ�Сn���ڽ���mat,�����ڵ��Ȩinf
//�ɸ��ı�Ȩ������,pre[]�������Ĺ���,�ø�����ʾ,���ڵ�(��һ��)preֵΪ-1
//���뱣֤ͼ����ͨ��!
#define MAXN 100
#define inf 1000000
typedef double elem_t;

elem_t prim(int n,elem_t mat[][MAXN],int* pre)
{
	elem_t min[MAXN],ret=0;
	int v[MAXN],i,j,k;
	for (i=0;i<n;i++)
		min[i]=inf,v[i]=0,pre[i]=-1;
	for (min[j=0]=0;j<n;j++){
		for (k=-1,i=0;i<n;i++)
			if (!v[i]&&(k==-1||min[i]<min[k]))
				k=i;
		for (v[k]=1,ret+=min[k],i=0;i<n;i++)
			if (!v[i]&&mat[k][i]<min[i])
				min[i]=mat[pre[i]=k][i];
	}
	return ret;
}

int n, kase = 0;
double x[100], y[100];
double dis[100][100];
int pre[100];
double ret;

int main()
{
	while (scanf("%d", &n) && n)
	{
		if (kase) printf("\n");
		for (int i = 0; i < n; ++i)
			scanf("%lf %lf", &x[i], &y[i]);

		memset(dis, 0, sizeof(dis));
		for (int i = 0; i < n; ++i)
		{
			for (int j = i + 1; j < n; ++j)
			{
				dis[i][j] = dis[j][i] = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
			}
		}

		ret = prim(n, dis, pre);

		printf("Case #%d:\n", ++kase);
		printf("The minimal distance is: %.2lf\n", ret);
	}
	return 0;
}
