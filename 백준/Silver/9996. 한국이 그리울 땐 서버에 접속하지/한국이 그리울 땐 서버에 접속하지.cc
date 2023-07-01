#include<iostream>
#include<string>

using namespace std;

int N;
string str;
string tstr;
int main()
{
	cin >>N>> str;

	//ft bk로 자르기
	auto it = str.find("*");

	string ft = str.substr(0, it);
	string bk = str.substr(it + 1);

	while (N--)
	{
		cin >> tstr;

		if (tstr.size() < str.size() - 1)
		{
			cout << "NE\n";
		}
		else
		{
			
			if (tstr.substr(0, it) == ft && tstr.substr(tstr.size()-bk.size()) == bk)
			{
				cout << "DA\n";
			}
			else
			{
				cout << "NE\n";
			}
		}
	}



	return 0;
}