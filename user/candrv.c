// #include "candrv.h"
// #include "fdcan.h"

// FDCAN_HandleTypeDef hfdcan1;
// FDCAN_HandleTypeDef hfdcan2;
// void canfd_baud_rate_set_init(uint8_t canctrl_id,uint32_t clk,float point1,float point2){
// if(canctrl_id == 0){

// }else{

// }
// }
// void canfd_rx_buffer_set_init(uint8_t canctrl_id,uint32_t clk,float point1,float point2){
//     if(canctrl_id == 0){

//     }else{
        
//     }
// }
// /* FDCAN1 init function */
// void MX_FDCAN1_Init(void)
// {

//   hfdcan1.Instance = FDCAN1;
//   hfdcan1.Init.FrameFormat = FDCAN_FRAME_CLASSIC;
//   hfdcan1.Init.Mode = FDCAN_MODE_NORMAL;
//   hfdcan1.Init.AutoRetransmission = DISABLE;
//   hfdcan1.Init.TransmitPause = DISABLE;
//   hfdcan1.Init.ProtocolException = DISABLE;
//   hfdcan1.Init.NominalPrescaler = 6;
//   hfdcan1.Init.NominalSyncJumpWidth = 1;
//   hfdcan1.Init.NominalTimeSeg1 = 14;
//   hfdcan1.Init.NominalTimeSeg2 = 5;
//   hfdcan1.Init.DataPrescaler = 1;
//   hfdcan1.Init.DataSyncJumpWidth = 1;
//   hfdcan1.Init.DataTimeSeg1 = 1;
//   hfdcan1.Init.DataTimeSeg2 = 1;
//   hfdcan1.Init.MessageRAMOffset = 0;
//   hfdcan1.Init.StdFiltersNbr = 0;
//   hfdcan1.Init.ExtFiltersNbr = 0;
//   hfdcan1.Init.RxFifo0ElmtsNbr = 0;
//   hfdcan1.Init.RxFifo0ElmtSize = FDCAN_DATA_BYTES_8;
//   hfdcan1.Init.RxFifo1ElmtsNbr = 0;
//   hfdcan1.Init.RxFifo1ElmtSize = FDCAN_DATA_BYTES_8;
//   hfdcan1.Init.RxBuffersNbr = 0;
//   hfdcan1.Init.RxBufferSize = FDCAN_DATA_BYTES_8;
//   hfdcan1.Init.TxEventsNbr = 0;
//   hfdcan1.Init.TxBuffersNbr = 0;
//   hfdcan1.Init.TxFifoQueueElmtsNbr = 0;
//   hfdcan1.Init.TxFifoQueueMode = FDCAN_TX_FIFO_OPERATION;
//   hfdcan1.Init.TxElmtSize = FDCAN_DATA_BYTES_8;
//   if (HAL_FDCAN_Init(&hfdcan1) != HAL_OK)
//   {
//     Error_Handler();
//   }

// }
// /* FDCAN2 init function */
// void MX_FDCAN2_Init(void)
// {
//   hfdcan2.Instance = FDCAN2;
//   hfdcan2.Init.FrameFormat = FDCAN_FRAME_CLASSIC;
//   hfdcan2.Init.Mode = FDCAN_MODE_NORMAL;
//   hfdcan2.Init.AutoRetransmission = DISABLE;
//   hfdcan2.Init.TransmitPause = DISABLE;
//   hfdcan2.Init.ProtocolException = DISABLE;
//   hfdcan2.Init.NominalPrescaler = 6;
//   hfdcan2.Init.NominalSyncJumpWidth = 1;
//   hfdcan2.Init.NominalTimeSeg1 = 15;
//   hfdcan2.Init.NominalTimeSeg2 = 4;
//   hfdcan2.Init.DataPrescaler = 1;
//   hfdcan2.Init.DataSyncJumpWidth = 8;
//   hfdcan2.Init.DataTimeSeg1 = 1;
//   hfdcan2.Init.DataTimeSeg2 = 1;
//   hfdcan2.Init.MessageRAMOffset = 0;
//   hfdcan2.Init.StdFiltersNbr = 0;
//   hfdcan2.Init.ExtFiltersNbr = 0;
//   hfdcan2.Init.RxFifo0ElmtsNbr = 0;
//   hfdcan2.Init.RxFifo0ElmtSize = FDCAN_DATA_BYTES_8;
//   hfdcan2.Init.RxFifo1ElmtsNbr = 0;
//   hfdcan2.Init.RxFifo1ElmtSize = FDCAN_DATA_BYTES_8;
//   hfdcan2.Init.RxBuffersNbr = 0;
//   hfdcan2.Init.RxBufferSize = FDCAN_DATA_BYTES_8;
//   hfdcan2.Init.TxEventsNbr = 0;
//   hfdcan2.Init.TxBuffersNbr = 0;
//   hfdcan2.Init.TxFifoQueueElmtsNbr = 1;
//   hfdcan2.Init.TxFifoQueueMode = FDCAN_TX_FIFO_OPERATION;
//   hfdcan2.Init.TxElmtSize = FDCAN_DATA_BYTES_8;
//   if (HAL_FDCAN_Init(&hfdcan2) != HAL_OK)
//   {
//     Error_Handler();
//   }
// }

// static uint32_t HAL_RCC_FDCAN_CLK_ENABLED=0;

// void HAL_FDCAN_MspInit(FDCAN_HandleTypeDef* fdcanHandle)
// {

//   GPIO_InitTypeDef GPIO_InitStruct = {0};
//   RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};
//   if(fdcanHandle->Instance==FDCAN1)
//   {
//     PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_FDCAN;
//     PeriphClkInitStruct.FdcanClockSelection = RCC_FDCANCLKSOURCE_PLL;
//     if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
//     {
//       Error_Handler();
//     }

//     HAL_RCC_FDCAN_CLK_ENABLED++;
//     if(HAL_RCC_FDCAN_CLK_ENABLED==1){
//       __HAL_RCC_FDCAN_CLK_ENABLE();
//     }

//     __HAL_RCC_GPIOB_CLK_ENABLE();
//     /**FDCAN1 GPIO Configuration
//     PB9     ------> FDCAN1_TX
//     PB8     ------> FDCAN1_RX
//     */
//     GPIO_InitStruct.Pin = GPIO_PIN_9|GPIO_PIN_8;
//     GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
//     GPIO_InitStruct.Pull = GPIO_NOPULL;
//     GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
//     GPIO_InitStruct.Alternate = GPIO_AF9_FDCAN1;
//     HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

//     HAL_NVIC_SetPriority(FDCAN1_IT0_IRQn, 0, 0);
//     HAL_NVIC_EnableIRQ(FDCAN1_IT0_IRQn);
//     HAL_NVIC_SetPriority(FDCAN1_IT1_IRQn, 0, 0);
//     HAL_NVIC_EnableIRQ(FDCAN1_IT1_IRQn);
//   }
//   else if(fdcanHandle->Instance==FDCAN2)
//   {
//     PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_FDCAN;
//     PeriphClkInitStruct.FdcanClockSelection = RCC_FDCANCLKSOURCE_PLL;
//     if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
//     {
//       Error_Handler();
//     }

//     /* FDCAN2 clock enable */
//     HAL_RCC_FDCAN_CLK_ENABLED++;
//     if(HAL_RCC_FDCAN_CLK_ENABLED==1){
//       __HAL_RCC_FDCAN_CLK_ENABLE();
//     }

//     __HAL_RCC_GPIOB_CLK_ENABLE();
//     /**FDCAN2 GPIO Configuration
//     PB5     ------> FDCAN2_RX
//     PB13     ------> FDCAN2_TX
//     */
//     GPIO_InitStruct.Pin = GPIO_PIN_5|GPIO_PIN_13;
//     GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
//     GPIO_InitStruct.Pull = GPIO_NOPULL;
//     GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
//     GPIO_InitStruct.Alternate = GPIO_AF9_FDCAN2;
//     HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
//   }
// }

// void HAL_FDCAN_MspDeInit(FDCAN_HandleTypeDef* fdcanHandle)
// {

//   if(fdcanHandle->Instance==FDCAN1)
//   {
//     HAL_RCC_FDCAN_CLK_ENABLED--;
//     if(HAL_RCC_FDCAN_CLK_ENABLED==0){
//       __HAL_RCC_FDCAN_CLK_DISABLE();
//     }
//     HAL_GPIO_DeInit(GPIOB, GPIO_PIN_9|GPIO_PIN_8);

//     /* FDCAN1 interrupt Deinit */
//     HAL_NVIC_DisableIRQ(FDCAN1_IT0_IRQn);
//     HAL_NVIC_DisableIRQ(FDCAN1_IT1_IRQn);
//   }
//   else if(fdcanHandle->Instance==FDCAN2)
//   {
//     HAL_RCC_FDCAN_CLK_ENABLED--;
//     if(HAL_RCC_FDCAN_CLK_ENABLED==0){
//       __HAL_RCC_FDCAN_CLK_DISABLE();
//     }
//     HAL_GPIO_DeInit(GPIOB, GPIO_PIN_5|GPIO_PIN_13);
//   }
// }





































