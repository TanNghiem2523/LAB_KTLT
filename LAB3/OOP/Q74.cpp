#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
class Integer {
private:
    int val;
public:
    void construct(int val){
        cin>>val;
    }
    void setValue(){
        this->val = val;
    }
    int getValue(){
        return val;
    }
};
int main() {
    
    return 0;
}