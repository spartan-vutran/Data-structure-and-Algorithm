#include <vector>
#include <cfloat>
#include <algorithm>

#include "test_framework/generic_test.h"

using std::vector;
double BuyAndSellStockOnce(const vector<double> &prices)
{
  double min = DBL_MAX;
  double max = 0;
  for (int i = 0; i < prices.size(); i++)
  {
    min = std::min(min, prices[i]);
    max = std::max(max, prices[i] - min);
  }

  return max;
}

int main(int argc, char *argv[])
{
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"prices"};
  return GenericTestMain(args, "buy_and_sell_stock.cc",
                         "buy_and_sell_stock.tsv", &BuyAndSellStockOnce,
                         DefaultComparator{}, param_names);
}
