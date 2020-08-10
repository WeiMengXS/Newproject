class Solution {
public:
    void push(int value) {
        _date.push(value);
        if(_min.size()==0||_min.top()>value)
        {
            _min.push(value);
        }
        else
        {
            _min.push(_min.top());
        }
        
    }
    void pop() {
        _date.pop();
        _min.pop();
    }
    int top() {
        return _date.top();
    }
    int min() {
       return  _min.top();
    }
    private:
    stack<int> _date;
    stack<int> _min;
};
