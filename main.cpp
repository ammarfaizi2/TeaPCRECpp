
#include <cstdio>
#include <stdlib.h>
#include "TeaPCRE.h"

int main(int argc, char const *argv[])
{
	char **result = (char**)malloc(200 * sizeof(char*));
	TeaPCRE tre;
	tre.setSubject("asd123qwe345p12g031230ei1e2ee000aaa919");
	tre.setPattern("(?:\\D|^)(\\d{3})(?:\\D|$)");

	unsigned int matchCount, i;

	tre.findAll(1, result, &matchCount, 4u);

	for (i = 0; i < matchCount; ++i)
	{
		printf("%s\n", result[i]);
	}

	return 0;
}
