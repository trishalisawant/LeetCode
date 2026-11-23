
class ProductOfNumbers {
public:
    vector<int> v;

    ProductOfNumbers() {
        v.push_back(1);
    }

    void add(int num) {
        if (num == 0) {
            v.clear();
            v.push_back(1);
        }
        else {
            int last = v.back();
            v.push_back(last * num);
        }
    }

    int getProduct(int k) {
        int n = v.size();

        if (k >= n) {
            return 0;
        }

        return v[n - 1] / v[n - k - 1];
    }
};
