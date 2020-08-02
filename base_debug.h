#ifndef __BASE_DEBUG_H
#define __BASE_DEBUG_H

#include "stdio.h"
#include "base_error_code.h"

/**
 * \brief   Debug log switch
 */
#define DEBUG_ENABLE    1
#define DEBUG_DISABLE   0
#define _BASE_DEBUG_LOG_SWITCH  DEBUG_ENABLE

#if _BASE_DEBUG_LOG_SWITCH
#define BASE_DEBUG_LOG(fmt, ...)    printf(fmt, ##__VA_ARGS__)
#else
#define BASE_DEBUG_LOG(fmt , ...)
#endif


/**
 * \brief   Function name debug log macro for convenience
 */
#define BASE_DEBUG_LOG_FUNCTION_NAME() \
    BASE_DEBUG_LOG("DEBUG LOG: %s\r\n", __FUNCTION__)


/**
 * \brief   Error code debug log macro for convenience
 */
#define BASE_DEBUG_LOG_FALSE() \
    BASE_DEBUG_LOG("DEBUG LOG: %s _BASE_FALSE\r\n", __FUNCTION__)

#define BASE_DEBUG_LOG_INVALID_PARAM() \
    BASE_DEBUG_LOG("DEBUG LOG: %s _BASE_INVALID_PARAM\r\n", __FUNCTION__)

#define BASE_DEBUG_LOG_INITIALIZED() \
    BASE_DEBUG_LOG("DEBUG LOG: %s _BASE_INITIALIZED\r\n", __FUNCTION__)

#define BASE_DEBUG_LOG_UNINITIALIZED() \
    BASE_DEBUG_LOG("DEBUG LOG: %s _BASE_UNINITIALIZED\r\n", __FUNCTION__)

#define BASE_DEBUG_LOG_NOT_FOUND() \
    BASE_DEBUG_LOG("DEBUG LOG: %s _BASE_NOT_FOUND\r\n", __FUNCTION__)

#define BASE_DEBUG_LOG_NOT_ENOUGH_MEMORY() \
    BASE_DEBUG_LOG("DEBUG LOG: %s _BASE_NO_ENOUGH_MEMORY\r\n", __FUNCTION__)

#define BASE_DEBUG_LOG_FULL() \
    BASE_DEBUG_LOG("DEBUG LOG: %s _BASE_FULL\r\n", __FUNCTION__)

#define BASE_DEBUG_LOG_EMPTY() \
    BASE_DEBUG_LOG("DEBUG LOG: %s _BASE_EMPTY\r\n", __FUNCTION__)

#endif
