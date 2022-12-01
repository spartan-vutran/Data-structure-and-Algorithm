#include <vector>

#include "test_framework/generic_test.h"
#include "test_framework/timed_executor.h"
using std::vector;
// Returns the number of valid entries after deletion.
int DeleteDuplicates(vector<int> *A_ptr)
{
  vector<int> rel;
  if (A_ptr->size() == 0)
    return 0;
  int i = 0;
  int j = 0;
  rel.push_back((*A_ptr)[0]);
  for (int i = 1; i < A_ptr->size() - 1; i++)
  {
    if ((*A_ptr)[i] != (*A_ptr)[i - 1])
      rel.push_back((*A_ptr)[i]);
    ;
  }
  A_ptr = &rel;
  return rel.size();
}
vector<int> DeleteDuplicatesWrapper(TimedExecutor &executor, vector<int> A)
{
  int end = executor.Run([&]
                         { return DeleteDuplicates(&A); });
  A.resize(end);
  return A;
}

int main(int argc, char *argv[])
{
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "A"};
  return GenericTestMain(
      args, "sorted_array_remove_dups.cc", "sorted_array_remove_dups.tsv",
      &DeleteDuplicatesWrapper, DefaultComparator{}, param_names);
}
