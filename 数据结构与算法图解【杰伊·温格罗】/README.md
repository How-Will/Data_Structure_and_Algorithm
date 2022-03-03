# Chapter 1

## exercise 1. 1

> For an array with a size of 100 elements, provide the number of steps that the following operations would take for:
> 
> 1. Reading
> 2. Searching
> 3. Insertion at the very beginning of the array
> 4. Insertion at the very end of the array
> 5. Deletion at the very beginning of the array
> 6. Deletion at the very end of the array

1. 需要1步，**数组的读取只需要1步**。

2. 最少需要1步，即目标元素在数组的第1个位置。最多需要100步，即目标元素不存在或者在数组的最后一个位置。

3. 需要101步，前100步移动数组，将第一个数组位置腾出，最后1步将元素插入即可。

4. 需要1步，PC可以直接确定最后一个位置，然后将元素插入即可。

5. 需要100步。第1步删除元素，后99步将剩余的元素向前移动。

6. 需要1步。删除最后一个位置的元素即可。

## exercise 1.2

> For an **array-based** *set* with a size of 100 elements, provide the number of steps that the following operations would take for:
> 
> 1. Reading
> 2. Searching
> 3. Insertion at the very beginning of the set
> 4. Insertion at the very end of the set
> 5. Deletion at the very beginning of the set
> 6. Deletion at the very end of the set

1. 需要1步。同数组读取。

2. 最少需要1步，最多需要100步。同数组查找。

3. 需要201步，前100步进行查找，判断插入元素是否已经重复了。再用100步移动元素，将第一个数组位置腾出，最后1步将元素插入即可。

4. 需要101步，前100步进行查找，判断插入元素是否已经重复了。最后1步在数组末尾插入元素即可。

5. 需要100步。同数组删除第一个元素。

6. 需要1步。同数组删除最后一个元素。

## exercise 1.3

> For a regular array, how many steps would it take to search for all of a certain item. For example, we want to search for every 55 contained within an array to determine how many times it appears. Give your answer in terms of N.

分最多和最少两种情况：n，表示目标元素出现的次数

最多步数的情况（所有目标元素都集中数组尾部）：则需要 `N! / (N - n - 1)!` 步

最少步数的情况（所有目标元素都集中数组头部）：需要 `n!` 步

## exercise 1.4

> How many steps would it take to delete all the 72’s from the following array: [72, 44, 66, 2019, 72, 55, 101, 72, 99, 2]. (The array would become [44, 66, 2019, 55, 101, 99, 2].)

分最多和最少两种情况：

最多步数的情况（顺序删除）：

1. 删除第1个72：删除元素，然后前移剩余元素，需要1+9=10步

2. 删除第2个72：需要1+5=6步

3. 删除第3个72：需要1+2=3步

4. 总共需要10+6+3=19步

最少步数的情况（逆序删除）：

1. 删除第3个72：需要1+2=3步

2. 删除第2个72：需要1+4=5步

3. 删除第1个72：需要1+7=8步

4. 总共需要3+5+8=16步

## exercise 1.5

> How many steps would it take to insert a 44 at both the beginning and end of the following array: [5, 6, 7, 8, 9, 10]. (The insertions would turn the array into: [44, 5, 6, 7, 8, 9, 10, 44].)

分最多和最少两种情况：

最多步数的情况：

1. 先在最后一个位置插入：需要1步

2. 再在第一个位置插入：移动元素，腾出位置，然后插入元素，需要7+1=8步

3. 总共需要1+8=9步

最少步数的情况：

1. 现在第一个位置插入：需要6+1=7步

2. 再在最后一个位置插入：需要1步

3. 总共需要7+1=8步

## [exercise 1.6](exe1_1.cpp)

> Use your favorite object-oriented programming language to create a class that represents an array-based set. It should include functions/methods that serve as the key operations: Read, search, insert, and delete. Ensure that the insert operation will not insert duplicate values.


