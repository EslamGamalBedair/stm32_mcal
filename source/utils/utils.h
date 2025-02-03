/**********************************************************************/
/*                                                                    */
/*  FILE        :                      		      */
/*  DATE        : Tue, Oct 24, 2023                                   */
/*  Last Update : Tue, Oct 24, 2023                            		  */
/*  DESCRIPTION : ADC config  Header                     			  */
/*  CPU GROUP   : r5f10w                                              */
/*  Author      : Islam Gamal Bedair						          */
/*                          						                  */
/***********************************************************************/
#ifndef __UTILS_H_

#define __UTILS_H_

#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>
#include <errno.h>
#include "types.h"
#include "bit_math.h"


typedef enum
{
	TAG_DATA_NULL_DATA 				= 0  ,
	TAG_DATA_ARRAY 					= 1  ,	/* complex data type */
	TAG_DATA_STRUCTURE 				= 2  ,	/* complex data type */
	TAG_DATA_BOOLEAN 				= 3  ,
	TAG_DATA_BIT_STRING 			= 4  ,
	TAG_DATA_DOUBLE_LONG 			= 5  ,
	TAG_DATA_DOUBLE_LONG_UNSIGNED 	= 6  ,
	TAG_DATA_FLOATING_POINT 		= 7  ,
	TAG_DATA_OCTET_STRING 			= 9  ,
	TAG_DATA_VISIBLE_STRING 		= 10 ,
	TAG_DATA_UTF8_STRING			= 12 ,
	TAG_DATA_BCD 					= 13 ,
	TAG_DATA_INTEGER 				= 15 ,
	TAG_DATA_LONG 					= 16 ,
	TAG_DATA_UNSIGNED 				= 17 ,
	TAG_DATA_LONG_UNSIGNED 			= 18 ,
	TAG_DATA_COMPACT_ARRAY 			= 19 ,	/* complex data type */
	TAG_DATA_LONG64 				= 20 ,
	TAG_DATA_LONG64_UNSIGNED 		= 21 ,
	TAG_DATA_ENUM 					= 22 ,
	TAG_DATA_FLOAT32 				= 23 ,
	TAG_DATA_FLOAT64 				= 24 ,
	TAG_DATA_DATE_TIME 				= 25 ,
	TAG_DATA_DATE 					= 26 ,
	TAG_DATA_TIME 					= 27 ,
	TAG_DATA_DONT_CARE 				= 255,
} Data_Tag;
typedef Data_Tag attr_type_t;

int32_t getAbs(int32_t n);
uint8_t uint32tostr(uint8_t str[],uint8_t start_index, uint32_t num );
uint8_t numtostr(uint8_t str[],uint8_t start_index, uint8_t end_type, int num );
int32_t convert_string_to_int32(const uint8_t* str);
uint32_t convert_string_to_uint32(const uint8_t* str,uint8_t size);
/******************************************************************************/
/*                     PRIVATE FUNCTIONS DEFINITIONS                          */
/******************************************************************************/
/**
 * @brief convert uint64 or int64 to string ascii value
 *
 * @param value  uint8 of int 64 value
 * @param type   TAG_DATA_LONG64_UNSIGNED
 *               TAG_DATA_LONG64
 * @param result_array pointer to buffer to carry the converted date
 * @return uint8_t  array size of converted data.
 */
 uint8_t convert_u_int64_to_string(void *value, uint8_t type, uint8_t *result_array);

char* ltoa( long value, char *string, int radix );
char* ultoa( unsigned long value, char *string, int radix );
char* itoa( int value, char *string, int radix );
char* utoa( unsigned int value, char *string, int radix );
void convert_number_to_string (uint16_t const num, uint8_t * const buffer);

#endif
