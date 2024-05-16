#include <at24c08.h>

// Create a eprom object configured at address 0
// Sketch assumes that there is an eprom present at this address
AT24C08 eprom(AT24C08_ADDRESS_0);

void setup() {
  Serial.begin(115200);
  Serial.println("Starting up");

  // Initialize the i2c library
  Wire.begin();
  int foo_in;
  eprom.get(0, foo_in);
  Serial.println(foo_in);
  
  /** Write and read an integer */
  int foo = 42;
  // Write the integer foo to the eprom starting at address 0
  eprom.put(0, foo);
  eprom.get(0, foo_in);
  // Read the integer foo_in from eprom starting at address 0
  eprom.get(0, foo_in);
  Serial.println(foo_in);
  
  // Get the last error code, it should be 0 since there was no error
  int lastError = eprom.getLastError();
  Serial.print("last status on write: ");
  Serial.println(lastError);
}

// This test program has no loop, it just runs once
void loop() {
}
