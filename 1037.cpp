#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> coupon;
vector<int> product;
int nc, np;

int main(void){
	int temp;
	int res = 0;
	cin >> nc;
	for (int i = 0; i < nc; ++i){
		scanf("%d", &temp);
		coupon.push_back(temp);
	}
	cin >> np;
	for (int i = 0; i < np; ++i){
		scanf("%d", &temp);
		product.push_back(temp);
	}
	sort(coupon.begin(),coupon.end());
	sort(product.begin(), product.end());


	int nege_pos1 = 0, nege_pos2 = 0;
	int posi_pos1 = nc - 1, posi_pos2 = np - 1;
	while (nege_pos1 < nc && nege_pos2 < np &&coupon[nege_pos1] < 0 && product[nege_pos2] < 0){
		res += coupon[nege_pos1] * product[nege_pos2];
		nege_pos1++;
		nege_pos2++;
	}
	while (posi_pos1 >= 0 && posi_pos2 >= 0 && coupon[posi_pos1]>0 && product[posi_pos2]>0){
		res += coupon[posi_pos1] * product[posi_pos2];
		posi_pos1--;
		posi_pos2--;
	}

	cout << res;

	return 0;
}