/*
zju 2136 Longest Ordered Subsequence
00:00.00 444k
2004.08.08 by adai
*/

#include <iostream>
using namespace std;

//�����������,���Ӷ�O(nlogn)
//ע����С���и��Ǻ�����еĶ�Ӧ��ϵ,����
//"define _cp(a,b) ((a)>(b))"�����ϸ�ݼ�����,��
//"define _cp(a,b) (!((a)>(b)))"�����С�ϸ�ݼ����и���
//�ɸ���Ԫ�����ͺͱȽϺ���
#define MAXN 1000
#define _cp(a,b) ((a)>=(b))
#define _cp2(a,b) ((a)<(b))
typedef int elem_t;

int subseq(int n,elem_t* a){
	int b[MAXN],i,l,r,m,ret=0;
	for (i=0;i<n;b[l]=i++,ret+=(l>ret))
		for (m=((l=1)+(r=ret))>>1;l<=r;m=(l+r)>>1)
			if (_cp(a[b[m]],a[i]))
				l=m+1;
			else
				r=m-1;
	return ret;
}

int subseq2(int n,elem_t* a){
	int b[MAXN],i,l,r,m,ret=0;
	for (i=0;i<n;b[l]=i++,ret+=(l>ret))
		for (m=((l=1)+(r=ret))>>1;l<=r;m=(l+r)>>1)
			if (_cp2(a[b[m]],a[i]))
				l=m+1;
			else
				r=m-1;
	return ret;
}

int num[1000];

int main()
{
	int kase;
	cin >> kase;
	for(int t = 0; t < kase; t ++)
	{
		if (t) cout << endl;
		int n;
		cin >> n;
		for (int i = 0; i < n; i ++) cin >> num[i];
		int maxn, max1, max2;
		max1 = subseq(n, num);
		max2 = subseq2(n, num);
		maxn = max1 > max2 ? max1 : max2;
		cout << max2 << endl;
	}
	return 0;
}
