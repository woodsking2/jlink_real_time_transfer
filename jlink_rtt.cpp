#include "jlink_rtt.h"
#include "RTT/SEGGER_RTT.h"

Jlink_rtt::Jlink_rtt(const char *name) : Stream(name), _name("/")
{
    SEGGER_RTT_Init();
    _name.append(name);
}
// void Jlink_rtt::redirect_std()
// {
//     auto outFile = freopen(_name.c_str(), "w", stdout);
// }
// void Jlink_rtt::flush_std()
// {
//     fflush(stdout);
// }
int Jlink_rtt::_getc()
{
    return -1;
}
int Jlink_rtt::_putc(int c)
{
    SEGGER_RTT_PutChar(0, c);
    return c;
}
void Jlink_rtt::lock()
{
    _mutex.lock();
}
void Jlink_rtt::unlock()
{
    _mutex.unlock();
}
// FileHandle *mbed::mbed_override_console(int fd)
// {
//     return &JLinkRealTimeTransferInstance;
// }