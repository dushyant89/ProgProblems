#include <iostream>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	int a[n][m];
	for(int i=0; i<n; i++) for(int j=0; j<m; j++)
	{
		char t;
		cin >> t;
		switch(t)
		{
			case '.': a[i][j] = 1; break;
			case 'R': a[i][j] = 3; break;		// horz
			case 'B': a[i][j] = 5; break;		// vert
			case 'G': a[i][j] = 15; break;
		}
	}
	
	// red horz
	int count = 0;
	for(int i=0; i<n; i++)
	{
		int j=0;
		while(j<m)
		{
			bool flag = false;
			while(a[i][j]%3==0 && j<m){
				flag = true;
				a[i][j] /= 3;
				j++;
			}
			if(flag)
			{
				count++;
				flag = false;
			}
			j++;
		}
	}
	
	// blue vert
	for(int j=0; j<m; j++)
	{
		int i=0;
		while(i<n)
		{
			bool flag = false;
			while(a[i][j]%5==0 && i<n){
				flag = true;
				a[i][j] /= 5;
				i++;
			}
			if(flag)
			{
				count++;
				flag = false;
			}
			else i++;
		}
	}
	cout << count << endl;
}
