#include <iostream>
#include <cstdio>
#include <ctime>
#include <string>
#include <map>
#include <set>
/*
 * This cpp is for generating random data to test B+ Tree.
 * You can overlook it.
 */
using namespace std;
string rand_str(int len){
    string str;
    char c;
    int idx;
    for(idx = 0; idx < len; ++idx){
        c = 'a' + rand() % 26;
        str.push_back(c);
    }
    return str;
}
string re[100000];int cnt = 0;
map<string, int> table;
int rand_int(){
    int flag = rand() % 2;
    return flag ? rand() : -rand();
}
pair<int, int> rand_pair(){
    return make_pair(rand_int(), rand_int());
}

set<string> KeySet;

signed main(){
    freopen("data.txt", "w", stdout);
    srand((unsigned )time(0));
    string ans;

    int n = 10000;
    cout << n << endl;

    for(int i = 1; i <= n; ++i){
        int op = (int)rand() % 3;
        if(op == 0){//insert
            string rand_key = rand_str(30);
            while(KeySet.find(rand_key) != KeySet.end()){
                rand_key = rand_int();
            }
            re[cnt++] = rand_key;
            ans += "insert ";
            ans += re[cnt - 1];
            ans.push_back(' ');
            table[re[cnt - 1]] = rand_int();
            ans += to_string(table[re[cnt - 1]]);
            cout << ans << endl;
            ans.clear();
        }
        if(op == 1){
            if(!cnt){
                i--;
                continue;
            }
            ans += "find ";
            int num = rand() % cnt;
            ans += re[num];
            cout << ans << endl;
            ans.clear();
        }
        if(op == 2){
            if(!cnt){
                i--;
                continue;
            }
            ans += "delete ";
            int num = rand() % cnt;
            ans += re[num];
            ans += " ";
            ans += to_string(table[re[num]]);
            table.erase(re[num]);
            KeySet.erase(re[num]);
            cnt--;
            for(int j = num; j < cnt; ++j){
                re[j] = re[j + 1];
            }
            cout << ans << endl;
            ans.clear();
        }
    }
}