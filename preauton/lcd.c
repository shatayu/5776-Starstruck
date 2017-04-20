/*
Splits auton into numAutons parts, returns values from [0,(numAutons-1)].

@param numAutons: the number of autons the robot has
*/
int autonSelector(int numAutons) {
	return (int) ((SensorValue[Selector]) * (numAutons)/(4096));
}

/*
writes data to second LCD screen (read-only, buttons do not work)

@param line: the line of the string to be written to the LCD
@param s: the string to be written to the LCD

@return 1 if successful
*/
int writeSecondLCD(int line, string s) {
    unsigned char data[22];
    int i, cs;
    int len;

    // bounds check line variable
    if ((line < BOTTOM) || (line > TOP))
        return -1;

    // Header for LCD communication
    data[0] = 0xAA;
    data[1] = 0x55;
    data[2] = 0x1e;
    data[3] = 0x12;
    data[4] = 0x02 + line;

    // Clear transmit buffer
    for(i = 0; i < 16; i++)
        data[5 + i] = 0x20;


    // get string length
    len = strlen(s);
    if (len > 16) len = 16;

    // copy string to transmit buffer
    memcpy(&(data[5]), s, len );

    // calculate checksum
    cs = 0;
    for (i = 4; i < 21; i++)
         cs += data[i];

    data[21] = 0x100 - cs;

    // transmit
    for (i = 0; i < 22; i++) {
        // send char
        sendChar(uartOne, data[i]);

        // wait for transmission complete
        while(!bXmitComplete(uartOne))
        	wait1Msec(20); // should really have some sort of timeout here !
    }
    // success
    return 1;
}

/*
Task to handle data on LCD
*/
task batteryLCD() {
	bLCDBacklight = true;
	string line1 = "Main PE  9V  ";
	string line2;
	string mainBattery, PEBattery, BackupBattery;
	while (true) {
		displayLCDString(TOP, 0, line1);
		sprintf(mainBattery, "%1.2f%c", nImmediateBatteryLevel/985.2); // Build the value to be displayed

		sprintf(PEBattery, "%1.2f%c", SensorValue[PowerExpander]/280.5);

		sprintf(BackupBattery, "%1.2f%c", BackupBatteryLevel/986.0);
		line2 = mainBattery;
		line2 += " ";
		line2 += PEBattery;
		line2 += "  ";
		line2 += BackupBattery;

		displayLCDString(BOTTOM, 0, line2);
		wait1Msec(20);
	}
}

task autonSelect() {
	bLCDBacklight = true;
	while (true) {
		displayLCDNumber(TOP, 0, SensorValue[LiftPot]);
		displayLCDNumber(BOTTOM, 0, SensorValue[Gyro]);
	}
}
