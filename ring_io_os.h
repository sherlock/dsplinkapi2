/*
 * Title: Ring_io_os
 * Created By: Shougang SHI
 * Creation Date: 11/01/2011

 * Description: OS specific definitions for the Ring_IO
 *
 * Revision: v0.00 - 11/01/2011 - Initial release
 */

#ifndef RING_IO_OS_H
#define RING_IO_OS_H

#include <sys/types.h>

/*  ----------------------------------- DSP/BIOS Link                 */
#include <dsplink.h>

/** ============================================================================
 *  @func   atoi
 *
 *  @desc   Extern declaration for function that converts a string into an
 *          integer value.
 *
 *  @arg    str
 *              String representation of the number.
 *
 *  @ret    <valid integer>
 *              If the 'initial' part of the string represents a valid integer
 *          0
 *              If the string passed does not represent an integer or is NULL.
 *
 *  @enter  None
 *
 *  @leave  None
 *
 *  @see    None
 *  ============================================================================
 */
extern int atoi (const char * str) ;
/** ============================================================================
 *  @func   RING_IO_Atoi
 *
 *  @desc   This function converts a string into an integer value.
 *
 *  @arg    str
 *              String representation of the number.
 *
 *  @ret    <valid integer>
 *              If the 'initial' part of the string represents a valid integer
 *          0
 *              If the string passed does not represent an integer or is NULL.
 *
 *  @enter  None
 *
 *  @leave  None
 *
 *  @see    None
 *  ============================================================================
 */
#define RING_IO_Atoi atoi

/** ============================================================================
 *  @func   RING_IO_IntToString
 *
 *  @desc   This function converts an integer value into a string.
 *
 *  @arg    num
 *              The number that neesd to be converted to string.
 *  @arg    str
 *              String representation of the number.
 *
 *  @ret    None
 *
 *  @enter  None
 *
 *  @leave  None
 *
 *  @see    None
 *  ============================================================================
 */
NORMAL_API
Void
RING_IO_IntToString (IN Int num, OUT Char8 * str) ;

/** ============================================================================
 *  @func   RING_IO_Atoll
 *
 *  @desc   Converts ascii to long int
 *
 *  @ret    <valid integer>
 *              If the 'initial' part of the string represents a valid integer
 *          0
 *              If the string passed does not represent an integer or is NULL.
 *
 *  @enter  None
 *
 *  @leave  None
 *
 *  @see    None
 *  ============================================================================
 */
NORMAL_API
Uint32
RING_IO_Atoll (Char8 * str) ;

/** ============================================================================
 *  @func   RING_IO_CreateSem
 *
 *  @desc   This function creates a semaphore.
 *
 *  @arg    semPtr
 *              Location to receive the semaphore object.
 *
 *  @ret    DSP_SOK
 *              Operation successfully completed.
 *          DSP_EFAIL
 *              General failure.
 *
 *  @enter  None
 *
 *  @leave  None
 *
 *  @see    None
 *  ============================================================================
 */
NORMAL_API
DSP_STATUS
RING_IO_CreateSem (OUT Pvoid * semPtr) ;

/** ============================================================================
 *  @func   RING_IO_DeleteSem
 *
 *  @desc   This function deletes a semaphore.
 *
 *  @arg    semHandle
 *              Pointer to the semaphore object to be deleted.
 *
 *  @ret    DSP_SOK
 *              Operation successfully completed.
 *          DSP_EFAIL
 *              General failure.
 *
 *  @enter  None
 *
 *  @leave  None
 *
 *  @see    None
 *  ============================================================================
 */
NORMAL_API
DSP_STATUS
RING_IO_DeleteSem (IN Pvoid semHandle) ;

/** ============================================================================
 *  @func   RING_IO_WaitSem
 *
 *  @desc   This function waits on a semaphore.
 *
 *  @arg    semHandle
 *              Pointer to the semaphore object to wait on.
 *
 *  @ret    DSP_SOK
 *              Operation successfully completed.
 *          DSP_EFAIL
 *              General failure.
 *
 *  @enter  None
 *
 *  @leave  None
 *
 *  @see    None
 *  ============================================================================
 */
NORMAL_API
DSP_STATUS
RING_IO_WaitSem (IN Pvoid semHandle) ;

/** ============================================================================
 *  @func   RING_IO_PostSem
 *
 *  @desc   This function posts a semaphore.
 *
 *  @arg    semHandle
 *              Pointer to the semaphore object to be posted.
 *
 *  @ret    DSP_SOK
 *              Operation successfully completed.
 *          DSP_EFAIL
 *              General failure.
 *
 *  @enter  None
 *
 *  @leave  None
 *
 *  @see    None
 *  ============================================================================
 */
NORMAL_API
DSP_STATUS
RING_IO_PostSem (IN Pvoid semHandle) ;





#endif
