

#include <string>
#include "SortedVector.h"
#include "SortedList.h"
#include <cstdlib>
#include "Node.h"

using namespace std;

// How many times to do gets.
const int GETS_COUNT = 10000;

void vector_prepends(SortedVector& sv, const int size)
{
	/***** Complete this function. *****/
	int i = size-1;
		while(i >= 0)
		{
			sv.prepend(i);
			i--;
		}
}

void list_prepends(SortedList& sl, const int size)
{
	/***** Complete this function. *****/
	int i = size-1;
	while(i >= 0)
	{
		sl.prepend(i);
		i--;
	}
}

void vector_appends(SortedVector& sv, const int size)
{
	/***** Complete this function. *****/
	int i = 0;
	while (i < size )
	{
		sv.append(i);
		i++;
	}
}

void list_appends(SortedList& sl, const int size)
{
	/***** Complete this function. *****/
	int i = 0;
	while( i < size)
	{
		sl.append(i);
		i++;
	}
}

void vector_gets(SortedVector& sv, const int size) throw (string)
																		{
	// First fill the vector data.
	vector_appends(sv, size);
	Node::reset();

	// Loop to access nodes at random positions.
	for (int i = 0; i < GETS_COUNT; i++)
	{
		int index =  rand() % size;
		long value = sv.at(index).get_value();
		//Node::reset();//*****CHANGE MADE HERE*****

		/***** Complete this function. *****/

		// Make sure we got the correct node.
		if (index != value)
		{
			throw string("Vector data mismatch!");
		}
	}
																		}

void list_gets(SortedList& sl, const int size) throw (string){

	list_appends(sl, size);
	Node::reset();

	for (int i = 0; i < GETS_COUNT; i++)
	{
		int index = rand() % sl.size();
		long value = sl.at(index).get_value();
		//Node::reset();//*****CHANGE MADE HERE*****

		/***** Complete this function. *****/

		// Make sure we got the correct node.
		if (index != value)
		{
			throw string("List data mismatch!");
		}
	}
}

void vector_removes(SortedVector& sv, const int size)
{
	vector_appends(sv, size);
	Node::reset();
	while (sv.size() > 0)
	{
		int index = rand()%sv.size();

		/***** Complete this function. *****/
		sv.remove(index);
	}
}

void list_removes(SortedList& sl, const int size)
{
	list_appends(sl, size);
	Node::reset();
	while (sl.size() > 0)
	{
		int index = rand()%sl.size();

		/***** Complete this function. *****/

		sl.remove(index);
	}
}

void vector_inserts(SortedVector& sv, const int size)
{
	for(int i = 0 ; i < size ; i ++){
		if(sv.size() < size){
			sv.insert(rand());
		}
	}
}

void list_inserts(SortedList& sl, const int size)
{
	/***** Complete this function. *****/
	for(int i = 0 ; i < size ; i ++){
		if(sl.size() < size){
			sl.insert(rand());
		}
	}
}

