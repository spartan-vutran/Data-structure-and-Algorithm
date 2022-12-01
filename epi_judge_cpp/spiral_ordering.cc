#include <vector>

#include "test_framework/generic_test.h"
using std::vector;
vector<int> MatrixInSpiralOrder(const vector<vector<int>> &square_matrix)
{
  int size = square_matrix.size();
  vector<int> rel;
  for (int i = 0; i < (size / 2) + 0.5; i++)
  {
    if (size - i - 1 - i == 0)
    {
      rel.push_back(square_matrix[i][i]);
      break;
    }
    for (int j = i; j < size - i - 1; j++)
    {
      rel.push_back(square_matrix[i][j]);
    }

    for (int j = i; j < size - i - 1; j++)
    {
      rel.push_back(square_matrix[j][size - i - 1]);
    }

    for (int j = size - i - 1; j >= i + 1; j--)
    {
      rel.push_back(square_matrix[size - i - 1][j]);
    }

    for (int j = size - i - 1; j >= i + 1; j--)
    {
      rel.push_back(square_matrix[j][i]);
    }
  }
  return rel;
}

int main(int argc, char *argv[])
{
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"square_matrix"};
  return GenericTestMain(args, "spiral_ordering.cc", "spiral_ordering.tsv",
                         &MatrixInSpiralOrder, DefaultComparator{},
                         param_names);
}
