class Solution {
public:
    int reverseDegree(string s) {
        unordered_map<char,int>m;
        m['a']=26;
        m['b']=25;
        m['c']=24;
        m['d']=23;
        m['e']=22;
        m['f']=21;
        m['g']=20;
        m['h']=19;
        m['i']=18;
        m['j']=17;
        m['k']=16;
        m['l']=15;
        m['m']=14;
        m['n']=13;
        m['o']=12;
        m['p']=11;
        m['q']=10;
        m['r']=9;
        m['s']=8;
        m['t']=7;
        m['u']=6;
        m['v']=5;
        m['w']=4;
        m['x']=3;
        m['y']=2;
        m['z']=1;
        int total = 0;
        for(int i=0;i<s.size();i++){
            total += m[s[i]]*(i+1);
        }
        return total;
    }
};