#include <iostream>

/*
1D Eraser
You are given a strip of paper s that is n cells long. Each cell is either black or white. In an operation you
can take any k consecutive cells and make them all white.

Find the minimum number of operations needed to remove all black cells.

INPUT: 
The first line contains a single integer t (1<=t<=1000) — the number of test cases.

The first line of each test case contains two integers n and k (1<=k<=n<=2*10^5) — the length of the paper and the
integer used in operation.

The second line of each test case contains a string s of length n consisting of characters B (representing a black
cell) and W (representing a white cell).

The sum of n over all test cases does not exceed 2*10^5.

OUTPUT:
For each test case, output a single integer — the minimum number of operations needed to remove all black cells.
*/

int main(){
    int n_tests, n, k; //n_tests: number of tests, n: length of paper, k: number of consecutive cells to make W
    std::string s; //s: string representing the paper
    std::cin>>n_tests;
    while(n_tests>0){
        std::cin>>n>>k;
        std::cin>>s;
        int count = 0; // count: number of operations needed
        for (int i=0; i<n; i++){
            if (s[i] == 'B'){ // if the cell is black then change it to W the next k cells (included the current one)
                count++; // increment the count of operations, also skip this cell to make it white
                i += k-1; // skip the next k-1 cells as they will be made white
                // 1 + k - 1 = k consecutive cells turned white
            }
        }
        std::cout<<count<<std::endl; // output the number of operations needed
        n_tests--; // decrement the number of test cases
    }

    return 0;
}