//names' pattern is simple ,so to store them in char[]?
#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <iostream>
using namespace std;
#define maxn 40005
#define maxk 2505

//struct Student{
//	string name;
//	set<int> course;
//}allstu[maxk];
map<string, set<int>> allstu;

struct Course{
	int courseid;
	int size;
	vector<string> stulist;
}allcourse[maxn];

int n, k;
string stuname[maxk];

int main(void){

	//input
	cin >> n >> k;
	string tempstr;
	for (int i = 0; i < k; ++i){
		/*scanf("%d%d", &tempcourse.courseid,&tempcourse.size);
		for (int j = 0; j < tempcourse.size; ++j){
			cin >> tempstr;
			tempcourse.stulist.push_back(tempstr);
		}*/
		int tempid;
		scanf("%d", &tempid);
		allcourse[tempid].courseid = tempid;
		scanf("%d", &allcourse[tempid].size);
		for (int j = 0; j < allcourse[i].size; ++j){
			cin >> tempstr;
			allcourse[i].stulist.push_back(tempstr);
			allstu[tempstr].insert(tempid);
		}
	}
	for (int i = 0; i < k; ++i){
		cin >> stuname[i];
	}

	//for (int i = 0; i < k; ++i){
	//	int coursenum = 0;
	//	cout << stuname[i] << " ";
	//	for (int j = 0; j < n; ++j){
	//		if (it = )
	//	}
	//}
	for (int i = 0; i < k; ++i){
		string queryname=stuname[i];
		cout << queryname << " ";
		cout << allstu[queryname].size();
		set<int>::iterator it;
		for (it = allstu[queryname].begin(); it != allstu[queryname].end(); ++it){
			cout << " " << (*it);
		}
	}
	return 0;
}