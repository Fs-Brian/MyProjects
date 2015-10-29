#include "class-08.h"
#include<vector>
using std::vector;
#include<map>
using std::map;
#include<string>
using std::string;
#include<iostream>
using std::ostream;
#include<initializer_list>
using std::initializer_list;
#include <iostream>
#include <fstream>
using std::ifstream;
using std::cout;
using std::endl;
#include<sstream>
#include <iterator>
using std::stringstream;
using std::istream_iterator;

//takes in filename and initializes
Program::Program(string file_name){
    //begins file stream
    ifstream file(file_name);
    string line;
    //checks if can open file
    if(file.is_open()){
        //loops through lien in file
        while(std::getline(file, line)){
            //adds each line to instructions
            instructions_.push_back(line);
        }    
    }
    //initializes index to 0 and status to running    
    instruction_index_ = 0;
    status_ = "running";  

}
//takes in if lock or not    
string Program::get_instruction(bool lock_flag){
    string final;
    //checks if out of instructions by checking if index is bigger than size
    if(lock_flag == 1 && instructions_[instruction_index_] == "lock"){
        final = "waiting";
    }else if (instruction_index_ > instructions_.size() ){
        final = "";
    //checks locked or next instruction is lock
    }else{
        //sets to next instructions
        final = instructions_[instruction_index_];
        instruction_index_ += 1;
    }
    
    return final;    
}
//initializes with list
CPU::CPU(initializer_list<Program> p_list){
    //sets program to the list
    programs_.assign(p_list.begin(), p_list.end());
    //lock flag is false
    lock_flag_ = 0;
    //index is first
    program_index_ = 0;
    //empty memory
    memory_ = {};
    //empty instructions
    current_instruction_ = "";
    //empty isntruction field
    instruction_fields_ = {};
    
}

bool CPU::finished(){
    bool final = true;
    //loops through program to make sure 1 is still running
    for(auto x : programs_){
            if (x.get_status() == "running"){
                final = false;
            }
    }  
    return final;
}

void CPU::run(){
    //loops while not finished
    while(!finished()){
        //sets current instructions
        current_instruction_ = programs_[program_index_].get_instruction(lock_flag_);
        //splits instructions
        split_instruction();
        //executes
        if(programs_[program_index_].get_status() == "running"){
        execute_instruction();
        }
            //checks if should increment or set to 0
            if(program_index_ < (programs_.size() - 1)){
                program_index_ += 1;    
            }else{
                program_index_ = 0;
            }

        
    }
    
    
}

bool CPU::is_assignment(){
    //checks if there is assignment, = sign
    bool final = false;
    if (instruction_fields_[1] == "="){
        final = true;   
    }
    return final;    
}

bool CPU::is_print(){
    //checks if first word is print
    bool final = false;
    if (instruction_fields_[0] == "print"){
        final = true;
    }
    return final;    
}

bool CPU::is_end(){
    //checks if end is first word
    bool final = false;
    if (instruction_fields_[0] == "end" ){
        final = true;
    }
    return final;    
}

bool CPU::is_lock(){
    //checks if lock is first word
    bool final = false;
    if(instruction_fields_[0] == "lock"){
        final = true;
    } 
    return final;
}

bool CPU::is_unlock(){
    //checks if unlock is first word
    bool final = false;
    if(instruction_fields_[0] == "unlock"){
        final = true;
    } 
    return final;    
}

void CPU::split_instruction(){
    //sets the string to the instructions
    string split = current_instruction_;
    //initiates a stringstream
    stringstream ss(split);
    //starts from beginging
    istream_iterator<std::string> begin(ss);
    //goes to the end
    istream_iterator<std::string> end;
    //stores that in vectpr
    vector<string> split_vector(begin, end);
    //sets that vector equal to instruction vector
    instruction_fields_ = split_vector;
}

void CPU::execute_instruction(){
    
    if (is_assignment()){
        bool num = true;
        //makes sure all are digits
        for(auto x : instruction_fields_[2]){
         if( !std::isdigit( x )){
           num = false;   
         } 
        }
        if(num){
        //sets memory to what is asked
        string var = instruction_fields_[0];
        long x = std::stol(instruction_fields_[2]);
        long val = x;
        memory_[var] = val;     
        }else{
            programs_[program_index_].set_status("error");    
        }
    }
    else if (is_print()){
        //checks if variable exists and if size is 2 then prints
        string var = instruction_fields_[1];
        if (memory_.count(var) && instruction_fields_.size() == 2){
            long x = memory_[var];
            string prn = std::to_string(x);
            cout << prn << std::endl;   
        }else{
            programs_[program_index_].set_status("error");
        }
                 
    }
    else if (is_lock()){
        //checks size then changes lock flag
        if (instruction_fields_.size() == 1){
        lock_flag_ = 1;
        }else{
            programs_[program_index_].set_status("error");
        }
    }
    else if (is_unlock()){
        //checks size then changes lock flag
        if (instruction_fields_.size() == 1){
        lock_flag_ = 0;
        }else{
            programs_[program_index_].set_status("error");
        }
    }
    else if (is_end()){
        //checks size then changes status
        if (instruction_fields_.size() == 1){
            programs_[program_index_].set_status("finished");
        }else{
            programs_[program_index_].set_status("error");
        }
        
    }
    else{
        //if all are false, an error occured 
        programs_[program_index_].set_status("error");
    }
    
}