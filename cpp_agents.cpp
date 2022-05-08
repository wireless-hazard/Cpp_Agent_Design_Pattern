#include <stdio.h>
#include <iostream>
#include <string>
#include <thread>
#include <queue>
#include <chrono>

namespace local_function{

std::string parse_command(const std::string& command){
	std::string cmd_param = command.substr(command.find(" ")+1);
	return std::move(cmd_param);
}

void task_implm(std::queue<std::string>& cmd_queue, std::queue<std::string>& reply_queue){ //TODO: Move the thread function to another file

	while(true){
		while(cmd_queue.empty()){
			std::this_thread::sleep_for(std::chrono::milliseconds{100}); //This will be exchanged by a condition_variable
		}
		std::string cmds = cmd_queue.front();
		reply_queue.push(parse_command(cmds));
		break;
	}
	return;
}
} //End namespace local_function

namespace agency {

class Agent{
public:
	explicit Agent(void){
		this->task = std::thread{local_function::task_implm, std::ref(cmd_queue), std::ref(reply_queue)};
	}
	~Agent(){
		task.join();
	}
	void getReply(void){
		while(this->reply_queue.empty()){
			std::this_thread::sleep_for(std::chrono::milliseconds{100}); //This will be exchanged by a condition_variable
		}
		std::cout<<this->reply_queue.front()<<"\n";
	}
	void sendCommand(const char *command){
		this->cmd_queue.push(command);
	}

protected:
	std::queue<std::string> cmd_queue;
	std::queue<std::string> reply_queue;
	std::thread task;
};

} //end namespace agency 



int main(){
	agency::Agent Smith;
	Smith.sendCommand("command value");
	Smith.getReply();
}