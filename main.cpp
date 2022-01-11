#include <iostream>
#include <cstdio>
#include <sys/proc_info.h>
#include <libproc.h>
#include <string>
#include <vector>
#include <algorithm>

namespace raine
{
struct process_info
{
    pid_t pid;
    std::string command;
};
}

std::vector<raine::process_info> getProcessCount() {
    std::vector<raine::process_info> result;
int numberOfProcesses = proc_listpids(PROC_ALL_PIDS, 0, NULL, 0);
pid_t pids[numberOfProcesses];
bzero(pids, sizeof(pids));
proc_listpids(PROC_ALL_PIDS, 0, pids, sizeof(pids));
for (int i = 0; i < numberOfProcesses; ++i) {
    if (pids[i] == 0) { continue; }
    char pathBuffer[PROC_PIDPATHINFO_MAXSIZE];
    bzero(pathBuffer, PROC_PIDPATHINFO_MAXSIZE);
    proc_pidpath(pids[i], pathBuffer, sizeof(pathBuffer));
    if (strlen(pathBuffer) > 0) {
        result.push_back({pids[i], pathBuffer});
    }
}
return result;
}
int main() {
    auto result = getProcessCount();
    std::for_each(result.begin(), result.end(), [](auto& info) {
        std::cout << info.pid << " " << info.command << std::endl;
    });
    return 0;
}