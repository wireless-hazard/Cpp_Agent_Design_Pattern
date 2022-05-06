#include <stdio.h>
#include <thread>

void printing(const char *parameter){
	printf("%s\n", parameter);
}

int main(){
	std::thread t1{printing,"this string is going to be printed"};
	t1.join();
}