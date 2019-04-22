#include "JLinkRealTimeTransfer.h"
#include "RTT/SEGGER_RTT.h"

JLinkRealTimeTransfer::JLinkRealTimeTransfer(const char *name) : Stream(name), _name("/")
{
    SEGGER_RTT_Init();
    _name.append(name);
}
// void JLinkRealTimeTransfer::redirect_std()
// {
//     auto outFile = freopen(_name.c_str(), "w", stdout);
// }
// void JLinkRealTimeTransfer::flush_std()
// {
//     fflush(stdout);
// }
int JLinkRealTimeTransfer::_getc()
{
    return -1;
}
int JLinkRealTimeTransfer::_putc(int c)
{
    SEGGER_RTT_PutChar(0, c);
    return c;
}
void JLinkRealTimeTransfer::lock()
{
    _mutex.lock();
}
void JLinkRealTimeTransfer::unlock()
{
    _mutex.unlock();
}
