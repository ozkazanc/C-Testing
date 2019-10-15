#include <chrono>

// A basic timer class to profile code
// Make sure to time code in Release build target not Debug.
// Timing can change depending on the background process.
// Measure multiple times and take the average.
// The measurements will vary depending on the machine's architecture, OS, compiler, specs.

class Timer{
public:
	Timer() :m_beg(clock_t::now()) {}
	
	void Reset(){ m_beg = clock_t::now(); }
	double Elapsed() const { return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count(); }

private:
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1> >;

	std::chrono::time_point<clock_t> m_beg;

};