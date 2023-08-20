// 03_association.cpp

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Patient
{
public:
	Patient(const string& name)
		: name(name)
	{}

	void AddDoctor(class Doctor* const doctor)
	{
		doctors.push_back(doctor);
	}

	void MeetDoctor(); // Doctor�� ���Ǻΰ� �ڿ� �����Ƿ� ����� �ٵ� �������Ѵ�.

private:
	string name;
	friend class Doctor;
	vector<class Doctor*> doctors;
};

class Doctor
{
public:
	Doctor(const string& name)
		: name(name)
	{}

	void AddPatient(class Patient* const patient)
	{
		patients.push_back(patient);
	}

	void MeetPatient()	// Patient�� ���Ǻΰ� �տ� �����Ƿ� �ٷ� ���� ����
	{
		for (const auto& patient : patients)
			cout << "Meet Patient : " << patient->name << endl;
	}

private:
	string name;
	friend class Patient;
	vector<class Patient*> patients;
};

//
void Patient::MeetDoctor()
{
	for (const auto& doctor : doctors)
		cout << "Meet Doctor : " << doctor->name << endl;
}


int main()
{
	Patient* p1 = new Patient("Kim");
	Patient* p2 = new Patient("Part");
	Patient* p3 = new Patient("Lee");

	Doctor* d1 = new Doctor("Doc. Lee");
	Doctor* d2 = new Doctor("Doc. Kim");

	// Associztion(����)
	// ��Ⱓ���� ġ�Ḧ ���� ��� �ǻ�� ȯ���� ��� �ǻ絵 ȯ�ڸ� �˾ƾ��ϰ�, ȯ�ڵ� �ǻ縦 �˾ƾ��Ѵ�.
	// ���ΰ� ���ο��� ������ ���� �� �ִ�. (���� ���� ���, �ϳ� �ٲ�� �� �� ������ �� �ֱ� ���� <Ŀ�ø�����>)
	p1->AddDoctor(d1);
	d1->AddPatient(p1);

	p2->AddDoctor(d2);
	d2->AddPatient(p2);

	p3->AddDoctor(d2);
	d2->AddPatient(p3);

	p2->MeetDoctor();
	d2->MeetPatient();

	// ���� ������� Ŭ������ �ٸ� Ŭ������ ���踦 ������ �ֱ� ������
	// �ٸ� Ŭ�������� ���� ����� �Ǹ� ������ ���� �� �ִ�. 
	// �׷��� ������ ���� �� ������ �������� �����ϴ°� ����.
	delete d2; // ������ �������� �����Ѵ�. ���� ������ Ŭ������ �ٸ� Ŭ������ ���踦 �ΰ� ���� ���ɼ��� ���� �����̴�.
	delete d1;
	delete p3;
	delete p2;
	delete p1;


	return 0;
}
