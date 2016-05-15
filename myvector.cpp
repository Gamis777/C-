#include <iostream>
using namespace std;
/*实现vector容器,增加两个函数:find sort sort(FUN)*/
template <class T>
class myvector
{
typedef bool (*sortfunction)(T a,T b);
public:
	/*定义迭代器*/
	typedef T* iterator;
	typedef const T* const_iterator;
	typedef T* reverse_iterator;

	/*构造函数*/
	myvector()
	{
		pstr=NULL;
		my_size=0;
		my_capacity=0;
	}

	myvector(int num,T value)
	{
		my_size=num;
		my_capacity=2*my_size;
		pstr=new T[my_capacity];
		int i;
		for(i=0;i<my_size;i++)
		{
			pstr[i]=value;
		}
	}

    /*vector(from) - 构造一个与vector from 相同的vector */
	myvector(const myvector<T> &v)
	{
		myvector<int> v1(10,7);
		my_size=v.my_size;
		my_capacity=v.my_capacity;
		pstr=new T[my_capacity];
		int i;
		for(i=0;i<my_size;i++)
		{
			pstr[i]=v.pstr[i];
		}
	}
    

    /*迭代器(start)和迭代器(end) */
	myvector(iterator start,iterator end)
	{
		myvector<int> v1(10,7);
		my_size=end-start;
		my_capacity=2*my_size;
		pstr=new T[my_capacity];
		int i;
		int j=start-v1.begin();
		for(i=0;i<my_size;i++)
		{
			pstr[i]=v1.pstr[j];
			j++;
		}
	}

   /*运算符重载*/
    void operator == (myvector m1)
    {
         *this == m1;
    }

    bool operator != (myvector m1)
    {
        return *this != m1;
    }

    bool operator >= (myvector m1)
    {
        int i;
        int num=(this->my_size)<(m1.my_size)?(this->my_size):(m1.my_size);
        for(i=0;i<num;i++)
        {
            if(this->pstr[i]>=m1.pstr[i])
            {
                return *this >= m1;
                break;
            }
        }
    }

    bool operator <= (myvector m1)
    {
        int i;
        int num=(this->my_size)<(m1.my_size)?(this->my_size):(m1.my_size);
        for(i=0;i<num;i++)
        {
            if(this->pstr[i]<=m1.pstr[i])
            {
                return *this <= m1;
                break;
            }
        }
    }

    T operator [](int i)
    {
        return this->pstr[i];
    }

	 /*at() 函数 返回当前Vector指定位置loc的元素的引用.*/
     T& at(int index)
     {
     	if(index>my_size)
     		cout<<"out_of_range,error num:";
     	else
     	{
     		T& a=pstr[index];
     		return a;
     	}     	
     }

     /*back() 函数返回当前vector最末一个元素的引用*/
     T &back()
     {
        T &a=pstr[my_size-1];
        return a;
     }  
    

    /*begin()函数返回一个指向当前vector起始元素的迭代器.*/
	iterator begin()
	{
		return pstr;
	}
    

    /*capacity() 函数 返回当前vector在重新进行内存分配以前所能容纳的元素数量.*/
    int capacity()
    {
    	return my_capacity;
    }

    /*clear()函数删除当前vector中的所有元素*/
    void clear()
    {
    	if(pstr!=NULL)
    	{
    		delete pstr;
    		pstr=NULL;
    	}
    	my_size=0;
    	my_capacity=0;
    }

    /*如果当前vector没有容纳任何元素,则empty()函数返回true,否则返回false*/
    bool empty()
    {
    	if(my_size==0)
    		return true;
    	else
    		return false;
    }

    /*end() 函数返回一个指向当前vector末尾元素的下一位置的迭代器. */   
	iterator end()
	{
		return pstr+my_size;
	}

	/*erase函数要么删作指定位置loc的元素 返回值是指向删除的最后一个元素的下一位置的迭代器*/
    iterator erase(iterator loc)
    {
    	int num=loc-begin();
    	if(num>=my_size)
    	{
    		cout<<"loc is out_of_range"<<endl;
            return end();
    	}
        else
        {
           int i;
           for(i=num;i<my_size-1;i++)
           {
               pstr[i]=pstr[i+1];
           }
           my_size--;
           my_capacity=2*my_size;            
           return loc; 
        }
    }
    
    /*删除区间[start, endl)的所有元素.返回值是指向删除的最后一个元素的下一位置的迭代器*/
    iterator erase(iterator start,iterator endl)
    {
        iterator it;
        erase(start);
        for(it=start+1;it!=endl;it++)
        {
            erase(start);
        }
        return start;
    }

    /*front()函数返回当前vector起始元素的引用*/
    T& front()
    {
    	T &a=pstr[0];
    	return a;
    }

    /*在指定位置loc前插入值为val的元素,返回指向这个元素的迭代器, */
    iterator insert(iterator loc,const T& value)
    {
    	if(loc-end()>0)
    	{
    		push_back(value);
    		return end()-1;
    	}
    	else
    	{
    		my_size=my_size+1;
    		my_capacity=2*my_size;
    		int i=loc-begin();
    		while(i<my_size)
    		{
    			pstr[i+1]=pstr[i];
    			i++;
    		}
    		pstr[loc-begin()]=value;
    		return loc;
    	}
    }


    //在指定位置loc前插入num个值为val的元素 
    iterator insert(iterator loc, int num, const T&value )
    {
    	if(loc-end()>0)
    	{
    		resize(my_size+num,value);
    	}
    	else
    	{
    		my_size=my_size+num;
    		my_capacity=2*my_size;
    		int tmp=loc-begin();
    		int i=tmp;
    		while(i<my_size)
    		{
    			pstr[i+num]=pstr[i];
    			i++;
    		}
    		for(i=tmp;i<tmp+num;i++)
    		{
    			pstr[i]=value;
    		}
    	}
    }

    /*在指定位置loc前插入区间[start, end)的所有元素 */
    void insert( iterator loc,iterator it_start,iterator it_end )
    {
    	int num=it_end-it_start;
    	int i=0;
    	if(loc>end())
    	{
    		while(i<num)
    		{
    			push_back(*it_start);
    			it_start++;
    			i++;
    		}
    	}
    	else
    	{
    		my_size=my_size+num;
    		my_capacity=2*my_size;
    		int tmp=loc-begin();
    		i=tmp;
    		while(i<my_size)
    		{
    			pstr[i+num]=pstr[i];
    			i++;
    		}
    		for(i=tmp;i<tmp+num;i++)
    		{
    			pstr[i]=*it_start;
    			it_start++;
    		}
    	}
    }

   /*resize() 函数改变当前vector的大小为size,且对新创建的元素赋值val*/
   void resize(int size,T value)
   {
       	int num=my_size;
       	my_size=size;
       	my_capacity=2*my_size;
        int i;
        for(i=num;i<my_size;i++)
        {
        	pstr[i]=value;
        }
   }


    /*push_back()添加值为val的元素到当前vector末尾*/
    void push_back(const T& value)
    {
    	if(pstr==NULL)
    	{
    		my_size=1;
    		my_capacity=2*my_size;
    		pstr=new T[my_capacity];
    		*begin()=value;
    	}
    	else
    	{
    		my_size=my_size+1;
    		my_capacity=2*my_size;
    		*(end()-1)=value;
    	}
    }

    /*pop_back()函数删除当前vector最末的一个元素*/
    void pop_back()
    {
    	my_size=my_size-1;
    	my_capacity=2*my_size;   	
    }

    /*rbegin函数返回指向当前vector末尾的逆迭代器.*/
    reverse_iterator rbegin()
    {
    	return end()-1;
    }    

    /*rend()函数返回指向当前vector起始位置的逆迭代器.*/ 
    reverse_iterator rend()
    {
    	return begin();
    }

    /*size() 函数返回当前vector所容纳元素的数目*/
    int size()
    {
    	return my_size;
    }

    /*swap()函数交换当前vector与vector from的元素*/
    void swap(myvector &from)
    {
      if(this->my_size>from.my_size)
      {
      	int tmp=this->my_size;
      	T *ptr=new T[tmp];
      	ptr=this->pstr;
      	this->my_size=from.my_size;
      	this->pstr=from.pstr;
      	from.my_size=tmp;
      	from.pstr=ptr;
      }
    }

    /*find */
    iterator find(iterator it_start,iterator it_end,const T& value)
    {
    	iterator fit;
    	for(fit=it_start;fit!=it_end;fit++)
    	{
    		if(*fit==value)
    		{
    			return fit;
    		}
    		if(fit==it_end-1)
    		{
    			cout<<"not found"<<endl;
    			return end();
    		}   
    	}    	
    }

    /*sort*/
    void sort()
    {
    	int i,j;
    	for(i=0;i<my_size;i++)
    	{
    		for(j=0;j<my_size-i-1;j++)
    		{
    			if(pstr[j]>pstr[j+1])
    			{
    				T tmp=pstr[j];
    				pstr[j]=pstr[j+1];
    				pstr[j+1]=tmp;
    			}
    		}
    	}
    }  

  /*sort FUN()排序谓词*/
    void sort(sortfunction cmp)
    {        
        int i,j;
        for(i=0;i<my_size;i++)
        {
            for(j=0;j<my_size-i-1;j++)
            {
                if(cmp(pstr[j],pstr[j+1]))
                {
                    T tmp=pstr[j];
                    pstr[j]=pstr[j+1];
                    pstr[j+1]=tmp;
                }
            }
        }
    }

private:
	T *pstr;
	int my_size;
	int my_capacity;
};

template<class T>
bool sortfun(T a,T b)
{
    return a<b;
}

int main(int argc, char const *argv[])
{
	myvector<int> v1(4,7);
	myvector<int> v2(1,1);
	//myvector<int> v1;
	v2.push_back(333);
	v2.push_back(3);
	v2.push_back(4);
	v2.push_back(5);
	v2.push_back(44);
	v2.push_back(7);
	v2.push_back(5463);
	v1.push_back(43);
	v1.push_back(565);
	 v1.push_back(7);
	v1.push_back(1223);
	v1.push_back(8989);
   //find(v2.begin(),v2.end(),55);
    //cout<<*v2.find(v2.begin(),v2.end(),5)<<endl;
    myvector<int>::iterator it;	
  // // cout<<*v1.insert(v1.begin()+5,10)<<endl;
  //  v1.insert(v1.begin()+2,v2.begin()+8,v2.end());
    //v1.swap(v2);
    v2.sort(sortfun);
    //cout<<*v2.erase(v2.begin()+2,v2.begin()+5)<<endl;
    //v2.pop_back();
   for(it=v2.begin();it!=v2.end();it++)
   {
   	cout<<*it<<'\t';
   }
   cout<<endl;
// myvector<int> v2(it+2,it+4);
  //cout<<*(v1.begin()+1)<<endl;
  // myvector<int>::iterator loc=v1.begin()+2;
  // cout<<*(v1.erase(loc))<<endl;
  // v1.compare(v2);
	//v1.clear();
	

	//v1.clear();
	//myvector<int>::iterator it=0;
    // for(it=v1.begin();it!=v1.end();it++)
    // {
    // 	cout<<*it<<'\t';
    // }
    // cout<<endl;
   // //v1.compare(v2);

	return 0;
}