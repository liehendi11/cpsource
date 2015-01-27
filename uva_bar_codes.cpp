#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <cstring>

using namespace std;

long long dp[52][52][52];
int n,k,m;

long long find(int a, int b, int c)
{

	if (dp[a][b][c] == -1)
	{
		if ((a==n) && (b == k) && (c<=m)) return 1;

		int temp=0;
		
		if ((a<n) && (c<m) && (b<k))
			temp += find(a+1, b, c+1);
		
		if ((a<n) && (b<k)) temp+=find(a+1, b+1, 1);

		dp[a][b][c] = temp;
	}
	
	return dp[a][b][c];
}

int main()
{
	while (scanf("%d%d%d", &n, &k, &m) != EOF)
	{
		memset(dp, -1, sizeof(dp));
		printf("%lld\n", find(0,0,1));
	}
	return 0;
}