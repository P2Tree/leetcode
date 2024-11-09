# LeetCode

| #    | Title                                              | Title CN               | Difficulty | Tag           | Mark |
| ---- | -------------------------------------------------- | ---------------------- | ---------- | ------------- | ---- |
| 1    | two sum                                            | 两数之和               | Easy       | Hash          |      |
| 9    | palindrome number                                  |                        | Easy       |               | Star |
| 17   | letter combinations of a phone number              | 拨号字母组合           | Middle     | Backtrace     |      |
| 20   | valid parentheses                                  | 有效的括号             | Easy       | Stack         |      |
| 21   | merge two sorted lists                             |                        | Easy       | List          |      |
| 26   | remove duplicates from sorted array                |                        | Easy       | 2-Pointer     |      |
| 27   | emove element                                      | 移除元素               | Easy       | 2-Pointer     |      |
| 28   | find the index of the first occurrence in a string |                        | Easy       | Algorithm:KMP | Star |
| 42   | trapping rain water                                | 接雨水                 | Hard       | Stack         | Star |
| 53   | maximum subarray                                   | 最大和子序列           | Middle     | Greedy        | Star |
| 59   | spiral matrix 2                                    | 螺旋矩阵 2             | Middle     | Simulation    |      |
| 70   | climbing stairs                                    | 爬楼梯的方法           | Easy       | DP            | Star |
| 77   | combinations                                       | 数字组合               | Middle     | Backtrace     | Star |
| 86   | partition list                                     |                        | Middle     | List          |      |
| 94   | binary tree inorder traversal                      |                        | Easy       | BinaryTree    | Star |
| 101  | symmetric tree                                     | 对称二叉树             | Easy       | BinaryTree    |      |
| 102  | binary tree level order traversal                  | 二叉树层序遍历         | Middle     | BinaryTree    | Star |
| 104  | maximum depth of binary tree                       | 二叉树深度             | Easy       | BinaryTree    |      |
| 107  | binary tree level order traversal 2                |                        | Middle     | BinaryTree    |      |
| 111  | minimum depth of binary tree                       | 二叉树最小深度         | Easy       | BinaryTree    |      |
| 141  | linked list cycle                                  | 环形链表               | Easy       | Link          | Star |
| 142  | linked list cycle 2                                | 环形链表求入口         | Middle     | Link          |      |
| 144  | binary tree preorder traversal                     |                        | Easy       | BinaryTree    | Star |
| 145  | binary tree postorder traversal                    |                        | Easy       | BinaryTree    | Star |
| 151  | reverse words in a string                          | 翻转字符串里的单词     | Middle     | String        | Star |
| 155  | min stack                                          |                        | Easy       | Stack         |      |
| 199  | binary tree right side view                        |                        | Middle     | BinaryTree    | Star |
| 200  | number of islands                                  | 有多少个岛屿           | Middle     | Graph         | Star |
| 206  | reverse linked list                                | 翻转链表               | Easy       | List          | Star |
| 209  | minimum size subarray sum                          | 长度最小子数组         | Middle     | 2-Pointer     | Star |
| 216  | combination sum 3                                  | 组合求和               | Middle     | Backtrace     |      |
| 226  | invert binary tree                                 | 翻转二叉树             | Easy       | BinaryTree    |      |
| 232  | implement queue using stacks                       | 用栈实现队列           | Easy       | Stack         | Star |
| 237  | delete node in a linked list                       |                        | Middle     | List          | Star |
| 242  | valid anagram                                      | 字母异位词             | Easy       | Map           |      |
| 344  | reverse string                                     | 翻转字符串             | Easy       | 2-Pointer     |      |
| 349  | intersection of two arrays                         | 数组的交集             | Easy       | Hash          |      |
| 376  | wiggle subsequence                                 | 摆动子序列             | Middle     | Greedy        |      |
| 394  | decode string                                      |                        | Middle     | Stack         | Star |
| 455  | assign cookies                                     | 给孩子们分配饼干       | Easy       | Greedy        | Star |
| 496  | next greater element i                             | 下一个更大的元素       | Easy       | Stack         |      |
| 509  | fibonacci number                                   | 斐波那契数列           | Easy       | DP            |      |
| 541  | reverse string 2                                   | 翻转字符串 2           | Easy       | 2-Pointer     |      |
| 559  | maximum depth of n ary tree                        | 树的深度               | Easy       | Tree          |      |
| 589  | n ary tree preorder traversal                      |                        | Easy       | Tree          |      |
| 590  | n ary tree postorder traversal                     |                        | Easy       | Tree          |      |
| 695  | max area of island                                 | 最大面积的岛屿         | Middle     | Graph         |      |
| 704  | binary search                                      | 二分查找               | Easy       | Search        | Star |
| 739  | daily temperatures                                 | 下一个温度高的日子     | Middle     | Stack         | Star |
| 746  | min cost climbing stairs                           | 爬楼梯的成本           | Easy       | DP            |      |
| 797  | all paths from source to target                    | 有向无环图所有简单路径 | Middle     | Graph         | Star |
| 977  | squares of a sorted array                          | 有序数组的平方         | Easy       | 2-Pointer     |      |
| 1002 | find common characters                             | 查找常用字符           | Easy       | Hash          |      |
| 3142 | check if grid satisfies conditions                 |                        | Easy       | Simulation    |      |

## 笔记

### 栈

大多数用栈能解决的问题都很容易判断，而且一旦想出思路就会很容易写出代码，多刷题自然就有感觉了。

#### 739 下一个温度高的日子

这个题用暴力写法复杂度是 O(n^2)，而且面试时并不会考察暴力写法，它可以用栈做，但又不那么明显。
这种栈叫单调栈，栈中保存日期的下标，任何时刻，栈中日期对应的温度排序是单调的。
记住，凡是题目要求求解下一个更大/更小的元素位置，就用单调栈，类似的题目还有 496。

#### 42 接雨水

一道困难题，在使用单调栈的基础上，需要多考虑几个问题，最重要的是想对如何计算面积。
面积要一层一层算，比如 2 1 0 3，处理 0 时，第一次计算 1 0 3 接的雨水是 1 _ 1 = 1；
然后后一步处理 1 0 时，第二次计算 2 1 0 3 接的雨水是 2 _ 1 = 2；我认为这是最难想明白的。
这道题常在面试中被问到，第一步是和面试官解释清楚你的思路，即使是暴力解法也可以。

### 链表

#### 141 环形链表中掌握快慢指针

这道题是我毕业那会儿找工作时被考过的一道题，总之还是一个思路，先意识到不使用辅助容器，用两个指针做，其次想到快慢指针的工作原理。

### 字符串

#### 28 字符串 KMP 算法是值得思考的一道题

利用先验的部分信息作为之后判断的信息，来避免重复的模式匹配。
其中比较复杂的是理解前缀子串集合避免重复匹配的原理，然后就是知道怎么构建 next 数组，以及怎么使用它实现跳过重复子串。

#### 394 decode string 是一道有意思的题

虽然这道题用 stack 很容易就做出来了，但如果深入追究，会发现这个题是一道经典的编译原理算法，是语法解析的一个问题。
所以这个题可以通过先编写出 BNF 范式，然后编写状态机来实现。

### 二叉树

递归三部曲：

1. 明确递归函数的参数和返回值。递归参数是在递归函数中需要用到的参数，递归计算结束后，要知道通过什么地方返回计算结果，通常是一个指针或引用参数。
2. 明确递归函数的终止条件。知道什么情况下，递归函数没必要继续下去了，选择提前返回。如果运行时栈溢出了，那么就可能是递归函数的终止条件不对。
3. 明确递归函数的主体逻辑。递归函数的主体逻辑中，需要重复调用自己，所以需要设计好内部调用自己时的参数和返回值。

#### 94,144,145 二叉树遍历这三道题的迭代解法

递归解法很简单，如果被考察，一定会考察迭代解法。
前中后序遍历的做法都不太一样，共同点是都使用 stack 来实现，类似用 stack 数据结构实现递归中的栈。
前序遍历最简单，root 压入栈，死循环直到栈空，内部读栈顶值，然后把右子节点压入栈，再把左子节点压入栈。
中序遍历比较难懂，需要一个辅助指针，初始化为 root，死循环直到栈空或者指针为空，内部先抓住指针，只看左子节点，依次入栈直到到底；然后出来读栈顶值，如果栈顶右子节点不为空，辅助指针指向右子节点，重复这个过程。
后序遍历不用特别的技巧，先写出前序遍历，子节点压栈时，先入左子节点，再入右子节点，最后读出遍历顺序后，整体反序。

#### 199 二叉树的右视图

这道题掌握技巧之后其实不难，但这道题是常考题。本质上还是二叉树的层序遍历。

#### 226 翻转二叉树

也就是每层的节点，左右交换一下。这道题唯一需要想到的就是翻转整个二叉树就是翻转其中每一个节点的两个子节点。
然后它就变成了一道二叉树遍历的题。

### 回溯法

回溯法解决用暴力破解很难或无法写出的题目。回溯法本身也是暴力枚举，但它把一层循环替换为递归查找。
回溯法是一种深度优先搜索算法，是用递归函数实现的，同样需要满足编写递归函数的几个步骤。回溯法中，每次递归内部会有一个循环，遍历当前次所有需要处理的情况，在每一次遍历中递归调用自己。
除此之外，回溯法需要在递归调用自身后，恢复调用状态，也就是“回溯”的由来。

二叉树深度遍历的递归写法，是一种特殊的回溯写法，可以看作是回溯中循环体只有两个元素的回溯法。

#### 77 数字组合

一道最经典的回溯法题目。暴力写不出来，只能用回溯法。回溯法有模版可以套进去，但需要留意这个题可以考虑通过剪枝的办法加速。
类似的题目还有 216

### 贪心法

贪心法没有固定的解题套路，但有统一的思维，就是全局最优解的达成是每一部局部最优解的累积。
有一些题，局部最优并不能达成全局最优，那就不能用贪心法，只能用动态规划。
贪心法的关键是想清楚局部最优是什么（当前这一步，最好的策略是什么）。

#### 455 给孩子们分饼干

一道贪心法的简单题。想清楚局部最优是把最大的饼干给胃口最大的孩子，或者把最小的饼干给胃口最小的孩子，这样都在局部时不会造成浪费。

#### 53 最大和子序列

局部最优是确保当前累积的值对后续的累积不产生副作用。我们的目标是让累积和尽可能大，所以如果当前累积和成为负数，那他对未来的累积就产生了副作用。

### 动态规划

动态规划简单来说，就是结果依赖于之前状态的推导。我之前研究过路径规划算法，就是动态规划问题，当前往哪里走，取决于之前的先验知识。
做动态规划的题，需要套入 5 步：

1. 确定动态规划数组的物理意义（即某个下标处的值/状态是什么意义）
2. 动态规划状态递推公式
3. 由第 2 步，再决定需要做初始化的状态有哪些
4. 决定好遍历的方向
5. 举例子来验证是否可行
   做题时，也可以把动态规划数组打出来，和自己举例子的结果对比，看哪里存在问题。

#### 70 爬楼梯的方法

这道题比较简单，是动态规划的入门题，曾经被面试考到过。他递推公式就是斐波那契数列，但需要掌握方法。
类似的题还有 746

### 图

#### 797 有向无环图所有简单路径

图的遍历通常都是面试中的常考题，所以需要掌握。思路比较简单，就是递归算法，但要注意图的存储结构。
另一个类似的题目是 200
