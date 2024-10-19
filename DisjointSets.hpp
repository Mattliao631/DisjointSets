#pragma once

#include <iostream>
#include <unordered_map>
#include <set>
#include <algorithm>

#include "SetNode.hpp"

using namespace std;

template <class T>
class DisjointSets {
public:
    void MakeSet(T* data) {
        if (nodes.find(data) != nodes.end()) return;
        SetNode<T>* node = new SetNode<T>(data);
        nodes[data] = node;
    }
    T* FindSet(T* data) {
        SetNode<T> *node = nodes[data];
        return findSet(node)->data;
    }
    void Union(T* x, T* y) {
        SetNode<T>* xNode = nodes[x];
        SetNode<T>* yNode = nodes[y];
        SetNode<T>* large = findSet(xNode);
        SetNode<T>* small = findSet(yNode);

        if (large == small) return;

        if ((large->rank) < (small->rank)) {
            swap(large, small);
        } else if (large->rank == small->rank) {
            large->rank++;
        }
        swap(small->successor, large->successor);
        small->parent = large;
    }
    void PrintSet(T* data) {
        SetNode<T>* node = nodes[data];
        printSet(node);
    }
    void PrintAllSets() {
        set<SetNode<T>*> printed;
        for (auto it = nodes.begin(); it != nodes.end(); it++) {
            SetNode<T>* node = findSet(it->second);
            SetNode<T>* temp = node;
            if (printed.find(node) == printed.end()) {
                printSet(node);
                cout << endl;
                printed.insert(node);
            }
        }
    }
private:
    unordered_map<T*, SetNode<T>*> nodes;
    SetNode<T>* findSet(SetNode<T>* node) {
        if (node->parent == node) return node;
        node->parent = findSet(node->parent);
        return node->parent;
    }

    void printSet(SetNode<T>* node) {
        SetNode<T>* temp = node;
        do {
            cout << *(node->data) << " ";
            node = node->successor;
        } while(temp != node);
    }
};