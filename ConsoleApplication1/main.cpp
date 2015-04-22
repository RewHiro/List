#include <iostream>
#include <list>
#include <algorithm>

class Object{
public:
	int id = 0;
	explicit Object(int i):
		id(i){}

	void Update(){}
};

bool Id(const Object& object)
{
	return (object.id % 2) == 0;
}

int main()
{
	std::list<Object>tests;
	for (int i = 1; i < 10; i++)
	{
		tests.emplace_back(Object(i));
	}

	//�@���[�v���ɍ폜������@
	auto it = tests.begin();
	while(it != tests.end())
	{

		//�@������
		it->Update();

		// ������Ƃ͕K���Ō�ɂ��Ȃ��ƃG���[��f���o��
		if((it->id % 2) == 0)
		{
			it = tests.erase(it);
		}
		else it++;

	}



	//�@�ylist�̃����o�֐�remove_if�ƃ����_���z
	//�@remove_if�ɂ͂������
	//�@bool (Object){} 
	//�@�u�[����Ԃ������̓|�C���^��Object�^�ȊO��������\
	//�@�����͑��₹�Ȃ�
	//tests.remove_if([](const Object& object){  return (object.id % 2) == 0; });

	


	//�@�ylist�̃����o�֐�erase��algorithm�̊֐�removeif�Ɩ����֐��łȂ��֐��z
	//�@tests.erase(std::remove_if(tests.begin(), tests.end(), Id),tests.end());
	


	//�@algorithm��remove_if�͍폜���Ȃ��l��擪�ɋl�߁A�v��Ȃ��Ȃ����v�f�̃C�e���[�^�[��Ԃ�
	//�@��F1�`10����Ƃ���
	//�@list�̃T�C�Y -> 10
	//�@���������������� -> 2,4,6,8,10
	//�@remove_if���s
	//�@list�̒� -> 1,3,5,7,9,?,?,?,?,?
	//�@remove_if�͍ŏ���?�̃C�e���[�^�[��Ԃ�
	//std::list<Object>::iterator itr = std::remove_if(tests.begin(), tests.end(), Id);
	//std::cout << tests.size() << std::endl;
	//while(itr != tests.end())
	//{
	//	std::cout << itr->id << std::endl;
	//	itr++;
	//}
	

	for(auto& test : tests)
	{
		std::cout << test.id << std::endl;
	}

}