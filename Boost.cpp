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
#include <chrono>
#include <ctime>
#include <fstream>
#include <iostream>
#include <iterator>
#include <stdlib.h>
#include <tuple>
#include <vector>
#include "Boost.hpp"

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
typedef adjacency_list<vecS, vecS, bidirectionalS, Vdistance, EdgeWeight> gBoost;
typedef property_map<gBoost, edge_weight_t>::type EdgeWeights;
typedef boost::graph_traits<gBoost>::vertex_descriptor vertex_Boost;
typedef graph_traits<gBoost>::edge_descriptor EDGE;
typedef boost::exterior_vertex_property<gBoost, int> DistanceProperty;
typedef DistanceProperty::matrix_type DistanciaMatrices;
typedef DistanceProperty::matrix_map_type MapaMatrices;

class GrafoGral{ 

    public:
        std::vector<std::string> grafString = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14"};

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

        auto start = high_resolution_clock::now();

        //cout << "Hacer Vertice funciona" << endl;
        vertex_Boost novo;
        novo = add_vertex(g);

        cout << "Vertice " << v << " ha sido insertado \n" << endl;

        auto stop = high_resolution_clock::now();

        auto durationSeg = duration_cast<seconds>(stop - start);
        auto durationMilli = duration_cast<milliseconds>(stop - start);
        auto durationMicro = duration_cast<microseconds>(stop-start);

        cout << "Le tomo " << durationSeg.count() << " segundos\n";
        cout << "Le tomo " << durationMilli.count() << " milisegundos\n";
        cout << "Le tomo " << durationMicro.count() << " microsegundos\n";

        cout << "\n";

        return g;

    }

    gBoost hacerArista(gBoost g, int principio, int dest, int peso){

        auto start = high_resolution_clock::now();

        //cout << "Hacer Arista funciona" << endl;
        add_edge(principio, dest, peso, g);

        auto stop = high_resolution_clock::now();

        cout << "Se añadió la arista " << principio << " exitosamente\n" << endl;

        auto durationSeg = duration_cast<seconds>(stop - start);
        auto durationMilli = duration_cast<milliseconds>(stop - start);
        auto durationMicro = duration_cast<microseconds>(stop - start);

        cout << "Le tomo " << durationSeg.count() << " segundos\n";
        cout << "Le tomo " << durationMilli.count() << " milisegundos\n";
        cout << "Le tomo " << durationMicro.count() << " microsegundos\n";

        cout << "\n";

        return g;
    }

    gBoost delVertice(gBoost g, int v){
        
        auto start = high_resolution_clock::now();

        //cout << "Borrar Vertices funciona" << endl;
        clear_vertex(v, g);
        remove_vertex(v, g);

        auto stop = high_resolution_clock::now();

        cout << "Se removió el vertice " << v << " exitosamente\n" << endl;

        auto durationSeg = duration_cast<seconds>(stop - start);
        auto durationMilli = duration_cast<milliseconds>(stop - start);
        auto durationMicro = duration_cast<microseconds>(stop - start);

        cout << "Le tomo " << durationSeg.count() << " segundos\n";
        cout << "Le tomo " << durationMilli.count() << " milisegundos\n";
        cout << "Le tomo " << durationMicro.count() << " microsegundos\n";

        cout << "\n";

        return g;        
    }

    gBoost delArista(gBoost g, int principio, int dest){

        //cout << "Borrar Aristas funciona" << endl;

        auto start = high_resolution_clock::now();

        remove_edge(principio, dest, g);

        auto stop = high_resolution_clock::now();
        
        cout << "Se removió la arista: " << principio << " exitosamente\n" << endl;

        auto durationSeg = duration_cast<seconds>(stop - start);
        auto durationMilli = duration_cast<milliseconds>(stop - start);
        auto durationMicro = duration_cast<microseconds>(stop - start);

        cout << "Le tomo " << durationSeg.count() << " segundos\n";
        cout << "Le tomo " << durationMilli.count() << " milisegundos\n";
        cout << "Le tomo " << durationMicro.count() << " microsegundos\n";

        cout << "\n";

        return g;
    }

    gBoost DFS(gBoost g){

        //cout << "DFS funciona" << endl;
        dfsBOOST dB;

        auto start = high_resolution_clock::now();

        depth_first_search(g, visitor(dB));

        auto stop = high_resolution_clock::now();

        cout << "\n";

        auto durationSeg = duration_cast<seconds>(stop - start);
        auto durationMilli = duration_cast<milliseconds>(stop - start);
        auto durationMicro = duration_cast<microseconds>(stop - start);

        cout << "Le tomo " << durationSeg.count() << " segundos\n";
        cout << "Le tomo " << durationMilli.count() << " milisegundos\n";
        cout << "Le tomo " << durationMicro.count() << " microsegundos\n";

        cout << "\n";

        return g;
    }

    gBoost BFS(gBoost g, int principio){

        //cout << "BFS funciona" << endl;
        bfsBOOST bfB;

        auto start = high_resolution_clock::now();

        breadth_first_search(g, principio, visitor(bfB));

        auto stop = high_resolution_clock::now();

        cout << "\n";

        auto durationSeg = duration_cast<seconds>(stop - start);
        auto durationMilli = duration_cast<milliseconds>(stop - start);
        auto durationMicro = duration_cast<microseconds>(stop - start);

        cout << "Le tomo " << durationSeg.count() << " segundos\n";
        cout << "Le tomo " << durationMilli.count() << " milisegundos\n";
        cout << "Le tomo " << durationMicro.count() << " microsegundos\n";

        cout << "\n";

        return g;
    }

    gBoost Prim(gBoost g){

        //cout << "Prim funciona" << endl;
        std::vector<vertex_Boost> vertice(num_vertices(g));

        property_map<gBoost, vertex_index_t>::type mapaVertices = get(vertex_index, g);

        property_map<gBoost, vertex_distance_t>::type distanciaVertice = get(vertex_distance, g);

        property_map<gBoost, edge_weight_t>::type pesoEsquema = get(edge_weight, g);

        auto start = high_resolution_clock::now();

        prim_minimum_spanning_tree(g, *vertices(g).first, &vertice[0], distanciaVertice, pesoEsquema,mapaVertices, default_dijkstra_visitor());

        for (int i = 1; i != vertice.size(); ++i)
            if (vertice[i] != i)
                cout << "Nodo padre: " << i << " es igual a " << vertice[i] << endl;
            else
                cout << "Nodo padre " << i << "\nNo hay nodo padre" << endl;
        
        auto stop = high_resolution_clock::now();

        auto durationSeg = duration_cast<seconds>(stop - start);
        auto durationMilli = duration_cast<milliseconds>(stop - start);
        auto durationMicro = duration_cast<microseconds>(stop - start);

        cout << "Le tomo " << durationSeg.count() << " segundos\n";
        cout << "Le tomo " << durationMilli.count() << " milisegundos\n";
        cout << "Le tomo " << durationMicro.count() << " microsegundos\n";

        cout << "\n";

        return g;
    }

    gBoost Kruskal(gBoost g){

        //cout << "Kruskal funciona" << endl;
        property_map<gBoost, edge_weight_t>::type weight = get(edge_weight, g);
        std::vector<EDGE> arbolKruskal;

        auto start = high_resolution_clock::now();

        kruskal_minimum_spanning_tree(g, std::back_inserter(arbolKruskal));

        auto stop = high_resolution_clock::now();

        cout << "Resultado, Kruskal: " << endl;
        for(std::vector<EDGE>::iterator krus = arbolKruskal.begin(); krus != arbolKruskal.end(); ++krus){

            cout << "De " << source(*krus, g) << " a " << target(*krus, g) << "\nTiene un peso de: " << weight[*krus] << "\n" << endl; 
        }

        auto durationSeg = duration_cast<seconds>(stop - start);
        auto durationMilli = duration_cast<milliseconds>(stop - start);
        auto durationMicro = duration_cast<microseconds>(stop - start);

        cout << "Le tomo " << durationSeg.count() << " segundos\n";
        cout << "Le tomo " << durationMilli.count() << " milisegundos\n";
        cout << "Le tomo " << durationMicro.count() << " microsegundos\n";

        cout << "\n";

        return g;
    };

    gBoost Dijkstra(gBoost g){

        //cout << "Dijkstra funciona" << endl;

        std::vector<vertex_Boost> dij(num_vertices(g));
        std::vector<int> kst(num_vertices(g));

        vertex_Boost tra = vertex(1, g);

        property_map<gBoost, vertex_index_t>::type mapa = get(vertex_index, g);

        property_map<gBoost, edge_weight_t>::type pesos = get(edge_weight, g);

        auto start = high_resolution_clock::now();

        dijkstra_shortest_paths(g, tra, &dij[0], &kst[0], pesos, mapa, std::less<int>(), closed_plus<int>(), (std::numeric_limits<int>::max)(), 0, default_dijkstra_visitor());

        auto stop = high_resolution_clock::now();

        graph_traits <gBoost>::vertex_iterator origen, destino;

        for(tie(origen, destino) = vertices(g); origen != destino; ++origen){
            
            cout << "Distancia de: " << grafString[*origen] << " es " << kst[*origen] << " el padre siendo " << grafString[dij[*origen]] << "\n" <<endl;
        
        }

        auto durationSeg = duration_cast<seconds>(stop - start);
        auto durationMilli = duration_cast<milliseconds>(stop - start);
        auto durationMicro = duration_cast<microseconds>(stop - start);

        cout << "Le tomo " << durationSeg.count() << " segundos\n";
        cout << "Le tomo " << durationMilli.count() << " milisegundos\n";
        cout << "Le tomo " << durationMicro.count() << " microsegundos\n" << endl;

        return g;

    };

    gBoost FW(gBoost g){

        //cout << "Floyd-Warshall funciona" << endl;

        auto start = high_resolution_clock::now();

        DistanciaMatrices dist(num_vertices(g));
        MapaMatrices distanciaMat(dist, g);

        property_map<gBoost, edge_weight_t>::type peso = get(edge_weight, g);

        floyd_warshall_all_pairs_shortest_paths(g, distanciaMat, boost::weight_map(peso));

        auto stop = high_resolution_clock::now();

        for(int x = 1; x < num_vertices(g); x++){
            for (int y = 1; y < num_vertices(g); y++)
            {
                cout << "Vertice " << x << " a " << y << endl;
                if (dist[x][y] == std::numeric_limits<int>::max())
                {
                    cout << "Fin" << endl;
                }else{
                    cout << dist[x][y] << "\n" << endl;
                }
                
            }
            
        }

        auto durationSeg = duration_cast<seconds>(stop - start);
        auto durationMilli = duration_cast<milliseconds>(stop - start);
        auto durationMicro = duration_cast<microseconds>(stop - start);

        cout << "Le tomo " << durationSeg.count() << " segundos\n";
        cout << "Le tomo " << durationMilli.count() << " milisegundos\n";
        cout << "Le tomo " << durationMicro.count() << " microsegundos\n" << endl;

        return g;
    }//FIN FLOYD-WARSHALL

};


int main(){

    GrafoGral inicio;
    gBoost graf = inicio.creacionGrafo();

    int opcion;

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

            //Algoritmo tipo ávido
            //Complejidad de O()
            break;

        case 8:
            /*Kruskal*/
            inicio.Kruskal(graf);

            //Algoritmo tipo
            //Complejidad de O()
            break;
        
        case 9:
            /*Dijkstra*/
            inicio.Dijkstra(graf);

            //Algoritmo tipo ávido
            //Complejidad de O()
            break;
        
        case 10:
            /*Floyd-Warshall*/
            inicio.FW(graf);

            //Algoritmo tipo dinámico
            //Complejidad de O(v^3)
            break;

        case 11:
            cout << "Adiós" << endl;
            exit(0);
            break;

        default:
            cout << "Escoja una opción aceptable\n" << endl;
            break;
        }

    }

    return 0;
}