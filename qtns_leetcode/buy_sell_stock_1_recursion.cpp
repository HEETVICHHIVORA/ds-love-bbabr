class Solution {
public:
    void maxprofitfinder(int i,vector<int>& prices,int &maxprofit,int &minprice){
        if(i==prices.size()){
            return ;
        }
        if(prices[i]<minprice){
            minprice = prices[i];
        }
        int cprof = prices[i]-minprice;
        if(cprof>maxprofit){
            maxprofit= cprof;
        }
        maxprofitfinder(i+1,prices,maxprofit,minprice);

    }
    int maxProfit(vector<int>& prices) {
        int minprice = INT_MAX;
        int maxprofi = INT_MIN ;

        maxprofitfinder(0,prices,maxprofi,minprice);
        return maxprofi;
    }
};