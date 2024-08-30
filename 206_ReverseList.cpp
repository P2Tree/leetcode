#include "Utils/List.h"
#include <vector>

using namespace std;

class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    if (head == nullptr || head->next == nullptr)
      return head;
    if (head->next->next == nullptr) {
      ListNode *p = head->next;
      head->next->next = head;
      head->next = nullptr;
      return p;
    }

    ListNode *r = head;
    ListNode *p = head->next;
    ListNode *q = head->next->next;

    r->next = nullptr;
    while (q != nullptr) {
      p->next = r;
      r = p;
      p = q;
      q = q->next;
    }
    p->next = r;

    return p;
  }
};

// a -> b -> c -> null
// r    p    q
// a <-> b   c -> null
// r     p   q
//       r   p    q
// a <-> b <- c   null

void test1() {
  List l = List{vector<int>{1, 2, 3}};
  cout << "before: " << l << endl;
  Solution so;
  auto *ret = so.reverseList(l.getHeadNode());
  cout << "after: ";
  print(ret);
}

void test2() {
  List l = List{vector<int>{1, 2}};
  cout << "before: " << l << endl;
  Solution so;
  auto *ret = so.reverseList(l.getHeadNode());
  cout << "after: ";
  print(ret);
}

void test3() {
  List l = List{vector<int>{1}};
  cout << "before: " << l << endl;
  Solution so;
  auto *ret = so.reverseList(l.getHeadNode());
  cout << "after: ";
  print(ret);
}
void test4() {
  List l = List{vector<int>{}};
  cout << "before: " << l << endl;
  Solution so;
  auto *ret = so.reverseList(l.getHeadNode());
  cout << "after: ";
  print(ret);
}
int main() {
  test1();
  test2();
  test3();
  test4();
}
