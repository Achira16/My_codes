// C++ program to find minimum and maximum using segment tree 
#include<bits/stdc++.h> 
using namespace std; 
#define pi pair<int,int>
// Node for storing minimum nd maximum value of given range 
typedef struct node 
{ 
    pi minimum; 
}node; 

// A utility function to get the middle index from corner indexes. 
int getMid(int s, int e) { return s + (e -s)/2; } 

/* A recursive function to get the minimum and maximum value in 
	a given range of array indexes. The following are parameters 
	for this function. 

	st --> Pointer to segment tree 
	index --> Index of current node in the segment tree. Initially 
			0 is passed as root is always at index 0 
	ss & se --> Starting and ending indexes of the segment 
				represented by current node, i.e., st[index] 
	qs & qe --> Starting and ending indexes of query range */
node MaxMinUntill(vector<node>& st, int ss, int se, int qs, 
						int qe, int index) 
{ 
	// If segment of this node is a part of given range, then return 
	// the minimum and maximum node of the segment 
	node tmp,left,right; 
	if (qs <= ss && qe >= se) 
		return st[index]; 

	// If segment of this node is outside the given range 
	if (se < qs || ss > qe) 
	{ 
	tmp.minimum = make_pair(-1,INT_MAX); 
	return tmp; 
	} 

	// If a part of this segment overlaps with the given range 
	int mid = getMid(ss, se); 
	left = MaxMinUntill(st, ss, mid, qs, qe, 2*index+1); 
	right = MaxMinUntill(st, mid+1, se, qs, qe, 2*index+2); 
	if(left.minimum.second < right.minimum.second)
	{
		tmp.minimum = left.minimum;
	}
	else if(right.minimum.second < left.minimum.second)
	{
		tmp.minimum = right.minimum;
	}
	else
	{
		if(left.minimum.first < right.minimum.first)
			tmp.minimum = left.minimum;
		else
			tmp.minimum = right.minimum;
	}
	return tmp; 
} 

// Return minimum and maximum of elements in range from index 
// qs (quey start) to qe (query end). It mainly uses 
// MaxMinUtill() 
node MaxMin(vector<node>& st, int n, int qs, int qe) 
{ 
	node tmp; 

	// Check for erroneous input values 
	if (qs < 0 || qe > n-1 || qs > qe) 
	{ 
		tmp.minimum = make_pair(-1,INT_MAX); 
		return tmp; 
	} 

	return MaxMinUntill(st, 0, n-1, qs, qe, 0); 
} 

// A recursive function that constructs Segment Tree for array[ss..se]. 
// si is index of current node in segment tree st 
void constructSTUtil(vector<int>& arr, int ss, int se, vector<node>& st, 
					int si) 
{ 
	// If there is one element in array, store it in current node of 
	// segment tree and return 
	if (ss == se) 
	{ 
		st[si].minimum = make_pair(ss,arr[ss]); 
		return ; 
	} 

	// If there are more than one elements, then recur for left and 
	// right subtrees and store the minimum and maximum of two values 
	// in this node 
	int mid = getMid(ss, se); 
	constructSTUtil(arr, ss, mid, st, si*2+1); 
	constructSTUtil(arr, mid+1, se, st, si*2+2); 
	if(st[si*2+1].minimum.second < st[si*2+2].minimum.second)
	{
		st[si].minimum = st[si*2+1].minimum;
	}
	else if(st[si*2+2].minimum.second < st[si*2+1].minimum.second)
	{
		st[si].minimum = st[si*2+2].minimum;
	}
	else
	{
		if(st[si*2+1].minimum.first < st[si*2+2].minimum.first)
			st[si].minimum = st[si*2+1].minimum;
		else
			st[si].minimum = st[si*2+2].minimum;
	}
} 

/* Function to construct segment tree from given array. This function 
allocates memory for segment tree and calls constructSTUtil() to 
fill the allocated memory */
vector<node> constructST(vector<int>& arr, int n) 
{ 
	// Allocate memory for segment tree 

	// Height of segment tree 
	int x = (int)(ceil(log2(n))); 

	// Maximum size of segment tree 
	int max_size = 2*(int)pow(2, x) - 1; 

	vector<node> st(max_size); 

	// Fill the allocated memory st 
	constructSTUtil(arr, 0, n-1, st, 0); 

	// Return the constructed segment tree 
	return st; 
} 
vector<int> mostCompetitive(vector<int>& nums, int k) 
{
	int n = nums.size();
    vector<node> st = constructST(nums, n); 
	vector<int> ans;
	int qs = 0,qe = n-k;
	node res = MaxMin(st,n,qs,qe);
	ans.push_back(nums[res.minimum.first]);
	k--;
	while(k)
	{
		qs = res.minimum.first + 1;
		qe = n-k;
		res = MaxMin(st,n,qs,qe);
		ans.push_back(nums[res.minimum.first]);
		k--;
	}
	return ans;
}
// Driver program to test above functions 
int main() 
{ 
	int n,k;
	cin>>n>>k;
	vector<int> nums(n);
	for(int i=0;i<n;i++)
		cin>>nums[i];
	vector<int> ans = mostCompetitive(nums,k);
	for(auto i:ans)
	{
		cout<<i<<" ";
	}
	return 0; 
} 
