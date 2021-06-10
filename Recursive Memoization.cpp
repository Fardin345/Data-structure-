#include <stdio.h>

int F[10];
int rfibMem(int n)
{
	if (n <= 1)
	{
		F[n] = n;
		return n;
	}
	else 
	{
		if (F[n - 2] == -1)
		{
			F[n - 2] = rfibMem(n - 2);
		}
		if (F[n - 1] == -1) 
		{
			F[n - 1] = rfibMem(n - 1);
		}
	}
	return F[n - 2] + F[n - 1];
}


int main() 
{
	for (int i = 0; i < 10; i++) {
		F[i] = -1;
	}

	printf("%d \n", rfibMem(10));
	return 0;
}
