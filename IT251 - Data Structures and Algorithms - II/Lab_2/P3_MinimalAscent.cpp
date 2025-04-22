//This code prints the maximum  lenght of subarray of an array where it increases it 

#include <iostream>
#include <vector>
using namespace std;

int maximalAscentLength(const std::vector<int>& A) {
    int n = A.size();
    if (n == 0) {
        return 0; // Emptyarray has no ascent
    }

    int maxAscentLength = 1; // Minimum ascent length is 1
    int currentAscentLength = 1; // Start withthe first element as an ascent

    for (int i = 1; i < n; ++i) {
        if (A[i] >= A[i - 1]) {
            // Extend the current ascent
            currentAscentLength++;
        } else {
            // Start a new ascent
            currentAscentLength = 1;
        }

        // Update themaximal length if needed
        if (currentAscentLength > maxAscentLength) {
            maxAscentLength = currentAscentLength;
        }
    }

    return maxAscentLength;
}

int main() {
    int n;
    
    
    cout<<"Enter the size of the array:"<<endl;
    cin>>n;
    vector<int> A(n);
    cout<<"Enter the elements of the array:";
    for(int i=0;i<n;i++) scanf("%d",&A[i]);

    int result = maximalAscentLength(A);
    cout << "Maximal length of an ascent: " << result << endl;

    return 0;
}
