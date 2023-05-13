#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
    int answer = 0;
    while(storey != 0)
    {
        int n = storey%10;
        
        if(n > 5)
        {
            answer += 10-n;
            storey /= 10;
            storey++;
        }
        else if (n==5)
        {
            int tmp = (storey/10)%10;
            if(tmp>=5)
            {
                storey/=10;
                storey++;
            }
            else
            {
                storey/=10;
            }
            answer +=5;
        }
        else
        {
            answer +=n;
            storey /=10;
        }
        
    }
    return answer;
}