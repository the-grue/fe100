/*  fe100.c
 *  Code file for the fe100 driver for Minix 3
 *  This driver is for the 3Com 3c905C PCI Fast 10/100 Ethernet Adapter
 *    -- possibly other adapters as coded/tested/verified
 *  
 *  Coded by James T. Sprinkle (thegrueking@gmail.com)
 *                             (the-grue@hotmail.com)
 *
 *  Based on 3Com document Part Number 89-0931-000 Published 9/99
 *
 */

#include <minix/drivers.h>
#include <minix/netdriver.h>

#include <stdlib.h>
#include <net/hton.h>
#include <net/gen/ether.h>
#include <net/gen/eth_io.h>
#include <machine/pci.h>
#include <minix/ds.h>
#include <minix/endpoint.h>

#include <timers.h>

#include "fe100.h"

int main(int argc, char **argv)
{
	message m;
	int ipc_status;
	int r;

	/* SEF local startup.  */
	env_setargs(argc, argv);
	sef_local_startup();	

#ifdef DEBUG
	printf("fe100 is starting\n");
#endif

	while(TRUE)
	{
		;	
	}

	return EXIT_SUCCESS;
}

static void sef_local_startup()
{
	/* Register init callbacks. */
	sef_setcb_init_fresh(sef_cb_init_fresh);
	sef_setcb_init_lu(sef_cb_init_fresh);
	sef_setcb_init_restart(sef_cb_init_fresh);

	/* Register live update callbacks. */
	sef_setcb_lu_prepare(sef_cb_lu_prepare_always_ready);
	sef_setcb_lu_state_isvalid(sef_cb_lu_state_isvalid_workfree);

	/* Register signal callbacks. */
	sef_setcb_signal_handler(sef_cb_signal_handler);

	/*  Let SEF perform startup.  */
	sef_startup();
}

static int sef_cb_init_fresh(int UNUSED(type), sef_init_info_t *UNUSED(info))
{
	/* Initialize the fe100 driver. */
        long v;
        int r;
        vir_bytes ft;

        system_hz = sys_hz();

        v = 0;
        (void) env_parse("instance", "d", 0, &v, 0, 255);
        fe100_instance = (int) v;

        ft = sizeof(*fe100_state);

        if(!(fe100_state = alloc_contig(ft, 0, NULL)))
                panic("couldn't allocate table: %d", ENOMEM);

        memset(fe100_state, 0, ft);

        if((r=tsc_calibrate()) != OK)
                panic("tsc_calibrate failed: %d", r);

        /* Announce we are up! */
        netdriver_announce();

        return(OK);
}

static void sef_cb_signal_handler(int signo)
{
        port_t port;
        fe100_t *fp;

        /* Only check for termination signal, ignore anything else. */
        if (signo != SIGTERM) return;

        fp= fe100_state;
/*
        if ((fp->fe100_mode == FM_ENABLED) && (fp->fe100_flags & FF_ENABLED)) {
                port= fp->fe100_base_port;

                \* Reset device *\
                if (debug)
                        printf("%s: resetting device\n", fp->fxp_name);
                fxp_outl(port, CSR_PORT, CP_CMD_SOFT_RESET);
        }
*/

#ifdef DEBUG
	printf("fe100 is terminating\n");
#endif

        exit(0);
}

