#include "Sorter.h"

Sorter::Sorter()
{
	strategy = nullptr;
}

Sorter::~Sorter()
{
}

void Sorter::setSorter(SortInterface * strategy)
{
	this->strategy = strategy;
}

SortInterface* Sorter::getSorter()
{
	return this->strategy;
}
