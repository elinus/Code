#ifndef __QUICK_SORT_H__
#define __QUICK_SORT_H__

#include "SortInterface.h"
#include <iostream>

class QuickSort : public SortInterface {
public:
    QuickSort();
    virtual ~QuickSort();
	// Inherited via SortInterface
	virtual void sort(int array[]) override;

};

#endif // !__QUICK_SORT_H__
