#pragma once
#include <ostream>
#ifndef __DEBUG_LOGGER_
#define __DEBUG_LOGGER_

#define NRM "\x1B[0m"
#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define YEL "\x1B[33m"
#define BLU "\x1B[34m"
#define MAG "\x1B[35m"
#define CYN "\x1B[36m"
#define WHT "\x1B[37m"

std::ostream& print_time(std::ostream& _in);

#define LOG_DEBUG(str) std::cout << YEL << "[DEBUG] " << NRM << print_time << str << "\n";
#define LOG_ERROR(str) std::cout << RED << "[ERROR] " << NRM << print_time << str << "\n";
#define LOG_EVENT(str) std::cout << CYN << "[EVENT] " << CYN << print_time << str << "\n";
#define LOG_GLERR(str) std::cout << MAG << "[GlLOG] " << NRM << print_time << str << "\n";
#endif