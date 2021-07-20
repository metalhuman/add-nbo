#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int readIntFromFile(const char* path) {
	FILE* fp = fopen(path, "rb");
	int fileContent;
	fread(&fileContent, sizeof(int), 1, fp);
	fclose(fp);

	int returnInt = ((fileContent >> 24) & 0xff) | // move byte 3 to byte 0
		((fileContent << 8) & 0xff0000) | // move byte 1 to byte 2
		((fileContent >> 8) & 0xff00) | // move byte 2 to byte 1
		((fileContent << 24) & 0xff000000); // byte 0 to byte 3

	return returnInt;
}

int main(int argc, char **argv)
{
	if (argc == 3) {
		int firstInt = readIntFromFile(argv[1]);
		int secondInt = readIntFromFile(argv[2]);

		printf("%d(%x) + %d(%x) = %d(%x)\n", firstInt, firstInt, secondInt, secondInt, firstInt + secondInt, firstInt + secondInt);
	}
	return 0;
}