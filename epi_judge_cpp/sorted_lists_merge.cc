#include "list_node.h"
#include "test_framework/generic_test.h"
shared_ptr<ListNode<int>> MergeTwoSortedLists(shared_ptr<ListNode<int>> L1,
                                              shared_ptr<ListNode<int>> L2)
{
  shared_ptr<ListNode<int>> tmp(new ListNode<int>);
  shared_ptr<ListNode<int>> dump = tmp;
  while (L1 != nullptr || L2 != nullptr)
  {
    if (L1 == nullptr)
    {
      tmp->next = L2;
      break;
    }
    if (L2 == nullptr)
    {
      tmp->next = L1;
      break;
    }
    if (L1->data <= L2->data)
    {
      tmp->next = L1;
      L1 = L1->next;
    }
    else
    {
      tmp->next = L2;
      L2 = L2->next;
    }
    tmp = tmp->next;
  }
  return dump->next;
}

int main(int argc, char *argv[])
{
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"L1", "L2"};
  return GenericTestMain(args, "sorted_lists_merge.cc",
                         "sorted_lists_merge.tsv", &MergeTwoSortedLists,
                         DefaultComparator{}, param_names);
}
