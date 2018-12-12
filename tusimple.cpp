
int minAddDelete(string str) {
	int len = str.length();
	int res = INT_MAX;
	string resString = "";
	helper(str, 0, len-1, 0, res, resString);
	return res;
}

void helper(string str, int left, int right, int step, int& minstep, string& s) {
	if(left >= right) {
		s = step < minstep ? str : s;
		minstep = min(minstep, step)
		return;
	}
	if(step >= minstep) return;
	if(str[left] == str[right]) {
		helper(str, left+1, right-1, step, minstep, s);
	} else {
		string tmp = str.substr(0, left) + str.substr(left+1);
		helper(tmp, left, right-1, step+1, minstep, s);
		tmp = str.substr(0, right) + str.substr(right+1);
		helper(tmp, left, right-1, step+1, minstep, s);
	}
	return;
}