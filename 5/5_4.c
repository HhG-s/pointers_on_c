void set_bit(char bit_arr[], unsigned bit_num);
void clear_bit(char bit_arr[], unsigned bit_num);
void assign_bit(char bit_arr[], unsigned bit_num, int value);
int test_bit(char bit_arr[], unsigned bit_num);


void
set_bit(char bit_arr[], unsigned bit_num) {
	bit_arr[bit_num] = '1';
}

void
clear_bit(char bit_arr[], unsigned bit_num) {
	bit_arr[bit_num] = '0';
}

void
assign_bit(char bit_arr[], unsigned bit_num, int value) {
	bit_arr[bit_num] = value? '0': '1';
}

int
test_bit(char bit_arr[], unsigned bit_num) {
	return bit_arr[bit_num] - '0';
}