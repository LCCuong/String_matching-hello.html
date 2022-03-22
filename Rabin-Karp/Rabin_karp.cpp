#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define base 311
#define MOD 10003


int main(){
	string txt, pat;
	cin>>txt;
	cin>>pat;
	unsigned long long MOD2 = MOD*MOD;
	
	int m = pat.length(), n = txt.length();
	txt = " " + txt;
	pat = " " + pat;
	vector<long long> hash_value(n,0), pow(n+1,0);
	
	//create pow array such that pow[i] = base^i 
	pow[0] = 1;
	for (int i = 1; i<=n ; i++) pow[i] = (pow[i-1]*base)%MOD;
	
	//create hash_value array of txt such that hash_value[i] = hash value of substring txt[0..i]
	for (int i=1; i<=n; i++) hash_value[i] = ((hash_value[i-1]*base)%MOD + txt[i])%MOD;
	
	//create hash_value of pattern
	long long HashOfPat = 0;
	for (int i=1; i<=m; i++)
		HashOfPat = ((HashOfPat*base)%MOD + pat[i])%MOD;
	cout<<"Hash_value of pattern: "<<HashOfPat<<endl<<endl;
	
	//matching
	for (int i=1;i<=n-m+1; i++){
		cout<<"Hash_value of substring txt["<<i-1<<".."<<i+m-2<<"]: "<<(hash_value[i+m-1] - (hash_value[i-1]*(pow[m]%MOD))%MOD + MOD2)%MOD<<endl;
		if (HashOfPat == ((hash_value[i+m-1] - (hash_value[i-1]*(pow[m]%MOD))%MOD + MOD2)%MOD)){
			//compare characters one by one if two strings have the same hash_value
			int k=1, j=i;
			while (k<=m&&pat[k] == txt[j+k-1]) k++;
			if (k>m) cout<<"Found at position: "<<i-1<<endl;
		}
		cout<<endl;
	};
			
	return 0;
}
