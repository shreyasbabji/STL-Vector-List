/*
 * Node.cpp
 *
 *  Created on: Oct 25, 2017
 *      Author: Shreyas
 */

#include <iostream>
#include "Node.h"

using namespace std;

long Node::constructor_count;
long Node::copy_count;
long Node::destructor_count;


/***** Complete this file. *****/
Node::Node(const long the_value) : value(the_value)
{
	constructor_count = constructor_count+1;
}

Node::Node(const Node& other)
{
	value = other.value;
	copy_count = copy_count+1 ;
}

Node::~Node()
{
	destructor_count = destructor_count+1;
}

long Node::get_value() const
{
	return value;
}


long Node::get_constructor_count()
{
	return constructor_count;
}


long Node::get_copy_count()
{
	return copy_count;
}


long Node::get_destructor_count()
{
	return destructor_count;
}


void Node::reset()
{
	constructor_count = 0;
	copy_count = 0;
	destructor_count = 0;
}


bool Node::operator ==(const Node& other) const {
	if(value == other.value)
		return true;
	else
		return false;
}

bool Node::operator >(const Node& other) const
{
	if(value > other.value)
		return true;
	else
		return false;
}
