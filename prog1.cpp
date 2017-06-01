
//  Created by James wang on 4/26/17.
//  Copyright © 2017 James wang. All rights reserved.
//

#include "prog1.hpp"
#include <iostream>

TableHeap::TableHeap(){}
TableHeap::TableHeap(const TableHeap &t)
{
    size_heap = t.size_heap;
    for(int i = 1; i <= t.size_heap; i++){
    
            data_heap[i] = t.data_heap[i];
        }
    
    
}

bool TableHeap::insert_hash( int number)
{
    key = number % 97;
    if(key < 0)
        key = key * (-1);
    
    if(list_search(data[key], number) != NULL)
    {
        //std::cout<<number;
        std::cout<<"error: item already exists\n";
        return false;
    }
    
    list_head_insert(data[key], number);
    insert_heap(number);
    size_hash++;
    
    
    return true;
}



bool TableHeap::insert_heap(int number){
    int hole = ++size_heap;
    int copy = number;
    
    data_heap[0] = std::move(copy);
    for(; number > data_heap[hole/2]; hole/=2)
        data_heap[hole] = std::move(data_heap[hole/2]);
    data_heap[hole] = std::move(data_heap[0]);
    return true;
}


int TableHeap::deleteMax_heap(){
    if(size_heap == 0)
        return false;
    int answer = data_heap[1];
    data_heap[1] = std::move (data_heap[size_heap--]);
    percolateDown(1);

    //delete_num_hash(answer);
    return answer;
}

void TableHeap::matchmax(){
    if(size_heap == 0)
    {
        std::cout << "error"<<std::endl;
        return;
    }
    int answer = deleteMax_heap();
    bool link = look_up_hash_no_cout(answer);
    while(link == false){
        if(size_heap == 0)
        {
            std::cout << "error"<<std::endl;
            return;
        }
        answer = deleteMax_heap();
        link = look_up_hash_no_cout(answer);
    }
    delete_num_hash(answer);
    std::cout<< answer<< std::endl;
}

void TableHeap::percolateDown(int hole)
{
    int child;
    int temp = std::move(data_heap[hole]);
    for(;hole*2 <= size_heap; hole = child)
    {
        child = hole * 2;
        if(child != size_heap && data_heap[child +1] > data_heap[child])
            ++child;
        if(data_heap[child] > temp)
            data_heap[hole] = std::move(data_heap[child]);
        else
            break;
        
    }
    data_heap[hole] = std::move(temp);
}



bool TableHeap::lookup_hash(int number)
{
    key = number % 97;
    if(key < 0)
        key = key * (-1);
    if(data[key] == NULL){
        std::cout << number;
        std::cout << " not found\n";
        return false;
    }
    node *a;
    a = list_search(data[key], number);
    if(a == NULL){
        std::cout << number;
        std::cout << " not found\n";
        return false;
    }
    std::cout << "found "<< number <<std::endl;
    return true;
}









bool TableHeap::look_up_hash_no_cout(int number)
{
    key = number % 97;
    if(key < 0)
        key = key * (-1);
    if(data[key] == NULL){
        return false;
    }
    node *a;
    a = list_search(data[key], number);
    if(a == NULL){
        return false;}
    
    return true;
}










bool TableHeap::delete_num_hash(int number)
{
    key = number % 97;
    if(key < 0)
        key = key * (-1);
    
    if(list_search(data[key], number) == NULL){
        //std::cout<<number;
        std::cout<<"error: item not present\n";
        return false;
    }
    else{
        if(data[key]==list_search(data[key], number))
            list_head_remove(data[key]);
        else{
            node *b = data[key];
            while(b ->link() != NULL){
                if(b -> link() == list_search(data[key], number)){
                    list_remove(b);
                    return true;
                }
                b = b->link();
            }
        }
    }
    return true;
}




void TableHeap::print_all()
{
    TableHeap copy(*this);
    int a = size_heap;
    for(int i = 1; i <= a; i++)
    {
        int a = copy.deleteMax_heap();
       
            if(look_up_hash_no_cout(a) == true)
            {
                delete_num_hash(a);
                std::cout << a << " ";
            }
        
    }
    std::cout << std::endl;
}
