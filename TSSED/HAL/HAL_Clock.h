/*
 * HAL_Clock.h
 *
 * Created: 12/01/2016 20:16:10
 *  Author: benoit TANI
 */ 


#ifndef HAL_CLOCK_H_
#define HAL_CLOCK_H_


/*================ TYPEDEFs, DEFINEs =====================*/

// CCP signature
#define CCP_SignatureIO					CCP_IOREG_gc	/* SPM Instruction Protection */
#define CCP_SignatureSPM				CCP_SPM_gc		/* IO Register Protection */
#define CLOCK_LOCK_bm					0x01


/* Ocillator define !!<*/
#define INTERNAL_32MHZ_OSC_ENABLE		0x02		/* Internal Oscillator 32 MHz  */
#define INTERNAL_2MHZ_OSC_ENABLE		0x01		/* Internal Oscillator 2 MHz source PLL */

#define PLL_ENABLE						0x10
#define PLL_SOURCE_IS_INT_32MHZ			0x80		/* Internal Oscillator source PLL */
#define PLL_SOURCE_IS_INT_32MHZ_bm		0xC0		/* Internal Oscillator bit mask for PLL register */
#define PLL_PRESCALER					0x01		/* Change the value of the prescaler from here !<*/
#define PLL_PRESCALER_bm				0x1F		/* 0 to 31 */

/* Note: No prescaler for now */
/* It's fucking to late !<*/

#define PLL_PRESCALER	0x01

// System Clock Port Numbers
typedef enum  {
	SYSCLK_PORT_GEN=0,   //!< Devices not associated with a specific port.
	SYSCLK_PORT_A,     //!< Devices on PORTA
	SYSCLK_PORT_B,     //!< Devices on PORTB
	SYSCLK_PORT_C,     //!< Devices on PORTC
	SYSCLK_PORT_D,     //!< Devices on PORTD
	SYSCLK_PORT_E,     //!< Devices on PORTE
	SYSCLK_PORT_F,     //!< Devices on PORTF
}eHAL_ClockPortId;


/*================ Prototypes =====================*/

void HAL_ClockInit( void);
void Hal_ClockEnableModule( eHAL_ClockPortId port, uint8_t id);
void Hal_ClockDisableModule( eHAL_ClockPortId port, uint8_t id);
void HAL_CpuLockDisableClockCtrl(void);

#endif /* HAL_CLOCK_H_ */