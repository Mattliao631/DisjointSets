#pragma once

template <class T>
struct SetNode {
    SetNode* parent;
    SetNode* successor;
    T* data;
    int rank;

    SetNode(T* data) : data(data) {
        parent = this;
        successor = nullptr;
        rank = 0;
    }
};