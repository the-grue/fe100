/*  fe100.h
 *  Header file for the fe100 driver for Minix 3
 *  This driver is for the 3Com 3c905C PCI Fast 10/100 Ethernet Adapter
 *    -- possibly other adapters as coded/tested/verified
 *  
 *  Coded by James T. Sprinkle (thegrueking@gmail.com)
 *                             (the-grue@hotmail.com)
 *
 *  Based on 3Com document Part Number 89-0931-000 Published 9/99
 *
 */

#ifndef FE100
#define FE100

/*  Host Register Variables (offsets)
 *
 *  See page 23 of document for more information
 */

#define HR_TXPKTID			0x18	/* 8bit */
#define HR_TIMER			0x1A	/* 8bit */
#define HR_TXSTATUS			0x1B	/* 8bit */

#define HR_INTSTATUSAUTO		0x1E	/* 16bit */

#endif
