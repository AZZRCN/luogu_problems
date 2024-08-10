#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(void){data=0;next = nullptr;};
};
Node* head[10];
Node* tail[10];
int main(){
    int n;
    cin >> n;
    Node* root = new Node();
    Node* it = root;
    int t;
    for(int i = 1; i <= n; i++){
        cin >> t;
        it->data = t;
        it->next = new Node();
        it = it->next;
    }
    cout << "1" << flush;
    it = root;
    int div = 1;
    int run_time = 3;
    while(run_time--){
        it = root;
        //fen
        while(it!=nullptr){
            if(head[(it->data/div)%10] == nullptr){
                head[(it->data/div)%10] = it;
                tail[(it->data/div)%10] = it;
            }
            else{
                tail[(it->data/div)%10]->next = it;
                tail[(it->data/div)%10] = it;
            }
            it = it->next;
        }
        //show
        cout << "middle" << flush;
        root->next = head[0];
        it = tail[0];
        for(int i = 1; i <= 8; i++){
            if(head[i]!=nullptr){
                it->next = head[i];
                it = tail[i];
            }
        }
        div = div * 10;
    }
    cout << "2" << flush;
    it = root;
    while(it != nullptr){
        cout << it->data;
        it = it->next;
    }
}