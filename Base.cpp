#include "Base.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

Base::Base(Base *parent, string name)  // Конструктор для объектов иерархии
{
	this->parent = parent;  // Присваиваем родителя, переданного в аргументах
	this->name = name;  // Присваиваем имя, переданное в аргументах
	readiness = 0;
	if (parent != nullptr)  // Если родитель, создаваемого объекта не нулевой,
	{
		parent->heirs.push_back(this);  // то мы добавляем этот объект в вектор родителя
	}
}

void Base::set_name(string name)  // Присваиваем имя объекту
{
	this->name = name;
}

string Base::get_name()  // Получаем имя объекта
{
	return name;
}

int Base::get_readiness() const
{
	return readiness;
}

Base *Base::get_object_root()
{
    Base* parent_previous = parent;  // Получаем родителя у объекта, который вызвал этот метод
    while (parent_previous -> parent != nullptr)  // Пока существует родитель у объекта, который вызывает метод get_object_root()
    {
        parent_previous = parent_previous -> parent;  // Текущим объектом становится родитель прошлого текущего объекта
    }
    return parent_previous; // Возвращаем объект, у которого нет родителя, т.е корневой
}

Base *Base::get_object(string s)
{
    if (name == s)  // Если имя объекта, который вызвал этот метод равно аргументу
    {
        return this;
    }
    for (int i = 0; i < heirs.size(); i++)
    {
        if (!heirs[i] -> heirs.empty())
        {
            Base* res = heirs[i] -> get_object(s);
            if (res != nullptr)
            {
                return res;
            }
        }
    }
	return nullptr;
}

void Base::print_tree(int is_ready)
{
    if (!is_ready)
    {
        cout<<"Object tree\n";
        print_objects(0,0);
    }
    else
    {
        cout << "The tree of objects and treir readiness\n";
        print_objects(0,1);
    }
}

void Base::print_objects (int level, int is_ready)
{
    string space;
    string ready;
    if (level > 0)
    {
        space.append(4*level, ' ');
    }
    cout << space << get_name();
    get_readiness() ? ready = "is ready" : ready = "is not ready";
    //is_ready ? cout << " " << ready << endl : cout << endl;
    if (is_ready)
    {
        cout <<" "<< ready;
    }
    level++;
    if (heirs.empty())
    {
        return;
    }
    for (int i = 0; i< heirs.size(); i++)
    {
        cout<<endl;
        heirs[i] -> print_objects(level, is_ready);
    }
    level--;
}

int Base::set_readiness(int readiness2)  // Метод присвоения готовности
{
    this-> readiness = what_readiness(readiness2);  // Определяем готовность у объекта, который вызвал этот метод, в соответствии с условием задачи
    return readiness;
}

int Base::what_readiness(int readiness2)  // Метод определения готовности
{
    if (parent == nullptr)
    {
        return readiness2;
    }
    else if (parent -> readiness == 0)
    {
        return 0;
    }
    else
    {
        readiness2 = parent -> what_readiness(readiness2);
        return readiness2;
    }
}

Base *Base::get_parent()  // Возвращаем родителя текущего объекта
{
    return parent;
}

const string &Base::get_object_path() const
{
	return object_path;
}

/* void Base::print_tree_old()  // Печатаем весь вектор объекта, который вызвал этот метод
{
	if (this->parent == nullptr)
	{  // Если у объекта нет parent, то печатаем его в соответствии с условием задачи
		cout << this->get_name() << "\n";
		cout << this->get_name() << "  ";
	}
	for (int i = 0; i < heirs.size() - 1; i++)  // Выводим весь вектор объекта до последнего объекта невключительно
	{
		cout << heirs[i]->get_name() << "  ";  // С двумя пробелами
	}
	cout << heirs[heirs.size() - 1]->get_name();  // Последний объект выводим без пробела

	for (int j = 0; j < heirs.size(); j++)
	{
		if (!heirs[j]->heirs.empty())  // Если вектор parent не пустой
		{
			cout << "\n" << heirs[j]->get_name() << "  ";
			heirs[j]->print_tree_old();  // , то печатаем наследников
		}
	}
} */
