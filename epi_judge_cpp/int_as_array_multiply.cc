#include <vector>

#include "test_framework/generic_test.h"
using std::vector;
vector<int> Multiply(vector<int> num1, vector<int> num2)
{
  vector<int> rel(num1.size() + num2.size(), 0);
  bool isNev = false;
  if (num1[0] < 0)
    isNev = !isNev;
  if (num2[0] < 0)
    isNev = !isNev;
  for (int i = num1.size() - 1; i >= 0; --i)
  {
    for (int j = num2.size() - 1; j >= 0; --j)
    {

      rel[i + j + 1] += abs(num1[i]) * abs(num2[j]);
      rel[i + j] += rel[i + j + 1] / 10;
      rel[i + j + 1] = rel[i + j + 1] % 10;
    }
  }
  int i = 0;
  rel = {
      find_if_not(begin(rel), end(rel), [](int a)
                  { return a == 0; }),
      end(rel)};
  if (rel.empty())
    return {0};
  if (isNev == true)
  {
    *(rel.begin()) = -(*(rel.begin()));
  }
  return rel;
}

int main(int argc, char *argv[])
{
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"num1", "num2"};
  return GenericTestMain(args, "int_as_array_multiply.cc",
                         "int_as_array_multiply.tsv", &Multiply,
                         DefaultComparator{}, param_names);
}
