//#include <iostream>
//#include <map>
//#include <string>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//struct node{
//	string name;
//	int status;
//	int month, time, day, hour, minute;
//};
//
//bool cmp(node a,node b){
//	return a.name != b.name ? a.name > b.name:a.time < b.time;
//}
//double billFromZero(node call, int *rate) {
//	double total = rate[call.hour] * call.minute + rate[24] * 60 * call.day;
//	for (int i = 0; i < call.hour; i++)
//		total += rate[i] * 60;
//	return total / 100.0;
//}
//
//int main(void){
//
//	int rate[25] = { 0 },n;
//	for (int i = 0; i < 24; ++i){
//		scanf("%d", &rate[i]);
//		rate[24] += rate[i];
//	}
//
//	scanf("%d", &n);
//	vector<node> data(n);
//	for (int i = 0; i < n; ++i){
//		cin >> data[i].name;
//		scanf("%d:%d:%d:%d", &data[i].month, &data[i].day, &data[i].hour, &data[i].minute);
//		string temp;
//		cin >> temp;
//		data[i].status = (temp == "on-line") ? 1 : 0;
//		data[i].time = data[i].day * 24 * 60 + data[i].hour * 60 + data[i].minute;
//	}
//
//	sort(data.begin(), data.end(), cmp);
//
//	map<string, vector<node>> custom;
//	for (int i = 1; i < n; i++) {
//		if (data[i].name == data[i - 1].name && data[i - 1].status == 1 && data[i].status == 0) {
//			custom[data[i - 1].name].push_back(data[i - 1]);
//			custom[data[i].name].push_back(data[i]);
//		}
//	}
//	for (auto it : custom) {
//		vector<node> temp = it.second;
//		cout << it.first;
//		printf(" %02d\n", temp[0].month);
//		double total = 0.0;
//		for (int i = 1; i < temp.size(); i += 2) {
//			double t = billFromZero(temp[i], rate) - billFromZero(temp[i - 1], rate);
//			printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", temp[i - 1].day, temp[i - 1].hour, temp[i - 1].minute, temp[i].day, temp[i].hour, temp[i].minute, temp[i].time - temp[i - 1].time, t);
//			total += t;
//		}
//		printf("Total amount: $%.2f\n", total);
//	}
//	return 0;
//}


#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int weight[25] = { 0 };
struct node{
	string name;
	bool is_online;
	int month, day, hour, minute;
	int wholetime;
};

bool cmp(node a, node b){
	return (a.name == b.name) ? (a.wholetime < b.wholetime) : (a.name < b.name);
}

double chargefromZero(node a){
	double total = weight[a.hour] * a.minute + weight[24] * 60 * a.day;
	for (int i = 0; i < a.hour; i++)
		total += weight[i] * 60;
	return total / 100.0;
}

int main(void){
	for (int i = 0; i < 24; ++i){
		scanf("%d", weight[i]);
		weight[24] += weight[i];
	}
	int n;
	scanf("%d", &n);
	vector<node> myvec(n);//默认构造函数初始化
	for (int i = 0; i < n; ++i){
		cin >> myvec[i].name;
		scanf("%d%d%d%d", &myvec[i].month, &myvec[i].day, &myvec[i].hour, &myvec[i].minute);
		string status;
		cin >> status;
		if (status == "on-line")
			myvec[i].is_online = true;
		myvec[i].wholetime = myvec[i].month * 0 + myvec[i].day * 60 * 24 + myvec[i].hour * 60 + myvec[i].minute;
	}
	
	//按照姓名顺序排序，每个人的顺序按照wholetime
	sort(myvec.begin(), myvec.end(), cmp);

	map<string, vector<node>> mmp;
	for (int i = 1; i < n; ++i){
		if (myvec[i].name == myvec[i - 1].name && myvec[i].is_online == false && myvec[i - 1].is_online){
			mmp[myvec[i].name].push_back(myvec[i]);
			mmp[myvec[i - 1].name].push_back(myvec[i - 1]);
		}
	}

	map<string, vector<node>>::iterator it;
	for (it = mmp.begin(); it != mmp.end(); ++it){
		cout << it->first;
		printf(" %02d", it->second[0].month);
		double total_cost=0;
		for (int i = 1; i < it->second.size(); i+=2){
			double cost = chargefromZero(it->second[i]) - chargefromZero(it->second[i - 1]);
			printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", it->second[i - 1].day, it->second[i - 1].hour, it->second[i - 1].minute, it->second[i].day, it->second[i].hour, it->second[i].minute, it->second[i].wholetime - it->second[i - 1].wholetime, cost);
			total_cost += cost;
		}
		printf("Total amount: $%.2f\n", total_cost);
	}

	return 0;

}