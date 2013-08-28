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

/*  Command Register (commands)
 *
 *  See pages 134-146 of document for more information
 */

/*  RESET COMMANDS
 */

#define COM_GLOBALRESET			0x0	/* 16bits */
#define		COM_GR_TPAUIRESET	1	/* 1bit */
#define		COM_GR_ENDECRESET	2	/* 1bit */
#define		COM_GR_NETWORKRESET	4	/* 1bit */
#define		COM_GR_FIFORESET	8	/* 1bit */
#define		COM_GR_AISMRESET	16	/* 1bit */
#define		COM_GR_HOSTRESET	32	/* 1bit */
#define		COM_GR_SMBRESET		64	/* 1bit */
#define		COM_GR_VCORESET		128	/* 1bit */
#define		COM_GR_UPDOWNRESET	256	/* 1bit */

#define COM_RXRESET			0x2800	/* 16bits */
#define		COM_RR_TPAUIRXRESET	1	/* 1bit */
#define		COM_RR_ENDECRXRESET	2	/* 1bit */
#define		COM_RR_NETWORKRXRESET	4	/* 1bit */
#define		COM_RR_FIFORXRESET	8	/* 1bit */
#define		COM_RR_UPRXRESET	128	/* 1bit */

#define COM_TXRESET			0x5800	/* 16bits */
#define		COM_TR_TPAUITXRESET	1	/* 1bit */
#define		COM_TR_ENDECTXRESET	2	/* 1bit */
#define		COM_TR_NETWORKTXRESET	4	/* 1bit */
#define		COM_TR_FIFITXRESET	8	/* 1bit */
#define		COM_TR_DNTXRESET	128	/* 1bit */

/*  TRANSMIT COMMANDS
 */

#define COM_DNSTALL			0x3002	/* 16bits */

#define COM_DNUNSTALL			0x3003	/* 16bits */

#define COM_SETTXRECLAIMTHRESH		0xC000	/* 16bits */

#define COM_SETTXSTARTTHRESH		0x9800	/* 16bits */
#define 	COM_STST_MASK		0xFFFC	/* 16bits */

#define COM_TXAGAIN			0x9000	/* 16bits */

#define COM_TXDISABLE			0x5000	/* 16bits */

#define COM_TXDONE			0x3800	/* 16bits */

#define COM_TXENABLE			0x4800	/* 16bits */

#define COM_TXFIFOBISECT		0xD800	/* 16bits */

/*  RECEIVE COMMANDS
 */

#define COM_RXDISABLE			0x1800	/* 16bits */

#define COM_RXDISCARD			0x5000	/* 16bits */

#define COM_RXENABLE			0x2000	/* 16bits */

#define COM_SETHASHFILTERBIT		0xC800	/* 16bits */
#define 	COM_SHFB_MASK_ON	0x0400	/* 1bit */
#define		COM_SHFB_MASK_OFF	0x0000	/* 1bit */

#define COM_SETRXEARLYTHRESH		0x8800	/* 1bit */
#define		COM_SRET_MASK		0xFFFC	/* 16bits */

#define COM_SETRXFILTER			0x8000	/* 16bits */
#define		COM_SRF_INDIVIDUAL	1	/* 1bit */
#define		COM_SRF_MULTICAST	2	/* 1bit */
#define		COM_SRF_BROADCAST	4	/* 1bit */
#define		COM_SRF_PROMISCUOUS	8	/* 1bit */
#define		COM_SRF_3C905B_MHF	16	/* 1bit */

#define COM_UPSTALL			0x3000	/* 16bits */

#define COM_UPUNSTALL			0x3001	/* 16bits */

/*  INTERRUPT COMMANDS
 */

#define	COM_ACKNOWLEDGEINTERRUPT	0x6800	/* 16bits */
#define		COM_AI_INTERRUPTLATCHACK	0	/* 1bit */
#define		COM_AI_LINKEVENTACK		2	/* 1bit */
#define		COM_AI_RXEARLYACK		32	/* 1bit */
#define		COM_AI_INTREQUESTEDACK		64	/* 1bit */
#define		COM_AI_DNCOMPLETEACK		512	/* 1bit */
#define		COM_AI_UPCOMPLETEACK		1024	/* 1bit */

#define COM_REQUESTINTERRUPT		0x6000	/* 16bits */

#define COM_SETINDICATIONENABLE		0x7800	/* 16bits */

#define COM_SETINTERRUPTENABLE		0x7000	/* 16bits */

/*  OTHER COMMANDS
 */

#define COM_DISABLEDCCONVERTER		0xB800	/* 16bits */

#define COM_ENABLEDCCONVERTER		0x1000	/* 16bits */

#define COM_SELECTREGISTERWINDOW	0x0800	/* 16bits */
#define 	COM_SRW_0		0	/* 3bits */
#define 	COM_SRW_1		1	/* 3bits */
#define 	COM_SRW_2		2	/* 3bits */
#define 	COM_SRW_3		3	/* 3bits */
#define 	COM_SRW_4		4	/* 3bits */
#define 	COM_SRW_5		5	/* 3bits */
#define 	COM_SRW_6		6	/* 3bits */
#define 	COM_SRW_7		7	/* 3bits */

#define	COM_STATISTICSDISABLE		0xB000	/* 16bits */

#define COM_STATISTICSENABLE		0xA800	/* 16bits */

/*  Structures 
 */

/*  Upload packet descriptor
 *	See page 104 of the documentation
 */

typedef struct upd
{
	u32_t	upnextptr;
	u32_t	uppktstatus;
	u32_t	upfragaddr;
	u32_t	upfraglen;
}upd_t;

/*  Down packet descriptor
 *	See page 84 of the documentation
 */

typedef struct dpd
{
	u32_t	dnnextptr;
	u32_t	framestartheader;
	u32_t	dnfragaddr;
	u32_t	dnfraglen;
}dpd_t;

typedef struct fe100
{
	upd_t	fe_100_upd;
	dpd_t	fe_100_dpd;
	int	fe100_mode;
	int	fe100_flags;
	u16_t	fe100_vid;
	u16_t	fe100_did;
	u16_t	fe100_command;
	u16_t	fe100_pcistat;
	u8_t	fe100_revid;
	u32_t	fe100_classcode;
	u8_t	fe100_cachelinesize;
	u8_t	fe100_latencytimer;
	u8_t	fe100_headertype;
	u32_t	fe100_iobaseaddress;
	u32_t	fe100_membaseaddress;
	u16_t	fe100_subsystemvid;
	u16_t	fe100_subsystemid;
	u32_t	fe100_biosromcontrol;
	u8_t	fe100_capptr;
	u8_t	fe100_interruptline;
	u8_t	fe100_interruptpin;
	u8_t	fe100_mingnt;
	u8_t	fe100_maxlat;
	u8_t	fe100_capid;
	u8_t	fe100_nextptr;
	u16_t	fe100_powermgmtcap;
	u16_t	fe100_powermgmtctrl;
	u8_t	fe100_data;
}fe100_t;

/*  Function Prototypes
 */

static void sef_local_startup(void);
static int sef_cb_init_fresh(int type, sef_init_info_t *info);
static void sef_cb_signal_handler(int signo);

/*  Instance Variables 
 */

static int fe100_instance;

static fe100_t *fe100_state;

static u32_t system_hz;

#endif
