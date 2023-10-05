#include<iostream>
#include<math.h>

using namespace std;


string str1, str2;
int cntStr1[26];
int cntStr2[26];
int ret;


void Input()
{
	cin >> str1 >> str2;
}

void Solution()
{
	for (int i = 0; i < str1.size(); i++)
	{
		cntStr1[str1[i] - 'a']++;
	}
	for (int j = 0; j < str2.size(); j++)
	{
		cntStr2[str2[j] - 'a']++;
	}

	for (int i = 0; i < 26; i++)
	{
		ret+=abs(cntStr1[i] - cntStr2[i]);
	}
	cout << ret << "\n";
}

int main()
{
	Input();
	Solution();


	return 0;
}