#ifndef CES_CMDIF_H
#define CES_CMDIF_H

#define CESState_Init			0
#define CESState_SOF1_Found		1
#define CESState_SOF2_Found		2
#define	CESState_PktLen_Found	3

#define CESState_EOF_Wait		98
#define	CESState_EOF_Found		99

/*CES CMD IF Packet Format*/
#define	CES_CMDIF_PKT_START_1           0x0A
#define	CES_CMDIF_PKT_START_2           0xFA
#define	CES_CMDIF_PKT_STOP		0x0B

/*CES CMD IF Packet Indices*/
#define	CES_CMDIF_IND_START_1		0
#define	CES_CMDIF_IND_START_2		1
#define	CES_CMDIF_IND_LEN		2
#define	CES_CMDIF_IND_LEN_MSB   	3
#define	CES_CMDIF_IND_PKTTYPE		4
#define	CES_CMDIF_IND_DATA0		5
#define	CES_CMDIF_IND_DATA1		6
#define	CES_CMDIF_IND_DATA2		7

/* CES OTA Data Packet Positions */
#define	CES_OTA_DATA_PKT_POS_LENGTH	0
#define CES_OTA_DATA_PKT_POS_CMD_CAT 	1
#define	CES_OTA_DATA_PKT_POS_DATA_TYPE	2
#define	CES_OTA_DATA_PKT_POS_SENS_TYPE	3
#define	CES_OTA_DATA_PKT_POS_RSVD	4
#define	CES_OTA_DATA_PKT_POS_SENS_ID	5
#define	CES_OTA_DATA_PKT_POS_DATA	6

#define	CES_OTA_DATA_PKT_OVERHEAD	6

#define	CES_CMDIF_PKT_OVERHEAD		5

/* CES CMD IF Packet Types */
#define	CES_CMDIF_TYPE_CMD		0x01
#define	CES_CMDIF_TYPE_DATA		0x02
#define	CES_CMDIF_TYPE_EVT		0x03
#define	CES_CMDIF_TYPE_RSP		0x04
#define CES_CMDIF_TYPE_BULK_DATA	0x05

/* CES CMD IF Command Packet */
#define CES_CMDIF_IND_CMD0		0
#define	CES_CMDIF_IND_CMD1		1

/* CES CMD IF Command Packet */
#define CES_CMDIF_CMD_CAT0		0
#define	CES_CMDIF_CMD_CAT1		1

#define CES_CMD_LOCCAT1                 0x21
#define CES_CMD_OTACAT1                 0x23
#define CES_EVT_LOC_NEWNODE             0x01

/* CES Waves CMDIF Commands */
#define CES_CMD_REM_STARTSENSOR         0x01
#define CES_CMD_REM_STOPSENSOR          0x02
#define CES_CMD_REM_CONFIGSENSOR        0x03

/* CES Waves CMDIF Sensor IDs */
#define CES_SENSORID_TEMP               0x01
#define CES_SENSORID_LIGHT              0x02
#define CES_SENSORID_ACCEL_X            0x03
#define CES_SENSORID_ACCEL_Y            0x04
#define CES_SENSORID_ACCEL_Z            0x05
#define CES_SENSORID_AN_CH0             0x06
#define CES_SENSORID_AN_CH1             0x07
#define CES_SENSORID_AN_CH2             0x08

#define CES_AN_VMULT_V                  0.000244
#define CES_AN_VMULT_MV                 0.24414
#define CES_ACC_GMULT                 0.004

// maximum number of inputs that can be handled
// in one function call
#define MAX_INPUT_LEN 80
// maximum length of filter than can be handled
#define MAX_FLT_LEN 163

// number of samples to read per loop
#define SAMPLES 80
// buffer to hold all of the input samples
#define BUFFER_LEN (MAX_FLT_LEN - 1 + MAX_INPUT_LEN)

#define FILTER_LEN 163

#endif // CES_CMDIF_H
