#include<iostream>
using std::cout; using std::endl;
#include<string>
using std::string;
#include<vector>
using std::vector;
#include<algorithm>
using std::copy;
#include<iterator>
using std::ostream_iterator;
#include "functions-05.h"


bool all_lower(string s){
  bool out = true;
  for(int x=0;x< s.length();x++){
    if (isalpha(s[x])){
      if (!islower(s[x])){
	out = false;
      }
    }else{
      out = false;
    }
  }
  return out;
}

bool key_shifts(string key, vector<int> & shifts){
  bool out = true;
  char curr_chr;
  int curr_int;
  int a_int = (int) 'a';
  int diff;
   
  if (all_lower(key)){
    for(int x=0; x< key.length();x++){
      curr_chr = key[x];
      curr_int = (int) curr_chr;
      diff = curr_int - a_int;
      shifts[x] = diff;      
    }    
  }else{
    out = false;
  }
  return key_shifts;
}

string encrypt(string s, vector<int> & shifts){
  string final;
  char curr_chr;
  int curr_int;
  char new_chr;
  int new_int;
  
  if (shifts.size() ==  0){
    final = s;
  }else{
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    for(int x=0;x<s.length();x++){
      if (isalpha(s[x])){
	curr_chr = s[x];
	curr_int = (int) curr_chr;
	new_int = curr_int + shifts[x%4];
	if (new_int > 122){
	  new_int = new_int - 122 + 97;
	}
	new_chr = (char) new_int;  
      }
    }
    final = s;
  }
  return final;
}


string decrypt(string s, vector<int> & shifts){
  string final;
  char curr_chr;
  int curr_int;
  char new_chr;
  int new_int;
  
  if (shifts.size() ==  0){
    final = s;
  }else{
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    for(int x=0;x<s.length();x++){
      if (isalpha(s[x])){
	curr_chr = s[x];
	curr_int = (int) curr_chr;
	new_int = curr_int - shifts[x%4];
	if (new_int < 97){
	  new_int = new_int + 122 - 97;
	}
	new_chr = (char) new_int;  
      }
    }
    final = s;
  }
  return final;
}