#include <vector>

#include "test_framework/generic_test.h"
using std::vector;
vector<int> PlusOne(vector<int> A)
{
  for (auto i = A.size() - 1; i >= 0; --i)
  {
    A[i]++;
    if (A[i] == 10)
    {
      A[i] = 0;
      if (i == 0)
      {
        A.insert(A.begin(), 1);
        break;
      }
      continue;
    }
    break;
  }
  return A;
}

int main(int argc, char *argv[])
{
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A"};
  return GenericTestMain(args, "int_as_array_increment.cc",
                         "int_as_array_increment.tsv", &PlusOne,
                         DefaultComparator{}, param_names);
}
