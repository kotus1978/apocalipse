#include <algorithm>
#include <vector>
int main(int argc,char *argv[])
{
  std::vector<int> v;
  
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  std::accumulate(v.begin(),v.end(),0);
  
  return (0);
}