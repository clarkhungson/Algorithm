#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

int T;
int64_t n;

struct P {
	P(int64_t vv, int64_t ii) : v(vv), i(ii) {}
	int64_t v;
	int64_t i;
};

void solve() {
	scanf("%lld", &n);
	vector<int64_t> v;
	int64_t vv;
	for (int64_t i = 0; i < n; ++i) {
		scanf("%lld", &vv);
		v.push_back(vv);
	}
	
	// **************************************************
	
	if (n <= 10) {

	// create reference
	int64_t sum = 0;
	vector<P> reference;
	for (int i = 0; i < n; i++) {
		P o(v[i], i);
		sum += v[i];
		reference.push_back(o);
	}
	sort(reference.begin(), reference.end(), [](const P& p1, const P& p2) {
		return p1.v < p2.v;
	});
	
	int max_index = 0;
	int max_sum = 0;

	for (int i = 0; i < n; i += 3) {
		int64_t sum1 = 0;
		int64_t sum2 = 0;
		int64_t number_of_range1 = i / 3;
		int64_t number_of_range2 = (n - i) / 3;
//		cout << "number_of_range1: " << number_of_range1 << ", number_of_range2: " << number_of_range2 << endl;
		int64_t n1 = 0;
		int64_t n2 = 0;
//		cout << "reference.size(): " << reference.size() << endl;
		for (int j = reference.size() - 1; j >= 0; j--) {
//			cout << "START i: " << i << "n1: " << n1 << ", n2: " << n2 << endl;
			if (reference[j].i == i ) {
				continue;
			}
			if (reference[j].i < i && n1 < number_of_range1) {
				sum1 += v[reference[j].i];
				n1++;
			}
			if (reference[j].i > i && n2 < number_of_range2) {
				sum2 += v[reference[j].i];
				n2++;
		    }
		    if (n1 == number_of_range1 && n2 == number_of_range2) {
		    	break;
			}
//			cout << "i: " << i << "n1: " << n1 << ", n2: " << n2 << endl;
		}
		int64_t r = sum - sum1 - sum2;
//		cout << "sum1: " << sum1 << ", sum2: " << sum2 << endl;
		if (r > max_sum) {
			max_index = i;
			max_sum = r;
		}
//		cout << "max_index: " << max_index << ", max_sum: " << max_sum << endl;
		
	}
	printf("%" PRId64 " " "%" PRId64 "\n", max_index, max_sum);
	
	} else {
	
	// **************************************************
	
	// BEGIN SUM
	
	vector<int64_t> begin_sum;
	{
		vector<int64_t> sort_numbers;
		priority_queue<int64_t, vector<int64_t>, greater<int64_t>> q_on_sum;
		priority_queue<int64_t> q_on_idle;
		
		// 3 first
		sort_numbers.push_back(v[0]);
		sort_numbers.push_back(v[1]);
		sort_numbers.push_back(v[2]);
		sort(sort_numbers.begin(), sort_numbers.end());
		begin_sum.push_back(sort_numbers[2]);
		q_on_sum.push(sort_numbers[2]);
		q_on_idle.push(sort_numbers[1]);
		q_on_idle.push(sort_numbers[0]);
		sort_numbers.clear();
		
		// 6 first
		sort_numbers.push_back(q_on_sum.top());
		q_on_sum.pop();
		sort_numbers.push_back(q_on_idle.top());
		q_on_idle.pop();
		sort_numbers.push_back(q_on_idle.top());
		q_on_idle.pop();
		sort_numbers.push_back(v[3]);
		sort_numbers.push_back(v[4]);
		sort_numbers.push_back(v[5]);
		sort(sort_numbers.begin(), sort_numbers.end());
		begin_sum.push_back(sort_numbers[4] + sort_numbers[5]);
		q_on_sum.push(sort_numbers[5]);
		q_on_sum.push(sort_numbers[4]);
		q_on_idle.push(sort_numbers[0]);
		q_on_idle.push(sort_numbers[1]);
		q_on_idle.push(sort_numbers[2]);
		q_on_idle.push(sort_numbers[3]);
		sort_numbers.clear();
		
		// 9 first
		sort_numbers.push_back(q_on_sum.top());
		q_on_sum.pop();
		sort_numbers.push_back(q_on_sum.top());
		q_on_sum.pop();
		sort_numbers.push_back(q_on_idle.top());
		q_on_idle.pop();
		sort_numbers.push_back(v[6]);
		sort_numbers.push_back(v[7]);
		sort_numbers.push_back(v[8]);
		sort(sort_numbers.begin(), sort_numbers.end());
		begin_sum.push_back(sort_numbers[3] + sort_numbers[4] + sort_numbers[5]);
		q_on_sum.push(sort_numbers[5]);
		q_on_sum.push(sort_numbers[4]);
		q_on_sum.push(sort_numbers[3]);
		q_on_idle.push(sort_numbers[0]);
		q_on_idle.push(sort_numbers[1]);
		q_on_idle.push(sort_numbers[2]);
		sort_numbers.clear();

		for (int i = 3; i < n / 3; ++i) {
			// 3i first (12, 15, 18, ...)
			int64_t temp = begin_sum[i - 1];
			sort_numbers.push_back(q_on_sum.top());
			temp -= q_on_sum.top();
			q_on_sum.pop();
			sort_numbers.push_back(q_on_sum.top());
			temp -= q_on_sum.top();
			q_on_sum.pop();
			sort_numbers.push_back(q_on_sum.top());
			temp -= q_on_sum.top();
			q_on_sum.pop();
			sort_numbers.push_back(q_on_idle.top());
			q_on_idle.pop();
			sort_numbers.push_back(v[3 * i]);
			sort_numbers.push_back(v[3 * i + 1]);
			sort_numbers.push_back(v[3 * i + 2]);
			sort(sort_numbers.begin(), sort_numbers.end());
			temp = temp + sort_numbers[3] + sort_numbers[4] + sort_numbers[5] + sort_numbers[6];
			q_on_sum.push(sort_numbers[6]);
			q_on_sum.push(sort_numbers[5]);
			q_on_sum.push(sort_numbers[4]);
			q_on_sum.push(sort_numbers[3]);
			q_on_idle.push(sort_numbers[0]);
			q_on_idle.push(sort_numbers[1]);
			q_on_idle.push(sort_numbers[2]);
			sort_numbers.clear();
			begin_sum.push_back(temp);
		}
	}
	
//	cout << "max_numbers.size(): " << max_numbers.size() << endl;
//	for (int i = 0; i < max_numbers.size(); i++) {
//		cout << max_numbers[i] << ", ";
//	}

	// END SUM
	
	vector<int64_t> end_sum;
	{
		vector<int64_t> sort_numbers;
		priority_queue<int64_t, vector<int64_t>, greater<int64_t>> q_on_sum;
		priority_queue<int64_t> q_on_idle;
		
		// 3 last
		sort_numbers.push_back(v[n - 1]);
		sort_numbers.push_back(v[n - 2]);
		sort_numbers.push_back(v[n - 3]);
		sort(sort_numbers.begin(), sort_numbers.end());
		end_sum.push_back(sort_numbers[2]);
		q_on_sum.push(sort_numbers[2]);
		q_on_idle.push(sort_numbers[1]);
		q_on_idle.push(sort_numbers[0]);
		sort_numbers.clear();
		
		// 6 last
		sort_numbers.push_back(q_on_sum.top());
		q_on_sum.pop();
		sort_numbers.push_back(q_on_idle.top());
		q_on_idle.pop();
		sort_numbers.push_back(q_on_idle.top());
		q_on_idle.pop();
		sort_numbers.push_back(v[n - 4]);
		sort_numbers.push_back(v[n - 5]);
		sort_numbers.push_back(v[n - 6]);
		sort(sort_numbers.begin(), sort_numbers.end());
		end_sum.push_back(sort_numbers[4] + sort_numbers[5]);
		q_on_sum.push(sort_numbers[5]);
		q_on_sum.push(sort_numbers[4]);
		q_on_idle.push(sort_numbers[0]);
		q_on_idle.push(sort_numbers[1]);
		q_on_idle.push(sort_numbers[2]);
		q_on_idle.push(sort_numbers[3]);
		sort_numbers.clear();
		
		// 9 last
		sort_numbers.push_back(q_on_sum.top());
		q_on_sum.pop();
		sort_numbers.push_back(q_on_sum.top());
		q_on_sum.pop();
		sort_numbers.push_back(q_on_idle.top());
		q_on_idle.pop();
		sort_numbers.push_back(v[n - 7]);
		sort_numbers.push_back(v[n - 8]);
		sort_numbers.push_back(v[n - 9]);
		sort(sort_numbers.begin(), sort_numbers.end());
		end_sum.push_back(sort_numbers[3] + sort_numbers[4] + sort_numbers[5]);
		q_on_sum.push(sort_numbers[5]);
		q_on_sum.push(sort_numbers[4]);
		q_on_sum.push(sort_numbers[3]);
		q_on_idle.push(sort_numbers[0]);
		q_on_idle.push(sort_numbers[1]);
		q_on_idle.push(sort_numbers[2]);
		sort_numbers.clear();

		for (int i = n - 10; i >= 2; i -= 3) {
			// 3i last (12, 15, 18, ...)
			int64_t temp = end_sum[(n - i) / 3 - 1];
			sort_numbers.push_back(q_on_sum.top());
			temp -= q_on_sum.top();
			q_on_sum.pop();
			sort_numbers.push_back(q_on_sum.top());
			temp -= q_on_sum.top();
			q_on_sum.pop();
			sort_numbers.push_back(q_on_sum.top());
			temp -= q_on_sum.top();
			q_on_sum.pop();
			sort_numbers.push_back(q_on_idle.top());
			q_on_idle.pop();
			sort_numbers.push_back(v[i]);
			sort_numbers.push_back(v[i - 1]);
			sort_numbers.push_back(v[i - 2]);
			sort(sort_numbers.begin(), sort_numbers.end());
			temp = temp + sort_numbers[3] + sort_numbers[4] + sort_numbers[5] + sort_numbers[6];
			q_on_sum.push(sort_numbers[6]);
			q_on_sum.push(sort_numbers[5]);
			q_on_sum.push(sort_numbers[4]);
			q_on_sum.push(sort_numbers[3]);
			q_on_idle.push(sort_numbers[0]);
			q_on_idle.push(sort_numbers[1]);
			q_on_idle.push(sort_numbers[2]);
			sort_numbers.clear();
			end_sum.push_back(temp);
		}
	}

//	vector<int64_t> end_sum;
//	{
//		vector<int64_t> max_numbers;
//		
//		priority_queue<int64_t> q;
//		
//		max_numbers.push_back(v[n - 1]);
//		max_numbers.push_back(v[n - 2]);
//		max_numbers.push_back(v[n - 3]);
//		sort(max_numbers.begin(), max_numbers.end());
//		end_sum.push_back(max_numbers[2]);
//		q.push(max_numbers[0]);
//		q.push(max_numbers[1]);
//		max_numbers.erase(max_numbers.begin(), max_numbers.begin() + 2);
//		
//		
//		max_numbers.push_back(v[n - 4]);
//		max_numbers.push_back(v[n - 5]);
//		max_numbers.push_back(v[n - 6]);
//		max_numbers.push_back(q.top());
////		cout << "q.top(): " << q.top() << endl;
//		q.pop();
////		cout << "q.top(): " << q.top() << endl;
//		sort(max_numbers.begin(), max_numbers.end());
//		end_sum.push_back(max_numbers[4] + max_numbers[3]);
//		q.push(max_numbers[0]);
//		q.push(max_numbers[1]);
//		q.push(max_numbers[2]);
////		cout << "-> max_numbers: " <<endl;
////		for (int i = 0; i < max_numbers.size(); i++) {
////			cout << max_numbers[i] << ", ";
////		}
//		max_numbers.erase(max_numbers.begin(), max_numbers.begin() + 3);
////		cout << "-> max_numbers2: " <<endl;
////		for (int i = 0; i < max_numbers.size(); i++) {
////			cout << max_numbers[i] << ", ";
////		}
//		
//		max_numbers.push_back(v[n - 7]);
//		max_numbers.push_back(v[n - 8]);
//		max_numbers.push_back(v[n - 9]);
//		max_numbers.push_back(q.top());
////		cout << "q.top(): " << q.top() << endl;
// 		q.pop();
//		sort(max_numbers.begin(), max_numbers.end());
//		end_sum.push_back(max_numbers[5] + max_numbers[4] + max_numbers[3]);
//		q.push(max_numbers[0]);
//		q.push(max_numbers[1]);
//		q.push(max_numbers[2]);
//		max_numbers.erase(max_numbers.begin(), max_numbers.begin() + 3);
		
//		cout << "q: ";
//		while (!q.empty()) {
//			cout << q.top() << " ";
//			q.pop();
//		}
//		cout << "end max_numbers: " <<endl;
//		for (int i = 0; i < max_numbers.size(); i++) {
//			cout << max_numbers[i] << ", ";
//		}
//		cout <<endl;
//		
//		for (int i = n - 10; i >= 2; i -= 3) {
//			int64_t temp = end_sum[(n - i) / 3 - 1] - max_numbers[0] - max_numbers[1] - max_numbers[2];
//			cout << "i : " << i << "end tmp 1: " << temp << endl;
//			max_numbers.push_back(v[i]);
//			max_numbers.push_back(v[i - 1]);
//			max_numbers.push_back(v[i - 2]);
//			max_numbers.push_back(q.top());
//			cout << "q.top(): " << q.top() << endl;
//	 		q.pop();
//			sort(max_numbers.begin(), max_numbers.end());
//			temp = temp + max_numbers[3] + max_numbers[4] + max_numbers[5] + max_numbers[6];
//			q.push(max_numbers[0]);
//			q.push(max_numbers[1]);
//			q.push(max_numbers[2]);
//			cout << "end max_numbers: " <<endl;
//			for (int i = 0; i < max_numbers.size(); i++) {
//				cout << max_numbers[i] << ", ";
//			}
//			cout  << endl;
//			max_numbers.erase(max_numbers.begin(), max_numbers.begin() + 4);
//			
//			end_sum.push_back(temp);
//			cout << "end tmp: " << temp << endl;
//		}
//	}
	

	int64_t sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += v[i];
	}

//	cout << "begin_sum: " << endl;
//	for (int i = 0; i < begin_sum.size(); i++) {
//		cout << begin_sum[i] << ", ";
//	}
//	cout  << endl;
//	
//	cout << "end_sum: " << endl;
//	for (int i = 0; i < end_sum.size(); i++) {
//		cout << end_sum[i] << ", ";
//	}
//	cout  << endl;
//	
//	cout << "sum: " << sum << endl;

	int64_t max_index = 0;
	int64_t MAX = 0;
	for (int i = 0; i < n; i += 3) {
		int64_t sum1 = 0;
		int64_t sum2 = 0;
		if (i > 0) {
			sum1 = begin_sum[i / 3 - 1];
		}
			
		if (i < n - 1) {
			sum2 = end_sum[(n - i) / 3 - 1];
		}
		int64_t r = sum - sum1 - sum2;
		if (r > MAX) {
			MAX = r;
			max_index = i;
		}
	}
	
	printf("%" PRId64 " " "%" PRId64 "\n", max_index, MAX);
	
	}
	
}

int main() {
    cin >> T;
    while (T > 0) {
        solve();
        T--;
    }
	return 0;
}

