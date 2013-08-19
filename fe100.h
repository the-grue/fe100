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

#define DEBUG 1

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
#define W1_SMBSTATUS			0x2	/* 16bit */
#define W1_SMBARB			0x4	/* 8bit */
#define W1_SMBDIAG			0x5	/* 8bit */
#define W1_SMBRXBYTES			0x6	/* 16bit */
#define W1_WAKEONTIMER			0x8	/* 16bit */
#define W1_SOSBITS			0xA	/* 8bit */
#define W1_TRIGGERBITS			0xC	/* 16bits */

#define W2_STATIONADDRESSLO		0x0	/* 16bits */
#define W2_STATIONADDRESSMID		0x2	/* 16bits */
#define W2_STATIONADDRESSHI		0x4	/* 16bits */
#define W2_STATIONMASKLO		0x6	/* 16bits */
#define W2_STATIONMASKMID		0x8	/* 16bits */
#define W2_STATIONMASKHI		0xA	/* 16bits */
#define W2_RESETOPTIONS			0xC	/* 16bits */

#define W3_INTERNALCONFIG		0x0	/* 32bits */
#define W3_MAXPKTSIZE			0x4	/* 16bits */
#define W3_MACCONTROL			0x6	/* 16bits */
#define W3_MEDIAOPTIONS			0x8	/* 16bits */
#define W3_RXFREE			0xA	/* 16bits */
#define W3_TXFREE			0xC	/* 16bits */

#define W4_VCODIAGNOSTIC		0x2	/* 16bits */
#define W4_FIFODIAGNOSTIC		0x4	/* 16bits */
#define W4_NETWORKDIAGNOSTIC		0x6	/* 16bits */
#define W4_PHYSICALMGMT			0x8	/* 16bits */
#define W4_MEDIASTATUS			0xA	/* 16bits */
#define W4_BADSSD			0xC	/* 8bits */
#define W4_UPPERBYTESOK			0xD	/* 8bits */

#define W5_TXSTARTTHRESH		0x0	/* 16bits */
#define W5_RXEARLYTHRESH		0x6	/* 16bits */
#define W5_RXFILTER			0x8	/* 8bits */
#define W5_TXRECLAIMTHRESH		0x9	/* 8bits */
#define W5_INTERRUPTENABLE		0xA	/* 16bits */
#define W5_INDICATIONENABLE		0xC	/* 16bits */

#define W6_CARRIERLOST			0x0	/* 8bits */
#define W6_SQEERRORS			0x1	/* 8bits */
#define W6_MULTIPLECOLLISIONS		0x2	/* 8bits */
#define W6_SINGLECOLLISIONS		0x3	/* 8bits */
#define W6_LATECOLLISIONS		0x4	/* 8bits */
#define W6_RXOVERRUNS			0x5	/* 8bits */
#define W6_FRAMESXMITTEDOK		0x6	/* 8bits */
#define W6_FRAMESRCVDOK			0x7	/* 8bits */
#define W6_FRAMESDEFERRED		0x8	/* 8bits */
#define W6_UPPERFRAMESOK		0x9	/* 8bits */
#define W6_BYTESRCVDOK			0xA	/* 16bits */
#define W6_BYTESXMITTEDOK		0xC	/* 16bits */

#define W7_VLANMASK			0x0	/* 16bits */
#define W7_VLANETHERTYPE		0x4	/* 16bits */
#define W7_POWERMGMTEVENT		0xC	/* 16bits */

/*  Function Prototypes */

static void sef_local_startup(void);

#endif
