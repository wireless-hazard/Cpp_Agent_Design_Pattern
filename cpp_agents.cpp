#include <stdio.h>
#include <iostream>
#include <string>
#include <thread>
#include <queue>
#include <chrono>


static void printing(std::queue<std::string>& cmd_queue){

	
	// std::this_thread::sleep_for(std::chrono::milliseconds{1000});
	std::string cmds = cmd_queue.front();
	std::cout<< cmds <<"\n";
}

namespace agency {

class thread_RAII : public std::thread{

	using thread::thread; //Inherits all constructor from thread

public:
	~thread_RAII(){if(this->joinable()) this->join();}

};

class Agent{
public:
	explicit Agent(const char *parameter) : task{printing, std::ref(cmd_queue)}{
		cmd_queue.push(parameter);
	}
	~Agent(){}

private:
	std::queue<std::string> cmd_queue;
	agency::thread_RAII task;
};

} //end namespace agency 



int main(){
	agency::Agent Smith("That string");
}