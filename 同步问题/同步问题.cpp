// 同步问题.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

#define N 5
#define LEFT (i + N - 1) % N // 左邻居
#define RIGHT (i + 1) % N    // 右邻居
#define THINKING 0
#define HUNGRY   1
#define EATING   2

typedef std::mutex semaphore;//互斥锁信号
std::mutex mutex;//互斥锁
std::condition_variable s[N];
int state[N];//5个科学家的行为

void check(int i) {
	if (state[i] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING) {
		state[i] = EATING;
		s[i].notify_all();
	}
}

void think(int i) {
	// 哲学家思考的操作
	std::cout << "Philosopher " << i << " is thinking." << std::endl;
}

void take_two(int i) {
	std::unique_lock<std::mutex> lock(mutex);//创建了一个名为 lock 的 std::unique_lock 对象，并传递了 mutex 作为参数，这意味着它将 mutex 上锁,
	//只允许一个线程进入此代码段，如果被占用，则该线程在此被阻塞
	state[i] = HUNGRY;
	check(i);
	while (state[i] == HUNGRY) {
		s[i].wait(lock);//如果check发现不成功，则此线程进入等待状态
		check(i);
	}
}

void put_two(int i) {
	std::unique_lock<std::mutex> lock(mutex); // 创建了一个名为 lock 的 std::unique_lock 对象，并传递了 mutex 作为参数，这意味着它将 mutex 上锁,
		//只允许一个线程进入此代码段，如果被占用，则该线程在此被阻塞
	state[i] = THINKING;
	check(LEFT);
	check(RIGHT);
}

void eat(int i) {
	std::cout << "Philosopher " << i << " is eating." << std::endl;
}


void philosopher(int i) {
	while (true) {
		think(i);
		take_two(i);
		eat(i);
		put_two(i);
	}
}

int main() {
	std::thread philosophers[N];

	// 初始化哲学家的状态
	for (int i = 0; i < N; ++i) {
		state[i] = THINKING;
	}

	// 创建哲学家线程
	for (int i = 0; i < N; ++i) {
		philosophers[i] = std::thread(philosopher, i);
	}

	// 等待哲学家线程完成
	for (int i = 0; i < N; ++i) {
		philosophers[i].join();
	}

	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
