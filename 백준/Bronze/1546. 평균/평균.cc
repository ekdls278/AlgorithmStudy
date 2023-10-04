#include<iostream>

int main() {
	int N;
	double Max=0;
	double res = 0;
	std::cin >> N;
	double* arr = new double[N];

	for (int i = 0; i < N; i++) {
		std::cin >> *(arr + i);
		if(Max < *(arr + i)) {
			Max = *(arr + i);
		}
	}
	
	for (int j = 0; j < N; j++) {
		res += *(arr + j) / Max * 100;
	}
	std::cout << res/N;


	delete[] arr;

	return 0;
}