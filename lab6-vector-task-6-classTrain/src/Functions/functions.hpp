#include "../Train/Train.hpp"


bool checkFile(std::ifstream& );
bool sortTime(Train& , Train& ) noexcept;
int32_t splittingIntoWords(std::string inputString, int32_t i)  noexcept;
void printTrainsInTimeRange(std::vector<Train>& trains, int32_t start_timeH, int32_t end_timeH, int32_t start_timeM, int32_t end_timeM) noexcept ;
	