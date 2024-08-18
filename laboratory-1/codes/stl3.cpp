#include <iostream>
#include <queue>
#include <map>

using namespace std;

int main(int argc, char * argv[]){
    
    //     Current   Year   Time
    //        |        |     |        
    // pair<int, pair<int, int> >

    priority_queue<
        pair<int, pair<int, int> >,
        vector<pair<int, pair<int, int> > >,
        greater<pair<int, pair<int, int> > >
    > prio_queue;
    
    while(1){
        string query;
        cin >> query;
        
        if(query == "#")
            break;

        int year, time;
        cin >> year >> time;

        prio_queue.push(make_pair(time, make_pair(year, time)));
    }

    int n_cases;
    cin >> n_cases;

    for(int i = 0; i<n_cases; i++){

        pair<int, pair<int, int> > current;
        current = prio_queue.top();
        prio_queue.pop();

        current.first = current.first + current.second.second; 
        cout << current.second.first << endl;

        prio_queue.push(current);
    }
}