#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
#define maxn 10010
string arr[maxn];

bool cmp(string a, string b){
	return a + b < b + a;
}

int main(void){

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i){
		cin >> arr[i];
	}

	sort(arr, arr + n, cmp);
	string ans;
	for (int i = 0; i < n; ++i){
		ans += arr[i];
	}
	while (ans.size() != 0 && ans[0] == '0'){
		ans.erase(ans.begin());
	}
	if (ans.size() == 0)
		cout << 0;
	else cout << ans;

	return 0;
}