#include <string>

#include "Log.h"

using namespace std;

int main()
{
    Log *log = Log::getInstance();

    log->log("Error", "Big problems, Jerry!");

    delete log;

    return 0;
}
