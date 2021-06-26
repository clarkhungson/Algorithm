#include <stdio.h>
#include <iostream>
#include <cstdint>
#include <vector>

#define MAX_SIZE 1000

// array an
// find i, j / a[j]-a[i] max (i < j)


int find(std::vector<int>& a, int start, int end, int& maxValue, int& minValue) {
	std::cout << "start: " << start << ", end: " << end << std::endl;
	if (start == end - 1) {
		maxValue = (a[start] > a[end]) ? a[start] : a[end];
		minValue = (a[start] < a[end]) ? a[start] : a[end];
		std::cout << "start: " << start << ", end: " << end << ". MAX: " << a[end] - a[start] << std::endl;
		return a[end] - a[start];
	}
	if (start == end) {
		maxValue = a[start];
		minValue = a[end];
		return -1000;
	}
	int maxValue1, minValue1, maxValue2, minValue2;
	int max1 = find(a, start, start + (end-start) / 2, maxValue1, minValue1);
	int max2 = find(a, start + (end-start) / 2 + 1, end, maxValue2, minValue2);
	
	maxValue = (maxValue1 > maxValue2) ? maxValue1 : maxValue2;
	minValue = (minValue1 < minValue2) ? minValue1 : minValue2;
	
	int MAX = max1;
	if (max2 > MAX) {
		MAX = max2;
	}
	if (maxValue2 - minValue1 > MAX) {
		MAX = maxValue2 - minValue1;
	}
	std::cout << "start: " << start << ", end: " << end << ". MAX: " << MAX << std::endl;
	return MAX;
}

int main() {
    std::vector<int> a = {4, 2, 5, 9, 1, 7, 3, 0, 6, 9};
    int maxValue, minValue;
    std::cout << "Hello" << a.size() << std::endl;
    auto result = find(a, 0, a.size() - 1, maxValue, minValue);
    std::cout << "Result:" << result << std::endl;
//    std::cout << "m: " << m << std::endl;
//    std::cout << "n: " << n << std::endl;
//    std::cout << "Value: " << a[m] - a[n] << std::endl;
    return 0;
}
