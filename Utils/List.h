#pragma once

#include <iostream>
#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int val) : val(val), next(nullptr) {}
  ListNode(int val, ListNode *next) : val(val), next(next) {}
};

static void print(ListNode *head) {
  auto *p = head;
  while (p != nullptr) {
    std::cout << p->val << " ";
    p = p->next;
  }
  std::cout << std::endl;
}

class List {
public:
  List(std::vector<int> input) : head(nullptr) {
    if (input.size() == 0)
      return;
    head = new ListNode(input[0]);
    if (input.size() == 1)
      return;
    ListNode *p = head;
    for (auto i = 1; i < input.size(); ++i) {
      ListNode *node = new ListNode(input[i]);
      p->next = node;
      p = node;
    }
  }

  friend std::ostream &operator<<(std::ostream &os, const List &list) {
    ListNode *p = list.head;
    while (p != nullptr) {
      os << p->val << " ";
      p = p->next;
    }
    return os;
  }

  ListNode *getHeadNode() const { return head; }

private:
  ListNode *head;
};
