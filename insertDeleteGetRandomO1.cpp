class RandomizedSet {
    int size;
    unordered_map<int, int> my_map;
    vector<int> my_vector;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        size = 0;
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (my_map.find(val) != my_map.end())  return false;
        my_map[val] = size;
        my_vector.resize(size+1);
        my_vector[size] = val;
        size++;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto it = my_map.find(val);
        if (it == my_map.end())  return false;
        int index = my_map[val];
        my_map.erase(val);
        size--;
        if (size == index)  return true;
        my_vector[index] = my_vector[size];
        my_map[my_vector[index]] = index;
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int ran = rand() % size;
        return my_vector[ran];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */