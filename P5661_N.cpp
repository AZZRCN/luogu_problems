#include <iostream>
#include <deque>
using namespace std;
class ticket {
public:
int time;
int price;
ticket(int a, int b) {
    time = a; price = b;
};
};
class manager{
    public:
    deque<ticket> tickets;
    void add_ticket(int price,int start) {
        tickets.push_back(ticket(start, price));//45 is const
    }
    void update(int time){
        int pos = 0;
        while(pos < tickets.size()){
            if(tickets[pos].time+45<time){
                tickets.erase(tickets.begin()+pos);
            } else{
                pos++;
            }
        }
    }
};
int main(){
    manager manag;
    int n,a,b,c,sum=0;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a >> b >> c;
        manag.update(c);
        if(a == 0){
            manag.add_ticket(b,c);
            sum += b;
        }
        else{
            deque<ticket>::iterator t = manag.tickets.begin();
            for(;t != manag.tickets.end();t++){
                if(t->price >= b){
                    break;
                }
            }
            if(t == manag.tickets.end()){
                sum += b;
            }
            else{
                manag.tickets.erase(t);
            }
        }
    }
    cout << sum << endl;
}