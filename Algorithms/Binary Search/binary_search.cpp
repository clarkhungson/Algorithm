#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	vector<int> arr = {1, 4, 5, 7, 8 ,9, 13, 14, 18, 19};
	{
		int j = upper_bound(arr.begin(), arr.end(), 12) - arr.begin();
		cout << "12 upper_bound: " << j << "ele: " << arr[j] << endl;
	}
	
	{
		int j = lower_bound(arr.begin(), arr.end(), 12) - arr.begin();
		cout << "12 lower_bound: " << j << "ele: " << arr[j] << endl;
	}
	
	{
		int j = upper_bound(arr.begin(), arr.end(), 13) - arr.begin();
		cout << "13 upper_bound: " << j << "ele: " << arr[j] << endl;
	}
	
	{
		int j = lower_bound(arr.begin(), arr.end(), 13) - arr.begin();
		cout << "13 lower_bound: " << j << "ele: " << arr[j] << endl;
	}
	
	{
		int j = upper_bound(arr.begin(), arr.end(), 19) - arr.begin();
		cout << "19 upper_bound: " << j << "ele: " << arr[j] << endl;
	}
	
	{
		int j = lower_bound(arr.begin(), arr.end(), 19) - arr.begin();
		cout << "1 lower_bound: " << j << "ele: " << arr[j] << endl;
	}
	
	{
		int j = upper_bound(arr.begin(), arr.end(), 22) - arr.begin();
		cout << "22 upper_bound: " << j << "ele: " << arr[j] << endl;
	}
	
	{
		int j = lower_bound(arr.begin(), arr.end(), 22) - arr.begin();
		cout << "22 lower_bound: " << j << "ele: " << arr[j] << endl;
	}
}
