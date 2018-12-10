// Peeking Iterator
// 继承Iterator类写一个新的类
// 因为next()就会移指针，但是新的函数peek又不想让他移
// 所以存下来next value，如果已经存了，就不用调next()求了

// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    stored = false;
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if(!stored) {
            nxtvalue = Iterator::next();
            stored = true;
        }
        return nxtvalue;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    if(stored) {
            stored = false;
            return nxtvalue;
        }
        return Iterator::next();
	}

	bool hasNext() const {
	    if(stored) return true;
        return Iterator::hasNext();
	}
private:
    int nxtvalue;
    bool stored;
};