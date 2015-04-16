#ifndef LOGGER_HPP
# define LOGGER_HPP

# include <string>
# include <iostream>
# include <sstream>
# include "OctoFile.hpp"

// Usage
// OctoLogger::Log("blabla");
// OctoLogger::Log() << "blabla";

class OctoLogger
{
private:
	static OctoFile			m_file;
	static OctoLogger *		msp_current;
	bool					mb_activateTime;

	virtual void write(std::string const & p_message);

protected:
	std::string currentDate(void) const;
	std::string currentTime(void) const;

public:
	OctoLogger(void);
	virtual ~OctoLogger(void);

	void activateTime(void);
	void desactivateTime(void);

	static OctoLogger & getCurrent(void);
	static OctoLogger & log(void);
	static void log(char const * pn_args, ...);
	static void logCmd(char const * pn_args, ...);
	static void log(std::string const & p_string);
	static void destroy(void);

	template<class T>
	OctoLogger & operator <<(const T& p_toLog)
	{
		std::ostringstream stream;
		stream << p_toLog;
		write(stream.str());
		return log();
	}

};

#endif
