
#ifndef __TEA_PCRE_H
#define __TEA_PCRE_H

#include <pcre.h>
#include <cstdio>
#include <string.h>
#include <stdlib.h>

class TeaPCRE
{
public:
	TeaPCRE();
	void setSubject(const char *subject);
	void setPattern(const char *pattern, int option = 0);
	void findAll(int rcOffset, char *result[], int *matchCount, unsigned int limit = 500);
	~TeaPCRE();
private:
	char *subject;
	const char *pattern;
	int option;
};

#endif
