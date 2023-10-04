#include<iostream>
#include<stack>
#include<algorithm>
#include<string>

#pragma warning(disable:4996)

using namespace std;

string str, del;
stack<char> st;

void Input()
{
	cin >> str >> del;
}

void Solution()
{
	int len = str.size();
	int delLen = del.size();
	for (int i = 0; i < len; i++)
	{
		st.push(str[i]);
		if (st.size() >= delLen && st.top() == del[delLen-1])
		{
			string ck = "";
			for (int i = 0; i < delLen; i++)
			{
				ck += st.top();
				st.pop();
			}
			reverse(ck.begin() , ck.end());
			if (ck != del)
			{
				for (int i = 0; i < delLen; i++)
				{
					st.push(ck[i]);
				}
			}
			

		}
	}
}

int main()
{
#ifdef _DEBUG
	freopen("C:\\Users\\ekdls\\Desktop\\study\\9935.txt", "r", stdin);
#endif

	Input();
	Solution();
	string ret = "";
	if (st.empty())
	{
		cout << "FRULA\n";
	}
	else
	{
		while(!st.empty())
		{
			ret += st.top();
			st.pop();
		}
		reverse(ret.begin(), ret.end());
		cout << ret << "\n";
	}
	return 0;
}