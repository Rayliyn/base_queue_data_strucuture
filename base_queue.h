/*
 * Module Nanme: Base Queue
 * Description: 
 *     this module implemented the circular queue data structure.
 * Author: Ray Liyn
 * Version: V0.01.00
 * Date: 2020.08.01
 */

#ifndef __BASE_QUEUE_H
#define __BASE_QUEUE_H

#include "base_debug.h"
#include "base_error_code.h"
#include "stdint.h"

struct base_queue;
typedef struct base_queue base_queue_t;
typedef void* element_t;

/**
 * \brief      create a queue
 * \param[in]  max_size: the maximum size of array in the queue
 * \retval     queue handle or NULL
 */
base_queue_t* base_create_queue (uint32_t max_size);

/**
 * \brief      destroy a queue
 * \param[in]  p_this: queue handle to be free
 * \retval     operation result:
 *                _BASE_INVALID_PARAM:
 *                _BASE_SUCCESS:
 */
base_error_code_t base_destroy_queue (base_queue_t *p_this);

/**
 * \brief      check if the queue is empty
 * \param[in]  p_this: queue handle
 * \retval     operation result:
 *                _BASE_FALSE:
 *                _BASE_SUCCESS:
 */
base_error_code_t base_queue_is_empty (base_queue_t *p_this);

/**
 * \brief      check if the queue is full
 * \param[in]  p_this: queue handle
 * \retval     operation result:
 *                _BASE_FALSE:
 *                _BASE_SUCCESS:
 */
base_error_code_t base_queue_is_full (base_queue_t *p_this);

/**
 * \brief      add an element at the end of the queue
 * \param[in]  p_this: queue handle
 * \retval     operation result:
 *                _BASE_FULL:
 *                _BASE_SUCCESS:
 *                _BASE_INVALID_PARAM
 */
base_error_code_t base_queue_enqueue (base_queue_t *p_this, element_t element);

/**
 * \brief      pop an element of the queue
 * \param[in]  p_this: queue handle
 * \retval     element value or 0(if p_this is invalid or queue is empty).
 */
element_t base_queue_dequeue (base_queue_t *p_this);

/**
 * \brief      make the queue empty
 * \param[in]  p_this: queue handle
 * \retval     operation result:
 *                _BASE_SUCCESS:
 *                _BASE_INVALID_PARAM
 */
base_error_code_t base_queue_make_empty (base_queue_t *p_this);




#endif

