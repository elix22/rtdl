/***********************************************************************************/
/* Copyright (c) 2013, Wictor Lund. All rights reserved.			   */
/* Copyright (c) 2013, Åbo Akademi University. All rights reserved.		   */
/* 										   */
/* Redistribution and use in source and binary forms, with or without		   */
/* modification, are permitted provided that the following conditions are met:	   */
/*      * Redistributions of source code must retain the above copyright	   */
/*        notice, this list of conditions and the following disclaimer.		   */
/*      * Redistributions in binary form must reproduce the above copyright	   */
/*        notice, this list of conditions and the following disclaimer in the	   */
/*        documentation and/or other materials provided with the distribution.	   */
/*      * Neither the name of the Åbo Akademi University nor the		   */
/*        names of its contributors may be used to endorse or promote products	   */
/*        derived from this software without specific prior written permission.	   */
/* 										   */
/* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND */
/* ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED   */
/* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE	   */
/* DISCLAIMED. IN NO EVENT SHALL ÅBO AKADEMI UNIVERSITY BE LIABLE FOR ANY	   */
/* DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES	   */
/* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;	   */
/* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND	   */
/* ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT	   */
/* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS   */
/* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. 		   */
/***********************************************************************************/

#ifndef APP_RTUCONT_CONTQUEUES_H
#define APP_RTUCONT_CONTQUEUES_H

#include <queue.h>

#include <System/types.h>

#define FRAME_COUNTING_FREQUENCY 5
#define RTUCONT_FIXED_UNIT (0x10000)

typedef u_int32_t	measurement_t;
typedef u_int32_t	controlsignal_t;

typedef enum controller_version_t {
	controller_version_1,
	controller_version_2,
	controller_version_3
} controller_version;

extern xQueueHandle	MeasurementQueue;
extern xQueueHandle	ControlSignalQueue;

typedef struct controller_state_v1_t {
	controller_version	ver;
	volatile float		integrator;
} controller_state_v1;

typedef struct controller_state_v2_t {
	controller_version	ver;
	volatile float		integrator;
} controller_state_v2;

typedef struct controller_state_v3_t {
	controller_version	ver;
	volatile float		integrator;
	volatile float		last_mv_u;
} controller_state_v3;


#endif /* APP_RTUCONT_CONTQUEUES_H */
