#include "CddAdc.h"

#define PWR_CR_VBATEN       (1UL << 8U)    /* Enable VBAT reading         */
#define RCC_APB2ENR_ADC1EN  (1UL << 8U)    /* Enable ADC1 clock           */
#define VBAT_ADC_CHANNEL            18U    /* ADC channel number for Vbat */

void CddAdc_Init(void)
{
  /* Enable the clock for ADC1 */
  RCC_APB2ENR |= RCC_APB2ENR_ADC1EN;

  /* Configure ADC to read from the VBAT channel */
  ADC1_SQR3 = VBAT_ADC_CHANNEL;

  ADC1_CR2 &= (uint32_t)(~(1 << 1));   // Ensure ADC is in single conversion mode

  /* Configure ADC to read from the VBAT channel */
  //ADC1_SQR3 = VBAT_ADC_CHANNEL;

  /* Enable ADC */
  ADC1_CR2 |= (1UL << 0U);
}


uint32_t CddAdc_ReadVBAT(void)
{
  /* Start the conversion */
  ADC1_CR2 |= (1UL << 30U);

  /* Wait until conversion done */
  while (!(ADC1_SR & (1UL << 1U)));

  /* Return the ADC value */
  return ADC1_DR;
}

