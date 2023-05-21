#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int N;
string str;
vector<vector<int>> vec(5);
vector<string> input;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string num = "";
		int idx = 0;
		cin >> str;
		input.push_back(str);
		if (str[0] == 'B')
		{
			idx = 0;
		}
		else if (str[0] == 'S')
		{
			idx = 1;
		}
		else if (str[0] == 'G')
		{
			idx = 2;
		}
		else if (str[0] == 'P')
		{
			idx = 3;
		}
		else
		{
			idx = 4;
		}

		for (int j = 1; j < str.size(); j++)
		{
			num += str[j];
		}
		vec[idx].push_back(stoi(num));
	}
	vector<string> answer;
	vector<string> teir = { "B", "S", "G", "P", "D" };
	for (int i = 0; i < 5; i++)
	{
		if (!vec[i].empty())
		{
			sort(vec[i].begin(), vec[i].end(), greater<>());
			for (auto it : vec[i])
			{
				answer.push_back(teir[i] + (to_string(it)));
			}
		}
		
	}
	vector<string> solvec;
	for (int i = 0; i < input.size(); i++)
	{
		if (answer[i] != input[i])
		{
			solvec.push_back(input[i]);
		}
	}
	if (solvec.empty())
	{
		cout << "OK";
	}
	else
	{
		cout << "KO\n";
		reverse(solvec.begin(), solvec.end());
		for (auto it : solvec)
		{
			cout << it << " ";
		}
	}

	return 0;
}