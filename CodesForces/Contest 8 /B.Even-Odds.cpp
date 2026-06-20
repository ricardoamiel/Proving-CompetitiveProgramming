#include <iostream>

/*
Being an nonconformist, Volodya is displeased with the current state of things, particularly with the order
of natural numbers (natural number is positive integer numbers). He is determined to rearrange them. But there are
many natural numbers, so Volodya decided to start with the first n. He writes down the following sequence of numbers:
firstly all odd integers from 1 to n (in ascending order), then all even integers from 1 to n (also in ascending
order). Help our hero to find out which number will stand at the position number k.

INPUT:
The only line of input contains integers n and k (1<=k<=n<=10^12)

Please do not use the %lld specifier to read or write 64-bit integers in C++. It is preferred to use the cin and cout
streams of the %I64d specifier.

OUTPUT:
Print the number that will stand at the position number k after Voladya's manipulation. 
*/

int main(){
    long long n, k; //n: final natural number, k: position of the number to find (index 1 to n)
    // notice that the number of odd integers from 1 to n = ceil(n/2)
    // # of odd integers = ceil(n/2) = (n+1)/2 if n is odd, n/2 if n is even
    std::cin>>n>>k;
    long long n_odds = (n + 1) / 2; // number of odd integers from 1 to n 
    if (k <= n_odds){ // the k-th number is the k-th odd integer
        std::cout<<2*k-1<<std::endl; // the k-th odd integer always be odd (2*k-1 = {1, 3, 5, 7, ...})
    }
    else{ // the k-th number is the (k - number of odd integers) -th even integer = (k - ceil(n/2)) = {2,4,6,...}
        std::cout<<2*(k-n_odds)<<std::endl;
    }
    return 0;
}

// For some reason only works with (n+1)/2 but not with ceil(n/2)
// this is because in C++ integer division truncates towards zero, 
// so (n+1)/2 effectively computes the ceiling of n/2 for positive integers.