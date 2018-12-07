// Flatten 2D Vector

// 先存下来
class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d) {
        curidx = 0;
        for(auto vec:vec2d) {
            v.insert(v.end(), vec.begin(), vec.end());
        }
    }

    int next() {
        return v[curidx++];
    }

    bool hasNext() {
        return curidx < v.size();
    }
private:
    int curidx;
    vector<int> v;
};


// 记录x和y
// 用while因为有可能多个空[]
class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d) {
        x = 0;
        y = 0;
        v = vec2d;
    }

    int next() {
        return v[x][y++];
    }

    bool hasNext() {
        while(x < v.size() && y == v[x].size()) {
            x++;
            y = 0;
        }
        return x < v.size() && y < v[x].size();
    }
private:
    int x;
    int y;
    vector<vector<int>> v;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */