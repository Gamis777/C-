/*
C++:自定义list 

Author：liupei

TIME:2016.3.28
*/
#include <iostream>
using namespace std;

template<class T>
class list;

template<class T>
class node
{
template<class T1>
friend ostream& operator <<(ostream& out,node<T1> n1);
friend class list<T>;
public:
	/*构造...*/
	node()
	{
       
	}   
	node(T _data)
	{
       data=_data;
       next=NULL;
       pre=NULL;
	}
private:
	T data;
	node<T> *next;
	node<T> *pre;
};

template<class T>
ostream& operator <<(ostream& out,node<T> n1)
{
	out<<n1.data<<endl;
	return out;
}

template<class T>
class list
{
typedef bool (*sortfuntion)(T a,T b);
typedef bool (*Unperd)(T a);
typedef bool (*BinPred)(T a);
public:
	class iterator
	{
	friend class list;
	public:
		/*构造...*/
		iterator()
		{
            ptr=NULL;
		}

		iterator(node<T>* _ptr)
		{
			ptr=_ptr;
		}
        
		/*符号重载*/
		void operator =(iterator it)
		{
			this->ptr=it.ptr;
		}

		bool operator !=(iterator it)
		{
			return this->ptr!=it.ptr;
		}

		iterator operator ++(int i)
		{
			iterator it;
			it=*this;
			this->ptr=this->ptr->next;
			return it;
		}

		iterator operator --(int i)
		{
			iterator it;
			it=*this;
			this->ptr=this->ptr->pre;
			return it;
		}
        
        iterator operator -(int num)
        {
        	int i;
			for(i=0;i<num;i++)
			{
				this->ptr=this->ptr->pre;
			}
			return *this;
        }

		iterator operator +(int num)
		{
			int i;
			for(i=0;i<num;i++)
			{
				this->ptr=this->ptr->next;
			}
			return *this;

		}

		node<T> operator *()
		{
			return *(this->ptr);
		}
	private:
		node<T> *ptr;
	};

	class reverse_iterator
	{
	friend class list;
	public:
		/*构造...*/
		reverse_iterator()
		{
            ptr=NULL;
		}

		reverse_iterator(node<T>* _ptr)
		{
			ptr=_ptr;
		}

		void operator =(reverse_iterator it)
		{
			this->ptr=it.ptr;
		}

		bool operator !=(reverse_iterator it)
		{
			return this->ptr!=it.ptr;
		}

		reverse_iterator operator ++(int i)
		{
			reverse_iterator it;
			it=*this;
			this->ptr=this->ptr->pre;
			return it;
		}

		reverse_iterator operator --(int i)
		{
			reverse_iterator it;
			it=*this;
			this->ptr=this->ptr->next;
			return it;
		}
        
        reverse_iterator operator -(int num)
        {
        	int i;
			for(i=0;i<num;i++)
			{
				this->ptr=this->ptr->next;
			}
			return *this;
        }

		reverse_iterator operator +(int num)
		{
			int i;
			for(i=0;i<num;i++)
			{
				this->ptr=this->ptr->pre;
			}
			return *this;

		}

		node<T> operator *()
		{
			return *(this->ptr);
		}
	private:
		node<T> *ptr;
	};

    /*构造...*/
	list()
	{
		head=NULL;
		curr=NULL;
	}

	list(int num,T value)
	{
		head=NULL;
		curr=NULL;
		node<T>* newnode=NULL;
		int i;
		for(i=0;i<num;i++)
		{
			newnode=new node<T>(value);
			if(head==NULL)
			{
				head=newnode;
				curr=head;
			}
			else
			{
				curr->next=newnode;
			    newnode->pre=curr;
				curr=newnode;
			}
			newnode=NULL;
		}
	}

	//list<T>(list.begin(),list.end())
	list(iterator start,iterator endl)
	{
		head=NULL;
		curr=NULL;
		iterator it;
		for(it=start;it!=endl;it++)
		{
			node<T>* newnode=new node<T>;
			newnode=it.ptr;
			if(head==NULL)
			{
				head=newnode;
				curr=head;
			}
			else
			{
				curr->next=newnode;
				newnode->pre=curr;
				curr=newnode;
				newnode=NULL;
			}
		}
	}

	//mylist(const myvector& vsour)
    list(list<T>& from)
    {
    	head=NULL;
		curr=NULL;
		iterator it;
		for(it=from.begin();it!=from.end();it++)
		{
			node<T>* newnode=new node<T>;
			newnode=it.ptr;
			if(head==NULL)
			{
				head=newnode;
				curr=head;
			}
			else
			{
				curr->next=newnode;
				newnode->pre=curr;
				curr=newnode;
				newnode=NULL;
			}
		}
	}

	/*assign()函数以迭代器start和endl指示的范围为list赋值*/
	void assign( iterator start, iterator endl )
	{
		iterator it = start;
		while( it != endl )
		{
			node<T>* newnode = new node<T>( it.ptr->data );
			if( head == NULL )
			{
				head = newnode;
				curr = newnode;
			}
			else
			{
				curr->next = newnode;
				curr = newnode;
				newnode = NULL;
			}
			it++;
		}
	}

	/*assign()函数为list赋值num个以val为值的元素*/
	 void assign( int num, const T &value )
	 {
	 	int i;
	 	for( i=0;i<num;i++ )
	 	{
	 		node<T>* newnode = new node<T>(value);
	 		if( head == NULL)
	 		{
	 			head = newnode;
	 			curr = newnode;
	 		}
	 		else
	 		{
	 			curr->next = newnode;
	 			curr = newnode;
	 			newnode = NULL;
	 		}
	 	}
	 }
    

    /*back()函数返回一个引用，指向list的最后一个元素*/
     T & back()  
    {
    	if(curr->next==NULL)
    	{
    		T & a = curr->data;
    		return a;
    	}
    }

    /*begin()函数返回一个迭代器，指向list的第一个元素*/
	iterator begin()
	{
		return iterator(head);
	}
    
    /*clear()函数删除list的所有元素*/
    void clear()
    {
    	while( head != NULL )
    	{
    		node<T>* tmp = new node<T>;
    		tmp = head;
    		head = head->next;
    		delete tmp;
    		tmp = NULL;
    	}
    }

    /*empty()函数返回真(true)如果链表为空，否则返回假*/
    bool empty()
    {
    	int ret = size(begin(),end());
    	if(ret == 0)
    	{
    		return true;
    	}
    	else
    	{
    		return false;
    	}
    }
    
    /*end()函数返回一个迭代器，指向链表的末尾*/
	iterator end()
	{
		return iterator();
	}

	/*erase()函数删除以pos指示位置的元素 返回值指向最后一个被删除元素的下一个元素*/
    iterator erase( iterator pos )
    {

    	if(pos.ptr==begin().ptr)
    	{
    		node<T>* tmp=new node<T>(head->data);
    		head=head->next;
    		delete tmp;
    		tmp=NULL;
    		return pos+1;
    	}
        
        int num1=size(begin(),pos);
    	int num2=size(begin(),end());
    	if(num1==num2-1)
    	{
    		pop_back();
    	}

    	else
    	{
    		node<T>* tmp=new node<T>(pos.ptr->data);
    		pos.ptr->pre->next=pos.ptr->next;
    		delete tmp;
    		tmp=NULL;
    		return pos+1;
    	}
    }

     /*erase()函数删除start和end之间的元素，返回值指向最后一个被删除元素的下一个元素*/
     iterator erase( iterator start, iterator endl )
     {
        iterator it;
        for(it=start;it!=endl;it++)
        {
            erase(it);
        }
        return it+1;
     }
     
    /*max_size()函数返回链表能够储存的元素数目*/
    int size(iterator start,iterator fin) 
    {
    	int len=0;
    	iterator it;
    	for(it=start;it!=fin;it++)
    	{
    		len++;
    	}
    	return len;
    }
    

    /*rbegin()函数返回一个逆向迭代器，指向链表的末尾*/
	reverse_iterator rbegain()
	{
		return reverse_iterator();
	}
    
    /*rbegin()函数返回一个逆向迭代器，指向链表的末尾*/
	reverse_iterator rend()
	{
		return reverse_iterator(head);
	}
    
    /*push_front()函数将val连接到链表的头部*/
	void push_front(T value)
	{
		node<T>* newnode=new node<T>(value);
		node<T>* tmp=new node<T>;
		tmp=head;
		head=newnode;
		newnode->next=tmp;
	}
    
    /*push_back()将val连接到链表的最后*/
    void push_back(T value)
    {
    	node<T>* newnode=new node<T>(value);
    	if(curr->next==NULL)
    	{
    		curr->next=newnode;
    		newnode->pre=curr;
    		curr=newnode;
    		curr->next=NULL;
    	}
    }
    
    /*front()函数返回一个引用，指向链表的第一个元素*/
    T & front()
    {
    	T & a=head->data;
    	return a;
    }

   /*pop_back()函数删除链表的最后一个元素*/
    void pop_back()
    {
    	if(curr->next==NULL)
    	{
    		node<T>* tmp = curr;
            curr->pre->next = NULL;
            curr = curr->pre;
            delete tmp;
            tmp = NULL;
    	}
    }

    /*pop_front()函数删除链表的第一个元素*/
    void pop_front()
    {
    	node<T>* tmp = new node<T>;
    	tmp = head;
    	head = head->next;
    	delete tmp;
    	tmp = NULL;
    }

    /*remove()函数删除链表中所有值为val的元素*///???
    void _remove(const T & value)
    {
        while(head->data == value)
    	{
    		pop_front();
    	}
    	
        curr = head->next;
        while(curr->next != NULL)
        {
        	node<T>* tmp = new node<T>;
            tmp = curr;
            if(curr->data == value)
            {
          	    curr->pre->next = curr->next;
          	    curr->next->pre = curr->pre;
          	    delete curr;
          	    curr = NULL;
            }
            curr = tmp->next;
    	}

    	if(curr->data == value)
    	{
            pop_back();
    	}    	
    }

    /*remove_if()以一元谓词pr为判断元素的依据，遍历整个链表。如果pr返回true则删除该元素*/
    void remove_if(Unperd pr)
    {
        while(pr(head->data))
        {
            pop_front();
        }
        
        curr = head->next;
        while(curr->next != NULL)
        {
            node<T>* tmp = new node<T>;
            tmp = curr;
            if(pr(curr->data))
            {
                curr->pre->next = curr->next;
                curr->next->pre = curr->pre;
                delete curr;
                curr = NULL;
            }
            curr = tmp->next;
        }

        if(pr(curr->data))
        {
            pop_back();
        }       
    }

  
    /*查找指定的值是否存在*/
    iterator find(const T value )
    {
    	iterator it;
    	int flag;
    	for(it=begin();it!=end();it++)
    	{
    		if(it.ptr->data==value)
    		{
    			flag=1;
    			break;
    		}
    		else
    		{
    			flag=0;
    		}
    	}
        if(flag==1)
        {
        	return it;
        }
        else
        {
            cout<<"not found"<<endl;
            return end();
        }       
    }

    
    

    //*插入一个元素在指定元素前面*/
    iterator insert(iterator pos,const T & value)
    {
    	if(pos.ptr==begin().ptr)
    	{
    		push_front(value);
    	}
    	else
    	{
            if(pos.ptr==end().ptr)
            {
                push_back(value);
            }
            else
            {
                node<T> *newnode=new node<T>(value);
                pos.ptr->pre->next=newnode;
                newnode->next=pos.ptr;
                pos.ptr->pre=newnode;
            }
    	} 
        return pos;      
    }

    
    /*insert()插入元素val到位置pos，或者插入num个元素val到pos之前*/
    void insert(iterator pos,int num,const T & value)
    {
    	int i;
    	if(pos.ptr==begin().ptr)
    	{
    		for(i=0;i<num;i++)
    		{
    			push_front(value);
    		}
    	}
    	
    	else
    	{
            if(pos.ptr==end().ptr)
            {
                for(i=0;i<num;i++)
                {
                    push_back(value);
                }
            }
            else
            {
                for(i=0;i<num;i++)
               {
                   node<T> *newnode=new node<T>(value);
                   pos.ptr->pre->next=newnode;
                   newnode->next=pos.ptr;
                   pos.ptr->pre=newnode;
               }
            }
    	}    	
    }

    /*插入start到end之间的元素到pos的位置*/
    void insert(iterator pos,iterator start,iterator endl)
    {
       iterator it;
       if(pos.ptr==begin().ptr)
       {
            push_front(start.ptr->data);
            curr=head;
            for(it=start+1;it!=endl;it++)
            {
                node<T>* newnode=new node<T>(it.ptr->data);
                node<T>* tmp=curr->next;
                curr->next=newnode;
                newnode->pre=curr;
                curr=newnode;
                curr->next=tmp;
                tmp->pre=newnode;
            }
       }
       else
       {
           if(pos.ptr==end().ptr)
           {
              for(it=start;it!=endl;it++)
              {
                  push_back(it.ptr->data);
              }
            }
          else
          {
              insert(pos,start.ptr->data);
              curr=(pos-1).ptr;
              for(it=start+1;it!=endl;it++)
              {
                  node<T>* newnode=new node<T>(it.ptr->data);
                  node<T>* tmp=curr->next;
                  curr->next=newnode;
                  newnode->pre=curr;
                  curr=newnode;
                  curr->next=tmp;
                  tmp->pre=newnode;
              }
          }

       }
    }
    
    /*sort()函数为链表排序，默认是升序*/
    void sort()
    {

    	T tmp;
    	curr=head;
    	node<T>* small=new node<T>;
    	node<T>* newnode=new node<T>;
    	while(curr!=NULL)
    	{
    		small=curr;
    		newnode=curr->next;
    		while(newnode!=NULL)
    		{
    			if(newnode->data<small->data)
    				small=newnode; 
    			newnode=newnode->next;   			
    		}
    		if(small!=curr)
    		{
    			tmp=curr->data;
    			curr->data=small->data;
    			small->data=tmp;
    		}
    		curr=curr->next;
    	}
    }
    
    /*如果指定compfunction的话，就采用指定函数来判定两个元素的大小*/
    void sort(sortfuntion cmp) 
    {
    	T tmp;
    	curr=head;
    	node<T>* small=new node<T>;
    	node<T>* newnode=new node<T>;
    	while(curr!=NULL)
    	{
    		small=curr;
    		newnode=curr->next;
    		while(newnode!=NULL)
    		{
    			if(cmp(newnode->data,small->data))
    				small=newnode; 
    			newnode=newnode->next;   			
    		}
    		if(small!=curr)
    		{
    			tmp=curr->data;
    			curr->data=small->data;
    			small->data=tmp;
    		}
    		curr=curr->next;
    	}
    }

   /*unique()函数删除链表中所有重复的元素*/
    void unique()
    {
         while(head->data==head->next->data)
         {
            pop_front();
         }
         curr=head->next;
         while(curr->next!=NULL)
         {
            if(curr->data==curr->next->data)
            {
               node<T>* tmp=curr;
               curr->pre->next=curr->next;
               curr->next->pre=curr->pre;
               delete tmp;
               tmp=NULL;
            }
            curr=curr->next;
         }
    }

    /*如果指定pr，则使用pr来判定是否删除*/
     void unique( BinPred pr )
     {
        while(head->data==head->next->data && pr(head->data))
         {
            pop_front();
         }
         curr=head->next;
         while(curr->next!=NULL)
         {
            if(curr->data==curr->next->data && pr(curr->data))
            {
               node<T>* tmp=curr;
               curr->pre->next=curr->next;
               curr->next->pre=curr->pre;
               delete tmp;
               tmp=NULL;
            }
            curr=curr->next;
         }
     }

    /*resize()函数把list的大小改变到num。被加入的多余的元素都被赋值为val*/
    void resize(int num,T value)
    {
    	int n1=size(begin(),end());
    	int tmp=num-n1;
    	int i;
    	for(i=0;i<tmp;i++)
    	{
    		push_back(value);
    	}
    }

    /*reverse()函数把list所有元素倒转*/
    void reverse()
    {
    	if(curr->next == NULL)
    	{
             node<T>* tmp = curr;
             curr = head;
    	    while(curr != tmp)
    	    {
    	    	node<T>* tmp1 = new node<T>(curr->data);
    	    	curr->data = tmp->data;
    	    	tmp->data = tmp1->data;
    	    	curr = curr->next;
    	    	tmp = tmp->pre;
    	    }
    	}
    }

    /*splice()函数把from连接到pos的位置*/
    void splice( iterator pos, list &from )
    {
       iterator it;
       if(pos.ptr==begin().ptr)
       {
            curr=head;
            for(it=from.begin();it!=from.end();it++)
            {
                node<T>* newnode=new node<T>(it.ptr->data);
                node<T>* tmp=curr->next;
                curr->next=newnode;
                newnode->pre=curr;
                curr=newnode;
                curr->next=tmp;
                tmp->pre=newnode;
            }
       }
       else
       {
           if(pos.ptr==end().ptr)
           {
              for(it=from.begin();it!=from.end();it++)
              {
                  push_back(it.ptr->data);
              }
            }
          else
          {
              curr=pos.ptr;
              for(it=from.begin();it!=from.end();it++)
              {
                  node<T>* newnode=new node<T>(it.ptr->data);
                  node<T>* tmp=curr->next;
                  curr->next=newnode;
                  newnode->pre=curr;
                  curr=newnode;
                  curr->next=tmp;
                  tmp->pre=newnode;
              }
          }
       }
    }

    /*如果指定其他参数，则插入lst中del所指元素到现链表的pos上*/
    void splice( iterator pos, list &from, iterator del )
    {
        if(pos.ptr==end().ptr)
        {
            push_back(del.ptr->data);
        }
        else
        {
             node<T>*newnode=new node<T>(del.ptr->data);
             node<T>* tmp=pos.ptr->next;
             pos.ptr->next=newnode;
             newnode->pre=pos.ptr;
             newnode->next=tmp;
             tmp->pre=newnode;
        }
    }

    /*用start和end指定范围*/
    void splice( iterator pos, list &from, iterator start, iterator endl )
    {
               iterator it;
       if(pos.ptr==begin().ptr)
       {
            curr=head;
            for(it=start;it!=endl;it++)
            {
                node<T>* newnode=new node<T>(it.ptr->data);
                node<T>* tmp=curr->next;
                curr->next=newnode;
                newnode->pre=curr;
                curr=newnode;
                curr->next=tmp;
                tmp->pre=newnode;
            }
       }
       else
       {
           if(pos.ptr==end().ptr)
           {
              for(it=start;it!=endl;it++)
              {
                  push_back(it.ptr->data);
              }
            }
          else
          {
              curr=pos.ptr;
              for(it=start;it!=endl;it++)
              {
                  node<T>* newnode=new node<T>(it.ptr->data);
                  node<T>* tmp=curr->next;
                  curr->next=newnode;
                  newnode->pre=curr;
                  curr=newnode;
                  curr->next=tmp;
                  tmp->pre=newnode;
              }
          }
       }
    }
    

    /*swap()函数交换from和现链表中的元素*/
    void swap(list &from)
    {
        int num1=size(begin(),end());   //本链表的元素个数
        int num2=size(from.begin(),from.end());  //from链表的元素个数
        int i;

        if(num1==num2)
        {
            this->curr=this->head;
            from.curr=from.head;
            while(curr!=NULL)
            {
                node<T>*tmp=new node<T>(this->curr->data);
                this->curr->data=from.curr->data;
                from.curr->data=tmp->data;
                curr=curr->next;
                from.curr=from.curr->next;
            }
        }

         if(num1>num2)
        {
            int num=num1-num2;
            int i;
            if(this->curr->next==NULL)
            {
                for(i=0;i<num;i++)
                {
                    curr=curr->pre;
                }
                for(i=0;i<num;i++)
                {
                    curr=curr->next;
                    from.push_back(this->curr->data);
                }
                 for(i=0;i<num;i++)
                {
                    pop_back();
                }
            }
            this->curr=this->head;
            from.curr=from.head;
            while(curr!=NULL)
            {
                node<T>*tmp=new node<T>(this->curr->data);
                this->curr->data=from.curr->data;
                from.curr->data=tmp->data;
                curr=curr->next;
                from.curr=from.curr->next;
            }
        }

         if(num1<num2)
        {
            int num=num2-num1;
            int i;
            if(from.curr->next==NULL)
            {
                for(i=0;i<num;i++)
                {
                    from.curr=from.curr->pre;
                }
                for(i=0;i<num;i++)
                {
                    from.curr=from.curr->next;
                    push_back(from.curr->data);
                }
                 for(i=0;i<num;i++)
                {
                    from.pop_back();
                }
            }
            this->curr=this->head;
            from.curr=from.head;
            while(from.curr!=NULL)
            {
                node<T>*tmp=new node<T>(this->curr->data);
                this->curr->data=from.curr->data;
                from.curr->data=tmp->data;
                curr=curr->next;
                from.curr=from.curr->next;
            }
        }
    }
	
private:
	node<T> *head;
	node<T> *curr;
};

template <class T>
bool fun(T a,T b)
{
   if (a > b)
   	return true;
}

template<class T>
bool isremove(T a)
{ 
	if(a == 17)
		return true;
	else
		return false;
}

template<class T>
bool isunique(T a)
{
    if(a==11)
        return true;
    else
        return false;
}
int main(int argc, char const *argv[])
{
	// list<int> list2(1,10);
	// list2.push_back(7);
	// list2.push_back(54);
	// list2.push_back(3);
	// list2.push_back(7);
	list<int> list1(1,11);
	list1.push_back(12);
	list1.push_back(13);
	list1.push_back(14);
	list1.push_back(15);
    // list1.push_back(16);
    // list1.push_back(17);

	list<int> list2(1,1);
    list2.push_back(2);
    list2.push_back(3);
    list2.push_back(4);
    list2.push_back(5);
    list2.push_back(6);
    list2.push_back(7);
    list2.push_back(8);
    list2.push_back(9);
	//list2.clear();
	//cout<<list2.empty()<<endl;
	//list1.insert(list1.begin(),list2.begin(),list2.end());
	//cout<<*list1.insert(list1.begin(),100)<<endl;;
    //list1.insert(list1.begin(),20);
	//list2.insert_1(list2.begin()+2,100);
	//cout<<list2.size(list2.begin(),list2.end())<<endl;
	//cout<<*list2.find(8)<<endl;
    //cout<<list2.back()<<endl;
   // cout<<*list1.erase(list1.begin(),list1.begin()+2)<<endl;
    ////list1.erase(list1.begin(),list1.begin()+6);
   // list1.sort();
    //list1.unique(isunique);
    //list2.pop_front();
    //list1.remove_if(isremove);
    //list2.resize(20,66);
    list1.swap(list2);
   // list1.splice(list1.begin()+3,list2,list2.begin(),list2.begin()+5);
	list<int>::iterator it;
	for(it=list1.begin();it!=list1.end();it++)
	{
		cout<<*it;
	}
    
    cout<<endl;
    for(it=list2.begin();it!=list2.end();it++)
    {
        cout<<*it;
    }
	return 0;
}