#include "iostream"  
using namespace std;  
const int V = 4;  
const int MAX = 999999;  
 
int graph[V + 1][V + 1] = {  
    { 0, 0, 0, 0, 0 },  
    { 0, 0, 12, 18, 24 },  
    { 0, 12, 0, 36, 28 },  
    { 0, 18, 36, 0, 32 },  
    { 0, 24, 28, 32, 0 }  
    };  
   
int memoize[V + 1][1 << (V + 1)];  
   
int travelling_salesman_problem(int i, int mask)  
{       
    if (mask == ((1 << i) | 3))  
        return graph[1][i];  
    if (memoize[i][mask] != 0)  
        return memoize[i][mask];  
  
    int minimumCost = MAX;  
    for (int j = 1; j <= V; j++)  
        if ((mask & (1 << j)) && j != i && j != 1)  
            minimumCost = std::min(minimumCost, travelling_salesman_problem(j, mask & (~(1 << i))) + graph[j][i]);  
    return memoize[i][mask] = minimumCost;  
}  
int main()  
{   
    int cost = MAX;  
    for (int i = 1; i <= V; i++)  
        cost = std::min(cost, travelling_salesman_problem(i, (1 << (V + 1)) - 1) + graph[i][1]);  
  
    cout << "Minimum Cost : " << cost;  
  
    return 0;  
}  
