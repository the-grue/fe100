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

#define HR_DMACTRL			0x20	/* 32bit */

#define HR_DNLISTPTR			0x24	/* 32bit */

#define HR_DNBURSTTHRESH		0x2A	/* 8bit */

#define HR_DNPRIORITYTHRESH		0x2C	/* 8bit */
#define HR_DNPOLL			0x2D	/* 8bit */

#define HR_UPPKTSTATUS			0x30	/* 32bit */

#define HR_FREETIMER			0x34	/* 16bit */
#define HR_COUNTDOWN			0x36	/* 16bit */

#define HR_UPLISTPTR			0x38	/* 32bit */

#define HR_UPPRIORITYTHRESH		0x3C	/* 8bit */
#define HR_UPPOLL			0x3D	/* 8bit */
#define HR_UPBURSTTHRESH		0x3E	/* 8bit */

#define HR_REALTIMECNT			0x40	/* 32bit */

#define HR_CONFIGADDRESS		0x44	/* 8bit */

#define HR_CONFIGDATA			0x48	/* 8bit */

#define HR_DEBUGDATA			0x70	/* 32bit */

#define HR_DEBUGCONTROL			0x74	/* 16bit */

#define HR_DNMAXBURST			0x78	/* 16bit */
#define HR_UPMAXBURST			0x7A	/* 16bit */

#define HR_POWERMGMTCTRL		0x7C	/* 16bit */

/*  Register Window Layout (offsets)
 *
 *  See page 24 of document for more information
 */

#define INTSTATUSCOMMAND		0xE	/* 16bit */

#define W0_BIOSROMADDR			0x4	/* 32bit */
#define W0_BIOSROMDATA			0x8	/* 8bit */
#define W0_EEPROMCOMMAND		0xA	/* 16bit */
#define W0_EEPROMDATA			0xC	/* 16bit */

#define W1_SMBFIFODATA			0x0	/* 8bit */
#define W1_SMBADDRESS			0x1	/* 8bit */
#endif
