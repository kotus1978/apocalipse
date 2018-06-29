#ifndef COMPLEX_GENERATOR_RND
#define COMPLEX_GENERATOR_RND
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
#include "AlgoGenerator.h"
#include "apocalipse.h"




struct ext_value
{
    size_t count;    
    int value;
    double probability;
    ext_value(size_t count_,int value_):count(count_),
    value(value_)
    {};
   /* bool operator < (const ext_value& ex )
    {
       return (count < ex.count);
    }
    
    bool operator > (const ext_value& ex )
    {
       return (count > ex.count);
    }
    
    bool operator == (const ext_value& ex)
    {
       return (count == ex.count);
    }
    
    bool operator !=(const ext_value& ex)
    {
        
       return (count != ex.count); 
    }*/
};
 
 
struct ext_comparator
{
    bool operator()(const ext_value& l_count,
        const ext_value& r_count)
    {  
      return (l_count.count < r_count.count);          
    }
};




class ComplexGenerator:public AlgoGenerator,
	protected Apocalipse_Random
{
   int real_;
   int i_;
   char sign_;
   float radius_;
   size_t probability;
   size_t average; 
   std::set< int > set_result;
   std::vector< ext_value > uni_result; 
   std::vector< int > result;
   void calculation(void);
   void dissolve(void);
   size_t reinit(void);
   ext_value get_max(void);
   void recalc(void);
public:
	ComplexGenerator(size_t _probability);
    void gen_value(void);
    unsigned int gen_unzero_index(void);
};

#endif