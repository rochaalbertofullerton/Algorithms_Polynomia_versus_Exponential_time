///////////////////////////////////////////////////////////////////////////////
// exhaustive_subsequence.hpp
//
// Exhaustive search algorithms for the longest substring, and longest
// subsequence, problems.
//
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <algorithm>
#include <cstdint>
#include <random>
#include <string>

std::string exhaustive_longest_substring(const std::string& a,const std::string& b) {

    std::string best = "" ;
    std::string temp ="";
    if(a.compare(b) == 0){
      return a;
    }
    
    
    for (int i = 0 ; i <= a.length(); i++){
      for(int j = 0; j < a.length() ; j++ ){
        
        temp= a.substr(i , j);
      
        if ((b.find(temp) != std::string::npos)  && temp.length() > best.length()){
          best=temp;
        }
        
      }
      
    }

  return best;
}

std::string random_letter_string(int seed, int size, int distinct_letters) {

  assert(size >= 0);
  assert(distinct_letters > 0);
  assert(distinct_letters <= 26);

  std::string s;

  std::mt19937 gen(seed);
  std::uniform_int_distribution<> dist('a', 'a' + distinct_letters - 1);

  for (int i = 0; i < size; ++i) {
    char ch;
    do {
      ch = dist(gen);
    } while (!isprint(ch));

    s.push_back(ch);
  }

  return s;
}

std::vector<std::string> subset(std:: string a){
  
 std::vector<std::string> subsets;
std::string tempString, temp;

  
  for(int i = 0 ; i < pow(2, a.length()) ; i++){
    for(int j = 0 ; j < a.length() ; j++){
      
      if(i & (1<<j)){
      tempString += a[j];
      }
      
      
    }
    subsets.push_back(tempString);
    tempString.clear();
  }

  return subsets;
  
  
}

bool detect_subsequence(const std::string& candidate_subsequence,
                        const std::string& candidate_supersequence) {


  
  std::vector<std::string> subsets = subset(candidate_supersequence);
  
  for(auto i : subsets){
    
    if (candidate_subsequence.compare(i) == 0) {
      return true;
    }
    
  }
  

  return false;
}




std::string exhaustive_longest_subsequence(const std::string& a,const std::string& b) {

  std::string shorter, longer;
  std::string best = "" ;
  
  if(a.length() < b.length()){
    shorter = a;
    longer = b;
  }
  else{
    shorter = b;
    longer = a;
  }
 std::vector<std::string> subsets = subset(shorter);
  for (auto sub : subsets){
    
    if(detect_subsequence(sub, longer) && sub.length() > best.length()){
      best = sub; 
    }
    
    
  }
  return best;
}

