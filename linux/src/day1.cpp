#include <iostream>
#include <csignal>
#include <ncurses.h>
#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <cstring>
#include <sys/time.h>
bool Isrunning = true;
void printHello()
{
	std::cout << "Hello" << std::endl;
}

void signalHandler(int signum)
{
	if (signum == '\033')
	{ // 检查按下的键是否为 ESC 键
		printHello();
		Isrunning = false;
	}
}

int main()
{
	std::cout << "程序已启动" << std::endl;

	signal(SIGINT, signalHandler); // 注册信号处理函数

	struct termios oldSettings, newSettings;
	tcgetattr(STDIN_FILENO, &oldSettings);
	newSettings = oldSettings;
	newSettings.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newSettings);

	char input;
	while (Isrunning)
	{
		if (read(STDIN_FILENO, &input, sizeof(input)) > 0)
		{
			if (input == '\033')
			{ // 检查按下的键是否为 ESC 键
				break;
			}
		}
	
	}

	tcsetattr(STDIN_FILENO, TCSANOW, &oldSettings);

	std::cout << "程序已退出" << std::endl;

	return 0;
}
