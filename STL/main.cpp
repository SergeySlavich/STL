#include<iostream>
#include<array>
#include<vector>
#include<deque>
#include<list>
#include<string>
#include<map>

using std::cin;
using std::cout;
using std::endl;

//STL:
//https://legacy.cplusplus.com/reference/stl/
//1. Разобраться с forward_list;
//2. Написать словарь, в котором каждому английскому слову соответствует несколько вариантов перевода на русский,
//	например:
//		Space - пробел, пространство, космос;
//		Set - задать, установить, набор;
//		Call - звонок, вызов, назвать;



#define tab "\t"
#define delimiter "\n--------------------------\n"

//https://legacy.cplusplus.com/reference/stl/

template<typename T>void vector_properties(const std::vector<T>& vec)
{
	cout << "Size:\t\t" << vec.size() << endl;
	cout << "Capacity:\t" << vec.capacity() << endl;
	cout << "Max size:\t" << vec.max_size() << endl;
}

//#define STL_ARRAY
//#define STL_VECTOR
//#define STL_DEQUE
//#define STL_LIST
#define HOME_WORK_STL_1

void main()
{
	setlocale(LC_ALL, "");
#ifdef STL_ARRAY
	//array - это контейнер, который хранит данные в виде статического массива.
	const int N = 5;
	std::array<int, N> arr = { 3, 5, 8 };
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr.data()[i] << tab;
	}
	cout << endl;
#endif // STL_ARRAY

#ifdef STL_VECTOR
	//vector - это контейнер, который хранит данные в виде динамического массива.
	//vector позволяет добавлять значения только в конец, и удалять элементы только с конца,
	//это НЕ считая вставки и удаления по индексу.
	std::vector<int> vec = { 0, 55, 1, 1, 2, 3, 5, 8, 13, 21, 34 };
	vec.resize(22);
	for (int i = 0; i < vec.capacity(); i++)
	{
		cout << vec[i] << tab;
		//cout << vec.at(i) << tab;
	}
	cout << endl;
	//vec.resize(8);
	try
	{
		for (int i = 0; i < vec.capacity(); i++)
		{
			//cout << vec[i] << tab;
			cout << vec.at(i) << tab;
		}
		cout << endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << endl;
	}
	vector_properties(vec);
	cout << delimiter << endl;
	std::vector<int> vec2(100);
	vector_properties(vec2);
	cout << delimiter << endl;
	vec2.push_back(123);
	vector_properties(vec2);
	//cout << delimiter << endl;
	//vec2.shrink_to_fit();	//убирает всю зарезервированную память, т.е., уменьшает capacity до фактического размера (size)
	//vector_properties(vec2);
	cout << delimiter << endl;
	for (int i = 0; i < 90; i++)vec2.pop_back();
	vector_properties(vec2);
	cout << delimiter << endl;
	vec2.reserve(255);
	vec2.resize(8);
	vector_properties(vec2);

	int index;
	int count;
	int value;
	cout << "Input index adding element: "; cin >> index;
	cout << "Input count adding element: "; cin >> count;
	cout << "Input value adding element: "; cin >> value;
	vec.insert(vec.begin() + index, count, value);
	for (int i : vec) cout << i << tab; cout << endl;

#endif // STL_VECTOR

#ifdef STL_DEQUE
	std::deque<int> deque = { 3, 5, 8, 13, 21 };
	for (int i = 0; i < deque.size(); i++)
	{
		cout << deque[i] << tab;
	}
	cout << endl;
	deque.push_front(2);
	deque.push_back(34);
#endif

#ifdef STL_LIST
	//list - это контейнер, кроторый хранит данные в виде двусвязного списка
	std::list<int> list = { 3, 5, 8, 13, 21 };
	/*for (int i = 0; i < list.size(); i++)
	{
		cout << list[i] << tab;
	}
	cout << endl;*/
	for (std::list<int>::iterator it = list.begin(); it != list.end(); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;
	for (std::list<int>::reverse_iterator rit = list.rbegin(); rit != list.rend(); ++rit)
	{
		cout << *rit << tab;
	}
	cout << endl;

	int index;
	int value;
	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	cout << "Введите значение добавляемого элемента: "; cin >> value;
	std::list<int>::iterator position = list.begin();
	//for (int i = 0; i < index; i++)++position;
	std::advance(position, index);
	list.insert(position, value);
	for (int i : list)cout << i << tab; cout << endl;
#endif // STL_LIST

#ifdef HOME_WORK_STL_1
	//1. Разобраться с forward_list;
	//2. Написать словарь, в котором каждому английскому слову соответствует несколько вариантов перевода на русский,
	std::multimap<std::string, std::string> dictionary =
	{
		{"Space", "Пробел"},
		{"Space", "Пространство"},
		{"Space", "Космос"},
		{"Set", "Задать"},
		{"Set", "Установить"},
		{"Set", "Набор"},
		{"Call", "Звонок"},
		{"Call", "Вызвать"},
		{"Call", "Назвать"},
		{"Mine", "Мой"},
		{"Mine", "Шахта"},
		{"Mine", "Мина"},
		{"Bolt", "Болт"},
		{"Bolt", "Вспышка молнии"},
		{"Bolt", "Быстро (внезапно) бежать"},
		{"Draft", "Сквозняк"},
		{"Draft", "Проект, черновик"},
		{"Draft", "Призыв (в армию)"},
		{"Squash", "Овощи семейства тыквенных"},
		{"Squash", "Игра с ракетками и мячами"},
		{"Squash", "Раздавить"}
	};
	for (std::multimap<std::string, std::string>::iterator it = dictionary.begin(); it != dictionary.end(); ++it)
	{
		cout << it->first << endl;
		if (it->first == (++it)->first) ++it;
	}
	std::string keyword;
	cout << "input word for output value: "; cin >> keyword;
	cout << endl;
	for (std::multimap<std::string, std::string>::iterator it = dictionary.begin(); it != dictionary.end(); ++it)
	{
		if (it->first == keyword)
		{
			cout << it->first << " - " << it->second << endl;
		}
	}
#endif
}
