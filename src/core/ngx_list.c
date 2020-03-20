
/*
 * Copyright (C) Igor Sysoev
 * Copyright (C) Nginx, Inc.
 */


#include <ngx_config.h>
#include <ngx_core.h>

/**
 * 创建链表
 */
ngx_list_t *
ngx_list_create(ngx_pool_t *pool, ngx_uint_t n, size_t size)
{
    ngx_list_t  *list;
    /* 从内存池上面分配一块内存，存储ngx_list_t数据结构 */
    list = ngx_palloc(pool, sizeof(ngx_list_t));
    if (list == NULL) {
        return NULL;
    }
     /* 分配一个链表节点的内存块。内存大小  n * size*/
    list->part.elts = ngx_palloc(pool, n * size);
    if (list->part.elts == NULL) {
        return NULL;
    }

    list->part.nelts = 0;       /* 使用的元素个数 */
    list->part.next = NULL;     /* 下一个节点 */
    list->last = &list->part;   /* 最后一个节点地址 */
    list->size = size;          /* 每个元素的大小	*/
    list->nalloc = n;           /* 分配多少个 */
    list->pool = pool;          /* 线程池 */

    return list;
}

/* 添加一个元素 */
void *
ngx_list_push(ngx_list_t *l)
{
    void             *elt;
    ngx_list_part_t  *last;

    last = l->last;
    /* 如果最后一个链表节点的元素已经用完，则需要创建一个新的链表*/
    if (last->nelts == l->nalloc) {

        /* the last part is full, allocate a new list part */
        /* 分配一块内存，存储ngx_list_part_t数据结构 */
        last = ngx_palloc(l->pool, sizeof(ngx_list_part_t));
        if (last == NULL) {
            return NULL;
        }
         /* 分配一个链表节点的内存块。内存大小  n * size*/
        last->elts = ngx_palloc(l->pool, l->nalloc * l->size);
        if (last->elts == NULL) {
            return NULL;
        }

        last->nelts = 0;
        last->next = NULL;

        l->last->next = last;
        l->last = last;
    }
     /* 返回元素指针 */
    elt = (char *) last->elts + l->size * last->nelts;
    last->nelts++;

    return elt;
}
