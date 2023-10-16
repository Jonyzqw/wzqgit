#include <bits/stdc++.h>
int main(){
    int n = 3;
    std::cin>>n;
    std::vector<int>vec(26,0);
    for(int i=0;i<n;i++){
        std::string s;
        std::cin>>s;
        int index = 1;
        for(auto x : s){
            vec[x-'a'] += index;
            index++;
        }
    }

    // std::vector<int>vec = {2,0,2,1,0,3};
    auto it = std::min_element(vec.begin(), vec.end(), [](int a, int b){if(a==0)return false;else if(b==0)return true;else return a<b;});
    std::string str = "";
    int count = std::count_if(vec.begin(), vec.end(), [](int a){return a!=0;});
    // std::cout<<count<<std::endl;
    while(*it){
       int diff = std::distance(vec.begin(), it); 
       str += 'a'+diff;
       vec[diff] = 0;
       it = std::min_element(vec.begin(), vec.end(), [](int a, int b){if(a==0)return false;else if(b==0)return true;else return a<b;});
    //    std::cout<<*it;
       count--;
    }
    std::cout<<str<<std::endl;
    return 0;
}