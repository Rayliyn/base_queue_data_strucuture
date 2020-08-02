/*
 * Module Nanme: Base Queue
 * Description: 
 *     this module implemented the circular queue data structure.
 * Author: Ray Liyn
 * Version: V0.01.00
 * Date: 2020.08.01
 */

#include "base_queue.h"
#include "stdlib.h"

/*
 *  base_queue data structure type definaton
 */
struct base_queue
{
    uint32_t capacity;         /* maximum size of the queue */
    uint32_t front;            /* front position of the queue */
    uint32_t rear;             /* rear position of the queue */
    uint32_t current_size;     /* record of the current size of the queue */
    element_t *array;          /* data element array in the queue */
};

/**
 * \brief      create a queue
 * \param[in]  max_size: the maximum size of array in the queue
 * \retval     queue handle or NULL
 */
base_queue_t* base_create_queue (uint32_t max_size)
{
    base_queue_t * p_queue_handle = malloc(sizeof(base_queue_t));
    if (p_queue_handle == NULL)
    {
        BASE_DEBUG_LOG_NOT_ENOUGH_MEMORY();
        return NULL;
    }

    p_queue_handle->array = malloc(sizeof(element_t) * max_size);
    if (p_queue_handle->array == NULL)
    {
        BASE_DEBUG_LOG_NOT_ENOUGH_MEMORY();
        return NULL;
    }
    p_queue_handle->capacity = max_size;
    p_queue_handle->current_size = 0;
    p_queue_handle->front = 0;
    p_queue_handle->rear = 0;
    
    return p_queue_handle;
}

/**
 * \brief      destroy a queue
 * \param[in]  p_this: queue handle to be free
 * \retval     operation result:
 *                _BASE_INVALID_PARAM:
 *                _BASE_SUCCESS:
 */
base_error_code_t base_destroy_queue (base_queue_t *p_this)
{
    if (p_this == NULL)
    {
        BASE_DEBUG_LOG_INVALID_PARAM();
        return _BASE_INVALID_PARAM;
    }

    free(p_this->array);
    free(p_this);

    return _BASE_SUCCESS;
}


/**
 * \brief      check if the queue is empty
 * \param[in]  p_this: queue handle
 * \retval     operation result:
 *                _BASE_FALSE:
 *                _BASE_SUCCESS:
 */
base_error_code_t base_queue_is_empty (base_queue_t *p_this)
{
    if (p_this->current_size == 0)
    {
        return _BASE_SUCCESS;
    }
    else
    {
        BASE_DEBUG_LOG_FALSE();
        return _BASE_FALSE;
    }
}

/**
 * \brief      check if the queue is full
 * \param[in]  p_this: queue handle
 * \retval     operation result:
 *                _BASE_FALSE:
 *                _BASE_SUCCESS:
 */
base_error_code_t base_queue_is_full (base_queue_t *p_this)
{
    if (p_this->current_size == p_this->capacity)
    {
        return _BASE_SUCCESS;
    }
    else
    {
        BASE_DEBUG_LOG_FALSE();
        return _BASE_FALSE;
    }
}

/**
 * \brief      Increase the count of front or rear. When count reach the capacity, set it to zero.
 * \param[in]  value: the value of front or rear
 * \param[in]  p_this: queue handle
 * \retval     value of the count
 */
static uint32_t increase_count (uint32_t value, base_queue_t *p_this)
{
    value++;
    if (value == p_this->capacity)
    {
        value = 0;
    }
    return value;
}

/**
 * \brief      add an element at the end of the queue
 * \param[in]  p_this: queue handle
 * \retval     operation result:
 *                _BASE_FULL:
 *                _BASE_SUCCESS:
 *                _BASE_INVALID_PARAM
 */
base_error_code_t base_queue_enqueue (base_queue_t *p_this, element_t element)
{
    if (p_this == NULL)
    {
        BASE_DEBUG_LOG_INVALID_PARAM();
        return _BASE_INVALID_PARAM;
    }
    else if (base_queue_is_full(p_this) == _BASE_SUCCESS)
    {
        BASE_DEBUG_LOG_FULL();
        return _BASE_FULL;
    }
    else
    {
        (p_this->current_size)++;
        p_this->rear = increase_count(p_this->rear, p_this);
        p_this->array[p_this->rear] = element;

        return _BASE_SUCCESS;
    }
}

/**
 * \brief      pop an element of the queue
 * \param[in]  p_this: queue handle
 * \retval     element value or 0(if p_this is invalid or queue is empty).
 */
element_t base_queue_dequeue (base_queue_t *p_this)
{
    if (p_this == NULL)
    {
        BASE_DEBUG_LOG_INVALID_PARAM();
        return 0;
    }
    else if (base_queue_is_empty(p_this) == _BASE_SUCCESS)
    {
        BASE_DEBUG_LOG_EMPTY();
        return 0;
    }
    else
    {
        (p_this->current_size)--;
        p_this->front = increase_count(p_this->front, p_this);
        return p_this->array[p_this->front];
    }
}

/**
 * \brief      make the queue empty
 * \param[in]  p_this: queue handle
 * \retval     operation result:
 *                _BASE_SUCCESS:
 *                _BASE_INVALID_PARAM
 */
base_error_code_t base_queue_make_empty (base_queue_t *p_this)
{
    if (p_this == NULL)
    {
        return _BASE_INVALID_PARAM;
    }
    else
    {
        p_this->current_size = 0;
        p_this->front = 0;
        p_this->rear = 0;

        return _BASE_SUCCESS;
    }
}

