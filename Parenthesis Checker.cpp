/*
Given an expression string exp. Examine whether the pairs and the orders of “{“,”}”,”(“,”)”,”[“,”]” are correct in exp.
For example, the program should print 'balanced' for exp = “[()]{}{[()()]()}” and 'not balanced' for exp = “[(])”

Input:
The first line of input contains an integer T denoting the number of test cases.  Each test case consists of a string of expression, in a separate line.

Output:
Print 'balanced' without quotes if the pair of parenthesis is balanced else print 'not balanced' in a separate line.

Constraints:
1 ≤ T ≤ 100
1 ≤ |s| ≤ 105

Example:
Input:
3
{([])}
()
([]

Output:
balanced
balanced
not balanced
*/

#include<bits/stdc++.h>
using namespace std ;

#define int 			long long
#define PB 				push_back
#define ULL				unsigned long long
#define MOD 			1000000007LL
#define ff				first
#define se				second
#define setBits(n)		__builtin_popcount(n)
#define sort(A)			sort(A.begin(),A.end())
#define rev(A)			reverse(A.begin(),A.end())
#define foreach(itr,A)	for(auto itr=A.begin();itr!=A.end();++itr)


typedef long long LL ;
typedef vector<int> VI ;
typedef vector<char> VC ;
typedef vector<string> VS;
typedef vector<vector<int>> VVI ;
typedef vector<vector<char>> VVC ;
typedef priority_queue<int> PQD ;
typedef priority_queue<int, VI, greater<int>> PQI ;
typedef pair<int, int> PII ;
typedef set<int> SEI ;
typedef multiset<int> MSEI ;
typedef unordered_set<int> USEI ;
typedef map<int, int> MPII ;
typedef unordered_map<int, int> UMPII ;
typedef stack<int> STI ;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


string check(string s) {

	stack<char> mystack ;

	for ( int i = 0 ; i < s.length() ; i++ ) {

		if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
			mystack.push(s[i]) ;
		}
		else {
			if (mystack.empty() == true ) return "not balanced" ;
			else if (s[i] == ')' && mystack.top() == '(') mystack.pop() ;
			else if (s[i] == '}' && mystack.top() == '{') mystack.pop() ;
			else if (s[i] == ']' && mystack.top() == '[') mystack.pop() ;
			else return "not balanced" ;
		}
	}

	if (!mystack.empty()) return "not balanced" ;

	return "balanced" ;

}

int main() {

	int t ; cin >> t ;

	while (t--) {
		string s ;
		cin >> s ;
		cout << check(s) << endl ;
	}

}
