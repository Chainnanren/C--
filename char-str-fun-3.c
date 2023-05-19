//strstr函数 - 查找字符串
#include<string.h>
int main() {
	char* p1 = "abcdef";
	char* p2 = "cd";
	char* ret = strstr(p1, p2);
	if (ret == NULL) {
		printf("字符串不存在\n");
	}
	else {
		printf("%s\n", ret);
	}
		return 0;
}

//strstr函数的实现
#include<assert.h>
char* my_strstr(char* p1, char* p2) {
	assert(p1 != NULL);
	assert(p2 != NULL);
	char* s1 = p1;
	char* s2 = p2;
	char* cur=p1;
	if (*p2 == '\0') {
		return p1;
	}
	while (*cur) {
		s1 = cur;
		s2 = p2;
		while ((*s1 != '\0') && (*s2 != '\0') && (*s1 == *s2)) {
			s1++;
			s2++;
		}
		if (*s2 == '\0') {
			return cur;//找到子串
			}
		if (*s1 == '\0') {
			return NULL;
		}
		cur++;
	}
	return NULL;//找不到子串
}
int main() {
	char* p1 = "abcdef";
	char* p2 = "ed";
	char*  ret = my_strstr(p1, p2);
	if (ret == NULL) {
		printf("字符串不存在\n");
	}
	else {
		printf("%s\n", ret);
	}
	return 0;
}