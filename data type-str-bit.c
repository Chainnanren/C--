//λ��
/*λ�ε������ͽṹ�����Ƶģ���������ͬ��
	1.λ�εĳ�Ա������int��unsigned int��signed int�������ξͿ��ԣ�
	2.λ�εĳ�Ա�������һ��ð�ź�һ������*/

//λ�� - ������λ
/*λ�ε��ڴ����
	1.λ�εĳ�Ա������int��unsigned int��signed int������char���������μ��壩����
	2.λ�εĿռ����ǰ�����Ҫ��4���ֽڣ�int������1���ֽڣ�char���ķ�ʽ�����ٵ�
	3.λ���漰�ܶ಻ȷ�����أ�λ���ǲ���ƽ̨�ģ�ע�ؿ���ֲ�ĳ���Ӧ�ñ���ʹ��λ��*/
struct S {
	int a : 2;//aֻ��Ҫռ2��bit
	int b : 5;//bֻ��Ҫռ5��bit
	int c : 10;
	int d : 30;
};
int main() {
	struct S s;
	return 0;
}
//��Ҫ����8���ֽڵĿռ�

struct S1 {
	char a : 3;
	char b : 4;
	char c : 5;
	char d : 4;
};
int main() {
	struct S1 s = { 0 };
	s.a = 10;
	s.b = 20;
	s.c = 3;
	s.d = 4;
	return 0;
}

/*λ�εĿ�ƽ̨����
	1.intλ�α������з����������޷������ǲ�ȷ����
	2.λ�������λ����Ŀ��ȷ����16λ�������16��32λ�������32��д��27����16λ
	����������⣩
	3.λ���еĳ�Ա���ڴ��д������ҷ��䣬���Ǵ�����������׼��δ����
	4.��һ���ṹ��������λ�Σ��ڶ���λ�γ�Ա�Ƚϴ��޷������ڵ�һ��λ��
	ʣ���λʱ��������ʣ���λ�������ã����ǲ�ȷ����*/
//�ܽڣ�
	//���ṹ��ȣ�λ�ο��Դﵽͬ����Ч�������ǿ��ԺܺõĽ�ʡ�ռ䣬�����п�ƽ̨���������