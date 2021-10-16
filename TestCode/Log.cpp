#include <string>

using namespace std;

enum class ErrorLevel
{
    SEVERE, ERROR, WARNING, INFO
};

struct ErrorContext
{
    ErrorLevel errlevel;
    const char *logmsg;
}
logcontext;

extern void SDAOSlogger(struct ErrorContext &logcontext);

class Log
{
    public:
        static Log *getInstance();
        void log(const std::string strType, const std::string strMsg);
    private:
        static Log *instance;

        Log();
};

Log* Log::instance = nullptr;

Log* Log::getInstance()
{
    if(nullptr == instance)
    {
        instance = new Log();
    }
    return instance;
}

void Log::log(const string strType, const string strMsg)
{
    ErrorContext errCon;

    if(strType == "Severe" || strType == "SEVERE")
    {
        errCon.errlevel = ErrorLevel::SEVERE;
    }
    else if(strType == "Error" || strType == "ERROR")
    {
        errCon.errlevel = ErrorLevel::ERROR;
    }
    else if(strType == "Warning" || strType == "WARNING")
    {
        errCon.errlevel = ErrorLevel::WARNING;
    }
    else
    {
        errCon.errlevel = ErrorLevel::INFO;
    }
    errCon.logmsg = strMsg.c_str();

    SDAOSlogger(errCon);
}

Log::Log()
{
}

int main()
{
    Log *log = Log::getInstance();

    log->log("Error", "Big problems, Jerry!");

    delete log;

    return 0;
}

