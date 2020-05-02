#ifndef __SORTER_H__
#define __SORTER_H__

#include "SortInterface.h"

class Sorter {
public:
  Sorter();
  virtual ~Sorter();
  void setSorter(SortInterface *strategy);
  SortInterface *getSorter();
  virtual void doSort(int listToSort[]) = 0;

private:
  SortInterface *strategy;
};

#endif // !__SORTER_H__
