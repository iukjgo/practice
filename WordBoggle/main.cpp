#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
using namespace std;
/*
 long power(int a, int b)
 {
 if (b == 1)
 {
 return a % 1000000007;
 }
 
 long test = power(a, b/2);
 if (b%2 == 0)
 {
 long ret = (test*test) % 1000000007;
 return ret;
 }
 else
 {
 long ret =(power(a,1) * ((test * test) % 1000000007) % 1000000007);
 return ret;
 }
 }*/

class CharNode {
public:
    CharNode(char value) : value(value), neighbors(8), visited(false) {
    }
    
    vector<CharNode*> neighbors;  // each node has 8 neighbors, starting from 3 o'clock potition rotating c-wise
    char value;
    bool visited;
};

class CharGraph {
public:
    ~CharGraph() {
        delete nodes_map;
        
        for (int i=0; i<nodes.size(); i++)
            delete nodes[i];
        
    }
    CharGraph(){}
    
    CharGraph(vector<vector<char>>& map) {
        
        x_len = (int)map[0].size();
        y_len = (int)map.size();
        
        nodes_map = new vector<vector<CharNode*>>(y_len, vector<CharNode*>(x_len));
        
        for (int y=0; y<y_len; y++)
        {
            for (int x=0; x<x_len; x++)
            {
                CharNode* node = new CharNode(map[y][x]);
                nodes.push_back(node);
                (*nodes_map)[y][x] = node;
            }
        }
        // initialize neighbors
        for (int y=0; y<y_len; y++)
        {
            for (int x=0; x<x_len; x++)
            {
                CharNode* cur = (*nodes_map)[y][x];
                cur->neighbors[0] = getNode(x+1, y);
                cur->neighbors[1] = getNode(x+1, y+1);
                cur->neighbors[2] = getNode(x, y+1);
                cur->neighbors[3] = getNode(x-1, y+1);
                cur->neighbors[4] = getNode(x-1, y);
                cur->neighbors[5] = getNode(x-1, y-1);
                cur->neighbors[6] = getNode(x, y-1);
                cur->neighbors[7] = getNode(x+1, y-1);
            }
        }
    }
    
    string DFS(set<string>& dictionary, int max_depth)
    {
        unordered_set<string> exists;
        for (int i=0; i<nodes.size(); i++)
        {
            DFS(dictionary, exists, nodes[i], "", max_depth);
            clearVisited();
        }
        
        if (exists.size() == 0)
            return "-1";
        
        string result;
        for (set<string>::iterator it = dictionary.begin();
             it != dictionary.end();
             it++)
        {
            string test = (*it);
            if (exists.find(test) != exists.end())
            {
                result += test + " ";
                
            }
        }
        
        return result;
    }
    
    void DFS(set<string>& dictionary, unordered_set<string>& exists, CharNode* curNode, string curStr, int max_depth)
    {
        if (curStr.length() >= max_depth)
            return;
        
        curNode->visited = true;
        curStr = curStr + curNode->value;
        
        if (dictionary.find(curStr) != dictionary.end())
        {
            exists.insert(curStr);
        }
        
        
        for (int i=0; i<8; i++)
        {
            CharNode* nextNode = curNode->neighbors[i];
            if (nextNode && nextNode->visited == false)
            {
                DFS(dictionary, exists, nextNode, curStr, max_depth);
            }
        }
        curNode->visited = false;
    }
    
    
    
    
private:
    void clearVisited()
    {
        for (int i=0; i<nodes.size(); i++)
        {
            nodes[i]->visited = false;
        }
    }
    
    CharNode* getNode(int x, int y)
    {
        if (y < 0 || y >= y_len || x < 0 || x >= x_len)
            return 0;
        return (*nodes_map)[y][x];
    }
    
private:
    vector<CharNode*> nodes;
    vector<vector<CharNode*>>* nodes_map;
    int x_len;
    int y_len;
};

int main() {
    
    int T=0;
    cin >> T;
    for (int i=0; i<T; i++)
    {
        int n = 0;
        cin >> n;
        set<string> dictionary;
        int max_depth=0;
        for (int j=0; j<n; j++)
        {
            string str;
            cin >> str;
            if (str.length() > max_depth)
                max_depth = (int)str.length();
            dictionary.insert(str);
        }
        int y=0;
        int x=0;
        cin >> y >> x;
        vector<vector<char>> map(y, vector<char>(x, char('\0')));
        for (int a=0; a<y; a++)
            for (int b=0; b<x; b++)
            {
                char c;
                cin >> c;
                map[a][b] = c;
            }
        CharGraph graph(map);
        string result = graph.DFS(dictionary, max_depth);
        cout << result << endl;
    }
    
    return 0;
}
