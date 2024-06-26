// gfg 

#include <vector>
#include <set>
using namespace std;

class Solution {
public:    

    vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3) {
        int i = 0, j = 0, k = 0;
        vector<int> ans;

        while (i < n1 && j < n2 && k < n3) {
            if (A[i] == B[j] && B[j] == C[k]) {
                ans.push_back(A[i]);
                i++;
                j++;
                k++;
            } 
            else if (A[i] < B[j]) {
                i++;
            } 
            else if (B[j] < C[k]) {
                j++;
            } 
            else {
                k++;
            }
        }

        // Remove duplicates from ans
        set<int> uniqueElements(ans.begin(), ans.end());
        ans.assign(uniqueElements.begin(), uniqueElements.end());

        return ans;
    }
};