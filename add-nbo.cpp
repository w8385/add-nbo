#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include<netinet/in.h>

#define bufsize 32

void add(unsigned char buf1[], unsigned char buf2[]){
	uint32_t * pbuf1 = reinterpret_cast<uint32_t *>(buf1);
	uint32_t * pbuf2 = reinterpret_cast<uint32_t *>(buf2);
	
	uint32_t num1 = ntohl(*pbuf1);
	uint32_t num2 = ntohl(*pbuf2);
	unsigned int sum = num1 + num2;
	
	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", num1, num1, num2, num2, sum, sum);
}
int main(int argc, char *argv[]){
	int n;
	
	FILE * str1;
	FILE * str2;
	
	unsigned char buf1[bufsize];
	unsigned char buf2[bufsize];
	
	if (( str1 = fopen(argv[1], "rb")) != NULL){
		n = fread(buf1, 1, bufsize, str1);
		if(n) fclose(str1);
	}
	
	if (( str2 = fopen(argv[2], "rb")) != NULL){
		n = fread(buf2, 1, bufsize, str2);
		if(n) fclose(str2);
	}
	add(buf1, buf2);
}
