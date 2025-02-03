
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
#include "../utils/utils.h"

#ifdef __cplusplus
extern "C" {
#endif

#define DELAY_MS(REQ_DELAY)  for(uint32_t DELAY_COUNTER = 0 ; DELAY_COUNTER<(REQ_DELAY*1000UL) ; DELAY_COUNTER++ )	\
								{NOP();}




// Function to calculate the absolute value of an integer
int32_t getAbs(int32_t n)
{
    // Create a mask based on the sign bit (31st bit for int)
    int const mask = n >> 31;
    return (n ^ mask) - mask; // If negative, flip bits and add 1 (two's complement)
}

// Function to convert an integer to a string representation
// Parameters:
// - str[]: Array to store the converted string
// - start_index: Starting index to write in the array
// - end_type: Character to append at the end (e.g., '\0' or a delimiter)
// - num: The integer to convert
// Returns: The new index after writing the number
uint8_t numtostr(uint8_t str[], uint8_t start_index, uint8_t end_type, int num)
{
    uint8_t len = start_index; // Current position in the array

    // Handle negative numbers
    if (num < 0) {
        num = getAbs(num);
        str[len++] = '-'; // Add the minus sign
    }

    // Handle zero explicitly
    if (num == 0) {
        str[len++] = '0';
    }

    // Determine the number of digits (without modifying the number itself)
    int temp_num = num;
    uint8_t digit_count = 0;
    while (temp_num > 0) {
        temp_num /= 10;
        digit_count++;
    }

    // Write the digits into the string array in reverse order
    uint8_t end_pos = len + digit_count - 1; // Final position for digits
    while (num > 0) {
        str[end_pos--] = (num % 10) + '0'; // Convert digit to character
        num /= 10;
    }

    len += digit_count; // Move length pointer past digits

    // Append the end type character
    str[len++] = end_type;

    return len; // Return the new length
}

/**
 * @brief convert uint64 or int64 to string ascii value
 *
 * @param value  uint8 of int 64 value
 * @param type   TAG_DATA_LONG64_UNSIGNED
 *               TAG_DATA_LONG64
 * @param result_array pointer to buffer to carry the converted date
 * @return uint8_t  array size of converted data.
 */
 uint8_t convert_u_int64_to_string(void *value, uint8_t type, uint8_t *result_array)
{
    uint64_t unsigned_value;
    uint64_t temp_value;
    int64_t signed_value;
    uint8_t array_size = 0;

    /* if signed values */
    if (type == TAG_DATA_LONG64)
    {
        signed_value = (int64_t)(*((int64_t *)(value)));
        /* if data is negative convert it to positive */
        if (signed_value < ((int64_t)(-1)))
        {
            unsigned_value = signed_value * ((int64_t)(-1));
            /* add - to the beginning of array*/
            result_array[array_size] = '-';
            array_size++;
        }
        else
        {
            unsigned_value = (uint64_t)(*((uint64_t *)(value)));
        }
    }
    else
    {
        unsigned_value = (uint64_t)(*((uint64_t *)(value)));
    }
/* convert number to ascii value */
    while (unsigned_value > 0)
    {
        temp_value = unsigned_value;
        temp_value = temp_value % 10;
        //sprintf(ARG1_CAST & result_array[array_size], ARG1_CAST "%u", (uint8_t)(temp_value));
        unsigned_value = unsigned_value / 10;
        array_size++;
    }
    /* add array termination */
    result_array[array_size] = 0;
    return array_size;
}
/***********************************************************************************************************************
* Function Name : uint32tostr
* Description   : Converts an uint32_t value into string of ascii.
* Argument      : (int8_t *) str - pointer to output buffer
                  (uint8_t) start_index - value of start_index in str
                  (uint32_t) num - value to be converted
*                 
* Return value  : uint8_t total size of string data 
***********************************************************************************************************************/

uint8_t uint32tostr(uint8_t str[],uint8_t start_index, uint32_t num )
{
	uint8_t  i=start_index;
	uint32_t n=num;
  if(num==0)
  {
    str[start_index++]='0';
    i++;
  }
  else
  {
    while(n)//determine length
    {
      n/=10;
      start_index++;
    }
    i=start_index;
    start_index--;
    while(num)
    {
      uint8_t rem = num %10;
        num /= 10;
        str[start_index--]=rem +'0';
    }
  }
  return i;
}

/***********************************************************************************************************************
* Function Name : int32tostr
* Description   : Converts an int32_t value into string of ascii.
* Argument      : (int8_t *) str - pointer to output buffer
                  (uint8_t) start_index - value of start_index in str
                  (uint32_t) num - value to be converted
*                 
* Return value  : uint8_t total size of string data 
***********************************************************************************************************************/

uint8_t int32tostr(uint8_t str[],uint8_t start_index, int32_t num )
{
	uint8_t  i=start_index;
//	if(start_index==0)str[len++]=',';//for data streamer delimiter sent before number
	int32_t n=num;
    if(num<0)
    {
    	num=getAbs(num);
    	str[start_index++]='-';
    }
    //    str[len++]='0';  str[len++]=',';//in case of float
    if(num==0)str[start_index++]='0';
    while(n)//detrmin length
    {
    	n/=10;
    	start_index++;
    }
	i=start_index;
	start_index-=2;
	while(num)
	{
		uint8_t rem = num %10;
      num /= 10;
      str[start_index--]=rem +'0';
  }
  return i;
}


char* ltoa( long value, char *string, int radix )
{
  char tmp[33];
  char *tp = tmp;
  long i;
  unsigned long v;
  int sign;
  char *sp;
  if ( string == NULL )
  {
    return 0 ;
  }
  if (radix > 36 || radix <= 1)
  {
    return 0 ;
  }
  sign = (radix == 10 && value < 0);
  if (sign)
  {
    v = -value;
  }
  else
  {
    v = (unsigned long)value;
  }
  while (v || tp == tmp)
  {
    i = v % radix;
    v = v / radix;
    if (i < 10)
      *tp++ = i+'0';
    else
      *tp++ = i + 'a' - 10;
  }
  sp = string;
  if (sign)
    *sp++ = '-';
  while (tp > tmp)
    *sp++ = *--tp;
  *sp = 0;
  return string;
}

char* ultoa( unsigned long value, char *string, int radix )
{
  char tmp[33];
  char *tp = tmp;
  long i;
  unsigned long v = value;
  char *sp;

  if ( string == NULL )
  {
    return 0;
  }

  if (radix > 36 || radix <= 1)
  {
    return 0;
  }

  while (v || tp == tmp)
  {
    i = v % radix;
    v = v / radix;
    if (i < 10)
      *tp++ = i+'0';
    else
      *tp++ = i + 'a' - 10;
  }
  sp = string;
  while (tp > tmp)
    *sp++ = *--tp;
  *sp = 0;
  return string;
}

char* itoa( int value, char *string, int radix )
{
  return ltoa( value, string, radix ) ;
}

char* utoa( unsigned int value, char *string, int radix )
{
  return ultoa( value, string, radix ) ;
}

 /**
 * @brief Convert a number to a string of hexadecimal digits
 * 
 * This function converts a 16-bit number to a string of four hexadecimal digits.
 * The digits are stored in the provided buffer in reverse order (i.e., the least significant digit comes first).
 * 
 * @param num The number to convert
 * @param buffer A pointer to the buffer where the digits should be stored
 */
void convert_number_to_string (uint16_t const num, uint8_t * const buffer)
{
    /* Declare a temporary variable */
    uint8_t a;

    /* Forming the string of hexadecimals */
    a = (uint8_t)((num & 0xF000U) >>  12);
    buffer[0] = (uint8_t)((a < 0x0A)? (a + '0') : (a + '7'));
    a = (uint8_t)((num & 0x0F00U) >>  8);
    buffer[1] = (uint8_t)((a < 0x0A)? (a + '0') : (a + '7'));
    a = (uint8_t)((num & 0x00F0U) >>  4);
    buffer[2] = (uint8_t)((a < 0x0A)? (a + '0') : (a + '7'));
    a = (uint8_t)(num & 0x000FU);
    buffer[3] = (uint8_t)((a < 0x0A)? (a + '0') : (a + '7'));
}
/***********************************************************************************************************************
End of function convert_number_to_string
***********************************************************************************************************************/
/**
 * @brief Convert a string to an integer
 * 
 * This function converts a string to an integer. It supports both decimal and hexadecimal numbers, and can handle negative numbers.
 * 
 * @param str The string to convert
 * @return int32_t The integer representation of the string
 */
int32_t convert_string_to_int32(const uint8_t* str)
{
    int32_t result = 0;
    int sign = 1;
    int i = 0;

    // Skip leading whitespace
    while (isspace(str[i]))
    {
        i++;
    }

    // Check for sign
    if (str[i] == '-')
    {
        sign = -1;
        i++;
    }
    else if (str[i] == '+')
    {
        i++;
    }

    // Convert digits
    while (isdigit(str[i]))
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }

    return result * sign;
}

/**
 * @brief Convert a string to an unsigned integer
 * 
 * This function converts a string to an unsigned integer. It supports both decimal and hexadecimal numbers, and can handle negative numbers.
 * 
 * @param str The string to convert
 * @return uint32_t The unsigned integer representation of the string
 */
uint32_t convert_string_to_uint32(const uint8_t* str,uint8_t size)
{
    uint32_t result = 0;
    int i = 0;
    // Skip leading whitespace
    while (isspace(str[i])&&(i<size))
    {
        i++;
    }
    // Convert digits
    while (isdigit(str[i]))
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return result;
}
#ifdef __cplusplus
} // extern "C"
#endif
