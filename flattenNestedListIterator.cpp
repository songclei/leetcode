/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
    vector<int> cur_vector;
    int cur;
    int size;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (int i = 0; i < nestedList.size(); ++i)  
            decode_nested(nestedList[i], cur_vector);
        size = cur_vector.size();
        cur = 0;
    }

    int next() {
        return cur_vector[cur++];
    }

    bool hasNext() {
        if (cur >= size)  return false;
        return true;
    }
    
    void decode_nested(NestedInteger &nest, vector<int> &v) {
        if (nest.isInteger()) {
            cout << nest.getInteger();
            v.push_back(nest.getInteger());
            return;
        }
        vector<NestedInteger> nest_list = nest.getList();
        for (int i = 0; i < nest_list.size(); ++i) {
            decode_nested(nest_list[i], v);
        }
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */