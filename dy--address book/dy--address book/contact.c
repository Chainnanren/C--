#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"

void InitContact(struct Contact* ps) {
	ps->data = (struct PeoInfo*)malloc(DEFAULT_SZ * sizeof(struct PeoInfo));
	if (ps->data == NULL) {
		return;
	}
	ps->size = 0;
	ps->capacity = DEFAULT_SZ;  
	//���ļ����Ѿ���ŵ�ͨѶ¼�е���Ϣ���ص�ͨѶ¼��
	void LoadContact(ps);
}

//��������
void CheckCapacity(struct Contact* ps);

void LoadContact(struct Contact* ps) {
	struct PeoInfo tmp = { 0 };
	FILE* pfRead = fopen("test.txt", "rb");
	if (pfRead == NULL) {
		printf("%s\n", strerror(errno));
		return;
	}
	//���ļ�����ŵ�ͨѶ¼��
	while (fread(&tmp, sizeof(struct PeoInfo), 1, pfRead)) {
		CheckCapacity(ps);
		ps->data[ps->size] = tmp;
		ps -> size++;
	}
	fclose(pfRead);
	pfRead = NULL;
}

void CheckCapacity(struct Contact* ps) {
	if (ps->size == ps->capacity) {
		struct PeoInfo* ptr = realloc(ps->data, (ps->capacity + 2) * sizeof(struct PeoInfo));
		if (ptr != NULL) {
			ps->data = ptr;
			ps->capacity += 2;
			printf("���ݳɹ�\n");
		}
		else {
			printf("����ʧ��\n");
		}
	}
}
void AddContact(struct Contact* ps) {
	/*��⵱ǰͨ��¼������
	  1.������ˣ������ӿռ�
	  2.���������ɶ��Ҳ����*/
	CheckCapacity(ps);
	printf("������:����>");
	scanf("%s", ps->data[ps->size].name);
	printf("������:����>");
	scanf("%d", &(ps->data[ps->size].age));
	printf("������:�Ա�>");
	scanf("%s", ps->data[ps->size].sex);
	printf("������:�绰>");
	scanf("%s", ps->data[ps->size].tele);
	printf("������:��ַ>");
	scanf("%s", ps->data[ps->size].addr);
	ps->size++;
	printf("��ӳɹ�\n");
	//��������
	/*if (ps->size == MAX) {
		printf("ͨѶ¼�������޷�����\n");
	}
	else {
		printf("������:����>");
		scanf("%s", ps->data[ps->size].name);
		printf("������:����>");
		scanf("%d", &(ps->data[ps->size].age));
		printf("������:�Ա�>");
		scanf("%s", ps->data[ps->size].sex);
		printf("������:�绰>");
		scanf("%s", ps->data[ps->size].tele);
		printf("������:��ַ>");
		scanf("%s", ps->data[ps->size].addr);
		ps->size++;
		printf("��ӳɹ�\n");
	}*/
}

//statciʹ�˺���ֻ����contact.c��ʹ��
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
	printf("������Ҫɾ���˵�����:>");
	scanf("%s", name);
	//1.����Ҫɾ������ʲôλ��
	/*�ҵ��˷����������ڵ��±�
	  �Ҳ�������-1*/
	int pos = FindByName(ps, name);
	//2.ɾ��
	if (pos == -1) {
		printf("Ҫɾ�����˲�����\n");
	}
	else {
		int j = 0;
		for (j = pos; j < ps->size - 1; j++) {
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("ɾ���ɹ�\n");
	}
}

void SearchContact(const struct Contact* ps) {
	char name[MAX_NAME];
	printf("������Ҫ�����˵�����:>");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (pos == -1) {
		printf("�Ҳ���Ҫ���ҵ���\n");
	}
	else {
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
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
	printf("������Ҫ�޸��˵�����:>");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (pos == -1) {
		printf("Ҫ�޸��˵���Ϣ������\n");
	}
	else {
		printf("������:����>");
		scanf("%s", ps->data[ps->size].name);
		printf("������:����>");
		scanf("%d", &(ps->data[ps->size].age));
		printf("������:�Ա�>");
		scanf("%s", ps->data[ps->size].sex);
		printf("������:�绰>");
		scanf("%s", ps->data[ps->size].tele);
		printf("������:��ַ>");
		scanf("%s", ps->data[ps->size].addr);
		printf("�޸ĳɹ�\n");
	}
}
void SortContact(struct Contact* ps) {
	int i = 0;
	struct PeoInfo tmp;
	printf("�������������\n");
	for (i = 0; i < ps->size; i++) {
		if (ps->data[i].name > ps->data[i].name) {
			tmp = ps->data[i + 1];
			ps->data[i + 1] = ps->data[i];
			ps->data[i] = tmp;
		}
	}
	printf("�������\n");
}

void DestroyContact(struct Contact* ps) {
	free(ps->data);
	ps->data = NULL;
}

void SaveContact(struct Contact* ps) {
	FILE* pfwrite = fopen("test.txt", "wb");
	if (pfwrite == NULL) {
		printf("%s\n", strerror(errno));
		return;
	}
	//дͨѶ¼�����ݵ��ļ���
	int i = 0;
	for (i = 0; i < ps->size; i++) {
		fwrite(&(ps->data[i]), sizeof(struct PeoInfo), 1, pfwrite);
	}
	fclose(pfwrite);
	pfwrite = NULL;
}

void ShowContact(const struct Contact* ps) {
	if (ps->size == 0) {
		printf("ͨѶ¼Ϊ��\n");
	}
	else {
		int i = 0;
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
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