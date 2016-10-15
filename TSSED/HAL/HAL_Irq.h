#include "Type.h"
#include "src/ASF/common/utils/interrupt/interrupt_avr8.h"

//===== TYPEDEFs, DEFINEs ===============================================================
typedef uint8_t irqflags_t;
#define barrier()   asm volatile("" ::: "memory")
/* Already defined in ASF */
/*
#define cpu_irq_enable()  __asm__ __volatile__ ("sei" ::: "memory")
#define cpu_irq_disable() __asm__ __volatile__ ("cli" ::: "memory")
*/


// No IRQ level in the Atmega328
/*
typedef enum  {
	PMIC_LVL_LOW    = PMIC_LOLVLEN_bm,		// Low-level interrupts
	PMIC_LVL_MEDIUM = PMIC_MEDLVLEN_bm,		// Medium-level interrupts
	PMIC_LVL_HIGH   = PMIC_HILVLEN_bm,		// High-level interrupts
	PMIC_LVL_NMI    = PMIC_NMIEX_bp,		// Non Maskable Interrupt
}eHAL_IRQ_PMICLEVEL;
*/

static inline irqflags_t HalIrqSave(void)
{
	irqflags_t flags = SREG;
	cpu_irq_disable();
	return flags;
}

static inline void HalIrqRestore(irqflags_t flags)
{
	barrier();
	SREG = flags;
}

/***************************************************************************************/
/*! * \brief Initialize the PMIC
 *
 * Enables all interrupt levels, with vectors located in the application section
 * and fixed priority scheduling.
 *
 *	return None
 */
/***************************************************************************************/
/*
static inline void Hal_IrqInit(void)
{
	PMIC.CTRL = PMIC_LVL_LOW | PMIC_LVL_MEDIUM | PMIC_LVL_HIGH;
}
*/