/*
 * Title: DSPLink RingIO
 * Created By: Shougang SHI
 * Creation Date: 11/01/2011

 * Description: RingIO between ARM and DSP
 *
 * Revision: v0.00 - 11/01/2011 - Initial release
 */


/*  ------------------------ DSP/BIOS Link ----------------------------------*/

#ifndef DSPLink_RingIO_H
#define DSPLink_RingIO_H

/*  ----------------------------------- DSP/BIOS Link                 */
#include <dsplink.h>


class DSPLink_RingIO {
public:
	DSPLink_RingIO();
	virtual ~DSPLink_RingIO();


	NORMAL_API DSP_STATUS RING_IO_Create (IN Uint8 processorId);
	NORMAL_API Void RING_IO_Delete(IN Uint8 processorId);

	NORMAL_API DSP_STATUS RING_IO_WriteClient1_Initial();
	NORMAL_API Uint32 RING_IO_WriteClient1_Task(const char *buf_in,const int len_in, char *buf_out, int len_out);
	NORMAL_API DSP_STATUS RING_IO_WriteClient1_Close();


	NORMAL_API DSP_STATUS RING_IO_WriteClient2_Initial();
	NORMAL_API Uint32 RING_IO_WriteClient2_Task(const char *buf_in,const int len_in, char *buf_out, int len_out);
	NORMAL_API DSP_STATUS RING_IO_WriteClient2_Close();


	STATIC NORMAL_API Void RING_IO_Writer_Notify1(IN RingIO_Handle handle,
			IN RingIO_NotifyParam param,
			IN RingIO_NotifyMsg msg);
	STATIC NORMAL_API Void RING_IO_Writer_Notify2(IN RingIO_Handle handle,
				IN RingIO_NotifyParam param,
				IN RingIO_NotifyMsg msg);
	STATIC NORMAL_API Void RING_IO_Reader_Notify1 (IN RingIO_Handle handle,
			IN RingIO_NotifyParam param,
			IN RingIO_NotifyMsg msg);
	STATIC NORMAL_API Void RING_IO_Reader_Notify2 (IN RingIO_Handle handle,
				IN RingIO_NotifyParam param,
				IN RingIO_NotifyMsg msg);

	void set_dspfilename(char * dspfilename){dspExecutable = dspfilename;}

	void set_RING_IO_BufferSize_Tx1(Uint32 buffersize){
		RING_IO_BufferSize_Tx1 = buffersize;
		RING_IO_BufferSize_Tx1 = DSPLINK_ALIGN (RING_IO_BufferSize_Tx1,
					DSPLINK_BUF_ALIGN);
	}

	void set_RING_IO_BufferSize_Rx1(Uint32 buffersize){
		RING_IO_BufferSize_Rx1 = buffersize;
		RING_IO_BufferSize_Rx1 = DSPLINK_ALIGN (RING_IO_BufferSize_Rx1,
					DSPLINK_BUF_ALIGN);
	}

	void set_RING_IO_BufferSize_Tx2(Uint32 buffersize){
		RING_IO_BufferSize_Tx2 = buffersize;
		RING_IO_BufferSize_Tx2 = DSPLINK_ALIGN (RING_IO_BufferSize_Tx2,
					DSPLINK_BUF_ALIGN);
	}

	void set_RING_IO_BufferSize_Rx2(Uint32 buffersize){
		RING_IO_BufferSize_Rx2 = buffersize;
		RING_IO_BufferSize_Rx2 = DSPLINK_ALIGN (RING_IO_BufferSize_Rx2,
					DSPLINK_BUF_ALIGN);
	}




private:
	Char8 * dspExecutable;

	/*  ============================================================================
	 *  @name   RING_IO_BufferSize
	 *
	 *  @desc   Size of the RingIO Data Buffer to be used for data transfer.
	 *  ============================================================================
	 */
	Uint32 RING_IO_BufferSize_Tx1;
	Uint32 RING_IO_BufferSize_Rx1;
	Uint32 RING_IO_BufferSize_Tx2;
	Uint32 RING_IO_BufferSize_Rx2;
	Uint32 RING_IO_BytesToTransfer1;
	Uint32 RING_IO_BytesToTransfer2;

	/** ============================================================================
	 *  @const  RingIOWriterName
	 *
	 *  @desc   Name of the RingIO used by the application in writer mode.
	 *  ============================================================================
	 */
	Char8 RingIOWriterName1[RINGIO_NAME_MAX_LEN] = "RINGIO1";
	Char8 RingIOWriterName2[RINGIO_NAME_MAX_LEN] = "RINGIO3";


	/** ============================================================================
	 *  @name   RingIOWriterHandle
	 *
	 *  @desc   Handle to the RingIO used by the application in writer mode.
	 *  ============================================================================
	 */
	RingIO_Handle RingIOWriterHandle1 = NULL;
	RingIO_Handle RingIOWriterHandle2 = NULL;

	/** ============================================================================
	 *  @const  RingIOReaderName
	 *
	 *  @desc   Name of the RingIO used by the application in reader mode.
	 *  ============================================================================
	 */
	Char8 RingIOReaderName1[RINGIO_NAME_MAX_LEN] = "RINGIO2";
	Char8 RingIOReaderName2[RINGIO_NAME_MAX_LEN] = "RINGIO4";

	/** ============================================================================
	 *  @name   RingIOReaderHandle
	 *
	 *  @desc   Handle to the RingIO used by the application in reader mode.
	 *  ============================================================================
	 */
	RingIO_Handle RingIOReaderHandle1 = NULL;
	RingIO_Handle RingIOReaderHandle2 = NULL;

	Pvoid semPtrWriter1 = NULL;
	Pvoid semPtrReader1 = NULL;

	Pvoid semPtrWriter2 = NULL;
	Pvoid semPtrReader2 = NULL;

	/** ============================================================================
	 *  @const  fReaderStart
	 *
	 *  @desc   boolean variable to  indicate Gpp reader can start reading.
	 *  ============================================================================
	 */
	Uint32 fReaderStart1 = FALSE;
	Uint32 fReaderStart2 = FALSE;

	/** ============================================================================
	 *  @const  fReaderEnd
	 *
	 *  @desc   boolean variable to  indicate Gpp reader should stop reading.
	 *  ============================================================================
	 */
	Uint32 fReaderEnd1 = FALSE;
	Uint32 fReaderEnd2 = FALSE;

};

#endif
