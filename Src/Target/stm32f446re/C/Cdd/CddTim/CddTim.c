#include "CddTim.h"

#define NumberOfDataItemsToTransfer 500UL

uint16_t TIM2_CH1_LookUp_Table[NumberOfDataItemsToTransfer] =
{
    0U,   1U,   2U,   3U,   4U,   5U,   6U,   7U,   8U,   9U,
   10U,  11U,  12U,  13U,  14U,  15U,  16U,  17U,  18U,  19U,
   20U,  21U,  22U,  23U,  24U,  25U,  26U,  27U,  28U,  29U,
   30U,  31U,  32U,  33U,  34U,  35U,  36U,  37U,  38U,  39U,
   40U,  41U,  42U,  43U,  44U,  45U,  46U,  47U,  48U,  49U,
   50U,  51U,  52U,  53U,  54U,  55U,  56U,  57U,  58U,  59U,
   60U,  61U,  62U,  63U,  64U,  65U,  66U,  67U,  68U,  69U,
   70U,  71U,  72U,  73U,  74U,  75U,  76U,  77U,  78U,  79U,
   80U,  81U,  82U,  83U,  84U,  85U,  86U,  87U,  88U,  89U,
   90U,  91U,  92U,  93U,  94U,  95U,  96U,  97U,  98U,  99U,
  100U, 101U, 102U, 103U, 104U, 105U, 106U, 107U, 108U, 109U,
  110U, 111U, 112U, 113U, 114U, 115U, 116U, 117U, 118U, 119U,
  120U, 121U, 122U, 123U, 124U, 125U, 126U, 127U, 128U, 129U,
  130U, 131U, 132U, 133U, 134U, 135U, 136U, 137U, 138U, 139U,
  140U, 141U, 142U, 143U, 144U, 145U, 146U, 147U, 148U, 149U,
  150U, 151U, 152U, 153U, 154U, 155U, 156U, 157U, 158U, 159U,
  160U, 161U, 162U, 163U, 164U, 165U, 166U, 167U, 168U, 169U,
  170U, 171U, 172U, 173U, 174U, 175U, 176U, 177U, 178U, 179U,
  180U, 181U, 182U, 183U, 184U, 185U, 186U, 187U, 188U, 189U,
  190U, 191U, 192U, 193U, 194U, 195U, 196U, 197U, 198U, 199U,
  200U, 201U, 202U, 203U, 204U, 205U, 206U, 207U, 208U, 209U,
  210U, 211U, 212U, 213U, 214U, 215U, 216U, 217U, 218U, 219U,
  220U, 221U, 222U, 223U, 224U, 225U, 226U, 227U, 228U, 229U,
  230U, 231U, 232U, 233U, 234U, 235U, 236U, 237U, 238U, 239U,
  240U, 241U, 242U, 243U, 244U, 245U, 246U, 247U, 248U, 249U,
  250U, 251U, 252U, 253U, 254U, 255U, 256U, 257U, 258U, 259U,
  260U, 261U, 262U, 263U, 264U, 265U, 266U, 267U, 268U, 269U,
  270U, 271U, 272U, 273U, 274U, 275U, 276U, 277U, 278U, 279U,
  280U, 281U, 282U, 283U, 284U, 285U, 286U, 287U, 288U, 289U,
  290U, 291U, 292U, 293U, 294U, 295U, 296U, 297U, 298U, 299U,
  300U, 301U, 302U, 303U, 304U, 305U, 306U, 307U, 308U, 309U,
  310U, 311U, 312U, 313U, 314U, 315U, 316U, 317U, 318U, 319U,
  320U, 321U, 322U, 323U, 324U, 325U, 326U, 327U, 328U, 329U,
  330U, 331U, 332U, 333U, 334U, 335U, 336U, 337U, 338U, 339U,
  340U, 341U, 342U, 343U, 344U, 345U, 346U, 347U, 348U, 349U,
  350U, 351U, 352U, 353U, 354U, 355U, 356U, 357U, 358U, 359U,
  360U, 361U, 362U, 363U, 364U, 365U, 366U, 367U, 368U, 369U,
  370U, 371U, 372U, 373U, 374U, 375U, 376U, 377U, 378U, 379U,
  380U, 381U, 382U, 383U, 384U, 385U, 386U, 387U, 388U, 389U,
  390U, 391U, 392U, 393U, 394U, 395U, 396U, 397U, 398U, 399U,
  400U, 401U, 402U, 403U, 404U, 405U, 406U, 407U, 408U, 409U,
  410U, 411U, 412U, 413U, 414U, 415U, 416U, 417U, 418U, 419U,
  420U, 421U, 422U, 423U, 424U, 425U, 426U, 427U, 428U, 429U,
  430U, 431U, 432U, 433U, 434U, 435U, 436U, 437U, 438U, 439U,
  440U, 441U, 442U, 443U, 444U, 445U, 446U, 447U, 448U, 449U,
  450U, 451U, 452U, 453U, 454U, 455U, 456U, 457U, 458U, 459U,
  460U, 461U, 462U, 463U, 464U, 465U, 466U, 467U, 468U, 469U,
  470U, 471U, 472U, 473U, 474U, 475U, 476U, 477U, 478U, 479U,
  480U, 481U, 482U, 483U, 484U, 485U, 486U, 487U, 488U, 489U,
  490U, 491U, 492U, 493U, 494U, 495U, 496U, 497U, 498U, 499U
};

uint16_t TIM2_CH2_LookUp_Table[NumberOfDataItemsToTransfer] =
{
  499U, 498U, 497U, 496U, 495U, 494U, 493U, 492U, 491U, 490U,
  489U, 488U, 487U, 486U, 485U, 484U, 483U, 482U, 481U, 480U,
  479U, 478U, 477U, 476U, 475U, 474U, 473U, 472U, 471U, 470U,
  469U, 468U, 467U, 466U, 465U, 464U, 463U, 462U, 461U, 460U,
  459U, 458U, 457U, 456U, 455U, 454U, 453U, 452U, 451U, 450U,
  449U, 448U, 447U, 446U, 445U, 444U, 443U, 442U, 441U, 440U,
  439U, 438U, 437U, 436U, 435U, 434U, 433U, 432U, 431U, 430U,
  429U, 428U, 427U, 426U, 425U, 424U, 423U, 422U, 421U, 420U,
  419U, 418U, 417U, 416U, 415U, 414U, 413U, 412U, 411U, 410U,
  409U, 408U, 407U, 406U, 405U, 404U, 403U, 402U, 401U, 400U,
  399U, 398U, 397U, 396U, 395U, 394U, 393U, 392U, 391U, 390U,
  389U, 388U, 387U, 386U, 385U, 384U, 383U, 382U, 381U, 380U,
  379U, 378U, 377U, 376U, 375U, 374U, 373U, 372U, 371U, 370U,
  369U, 368U, 367U, 366U, 365U, 364U, 363U, 362U, 361U, 360U,
  359U, 358U, 357U, 356U, 355U, 354U, 353U, 352U, 351U, 350U,
  349U, 348U, 347U, 346U, 345U, 344U, 343U, 342U, 341U, 340U,
  339U, 338U, 337U, 336U, 335U, 334U, 333U, 332U, 331U, 330U,
  329U, 328U, 327U, 326U, 325U, 324U, 323U, 322U, 321U, 320U,
  319U, 318U, 317U, 316U, 315U, 314U, 313U, 312U, 311U, 310U,
  309U, 308U, 307U, 306U, 305U, 304U, 303U, 302U, 301U, 300U,
  299U, 298U, 297U, 296U, 295U, 294U, 293U, 292U, 291U, 290U,
  289U, 288U, 287U, 286U, 285U, 284U, 283U, 282U, 281U, 280U,
  279U, 278U, 277U, 276U, 275U, 274U, 273U, 272U, 271U, 270U,
  269U, 268U, 267U, 266U, 265U, 264U, 263U, 262U, 261U, 260U,
  259U, 258U, 257U, 256U, 255U, 254U, 253U, 252U, 251U, 250U,
  249U, 248U, 247U, 246U, 245U, 244U, 243U, 242U, 241U, 240U,
  239U, 238U, 237U, 236U, 235U, 234U, 233U, 232U, 231U, 230U,
  229U, 228U, 227U, 226U, 225U, 224U, 223U, 222U, 221U, 220U,
  219U, 218U, 217U, 216U, 215U, 214U, 213U, 212U, 211U, 210U,
  209U, 208U, 207U, 206U, 205U, 204U, 203U, 202U, 201U, 200U,
  199U, 198U, 197U, 196U, 195U, 194U, 193U, 192U, 191U, 190U,
  189U, 188U, 187U, 186U, 185U, 184U, 183U, 182U, 181U, 180U,
  179U, 178U, 177U, 176U, 175U, 174U, 173U, 172U, 171U, 170U,
  169U, 168U, 167U, 166U, 165U, 164U, 163U, 162U, 161U, 160U,
  159U, 158U, 157U, 156U, 155U, 154U, 153U, 152U, 151U, 150U,
  149U, 148U, 147U, 146U, 145U, 144U, 143U, 142U, 141U, 140U,
  139U, 138U, 137U, 136U, 135U, 134U, 133U, 132U, 131U, 130U,
  129U, 128U, 127U, 126U, 125U, 124U, 123U, 122U, 121U, 120U,
  119U, 118U, 117U, 116U, 115U, 114U, 113U, 112U, 111U, 110U,
  109U, 108U, 107U, 106U, 105U, 104U, 103U, 102U, 101U, 100U,
   99U,  98U,  97U,  96U,  95U,  94U,  93U,  92U,  91U,  90U,
   89U,  88U,  87U,  86U,  85U,  84U,  83U,  82U,  81U,  80U,
   79U,  78U,  77U,  76U,  75U,  74U,  73U,  72U,  71U,  70U,
   69U,  68U,  67U,  66U,  65U,  64U,  63U,  62U,  61U,  60U,
   59U,  58U,  57U,  56U,  55U,  54U,  53U,  52U,  51U,  50U,
   49U,  48U,  47U,  46U,  45U,  44U,  43U,  42U,  41U,  40U,
   39U,  38U,  37U,  36U,  35U,  34U,  33U,  32U,  31U,  30U,
   29U,  28U,  27U,  26U,  25U,  24U,  23U,  22U,  21U,  20U,
   19U,  18U,  17U,  16U,  15U,  14U,  13U,  12U,  11U,  10U,
    9U,   8U,   7U,   6U,   5U,   4U,   3U,   2U,   1U,   0U
};

static void CddTim_ConfigureDMA1Stream5(void);
static void CddTim_ConfigureDMA1Stream6(void);


void CddTim_Init(void)
{
  /* Enable Clock access to TIM2                    */
  RCC_APB1ENR |= (uint32_t)(1UL << 0U);

  /* Set timer Prescaler                            */
  /* Prescale to 100kHz (45MHz / 4500)              */
  //TIM2_PSC = 45000UL - 1UL; /* for 4Hz */
  //TIM2_PSC = 180UL - 1UL; //for normal pwm with ramp up
  TIM2_PSC = 2000UL - 1UL; // DMA

  /* Set Auto-reload value                          */
  TIM2_ARR = 500UL - 1UL;

  /* Reset the timer count                          */
  TIM2_CNT = (uint32_t)0UL;

  /* Set PA1 (ch1) and PA0 (ch2) to 100: PWM mode 1 */
  TIM2_CCMR1 &= (uint32_t)(~(1UL << 4U));
  TIM2_CCMR1 |= (uint32_t)(1UL << 5U);
  TIM2_CCMR1 |= (uint32_t)(1UL << 6U);

  TIM2_CCMR1 &= (uint32_t)(~(1UL << 12U));
  TIM2_CCMR1 |= (uint32_t)(1UL << 13U);
  TIM2_CCMR1 |= (uint32_t)(1UL << 14U);

  /* Enable Capture/Compare 1/2 DMA request         */
  TIM2_DIER |= (uint32_t)((1UL << 9U) | (1UL << 10U));

  /* Update DMA request enable                      */
  TIM2_DIER |= (uint32_t)(1UL << 8U);

  /* Trigger DMA request enable */
  TIM2_DIER |= (uint32_t)(1UL << 14U);

  /* Enable preload register on CH1 and CH2         */
  TIM2_CCMR1 |= (uint32_t)((1UL << 3U) | (1UL << 11U));

  /* Enable (ch2) and (ch1)                         */
  TIM2_CCER |= (uint32_t)(1UL << 0U);
  TIM2_CCER |= (uint32_t)(1UL << 4U);

  #ifdef PWM_WITH_DMA
  /* Configure DMA parameters                       */
  /* Stream5 for Tim2Ch1 and Stream6 for Tim2Ch2    */
  CddTim_ConfigureDMA1Stream5();
  CddTim_ConfigureDMA1Stream6();
  #endif /* PWM_WITH_DMA */

  /* Enable timer                                   */
   TIM2_CR1 |= (uint32_t)(1UL << 0U);

  /* Force update generation                        */
  TIM2_EGR |= (uint32_t)1UL;
}


static void CddTim_ConfigureDMA1Stream5(void)
{
  /* DMA1 clock enable */
  RCC_AHB1ENR |= (uint32_t)(1UL << 21U);

  /* Disable DMA1 stream5 and also reset the the register value */
  DMA1_STREAM5_CR = (uint32_t)0UL;
  while(DMA1_STREAM5_CR & (1U << 0U)) {/* Do nothing */}

  /* Select Ch3 in DMA1_STREAM5 */
  DMA1_STREAM5_CR |= (uint32_t)(1UL << 25U);
  DMA1_STREAM5_CR |= (uint32_t)(1UL << 26U);
  DMA1_STREAM5_CR &= (uint32_t)(~(1UL << 27U));

  /* Memory increment mode */
  DMA1_STREAM5_CR |= (uint32_t)(1UL << 10U);

  /* Peripheral data size : Word (32-bit) */
  DMA1_STREAM5_CR |= (uint32_t)(1UL << 12U);

  /* Memory data size : Word (32-bit) */
  DMA1_STREAM5_CR |= (uint32_t)(1UL << 14U);

  /* Circular mode */
  DMA1_STREAM5_CR |= (uint32_t)(1UL << 8U);

  /* Transfer complete interrupt enable */
  DMA1_STREAM5_CR |= (uint32_t)(1UL << 4U);

  /* Data transfer direction (Mem to Peripheral) */
  DMA1_STREAM5_CR |= (uint32_t)(1UL << 6U);

  /* Number of data items to transfer */
   DMA1_STREAM5_NDTR = (uint32_t)200UL;

   /* Peripheral address */
   DMA1_STREAM5_PAR = (uint32_t)(&TIM2_CCR1);

   /* Memory address */
   DMA1_STREAM5_M0AR = (uint32_t)(&TIM2_CH1_LookUp_Table);

   /* Enable DMA1 Stream5 */
   DMA1_STREAM5_CR |= (uint32_t)( 1UL << 0U);
}


static void CddTim_ConfigureDMA1Stream6(void)
{
  /*-----------------------------------------------*/
  /*           Configure DMA parameters            */
  /*-----------------------------------------------*/
  /* DMA1 clock enable                             */
  RCC_AHB1ENR |= (uint32_t)(1UL << 21U);

  /* Disable DMA1 stream6                          */
  DMA1_STREAM6_CR = (uint32_t)0UL;
  while(DMA1_STREAM6_CR & (1U << 0U)) {/* Do nothing */}

  /* Select Ch3 in DMA1_STREAM6                    */
  DMA1_STREAM6_CR |= (uint32_t)(1UL << 25U);
  DMA1_STREAM6_CR |= (uint32_t)(1UL << 26U);
  DMA1_STREAM6_CR &= (uint32_t)(~(1UL << 27U));

  /* Memory increment mode */
  DMA1_STREAM6_CR |= (uint32_t)(1UL << 10U);

  /* Peripheral data size : Word (32-bit) */
  DMA1_STREAM6_CR |= (uint32_t)(1UL << 12U);

  /* Memory data size : Word (32-bit) */
  DMA1_STREAM6_CR |= (uint32_t)(1UL << 14U);

  /* Circular mode */
  DMA1_STREAM6_CR |= (uint32_t)(1UL << 8U);

  /* Transfer complete interrupt enable */
  DMA1_STREAM6_CR |= (uint32_t)(1UL << 4U);

  /* Data transfer direction (Mem to Peripheral) */
  DMA1_STREAM6_CR |= (uint32_t)(1UL << 6U);

  /* Number of data items to transfer */
   DMA1_STREAM6_NDTR = (uint32_t)200UL;

   /* Peripheral address */
   DMA1_STREAM6_PAR = (uint32_t)(&TIM2_CCR2);

   /* Memory address */
   DMA1_STREAM6_M0AR = (uint32_t)(&TIM2_CH2_LookUp_Table);

   /* Enable DMA1 Stream6 */
   DMA1_STREAM6_CR |= (uint32_t)( 1UL << 0U);
}



void CddTim_SetPwmDutyCycle(uint8_t PwmChannel, uint32_t DutyCycle)
{
  /* Set Duty cycle */
  switch(PwmChannel)
  {
  case 1:
    TIM2_CCR1 = DutyCycle;
    break;
  case 2:
    TIM2_CCR2 = DutyCycle;
    break;
  default:
    break;
  }
}

