#ifndef HARL_HPP
#define HARL_HPP

#include "Harl.h"

class Harl
{
private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
	std::string level;
public:
	void complain(const std::string& level);
};

#endif
