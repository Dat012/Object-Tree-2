#ifndef BASE_H
#define BASE_H

#include <string>
#include <vector>

using namespace std;

class Base {
private:
	string name;
	string object_path;
	Base *parent;
	vector<Base *> heirs;
public:
	int readiness; //поле готовности

	int class_number; //номер класса

	Base(Base *parent = nullptr, string name = "");

	Base* get_object_root();

	Base* get_object(string obj_name);

	void set_name(string name);

	string get_name();

	void print_tree(int is_ready);

    void print_objects(int level, int is_ready);

	void set_parent(Base *parent);

	Base *get_parent();

	Base *get_object();



	int get_readiness() const;

	int set_readiness(int readiness);

	int what_readiness(int readiness);

	void set_object_path(const string &objectPath);

	const string &get_object_path() const;
};

#endif