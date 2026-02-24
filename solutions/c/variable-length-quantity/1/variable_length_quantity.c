 #include "variable_length_quantity.h"

int encode(const uint32_t *integers, size_t integers_len, uint8_t *output)
{
    // write to `output`, return final output's length
    // `output` buffer should be enough to hold the full result

    int out_index = 0;

    for (size_t j = 0; j < integers_len; j++) {

        uint32_t value = integers[j];
        uint8_t buffer[5];   // max 5 bytes for 32-bit value
        int count = 0;

        // Extract 7-bit chunks
        do {
            buffer[count++] = value & 0x7F;
            value >>= 7;
        } while (value > 0);

        // Write in reverse order with continuation bits

        for (int i = count - 1; i >= 0; i--) {
            uint8_t byte = buffer[i];
            if (i != 0)
                byte |= 0x80;  // set continuation bit
            output[out_index++] = byte;
        }
    }

    return out_index; // number of bytes written
}

int decode(const uint8_t *bytes, size_t buffer_len, uint32_t *output)
{
    // write to `output`, return final output's length
    // return -1 if error
    // `output` buffer should be enough to hold the full result

    if (buffer_len <= 1 && bytes[0] & 0x80)return -1;
    int len = 0;
    uint32_t value = 0;

    for (size_t j = 0; j < buffer_len;) {
        while (1) {
            uint8_t byte = bytes[j];
            value = (value << 7) | (byte & 0x7F);
            j++;

            if ((byte & 0x80) == 0) // last byte
            {
                output[len++] = value;
                value = 0;
                break;
            }

        }

    }

    return len;
}