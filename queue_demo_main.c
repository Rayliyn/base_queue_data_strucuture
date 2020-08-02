#include "base_queue.h"
#include "stdio.h"

#define ARRAY_SIZE  5
uint8_t byte_array[ARRAY_SIZE] = {1, 2, 3, 4, 5};

int main (void)
{
    base_queue_t *p_queue_temp = base_create_queue(ARRAY_SIZE); /* 创建一个队列 */
    if (p_queue_temp == NULL)
    {
        printf("End of creating queue\r\n");
        getchar();
        return 0;
    }

    if (base_queue_is_empty(p_queue_temp) == _BASE_TRUE)  /* 测试队列是否为空 */
    {
        printf("Queue is empty\r\n");
    }

    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        if (base_queue_enqueue(p_queue_temp, (void *)&byte_array[i]) != _BASE_SUCCESS) /* 将数据的地址放入队列中 */
        {
            printf("End of enqueuing\r\n");
            getchar();
            return 0;
        }
    }

    if (base_queue_enqueue(p_queue_temp, (void*)&byte_array[5]) != _BASE_SUCCESS)  /* 再放一个 */
    {
        printf("enqueuing faild\r\n");
    }

    
    if (base_queue_is_full(p_queue_temp) == _BASE_TRUE)    /* 检查是否队列满了 */
    {
        printf("Queue is full\r\n");
    }

    uint8_t *p_byte = NULL;
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        p_byte = base_queue_dequeue(p_queue_temp);    /* 数据弹出队列 */
        printf("byte[%d]: %d\r\n", i, *p_byte);
    }

    if (base_queue_is_empty(p_queue_temp) == _BASE_TRUE)  /* 再次检查队列是否为空 */
    {
        printf("Queue is empty\r\n");
    }

    if (base_queue_enqueue(p_queue_temp, (void *)&byte_array[4]) != _BASE_SUCCESS)  /* 测试再入队出队操作后在入队一个数据是否有问题 */
    {
        printf("End of enqueuing\r\n");
        getchar();
        return 0;
    }


    p_byte = base_queue_dequeue(p_queue_temp);    /* 数据出队 */
    printf("byte[%d]: %d\r\n", 0, *p_byte);

    if (base_queue_make_empty(p_queue_temp) == _BASE_SUCCESS)   /* 清空队列 */
    {
        if (base_queue_is_empty(p_queue_temp) == _BASE_TRUE)
        {
            printf("Queue is empty\r\n");
        }
    }
    else
    {
        printf("Faild to make queue empty\r\n");
    }

    if(base_destroy_queue(p_queue_temp) == _BASE_SUCCESS)  /* 释放动态分配的队列 */
    {
         printf("Successfully destroy the queue\r\n");
    }

    getchar();
    return 0;
}