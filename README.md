# data-structure-and-algorithm
- basic data structure &amp; algorithm implementation in C/CPP
- it is recommanded to read and test this repository in Visual Studio 2019
## data structure
### ArrayList (primary)
### LinkedList (primary)
### Stack
- linked stack(c)
- array stack(c)
- circular stack(c)
### Queue
- linked queue(c)
- array stack(c)
### Tree
- Binary Tree(c)
- Binary Search Tree(c)
- AVL Binary Search Tree(c)
- Array Binary Heap(c)
### Hash Table
- linked hash table(c)
- array hash table(c)
### Graph
- directed weight graph(c)
## basic algorithm
### sort
- select(c)
- insertion(c)
- bubble(c)
- quick sort(c)
- merge(c)
- bucket sort(c)
- radix sort(c)
### search
- binary(c++)
- trinary(c++)
### shortest path
- dijkstra(c++)
## more algorithm
### Greedy
- huffman code(java)
### Divide and Conquer
- merge sort(c++)
- subset sum problem(c++)
### Dynamic Programing
- 硬币找零 Make Change(java)
- 最长公共子序列 Longest common subsequent(java)
# 中文日志
- 2019-09-08	使用array list实现了Dijkstra
- 2019-09-09	根据教授提供的思路将时间复杂度优化，完成了sample数据的测试
- 2019-09-20    使用java和c++完成了飞机航线规划算法，都需要改善
- 2019-11-05    使用java完成huffman code和make change算法
- 2019-11-06    使用java完成Longest common subsequent算法
- 2019-12-25	重构数据结构c语言代码，删除java和c++算法代码，将来全部使用c++重写，并入同一个项目中
- 2020-07-07    使用strategy design重构了排序的c++代码
- 2020-07-10	添加findMedianSortedArrays算法(c++)
- 2020-07-17	添加longestPalindrome算法(c++). 发现data-structure方案里bug: char指针转型成int时溢出, 需要重写linked node。