#include <stdio.h>

void print_binary(long n){
	int i = 0;
	while (n) {	
    		if (n & 1)
        		printf("1");
    		else
        		printf("0");
    		n >>= 1;
		i++;
	}
	printf("\n");
	printf("%d\n", i);
}

int main(){
	float a = 2.2;
	long hacks = * (long *) &a;
	print_binary(hacks);
}
