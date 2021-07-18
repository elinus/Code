#include <iostream>
#include <chrono>
#include <thread>

class Timer {
private:
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1>>;
	std::chrono::time_point<clock_t> m_beg;
public:
	Timer() : m_beg{ clock_t::now() }
	{}
	void reset() {
		m_beg = clock_t::now();
	}
	double elapsed() {
		return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
	}
};

int main() {
	Timer t;
	std::this_thread::sleep_for(std::chrono::microseconds(5000));
	std::cout << t.elapsed() << std::endl;
	return 0;
}