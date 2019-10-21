/*
 *  Problema Práctico 2
 *  Usando librerías de SNAP
 * 
 *  Código hecho por:
 *  Luis Daniel Roa     -   A01021960
 *  Christian Dalma     -   A01423166
 * 
 */


#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <iomanip>
#include "Snap.h"
#include <chrono>
#include <ctime>

#define INF 10000
using namespace std;
using namespace std::chrono;

const int Nodos_num = 15;

PNGraph graph ;

int Valor[Nodos_num][Nodos_num];


void AddVertice(int, int, int);
void AddNodo(int);
void DeleteNodo(int);
void DeleteVertice(int, int);
void DFS(bool[], int);
void BFS(int);
void Dijkstra(int);
void FloydWarshall();

vector <pair <int,int> > GetChildID(int);

void AddNodo(int ID_Nodo){
    graph -> AddNode(ID_Nodo);
}

void DeleteNodo(int ID_Nodo){
    graph->DelNode(ID_Nodo);
}

void AddVertice(int Start, int End, int Peso){
    graph->AddEdge(Start, End);
    Valor[Start][End] = Peso;
}

void DeleteVertice(int Start, int End){
    graph->DelEdge(Start, End);
    Valor[Start][End] = 0;
}



void sortChilds(vector<pair<int,int> >& childs){
    sort(childs.begin(), childs.end(),
        [](const pair<int,int> & a, const pair<int,int> & b) -> bool
    {
    return a.second > b.second;
    });
}

vector<pair<int,int> > GetChildID(int ID_Nodo){
   vector<pair<int,int> > childs;
    TNGraph::TNodeI nodeI = graph->GetNI(ID_Nodo);
    for (int i = 1; i < Nodos_num; i++){
        if (nodeI.IsOutNId(i)){
            childs.push_back(make_pair(i,Valor[ID_Nodo][i]));
        }
    }
    sortChilds(childs);
    return childs;
}


//.................Algoritmos DFS,BFS,Dijkstra y FloydWarshall....................//


void DFS(bool Visitado[], int ID_now){
    if (!Visitado[ID_now]){
        cout << ID_now << endl;
        Visitado[ID_now] = true;
        vector<pair<int,int> > childs = GetChildID(ID_now);

        for (int i = 0; i < childs.size(); i++)
            DFS(Visitado,childs.at(i).first);
    }
}

void BFS(int startId){

    queue<pair<int,int>> q;

    bool Visitado[Nodos_num];
    fill(Visitado, Visitado + Nodos_num, false);

    q.push(make_pair(startId,0));

    while (!q.empty()){

        int ID_now = q.front().first;
        q.pop();

        if (!Visitado[ID_now]){
            cout << ID_now << endl;
            vector<pair<int,int> > childs = GetChildID(ID_now);

            for (int i = 0; i < childs.size(); i++){
                q.push(childs.at(i));
            }
        }
        Visitado[ID_now] = true;
    }
}

void Prim(int startId) {

    queue<pair<int,int> > q;

    bool Visitado[Nodos_num];
    int Distancia[Nodos_num];

    queue<pair<int,int> > ps;
    fill(Visitado, Visitado+Nodos_num, false);
    fill(Distancia, Distancia+Nodos_num,INF);

    q.push(make_pair(startId,0));
    Distancia[startId] = 0;

    while (!q.empty()) {
        int ID_now = q.front().first;
        q.pop();
        if (!Visitado[ID_now]) {
            vector<pair<int,int> > childs = getChildIds(ID_now);
            for (int i = 0; i < childs.size(); i++) {
                if (childs.at(i).second < Distancia[childs.at(i).first]) {
                    if(childs.at(i).first != NULL){
                    Distancia[childs.at(i).first] = childs.at(i).second;
                    q.push(childs.at(i));
                    ps.push(make_pair(i,childs.at(i).second));
                    }
                }
            }
        }
        Visitado[ID_now] = true;
    }

    cout << "Origen \t Parent \t Peso" << endl;
    cout << "   " << 1 << "\t   - \t   INF" << endl;
    int i = 2;  
    while(!ps.empty()) {
        cout << "   " << i << "\t   " << ps.front().second << "\t   " << Distancia[i] << endl;
        ps.pop();
        i++;
        if(i == Nodos_num) break;
    }

}

/*

struct DisjointSets 
{ 
    int *parent, *rnk; 
    int n; 

    DisjointSets(int n) 
    { 
        this->n = n; 
        parent = new int[n+1]; 
        rnk = new int[n+1]; 
  
        for (int i = 0; i <= n; i++) 
        { 
            rnk[i] = 0; 
  
            parent[i] = i; 
        } 
    } 

    int find(int u) 
    { 
 
        if (u != parent[u]) 
            parent[u] = find(parent[u]); 
        return parent[u]; 
    } 
  

    void merge(int x, int y) 
    { 
        x = find(x), y = find(y); 
  

        if (rnk[x] > rnk[y]) 
            parent[y] = x; 
        else 
            parent[x] = y; 
  
        if (rnk[x] == rnk[y]) 
            rnk[y]++; 
    } 
}; 


int Graph::kruskalMST() 
{ 
    int mst_wt = 0; 
  
    sort(edges.begin(), edges.end()); 
  
    DisjointSets ds(V); 
  
    vector< pair<int, iPair> >::iterator it; 
    for (it=edges.begin(); it!=edges.end(); it++) 
    { 
        int u = it->second.first; 
        int v = it->second.second; 
  
        int set_u = ds.find(u); 
        int set_v = ds.find(v); 
  
        
        if (set_u != set_v) 
        { 
            cout << u << " - " << v << endl; 

            mst_wt += it->first; 

            ds.merge(set_u, set_v); 
        } 
    } 
  
    return mst_wt; 
} */



void Dijkstra(int startId){
    queue<pair<int,int>> q;
    bool Visitado[Nodos_num];
    int Distancia[Nodos_num];
    fill(Visitado, Visitado+Nodos_num, false);
    fill(Distancia, Distancia+Nodos_num,INF);

    q.push(make_pair(startId,0));
    Distancia[startId] = 0;

    while (!q.empty()){
        int ID_now = q.front().first;
        q.pop();
        if (!Visitado[ID_now]){
            vector<pair<int,int> > childs = GetChildID(ID_now);
            for (int i = 0; i < childs.size(); i++){
                if (Distancia[ID_now] + childs.at(i).second < Distancia[childs.at(i).first])
                {
                    Distancia[childs.at(i).first] = Distancia[ID_now] + childs.at(i).second;
                    q.push(childs.at(i));
                }
            }
        }
        Visitado[ID_now] = true;
    }

    for (int i = 1; i < Nodos_num; i++){
        cout << "(" << i << ") ";
        if (Distancia[i] == INF) cout << "INF";
        else cout << Distancia[i];
        cout << endl;
    }
}

void FloydWarshall(){
    int table[Nodos_num][Nodos_num];
    for (int i = 1; i < Nodos_num; i++){
        for (int j = 1; j < Nodos_num; j++){
            table[j][i] = Valor[j][i];
            if (table[j][i] == 0) table[j][i] = INF;
            if (j == i) table[j][i] = 0;
        }
    }
    for (int i = 1; i < Nodos_num; i++){
        for (int j = 1; j < Nodos_num; j++){
            for (int k = 1; k < Nodos_num; k++){
                if (table[i][j] + table[k][i]< table[k][j]){
                    table[k][j] = table[i][j] + table[k][i];
                }
            }
        }
    }

    for (int i = 1; i < Nodos_num; i++){
        for (int j = 1; j < Nodos_num; j++){
            if (table[j][i] == INF) cout << "||";
            else{
                if (table[j][i] == 0) cout << "  ";
                else cout << setfill('0') << setw(2) << table[j][i];
            }
            cout << " ";
        }
        cout << endl;
    }

}


int main(int argc, char* argv[]){
    //Inicializar grafo


    graph = TNGraph::New();
    for (int i = 1; i < Nodos_num; ++i)
        AddNodo(i);

    AddVertice(1 ,3 ,8);
    AddVertice(1 ,4 ,8);
    AddVertice(3 ,2 ,7);
    AddVertice(3 ,5 ,8);
    AddVertice(3 ,10,4);
    AddVertice(2 ,5 ,7);
    AddVertice(4 ,5 ,1);
    AddVertice(4 ,7 ,3);
    AddVertice(4 ,8 ,2);
    AddVertice(5 ,6 ,9);
    AddVertice(6 ,13,4);
    AddVertice(7 ,4 ,6);
    AddVertice(8 ,7 ,3);
    AddVertice(8 ,9 ,3);
    AddVertice(9 ,10,2);
    AddVertice(9 ,12,4);
    AddVertice(10,3 ,10);
    AddVertice(10,6 ,6);
    AddVertice(11,12,6);
    AddVertice(12,9 ,2);
    AddVertice(12,11,8);
    AddVertice(12,14,9);
    AddVertice(13,14,6);
    AddVertice(14,13,2);
/*
    AddNodo(ID_Nodo);
    DeleteNodo(ID_Nodo);
    AddVertice(Start, End, Peso)
    DeleteVertice(Start, End, Peso)


*/
    // algoritmos

    bool Visitado[Nodos_num];
    fill(Visitado, Visitado+Nodos_num, false);

    cout << "Algoritmo DFS:" << endl;
    auto start = high_resolution_clock::now();
    DFS(Visitado,1);
    auto stop = high_resolution_clock::now();

    /*
    cout << endl << "Algoritmo BFS" << endl;
    auto start = high_resolution_clock::now();
    BFS(1);
    auto stop = high_resolution_clock::now();

    cout << endl << "Algoritmo Dijkstra" << endl;
    auto start = high_resolution_clock::now();
    Dijkstra(1);
    auto stop = high_resolution_clock::now();

    cout << endl << "-Algoritmo de Floyd Warshall" << endl;
    auto start = high_resolution_clock::now();
    FloydWarshall();
    auto stop = high_resolution_clock::now();

    cout << endl << "-Algoritmo de prim" << endl;
    auto start = high_resolution_clock::now();
    Prim(1);
    auto stop = high_resolution_clock::now();

    cout << endl << "-Algoritmo de prim" << endl;
    auto start = high_resolution_clock::now();
    
    int mst_wt = g.kruskalMST(); 
  
    cout << "\nWeight of MST is " << mst_wt; 
    auto stop = high_resolution_clock::now();

    */

    auto durationSeg = duration_cast<seconds>(stop - start);
        auto durationMilli = duration_cast<milliseconds>(stop - start);
        auto durationMicro = duration_cast<microseconds>(stop - start);

        cout << "Le tomo " << durationSeg.count() << " segundos\n";
        cout << "Le tomo " << durationMilli.count() << " milisegundos\n";
        cout << "Le tomo " << durationMicro.count() << " microsegundos\n" << endl;
}

