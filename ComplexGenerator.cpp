//                           #include <algorithm>
#include "ComplexGenerator.h"


ComplexGenerator::
ComplexGenerator(size_t _probability): Apocalipse_Random(0, 37, 100),
probability(_probability),sign_('-'),average(0)
	{
       	real_ = gen_unzero_index();
		i_    = gen_unzero_index();

	};

size_t
ComplexGenerator::
gen_unzero_index(void)
{
    size_t index = get_element();
    while(true)
    {
        if (index > 0)
            break;
      index = get_element();   
    }
    return (index);
}
 
void   
ComplexGenerator::
gen_value(void) 
 {
	
	radius_ =sqrt(( real_ * real_) + (i_ * i_));
	double cos_fi = (radius_ / i_)* PI / 180;
	long a_c  = abs(acos(cos_fi)* (180.0 / PI));
	double sin_fi = (radius_ / real_)* PI / 180;
	long a_s  = abs( asin(sin_fi)* (180.0 / PI));
	std::vector<double> buffer;
	if (a_c > a_s)
	{
		size_t int_rnd = 0;
		size_t multiplicator = 10;
		for (size_t i = a_s,j = a_c; i < a_c + gen_unzero_index()+ gen_unzero_index(); ++i,--j)
		{
			size_t test = i ^ j;
			double rnd_result = (cos(double(test )*PI / 180.0));
			int_rnd = int((rnd_result * multiplicator));		
            if (int_rnd < 1)
				{
                    multiplicator = 100;
 					int_rnd = int((rnd_result * multiplicator));
                    if (int_rnd<0)
                    {
                        int_rnd = gen_unzero_index();
                    }
				}
                
				for (size_t z = 0; z < gen_unzero_index()*(rand()%10); ++z)
                    int_rnd ^= gen_unzero_index();
				
				size_t counter = (gen_unzero_index() % probability) + 1;
                for (size_t j = 0; j < counter ;++j)
                {
                    int replicate = replication(int_rnd,gen_unzero_index(),j,gen_unzero_index())+1;
                    int result_of_operations = int_rnd ^ replicate;//shift(int_rnd,replicate);
					gen_.set_index(gen_unzero_index() % 5);
					size_t gen_res = gen_(gen_unzero_index()%10,int_rnd);
					gen_res = gen_(gen_unzero_index() % 10, gen_res);
					gen_.set_index(gen_unzero_index() % 5);
					gen_res = gen_(gen_unzero_index() % 10, gen_res);
					gen_.set_index(gen_unzero_index() % 5);
					gen_res = gen_(gen_unzero_index() % 10, gen_res);

					result_of_operations += gen_res;

					if (result_of_operations < 0)
					{
					//	__asm{nop }
						result_of_operations = result_of_operations * (-1);
					}
                    //result.push_back(result_of_operations);
                    replicate = replication(int_rnd,gen_unzero_index(),i,gen_unzero_index());
                    result_of_operations = int_rnd^replicate;
					if (result_of_operations < 0)
					{
						//	__asm{nop }
						result_of_operations = result_of_operations * (-1);
					}
					result.push_back(result_of_operations); 
                }
              }
//	debug(0);
    }
    

 
        std::rotate(result.begin(), result.begin() + (result.size() / gen_unzero_index()), result.end());
        std::random_shuffle(result.begin(), result.end());
        std::rotate(result.begin(), result.begin() + (result.size() / gen_unzero_index()), result.end());
        std::random_shuffle(result.begin(),result.end());
        printf("res_sz = %d\n",result.size());
        calculation();
        printf("set_sz = %d\n",set_result.size());
		recalc();
		while (true)
		{
//			debug(2);
            dissolve();
			
            recalc();
          //  debug(4);
			ext_value max = get_max();
		//	printf("=================]\n");
			printf("max(%d,%d)\n", max.count, max.value);
			//printf("average = %d\n",average);
			//getc(stdin);
		//	printf("=================]\n");

			if ((max.count <= average)|| (average < 2))
				break;

		
		}
		printf("average =%d\n", average);
debug(5);
	   

      }
  
void
ComplexGenerator::
recalc(void)
{
	calculation();
	size_t counter = reinit();
	average = counter / set_result.size();
}

size_t
ComplexGenerator::
reinit(void)
{
    uni_result.clear();
    size_t counter = 0;
    std::set< int >::iterator first = set_result.begin();
    std::set< int >::iterator last = set_result.end();
    while(first != last)
    {
       size_t counter_ = std::count(result.begin(),result.end(),*first);  
       counter += counter_;
       int test = (*first);
     //  std::cout << " !!count = " << counter_ << " , val=" << test << std::endl;  
       ext_value e_v(counter_,*first);
       uni_result.push_back( e_v );
       ++first;
    }    
    return(counter);
}

void 
ComplexGenerator::
calculation(void)
{
    set_result.clear();
   for (size_t i = 0 ; i < result.size();++i)
      set_result.insert(result[i]);
}


ext_value
ComplexGenerator::
get_max(void)
{
  ext_value max(0,0);
  for (size_t i = 0; i < uni_result.size();++i)
  {
    if (max.count < uni_result[i].count)
    {
      max = uni_result[i];
    }
  } 
  return ( max );   
}
    
void    
ComplexGenerator::
dissolve(void)
{
  printf("average = %d\n",average); 
  ext_value max = get_max();
 // printf ("max = (%d:%d)\n",max.count,max.value);
  size_t counter = max.count;
  
  for(size_t i = 0 ; i < result.size() ;++ i )
  {
     if ( result[i]!= max.value)
         continue;
  //   printf("i = %d\n",i); 
    if (counter <= average )
    {            
      //  printf("counter[I] = %d\n",counter);
        break;
    }
  

      size_t res_x = replication(result[i],i+gen_unzero_index()%probability,counter*(gen_unzero_index()%2),1000%gen_unzero_index());
     res_x = replication(replication(res_x,result[i],shift( res_x , 30 - (gen_unzero_index()%27) ),counter),res_x,1000%gen_unzero_index(),counter - average);
     res_x = replication(shift( res_x , 30 - (gen_unzero_index()%27) ),res_x,res_x,shift( res_x , 30 - (gen_unzero_index()%27) ));
     size_t reinit = res_x;
     reinit^= gen_unzero_index();//shift( res_x , 30 - (gen_unzero_index()%27) );
	 
     if (reinit != result[i])
	 {
       result[i] = reinit;
	   if (result[i]<0)
       {
         printf("result[%d]=%d\n",i,result[i]);
         getc(stdin);
       }
     }
	 else
	 {
		 printf("SHITTT!!!!!!!!!!\n\n");
		 printf("reinit:%d,result[%d]=%d\n", reinit, i, result[i]);
		// reinit  = + shift(gen_unzero_index() % 27, gen_unzero_index());
        // printf("!!!test = %d\n",test);
         result[i] = (reinit + gen_unzero_index())^counter;
      //   if (0>reinit)
       //      reinit = reinit * (-1);
             
        // result[i] = reinit;
		// getc(stdin);
	 }
	 --counter;
//debug(3); 
  } 

}

void 
ComplexGenerator::
debug(size_t stage)
{
 printf("result.size = %d\n", result.size());
 size_t accumulator_ = std::accumulate(result.begin(),result.end(),0);
 printf("accumulator_ = %d\n" , accumulator_);
 size_t average_product = accumulator_ / result.size();
 printf("average_product = %d\n " , average_product);
 getc(stdin);
 
 for (size_t i =0;i<result.size();++i)
 {
      if (result[i]>average_product)  
      {
		  size_t divider = gen_unzero_index() % 3;
		  if (!divider)
			  divider = 2;
      result[i] = result[i] / divider;
      }
      printf("result[%d] = %d\n",i,result[i]);   
  }   
    
    
}


/*void   
ComplexGenerator::
math_wait(void)
{
       
    
}*/