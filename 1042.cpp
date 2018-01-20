//#include <cstdio>
//#include <vector>
//#include <iostream>
//#include <string>
//#include <algorithm>
//#define maxn 60
//using namespace std;
//
//string mystrings[maxn];
//int newOrder[maxn];
//int repeat;
//
//int main(void){
//	//init;
//	/*string a = "hello";
//	string b = "world";
//	string c = to_string(13);
//	cout << a + b + c << endl;*/
//
//	for (int i = 1; i <= 52; ++i){
//		switch (int group=i / 13){
//			case 0: mystrings[i] = "S" + to_string(i % 13); break;
//			case 1: mystrings[i] = "H" + to_string(i % 13); break;
//			case 2:	mystrings[i] = "C" + to_string(i % 13); break;
//			case 3:	mystrings[i] = "D" + to_string(i % 13); break;
//		}
//	}
//
//
//	for (int i = 1; i <= 52; ++i){
//		cout << mystrings << endl;
//	}
//	/*cin >> repeat;
//	for (int i = 1; i <= repeat; ++i){
//		scanf("%d", &newOrder[i]);
//	}*/
//
//
//	return 0;
//}

#include <cstdio>
using namespace std;
int main() {
	int cnt;
	scanf("%d", &cnt);
	int start[55], end[55], scan[55];
	for (int i = 1; i < 55; i++) {
		scanf("%d", &scan[i]);
		end[i] = i;
	}
	for (int i = 0; i < cnt; i++) {
		for (int j = 1; j < 55; j++)
			start[j] = end[j];
		for (int k = 1; k < 55; k++)
			end[scan[k]] = start[k];
	}
	char c[6] = { "SHCDJ" };
	for (int i = 1; i < 55; i++) {
		end[i] = end[i] - 1;
		printf("%c%d", c[end[i] / 13], end[i] % 13 + 1);
		if (i != 54) printf(" ");
	}
	return 0;
}