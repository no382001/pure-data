#ifndef _RINGBUFFER_H
#define _RINGBUFFER_H
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

/*
 * ringbuffer.h
 * Ring Buffer utility..
 *
 * Author: Phil Burk, http://www.softsynth.com
 *
 * This program is distributed with the PortAudio Portable Audio Library.
 * For more information see: http://www.audiomulch.com/portaudio/
 * Copyright (c) 1999-2000 Ross Bencina and Phil Burk
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files
 * (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of the Software,
 * and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * Any person wishing to distribute modifications to the Software is
 * requested to send the modifications to the original developer so that
 * they can be incorporated into the canonical version.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR
 * ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */

typedef struct
{
    long   bufferSize;          /* Number of bytes in FIFO.
                                    Set by sys_ringbuf_init. */
    volatile long   writeIndex; /* Index of next writable byte.
                                    Set by sys_ringbuf_AdvanceWriteIndex. */
    volatile long   readIndex;  /* Index of next readable byte.
                                    Set by sys_ringbuf_AdvanceReadIndex. */
} sys_ringbuf;

/* Initialize Ring Buffer. */
long sys_ringbuf_init(volatile sys_ringbuf *rbuf, long numBytes,
    volatile char *dataPtr, long nfill);

/* Return number of bytes available for writing. */
long sys_ringbuf_getwriteavailable(volatile sys_ringbuf *rbuf );
/* Return number of bytes available for read. */
long sys_ringbuf_getreadavailable(volatile sys_ringbuf *rbuf );
/* Return bytes written. */
long sys_ringbuf_write(volatile sys_ringbuf *rbuf, const void *data,
    long numBytes, volatile char *buffer);
/* Return bytes read. */
long sys_ringbuf_read(volatile sys_ringbuf *rbuf, void *data, long numBytes,
    volatile char *buffer);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* _RINGBUFFER_H */
