/*
O(n) 
 1. ��������ָ��p1,p2. ��ʼ��ʱp1ָ��s[0],p2ָ��s[1]. 
 2. k=0��ʼ������s[p1+k] �� s[p2+k] ��Ӧ���ַ��Ƿ����.����ȣ���k++,һֱ��ȥ�� 
    ֱ���ҵ���һ����ͬ��(��k����һ���ַ����ĳ���Ҳû�ҵ���ͬ�����㷨��ֹ). 
    ��ʱ,��Ϊs[p1+k] �� s[p2+k] ��ͬ�������������: 
    case I: 
        s[p1+k]>s[p2+k]. ����֤������p1��p1+k����������Ҫ����Ǹ��ַ����Ŀ�ͷ 
        ��ĸ�����ǣ����԰�p1�Ƶ�p1+k+1, p2���䡣 
    case II: 
        s[p1+k]<s[p2+k]. ����֤������p2��p2+k����������Ҫ����Ǹ��ַ����Ŀ�ͷ 
        ��ĸ�����ǣ����԰�p2�Ƶ�p2+k+1, p1���䡣 
    ���ش˲�����ֱ��p1��p2�������ַ������������. 
 3. ���p1��p2�е���Сֵ. 

 ע�⣺ 
    1. �����Ȱ��ַ���double�����������ܷ���Щ. 
    2. ���磬p1Ҫ�Ƶ�p1+k+1ʱ�����p1+k+1������p2�Ļ�������ֱ�Ӱ�p1�Ƶ� 
       p2ǰ����Ϊ��p2������Ѿ��������.(p2ʱ������) �������һ��.
*/

/*
ZJU 2006 Glass Beads
2004.05.07 By adai
00:00.01 456K
*/

#include <iostream>
#include <cstring>
using namespace std;

int main(){
	int kase,i;
	cin>>kase;
	char input[20001];
	while(kase--){
		cin>>input;
		int len=strlen(input);
		for(i=0;i<len;i++) input[i+len]=input[i];
		int p1(0),p2(1),k(0);
		while(1){
			if(input[p1+k]==input[p2+k]){
				k++;
				if(k==len) break;
			}
			else if(input[p1+k]>input[p2+k]){
				p1+=k+1;
				if(p1<=p2) p1=p2+1;
				if(p1>=len){
					p1=len-1;
					break;
				}
				k=0;
			}
			else{
				p2+=k+1;
				if(p2<=p1) p2=p1+1;
				if(p2>=len){
					p2=len-1;
					break;
				}
				k=0;
			}
		}
		int sign(0);
		for(k=0;k<len;k++){
			if(input[p1+k]<input[p2+k]){
				sign=-1;
				break;
			}
			else if(input[p1+k]>input[p2+k]){
				sign=1;
				break;
			}
		}
		if(sign>0) cout<<p2+1<<endl;
		else if(sign<0) cout<<p1+1<<endl;
		else{
			if(p1>p2) p1=p2;
			cout<<p1+1<<endl;
		}
	}
	return 0;
}