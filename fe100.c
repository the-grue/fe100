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
	printf("%s is starting\n", argv[0]);
#endif

	while(TRUE)
	{
		;	
	}

#ifdef DEBUG
	printf("%s is terminating\n", argv[0]);
#endif

	return EXIT_SUCCESS;
}

static void sef_local_startup()
{
	/*  Let SEF perform startup.  */
	sef_startup();
}
