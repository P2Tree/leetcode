# LeetCode

| #    | Title                                              | Title CN           | Difficulty | Tag           | Mark |
| ---- | -------------------------------------------------- | ------------------ | ---------- | ------------- | ---- |
| 1    | two sum                                            | 两数之和           | Easy       | Hash          |      |
| 9    | palindrome number                                  |                    | Easy       |               | Star |
| 20   | valid parentheses                                  | 有效的括号         | Easy       | Stack         |      |
| 21   | merge two sorted lists                             |                    | Easy       | List          |      |
| 26   | remove duplicates from sorted array                |                    | Easy       | 2-Pointer     |      |
| 27   | emove element                                      | 移除元素           | Easy       | 2-Pointer     |      |
| 28   | find the index of the first occurrence in a string |                    | Easy       | Algorithm:KMP | Star |
| 59   | spiral matrix 2                                    | 螺旋矩阵 2         | Middle     | Simulation    |      |
| 77   | combinations                                       | 数字组合           | Middle     | Backtrace     | Star |
| 86   | partition list                                     |                    | Middle     | List          |      |
| 94   | binary tree inorder traversal                      |                    | Easy       | BinaryTree    | Star |
| 102  | binary tree level order traversal                  | 二叉树层序遍历     | Middle     | BinaryTree    | Star |
| 104  | maximum depth of binary tree                       | 二叉树深度         | Easy       | BinaryTree    |      |
| 107  | binary tree level order traversal 2                |                    | Middle     | BinaryTree    |      |
| 144  | binary tree preorder traversal                     |                    | Easy       | BinaryTree    | Star |
| 145  | binary tree postorder traversal                    |                    | Easy       | BinaryTree    | Star |
| 151  | reverse words in a string                          | 翻转字符串里的单词 | Middle     | String        | Star |
| 155  | min stack                                          |                    | Easy       | Stack         |      |
| 199  | binary tree right side view                        |                    | Middle     | BinaryTree    | Star |
| 206  | reverse linked list                                | 翻转链表           | Easy       | List          | Star |
| 209  | minimum size subarray sum                          | 长度最小子数组     | Middle     | 2-Pointer     | Star |
| 216  | combination sum 3                                  | 组合求和           | Middle     | Backtrace     |      |
| 226  | invert binary tree                                 | 翻转二叉树         | Easy       | BinaryTree    |      |
| 232  | implement queue using stacks                       | 用栈实现队列       | Easy       | Stack         | Star |
| 237  | delete node in a linked list                       |                    | Middle     | List          | Star |
| 242  | valid anagram                                      | 字母异位词         | Easy       | Map           |      |
| 344  | reverse string                                     | 翻转字符串         | Easy       | 2-Pointer     |      |
| 349  | intersection of two arrays                         | 数组的交集         | Easy       | Hash          |      |
| 394  | decode string                                      |                    | Middle     | Stack         | Star |
| 541  | reverse string 2                                   | 翻转字符串 2       | Easy       | 2-Pointer     |      |
| 559  | maximum depth of n ary tree                        | 树的深度           | Easy       | Tree          |      |
| 589  | n ary tree preorder traversal                      |                    | Easy       | Tree          |      |
| 590  | n ary tree postorder traversal                     |                    | Easy       | Tree          |      |
| 704  | binary search                                      | 二分查找           | Easy       | Search        | Star |
| 977  | squares of a sorted array                          | 有序数组的平方     | Easy       | 2-Pointer     |      |
| 1002 | find common characters                             | 查找常用字符       | Easy       | Hash          |      |
| 3142 | check if grid satisfies conditions                 |                    | Easy       | Simulation    |      |

## 笔记

### 字符串

#### 28 字符串 KMP 算法是值得思考的一道题

利用先验的部分信息作为之后判断的信息，来避免重复的模式匹配。
其中比较复杂的是理解前缀子串集合避免重复匹配的原理，然后就是知道怎么构建 next 数组，以及怎么使用它实现跳过重复子串。

#### 394 decode string 是一道有意思的题

虽然这道题用 stack 很容易就做出来了，但如果深入追究，会发现这个题是一道经典的编译原理算法，是语法解析的一个问题。
所以这个题可以通过先编写出 BNF 范式，然后编写状态机来实现。

### 二叉树

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

#### 77 数字组合

一道最经典的回溯法题目。暴力写不出来，只能用回溯法。回溯法有模版可以套进去，但需要留意这个题可以考虑通过剪枝的办法加速。
类似的题目还有 216
