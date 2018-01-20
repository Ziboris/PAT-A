//#include <stdio.h>
//#include <iostream>
//#include <vector>
//#include <algorithm>
////#include <map>
//#define maxn 100010
//using namespace std;
//
//typedef struct Node{
//	int key;
//	int times = 1;
//}node,*pnode;
//int n;
//node tempnode;
//
//bool findx(node &x){
//	return x.key == tempnode.key;
//}
//
//int main(void){
//	/*int tempkey;
//	map<int, int> mmp;
//
//	scanf("%d", &n);
//	for (int i = 0; i < n; ++i){
//		scanf("%d", &tempkey);
//		if (mmp.find(tempkey) != mmp.end()){
//			mmp[tempkey] = 1;
//		}
//		else{
//			mmp[tempkey]++;
//		}
//	}*/
//
//	vector<node> myvec;
//	vector<node>::iterator it;
//	scanf("%d", &n);
//	for (int i = 0; i < n; ++i){
//		scanf("%d", &tempnode.key);
//		it = find_if(myvec.begin(), myvec.end(), findx);
//		if (it != myvec.end()){
//			it->times++;
//		}
//		else{
//			tempnode.times++;
//			myvec.push_back(tempnode);
//		}
//	}
//
//	for (it = myvec.begin(); it != myvec.end(); ++it){
//		if ((it->times) == 1)
//			printf("%d", it->key);
//		return 0;
//	}
//	printf("None");
//
//	return 0;
//}


//hash
#include <cstdio>
using namespace std;
int a[100001], m[100000];
int main(void){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
		m[a[i]]++;
	}
	for (int i = 0; i < n; ++i){
		if (m[a[i]] == 1){
			printf("%d", a[i]);
			return 0;
		}
	}
	printf("None");
	return 0;
}