#include "Utils/List.h"
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    unordered_map<ListNode *, int> m;
    if (head == nullptr || head->next == nullptr)
      return nullptr;

    ListNode *p = head;

    while (p != nullptr) {
      if (m.find(p) != m.end()) {
        break;
      }
      m.insert(make_pair(p, p->val));
      p = p->next;
    }
    if (p == nullptr) {
      return nullptr;
    }
    return p;
  }
};

void test() {
  Solution so;
  List list{3, 2, 0, -4};
  auto *tail = list.getNode(3);
  auto *node = list.getNode(1);
  tail->next = node;
  cout << list << endl;
  auto *res = so.detectCycle(list);
  if (res == nullptr)
    cout << "not loop" << endl;
  else
    cout << res->val << endl;
}

int main() {
  test();
  return 0;
}
