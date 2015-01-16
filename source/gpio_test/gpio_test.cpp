#include <iostream>
#include <rpi-hw.hpp>
#include <rpi-hw/time.hpp>
#include <rpi-hw/gpio.hpp>

// Use Rpi-hw namespace
using namespace rpihw;

int main() {

	int pinNo = 21;

	std::cout << "Pin test" << std::endl; // prints !!!Hello World!!!




	// GPIO controller interface
	gpio &io = gpio::get();

	// Set the output GPIO to the LED

	io.setup(pinNo, OUTPUT);

	// Main loop
	for (;;) {

		std::cout << "pinNo HIGH" << std::endl; // prints !!!Hello World!!!

		// Turn it on
		io.write(pinNo, HIGH);

		// Wait some time
		time::sleep(4);

		std::cout << "pinNo LOW" << std::endl; // prints !!!Hello World!!!
		// Turn it off
		io.write(pinNo, LOW);

		// Wait some time
		time::sleep(4);
	}

	return 0;
}
