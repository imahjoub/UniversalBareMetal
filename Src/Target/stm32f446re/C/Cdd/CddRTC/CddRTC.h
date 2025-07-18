#ifndef CDD_RTC_2025_07_14_H
  #define CDD_RTC_2025_07_14_H

  #include "Mcal/Reg.h"

  void CddRTC_Init(void);
  void CddRTC_ReadDate(uint8_t* Year, uint8_t* Month, uint8_t* Date, uint8_t* WeekDay);
  void CddRTC_ReadTime(uint8_t* Hours, uint8_t* Minutes, uint8_t* Seconds, uint8_t* Am_Pm);



#endif /* CDD_RTC_2025_07_14_H */
