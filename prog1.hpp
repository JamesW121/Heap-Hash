
//  Created by James wang on 4/26/17.
//  Copyright © 2017 James wang. All rights reserved.
//

#ifndef prog1_hpp
#define prog1_hpp

#include <stdio.h>
#include <vector>
#include "node.hpp"

const int sizeofarray = 300000;
class TableHeap
{
public:
    TableHeap();
    TableHeap(const TableHeap &t);
    bool insert_hash(int number);
    bool insert_heap(int number);
    
    
    bool look_up_hash_no_cout(int number);

    
    
    bool lookup_hash(int number);
    int deleteMax_heap();
    void matchmax();
    bool delete_num_hash(int number);
    void percolateDown(int hole);
    void print_all();
    
private:
    node *data[sizeofarray];
    int size_hash;
    int key;

    int size_heap;
    int data_heap[sizeofarray];
    
};

#endif /* prog1_hpp */
