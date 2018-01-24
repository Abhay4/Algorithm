#include<iostream>
#include<string>

using namespace std;

int digitSum(string n, int k) {
    // Complete this function
  long long sum=0;
  int N=n.length();
  for(int i=0;i<N;i++)
	{
	sum=sum+(n[i%N]-'0');	
	}
  
  if(sum<10 && k==1)
	return sum;
  else if(sum<10 && k>1){
      sum*=k;
      return digitSum(to_string(sum),1);
  }
  else
	return digitSum(to_string(sum),k);
}

int main() {
    string n;
    int k;
    cin >> n >> k;
    int result = digitSum(n, k);
    cout << result << endl;
    return 0;
}




