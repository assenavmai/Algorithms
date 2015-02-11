#include <math.h>
#include <stdio.h>
#include <time.h>

#define PHI ((1+sqrt(5))/2)

int fib1(int n) {
	if(n == 0)
		return 0;
	else if(n == 1)
		return 1;
	else
		return (fib1(n-1) + fib1(n-2));
   /*if (n<=1)
      return n;
   else
      return ( fib1(n-1) + fib1(n-2) );*/
}

long long int fib2(int n) {
	int fnow = 0, fnext = 1, tempf;
	while(--n>0){
		tempf = fnow + fnext;
		fnow = fnext;
		fnext = tempf;
		}
		return fnext;
}



long long unsigned fib3(unsigned n) {
    return floor( (pow(PHI, n) - pow(1 - PHI, n))/sqrt(5) );
}

int main(int argc, char const *argv[])
{
	int n, i,j = 0;
	unsigned f = 0, g = 0;
	int ret;
	double elapsed;
	clock_t start, finish;


	ret = 0;
	n = 50;
	f = 100;
	elapsed = 0;

	srand(time(NULL));
	start = clock();

	for(i = 1; i < f; i++)
	{
		ret = fib3(g);
		g++;
	}
	

	finish = clock();
    
    elapsed = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("time = %f \n\n", elapsed);

	return 0;
}