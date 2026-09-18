class Solution {
public:
    unordered_map<int,string> m = {
    {1,"I"}, {5,"V"}, {10,"X"},
    {50,"L"}, {100,"C"}, {500,"D"}, {1000,"M"}
    };

    int getval(int num,int size){
        for(int i=1;i<size;i++){
            num /= 10;
        }
        if(num>9){
            int col = num/10;
            int multi = col*10;
            num = num-multi;
        }
        return num;
    }
    void identify(string& s,int num,int size,int& index){
        int multi = 1;
        for(int i=1;i<size;i++){
            multi *= 10;
        }
        vector<int>insert;
        if(num<=5){
            if(num==5){
                insert.push_back(5*multi);
            }else if(num==4){
                insert.push_back(1*multi);
                insert.push_back(5*multi);
            }else{
                for(int i=0;i<num;i++){
                    insert.push_back(1*multi);
                }
            }
        }
        else{
            if(num==9){
                insert.push_back(1*multi);
                insert.push_back((1*multi)*10);
            }else{
                insert.push_back(5*multi);
                for(int i=5;i<num;i++){
                    insert.push_back(1*multi);
                }
            }
        }
        for(int i=0;i<insert.size();i++){
            
            s += m[insert[i]][0];
            index++;
        }
    }
    string intToRoman(int num) {
        string s = to_string(num);
        string ans;
        int index = 0;
        for(int i=0;i<s.size();i++){
            int currsize = s.size()-i;
            int val = getval(num,currsize);
            identify(ans,val,currsize,index);
        }
        return ans;
    }
};