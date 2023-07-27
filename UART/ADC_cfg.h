

#ifndef ADC_CFG_H_
#define ADC_CFG_H_


/**
 * @brief 
 * @details configure the refrence voltage , options are :  1- AREF_REF
 *                                                          2- AVCC_REF
 *                                                          3- INTERNAL_2560mV_REF
 */


#define ADC_u8REF_VOLT            AVCC_REF




/**
 * @details configure the required ADC resolution  , options are :  1- EIGHT_BITS
 *                                                                  2- TEN_BITS                                                        
 */

#define ADC_u8RESOLUTION           EIGHT_BITS




/**
 * @details configure the required ADC resolution  , options are :  1- ENABLE
 *                                                                  2- DISABLE                                                        
 */

#define ADC_u8AUTO_TRIGGER          DISABLE



/**
 * @details configure the interrupt enable configration  , options are :  1- ENABLE
 *                                                                        2- DISABLE                                                        
 */

#define ADC_u8INT_ENABLE  DISABLE


/**
 * @details configure the prescaler configration  , options are :         1- DIVISION_BY_2
 *                                                                        2- DIVISION_BY_4
 *                                                                        3- DIVISION_BY_8
 *                                                                        4- DIVISION_BY_16
 *                                                                        5- DIVISION_BY_32
 *                                                                        6- DIVISION_BY_64
 *                                                                        7- DIVISION_BY_128                                                        
 */


#define ADC_u8PRESCALER_VAL           DIVISION_BY_128






#endif
