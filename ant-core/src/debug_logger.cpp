#include "debug_logger.h"
#include "deps.h"
#include <ostream>
std::ostream& print_time(std::ostream& _in)
{
    time_t tmNow;
    tmNow = time(NULL);
    struct tm t = *localtime(&tmNow);
    std::cout << GRN << "[" << t.tm_hour << ":" << t.tm_min << ":" << t.tm_sec << "] "<<NRM ;
    return _in;
}