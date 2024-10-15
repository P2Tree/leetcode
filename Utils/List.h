#pragma once

#include <iostream>
#include <set>
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
  List(std::vector<int> &values) : head(nullptr) {
    if (values.size() == 0)
      return;
    head = new ListNode(values[0]);
    if (values.size() == 1)
      return;
    ListNode *p = head;
    for (auto i = 1; i < values.size(); ++i) {
      ListNode *node = new ListNode(values[i]);
      p->next = node;
      p = node;
    }
  }

  List(const std::initializer_list<int> &values) : head(nullptr) {
    if (values.size() == 0)
      return;
    head = new ListNode();
    ListNode *p = head;
    for (auto i : values) {
      ListNode *node = new ListNode(i);
      p->next = node;
      p = node;
    }
    p = head;
    head = head->next;
    delete p;
  }

  List(ListNode *h) : head(nullptr) {
    if (h == nullptr)
      return;
    head = new ListNode();
    ListNode *p = head;
    while (h != nullptr) {
      p->next = new ListNode(h->val);
      p = p->next;
      h = h->next;
    }
    p = head;
    head = head->next;
    delete p;
  }

  ~List() {
    ListNode *p;
    while (head != nullptr) {
      p = head;
      head = head->next;
      delete p;
    }
  }

  friend std::ostream &operator<<(std::ostream &os, const List &list) {
    ListNode *p = list.head;
    std::set<ListNode *> saveNode;
    while (p != nullptr) {
      saveNode.insert(p);
      os << p->val << " -> ";
      p = p->next;
      if (std::find(saveNode.begin(), saveNode.end(), p) != saveNode.end()) {
        os << "(" << p->val << ")";
        break;
      }
    }
    if (p == nullptr) {
      os << "(null)";
    }
    return os;
  }

  ListNode *getHeadNode() const { return head; }
  ListNode *getNode(int index) const {
    int i = 0;
    ListNode *p = head;
    while (p != nullptr) {
      if (i == index)
        return p;
      i++;
      p = p->next;
    }
    return nullptr;
  }

  operator ListNode *() const { return head; }

private:
  ListNode *head;
};
