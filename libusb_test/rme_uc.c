
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>
#include <libusb-1.0/libusb.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>

#include "rme_uc.h"
#include "usb.h"
#include "FirefaceUSB.h"



#define EP_DATA_IN	0x82
#define EP_ISO_IN	0x86

#define EP_ISO_OUT	0x01	/* mod */

static int do_exit = 0;
static struct libusb_device_handle *devh = NULL;

static unsigned long /*num_bytes = 0,*/ num_xfer = 0;
static struct timeval tv_start;

static void cb_xfr(struct libusb_transfer *xfr)
{

	if (xfr->status == LIBUSB_TRANSFER_TIMED_OUT) {
		fprintf(stderr, "TX %li : TIMED_OUT\n", num_xfer);
	}

	num_xfer++;
/*	unsigned int i;

	if (xfr->status != LIBUSB_TRANSFER_COMPLETED) {
		fprintf(stderr, "transfer status %d\n", xfr->status);
//		libusb_free_transfer(xfr);
//		exit(3);
	}

	if (xfr->type == LIBUSB_TRANSFER_TYPE_ISOCHRONOUS) {
		for (i = 0; i < xfr->num_iso_packets; i++) {
			struct libusb_iso_packet_descriptor *pack = &xfr->iso_packet_desc[i];

			if (pack->status != LIBUSB_TRANSFER_COMPLETED) {
				fprintf(stderr, "Error: pack %u status %d\n", i, pack->status);
				exit(5);
			}

//			printf("pack%u length:%u, actual_length:%u\n", i, pack->length, pack->actual_length);
		}
	}

//	printf("length:%u, actual_length:%u\n", xfr->length, xfr->actual_length);
	for (i = 0; i < xfr->actual_length; i++) {
		printf("%02x", xfr->buffer[i]);
		if (i % 16)
			printf("\n");
		else if (i % 8)
			printf("  ");
		else
			printf(" ");
	}
	num_bytes += xfr->actual_length;
	num_xfer++;

	if (libusb_submit_transfer(xfr) < 0) {
		fprintf(stderr, "error re-submitting URB\n");
		exit(1);
	}
*/
}



// static int benchmark_in(uint8_t ep)
// {
// 	static uint8_t buf[2048];
// 	static struct libusb_transfer *xfr;
// 	int num_iso_pack = 0;
//
// 	if (ep == EP_ISO_IN)
// 		num_iso_pack = 16;
//
// 	xfr = libusb_alloc_transfer(num_iso_pack);
// 	if (!xfr)
// 		return -ENOMEM;
//
// 	if (ep == EP_ISO_IN) {
// 		libusb_fill_iso_transfer(xfr, devh, ep, buf,
// 				sizeof(buf), num_iso_pack, cb_xfr, NULL, 0);
// 		libusb_set_iso_packet_lengths(xfr, sizeof(buf)/num_iso_pack);
// 	} else
// 		libusb_fill_bulk_transfer(xfr, devh, ep, buf,
// 				sizeof(buf), cb_xfr, NULL, 0);
//
// 	gettimeofday(&tv_start, NULL);
//
// 	/* NOTE: To reach maximum possible performance the program must
// 	 * submit *multiple* transfers here, not just one.
// 	 *
// 	 * When only one transfer is submitted there is a gap in the bus
// 	 * schedule from when the transfer completes until a new transfer
// 	 * is submitted by the callback. This causes some jitter for
// 	 * isochronous transfers and loss of throughput for bulk transfers.
// 	 *
// 	 * This is avoided by queueing multiple transfers in advance, so
// 	 * that the host controller is always kept busy, and will schedule
// 	 * more transfers on the bus while the callback is running for
// 	 * transfers which have completed on the bus.
// 	 */
//
// 	return libusb_submit_transfer(xfr);
// }

int tx_rate = 1000;	// per sec rate
int tx_lt_cnt = 0;	// last ten count
uint32_t unkId = 0x16;


void proc_sample( uint32_t *buf, uint32_t *pcm ) {
//	*buf = le2be( *pcm );
	*buf = *pcm;
}

void fill_audio_data( uint32_t *buf, size_t buf_sz, uint32_t *pcm, struct libusb_transfer *xfr ) {

	uint32_t i = 0, /*y = 0,*/ x = 0, z = 0, ckCnt = 0/*, offset = 0*/;

	while ( i < (buf_sz/4) ) {

		buf[i+0] = unkId;


		if ( buf_sz == 3420 && ckCnt == 1 ) {

			for ( x=1; x < (6 * 19); x+=19 ) {
				proc_sample( &buf[i+x], &pcm[z] );
				proc_sample( &buf[i+x+1], &pcm[z]);
				z++;
//				buf[i+x] = pcm[z++];// << 0x16;
//				buf[i+x+1] = pcm[z++];// << 0x16;
			}

			i += x-1;

			xfr->iso_packet_desc[ckCnt].length = 0x01c8;
			unkId += 6;

			ckCnt++;

		} else if ( ckCnt % 2 ) {

			for ( x=1; x < (5 * 19); x+=19 ) {
//				proc_sample();
//				proc_sample( &buf[i+x], &pcm[z++] );
				proc_sample( &buf[i+x], &pcm[z] );
				proc_sample( &buf[i+x+1], &pcm[z]);
				z++;

//				buf[i+x] = pcm[z++];// << 0x16;
//				buf[i+x+1] = pcm[z++];// << 0x16;
			}

			i += x-1;

			xfr->iso_packet_desc[ckCnt].length = 0x017c;
			unkId += 5;

			ckCnt++;

		} else {

			for ( x=1; x < (6 * 19 ); x+=19 ) {
//				proc_sample( &buf[i+x], &pcm[z++] );
				proc_sample( &buf[i+x], &pcm[z] );
				proc_sample( &buf[i+x+1], &pcm[z]);
				z++;

//				buf[i+x] = pcm[z++];// << 0x16;
//				buf[i+x+1] = pcm[z++];// << 0x16;
			}

			i += x-1;

			xfr->iso_packet_desc[ckCnt].length = 0x01c8;
			unkId += 6;

			ckCnt++;
		}
//		printf("new iso %d\n", ckCnt);
	}
}


// size_t get_audio_data_from_file( const char *filename, uint32_t **buf )
// {
// 	size_t size = 0;
//
// 	FILE *f = fopen(filename, "rb");
//
// 	if (f == NULL)
// 	{
// 		*buf = NULL;
// 		return -1; // -1 means file opening fail
// 	}
//
// 	fseek(f, 0, SEEK_END);
//
// 	size = ftell(f);
//
// 	fseek(f, 0, SEEK_SET);
//
// 	*buf = malloc(size+1);
//
// 	if (size/sizeof(uint32_t) != fread(*buf, sizeof(uint32_t), size/sizeof(uint32_t), f))
// 	{
// 		free(*buf);
// 		*buf = NULL;
// 		return -2; // -2 means file reading fail
// 	}
//
// 	fclose(f);
// 	// (*buf)[size] = 0;
// 	return size;
// }



static int send_iso_out(uint8_t ep)
{

	uint32_t buf[855];
	uint32_t pcm[45];				/* TODO: when back to read() */

	static struct libusb_transfer *xfr;
	int num_iso_pack = 0;

	int buf_len = 0;
	int pcm_len = 0;

	if ( tx_lt_cnt == 9 )
	{
		buf_len = 3420;
		pcm_len = 180;
		tx_lt_cnt  = 0;
	}
	else
	{
		buf_len = 3344;
		pcm_len = 176;
		tx_lt_cnt++;
	}

	if ( unkId > 0xffff )
		unkId = 0x16;

//	int chunkCount = 0;
//	int i = 0;
//	int y = 0;

	num_iso_pack = 8;

	xfr = libusb_alloc_transfer(num_iso_pack);
	if (!xfr)
		return -ENOMEM;

	libusb_fill_iso_transfer(xfr, devh, ep, (unsigned char *)buf,
		buf_len, num_iso_pack, cb_xfr, NULL, 0);

	xfr->flags = LIBUSB_TRANSFER_FREE_TRANSFER;

	memset((unsigned char *)pcm, 0, pcm_len);
	memset((unsigned char *)buf, 0, buf_len);


	// uint32_t *audioData = NULL;

	// size_t audioDataSize = get_audio_data_from_file( "../1CH_44100_f32le_RIFF.raw", &audioData );

	// printf("coucou\n");


    //
	if ( read( 0, pcm, pcm_len ) == 0 ) {
		printf("*** EOF ***\n");
		do_exit = 1;
		return 1;
	}

/*
	int i = 0;
	while ( i < buf_len/4 ) {
		printf("0x%04x  0x%04x  0x%04x  0x%04x  0x%04x  0x%04x  0x%04x  0x%04x\n",
			buf[i++], buf[i++], buf[i++], buf[i++], buf[i++], buf[i++], buf[i++], buf[i++]);
//		i++;
	}

//	return -1;
	exit(1);
*/
//	printf("buf_len : %d\n", buf_len);


	fill_audio_data( buf, buf_len, pcm, xfr );

	gettimeofday(&tv_start, NULL);

	/* NOTE: To reach maximum possible performance the program must
	 * submit *multiple* transfers here, not just one.
	 *
	 * When only one transfer is submitted there is a gap in the bus
	 * schedule from when the transfer completes until a new transfer
	 * is submitted by the callback. This causes some jitter for
	 * isochronous transfers and loss of throughput for bulk transfers.
	 *
	 * This is avoided by queueing multiple transfers in advance, so
	 * that the host controller is always kept busy, and will schedule
	 * more transfers on the bus while the callback is running for
	 * transfers which have completed on the bus.
	 */

	libusb_submit_transfer(xfr);

	return 0;
}




// static int send_iso_in(uint8_t ep)
// {
// 	int buf_len = 4064;
// 	uint8_t buf[4064];
// 	// uint32_t buf[4064];
// 	memset((unsigned char *)buf, 0, buf_len);
//
// 	uint32_t pcm[45];				/* TODO: when back to read() */
// 	int pcm_len = 45;
//
// 	static struct libusb_transfer *xfr;
// 	int num_iso_pack = 8;
//
//
// 	xfr = libusb_alloc_transfer(num_iso_pack);
// 	if (!xfr)
// 		return -ENOMEM;
//
//
// 	libusb_fill_iso_transfer(xfr, devh, ep, buf,
// 		buf_len, num_iso_pack, cb_xfr, NULL, 0);
//
// /*
// 	xfr->iso_packet_desc[0].length = 0x01b4;
// 	xfr->iso_packet_desc[1].length = 0x016c;
// 	xfr->iso_packet_desc[2].length = 0x01b4;
// 	xfr->iso_packet_desc[3].length = 0x016c;
// 	xfr->iso_packet_desc[4].length = 0x01b4;
// 	xfr->iso_packet_desc[5].length = 0x016c;
// 	xfr->iso_packet_desc[6].length = 0x01b4;
// 	xfr->iso_packet_desc[7].length = 0x016c;
// */
//
// 	xfr->iso_packet_desc[0].length = 0x01fc;
// 	xfr->iso_packet_desc[1].length = 0x01fc;
// 	xfr->iso_packet_desc[2].length = 0x01fc;
// 	xfr->iso_packet_desc[3].length = 0x01fc;
// 	xfr->iso_packet_desc[4].length = 0x01fc;
// 	xfr->iso_packet_desc[5].length = 0x01fc;
// 	xfr->iso_packet_desc[6].length = 0x01fc;
// 	xfr->iso_packet_desc[7].length = 0x01fc;
//
// 	xfr->flags = LIBUSB_TRANSFER_FREE_TRANSFER;
//
// 	memset((unsigned char *)pcm, 0, pcm_len);
// 	memset((unsigned char *)buf, 0, buf_len);
//
//
// 	if ( read( 0, pcm, pcm_len ) == 0 ) {
// 		printf("*** EOF ***\n");
// 		do_exit = 1;
// 	}
// /*
// 	int i = 0;
// 	while ( i < buf_len/4 ) {
// 		printf("0x%04x  0x%04x  0x%04x  0x%04x  0x%04x  0x%04x  0x%04x  0x%04x\n",
// 			buf[i++], buf[i++], buf[i++], buf[i++], buf[i++], buf[i++], buf[i++], buf[i++]);
// //		i++;
// 	}
//
// //	return -1;
// 	exit(1);
// */
// //	printf("buf_len : %d\n", buf_len);
//
// 	fill_audio_data( (uint32_t*)buf, buf_len, pcm, xfr );
//
// 	gettimeofday(&tv_start, NULL);
//
// 	/* NOTE: To reach maximum possible performance the program must
// 	 * submit *multiple* transfers here, not just one.
// 	 *
// 	 * When only one transfer is submitted there is a gap in the bus
// 	 * schedule from when the transfer completes until a new transfer
// 	 * is submitted by the callback. This causes some jitter for
// 	 * isochronous transfers and loss of throughput for bulk transfers.
// 	 *
// 	 * This is avoided by queueing multiple transfers in advance, so
// 	 * that the host controller is always kept busy, and will schedule
// 	 * more transfers on the bus while the callback is running for
// 	 * transfers which have completed on the bus.
// 	 */
// 	printf("before libusb_submit_transfer()\n");
// 	libusb_submit_transfer(xfr);
// 	printf("after  libusb_submit_transfer()\n");
//
// 	return 0;
// }



// static void measure(void)
// {
// 	struct timeval tv_stop;
// 	unsigned int diff_msec;
//
// 	gettimeofday(&tv_stop, NULL);
//
// 	diff_msec = (tv_stop.tv_sec - tv_start.tv_sec)*1000;
// 	diff_msec += (tv_stop.tv_usec - tv_start.tv_usec)/1000;
//
// 	printf("\n%lu transfers (total %lu bytes) in %u miliseconds => %lu bytes/sec\n",
// 		num_xfer, num_bytes, diff_msec, (num_bytes*1000)/diff_msec);
// }

static void sig_hdlr( int signum )
{
	switch ( signum )
	{
		case SIGINT:
//			measure();
			do_exit = 1;
			break;
	}
}


int main( int argc, char **argv )
{

	// SHUT GCC UP
	if ( argc > 0 ) argv[0] = argv[0];

	// uint16_t val = 0x200;
	int rc = 0;

	// int rme_init_iface( libusb_device_handle *dev ) {

	// devh = dev;


	rc = libusb_init(NULL);

	if (rc < 0) {
		fprintf(stderr, "Error initializing libusb: %s\n", libusb_error_name(rc));
		exit(1);
	}

	libusb_set_debug(NULL, LIBUSB_LOG_LEVEL_WARNING);

	devh = libusb_open_device_with_vid_pid(NULL, 0x0424, 0x3fc6);

	if (!devh) {
		fprintf(stderr, "Error finding USB device : Running Offline\n");
		// goto out;
	}

	printf("claiming\n");

	if ( devh )
		rc = libusb_claim_interface(devh, 0);

	if (rc < 0) {
		fprintf(stderr, "Error claiming interface: %s\n", libusb_error_name(rc));
		goto out;
	}

	if ( devh )
		libusb_set_interface_alt_setting( devh, rc, 1 );



	/*
		Get Hardware Revision (Firmware Version)
	*/

	uint32_t rev = 0;

	hwGetRevision( devh, &rev );
	printf("Firmware Version : %d (0x%02x)\n", rev, rev);



	/*
		Init Hardware
	*/

	hwInitHardware( devh );



	/*
		Get Sample Rate
	*/

	int rate = hwGetRate( devh, 1 );

	printf("Sample Rate : %d\n", rate);




	goto out;

	goto SEND_AUDIO;


	/*
		call hwSetSampleRate()
		seems to always init with 44100 Hz :

		0x00007ec3	mov	rdi, qword [ds:r15+0x120]		; argument #1 for method
		0x00007eca	movzx	edx, word [ds:r15+0x128]		; argument #3 for method
		0x00007ed2	mov	esi, 0xac44				; argument #2 for method
		0x00007ed7	call	__Z15hwSetSampleRateP11IOUSBDevicejt
	*/

	hwSetSampleRate( devh, 44100 );


	/*
		do some stuff seen in wireshark.
		This was not found in original drivers yet..

		EDIT: NOW IT IS, MOTHERFUCKAAAAAAA !!!
	*/

	printf("\n");

	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x000a, 0x0000, 0, NULL );	// set MIC_1 GAIN to 10
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x000a, 0x0001, 0, NULL );	// set MIC_2 GAIN to 10
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x0000, 0x0002, 0, NULL );	// set LIN_3 GAIN to  0
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x0000, 0x0003, 0, NULL );	// set LIN_4 GAIN to  0

	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x002e, 0x0004, 0, NULL );
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x002e, 0x0005, 0, NULL );
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x002e, 0x0006, 0, NULL );
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x002e, 0x0007, 0, NULL );
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x002e, 0x0008, 0, NULL );
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x002e, 0x0009, 0, NULL );
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x002e, 0x000a, 0, NULL );
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x002e, 0x000b, 0, NULL );
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x002e, 0x000c, 0, NULL );
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x002e, 0x000d, 0, NULL );
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x002e, 0x000e, 0, NULL );
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x002e, 0x000f, 0, NULL );
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x002e, 0x0010, 0, NULL );
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x002e, 0x0011, 0, NULL );
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x002e, 0x0012, 0, NULL );
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x002e, 0x0013, 0, NULL );
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x002e, 0x0014, 0, NULL );
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x002e, 0x0015, 0, NULL );

//	usleep(100000);

	// send bulk_in	> 11 EP 0x8b
	// GET_DESCRIPTORS

	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x0006, 0x0014, 0, NULL );
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x0006, 0x0015, 0, NULL );
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x0006, 0x0012, 0, NULL );
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x0006, 0x0013, 0, NULL );
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x0006, 0x0010, 0, NULL );
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x0006, 0x0011, 0, NULL );
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x0006, 0x000e, 0, NULL );
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x0006, 0x000f, 0, NULL );
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x0006, 0x000c, 0, NULL );
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x0006, 0x000d, 0, NULL );
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x0006, 0x0008, 0, NULL );
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x0006, 0x0009, 0, NULL );
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x0006, 0x0006, 0, NULL );
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x0006, 0x0007, 0, NULL );
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x0006, 0x0004, 0, NULL );
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x0006, 0x0005, 0, NULL );
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x0027, 0x000a, 0, NULL );
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x0027, 0x000b, 0, NULL );

	/* set true gain values for inputs 1,2,3,4 */
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x0000, 0x0000, 0, NULL );
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x0000, 0x0001, 0, NULL );
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x0000, 0x0002, 0, NULL );
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x0000, 0x0003, 0, NULL );

	// BULK_IN > 6 EP 0x8§
	// MIDI Stuff > 7 EP 0x07

	// set mixer (routes)

//		printf(" %d ms\n", clock());








/***********************************************************************************************************
					    P L A Y    A U D I O
***********************************************************************************************************/

SEND_AUDIO:


	hwSetSampleRate( devh, 44100 );
	hwMuteChannels( devh, 1 );	// unmute channels



	struct sigaction sigact;

	sigact.sa_handler = sig_hdlr;
	sigemptyset(&sigact.sa_mask);
	sigact.sa_flags = 0;
	sigaction(SIGINT, &sigact, NULL);




	int loop_cnt = 0;

	while (!do_exit) {

		struct timeval timeout;
		timeout.tv_sec = 0;
		timeout.tv_usec = 0;

		// rc = send_iso_in(0x82);
		rc = send_iso_out(0x01);

		// libusb_handle_events_locked( NULL, NULL );

		// rc = send_iso_out(0x82);

		struct timeval tv_mes;
		gettimeofday(&tv_mes, NULL);

		timeout.tv_usec = 1000 - (tv_mes.tv_usec - tv_start.tv_usec);

//		printf("SET TIME_OUT : %d\n", timeout.tv_usec);

		rc = libusb_handle_events_timeout_completed(NULL, &timeout, NULL);

		if (rc != LIBUSB_SUCCESS) {
			printf("LIBUSB ERROR (%d) : %s\n", rc, libusb_error_name( rc ));
			break;
		}

		loop_cnt++;

		if ( loop_cnt == 3000 ) {
//			printf("set level to (0x%04x) %d\n", val, val);
//			send_ctrl_setup_alt( devh, 0x40, 0x1a, val, 0x000a, 0, NULL );
//			send_ctrl_setup_alt( devh, 0x40, 0x1a, val, 0x000b, 0, NULL );
//			send_ctrl_setup_alt( devh, 0x40, 0x12, val, 0x03e6, 0, NULL );
//			send_ctrl_setup_alt( devh, 0x40, 0x12, val, 0x03e7, 0, NULL );

//			val += 5;
//			val -= 50;
//			loop_cnt = 0;
//			hwMuteChannels( devh, 0 );
		} else if ( loop_cnt > 6000 ) {
//			hwMuteChannels( devh, 1 );
			loop_cnt = 0;
		}
	}

	rc = libusb_handle_events( NULL );

	if (rc != LIBUSB_SUCCESS) {
		printf("LIBUSB ERROR (%d) : %s\n", rc, libusb_error_name( rc ));
	}

	hwMuteChannels( devh, 0 );

//	libusb_release_interface(devh, 0);

out:
//	libusb_release_interface(devh, 0);

	if (devh)
		libusb_close(devh);

	libusb_exit(NULL);
	return rc;




	//printf("xxx\n");
	return 0;
}
