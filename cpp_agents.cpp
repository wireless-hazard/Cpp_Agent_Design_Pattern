#include <stdio.h>
#include <thread>


void printing(const char *parameter){
	printf("%s\n", parameter);
}

namespace agency {
class thread_RAII : public std::thread{

	using thread::thread; //Inherits all constructor from thread

public:
	~thread_RAII(){if(this->joinable()) this->join();}

};

class Agent{
public:
	explicit Agent(const char *parameter) : t1{printing, parameter} {

	}
	~Agent(){printf("Agent is out!!\n");}

private:
	agency::thread_RAII t1;
};

} //end namespace agency 



int main(){
	agency::Agent Smith("This string");
}