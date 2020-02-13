#include "CachePerformanceTest.h"
#include "../Timer.h"

namespace CachePerformanceTest {
	void Main() {
		// Cache here means the L1 cache, I did not consider L2, and L3 caches effects to performance

		std::cout << "Size of int: " << sizeof(int) << "\n";
		// 256 KB (2^18) L1 cache 2^18, sizeof int is 4 B (2^2) so we can fit 65536 (2^16) ints in a single cache line.

		// #cache misses = #total data / #data processed per cache miss
		const int rowCount = 10000;
		const int colCount = 10000;

		// Populate the matrix by row first algorithm
		int* cacheFriendly = new int[rowCount * colCount];
		Timer cf_timer;
		for (int i = 0; i < rowCount; i++) {
			for (int j = 0; j < colCount; j++) {
				cacheFriendly[i * colCount + j] = 0;
			}
		}
		
		// Cache friendly: appr. 1526 cache misses 
		// #Total data = 10^8
		// #Processed data per cache miss = 2^16	We work on the data the same way that is layed out in memory so we get a cache miss every 65536th int
		// 10^8 / 2^16 = ~1526 cache misses

		double timeCacheFriendly = cf_timer.Elapsed();
		std::cout << "Cache friendly: " << timeCacheFriendly << "\n";


		// Populate the matrix by column first algorithm
		int* cacheNonFriendly = new int[rowCount * colCount];
		Timer cnf_Timer;
		for (int i = 0; i < colCount; i++) {		// These loops are swapped.
			for (int j = 0; j < rowCount; j++) {
				cacheNonFriendly[j * colCount + i] = 1;
			}
		}
		
		// Cache unfriendly: appr. 16.67 million cache misses
		// #Total data = 10^8
		// #Processed data per cache miss = 6 
		// We can only fits just over 6 rows of data into a single cache line, so by processing columns first we can only proccess 6 data per cache line.
		// 10^8 / 6 = ~16.67 million cache misses
		
		double timeCacheNonFriendly = cnf_Timer.Elapsed();
		std::cout << "Cache non-friendly: " << timeCacheNonFriendly << std::endl;

		delete[] cacheFriendly;
		delete[] cacheNonFriendly;
	}
}
