void setup() {
  Serial.begin(9600);
  Serial.println("Enter a test NMEA String.");
}

char rx_byte = 0;
String rx_str = "";

void loop() {
  if (Serial.available() > 0) {    // is a character available?
    rx_byte = Serial.read();       // get the character
    
    if (rx_byte != '\n') {
      // a character of the string was received
      if (rx_byte == '$') {       // Begining of NMEA string
        rx_str = "";              // Clear string buffer
      }
      rx_str += rx_byte;
    }
    else {
      // end of string
      Serial.print("Welcome ");
      Serial.println(rx_str);
      rx_str = "";                // clear the string for reuse
      Serial.println("");
      Serial.println("Enter your name.");
    }
  } // end: if (Serial.available() > 0)
}
