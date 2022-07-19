// number: 1570
// name: Dot Product of Two Sparse Vectors
// tags: two pointers, hash map

class SparseVector {
public:
    
    SparseVector(vector<int> &nums) {
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (nums[i] != 0) {
                indexes.push_back(i);
                data.push_back(nums[i]);
            }
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int i = 0;
        int j = 0;
        int ans = 0;
        while (i < (int)indexes.size() && j < (int)vec.indexes.size()) {
            if (indexes[i] == vec.indexes[j]) {
                ans += data[i]*vec.data[j];
                i++;
                j++;
            } else if (indexes[i] < vec.indexes[j]) i++;
            else j++;
        }
        return ans;
    }

    vector<int> indexes;
    vector<int> data;
};


// O(min(n, m) O(N)
class SparseVector {
public:
    
    SparseVector(vector<int> &nums) {
        pair<int, int> curPair;
        for (int i = 0; i < nums.size(); ++i) {
            if (i == 0) {
                curPair.first = nums[0];
                curPair.second = 1;
            } else {
                if (nums[i] != nums[i - 1]) {
                    d_data.push_back(curPair);
                    curPair.first = nums[i];
                    curPair.second = 1;
                } else curPair.second++;
            }
        }
        d_data.push_back(curPair);
    }
    
    size_t size() {
        return d_data.size();
    }
    
    pair<int, int> operator[](size_t index) {
        return d_data[index];
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int answer = 0;
        int v1_index = 0;
        int v2_index = 0;
        int v1_counter = 0;
        int v2_counter = 0;
        for (; v1_index < d_data.size() && v2_index < vec.size();) {
            auto v1_pair = d_data[v1_index];
            auto v2_pair = vec[v2_index];
            if (v1_counter == 0) v1_counter = v1_pair.second;
            if (v2_counter == 0) v2_counter = v2_pair.second;
            if (v1_counter == v2_counter) {
                answer += (v1_pair.first * v2_pair.first) * v1_counter;
                v1_counter = 0;
                v2_counter = 0;
                v1_index++;
                v2_index++;
            } else if (v1_counter < v2_counter) {
                answer += (v1_pair.first * v2_pair.first) * v1_counter;
                v2_counter -= v1_counter;
                v1_counter = 0;
                v1_index++;
            } else if (v2_counter < v1_counter) {
                answer += (v1_pair.first * v2_pair.first) * v2_counter;
                v1_counter -= v2_counter;
                v2_counter = 0;
                v2_index++;
            }
        }
        return answer;
    }
    
private:
    vector<pair<int, int>> d_data;
};

