#include "Utils/List.h"
#include <iostream>
#include <set>
using namespace std;
class Solution {
public:
  bool hasCycle1(ListNode *head) {
    if (head == nullptr || head->next == nullptr)
      return false;

    ListNode *p = head;
    set<ListNode *> save;

    while (p != nullptr) {
      save.insert(p);
      p = p->next;
      if (find(save.begin(), save.end(), p) != save.end()) {
        return true;
      }
    }
    return false;
  }
  bool hasCycle(ListNode *head) {
    if (head == nullptr || head->next == nullptr)
      return false;

    ListNode *slow = head;
    ListNode *fast = head->next;

    while (slow != nullptr && fast != nullptr) {
      if (slow == fast)
        return true;
      slow = slow->next;
      if (fast->next != nullptr)
        fast = fast->next->next;
      else
        fast = nullptr;
    }
    return false;
  }
};

void test() {
  Solution so;
  List list({3, 2, 0, -4});
  auto *tail_node = list.getNode(3);
  auto *start_node = list.getNode(1);
  tail_node->next = start_node;
  cout << list << endl;
  auto res = so.hasCycle(list);
  if (res)
    cout << "has cycle" << endl;
  else
    cout << "don't has cycle" << endl;
}

int main() {
  test();

  return 0;
}
