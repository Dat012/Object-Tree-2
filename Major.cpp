#include "Major.h"
#include "Base.h"
#include "Heir2.h"
#include "Heir3.h"
#include "Heir4.h"
#include "Heir5.h"
#include "Heir6.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void Major::bild_tree_objects()  // Строим дерево объектов на основе введенных данных
{
    Base *cur_obj = this;  // Создаем основной объект, который равен this по умолчанию
    cur_obj -> class_number = 1;
    Base *cp = nullptr;
    string root_name;
    string parent_name;
    string heir_name;
    int cl_number;
    cin >> root_name;
    cur_obj->set_name(root_name);
    cin >> parent_name >> heir_name>>cl_number;
    while (parent_name != "endtree")
    {
        if (parent_name != cur_obj->get_name())
        {
            cur_obj = get_object(parent_name);
        }
        switch (cl_number)
        {
            case 2:
                cp = new Heir2(cur_obj, heir_name);
                break;
            case 3:
                cp = new Heir3(cur_obj, heir_name);
                break;
            case 4:
                cp = new Heir4(cur_obj, heir_name);
                break;
            case 5:
                cp = new Heir5(cur_obj, heir_name);
                break;
            case 6:
                cp = new Heir6(cur_obj, heir_name);
                break;
        }
        cp -> class_number = cl_number;
        cin >> parent_name;
        if (parent_name == "endtree")
        {
            while (cin)
            {
                cin>>heir_name;
                Base* ready = cp -> get_object_root() -> get_object(heir_name);
                int r;
                cin>>r;
                ready ->set_readiness(r);
            }
            break;
        }
        cin>>heir_name>>cl_number;
    }
}

void Major::exec_app()  //  Метод запуска приложения
{
    this->print_tree(0);
    cout << endl;
    this->print_tree(1);
}