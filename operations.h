#include <vector>
#include <algorithm>

class operators
{
public:
	virtual unsigned int option(unsigned int l_arg, unsigned int r_arg) = 0;
	//virtual ~operators();
};

class common_not_or :public operators
{

public:
	unsigned int option(unsigned int l_arg, unsigned int r_arg)
	{
		return (l_arg ^ r_arg);
	}
	common_not_or()
	{
	}
	~common_not_or()
	{
	}
private:


};

class common_or :public operators
{

public:
	unsigned int option(unsigned int l_arg, unsigned int r_arg)
	{
		return (l_arg | r_arg);
	}
	common_or()
	{
	}
	~common_or()
	{
	}
private:


};



class common_and :public operators
{

public:
	unsigned int option(unsigned int l_arg, unsigned int r_arg)
	{
		return (l_arg & r_arg);
	}
	common_and()
	{
	}
	~common_and()
	{
	}
private:
};


class common_not_inc :public operators
{

public:
	unsigned int option(unsigned int l_arg, unsigned int r_arg)
	{
		size_t res = (l_arg | r_arg);
		++res;
		return (res);
	}
	common_not_inc()
	{
	}
	~common_not_inc()
	{
	}
private:
};

class common_shift_left :public operators
{

public:
	unsigned int option(unsigned int l_arg, unsigned int r_arg)
	{
		return (l_arg << r_arg);
	}
	common_shift_left()
	{
	}
	~common_shift_left()
	{
	}
private:
};


class common_shift_right :public operators
{

public:
	unsigned int option(unsigned int l_arg, unsigned int r_arg)
	{
		return (l_arg << r_arg);
	}
	common_shift_right()
	{
	}
	~common_shift_right()
	{
	}
private:
};




class generator
{
	size_t index_;
	std::vector<operators *> operations;
public:
	generator() 
  {
	  operations.push_back(new common_not_or);
	  operations.push_back(new common_or);
	  operations.push_back(new common_and);
	  operations.push_back(new common_not_inc);
	  operations.push_back(new common_shift_left);
	  operations.push_back(new common_shift_right);
	  std::random_shuffle(operations.begin(), operations.end());
	}
	  
	
  void set_index(size_t index)
  {
	  index_ = index;
  }

  unsigned int operator()(unsigned int l_arg, unsigned int r_arg) throw (std::out_of_range&)
  {
	 return ( operations.at(index_)->option(l_arg , r_arg)
		 );
  }

  ~generator()
  {
	  for (size_t i = 0; i < operations.size(); ++i)
	  delete operations[i];
  }
};


