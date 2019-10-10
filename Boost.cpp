/*
 *  Problema Práctico 2
 *  Usando librerías de BOOST
 * 
 *  Código hecho por:
 *  Luis Daniel Roa     -   A01021960
 *  Christian Dalma     -   A01423166
 * 
 */

#include <algorithm>
#include <bits/stdc++.h>
#include <chrono>
#include <ctime>
#include <fstream>
#include <iostream>
#include <iterator>
#include <stdlib.h>
#include <tuple>
#include <vector>

#include <boost/config.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/breadth_first_search.hpp>
#include <boost/graph/depth_first_search.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>
#include <boost/graph/exterior_property.hpp>
#include <boost/graph/floyd_warshall_shortest.hpp>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/kruskal_min_spanning_tree.hpp>
#include <boost/graph/prim_minimum_spanning_tree.hpp>
#include <boost/property_map/property_map.hpp>

using namespace boost;
using namespace std;
using namespace std::chrono;

typedef property<vertex_distance_t, int> Vdistance;
typedef property<edge_weight_t, int> EdgeWeight;
typedef adjacency_list <vecS, vecS, bidirectionalS, Vdistance, EdgeWeight> gBoost;
typedef property_map<gBoost, edge_weight_t>::type EdgeWeights;
typedef boost::graph_traits<gBoost>::vertex_descriptor vertex_Boost;
typedef graph_traits<gBoost>::edge_descriptor EDGE;
typedef boost::exterior_vertex_property<gBoost, int> DistanceProperty;
typedef DistanceProperty::matrix_type DistanceMatrix;
typedef DistanceProperty::matrix_map_type DistanceMatrixMap;

class dfsBOOST : public boost::default_dfs_visitor{
  public:

    void discover_vertex(vertex_Boost v, const gBoost) const{
      std::cerr << v << "";

      return;
    }

};

class bfsBOOSt : public boost::default_bfs_visitor{
public:
    void discover_vertex(vertex_Boost v, const gBoost &graf) const{
        std::cerr << v << " ";
        return;
    }
};

class GrafoGral{ 

    public:
        std::vector<std::string> name = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14"};

    gBoost creacionGrafo(){

        std::vector<int> vert = {1,2,3,4,5,6,7,8,9,10,11,12,13,14};
        gBoost graf(vert.size());
        std::vector<int> wght = {8, 8, 8, 7, 4, 7, 9, 4, 6, 2, 3, 1, 2, 6, 3, 3, 2, 4, 10, 6, 8, 6, 2, 9};

        add_edge(1, 3, 8, graf);
        add_edge(1, 4, 8, graf);
        add_edge(3, 2, 7, graf);
        add_edge(3, 5, 8, graf);
        add_edge(3, 10, 4, graf);
        add_edge(2, 5, 7, graf);
        add_edge(5, 6, 9, graf);
        add_edge(6, 13, 4, graf);
        add_edge(13, 14, 6, graf);
        add_edge(14, 13, 2, graf);
        add_edge(4, 7, 3, graf);
        add_edge(4, 5, 1, graf);
        add_edge(4, 8, 2, graf);
        add_edge(7, 4, 6, graf);
        add_edge(8, 7, 3, graf);
        add_edge(8, 9, 3, graf);
        add_edge(9, 10, 2, graf);
        add_edge(9, 12, 4, graf);
        add_edge(10, 3, 10, graf);
        add_edge(10, 6, 6, graf);
        add_edge(12, 11, 8, graf);
        add_edge(11, 12, 6, graf);
        add_edge(12, 9, 2, graf);
        add_edge(12, 14, 9, graf);

        return graf;
    
    }

    gBoost hacerVertice(gBoost g, int v){

        //cout << "Hacer Vertice funciona" << endl;

        return g;

    }

    gBoost hacerArista(gBoost g, int principio, int dest, int peso){

        cout << "Hacer Arista funciona" << endl;

        return g;
    }

    gBoost delVertice(gBoost g, int v){
        
        cout << "Borrar Vertices funciona" << endl;

        return g;        
    }

    gBoost delArista(gBoost g, int principio, int dest){

        cout << "Borrar Aristas funciona" << endl;

        return g;
    }

    gBoost DFS(gBoost g){

        cout << "DFS funciona" << endl;

        return g;
    }

    gBoost BFS(gBoost g, int principio){

        cout << "BFS funciona" << endl;

        return g;
    }

    gBoost Prim(gBoost g){

        cout << "Prim funciona" << endl;

        return g;
    }

    gBoost Kruskal(gBoost g){

        cout << "Kruskal funciona" << endl;

        return g;
    }

    gBoost Dijkstra(gBoost g){

        cout << "Dijkstra funciona" << endl;

        return g;
    }

    gBoost FW(gBoost g){

        cout << "Floyd-Warshall funciona" << endl;

        return g;
    }

};


int main(){

    GrafoGral inicio;
    gBoost graf = inicio.creacionGrafo();

    int opcion;
    
    auto start = high_resolution_clock::now();

    while(1){

        cout << "Nota, todos las funciones están cronometradas" << endl;

        cout << "Seleccione una opción.\n1)Insertar vértice al grafo\n2)Insertar arista en el grafo\n3)Eliminar vértice del grafo\n4)Eliminar arista del grafo\n5)Correr DFS\n6)Correr BFS\n7)Prim\n8)Kruskal\n9)Dijkstra\n10)Floyd-Warshall\n11)Salir del programa" << endl;
        cin >> opcion;
        cout << "\n";


        switch (opcion)
        {
        case 1:
            /*Inserción de vertice*/
            graf= inicio.hacerVertice(graf, 15);

            break;
        
        case 2:
            /* inserción de arista*/
            graf= inicio.hacerArista(graf, 11, 15, 7);

            break;

        case 3:
            /*Eliminar vértice*/
            graf= inicio.delVertice(graf, 15);
            
            break;

        case 4:
            /*Eliminar arista*/
            graf= inicio.delArista(graf, 14 ,11);

            break;

        case 5:
            /*DFS*/
            inicio.DFS(graf);

            break;
        
        case 6:
            /*BFS*/
            inicio.BFS(graf, 1);

            break;

        case 7:
            /*PRIM*/
            inicio.Prim(graf);

            break;

        case 8:
            /*Kruskal*/
            inicio.Kruskal(graf);

            break;
        
        case 9:
            /*Dijkstra*/
            inicio.Dijkstra(graf);

            break;
        
        case 10:
            /*Floyd-Warshall*/
            inicio.FW(graf);

            break;

        case 11:
            cout << "Adiós" << endl;
            exit(0);
            break;

        default:
            cout << "Escoga una opción disponible\n" << endl;
            break;
        }

        auto stop = high_resolution_clock::now();

        auto durationSeg= duration_cast<seconds>(stop - start);
        auto durationMilli = duration_cast<milliseconds>(stop - start);

        cout << "Le tomo " << durationSeg.count() << " segundos\n";
        cout << "Le tomo " << durationMilli.count() << " milisegundos\n";

        cout << "\n";   
    }

    return 0;
}