//https://leetcode.com/problems/employee-importance/

/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int totalImportance = 0;
    int getImportance(vector<Employee*> employees, int id) {
        map<int, vector<int>> emplGraph;
        vector<bool> visited(2005, false);
        map<int, int> emplImportance;
        
        for(auto employee: employees){
            emplImportance[employee->id]=employee->importance;
            for(auto subordinate: employee->subordinates){
                emplGraph[employee->id].push_back(subordinate);
            }
        }
        for(auto emp: emplGraph){
            cout<<emp.first<<endl;
            for(auto subordinate: emp.second){
                cout<<subordinate<<" ";
            }
            cout<<endl;
        }
        
        bfs(id, emplGraph, emplImportance, visited);
        
        return totalImportance;
    }
    
    void bfs(int source, map<int, vector<int>>& emplGraph, map<int, int>& emplImportance, vector<bool>& visited){
        queue<int> bfsQueue;
        bfsQueue.push(source);
        
        while(!bfsQueue.empty()){
            int top = bfsQueue.front();
            cout<<"top="<<top<<endl;
            bfsQueue.pop();
            visited[top]=true;
            totalImportance+=emplImportance[top];
            if(emplGraph.find(top)!=emplGraph.end()){
                for(int edge: emplGraph[top]){
                    bfsQueue.push(edge);
                }
            }
        }
        return;
    }
    
    
};
