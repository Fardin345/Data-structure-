#include <stdio.h>


//========================================== Sin() Function Recursion ======================================
double sinFunc(double x, int n) {
	static double s = 1;
	if (n == 0)
		return s;
	else {
		if(n%2!= 0)
		{
			s = (x / n) * s;
		}
		else if (n % 2 == 0) {
			s = 1 - (x / n) * s; //Mistake was done multiplying [(1-(x/n))*s] complete expression with s
		}

		
	}
	return sinFunc(x, n - 1);
}
//=========================================== Cos(x) Function Recursion ======================================
double cosFunc(double x, int n)
{
	static double s2 = 1;
	if (n == 0)
		return s2;
	else {
		if (n % 2 == 0)
		{
			s2 = (x / n) * s2;
		}
		else if(n%2!=0) {

			s2 = 1 - (x / n) * s2;
		}
	} 
	
	return cosFunc(x, n-1);
}

int main() {
	
	printf("%lf\n", sinFunc(0.7853939, 15));
	printf("%lf\n", cosFunc(0.7853939, 15));
	
	return 0;
}