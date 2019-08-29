/*
* In order to build the example, add libm2k-sharp.dll as a reference to the project.
* For example, in the command line: mcs voltmeter.cs -reference:libm2k-sharp.dll
* Please make sure that libm2k-sharp.dll and libm2k-sharp-cxx-wrap.dll
* Please make sure that the location of libm2k is in the PATH.
*/

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace examples
{
    class Voltmeter
    {
        static void Main()
        {
            M2k ctx = libm2k.m2kOpen();
            ctx.calibrateADC();

            // Setup analog in
            M2kAnalogIn ain = ctx.getAnalogIn();
            ain.enableChannel(0, true);

            double voltage = ain.getVoltage(ANALOG_IN_CHANNEL.ANALOG_IN_CHANNEL_1);

            Console.WriteLine(voltage);
            libm2k.deviceClose(ctx);
        }
    }
}