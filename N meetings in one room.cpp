#include <bits/stdc++.h>
using namespace std;

struct meeting
{
	int start_time ;
	int end_time ;
	int index ;
};

bool sorter(meeting a , meeting b) {
	return (a.end_time < b.end_time) || (a.end_time == b.end_time && a.start_time < b.start_time) ;
}


main() {

	int number_of_testcase ; cin >> number_of_testcase ;

	while (number_of_testcase--) {
		int n ; cin >> n ;
		vector<meeting> vec(n, {0, 0, 0}) ;

		vector<int> a ;
		vector<int> b ;

		for ( int i = 0 ; i < n ; i++ ) {
			int k ; cin >> k ;
			a.push_back(k) ;
		}

		for ( int i = 0 ; i < n ; i++ ) {
			int k ; cin >> k ;
			b.push_back(k) ;
		}

		for ( int i = 0 ; i < n ; i++ ) {
			vec[i].start_time = a[i] ;
			vec[i].end_time = b[i] ;
			vec[i].index = i + 1 ;
		}

		sort(vec.begin(), vec.end(), sorter) ;

		for ( int i = 0 ; i < n ; i++ ) {
			meeting last_meeting ;
			if (i == 0) {
				cout << vec[i].index << " " ;
				last_meeting = vec[i] ;
			}
			else {
				if (vec[i].start_time >= last_meeting.end_time) {
					cout << vec[i].index << " " ;
					last_meeting = vec[i] ;
				}
			}
		}

		cout << endl ;

	}
}
