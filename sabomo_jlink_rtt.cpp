#include "sabomo_jlink_rtt.h"
#include "SEGGER_RTT.h"

namespace sabomo
{
Jlink_rtt::Jlink_rtt(const char *name) : Stream(name)
{
    SEGGER_RTT_Init();
}

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
    Thread_safe::lock();
}
void Jlink_rtt::unlock()
{
    Thread_safe::unlock();
}
} // namespace sabomo
