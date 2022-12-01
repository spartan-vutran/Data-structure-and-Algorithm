#include <vector>

#include "test_framework/generic_test.h"
using std::vector;
// Check if a partially filled matrix has any conflicts.
bool CheckValid(int row, int col, const vector<vector<int>> &partial_assignment, int n);
bool IsValidSudoku(const vector<vector<int>> &partial_assignment)
{
  int size = partial_assignment.size();
  for (int i = 0; i < size; i++)
  {
    if (CheckValid(i, 0, i, size, partial_assignment))
  }

  for (int i = 0; i < size; i++)
  {
    /* code */
  }

  for (int i = 0; i < size; i++)
  {
    }
  return true;
}

bool CheckValid(int rowstart, int colstart, int rowend, int colend, const vector<vector<int>> &partial_assignment)
{
  int value = partial_assignment[row][col];
  for (int i = 0; i < n; ++i)
  {
    if (i == row)
      continue;
    if (partial_assignment[i][col] == value)
      return false;
  }
  for (int j = 0; j < n; ++j)
  {
    if (j == col)
      continue;
    if (partial_assignment[row][j] == value)
      return false;
  }
  for (int i = (row / 3) * 3; i < ((row / 3) + 1) * 3; i++)
  {
    for (int j = (col / 3) * 3; j < ((col / 3) + 1) * 3; j++)
    {
      if (row == i && col == j)
        continue;
      if (partial_assignment[i][j] == value)
        return false;
    }
  }
  return true;
}

int main(int argc, char *argv[])
{
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"partial_assignment"};
  return GenericTestMain(args, "is_valid_sudoku.cc", "is_valid_sudoku.tsv",
                         &IsValidSudoku, DefaultComparator{}, param_names);
}
