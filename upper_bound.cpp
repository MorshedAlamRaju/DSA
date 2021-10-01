#include<bits/stdc++.h>
using namespace std;

int upperBound(vector<int> nums, int target) {
	int l = 0, r = nums.size();
	while (l < r) {
		int mid = (l + r) >> 1;
		if (nums[mid] <= target) {
			l = mid + 1;
		} else {
			r = mid;
		}
	}
	return l;
}


int getUpperBound(vector<int> nums, int target) {
	vector<int>::iterator st = nums.begin();
	vector<int>::iterator en = nums.end();
	
	auto _len = std::distance(st, en);
	
	while (_len > 0) {
		auto _half = _len >> 1;

		auto middle = st;
		std::advance(middle, _half);
		
		if (nums[_half] <= target) {
			st = middle;
			st++;
			_len = _len - _half - 1;
		} else {
			_len = _half;
		}
	}
	return st - nums.begin();
}
		
		



int main(int argc, char **argv) {
	vector<int> nums;
	
	for (int i = 1; i < argc; i++) {
		nums.push_back(stoi(argv[i]));
	}
	
	int target = stoi(argv[argc-1]);
	int r = upper_bound(begin(nums), end(nums), target) - nums.begin();
	int u = upperBound(nums, target);
	int rr = getUpperBound(nums, target);
	cout << r << " " << u << " " << rr << endl;
}
