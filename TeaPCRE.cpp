
#include "TeaPCRE.h"

TeaPCRE::TeaPCRE() {

}

void TeaPCRE::setSubject(const char *subject) {
	this->subject = (char*)malloc(strlen(subject) * sizeof(char*));
	strcpy(this->subject, subject);
}

void TeaPCRE::setPattern(const char *pattern, int option) {
	this->option = option;
	this->pattern = pattern;
}

void TeaPCRE::findAll(int rcOffset, char *result[], int *matchCount, unsigned int limit) {
	
    int erroffset, rc, i, ovector[100], j = 0;
    size_t subjectLength = strlen(this->subject);

    char *str = (char*)malloc(subjectLength * sizeof(char*));
    const char *error;

    memcpy(str, this->subject, subjectLength);
	pcre *re = pcre_compile(this->pattern, this->option, &error, &erroffset, 0);

    unsigned int offset = 0;
    unsigned int len    = strlen(str);

    *matchCount = 0;
    while (offset < len && (rc = pcre_exec(re, 0, str, len, offset, 0, ovector, sizeof(ovector))) >= 0)
    {
        for(i = 0; i < rc; ++i){
            if (i == rcOffset) {
            	if ((*matchCount) == limit) {
            		return;
            	}
            	char *tmp = str + ovector[2*i];
            	result[j] = (char*)malloc(strlen(tmp) * sizeof(char*));
            	sprintf(result[j++], "%.*s", ovector[2*i+1] - ovector[2*i], tmp);
            	*matchCount = (*matchCount) + 1;
            }
        }
        offset = ovector[1];
    }
}

TeaPCRE::~TeaPCRE() {
	
}
