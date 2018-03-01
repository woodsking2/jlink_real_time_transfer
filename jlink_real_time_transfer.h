#pragma once
#ifndef __JLINK_REAL_TIME_TRANSFER_H__
#define __JLINK_REAL_TIME_TRANSFER_H__
#ifdef __cplusplus
extern "C" {
#endif //!<#ifdef __cplusplus
/*************************** C start ********************************/
/*************************** C end ********************************/
#ifdef __cplusplus
}
/*************************** cpp start ********************************/
#include "platform/platform.h"
#include "Stream.h"
#include "platform/NonCopyable.h"
#include "RTT/SEGGER_RTT.h"
#include <string>
class Jlink_real_time_transfer : public mbed::Stream, private mbed::NonCopyable<Jlink_real_time_transfer>
{
  public:
    Jlink_real_time_transfer(const char *name = "Jlink_real_time_transfer") : Stream(name), m_name("/")
    {
        SEGGER_RTT_Init();
        m_name.append(name);
    }
    ~Jlink_real_time_transfer() = default;
    void redirect_std()
    {
        freopen(m_name.c_str(), "w", stdout);
    }

  protected:
    virtual int _getc()
    {
        return -1;
    }
    virtual int _putc(int c)
    {
        SEGGER_RTT_PutChar(0, c);
        return c;
    }
    virtual void lock()
    {
        m_mutex.lock();
    }
    virtual void unlock()
    {
        m_mutex.unlock();
    }

    PlatformMutex m_mutex;

  private:
    std::string m_name;
};

/*************************** cpp end ********************************/
#endif //!<#ifdef __cplusplus
#endif //!< #ifndef __JLINK_REAL_TIME_TRANSFER_H__