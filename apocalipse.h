#include <stdio.h>
#include <vector>
#include <ctime>
#include <time.h>
#include <algorithm>
#include <math.h> 

#define PI 3.14159265358979323846264

#ifndef APOCALIPSE_RANDOM_CORE
#define APOCALIPSE_RANDOM_CORE

class Apocalipse_Random
{
  size_t begin_of_distribution;
  size_t end_of_distribution;
  size_t redistribution_limit;
  std::vector< int > values;

  public:
  Apocalipse_Random(size_t beg_distr,size_t end_distr,size_t limit_redistr);
  protected:
  int get_element(void);
  int replication(int X,int Y,int Z,int Trash);
  size_t shift(unsigned int x, unsigned int k);
  int index(void);
 };
#endif
