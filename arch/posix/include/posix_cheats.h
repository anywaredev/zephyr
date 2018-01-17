/*
 * Copyright (c) 2017 Oticon A/S
 *
 * SPDX-License-Identifier: Apache-2.0
 */


/*
 * Header to be able to compile the Zephyr kernel on top of a POSIX OS
 */

#ifndef _POSIX_CHEATS_H
#define _POSIX_CHEATS_H

#ifdef CONFIG_ARCH_POSIX

#ifndef main
#define main(...) zephyr_app_main(__VA_ARGS__)
#endif

/* For the include/posix/pthreads.h provided with Zephyr,
 * in case somebody would use it, we rename all symbols here adding
 * some prefix, and we ensure this header is included
 */

#define timespec zap_timespec
#define pthread_mutex_t zap_pthread_mutex_t
#define pthread_mutexattr_t    zap_pthread_mutexattr_t
#define pthread_cond_t         zap_pthread_cond_t
#define pthread_condattr_t     zap_pthread_condattr_t
#define pthread_barrier_t      zap_pthread_barrier_t
#define pthread_barrierattr_t  zap_pthread_barrierattr_t
#define pthread_attr_t         zap_pthread_attr_t
#define clockid_t              zap_clockid_t
#define sched_param            zap_sched_param

/* Condition variables */
#define pthread_cond_init(...)        zap_pthread_cond_init(__VA_ARGS__)
#define pthread_cond_destroy(...)     zap_pthread_cond_destroy(__VA_ARGS__)
#define pthread_cond_signal(...)      zap_pthread_cond_signal(__VA_ARGS__)
#define pthread_cond_broadcast(...)   zap_pthread_cond_broadcast(__VA_ARGS__)
#define pthread_cond_wait(...)        zap_pthread_cond_wait(__VA_ARGS__)
#define pthread_cond_timedwait(...)   zap_pthread_cond_timedwait(__VA_ARGS__)
#define pthread_condattr_init(...)    zap_pthread_condattr_init(__VA_ARGS__)
#define pthread_condattr_destroy(...) zap_pthread_condattr_destroy(__VA_ARGS__)
/* Mutex */
#define pthread_mutex_init(...)       zap_pthread_mutex_init(__VA_ARGS__)
#define pthread_mutex_destroy(...)    zap_pthread_mutex_destroy(__VA_ARGS__)
#define pthread_mutex_lock(...)       zap_pthread_mutex_lock(__VA_ARGS__)
#define pthread_mutex_timedlock(...)  zap_pthread_mutex_timedlock(__VA_ARGS__)
#define pthread_mutex_trylock(...)    zap_pthread_mutex_trylock(__VA_ARGS__)
#define pthread_mutex_unlock(...)     zap_pthread_mutex_unlock(__VA_ARGS__)
#define pthread_mutexattr_init(...)   zap_pthread_mutexattr_init(__VA_ARGS__)
#define pthread_mutexattr_destroy(...) \
		zap_pthread_mutexattr_destroy(__VA_ARGS__)
/* Barrier */
#define pthread_barrier_wait(...)     zap_pthread_barrier_wait(__VA_ARGS__)
#define pthread_barrier_init(...)     zap_pthread_barrier_init(__VA_ARGS__)
#define pthread_barrier_destroy(...)  zap_pthread_barrier_destroy(__VA_ARGS__)
#define pthread_barrierattr_init(...) zap_pthread_barrierattr_init(__VA_ARGS__)
#define pthread_barrierattr_destroy(...) \
	zap_pthread_barrierattr_destroy(__VA_ARGS__)

/* Pthread */
#define pthread_attr_init(...)		zap_pthread_attr_init(__VA_ARGS__)
#define pthread_attr_destroy(...)	zap_pthread_attr_destroy(__VA_ARGS__)
#define pthread_attr_getschedparam(...) \
			zap_pthread_attr_getschedparam(__VA_ARGS__)
#define pthread_attr_getstack(...)	zap_pthread_attr_getstack(__VA_ARGS__)
#define pthread_attr_getstacksize(...)	\
			zap_pthread_attr_getstacksize(__VA_ARGS__)
#define pthread_equal(...)		zap_pthread_equal(__VA_ARGS__)
#define pthread_self(...)		zap_pthread_self(__VA_ARGS__)
#define pthread_getschedparam(...)	zap_pthread_getschedparam(__VA_ARGS__)
#define pthread_exit(...)		zap_pthread_exit(__VA_ARGS__)
#define pthread_join(...)		zap_pthread_join(__VA_ARGS__)
#define pthread_detach(...)		zap_pthread_detach(__VA_ARGS__)
#define pthread_cancel(...)		zap_pthread_cancel(__VA_ARGS__)
#define pthread_attr_getdetachstate(...)	\
		zap_pthread_attr_getdetachstate(__VA_ARGS__)
#define pthread_attr_setdetachstate(...)	\
		zap_pthread_attr_setdetachstate(__VA_ARGS__)
#define pthread_attr_setschedparam(...)	\
		zap_pthread_attr_setschedparam(__VA_ARGS__)
#define pthread_attr_setschedpolicy(...)\
		zap_pthread_attr_setschedpolicy(__VA_ARGS__)
#define pthread_attr_getschedpolicy(...)\
		zap_pthread_attr_getschedpolicy(__VA_ARGS__)

#define pthread_attr_setstack(...)	zap_pthread_attr_setstack(__VA_ARGS__)
#define pthread_create(...)		zap_pthread_create(__VA_ARGS__)
#define pthread_setcancelstate(...)	zap_pthread_setcancelstate(__VA_ARGS__)
#define pthread_setschedparam(...)	zap_pthread_setschedparam(__VA_ARGS__)

/* Scheduler */
#define sched_yield(...)		zap_sched_yield(__VA_ARGS__)
#define sched_get_priority_min(...)	zap_sched_get_priority_min(__VA_ARGS__)
#define sched_get_priority_max(...)	zap_sched_get_priority_max(__VA_ARGS__)

/* Sleep */
#define sleep(...)			zap_sleep(__VA_ARGS__)
#define usleep(...)			zap_usleep(__VA_ARGS__)

/* Clock */
#define clock_gettime(...)		zap_clock_gettime(__VA_ARGS__)
#define clock_settime(...)		zap_clock_settime(__VA_ARGS__)

#endif /* CONFIG_ARCH_POSIX */

#endif
