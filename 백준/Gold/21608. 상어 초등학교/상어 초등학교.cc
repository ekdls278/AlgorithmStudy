#include <stdio.h>
#include <vector>
#include <algorithm>
#pragma warning (disable: 4996)
#define MAX 25
using namespace std;

struct Student
{
	int loveNum;
	int emptyNum;
	int y;
	int x;
};

bool compare(Student A, Student B)
{
	if (A.loveNum == B.loveNum)
	{
		if (A.emptyNum == B.emptyNum)
		{
			if (A.y == B.y)
			{
				return A.x < B.x;
			}
			return A.y < B.y;
		}
		return A.emptyNum > B.emptyNum;
	}
	return A.loveNum > B.loveNum;
}

int dy[] = { 0, -1, 0, 1 };
int dx[] = { -1, 0 ,1 ,0 };

vector<vector<Student>> vec;
int arr[MAX * MAX][5];
int studentSit[MAX][MAX];
int n;
int studentNum;
int main()
{
#ifdef _DEBUG
	freopen("C:\\Users\\ekdls\\Desktop\\study\\21608.txt", "r", stdin);
#endif
	scanf("%d", &n);
	vec.resize(n*n + 2);
	//n*n명의 학생 정보 입력받기
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &studentNum);
			for (int k = 0; k < 4; k++)
			{
				scanf("%d", &arr[studentNum][k]);
			}
			// 전체 돌면서 자리 찾기
			for (int p = 0; p < n; p++)
			{
				for (int q = 0; q < n; q++)
				{
					//검사 하려는 자리가 이미 사람이 있으면 continue;
					if (studentSit[p][q])continue;
					Student nowInfo = { 0, 0, p, q };
					for (int d = 0; d < 4; d++)
					{
						int ny = p + dy[d];
						int nx = q + dx[d];
						//범위 밖 예외처리
						if (ny >= n || ny<0 || nx>=n || nx < 0)continue;
						//검사 하려는 자리가 비어 있으면
						if (!studentSit[ny][nx]) {
							nowInfo.emptyNum++;
							continue;
						}
						//좋아하는 사람이 있는지 검사
						for (int z = 0; z < 4; z++)
						{
							if (arr[studentNum][z] == studentSit[ny][nx])
							{
								nowInfo.loveNum++;
							}
						}
					}
					vec[studentNum].push_back(nowInfo);
				}
			}
			sort(vec[studentNum].begin(), vec[studentNum].end(), compare);
			studentSit[vec[studentNum][0].y][vec[studentNum][0].x] = studentNum;
		}
	}
	int answer = 0;
	int scoreLevel[5] = { 0,1,10,100,1000 };
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int nowStudent = studentSit[i][j];
			int nowScore = 0;
			//arr[nowStudent][0~3];
			for (int p = 0; p < 4; p++)
			{
				int ny = i + dy[p];
				int nx = j + dx[p];
				if (ny >= n || ny < 0 || nx >= n || nx < 0)continue;
				for (int q = 0; q < 4; q++)
				{
					if (studentSit[ny][nx] == arr[nowStudent][q])nowScore++;
				}
			}
			answer += scoreLevel[nowScore];
		}
	}

	printf("%d", answer);
}