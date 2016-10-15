/*
 * HAL_Gpio.h
 *
 * Created: 17/01/2016 14:49:01
 * Author: benoit tANI
 */ 


#ifndef HAL_GPIO_H_
#define HAL_GPIO_H_

/* ============== TYPEDEF ============= */

/* ============== DEFINE ============== */

/* Define here the facade to your hardware : */
/* Your hardware mapping must be done here!  */
/* This insure that no conflict is created	 */

/*!< List of alias for port #A */


/*!< List of alias for port #B */
#define PORT_RS485		&PORTB		/* Don't forget our function use pointer */
#define PORT_LED		&PORTB

/*!< List of PIN alias on port #B */
#define PIN_485_RE		PIN_0
#define PIN_485_DE		PIN_1
#define PIN_485_RX		PIN_2
#define PIN_485_TX		PIN_3
#define PIN_LED_GREEN	PIN_4
#define PIN_LED_RED		PIN_5
#define NONE_B6			PIN_6
#define NONE_B7			PIN_7

/* =============== ENUM =============== */

typedef enum
{
	PIN_0 = (1<<0)
	, PIN_1 = (1<<1)
	, PIN_2 = (1<<2)
	, PIN_3 = (1<<3)
	, PIN_4 = (1<<4)
	, PIN_5 = (1<<5)
	, PIN_6 = (1<<6)
	, PIN_7 = (1<<7)
}eHAL_GpioPin;

typedef enum
{
	BOTHEDGES		= 0				/*!< Sense Both Edges */
	, RISING		= 1				/*!< Sense Rising Edge */
	, FALLING		= 2				/*!< Sense Falling Edge */
	, LEVEL			= 3				/*!< Sense Low Level */
	, INPUT_DISABLE = 7				/*!< Input Buffer Disabled */
}eHAL_GpioSense;

typedef enum
{
	TOTEM			= 0x00			//!< Totem-pole (N/A) */
	, BUSKEEPER		= (0x01<<3)		/*!< Totem-pole Bus-keeper */
	, PULLDOWN		= (0x02<<3)		/*!< Totem-pole Pull-down (on input) */
	, PULLUP		= (0x03<<3)		/*!< Totem-pole Pull-up (on input) */
	, WIREDOR		= (0x04<<3)		/*!< Wired-OR (N/A) */
	, WIREDAND		= (0x05<<3)		/*!< Wired-AND (N/A) */
	, WIREDORPULL	= (0x06<<3)		/*!< Wired-OR Pull-down */
	, WIREDANDPULL	= (0x07<<3)		/*!< Wired-AND Pull-up */
	}eHAL_GpioMode;
	
/* ============ PROTOTYPES ============ */

void HalGpioPinsConfigMode( PORT_t* port, uint8_t pin_mask, eHAL_GpioMode mode);
inline void Hal_GpioPinsSet( PORT_t* port, uint8_t pin_mask);
inline void Hal_GpioPinsClear( PORT_t* port, uint8_t pin_mask);
inline void Hal_GpioSetOutputs( PORT_t* port, uint8_t pin_mask);
inline void Hal_GpioSetInputs( PORT_t* port, uint8_t pin_mask);

/* ============ VARIABLES ============= */


/* ========= INLINE FUNCTIONS ========= */

/*! \brief Set an output Pin to high-level.
 *
 *  Warning: this is a inline FUNCTION.
 *  Compiler might not inline it !!!
 */
inline void Hal_GpioPinsSet( PORT_t* port, uint8_t pin_mask)
{
	port->OUTSET = pin_mask;		/*!<  OUTSET used instead of a Read/Modify/Write */
}

/*! \brief Set the selected Output pin to low-level.
 *
 *  Warning: this is a inline FUNCTION.
 *  Compiler might not inline it !!!
 */
inline void Hal_GpioPinsClear( PORT_t* port, uint8_t pin_mask)
{
	port->OUTCLR = pin_mask;		/*!<  OUTCLR used instead of a Read/Modify/Write */
}

/*! \brief Set the selected Gpio as an output.
 *
 *  Warning: this is a inline FUNCTION.
 *  Compiler might not inline it !!!
 */
inline void Hal_GpioSetOutputs( PORT_t* port, uint8_t pin_mask)
{
	port->DIRSET = pin_mask;		/*!<  DIRSET used instead of a Read/Modify/Write */
}

/*! \brief Set the selected Gpio as an intput.
 *
 *  Warning: this is a inline FUNCTION.
 *  Compiler might not inline it !!!
 */
inline void Hal_GpioSetInputs( PORT_t* port, uint8_t pin_mask)
{
	port->DIRCLR = pin_mask;		/*!<  DIRCLR used instead of a Read/Modify/Write */
}

#endif /* HAL_GPIO_H_ */