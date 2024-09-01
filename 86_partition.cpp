#include "Utils/List.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  ListNode *partition(ListNode *head, int x) {
    ListNode *s = new ListNode();
    ListNode *l = new ListNode();
    ListNode *ss = s;
    ListNode *ll = l;
    ListNode *p = head;
    ListNode *t;
    while (p != nullptr) {
      if (p->val < x) {
        s->next = p;
        s = p;
      } else {
        l->next = p;
        l = p;
      }
      p = p->next;
    }

    s->next = ll->next;
    l->next = nullptr;

    // delete ss;
    // delete ll;

    return ss->next;
  }
};

// 1  4  3  2  5  2
//       p
// 2  1
//

void test1() {
  Solution so;
  List l1{1, 4, 3, 2, 5, 2};
  cout << "input: " << l1 << endl;
  List r1 = so.partition(l1.getHeadNode(), 3);
  cout << "output: " << r1 << endl;
}

void test2() {
  Solution so;
  List l1{2, 1};
  cout << "input: " << l1 << endl;
  List r1 = so.partition(l1.getHeadNode(), 2);
  cout << "output: " << r1 << endl;
}

int main() {
  test1();
  test2();
}
