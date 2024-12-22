#include "platform.h"
#include "general.h"

#define SET_BIT(value, bit)       ((value) |= (1U << (bit)))
#define CLEAR_BIT(value, bit)     ((value) &= ~(1U << (bit)))
#define TOGGLE_BIT(value, bit)    ((value) ^= (1U << (bit)))
#define CHECK_BIT(value, bit)     (((value) >> (bit)) & 1U)

STD_RESULT get_bit(U32 number, U8 position, U8 *result) {
    STD_RESULT returnResult = OK;
    
    /* Validate the input parameters */
    if (position > 31 || result == NULL_PTR) {
        returnResult = NOK;
    } else {
        /* Retrieve the bit at the specified position */
        *result = CHECK_BIT(number, position);
    }
    
    return returnResult;
}

STD_RESULT set_bit(U32 *number, U8 value, U8 position) {
    STD_RESULT returnResult = OK;
    
    /* Validate the input parameters */
    if (number == NULL_PTR || value > 1U || position > 31U) {
        returnResult = NOK;
    } else {
        /* Set or clear the bit at the specified position based on the value */
        if (value) {
            SET_BIT(*number, position);
        } else {
            CLEAR_BIT(*number, position);
        }
    }
    
    return returnResult;
}

U8 count_ones(U32 number) {
    U8 count = 0U;
    
    /* Count the number of '1' bits */
    while (number) {
        count += CHECK_BIT(number, 0U);
        number >>= 1U;
    }
    
    return count;
}

STD_RESULT to_binary(U32 number, U8 *output) {
    STD_RESULT returnResult = OK;
    
    /* Validate the output pointer */
    if (output == NULL_PTR) {
        returnResult = NOK;
    } else {
        /* Convert the number to binary based on CPU bit order */
        for (U8 i = 0; i < 32; i++) {
            if (CPU_BIT_ORDER == LSB) {
                output[i] = CHECK_BIT(number, i);
            } else {
                output[31 - i] = CHECK_BIT(number, i);
            }
        }
    }
    
    return returnResult;
}

U32 concatenate_bytes(U8 byte1, U8 byte2, U8 byte3, U8 byte4) {
    U32 result = 0;
    
    /* Concatenate four bytes into a 32-bit number */
    result |= ((U32)byte1 << 24);
    result |= ((U32)byte2 << 16);
    result |= ((U32)byte3 << 8);
    result |= (U32)byte4;
    
    return result;
}

STD_RESULT split_into_bytes(U32 number, U8 *output) {
    STD_RESULT returnResult = OK;
    
    /* Validate the output pointer */
    if (output == NULL_PTR) {
        returnResult = NOK;
    } else {
        /* Split the 32-bit number into its byte components */
        output[0] = (number >> 24) & 0xFF;
        output[1] = (number >> 16) & 0xFF;
        output[2] = (number >> 8) & 0xFF;
        output[3] = number & 0xFF;
    }
    
    return returnResult;
}
