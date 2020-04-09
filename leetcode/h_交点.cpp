//https://leetcode-cn.com/problems/intersection-lcci/
//线段交点，线段平行情况，相交，精度问题
typedef pair<long long, long long> pll;
class Solution {
public:
    struct F {
        pll a, b, c; // ax+cy+b = 0
        bool isX = false;
        bool isY = false;
        int min_x;
        int max_x;
        int min_y;
        int max_y;
        void print() {
            printf("abc: %lld %lld %lld %lld %lld %lld \n", a.first, a.second, b.first, b.second, c.first, c.second);
            printf("isXY: %d %d \n", isX, isY);
            printf("xy:  %d %d %d %d \n", min_x, max_x, min_y, max_y);
        }
    };

    F genF(int x, int y, int x1, int y1) {
        F f;
        f.min_x = min(x, x1);
        f.max_x = max(x, x1);
        f.min_y = min(y, y1);
        f.max_y = max(y, y1);
        
        if(x != x1 && y == y1) {
            f.isY = true;
            f.min_y = f.max_y = y;
            f.a = {0, 0};
            f.c = {1, 1};
            f.b = {y, 1};
            return f;
        }

        if(x == x1 && y != y1) {
            f.isX = true;
            f.min_x = f.max_x = x;
            f.c = {0, 0};
            f.a = {1, 1};
            f.b = {x, 1};
            return f;
        }
        f.c = {1, 1};
        f.a = {y - y1, x - x1};
        f.b = {x* y1 - x1 * y, x - x1};
        return f;
    }

    pair<int, int> xDomain(F f1, F f2) { //x 范围
        return {max(f2.min_x, f1.min_x), min(f1.max_x, f2.max_x)};
    }

    pair<int, int> yDomain(F f1, F f2) {  //y 范围
        return {max(f2.min_y, f1.min_y), min(f1.max_y, f2.max_y)};
    }

    bool isSame(pll a, pll b) { //是否平行
        return a.first * b.second == a.second * b.first;
    }

    double cal(pll x, F f) { //通过x计算y
        return round((f.a.first * f.b.second * x.first + f.b.first * f.a.second * x.second)  * 1e6/f.a.second/f.b.second/x.second) /1e6; 
    }

    double calX(int y, F f) { //通过y计算x
        return round((f.a.second * f.b.second * y  - f.b.first * f.a.second)  * 1e6/f.a.first/f.b.second) /1e6; 
    }

    vector<double> intersection(vector<int>& start1, vector<int>& end1, vector<int>& start2, vector<int>& end2) {
        int x1 = start1[0], y1 = start1[1], x2 = end1[0], y2 = end1[1];
        int x3 = start2[0], y3 = start2[1], x4 = end2[0], y4 = end2[1];
        
        F f1 = genF(x1, y1, x2, y2);
        F f2 = genF(x3, y3, x4, y4);
        

        auto xD = xDomain(f1, f2);
        int min_x = xD.first, max_x = xD.second;
        auto yD = yDomain(f1, f2);
        int min_y = yD.first, max_y = yD.second;
        
        if(f1.isX && f2.isX) { //平行于y
            if(f1.min_x != f2.min_x) return {};
            if(max_y >= min_y) {
                return {(double) f1.min_x, (double) min_y};
            } else {
                return {};
            }
        }

        if(f1.isY && f2.isY) { //平行于x
            if(f1.min_y != f2.min_y) return {};
            if(max_x >= min_x) {
                return {(double) min_x, (double) f1.min_y} ;
            } else {
                return {};
            }
        }

        if(!f1.isX && !f1.isY && !f2.isX && !f2.isY && isSame(f1.a, f2.a)) { //斜率相同
            if(!isSame(f1.b, f2.b)) {
                return {};
            } else {
                if(max_x >= min_x  && max_y >= min_y) {
                    return {(double) min_x, cal({min_x, 1}, f1)};
                } 
                return {};
            }
        } else {
            vector<double> ans;
            if(f1.isX || f2.isX) { //有一平行于 y
                int x = f1.isX ? x1 : x3;
                double y = f1.isX ? cal({x, 1}, f2) : cal({x, 1}, f1);
                ans = {(double) x, y};
            } else if(f1.isY || f2.isY) {  //有一平行于 x
                int y = f1.isY ? y1 : y3;
                double x = f1.isY ? calX(y, f2) : calX(y, f1);
                ans = {x, (double) y};
            } else {  // 普通相交求解
                pll xp = {f2.a.second * f1.a.second * (f1.b.second * f2.b.first - f2.b.second * f1.b.first), 
                          f2.b.second * f1.b.second * (f2.a.second * f1.a.first - f1.a.second * f2.a.first)  
                };

                double y = cal(xp, f1);
                double x = round((xp.first * 1e6 / xp.second)) / 1e6;
                ans = {x, y};
            }
            if(ans[0] >= min_x && ans[0]<=max_x && ans[1]>=min_y && ans[1]<=max_y) return ans;
        }
        return {};
    }
};


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
