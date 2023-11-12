#include<iostream>
#include<vector>
#pragma warning (disable:4996)
#define MAXHP 999999000001*123456
//#define MAXHP 100

typedef long long ll;

using namespace std;

struct Mob
{
	int type;
	ll ATK;
	ll HP;
};

ll ret = 1;
int N;
int sATK;
vector<Mob> board;

void Input()
{
	int t, a, h;
	cin >> N >> sATK;
	for (int i = 0; i < N; i++)
	{
		cin >> t >> a >> h;
		board.push_back({ t,a,h });
	}
}

bool check(ll maxHP)
{
	Mob Hero = { 0, sATK, maxHP };

	for (int i = 0; i < N; i++)
	{
		Mob curMob = board[i];
		//몬스터
		if (curMob.type == 1)
		{
			ll div = curMob.HP / Hero.ATK + (curMob.HP % Hero.ATK ? 1 : 0);
			ll atkCnt = div - 1;
			Hero.HP -= atkCnt * curMob.ATK;
		}
		//포션
		else
		{
			Hero.ATK += curMob.ATK, Hero.HP += curMob.HP;
			if (Hero.HP > maxHP)Hero.HP = maxHP;
		}
		if (Hero.HP <= 0)return false;
	}
	return true;
}

void binarySearch()
{
	ll l = 1, r = 1e18+4;

	while (l <= r)
	{
		ll mid = (l + r) / 2;
		if (check(mid))
		{
			r = mid - 1;
			ret = mid;
		}
		else
		{
			l = mid + 1;
		}
	}

}


int main()
{
#ifdef _DEBUG
	freopen("C:\\Users\\ekdls\\Desktop\\study\\16434.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Input();
	binarySearch();
	cout << ret<<"\n";
}