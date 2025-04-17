class RandomizedSet {
private:
    unordered_map<int, int> valToIndex;
    vector<int> values;

public:
    RandomizedSet() {
        srand(time(0)); 
    }

    bool insert(int val) {
        if (valToIndex.count(val)) return false;
        values.push_back(val);
        valToIndex[val] = values.size() - 1;
        return true;
    }

    bool remove(int val) {
        if (!valToIndex.count(val)) return false;

        int index = valToIndex[val];
        int lastVal = values.back();

      
        values[index] = lastVal;
        valToIndex[lastVal] = index;

       
        values.pop_back();
        valToIndex.erase(val);

        return true;
    }

    int getRandom() {
        int randomIndex = rand() % values.size();
        return values[randomIndex];
    }
};

