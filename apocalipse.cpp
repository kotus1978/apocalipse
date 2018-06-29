#include"apocalipse.h"

Apocalipse_Random::
 Apocalipse_Random(size_t beg_distr,size_t end_distr,size_t limit_redistr):begin_of_distribution(beg_distr),
 end_of_distribution(end_distr),redistribution_limit(limit_redistr)
 {
    if (values.size()<=redistribution_limit)
    {

      for (size_t j = 0 ; j < redistribution_limit ; j++) 
      {

       for ( size_t i = begin_of_distribution 
		; i < end_of_distribution ; ++i )

       {
         values.push_back(i);
       }
       std::random_shuffle(values.begin(),values.end());
      }
    }


 }

  int 
  Apocalipse_Random::
  index(void)
  {
	  time_t _timer;
	  struct tm test;
	  test.tm_hour = 0;   test.tm_min = 0; test.tm_sec = 0;
	  test.tm_year = 100; test.tm_mon = 0; test.tm_mday = 1;
	  time(&_timer);
	  double seconds = difftime(_timer, mktime(&test));
	  double test_f = cos(seconds* PI / 180);
	  size_t index = int(test_f * 100);
	  if (index < 0) { index = index * (-1); };
	  if (index >= end_of_distribution) 
	  {
		  index = rand()%end_of_distribution;
	  };
	  return (index);
  }

  int 
  Apocalipse_Random::
  get_element(void)
  { 
    std::random_shuffle(values.begin(),values.end());
    int value = 0 ;
   	size_t i_ix = index();
   	size_t ii_ix = index();
	if (i_ix > ii_ix)
    {   
      size_t i_loc = index();
      if (i_loc < 1)  i_loc =1 + rand()%4; 
      std::reverse(values.begin(), 
        values.begin() + (values.size() / i_loc)
        );  
      std::random_shuffle(values.begin(),values.end());
      value = values[index()];
	 // printf("[1]\n");
    }
    else 
    {
	  std::rotate(values.begin(),values.begin()+ (values.size()/2),values.end());
      std::random_shuffle(values.begin(),values.end());
	  value = values[index()];
	 // printf("[2]\n");
	} 
    return (value);
  }

int Apocalipse_Random::
  replication(int X,int Y,int Z,int Trash)
  {
    int result_A = (X*Y) & ~X & Z;
    int result_B = (X*Y) & (X*Z) &(Y*Z);
    int result_C = result_A ^ result_B ^ Z;
    return ( result_C | result_A | result_B ); 
  }
  
size_t Apocalipse_Random::
  shift(unsigned int x ,unsigned int k)
  {
   // printf("k = %d\n",k);  
    size_t r = (x >> k) | (x <<  k)  ;   
    return ( r );  
      
  } 