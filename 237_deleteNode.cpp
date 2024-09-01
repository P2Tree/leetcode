#include "Utils/List.h"

using namespace std;

class Solution {
public:
  void deleteNode(ListNode *node) {
    ListNode *next = node->next;
    node->val = next->val;
    node->next = next->next;
  }
};

void test1() {
  Solution so;
  List l1{4, 5, 3, 1};
  ListNode *n = l1.getNode(2); // get node 3
  so.deleteNode(n);
  cout << l1 << endl;
}

int main() { test1(); }
