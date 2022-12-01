#include "list_node.h"
#include "test_framework/generic_test.h"

shared_ptr<ListNode<int>> ReverseSublist(shared_ptr<ListNode<int>> L, int start,
                                         int finish)
{
  if (start == finish)
    return L;
  shared_ptr<ListNode<int>> tmp = make_shared<ListNode<int>>(ListNode<int>{0, L});
  auto dump = tmp;
  while (--start)
  {
    tmp = tmp->next;
    --finish;
  }
  auto inter = tmp->next;
  while (--finish)
  {
    auto var = inter->next;
    inter->next = var->next;
    var->next = tmp->next;
    tmp->next = var;
  }

  return dump->next;
}

int main(int argc, char *argv[])
{
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"L", "start", "finish"};
  return GenericTestMain(args, "reverse_sublist.cc", "reverse_sublist.tsv",
                         &ReverseSublist, DefaultComparator{}, param_names);
}
