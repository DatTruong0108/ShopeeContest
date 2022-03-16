#include<iostream>
#include<vector>
using namespace std;

vector <int> sortedSquares(vector<int> numbers)
{
    int l = 0;
    int r = numbers.size()-1;
    int i = numbers.size()-1;
    vector<int> ans(numbers.size(),0);
    while(l<=r)
    {
        if(abs(numbers[l]) > abs(numbers[r]))
        {
            ans[i] = numbers[l]*numbers[l];
            l++;
        }
        else
        {
            ans[i] = numbers[r]*numbers[r];
            r--;
        }
        i--;
    }
    return ans;

}
int main()
{
    vector<int> num = {-4,-2,0,3,5};
    
    for(auto i:sortedSquares(num))
        cout<<i<<" ";
}