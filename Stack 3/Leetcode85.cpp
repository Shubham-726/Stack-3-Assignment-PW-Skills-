class Solution {
public:
    int calPoints(vector<string>& op) {
        stack<int>st;
        for(int i = 0; i< op.size(); i++){
            if(op[i].size() > 1 || op[i].size() == 1  && op[i][0] >= '0' && op[i][0] <= '9')
            st.push(stoi(op[i]));
            else if(op[i] == "C") st.pop();
            else if(op[i] == "D"){
                st.push(2*st.top());
            }
            else {
                int val1 = st.top();
                st.pop();
                int val2 = st.top() + val1;
                st.push(val1);
                st.push(val2);
            }
        }
        int sum = 0;
        while(st.size() > 0){
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};