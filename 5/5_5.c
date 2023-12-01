int store_bit_field(int original_value,
                    int value_to_store,
                    unsigned start_bit, unsigned end_bit)
{
        /* Calculate the length of the bit field */
        unsigned len = end_bit - start_bit + 1;

        /* Create a bitmask to isolate the bits in the specified range */
        unsigned mask = 1;
        mask <<= len + 1;       /* Shift an extra bit for subtraction later */
        mask -= 1;              /* Set all specified bits in the mask to 1 */
        mask <<= end_bit - 1;   /* Shift to the target bit position */

        /* Clear the original value within the specified bit range */
        original_value &= ~mask;

        /* Prepare the value to store by aligning with the target bit range */
        value_to_store <<= end_bit - 1;
        value_to_store &= mask;

        /* Combine the modified original value and the prepared value to store */
        return value_to_store | original_value;
}
