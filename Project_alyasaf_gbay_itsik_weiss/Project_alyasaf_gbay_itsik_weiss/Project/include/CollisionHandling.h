#pragma once

#include "Object.h"

#include <iostream>
#include <typeinfo>

// Sample struct for exception throwing
struct UnknownCollision
{
	UnknownCollision(Object& a, Object& b) : first(a), second(b)
	{
		std::cout << "Unknown collision of " << typeid(a).name() << " and "
			<< typeid(b).name() << std::endl;
	}
	Object& first;
	Object& second;
};

void processCollision(Object& object1, Object& object2);

