//https://leetcode-cn.com/problems/intersection-lcci/
class Solution {
public:

    pair<long long, long long> getA(int x, int y, int x1, int y1) {
        if(y == y1 || x == x1) {
            return {0, 1};
        } else {
            return {(y - y1),  (x - x1)};
        }
    }

    pair<long long , long long > getB(int x, int y, pair<int, int> a) {
        if(a.first == 0) {
            return {y, 1};
        } else {
            return {a.second * y - a.first * x, a.second};
        }
    }

    bool isSame(pair<long long, long long> a, pair<long long, long long> b) {
        return a.first * b.second == a.second * b.first;
    }

    bool isX(int x, int x1, int y, int y1) {
        return (y != y1 && x == x1);
    }

    double getY(pair<long long, long long> a, pair<long long, long long> b, pair<long long,long long> x) {
        pair<long long, long long> y = { a.first * x.first * b.second + a.second * x.second * b.first, a.second * b.second * x.second};
        return round(y.first * 1e6 / y.second) / 1e6;
    }

    vector<double> intersection(vector<int>& start1, vector<int>& end1, vector<int>& start2, vector<int>& end2) {
        int x1 = start1[0], y1 = start1[1], x2 = end1[0], y2 = end1[1];
        int x3 = start2[0], y3 = start2[1], x4 = end2[0], y4 = end2[1];
        
        int xmin = max(min(x1, x2), min(x3, x4)), xmax = min(max(x1,x2), max(x3, x4));
        int ymin = max(min(y1, y2), min(y3, y4)), ymax = min(max(y2,y1), max(y3, y4));

        pair<int, int> a = getA(x1, y1, x2, y2);
        pair<int, int> b = getB(x1, y1, a);
        pair<int, int> a1 = getA(x3, y3, x4, y4);
        pair<int, int> b1 = getB(x3, y3, a1);

        pair<long long, long long> x = {a.second * a1.second* (b.second * b1.first - b1.second * b.first), 
            b1.second * b.second * (a1.second * a.first - a1.first * a.second)
        };


        bool isx1 = isX(x1, x2, y1, y2), isx2 = isX(x3, x4, y3, y4);
        if(isx1 && !isx2) {
            if(x1 >= xmin && x1 <=xmax && ymax >= ymin) {
                return {(double)x1, getY(a1, b1, {x1, 1})};
            }
            return {};
        }

        if(isx2 && !isx1) {
            if(x3 >= xmin && x3 <=xmax && ymax >= ymin) {
                return {(double)x3, getY(a, b, {x3, 1})};
            }
            return {};
        }

        if(isx1 && isx2) {
            if(x1 == x3 && ymax >= ymin) return {(double) x1, (double) ymin};
            return {};
        }
        
        bool isP = isSame(a, a1);
        if(isP) {
            if(isSame(b, b1)) {
                if(xmax >= xmin && ymax >= ymin) {
                    return {(double)xmin, (double)(xmin == x1 ? y1 : y3)};
                } else {
                    return {};
                }
            } else {
                return {};
            }
        }


        double xd = round(x.first * 1e6 / x.second) / 1e6;
        double yd = getY(a, b, x);

        if( xd <= xmax && xd >=xmin) return {xd, yd};
        return {};
        
    }
};
