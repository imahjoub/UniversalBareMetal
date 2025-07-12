#ifndef CDD_STAND_BY_MODE_MANAGER_2025_07_10_H
  #define CDD_STAND_BY_MODE_MANAGER_2025_07_10_H

  #include "stdint.h"
  #include "Mcal/Mcu.h"


  void     CddSSM_HandleReset(void);
  void     CddSSM_StandbyWakeupPinSetup(void);
  uint32_t CddSSM_GetWakeUpStatePin(void);

#endif /* CDD_STAND_BY_MODE_MANAGER_2025_07_10_H */




