#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// to improve the search, a heuristic must be defined for better actions
vector<pair<int, int>> actions = {{2,0},{1,1},{1,0},{0,2},{0,1}};

typedef struct state{
    int missionarie, cannibal, boat;

    bool operator ==(state other){
        return missionarie == other.missionarie &&
               cannibal == other.cannibal &&
               boat == other.boat;
    }
}state;

bool isValid(state state) {
    return (state.missionarie >= 0 && state.cannibal >= 0 &&
            state.missionarie <= 3 && state.cannibal <= 3 &&
            (state.missionarie == 0 || state.missionarie >= state.cannibal));
}

bool isVisited(vector<state> visited, state x) {
    for(int i = 0; i<visited.size(); i++){
        if(visited[i] == x)
            return true;
    }
    return false;
}

vector<state> create_childrens(state current, vector<state> visited){
    vector<state> children;

    for (auto action : actions) {
        state child = current;
        state aux;

        child.missionarie -= action.first;
        child.cannibal -= action.second;
        (child.boat == 1)? child.boat = 0 : child.boat = 1;

        if (isValid(child)) children.push_back(child);

    }
    return children;
}


int search(state shore1, state shore2, int boat, int depth, vector<state> visited){

    if(shore1.cannibal == 0 && shore1.missionarie == 0)
        return depth;

    if (depth > 11) 
        return -1; 

    vector<state> children = create_childrens((boat == 1) ? shore1 : shore2, visited);

    for(auto child : children){
        state temp1 = shore1;
        state temp2 = shore2;
        
        if(boat == 1){
            temp1 = child;
            temp2.missionarie += shore1.missionarie - child.missionarie;
            temp2.cannibal += shore1.cannibal - child.cannibal;
            temp2.boat = 1;
    
        }else{
            temp2 = child;
            temp1.missionarie += shore2.missionarie - child.missionarie;
            temp1.cannibal += shore2.cannibal - child.cannibal;
            temp1.boat = 1;
        }

        if(!isValid(temp1) || !isValid(temp2))
            continue;

        if(isVisited(visited, temp1))
            continue;
        else 
            visited.push_back(temp1);
        
        int result = search(temp1, temp2, (boat == 1) ? 0 : 1, depth + 1, visited);

        if (result != -1) 
            return result;    
    } 

    return -1;
}


int main(){

    for(int i = 0; i<16; i++){
        int depth;
        state shore1, shore2;
        cin >> shore1.missionarie >> shore1.cannibal >> shore1.boat;

        shore2.missionarie = 3 - shore1.missionarie;
        shore2.cannibal = 3 - shore1.cannibal;
        shore2.boat = 0;

        vector<state> visited;
        visited.push_back(shore1);

        if(isValid(shore1) && isValid(shore2))
            depth = search(shore1, shore2, 1, 0, visited);
        else
            depth = -1;

        if (depth != -1)
            cout << "Profundidade da sol: " << depth << endl;
        else 
            cout << "Nao existe sol" << endl;
        
    }

    return 0;
}

