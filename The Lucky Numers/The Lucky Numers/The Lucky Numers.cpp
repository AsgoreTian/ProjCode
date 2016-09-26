#include <iostream>
using namespace std;

typedef long long ll;

ll dp[20][20][20][20];//i为,不是4和7的个数,4的个数,7的个数
ll l, r;
int num[20], len;


inline ll dfs(int i, int s, int p, int q, bool e, bool pre){
	if (i == -1){
		if (s <= 1) return 1;
		return 0;
	}
	if (!e && dp[i][s][p][q] != -1) return dp[i][s][p][q];
	int v = (e ? num[i] : 9);
	ll ans = 0;
	for (int j = 0; j <= v; j++){
		int news = s;
		if (j != 4 && j != 7){
			if (j != 0 || (!pre&&j == 0))
				news++;
		}
		ans += dfs(i - 1, news, p + (j == 4), q + (j == 7), e && (j == v), (j == 0 && pre));
	}
	if (!e) dp[i][s][p][q] = ans;
	return ans;
}
inline ll solve(ll n){
	if (n<0) return 0;
	if (n == 0) return 1;
	len = 0;
	while (n){
		num[len++] = n % 10;
		n /= 10;
	}
	return dfs(len - 1, 0, 0, 0, 1, 1);
}

int main(){

	memset(dp, -1, sizeof(dp));
	int ans = 0;
	while (~scanf("%lld%lld", &l, &r)){
		printf("%lld\n", solve(r) - solve(l - 1));
	}
	return 0;
}
