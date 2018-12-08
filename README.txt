# DS
data structure&amp;sorting implementation in C
1.Dynamic Array(ArrayList)
2.LinkedList
添，删，查

以上两种是最所有结构的根基

3.Stack
pop(),push()
4.Queue
enqueue(),dequeue()


5.Tree->BinaryTree->BinarySearchTree->AVLBinarySearchTree
Travese 前中后+横向(queue)

rebalance
先通过balance factor来判断是否平衡(左孩子高度-右孩子高度)
四种情况选择四种不同的rotation
  /   /   \   \
 /    \   /    \


6.graph
有向图/无向图
vertices/edges

实现方法一：adjacency matrix
实现方法二：vertices结构体里用next/linked数组来储存接下来指向的所有vertices

BFT和DFT和树的有两个区别
1 需要选择起始位置
2 使用一个数组记录每个vertice是否被访问过的状态

weight graph
最短路径算法 这个很有趣。小朋友画图都能解决，我却没想到，蠢得很



sort算法


hash算法

