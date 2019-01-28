#include "Sorter.h"

Sorter::Sorter()
{
	strategy = nullptr;
}

Sorter::~Sorter()
{
    if (strategy != nullptr) {
        delete strategy;
    }
}

void Sorter::setSorter(SortInterface * strategy)
{
    if (this->strategy != nullptr) {
        delete this->strategy;
    }
	this->strategy = strategy;
}

SortInterface* Sorter::getSorter()
{
	return this->strategy;
}
