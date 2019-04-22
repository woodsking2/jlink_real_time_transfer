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
#include <string>
class JLinkRealTimeTransfer : public mbed::Stream, private mbed::NonCopyable<JLinkRealTimeTransfer>
{
  public:
    JLinkRealTimeTransfer(const char *name = "JLinkRealTimeTransfer");
    ~JLinkRealTimeTransfer() = default;
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
#endif //!< #ifndef __JLINK_REAL_TIME_TRANSFER_H__