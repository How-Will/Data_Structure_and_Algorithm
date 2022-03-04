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

## [exercise 1.6](exe1_6.cpp)

> Use your favorite object-oriented programming language to create a class that represents an array-based set. It should include functions/methods that serve as the key operations: Read, search, insert, and delete. Ensure that the insert operation will not insert duplicate values.

# Chapter 2

## exercise 2.1

> There’s an age old puzzle that goes as follows: You’re at a river with two buckets. One holds exactly 3 liters, and one holds exactly 5 liters. Figure out how to measure out exactly 4 liters using those two buckets.
> 
> 1. Develop two different algorithms for measuring out 4 liters.
> 2. Which of your algorithms is more efficient? That is, how many steps does each algorithm take?

算法1：

1. 5L桶装满水。

2. 由5L桶向3L桶倒水，倒满为止。**5L桶中余下2L水。**

3. 把3L桶的水倒掉，由5L桶向3L桶倒水。**3L桶中现有2L水，5L桶中没有水。**

4. 5L桶装满水。

5. 由5L桶向3L桶倒水，倒满为止。**5L桶中现有4L水。**

算法2：

1. 将3升的桶装满，倒到5升里面，重复执行两次，此时**3升桶里面剩余1升。**

2. 将5升的桶中的谁倒掉，将第一步中的1升水倒入5升桶中。

3. 将3升的桶装满，向5升的桶中倒，则**5升桶中有4升水了。**

## exercise 2.2

> How many steps would it take to insert the number 7 into the ordered array of [2, 4, 6, 8, 10, 12]?

1. 搜索插入位置：4步

2. 元素后移：3步

3. 插入元素：1步

4. 总共需要 4 + 3 + 1 = 8步

## exercise 2.3

> How many steps would it take to search for the number 8 in the ordered array: [2, 4, 6, 8, 10, 12]?

使用二分查找算法需要2步。使用顺序查找需要4步。

## exercise 2.4

> How many steps does it take to perform binary search on array of size 200?

至多需要8步。

## exercise 2.5

> How many steps does it take to perform binary search on array of size 400?

至多需要9步。

## [exercise 2.6](exe2_6.cpp)

> Use your favorite object-oriented programming language to create a class that represents an ordered array. It should include functions/methods that serve as the key operations: Read, search, insert, and delete. Ensure that the insert operation inserts the value in the correct place within the ordered array.

# Chapter 3

## exercise 3.1

> Inspect the following algorithm, and describe its time complexity in terms of Big O Notation:
> 
> ```python
> x = 1
> while x < 100
>   print x
>   x += 1
> end
> ```

该算法总共会执行99步。用大O记法表示为 `O(N)`

## exercise 3.2

> In the below graph, six algorithms are depicted. The x axis represents the number of data elements, and the y axis represents how many steps the algorithm takes. By color, list the algorithms from fastest to slowest.
> 
> ![](https://commonsensecomputerscience.com/old-site/img/exercises/chapter_3_graph.png)

青色 > 紫色 > 橘色 > 绿色 > 红色 > 蓝色

## exercise 3.3

> How would you describe the following algorithm in terms of Big O Notation: Looking up someone in a phone book by starting with the first name in the book and reading each subsequent name until you find the name you’re looking for.

顺序查找的时间复杂度为 `O(N)`

## exercise 3.4

> How would you describe the following algorithm in terms of Big O Notation: Looking up someone in a phone book by starting with the middle of the book - and, when seeing that the name is higher or lower, jumping to the next halfway point, and so on until you find the correct name.

二分查找的时间复杂度为 `O(logN)`

## exercise 3.5

> How would you describe the following algorithm in terms of Big O Notation: You’d like to use one laptop to clone its operating system to 15 other laptops, so you take the original laptop, and one by one, you use it to clone each other laptop.

时间复杂度为 `O(N)`

## exercise 3.6

> How would you describe the following algorithm in terms of Big O Notation: You’d like to use one laptop to clone its operating system to 15 other laptops, so you take the first laptop and clone a second laptop. You then take the 2 completed laptops and clone 2 other laptops. You then take the 4 completed laptops to clone 4 other laptops. Finally, you take the 8 completed laptops and use them to clone 8 other laptops, so you end up with 16 completed laptops.

时间复杂度为 `O(logN)`
