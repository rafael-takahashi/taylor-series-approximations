#include <stdio.h>

int main(){
	int x;

	scanf("%d", &x);
	
	if (x & 1)
		printf("odd\n");
	else
		printf("even\n");
}
