#include <stdio.h>

void myWhile() {
	while (1) {printf("aaa\n");break;}
}

int main() {
	myWhile();
	while (2) {printf("bbb\n");break;}
}
