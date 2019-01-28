#ifndef __SORT_INTERFACE_H__
#define __SORT_INTERFACE_H__

class SortInterface {
public:
    virtual ~SortInterface() 
    {}
	virtual void sort(int array[]) = 0;
};

#endif // !__SORT_INTERFACE_H__
