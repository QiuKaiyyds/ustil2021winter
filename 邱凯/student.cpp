#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class Score {
public:
	int chinese;
	int maths;
	int english;
	void inputscore(int e, int m, int c) {
		this->chinese = e;
		this->maths = m;
		this->english = c;
	}
};
class Student
{
public:
	void inputname() {
		this->name = "xioaming";
	}
	friend Score;
	Student() {}
	
	Student(string a, string b, int e, int m, int c);
	
	~Student();

	Student(const Student& temp) {
		this->id = temp.id;
		this->name = temp.name;
		this->score.chinese = temp.score.chinese;
		this->score.maths = temp.score.maths;
		this->score.english = temp.score.english;
		num++;
	}

	void Print(Student stu[]);
	void Update(Student* stu);
	void  AverageScore(Student stu[]);
	Student input();

	string id;
	string name;
	Score score;
	Score* pscore;
	
	static int num;//����
	static void shownum() {
		cout << num/3 << endl;
	}
};

int Student::num = 0;//��̬���ݳ�Ա����ͳ�ʼ��

Student::~Student() {
	num++;
}
// ��ʾѧ������
void Student::Print	(Student stu[]) {
	cout << "����   ѧ��   ����   ��ѧ  Ӣ��   ƽ���ɼ�" << endl;
	for (int i = 1; i <= num/3; i++) {
		cout << stu[i].name << "   " << stu[i].id << "   " << stu[i].score.chinese << "   " << stu[i].score.maths;
		cout << "   " << stu[i].score.english << "   " << (stu[i].score.chinese + stu[i].score.maths + stu[i].score.english) / 3 << endl;
	}
}

//�޸�ĳѧ������
void Student::Update(Student* stu) {
	int i;
	pscore = &stu->score;
	cout << "�밴˳���������ݣ�ÿ��������밴�س�" << endl;
	cout << "ѧ��  ����  ���ĳɼ�  ��ѧ�ɼ�  Ӣ��ɼ�" << endl;
	cin >> stu->id;
	cin >> stu->name; 
	cin >> stu->pscore->chinese;
	cin >> stu->pscore->maths; 
	cin >> stu->pscore->english; 
}

//�����Ŀƽ����
void  Student::AverageScore(Student stu[]) {
	int sum = 0;
	cout << "����\t��ѧ\tӢ��" << endl;
	for (int i = 1; i <= num / 3; i++) {
		sum += stu[i].score.chinese;
	}
	cout << sum / (num / 3) << "	";
	sum = 0;
	for (int i = 1; i <= num / 3; i++) {
		sum += stu[i].score.maths;
	}
	cout << sum / (num / 3) << "	";
	sum = 0;
	for (int i = 1; i <= num / 3; i++) {
		sum += stu[i].score.english;
	}
	cout << sum / (num / 3) << "	" << endl;
}
//���ѧ����Ϣ
Student Student::input()     //����ѧ����Ϣ����
{
	Student stu;
	cout << "ѧ�ţ�";
	cin >> stu.id;
	cout << "������";
	cin >> stu.name;
	cout << "chinese��";
	cin >> stu.score.chinese;
	cout << "math��";
	cin >> stu.score.maths;
	cout << "english��";
	cin >> stu.score.english;
	return stu;
}

//��ӭ����
void welcomemenu() {
	cout << "1.��ʾѧ������" << endl;
	cout << "2.���ѧ����Ϣ" << endl;
	cout << "3.�����Ŀƽ����" << endl;
	cout << "4.�鿴ѧ������" << endl;
	cout << "5.�޸�ĳѧ������" << endl;
}
int main() {
	int i, a;
	Student stu, st[100];
	int Num = 1;
	welcomemenu();
	while (cin >> i){
		switch (i){
		case 1:
			stu.Print(st);
			break;
		case 2:
			st[Num] = stu.input();
			Num++;//��������˿������캯��
			break;
		case 3:
			stu.AverageScore(st);
			break;
		case 4:stu.shownum();//��̬�������ʾ�̬��Ա
			break;
		case 5:
			cout << "������Ҫ�޸ĵ�ѧ�������" << endl;
			cin >> a;
			st[a].Update(&st[a]);
			break;
		}
		system("pause");
		system("cls");
		welcomemenu();//������
	}
	return 0;
}