#include <iostream>
#include <vector>

#include "Utils/List.h"

using namespace std;

class Solution {
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    if (list1 == nullptr && list2 == nullptr)
      return nullptr;
    if (list1 == nullptr)
      return list2;
    if (list2 == nullptr)
      return list1;
    auto *p1 = list1;
    auto *p2 = list2;
    ListNode *p, *head;
    if (p1->val < p2->val) {
      head = new ListNode{p1->val};
      p1 = p1->next;
    } else {
      head = new ListNode{p2->val};
      p2 = p2->next;
    }
    p = head;
    while (!(p1 == nullptr && p2 == nullptr)) {
      if (p1 == nullptr) {
        auto *node = new ListNode{p2->val};
        p->next = node;
        p = node;
        p2 = p2->next;
        continue;
      }
      if (p2 == nullptr) {
        auto *node = new ListNode{p1->val};
        p->next = node;
        p = node;
        p1 = p1->next;
        continue;
      }

      if (p1->val < p2->val) {
        auto *node = new ListNode{p1->val};
        p->next = node;
        p = node;
        p1 = p1->next;
      } else {
        auto *node = new ListNode{p2->val};
        p->next = node;
        p = node;
        p2 = p2->next;
      }
    }
    return head;
  }
};

void test1() {
  vector<int> list1 = {1, 2, 4};
  List l1{list1};
  cout << "left list: " << l1 << endl;

  vector<int> list2 = {1, 3, 5};
  List l2{list2};
  cout << "right list: " << l2 << endl;

  Solution so;
  auto ret = so.mergeTwoLists(l1.getHeadNode(), l2.getHeadNode());
  print(ret);
}

void test2() {
  vector<int> list1 = {};
  List l1{list1};
  cout << "left list: " << l1 << endl;

  vector<int> list2 = {};
  List l2{list2};
  cout << "right list: " << l2 << endl;

  Solution so;
  auto ret = so.mergeTwoLists(l1.getHeadNode(), l2.getHeadNode());
  print(ret);
}

void test3() {
  vector<int> list1 = {3};
  List l1{list1};
  cout << "left list: " << l1 << endl;

  vector<int> list2 = {2};
  List l2{list2};
  cout << "right list: " << l2 << endl;

  Solution so;
  auto ret = so.mergeTwoLists(l1.getHeadNode(), l2.getHeadNode());
  print(ret);
}

int main() {
  test1();
  test2();
  test3();
}
