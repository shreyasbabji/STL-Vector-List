/*
 * SortedVector.cpp
 *
 *  Created on: Oct 25, 2017
 *      Author: Shreyas
 */

#include <iostream>
#include <iterator>
#include "SortedVector.h"

using namespace std;

SortedVector::SortedVector()
{
	Node::reset();
}

SortedVector::~SortedVector()
{
	Node::reset();
}

int SortedVector::size() const
{
	return data.size();
}

bool SortedVector::check() const
{
    if (data.size() == 0) return true;

    vector<Node>::const_iterator it = data.begin();
    vector<Node>::const_iterator prev = it;

    it++;

    // Ensure that each node is greater than the previous node.
    while ((it != data.end()) && (*it > *prev))
    {
        prev = it;
        it++;
    }

    return it == data.end();  // Good if reached the end.
}


void SortedVector::prepend(const long value)
{
	data.insert(data.begin(), Node(value));
}

void SortedVector::append(const long value)
{
	/***** Complete this function. *****/
	data.push_back(Node(value));
}

void SortedVector::remove(const int index)
{
	/***** Complete this function. *****/
	data.erase(data.begin()+index);
}

void SortedVector::insert(const long value)
{
	vector<Node>::const_iterator it ;
	for(it = data.begin() ; it!=data.end(); ++it){
		if( it->get_value() > value){
//			data.insert(it, Node(value));
			break;
		}
	}
	data.insert(it, Node(value));
}

Node SortedVector::at(const int index)
{
	return data[index];
}
