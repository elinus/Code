#ifndef __MY_SORTER_H__
#define __MY_SORTER_H__

#include "Sorter.h"

class MySorter : public Sorter {
    public:
        MySorter();
        virtual ~MySorter();
        // Inherited via Sorter
        virtual void doSort(int listToSort[]) override;
};

#endif // !__MY_SORTER_H__
