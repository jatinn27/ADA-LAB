#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>

using namespace std;

class item
{
public:
    float profit;
    float weight;
    float profitByWeight;

    item(float profit, float weight)
    {
        this->profit = profit;
        this->weight = weight;
        this->profitByWeight = (profit / weight);
    }
};

bool cmpProfit(item a, item b)
{
    return b.profit < a.profit;
}

bool cmpWeight(item a, item b)
{
    return b.weight > a.weight;
}

bool cmpProfitbyWeight(item a, item b)
{
    return b.profitByWeight < a.profitByWeight;
}

float fractionalKnapsack(vector<item> &items, int maxWeight)
{
    sort(items.begin(), items.end(), cmpProfitbyWeight);
    float profit = 0;

    for (int i = 0; i < items.size(); i++)
    {
        if (maxWeight >= items[i].weight)
        {
            profit += items[i].profit;
            maxWeight -= items[i].weight;
        }
        else
        {
            profit += (maxWeight / items[i].weight) * items[i].profit;
            break;
        }
    }

    return profit;
}

int main()
{
    vector<item> items = {item(10, 2),item(5, 3),item(15, 5),item(7, 7),item(6, 1),item(18, 4),item(3, 1)};
    int maxWeight = 15;

    float maxProfit = fractionalKnapsack(items, maxWeight);

    cout << "Maximum profit earned is " << setprecision(3) << fixed << maxProfit << endl;

    return 0;
}
