#include "Maker.hpp" // ���ã�

/*
�������һ��
template<class NameType, class AgeType>
class Maker
{
public:
	Maker(NameType name, AgeType age);
	void printMaekr();
public:
	NameType name;
	AgeType age;
};
*/

int main()
{
	// �������ʱ������ģ���࣬��Ҫ������һ��
	Maker<string, int> m("С���", 20);
	m.printMaker();

	system("pause");
	return 0;
}