#ifndef __BUBBLE_SORT_H__
#define __BUBBLE_SORT_H__

#include "SortInterface.h"
#include <iostream>

class BubbleSort : public SortInterface {
public:
    BubbleSort();
    virtual ~BubbleSort();
	// Inherited via SortInterface
	virtual void sort(int array[]) override;

};

#endif // !__BUBBLE_SORT_H__
