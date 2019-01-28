#include "MySorter.h"
#include "BubbleSort.h"
#include "QuickSort.h"

int main() {
	int listToBeSorted[] = {18, 26, 26, 12, 127, 47, 62, 82, 3, 236, 84, 5};

	MySorter *mysorter = new MySorter();
	mysorter->setSorter(new BubbleSort());
	mysorter->doSort(listToBeSorted);
	mysorter->setSorter(new QuickSort());
	mysorter->doSort(listToBeSorted);
	delete mysorter;

	return 0;
}
