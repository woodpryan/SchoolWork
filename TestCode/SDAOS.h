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
