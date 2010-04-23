	/*平均时间复杂度由高到低为：
	插入排序 O(n2)
	冒泡排序 O(n2)
	选择排序 O(n2)
	快速排序 O(n log n)
	堆排序 O(n log n)
	归并排序 O(n log n)
	希尔排序 O(n1.25)
	基数排序 O(n)
	[编辑]实际测试结果

	OS: winxp, Compiler: vc8, CPU：Intel T7200,  Memory: 2G
	不同数组长度下调用6种排序1000次所需时间(秒）

	length		shell		quick		merge		insert		select		bubble
	100		0.0141		0.359		1.875		0.204		0.313		0.421
	1000		0.218		0.578		2.204		1.672		2.265		4
	5000		1.484		3.25		14.14		41.392		63.656		101.703
	10000		3.1		7.8		23.5		253.1		165.6		415.7
	50000		21.8		40.6		121.9		411.88		6353.1		11648.5
	100000		53.1		89		228.1		16465.7		25381.2		44250


	结论：
	数组长度不大的情况下不宜使用归并排序，其它排序差别不大。
	数组长度很大的情况下Shell最快，Quick其次，冒泡最慢。*/
#ifndef H_SORT
#define H_SORT

#ifdef __cplusplus
extern "C" {
#endif

#include "ORC.h"
   int ORCbubblesort(int *a, int len);
   int ORCselectsort(int *a, int len);
   int ORCshellsort (int *a, int len);

#ifdef __cplusplus
}
#endif

#endif
