#ifndef HoTTv4_h
#define HoTTv4_h

#define HOTTV4_GPS_SENSOR_ID 0x8A // GPS Sensor ID
#define HOTTV4_GPS_SENSOR_TEXT_ID 0xA0 // GPS Module ID

const uint8_t kHoTTv4BinaryPacketSize = 45; 
const uint8_t kHoTTv4TextPacketSize = 173;

typedef enum {
  HoTTv4NotificationErrorCalibration     = 0x01,
  HoTTv4NotificationErrorReceiver        = 0x02,
  HoTTv4NotificationErrorDataBus         = 0x03,
  HoTTv4NotificationErrorNavigation      = 0x04,
  HoTTv4NotificationErrorError           = 0x05,
  HoTTv4NotificationErrorCompass         = 0x06,
  HoTTv4NotificationErrorSensor          = 0x07,
  HoTTv4NotificationErrorGPS             = 0x08,
  HoTTv4NotificationErrorMotor           = 0x09,
  
  HoTTv4NotificationMaxTemperature       = 0x0A,
  HoTTv4NotificationAltitudeReached      = 0x0B,
  HoTTv4NotificationWaypointReached      = 0x0C,
  HoTTv4NotificationNextWaypoint         = 0x0D,
  HoTTv4NotificationLanding              = 0x0E,
  HoTTv4NotificationGPSFix               = 0x0F,
  HoTTv4NotificationUndervoltage         = 0x10,
  HoTTv4NotificationGPSHold              = 0x11,
  HoTTv4NotificationGPSHome              = 0x12,
  HoTTv4NotificationGPSOff               = 0x13,
  HoTTv4NotificationBeep                 = 0x14,
  HoTTv4NotificationMicrocopter          = 0x15,
  HoTTv4NotificationCapacity             = 0x16,
  HoTTv4NotificationCareFreeOff          = 0x17,
  HoTTv4NotificationCalibrating          = 0x18,
  HoTTv4NotificationMaxRange             = 0x19,
  HoTTv4NotificationMaxAltitude          = 0x1A,
  
  HoTTv4Notification20Meter              = 0x25,
  HoTTv4NotificationMicrocopterOff       = 0x26,
  HoTTv4NotificationAltitudeOn           = 0x27,
  HoTTv4NotificationAltitudeOff          = 0x28,
  HoTTv4Notification100Meter             = 0x29,
  HoTTv4NotificationCareFreeOn           = 0x2E,
  HoTTv4NotificationDown                 = 0x2F,
  HoTTv4NotificationUp                   = 0x30,
  HoTTv4NotificationHold                 = 0x31,
  HoTTv4NotificationGPSOn                = 0x32,
  HoTTv4NotificationFollowing            = 0x33,
  HoTTv4NotificationStarting             = 0x34,
  HoTTv4NotificationReceiver             = 0x35,
} HoTTv4Notification;

struct {
  uint8_t startByte;               /* Byte 1: 0x7C = Start byte data */
  uint8_t sensorID;                /* Byte 2: 0x8A = GPS Sensor */
  uint8_t alarmTone;               /* Byte 3: 0…= warning beeps */
  uint8_t sensorTextID;            /* Byte 4: 160 0xA0 Sensor ID Neu! */
  uint8_t alarmInverse1;           /* Byte 5: 01 inverse status */
  uint8_t alarmInverse2;           /* Byte 6: 00 inverse status status 1 = kein GPS Signal */
  uint8_t flightDirection;         /* Byte 7: 119 = Flightdir./dir. 1 = 2°; 0° (North), 9 0° (East), 180° (South), 270° (West) */
  uint8_t GPSSpeedLow;             /* Byte 8: 8 = /GPS speed low byte 8km/h */
  uint8_t GPSSpeedHigh;            /* Byte 9: 0 = /GPS speed high byte */
  
  uint8_t LatitudeNS;              /* Byte 10: 000 = N = 48°39’988 */
  uint8_t LatitudeMinLow;          /* Byte 11: 231 0xE7 = 0x12E7 = 4839 */
  uint8_t LatitudeMinHigh;         /* Byte 12: 018 18 = 0x12 */
  uint8_t LatitudeSecLow;          /* Byte 13: 171 220 = 0xDC = 0x03DC =0988 */
  uint8_t LatitudeSecHigh;         /* Byte 14: 016 3 = 0x03 */
 
  uint8_t longitudeEW;            /* Byte 15: 000  = E= 9° 25’9360 */
  uint8_t longitudeMinLow;         /* Byte 16: 150 157 = 0x9D = 0x039D = 0925 */
  uint8_t longitudeMinHigh;        /* Byte 17: 003 3 = 0x03 */
  uint8_t longitudeSecLow;         /* Byte 18: 056 144 = 0x90 0x2490 = 9360*/
  uint8_t longitudeSecHigh;        /* Byte 19: 004 36 = 0x24 */
  
  uint8_t distanceLow;             /* Byte 20: 027 123 = /distance low byte 6 = 6 m */
  uint8_t distanceHigh;            /* Byte 21: 036 35 = /distance high byte */
  uint8_t altitudeLow;             /* Byte 22: 243 244 = /Altitude low byte 500 = 0m */
  uint8_t altitudeHigh;            /* Byte 23: 001 1 = /Altitude high byte */
  uint8_t resolutionLow;           /* Byte 24: 48 = Low Byte m/s resolution 0.01m 48 = 30000 = 0.00m/s (1=0.01m/s) */
  uint8_t resolutionHigh;          /* Byte 25: 117 = High Byte m/s resolution 0.01m */
  uint8_t unknow1;                 /* Byte 26: 120 = 0m/3s */
  uint8_t GPSNumSat;               /* Byte 27: GPS.Satelites (number of satelites) (1 byte) */
  uint8_t GPSFixChar;              /* Byte 28: GPS.FixChar. (GPS fix character. display, if DGPS, 2D oder 3D) (1 byte) */
  uint8_t HomeDirection;           /* Byte 29: HomeDirection (direction from starting point to Model position) (1 byte) */
  uint8_t angleXdirection;         /* Byte 30: angle x-direction (1 byte) */
  uint8_t angleYdirection;         /* Byte 31: angle y-direction (1 byte) */
  uint8_t angleZdirection;         /* Byte 32: angle z-direction (1 byte) */
  uint8_t gyroXLow;                /* Byte 33: gyro x low byte (2 bytes) */
  uint8_t gyroXHigh;               /* Byte 34: gyro x high byte */
  uint8_t gyroYLow;                /* Byte 35: gyro y low byte (2 bytes) */
  uint8_t gyroYHigh;               /* Byte 36: gyro y high byte */
  uint8_t gyroZLow;                /* Byte 37: gyro z low byte (2 bytes) */
  uint8_t gyroZHigh;               /* Byte 38: gyro z high byte */
  uint8_t vibration;               /* Byte 39: vibration (1 bytes) */
  uint8_t Ascii4;                  /* Byte 40: 00 ASCII Free Character [4] */
  uint8_t Ascii5;                  /* Byte 41: 00 ASCII Free Character [5] */
  uint8_t GPS_fix;                 /* Byte 42: 00 ASCII Free Character [6], we use it for GPS FIX */
  uint8_t version;                 /* Byte 43: 00 version number */
  uint8_t endByte;                 /* Byte 44: 0x7D Ende byte */
  uint8_t chksum;                  /* Byte 45: Parity Byte */
} HoTTV4GPSModule;

#endif
