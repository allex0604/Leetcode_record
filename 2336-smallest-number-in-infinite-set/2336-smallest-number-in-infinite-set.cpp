class SmallestInfiniteSet {
public:
    SmallestInfiniteSet() {
        for(int i=1; i<=1000; ++i)
            iset.insert(i);
    }
    
    int popSmallest() {
        it = iset.begin();
        int ans = *it;
        iset.erase(it);
        return ans;
    }
    
    void addBack(int num) {
        iset.insert(num);
    }
private:
    set<int> iset;
    std::set<int>::iterator it;
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */