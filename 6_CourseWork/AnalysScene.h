/*
	class AnalysScene
*/
#ifndef ANALYSSCENE_H
#define ANALYSSCENE_H
#include<thread>
#include<mutex>
#include<atomic>
#include "Menu.h"

class AnalysScene :public Menu
{
	std::atomic<int> tCount;
	std::mutex tMutex;

public:
	AnalysScene() :tCount(0), tMutex() {};
	virtual void start();
	void parseOneStr();
};

#endif

