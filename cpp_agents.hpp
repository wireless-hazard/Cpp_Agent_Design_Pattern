#include <stdio.h>
#include <iostream>
#include <string>
#include <thread>
#include <queue>
#include <chrono>

namespace local_function{

std::string parse_command(const std::string& command);
void task_implm(std::queue<std::string>& cmd_queue, std::queue<std::string>& reply_queue);

}

namespace agency {

class Agent{
public:
	explicit Agent(void){
		this->task = std::thread{local_function::task_implm, std::ref(cmd_queue), std::ref(reply_queue)};
	}
	inline ~Agent(){
		this->task.join();
	}
	void getReply(void);
	void sendCommand(const char *command);

protected:
	std::queue<std::string> cmd_queue;
	std::queue<std::string> reply_queue;
	std::thread task;
};

} //end namespace agency 