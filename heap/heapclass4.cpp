class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> maxHeap;

        for(int i=0; i<piles.size(); i++) {
            int element = piles[i];
            maxHeap.push(element);
        }

        while(k--) {
            int topElement = maxHeap.top();
            maxHeap.pop();

            topElement = topElement - topElement/2;

            maxHeap.push(topElement);
        }

        int sum = 0;
        while(!maxHeap.empty()) {
            int top = maxHeap.top();
            sum += top;
            maxHeap.pop();
        }
        return sum;
        
    }
};

class Info{
    public:
        char val;
        int count;
    Info(char ch, int cnt) {
        this->val = ch;
        this->count = cnt;
    }
};

class compare{
    public:
        bool operator()(Info a, Info b) {
            return a.count < b.count;
        }
};


class Solution {
public:
    string reorganizeString(string s) {
        int freq[26] = {0};

        //count freq of all chartacter in string
        for(int i=0; i<s.length(); i++) {
            char ch = s[i];
            freq[ch-'a']++;
        }
        //push all characters in maxHeap
        priority_queue<Info, vector<Info>, compare> maxHeap;
        //push all characters into heap, where freq > 0
        for(int i=0; i<26; i++) {
            if(freq[i] > 0) {
                Info temp(i+'a', freq[i]);
                // temp.val = i+'a';
                // temp.count = freq[i];
                maxHeap.push(temp);
            }
        }

        string ans = "";

        while(maxHeap.size() > 1) {
            Info first = maxHeap.top();
            maxHeap.pop();
            Info second = maxHeap.top();
            maxHeap.pop();

            ans.push_back(first.val);
            first.count--;
            ans.push_back(second.val);
            second.count--;

            if(first.count > 0) {
                maxHeap.push(first);
            }
            if(second.count > 0) {
                maxHeap.push(second);
            }
        }

        //if 1 element bacha h, toh alag se handle karo
        if(maxHeap.size() == 1) {
            Info first = maxHeap.top();
            maxHeap.pop();

            ans.push_back(first.val);
            first.count--;

            if(first.count != 0 ) {
                //answer not possible
                return  "";
            }
        }
    return ans;
 
    }
};



class Info{
    public:
        char val;
        int count;
    Info(char ch, int cnt) {
        this->val = ch;
        this->count = cnt;
    }
};

class compare{
    public:
        bool operator()(Info a, Info b) {
            return a.count < b.count;
        }
};


class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<Info, vector<Info>, compare> maxHeap;
        if(a > 0) {
            Info temp('a', a);
            maxHeap.push(temp);
        }
        if(b > 0) {
            Info temp('b', b);
            maxHeap.push(temp);
        }
        if(c > 0) {
            Info temp('c', c);
            maxHeap.push(temp);
        }

        string ans = "";
        while(maxHeap.size() > 1) {
            Info first = maxHeap.top();
            maxHeap.pop();
            Info second = maxHeap.top();
            maxHeap.pop();
            
            if(first.count >=2) {
                ans.push_back(first.val);
                ans.push_back(first.val);
                first.count -= 2;
            }
            else {
                ans.push_back(first.val);
                first.count--;
            } 

            if(second.count >=2 && second.count >= first.count) {
                ans.push_back(second.val);
                ans.push_back(second.val);
                second.count -= 2;
            }
            else {
                ans.push_back(second.val);
                second.count--;
            } 

            if(first.count > 0) {
                maxHeap.push(first);
            }
            if(second.count > 0) {
                maxHeap.push(second);
            }       
        }

        if(maxHeap.size() == 1) {
            Info first = maxHeap.top();
            maxHeap.pop();

            if(first.count >=2) {
                ans.push_back(first.val);
                ans.push_back(first.val);
                first.count -= 2;
            }
            else {
                ans.push_back(first.val);
                first.count--;
            } 
        } 
        return ans;
    }
};


#include <iostream>
#include<queue>
using namespace std;

void solveForMedian(double &median, priority_queue<int> &maxi, priority_queue<int,vector<int>, greater<int> > &mini, int element) {

	
	if(maxi.size() == mini.size()) {
		if(element > median) {
			mini.push(element);
			median = mini.top();
		}
		else {
			maxi.push(element);
			median = maxi.top();
		}
	}
	else if(maxi.size() == mini.size()+1) {
		if(element > median) {
			mini.push(element);
		}
		else {
			int maxTop = maxi.top();
			maxi.pop();
			mini.push(maxTop);
			maxi.push(element);
		}
		median = (mini.top() + maxi.top())/2.0;
	}
	else if(mini.size() == maxi.size()+1) {
		if(element > median) {
			int minTop = mini.top();
			mini.pop();
			maxi.push(minTop);
			mini.push(element);
		}
		else {
			maxi.push(element);
		}
		median = (mini.top() + maxi.top())/2.0;
	}
}

int main() {

	int arr[] = {12,10,8,4,2,3,15};
	int n = 7;

	//12 -> 12
	//10 12 -> 11
	//8 10 12 -> 10
	//4 8 10 12 -> 9
	//2 4 8 10 12 -> 8
	//2 3 4 8 10 12 0 -> 6
	//2 3 4 8 10 12 15 -> 8

	double median  = 0;
	priority_queue<int> maxi;
	
	priority_queue<int,vector<int>, greater<int> > mini;
	
	for(int i=0; i<n; i++) {
		int element = arr[i];
		solveForMedian(median, maxi, mini, element);
		cout << "Median found: " << median << endl;
	}



	return 0;
}