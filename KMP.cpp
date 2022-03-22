#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
	string txt, pat;
	cin>>txt;
	cin>>pat;
	int m = pat.length(), n = txt.length();
	vector<int> lps(m,0);
	
	cout<<endl;
	//create lps array
	int len = 0;
	for (int i = 1; i<m; i++){
		if (pat[i]==pat[len]){
			len++;
			lps[i] = len;
		}else{
			if (len!=0) len = lps[len-1];
		}
	};
	cout<<"Lps array:"<<endl;
	for (int i=0;i<m;i++) cout<<lps[i]<<" ";
	cout<<endl;
	cout<<endl;
	
	//matching
	int i = 0, j = 0, count = 0;;
	while (i<n){
		if (i<n&&txt[i]!=pat[j]){
			if (j!=0) j = lps[j-1];
				else i++;	
		}else {
			i++;
			j++;
			if (j==m) {
				cout<<"Tim thay tai vi tri "<<i-m<<endl;
				j=lps[j-1];
				count++;
			}
		}
	}
	cout<<"Co "<<count<<" vi tri duoc tim thay"<<endl;
	return 0;
}
