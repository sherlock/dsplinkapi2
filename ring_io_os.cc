/*
 * Title: Ring_io_os
 * Created By: Shougang SHI
 * Creation Date: 11/01/2011

 * Description: OS specific definitions for the Ring_IO
 *
 * Revision: v0.00 - 11/01/2011 - Initial release
 */
/*  ----------------------------------- OS Specific Headers           */
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <semaphore.h>
#include <stdlib.h>
#include <pthread.h>
#include <sched.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

/*  ----------------------------------- DSP/BIOS Link                 */
#include <dsplink.h>
#include <proc.h>
/*  ----------------------------------- Application Header            */
#include <ring_io_os.h>

/** ============================================================================
 *  @func   RING_IO_0Print
 *
 *  @desc   Print a message without any arguments.
 *
 *  @modif  None
 *  ============================================================================
 */
NORMAL_API
Void RING_IO_0Print(Char8 * str) {
	printf(str);
}

/** ============================================================================
 *  @func   RING_IO_1Print
 *
 *  @desc   Print a message with one arguments.
 *
 *  @modif  None
 *  ============================================================================
 */
NORMAL_API
Void RING_IO_1Print(Char8 * str, Uint32 arg) {
	printf(str, arg);
}

/** ============================================================================
 *  @func   RING_IO_IntToString
 *
 *  @desc   This function converts an integer value into a string.
 *
 *  @modif  None
 *  ============================================================================
 */
NORMAL_API
Void
RING_IO_IntToString (IN Int num, OUT Char8 * str)
{
	/*  ------------------------------------------------------------------------
	 *  There can be a max of 7 char str for signed int including terminator
	 *  so we use a temp string of 7 char. The index is to the rightmost space
	 *  ie. 5. We divide the number by 10, and successively store the remainder
	 *  in the rightmost space while decrementing the counter. Later we add the
	 *  sign if required.
	 *  ------------------------------------------------------------------------
	 */
	Int16 sign = 0;
	Char8 remainder = 0;
	char temp [11] = {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','\0'};
	Int16 index = 9;

	sign = (num < 0) ? -1 : 1;
	num = num * sign;

	do {
		remainder = num % 10;
		temp [index] = '0' + remainder;
		num = num / 10;
		index--;
	}while ((num > 0)&& (index >= 0));

	if (sign == -1) {
		temp [index] = '-';
	}
	else {
		index++;
	}

	strncpy (str, &(temp [index]), 11);
}

/** ============================================================================
 *  @func   RING_IO_Atoll
 *
 *  @desc   Converts ascii to long int
 *
 *  @modif  None
 *  ============================================================================
 */
NORMAL_API
Uint32 RING_IO_Atoll(Char8 * str) {
	Uint32 val = 0;
	val = strtoll(str, NULL, 16);
	return val;
}

/** ============================================================================
 *  @func   RING_IO_Sleep
 *
 *  @desc   Sleeps for the specified number of microseconds.
 *
 *  @modif  None
 *  ============================================================================
 */
NORMAL_API
Void RING_IO_Sleep(Uint32 uSec) {
	usleep(uSec);
}


/** ============================================================================
 *  @func   RING_IO_CreateSem
 *
 *  @desc   This function creates a semaphore.
 *
 *  @modif  None
 *  ============================================================================
 */
NORMAL_API
DSP_STATUS
RING_IO_CreateSem (OUT Pvoid * semPtr)
{
	DSP_STATUS status = DSP_SOK;
	RING_IO_SemObject * semObj;
	int osStatus;

	semObj = malloc (sizeof (RING_IO_SemObject));
	if (semObj != NULL) {
		osStatus = sem_init (&(semObj->sem), 0, 0);
		if (osStatus < 0) {
			status = DSP_EFAIL;
		}
		else {
			*semPtr = (Pvoid) semObj;
		}
	}
	else {
		*semPtr = NULL;
		status = DSP_EFAIL;
	}

	return (status);
}
/** ============================================================================
 *  @func   RING_IO_DeleteSem
 *
 *  @desc   This function deletes a semaphore.
 *
 *  @arg    semHandle
 *              Pointer to the semaphore object to be deleted.
 *
 *  @modif  None
 *  ============================================================================
 */
NORMAL_API
DSP_STATUS
RING_IO_DeleteSem (IN Pvoid semHandle)
{
	DSP_STATUS status = DSP_SOK;
	RING_IO_SemObject * semObj = semHandle;
	int osStatus;

	osStatus = sem_destroy (&(semObj->sem));
	if (osStatus < 0) {
		status = DSP_EFAIL;
	}

	free (semObj);

	return (status);
}

/** ============================================================================
 *  @func   RING_IO_WaitSem
 *
 *  @desc   This function waits on a semaphore.
 *
 *  @modif  None
 *  ============================================================================
 */
NORMAL_API
DSP_STATUS
RING_IO_WaitSem (IN Pvoid semHandle)
{
	DSP_STATUS status = DSP_SOK;
	RING_IO_SemObject * semObj = semHandle;
	int osStatus;

	osStatus = sem_wait (&(semObj->sem));
	if (osStatus < 0) {
		status = DSP_EFAIL;
	}

	return (status);
}

/** ============================================================================
 *  @func   RING_IO_PostSem
 *
 *  @desc   This function posts a semaphore.
 *
 *  @modif  None
 *  ============================================================================
 */
NORMAL_API
DSP_STATUS
RING_IO_PostSem (IN Pvoid semHandle)
{
	DSP_STATUS status = DSP_SOK;
	RING_IO_SemObject * semObj = semHandle;
	int osStatus;

	osStatus = sem_post (&(semObj->sem));
	if (osStatus < 0) {
		status = DSP_EFAIL;
	}

	return (status);
}



















