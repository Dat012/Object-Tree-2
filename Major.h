#ifndef MAJOR_H
#define MAJOR_H

#include <vector>
#include <string>
#include <iostream>
#include "Base.h"

class Major : public Base
{
public:
	using Base::Base;

	void bild_tree_objects();

	void exec_app();
};

#endif