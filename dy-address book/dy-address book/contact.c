#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"

void InitContact(struct Contact* ps) {
	ps->data = (struct PeoInfo*)malloc(DEFAULT_SZ * sizeof(struct PeoInfo));
	if (ps->data == NULL) {
		return;
	}
	ps->size = 0;
	ps->capacity = DEFAULT_SZ;

}
void CheckCapacity(struct Contact* ps) {
	if (ps->size == ps->capacity) {
		struct PeoInfo* ptr = realloc(ps->data, (ps->capacity + 2) * sizeof(struct PeoInfo));
		if (ptr != NULL) {
			ps->data = ptr;
			ps->capacity += 2;
			printf("增容成功\n");
		}
		else {
			printf("增容失败\n");
		}
	}
}
void AddContact(struct Contact* ps) {
	/*检测当前通信录的容量
	  1.如果满了，就增加空间
	  2.如果不满，啥事也不干*/
	CheckCapacity(ps);
	printf("请输入:名字>");
	scanf("%s", ps->data[ps->size].name);
	printf("请输入:年龄>");
	scanf("%d", &(ps->data[ps->size].age));
	printf("请输入:性别>");
	scanf("%s", ps->data[ps->size].sex);
	printf("请输入:电话>");
	scanf("%s", ps->data[ps->size].tele);
	printf("请输入:地址>");
	scanf("%s", ps->data[ps->size].addr);
	ps->size++;
	printf("添加成功\n");
	//增加数据
	/*if (ps->size == MAX) {
		printf("通讯录已满，无法增加\n");
	}
	else {
		printf("请输入:名字>");
		scanf("%s", ps->data[ps->size].name);
		printf("请输入:年龄>");
		scanf("%d", &(ps->data[ps->size].age));
		printf("请输入:性别>");
		scanf("%s", ps->data[ps->size].sex);
		printf("请输入:电话>");
		scanf("%s", ps->data[ps->size].tele);
		printf("请输入:地址>");
		scanf("%s", ps->data[ps->size].addr);
		ps->size++;
		printf("添加成功\n");
	}*/
}

//statci使此函数只能在contact.c中使用
static int FindByName(const struct Contact* ps, char name[MAX_NAME]) {
	int i = 0;
	for (i = 0; i < ps->size; i++) {
		if (strcmp(ps->data[i].name, name) == 0) {
			return i;
		}
	}
	return -1;
}

void DelContact(struct Contact* ps) {
	char name[MAX_NAME];
	printf("请输入要删除人的名字:>");
	scanf("%s", name);
	//1.查找要删除人在什么位置
	/*找到了返回名字所在的下标
	  找不到返回-1*/
	int pos = FindByName(ps, name);
	//2.删除
	if (pos == -1) {
		printf("要删除的人不存在\n");
	}
	else {
		int j = 0;
		for (j = pos; j < ps->size - 1; j++) {
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("删除成功\n");
	}
}

void SearchContact(const struct Contact* ps) {
	char name[MAX_NAME];
	printf("请输入要查找人的名字:>");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (pos == -1) {
		printf("找不到要查找的人\n");
	}
	else {
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
		printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
			ps->data[pos].name,
			ps->data[pos].age,
			ps->data[pos].sex,
			ps->data[pos].tele,
			ps->data[pos].addr);
	}
}

void ModifyContact(const struct Contact* ps) {
	char name[MAX_NAME];
	printf("请输入要修改人的名字:>");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (pos == -1) {
		printf("要修改人的信息不存在\n");
	}
	else {
		printf("请输入:名字>");
		scanf("%s", ps->data[ps->size].name);
		printf("请输入:年龄>");
		scanf("%d", &(ps->data[ps->size].age));
		printf("请输入:性别>");
		scanf("%s", ps->data[ps->size].sex);
		printf("请输入:电话>");
		scanf("%s", ps->data[ps->size].tele);
		printf("请输入:地址>");
		scanf("%s", ps->data[ps->size].addr);
		printf("修改成功\n");
	}
}
void SortContact(struct Contact* ps) {
	int i = 0;
	struct PeoInfo tmp;
	printf("按年龄进行排序\n");
	for (i = 0; i < ps->size; i++) {
		if (ps->data[i].name > ps->data[i].name) {
			tmp = ps->data[i + 1];
			ps->data[i + 1] = ps->data[i];
			ps->data[i] = tmp;
		}
	}
	printf("排序完成\n");
}

void DestroyContact(struct Contact* ps) {
	free(ps->data);
	ps->data = NULL;
}

void ShowContact(const struct Contact* ps) {
	if (ps->size == 0) {
		printf("通讯录为空\n");
	}
	else {
		int i = 0;
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
		for (i = 0; i < ps->size; i++) {
			printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
				ps->data[i].name,
				ps->data[i].age,
				ps->data[i].sex,
				ps->data[i].tele,
				ps->data[i].addr);
		}
	}
}