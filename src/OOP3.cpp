// OOP3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "Vector.h"
#include <fstream>
#include <chrono>

// Laikmacio klase detalaus laiko skaiciavimui
class Timer {
private:
	using hrClock = std::chrono::high_resolution_clock;
	using durationDouble = std::chrono::duration<double>;
	using tmPt = std::chrono::time_point<hrClock>;

	tmPt start_;
	durationDouble duration_{ 0 }, null_duration_{ 0 };

	inline void addDuration_() { duration_ += hrClock::now() - start_; }
public:
	Timer() : start_{ hrClock::now() } {}

	inline void reset() {
		start_ = hrClock::now();
		duration_ = null_duration_;
	}
	inline double elapsed() {
		addDuration_();
		return duration_.count();
	}
	inline void pause() {
		addDuration_();
	}
	inline void resume() {
		start_ = hrClock::now();
	}
};


int main()
{
	unsigned int sz = 100000000;

	for (int j = 0; j < 100; j++)
	{
		Timer t1;
		std::vector<int> v1;
		for (int i = 1; i <= sz; ++i)
			v1.push_back(i);
		t1.pause();
		std::cout << "std::vector<int> fill " << sz << ": " << t1.elapsed() << " s\n";
	}
	std::cout << "\n\n\n\n\n\n\n";

	for (int j = 0; j < 100; j++)
	{
		Timer t2;
		Vector<int> v2;
		for (int i = 1; i <= sz; ++i)
			v2.push_back(i);
		t2.pause();
		std::cout << "Vector<int>   \t fill " << sz << ": " << t2.elapsed() << " s\n";
	}
}
