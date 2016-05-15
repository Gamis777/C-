#include <iostream>
using namespace std;
int N=100;
//参照 标准c++ 字符串类 自定义实现一个好用字符串类

//strlen strcpy strcat strcmp 都要求自己实现

//构造str类

class my_string
{
friend class A;
public:
	//my_strcpy
    char * my_Strcpy(char *dest,char *src)
    {
       int i;
       int len=my_strlen(src);
       for(i=0;i<len;i++)
       {
       	src[i]=dest[i];
       }
        src[len+1]='\0';
    }
    //my_strlen
	int my_strlen(char *dest)
    { 
    	int len=0;
    	while(1)
    	{
           if(dest[len]!='\0')
           {
             len++;
           }
           else
           	break;         
    	}
    	return len;
    }
    
    //my_strcmp
    int my_strcmp(char *dest,char *src)
    {
    	int len1=my_strlen(dest);
    	int len2=my_strlen(src);
    	int flag;
    	int i;
    	if(len1==len2)
    	{
    		for(i=0;i<len1;i++)
    		{
    			if(dest[i]==src[i])
    			{
    				flag=0;
    				break;                   
    			}  
    			if(dest[i]<src[i])
    			{
    				flag=-1;
    				break;
    			}         
    			if(dest[i]>src[i])
    			{
    				flag=1;
    				break;
    			}       
    		}
    	}
    	if(len1<len2)
    	{
    		for(i=0;i<len1;i++)
    		{
    			if(dest[i]==src[i]||dest[i]<src[i])
    			{
    				flag=-1;
    				break;  
    			}
    			if(dest[i]>src[i])
    			{
    				flag=1;
    				break;  
    			}
    		}
    	}
    	if(len1>len2)
    	{
    		for(i=0;i<len2;i++)
    		{
    			if(dest[i]==src[i]||dest[i]>src[i])
    			{
    				flag=1;
    				break;  
    			}
    			if(dest[i]<src[i])
    			{
    				flag=-1;
    				break;  
    			}
    		}
    	}
    	return flag;
    }

    //my_strcat
    char * my_strcat(char *dest,char *src)
    {
        int len1=my_strlen(dest);
        int len2=my_strlen(src);
        if(len1+len2+1<=N)
        {
        	int i;
        	int j;
        	for(i=len1,j=0;i<N,j<len2;i++,j++)
        	{
        		if(src[j]!='\0')
        		{
        			dest[i]=src[j];
        		}
        	    else
        	    	break;
        	}
        	 dest[len1+len2+1]='\0';
        }
        return dest;
    }

	//Constructors 构造函数，用于字符串初始化 
    char* Constructors(char *dest,int len)
    {
    	int i;
    	for(i=0;i<len;i++)
    	{
    		cout<<dest[i];
    	}
    	cout<<endl;
    	return dest;
    }

    //Operators 操作符，用于字符串比较和赋值
    char * Operators(char *dest,char *src)
    {
    	int flag=my_strcmp(dest,src);
    	int len1=my_strlen(dest);
    	int len2=my_strlen(src);
    	if(flag==1)
    		return "dest==src";
    	else
    	{
    		int tmp=len1>len2?len1:len2;
    		int i;
    		for(i=0;i<tmp;i++)
    		{
    			if(dest[i]<src[i])
    			{
    				return "dest<src";
    				break;
    			}
    			if(dest[i]>src[i])
    			{
    				return "dest>src";
    				break;
    			}
    		}
    	}
    }


    char * Operators_link(char *dest,char *src)//+  +=
    {
    	dest=my_strcat(dest,src);
    	return dest;
    }

    // char *Operators_special(char *dest)  //[]  ??
    // {

    // }
    
    //添加文本(append) 
    char *Append(char *dest,char *src,int len)
    {
    	int len1=my_strlen(dest);
    	int i;
    	for(i=len1;i<len1+len;i++)
    	{
    		dest[i]=src[0];
    	}
    	dest[len1+len]='\0';
    	return dest;
    }
    
    //赋值(assign) 
    char *assign(char *dest,char *src,int index,int len)
    {
    	int i,j;
    	int len1=my_strlen(dest);
    	int len2=my_strlen(src);
    	for(i=0;i<len1;i++)
    	{
    		dest[i]='\0';
    	}
    	if(index+len<=len2)
    	{
    	    for(j=0,i=index-1;j<N,i<=index+len;j++,i++)
    	    {
    	    	dest[j]=src[i];
    	    }
    	    dest[index+len+1]='\0';
    	}
    	else
    	{
    		for(j=0,i=index-1;j<N,i<=len2;j++,i++)
    	    {
    	    	dest[j]=src[i];
    	    }
    	    dest[len2+1]='\0';    	
    	}
    	return dest;
    }
    
    //at()函数
    class _throw
    {
    public:
       _throw(char *_msg)
       {
             my_string m;
             m.my_Strcpy(msg,_msg);
       }

       char* output()
       {
       	return msg;
       }
    private:
	   char msg[20];
     	
    };

    char *_at(char *dest,int index)
    {
    	int len1=my_strlen(dest);
    	int i;
    	if(index<=len1)
    	{ 
    		dest[0]=dest[index];
    		dest[1]='\0';
    		return dest;         
    	}
    	else
    	{        
            throw _throw("out of range");
            return "out of range";
    	}
    	
    }
    
    //begin 
    char begin(char *dest)
    {
    	return dest[0];
    }
    
    //c_str()函数返回一个指向正规C字符串的指针, 内容与本字符串相同.

    const char *c_str(char *dest)
    {
    	int len=my_strlen(dest);
    	char *p=new char[len];
    	int i;
    	for(i=0;i<len;i++)
    	{
    		p[i]=dest[i];
    	}
    	return p;
    }

    //capacity()函数返回在重新申请更多的空间前字符串可以容纳的字符数. 这个数字至少与 size()一样大.
    int capacity(char *dest)
    {
    	int len=my_strlen(dest);
    	if(len<N)
    	   return N;
    	else
    		return len;
    }

    //compare()函数以多种方式比较本字符串和str,返回：
    int compare(char *dest,char *src)
    {
    	int len1=my_strlen(dest);
    	int len2=my_strlen(src);
    	int flag;
    	int i;
    	if(len1==len2)
    	{
    		for(i=0;i<len1;i++)
    		{
    			if(dest[i]==src[i])
    			{
    				flag=0;
    				break;                   
    			}  
    			if(dest[i]<src[i])
    			{
    				flag=-1;
    				break;
    			}         
    			if(dest[i]>src[i])
    			{
    				flag=1;
    				break;
    			}       
    		}
    	}
    	if(len1<len2)
    	{
    		for(i=0;i<len1;i++)
    		{
    			if(dest[i]==src[i]||dest[i]<src[i])
    			{
    				flag=-1;
    				break;  
    			}
    			if(dest[i]>src[i])
    			{
    				flag=1;
    				break;  
    			}
    		}
    	}
    	if(len1>len2)
    	{
    		for(i=0;i<len2;i++)
    		{
    			if(dest[i]==src[i]||dest[i]>src[i])
    			{
    				flag=1;
    				break;  
    			}
    			if(dest[i]<src[i])
    			{
    				flag=-1;
    				break;  
    			}
    		}
    	}
    	return flag;
    }

    //拷贝(copy)  //编译没问题 结果段错误
    int copy(char *dest,int num,int index)
    {
    	int len1=my_strlen(dest);
    	char *str;
    	int i,j;
    	if(index+num>len1)
    	{

    		for(j=0,i=index;j<num,i<len1;j++,i++)
    		{
    			str[j]=dest[i];
    		}
    		str[j+1]='\0';
    	}
    	else
    	{
    		for(j=0,i=index;j<num,i<index+num;j++,i++)
    		{
    			str[j]=dest[i];
    		}
    		str[num]='\0';
    	}
    	return j;
    }

    //data()函数返回指向自己的第一个字符的指针.
    char *data(char *dest)
    {
    	char *p;
    	p=&dest[0];
    	return p;
    }

    //如果字符串为空则empty()返回真(true)，否则返回假(false).
    bool empty(char *dest)
    {
    	if(my_strlen(dest)==0)
    		return true;
    	else
    		return false;
    }

    //end()函数返回一个迭代器，指向字符串的末尾(最后一个字符的下一个位置).
    char *end(char *dest)
    {
    	int len1=my_strlen(dest);
    	char *p=&dest[len1];
    	return p;
    }

    //删除(erase)
    char erase_1(char *dest,int pos)
    {
    	int len1=my_strlen(dest);
    	if(pos>len1)
    	{
    		cout<<"out of range";
    		return 'N';
    	}
    	else
    	{
    		int i;
    		for(i=pos;i<len1;i++)
    		{
    			dest[i]=dest[i+1];
    		}
    		char *p=&dest[pos];
    		return *p;
    	}
    }
//删除从start到end的所有字符, 返回一个迭代器,指向被删除的最后一个字符的下一个位置 
    char erase_2(char *dest,int start,int end)
    {
    	int len1=my_strlen(dest);
    	int i;
    	char *p=NULL;
    	if(start>=len1&&start>=len1)
    	{
    		cout<<"out of range"<<endl;
    	}
    	if(start<len1&&end>=len1)
    	{
    		dest[start]='\0';
    		p=&dest[start];
    		return *p;
    	}
    	if(start<len1&&end<len1)
    	{
    		int tmp1=len1-end;
    		int tmp2=start;
    		i=0;
    		while(i<tmp1)
    		{
    			dest[start]=dest[end+1];
    			start++;
    			end++;
    			i++;
    		}
    		p=&dest[tmp2];
    		return *p;
    	}
    }

    //查找(find)
    int find_1(char *dest,char *src,int index)
    {
    	int len1=my_strlen(dest);
    	if(len1<index)
    	{
            cout<<"string::npos"<<endl;
            return -1;
    	}
    	else
    	{
    		int i;
    		for(i=index;i<len1;i++)
    		{
    			if(dest[i]==src[0])
    		    {
    		    	return i;  
    				break;
    			}
    		}  
    		for(i=index;i<len1;i++)
    		{
    			if(dest[i]!=src[0])
    			{
    				cout<<"string::npos"<<endl;
                    return -1;
    			}
    		}		
    	}
    }

    //查找在字符串中第一个与str中的某个字符匹配的字符，返回它的位置。搜索从index开始，
    //如果没找到就返回string::npos 
    int find_first_of (char *dest,char *src,int index)
    {
    	int len1=my_strlen(dest);
    	int len2=my_strlen(src);
    	int i,num;
    	cin>>num;
    	while(num>len2)
    	{
    		cout<<"please cin num again"<<endl;
    		cin>>num;
    	}
    	if(len1<index)
    	{
    		cout<<"string::npos"<<endl;
            return -1;
    	}
    	else
    	{
    		for(i=index;i<len1;i++)
    		{
    			if(dest[i]==src[num])
    			{
    				return i;
    				break;
    			}
    		}
    		for(i=index;i<len1;i++)
    		{
    			if(dest[i]!=src[num])
    			{
    				cout<<"string::npos"<<endl;
                    return -1;
    			}
    		}

    	}
   }

   /*在字符串中查找第一个与str中的字符都不匹配的字符，返回它的位置。搜索从index开始。
   如果没找到就返回string::nops */ //有问题
   int find_first_not_of(char *dest,char *src,int index)
   {
   	 int len1=my_strlen(dest);
   	 int len2=my_strlen(src);
   	 int i=0;
   	 int j=0;
   	 if(len1<index)
   	 {
   		cout<<"string::npos"<<endl;
           return -1;
   	 }
   	 else
   	 {
   	 	for(i=0;i<len2;i++)
   	 	{
   	 		for(j=0;j<len1;j++)
    		{
    			if(dest[j]!=src[i])
    			{
    				return i;
    				break;
    			}
    		}
    		for(j=0;j<len1;j++)
    		{
    			if(dest[j]==src[i])
    			{
    				cout<<"string::npos"<<endl;
                    return -1;
    			}
    		}

   	 	}
   	 }
   }

   //在字符串中查找最后一个与str中的某个字符匹配的字符，返回它的位置。
   //搜索从index开始。如果没找到就返回string::nops 
   int find_last_of (char *dest,char *src,int index)
   {
   	    int len1=my_strlen(dest);
    	int len2=my_strlen(src);
    	int i,num;
    	cin>>num;
    	while(num>len2)
    	{
    		cout<<"please cin num again"<<endl;
    		cin>>num;
    	}
    	if(len1<index)
    	{
    		cout<<"string::npos"<<endl;
            return -1;
    	}
    	else
    	{
    		for(i=len1-1;i>=0;i--)
    		{
    			if(dest[i]==src[num])
    			{
    				return i;
    				break;
    			}
    		}
    		for(i=index;i<len1;i++)
    		{
    			if(dest[i]!=src[num])
    			{
    				cout<<"string::npos"<<endl;
                    return -1;
    			}
    		}    		
    	}
   }
    
    //在字符串中查找最后一个与str中的字符都不匹配的字符，返回它的位置。
   //搜索从index开始。如果没找到就返回string::nops 
    int find_last_not_of(char *dest,char *src,int index)
    {
    	int len1=my_strlen(dest);
    	int len2=my_strlen(src);
    	if(index>=len1)
    	{
    		cout<<"string::nops"<<endl;
    		return -1;
    	}
    	else
    	{
    		int i=0;
    		int j=0;
    		for(i=len1-1;i>=index;i--)
    		{
    			while(dest[i]!=src[j])
    			{
    				j++;
    				if(j==len2)
    				{
    					return i;
    					break;
    				}
    			}
    		}
    		cout<<"string::nops"<<endl;
    		return -1;
    	}

    }

    //get_allocator()函数返回本字符串的配置器


    //插入(insert)  在字符串的位置index插入字符串str, 
    char *insert(char *dest,char *src,int index)
    {
    	int len1=my_strlen(dest);
    	int len2=my_strlen(src);
    	if(index>=len1)
    	{
    		dest=my_strcat(dest,src);
    	}
    	else
    	{
    		int i,j;
    		for(i=index+len2,j=index;i<len1+len1-index,j<len1;i++,j++)
    		{
    			dest[i]=dest[j];
    		}
    		dest[len1+len1-index]='\0';

    		for(i=index,j=0;i<index+len2,j<len2;i++,j++)
    		{
    			dest[i+1]=src[j];
    		}
    		//dest=my_strcat(dest,tmp);
    	}
    	return dest;
    }

    //长度(length)
    int length(char *dest)
    {
    	int len=my_strlen(dest);
    	return len;
    }

    //max_size()函数返回字符串能保存的最大字符数。
    int max_size(char *dest)
    {
    	return N;
    }

    //rbegin()返回一个逆向迭代器，指向字符串的最后一个字符。
    char *rbegin(char *dest)
    {
    	int len=my_strlen(dest);
    	char *p=&dest[len-1];
    	return p;
    }

    //rend()函数返回一个逆向迭代器，指向字符串的开头（第一个字符的前一个位置）。
    char *rend(char *dest)
    {
    	char *p;
    	p=&dest[0];
    	return p;
    }

    //替换(replace) 用str中的num个字符替换本字符串中的字符,从index开始
    char *replace(char *dest,char *src,int index)
    {
    	int len1=my_strlen(dest);
    	int len2=my_strlen(src);
    	if(index>=len1)
    	{
    		cout<<"out of range"<<endl;
    	}
    	else
    	{
    		int i,j;
    		for(i=index,j=0;i<index+len2,j<len2;i++,j++)
    		{
    			dest[i]=src[j];
    		}
    	}
    	return dest;
    }

    //reserve()函数设置本字符串的capacity 以保留num个字符空间。
    void reserve(char *dest,int num)
    {
    	int len1=my_strlen(dest);
    	if(N-len1>num)
    	{
    		N=N;
    	}
    	if(N-len1<num)
    	{
    		N=len1+num;
    	}	
    	cout<<N<<endl;
    }

    //resize()函数改变本字符串的大小到num, 新空间的内容不确定。也可以指定用ch填充
    char *resize(char *dest,int num,char ch)
    {
    	int i;
    	int len1=my_strlen(dest);
    	if(num<=len1)
    	{
    		dest=dest;
    	}
    	else
    	{
    		for(i=len1;i<num;i++)
    	    {
    		   dest[i]=ch;
    	    }
    	    dest[num]='\0';
    	}
    	return dest;
    }

    //返回最后一个与str中的某个字符匹配的字符，从index开始查找。如果没找到就返回string::npos 
    char rfind(char *dest,char *src,int index)
    {
    	int num;
    	int len1=my_strlen(dest);
    	int len2=my_strlen(src);
    	cin>>num;
    	while(num>=len2)
    	{
    		cout<<"please input num again"<<endl;
    		cin>>num;
    	}
        
        if(index>=len1)
        {
        	cout<<"string::npos"<<endl;
    		return '\n';
        }
        else
        {
        	int i;
    	    for(i=len1-1;i>=index;i--)
    	    {
    	    	if(dest[i]==src[num])
    	    	{
    	    		return dest[i];
    	    		break;
    	    	}
    	    }
    
    	    i=0;
    	    while(dest[i]!=src[num])
    	    {
    	    	i++;
    	    	if(i==len1)
    	    	{
    	    	   cout<<"string::npos"<<endl;
    	    	   return '\n';
    	    	}
    	    }
        }        
    }

    //size()函数返回字符串中现在拥有的字符数。+'\n'
    int size(char *dest)
    {
    	int len1=my_strlen(dest);
    	int size=len1+1;
    	return size;
    }

    //substr()返回本字符串的一个子串，从index开始，长num个字符。
    //如果没有指定，将是默认值 string::npos。这样，substr()函数将简单的返回从index开始的剩余的字符串

    char *substr(char *dest,char *src,int index)
    {
    	int len1=my_strlen(dest);
    	int len2=my_strlen(src);

    	int num;
    	cin>>num;
    	while(num>=len1)
    	{
    		cout<<"please input num again"<<endl;
    		cin>>num;
    	}

    	if(index>=len1)
    	{
    		return "string::npos";
    	}
    	else
    	{
    		int i,j;
    		char *tmp;
    		for(i=0,j=index;i<num,j<index+num;i++,j++)
    		{
    			tmp[i]=dest[j];
    		}
    		tmp[index+num]='\0';

    		return my_strcat(src,tmp);
    	}
    }

    //swap()函数把str和本字符串交换

    void swap(char *dest,char *src)
    {
    	int len1=my_strlen(dest);
    	int len2=my_strlen(src);
    	int num=len1>len2?len1:len2;
    	int i;
    	char *tmp;
    	for(i=0;i<num;i++)
    	{
    		tmp[i]=dest[i];
    		dest[i]=src[i];
    		src[i]=tmp[i];
    	}

    	cout<<"dest:"<<dest<<endl;
    	cout<<"src: "<<src<<endl;
    }
};

int main(int argc, char const *argv[])
{
	my_string m1;
	char dest[N];
	bzero(dest,sizeof(dest));
	gets(dest);
	char src[N];
	bzero(src,sizeof(src));
	gets(src);
	//int num;
	// cin>>num;
	int index;
    cin>>index;
	// int start;
	// cin>>start;
	// int end;
	// cin>>end;
	// char ch;
	// cin>>ch;
    cout<<m1.find_last_not_of(dest,src,index)<<endl;
    //m1.swap(dest,src);
	return 0;
}