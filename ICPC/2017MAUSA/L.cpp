/* Dynamic Programming C++ implementation of LCS problem */
#include<bits/stdc++.h> 
using namespace std; 

int max(int a, int b); 

/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int lcs( vector<char []> strings, int k ) 
{ 
	int L[k + 1][k + 1]; 
	int i, j; 
	
	/* Following steps build L[m+1][n+1] in 
	bottom up fashion. Note that L[i][j] 
	contains length of LCS of X[0..i-1] 
	and Y[0..j-1] */
	for (i = 0; i <= k; i++) 
	{ 
		for (j = 0; j <= n; j++) 
		{ 
		if (i == 0 || j == 0) 
			L[i][j] = 0; 
	
		else if (X[i - 1] == Y[j - 1]) 
			L[i][j] = L[i - 1][j - 1] + 1; 
	
		else
			L[i][j] = max(L[i - 1][j], L[i][j - 1]); 
		} 
	} 
		
	/* L[m][n] contains length of LCS 
	for X[0..n-1] and Y[0..m-1] */
	return L[m][n]; 
} 

/* Utility function to get max of 2 integers */
int max(int a, int b) 
{ 
	return (a > b)? a : b; 
} 

// Driver Code 
int main() 
{ 
    int n, k;
    cin >> n >> k;

    vector<char []> strings;
    char word[k];
    for (int i = 0; i < n; i++) {
        cin >> word;
        strings.push_back(word);
    }
	
	cout << "Length of LCS is "
		<< lcs( , Y, k, k ); 
	
	return 0; 
} 

// This code is contributed by rathbhupendra 
