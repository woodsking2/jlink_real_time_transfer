#pragma once
#ifndef __JLINK_RTT_H__
#define __JLINK_RTT_H__
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
#include <string>
class Jlink_rtt : public mbed::Stream, private mbed::NonCopyable<Jlink_rtt>
{
  public:
    Jlink_rtt(const char *name = "Jlink_rtt");
    ~Jlink_rtt() = default;
    // void redirect_std();
    // void flush_std();
  protected:
    virtual int _getc();
    virtual int _putc(int c);
    virtual void lock();
    virtual void unlock();
    PlatformMutex _mutex;
  private:
    std::string _name;
};

/*************************** cpp end ********************************/
#endif //!<#ifdef __cplusplus
#endif //!< #ifndef __JLINK_RTT_H__