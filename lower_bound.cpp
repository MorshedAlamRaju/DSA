#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> v, int t) {
	int l = 0, r = v.size();
	
	while (l < r) {
		int mid = (l + r) >> 1;
		if (v[mid] < t) {
			l = mid + 1;
		} else {
			r = mid;
		}
	}
	return l;
}

int getLowerBound(vector<int> v, int target) {

	vector<int>::iterator st = v.begin();
	vector<int>::iterator en = v.end();
	
	auto __len = std::distance(st,en);
	
	while (__len > 0) {
		auto __half = __len >> 1;

		auto middle = st;
		std::advance(middle, __half);

		if (v[__half] < target) {
			st = middle;
			st++;
			__len = __len - __half - 1;
		} else {
			__len = __half;
		}
	}
	return st - v.begin();
}

int stoi(char *s) {
	int sum = 0;
	while (*s != '\0') {
		sum *= 10;
		sum += (*s) - '0';
		s++;
	}
	return sum;
}


int main(int argc, char **argv) {
	vector<int> v;
	
	for (int i = 1; i < argc - 1; i++) {
		v.push_back(stoi(argv[i]));
	}
	
	int target = stoi(argv[argc-1]);
	auto l = lower_bound(v.begin(), v.end(), target) - v.begin();
	auto ll = getLowerBound(v, target);
	auto lll = getLowerBound(v, target);

	cout << l << " " << ll << " " << lll << endl;
}


