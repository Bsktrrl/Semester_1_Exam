#pragma once

//I've chosen to include every library we've used this semester (copied from my own database)
//to save time over selecting each include induvidualy when needed (it also prevents errors in cases I would forget to include them).
#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>
#include <random>
#include <conio.h>
#include <vector>
#include <thread>
#include <fstream>
#include <time.h>
#include <chrono>
#include <mutex>

//Instead of using "namespace std" (which is bad practice), I've selected all includes we've used this semester
//to save time over selecting induvidualy. I may not use them all, but this saves me time throughout the exam.
#pragma region Namespace
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::setw;
using std::vector;
using std::ios;
using std::fstream;
using std::ifstream;
using std::ofstream;
using std::streampos;
using std::ostream;
using std::thread;
using std::mutex;

using std::random_device;
using std::mt19937_64;
using std::uniform_int_distribution;
#pragma endregion