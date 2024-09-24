# LeetCode

| #    | Title                                              | Difficulty | Solution      | Mark |
| ---- | -------------------------------------------------- | ---------- | ------------- | ---- |
| 1    | two sum                                            | Easy       | Hash          |      |
| 9    | palindrome number                                  | Easy       |               | Star |
| 20   | valid parentheses                                  | Easy       | Stack         |      |
| 21   | merge two sorted lists                             | Easy       | List          |      |
| 26   | remove duplicates from sorted array                | Easy       | 2-Pointer     |      |
| 27   | emove element                                      | Easy       | 2-Pointer     |      |
| 28   | find the index of the first occurrence in a string | Easy       | Algorithm:KMP | Star |
| 59   | spiral matrix 2                                    | Middle     | Simulation    |      |
| 86   | partition list                                     | Middle     | List          |      |
| 94   | binary tree inorder traversal                      | Easy       | BinaryTree    | Star |
| 102  | binary tree level order traversal                  | Middle     | BinaryTree    | Star |
| 144  | binary tree preorder traversal                     | Easy       | BinaryTree    | Star |
| 145  | binary tree postorder traversal                    | Easy       | BinaryTree    | Star |
| 151  | reverse words in a string                          | Middle     | String        | Star |
| 155  | min stack                                          | Easy       | Stack         |      |
| 206  | reverse linked list                                | Easy       | List          | Star |
| 209  | minimum size subarray sum                          | Middle     | 2-Pointer     | Star |
| 232  | implement queue using stacks                       | Easy       | Stack         | Star |
| 237  | delete node in a linked list                       | Middle     | List          | Star |
| 242  | valid anagram                                      | Easy       | Map           |      |
| 344  | reverse string                                     | Easy       | 2-Pointer     |      |
| 349  | intersection of two arrays                         | Easy       | Hash          |      |
| 394  | decode string                                      | Middle     | Stack         | Star |
| 541  | reverse string ii                                  | Easy       | 2-Pointer     |      |
| 704  | binary search                                      | Easy       | Search        | Star |
| 977  | squares of a sorted array                          | Easy       | 2-Pointer     |      |
| 1002 | find common characters                             | Easy       | Hash          |      |
| 3142 | check if grid satisfies conditions                 | Easy       | Simulation    |      |

## 笔记

- 28 字符串 KMP 算法是值得思考的一道题
  利用先验的部分信息作为之后判断的信息，来避免重复的模式匹配。
  其中比较复杂的是理解前缀子串集合避免重复匹配的原理，然后就是知道怎么构建 next 数组，以及怎么使用它实现跳过重复子串。

- 94,144,145 二叉树遍历这三道题的迭代解法
  递归解法很简单，如果被考察，一定会考察迭代解法。
  前中后序遍历的做法都不太一样，共同点是都使用 stack 来实现，类似用 stack 数据结构实现递归中的栈。
  前序遍历最简单，root 压入栈，死循环直到栈空，内部读栈顶值，然后把右子节点压入栈，再把左子节点压入栈。
  中序遍历比较难懂，需要一个辅助指针，初始化为 root，死循环直到栈空或者指针为空，内部先抓住指针，只看左子节点，依次入栈直到到底；然后出来读栈顶值，如果栈顶右子节点不为空，辅助指针指向右子节点，重复这个过程。
  后序遍历不用特别的技巧，先写出前序遍历，子节点压栈时，先入左子节点，再入右子节点，最后读出遍历顺序后，整体反序。

- 394 decode string 是一道有意思的题
  虽然这道题用 stack 很容易就做出来了，但如果深入追究，会发现这个题是一道经典的编译原理算法，是语法解析的一个问题。
  所以这个题可以通过先编写出 BNF 范式，然后编写状态机来实现。
