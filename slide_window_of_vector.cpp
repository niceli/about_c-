/*给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。
例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么一
共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}； 针对数组
{2,3,4,2,6,2,5,1}的滑动窗口有以下6个： {[2,3,4],2,6,2,5,1}，
{2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}， {2,3,4,[2,6,2],5,1}，
{2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。
*/
class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> v;
        if(num.size() == 0||num.size()<size||size == 0) return v;
        for(int i=0;i<=num.size()-size;i++){
            int tmp = num[i];
            for(int j=i;j<num.size()&&j-i<size;j++){
				if(num[j]>tmp) tmp = num[j];
            }
            v.push_back(tmp);
        }
        return v;
    }
};
//
class Solution {
public:
    vector<int> maxInWindows(const vector<int>& a, unsigned int k){
        vector<int> res;
        deque<int> s;
        for(unsigned int i = 0; i < a.size(); ++i){
            while(s.size() && a[s.back()] <= a[i]) s.pop_back();
            while(s.size() && i - s.front() + 1 > k) s.pop_front();
            s.push_back(i);
            if(k && i + 1 >= k) res.push_back(a[s.front()]);
        }
        return res;
    }
};
