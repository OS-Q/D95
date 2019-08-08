
#ifndef _HTU21_H
#define _HTU21_H

#if (ARDUINO >= 100)
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif
#include "Wire.h"

/** Default I2C address for the HTU21D. */
#define HTU21_I2CADDR         (0x40)

/** Read temperature register. */
#define HTU21_READTEMP        (0xE3)

/** Read humidity register. */
#define HTU21_READHUM         (0xE5)

/** Write register command. */
#define HTU21_WRITEREG        (0xE6)

/** Read register command. */
#define HTU21_READREG         (0xE7)

/** Reset command. */
#define HTU21_RESET           (0xFE)

/**
 * Driver for the Adafruit HTU21 breakout board.
 */
class HTU21 {
    public:
        HTU21();

        boolean begin(void);
        float   readTemperature(void);
        float   readHumidity(void);
        void    reset(void);

    private:
        boolean readData(void);
        float _last_humidity, _last_temp;
};

#endif /* _ADAFRUIT_HTU21_H */
