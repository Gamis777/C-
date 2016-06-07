/*实现一个简单的多线程类*/
#include <iostream>
#include <pthread.h>
using namespace std;
typedef void* (*FUN)(void* arg);
class my_pthread
{
// typedef void* (*FUN)(void* arg);
public:
	my_pthread()
	{

	}

	void run(FUN fp)
	{
		pthread_t th1;
		int ret = pthread_create(&th1,NULL,fp,NULL);
		while(ret == -1)
		{
			ret = pthread_create(&th1,NULL,fp,NULL);
		}

		pthread_join(th1,NULL);
	}


};

void * do_work(void* arg)
{
	cout<<"ptread is starting"<<endl;
	return NULL;
}
int main(int argc, char const *argv[])
{
	my_pthread* p1 = new my_pthread();
	p1->run(do_work);
	return 0;
}