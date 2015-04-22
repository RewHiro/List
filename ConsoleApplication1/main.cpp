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

	//　ループ中に削除する方法
	auto it = tests.begin();
	while(it != tests.end())
	{

		//　処理中
		it->Update();

		// 消す作業は必ず最後にしないとエラーを吐き出す
		if((it->id % 2) == 0)
		{
			it = tests.erase(it);
		}
		else it++;

	}



	//　【listのメンバ関数remove_ifとラムダ式】
	//　remove_ifにはいる引数
	//　bool (Object){} 
	//　ブールを返す引数はポインタのObject型以外だったら可能
	//　引数は増やせない
	//tests.remove_if([](const Object& object){  return (object.id % 2) == 0; });

	


	//　【listのメンバ関数eraseとalgorithmの関数removeifと無名関数でない関数】
	//　tests.erase(std::remove_if(tests.begin(), tests.end(), Id),tests.end());
	


	//　algorithmのremove_ifは削除しない値を先頭に詰め、要らなくなった要素のイテレーターを返す
	//　例：1～10あるとする
	//　listのサイズ -> 10
	//　偶数だけ消したい -> 2,4,6,8,10
	//　remove_if実行
	//　listの中 -> 1,3,5,7,9,?,?,?,?,?
	//　remove_ifは最初の?のイテレーターを返す
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