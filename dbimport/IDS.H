/*
********************************************** S H A R E D ***************
*
*       Copyright                       : Hottinger Baldwin Meßtechnik GmbH
*
*************************************************************************
*** I D E N T I F I K A T I O N ******************************************
*
*       Dateiname                       : IDS.H
*       Projekt                         : Firmware für Spider8
*                                       : Firmware fuer MGCplus
*                                       : Firmware fuer PME
*
*** E N T W I C K L U N G S U M G E B U N G ******************************
*
*       Entwicklungssystem      :
*       Hardware                        : DELL Dimension XPS P120c
*                                               : I+ME EvaBoard C167 2.0
*       Sprache                         : GNU C
*       Editor                          : Codewright 3.1
*       Emulator                        : fast-view 66
*       Betriebssystem                  : MS Windows 3.1
*
*       Zielsystem                      :
*       Hardware                        : Spider8 mit Mikrocontroller 80C167
*       Betriebssystem                  : -
*
*       Bemerkungen                     : Header-Datei für C-Code
*


#ifndef _IDSDEF_H
 #define _IDSDEF_H

/* hoffmann reserved 30000...30500 */

/**************************************************************************
 Allgemein
**************************************************************************/
#define IDS_AUS                 0
#define IDS_EIN                 1
#define IDS_NEIN                2
#define IDS_JA                  3
#define IDS_GESPERRT            4
#define IDS_FREI                5
#define IDS_INAKTIV             6
#define IDS_AKTIV               7

/**************************************************************************
* Brueckenspeisespannung
**************************************************************************/
#define IDS_NOBSPG              10
#define IDS_1V_BSPG             11
#define IDS_1p25V_BSPG          12
#define IDS_2p5V_BSPG           13
#define IDS_5V_BSPG             14
#define IDS_10V_BSPG            15
#define IDS_2_20mA              16
#define IDS_0p2V_BSPG           17
#define IDS_0p5V_BSPG           18
#define IDS_3V_BSPG             19
#define IDS_6V_BSPG             20


/**************************************************************************
* Eingangsamplitude
**************************************************************************/
#define IDS_5V_EING             21
#define IDS_100mV_EING          22

/**************************************************************************
* Eingangsschaltung ML460
**************************************************************************/
#define IDS_IN_AP460_DIRECT     23
#define IDS_IN_AP460_INDUCTIVE  24

/**************************************************************************
* Eingangsschaltung  ML35B, Widerstandsmessung
**************************************************************************/
#define IDS_3Leiter             25
#define IDS_4Leiter             26


/**************************************************************************
* Zeitkonstante
**************************************************************************/
#define IDS_SHORT               31
#define IDS_MEDIUM              32
#define IDS_LONG                33



/*************************************************************************
* Eingangssignal
**************************************************************************/
#define IDS_NULLSIG             40
#define IDS_KALSIG              41
#define IDS_MESSIG              42
#define IDS_TEMPSIG             43

#define IDS_SHUNT_POS           44
#define IDS_SHUNT_NEG           45

#define IDS_MES_NoUb            46  // AP810, AP814, AP815, AP836
#define IDS_NOSIG               47
#define IDS_EXTKALSIG           48
/*************************************************************************
* Fernsteuerfunktion
**************************************************************************/
#define IDS_F_NOP               50
#define IDS_F_ACL               51
#define IDS_F_TARA              52
#define IDS_F_CPV1              53
#define IDS_F_HLD1              54
#define IDS_F_CPV2              55
#define IDS_F_HLD2              56
#define IDS_F_ZERO              57
#define IDS_F_SHNT              58
#define IDS_F_PRT               59
#define IDS_F_KAL               60
#define IDS_F_NULL              61
#define IDS_F_INV               62
#define IDS_F_PA1               63
#define IDS_F_PA2               64
#define IDS_F_PA3               65
#define IDS_F_REM               66
#define IDS_F_INT               67
#define IDS_F_FREQ              68
#define IDS_F_RNGE              69
#define IDS_F_TVRGL             70
#define IDS_F_MPV1              71
#define IDS_F_MPV2              72
#define IDS_F_PA4               73

#define IDS_F_PRT_MW            80  // Messwert drucken
#define IDS_F_PRT_FF            81  // Seitenvorschub auslöesen
#define IDS_F_TRIG              82  // externen Trigger auslösen
#define IDS_F_STP               83  // stop aquisition

#define IDS_F_HDFULL            90  // Harddisk is full


#define IDS_NO_INPUT            100
#define IDS_EING1               101
#define IDS_EING2               102
#define IDS_EING3               103
#define IDS_EING4               104
#define IDS_EING5               105 //mp85


/*************************************************************************
* Schrittweite
**************************************************************************/
#define IDS_STEP_1              110
#define IDS_STEP_2              111
#define IDS_STEP_5              112
#define IDS_STEP_10             113
#define IDS_STEP_20             114
#define IDS_STEP_50             115
#define IDS_STEP_100            116
#define IDS_STEP_200            117
#define IDS_STEP_500            118
#define IDS_STEP_1000           119


/*************************************************************************
* Schaltrichtung Grenzwerte
**************************************************************************/
#define IDS_GW_UEBER            130
#define IDS_GW_UNTER            131


/*************************************************************************
* Ausgangslogik Grenzwerte
**************************************************************************/
#define IDS_GW_POSITIV          135
#define IDS_GW_NEGATIV          136


/*************************************************************************
* ASF Filtercharakteristik
*************************************************************************/
#define IDS_NoFil               140
#define IDS_Butw                141
#define IDS_Bess                142
#define IDS_aperio              143
#define IDS_Butw4               144     // 4.Ordnung für 8-kan
#define IDS_Bess4               145     // 4.Ordnung für 8-kan
#define IDS_CFC                 146     // CFC-Norm-konform 15.06.04

#define IDS_Filt1               148
#define IDS_Filt2               149


/*************************************************************************
* Verknüpfungsart
*************************************************************************/
#define IDS_NO_COM              150
#define IDS_AND                 151
#define IDS_OR                  152
#define IDS_EXOR                153
#define IDS_NAND                154
#define IDS_NOR                 155
#define IDS_NEXOR               156


/*************************************************************************
* Modus Spitzenwertspeicher
*************************************************************************/
#define IDS_BR_MIN              180
#define IDS_NET_MIN             181
#define IDS_BR_MAX              182
#define IDS_NET_MAX             183
#define IDS_BR_SPSP             184
#define IDS_NET_SPSP            185
#define IDS_VER_SPSP            186
#define IDS_VER_MITTEL          187
#define IDS_INT_BRUTTO          188
#define IDS_INT_NETTO           189
#define IDS_NOSPW               190
#define IDS_SP1_VAL_HOLD        191
#define IDS_SP2_VAL_HOLD        192


/*************************************************************************
* Signaltyp
*************************************************************************/
#define IDS_NO_SIG              200
#define IDS_DISP_SIG            201
#define IDS_BR_SIG_FILT         202
#define IDS_NT_SIG_FILT         203
#define IDS_SPWT1_SIG           204
#define IDS_SPWT2_SIG           205
#define IDS_GW1_EIN_SIG         206
#define IDS_GW1_AUS_SIG         207
#define IDS_GW2_EIN_SIG         208
#define IDS_GW2_AUS_SIG         209
#define IDS_GW3_EIN_SIG         210
#define IDS_GW3_AUS_SIG         211
#define IDS_GW4_EIN_SIG         212
#define IDS_GW4_AUS_SIG         213
#define IDS_BR_SIG_DYN          214
#define IDS_NT_SIG_DYN          215
#define IDS_GW_STAT_SIG         216
#define IDS_SPWT_VER_SIG        217

#define IDS_SPWTSS_SIG          218
#define IDS_USR_SIG             219
#define IDS_CONTROLLER_SIG      220      //aus einem Signal im Controller   z.B.:CAN-Signal

#define IDS_GW1                 221
#define IDS_GW2                 222
#define IDS_GW3                 223
#define IDS_GW4                 224

#define IDS_BR2_SIG_DYN         225     // Gross sec. dig. signal path (MGC++ GA11)
#define IDS_NT2_SIG_DYN         226     // Net sec. dig. signal path (MGC++ GA11)

#define IDS_USR_SIG2            227     //th t12
#define IDS_USR_SIG3            228     //th t12
#define IDS_USR_SIG4            229     //th t12

#define IDS_ERR                 230
#define IDS_MOTION              231
#define	IDS_FREQ1               232
#define IDS_FREQ2               233
#define IDS_DIRECTION           234
#define IDS_PULSE               235

#define IDS_USR_SIG5            236     //th t12
#define IDS_USR_SIG6            237     //th t12
#define IDS_USR_SIG7            238     //th t12
#define IDS_USR_SIG8            239     //th t12

#define IDS_ERR_2               240   //rh MP85
#define IDS_GW1_2               241
#define IDS_GW2_2               242
#define IDS_GW1_3               243
#define IDS_GW2_3               244
#define IDS_GW1_4               245
#define IDS_GW2_4               246
#define IDS_GW3_2               247    //rh MP85
#define IDS_GW4_2               248    //rh MP85
#define IDS_DIRECT_OUT1         249    //rh MP85
#define IDS_DIRECT_OUT2         250    //rh MP85
#define IDS_DIRECT_OUT3         251    //rh MP85
#define IDS_DIRECT_OUT4         252    //rh MP85
#define IDS_DIRECT_OUT5         253    //rh MP85
#define IDS_DIRECT_OUT6         254    //rh MP85
#define IDS_DIRECT_OUT7         255    //rh MP85
#define IDS_DIRECT_OUT8         256    //rh MP85
#define IDS_SENSORCHECK_OK1     257    //rh MP85
#define IDS_SENSORCHECK_OK2     258    //rh MP85
#define IDS_NOMEASVALINT        259    //rh MP85

#define IDS_SPWT1_SIG_2         260
#define IDS_SPWT1_SIG_3         261
#define IDS_SPWT1_SIG_4         262
#define IDS_SPWT2_SIG_2         265
#define IDS_SPWT2_SIG_3         266
#define IDS_SPWT2_SIG_4         267

#define IDS_SPWTSS_SIG_2        270
#define IDS_SPWTSS_SIG_3        271
#define IDS_SPWTSS_SIG_4        272

#define IDS_BR_SIG_DYN_2        280
#define IDS_BR_SIG_DYN_3        281
#define IDS_BR_SIG_DYN_4        282
#define IDS_BR2_SIG_DYN_2       283 //rh T12

#define IDS_NT_SIG_DYN_2        285
#define IDS_NT_SIG_DYN_3        286
#define IDS_NT_SIG_DYN_4        287

#define IDS_FLOWRATE            288
#define IDS_REMOTE_STATE        289 // status of remote contacts (MGC++)

#define IDS_USER_INFO           299 // string für User-Abfrage Ki 19.12.2003

/*************************************************************************
Analogausgang
*************************************************************************/
#define IDS_A_10V               290
#define IDS_A_20mA              291
#define IDS_A_4_20mA            292


/*************************************************************************
* logisches Eingangssignal
*************************************************************************/
#define IDS_VER_NOP             300
#define IDS_VER_GW1             301
#define IDS_VER_GW1X            302
#define IDS_VER_GW2             303
#define IDS_VER_GW2X            304
#define IDS_VER_GW3             305
#define IDS_VER_GW3X            306
#define IDS_VER_GW4             307
#define IDS_VER_GW4X            308
#define IDS_VER_IN1             309
#define IDS_VER_IN1X            310
#define IDS_VER_IN2             311
#define IDS_VER_IN2X            312
#define IDS_VER_IN3             313
#define IDS_VER_IN3X            314
#define IDS_VER_IN4             315
#define IDS_VER_IN4X            316


/*************************************************************************
* ASA Aufnehmerart
*************************************************************************/
#define IDS_VoBr                350
#define IDS_HaBr                351
#define IDS_VIERTELBR           352
#define IDS_DMS_VOLL            353     /* ML30, ML55 */
#define IDS_DMS_HALB            354     /* ML55 */
#define IDS_DMS_VIERTEL         355
#define IDS_IND_VOLL            356     /* ML55 */
#define IDS_IND_HALB            357     /* ML55 */
#define IDS_LOW_VOLL            358     /* ML10 */
#define IDS_LOW_HALB            359     /* ML10 */
#define IDS_HIGH_VOLL           360     /* ML10 */
#define IDS_HIGH_HALB           361     /* ML10 */
#define IDS_DMS_VOLL_120        362     /* AP14 */
#define IDS_DMS_VOLL_350        363     /* AP14 */
#define IDS_DMS_VOLL_700        364     /* AP14 */
#define IDS_DMS_HALB_120        365     /* AP14 */
#define IDS_DMS_HALB_350        366     /* AP14 */
#define IDS_DMS_HALB_700        367     /* AP14 */
#define IDS_4L_VIERTEL_120      368     /* AP14, AP815 */
#define IDS_4L_VIERTEL_350      369     /* AP14, AP815 */
#define IDS_4L_VIERTEL_700      370     /* AP14, AP815 */
#define IDS_3L_VIERTEL_120      371     /* AP14, AP814 */
#define IDS_3L_VIERTEL_350      372     /* AP14, AP814 */
#define IDS_3L_VIERTEL_700      373     /* AP14, AP814 */
#define IDS_3L_VIERTEL_1000     374     /* AP814 opt */
#define IDS_3L_VIERTEL_USER     375     /* AP814 opt */
#define IDS_4L_VIERTEL_1000     376     /* AP815 opt */
#define IDS_4L_VIERTEL_USER     377     /* AP815 opt */

#define IDS_LVDT                380
#define IDS_POTI                385     /* AP836 */

#define IDS_TORQUE1             386     //T12
#define IDS_SPEED1              387     //T12
#define IDS_TURNANGLE1          388     //T12
#define IDS_POWER1              389     //T12
#define IDS_TORQUE2             390     //T12
#define IDS_SPEED2              391     //T12
#define IDS_TURNANGLE2          392     //T12
#define IDS_POWER2              393     //T12
#define IDS_TORQUESPEED1        394     //T12
#define IDS_TORQUESPEED2        395     //T12
#define IDS_TORQUETURNANGLE1    396     //T12
#define IDS_TORQUETURNANGLE2    397     //T12
#define IDS_POWER1POWER2        398     //T12
#define IDS_STATE               399     //T12
#define IDS_SPEEDTURNANGLE1     400     //T12


#define IDS_DCVo                420
#define IDS_DCAm                421
#define IDS_2_TRANSMIT          422     /*MP01*/
#define IDS_DC75MV              425     /* ML01   */
#define IDS_DC10V               426     /* ML01   */
#define IDS_DC20MA              427     /* ML01, AP402 +-20mA */
#define IDS_DC2V                428     /*Ki AP801S41 2V */
#define IDS_DC0V1               429     /*Ki AP801S41 0.1V */
#define IDS_DCUSER              430     /*Ki AP801S41 free: variable */
#define IDS_TF                  431     //fuer den CanHead SM
#define IDS_DC                  432     //fuer den CanHead SM
#define IDS_DC60V               433     /*Ki AP402   */
#define IDS_DC1V                434     /*Ki AP402   */
#define IDS_DC4_20MA            435     /* AP402 4..20mA */

#define IDS_Thermo              449
#define IDS_ThmJ                450
#define IDS_ThmK                451
#define IDS_ThmT                452
#define IDS_ThmS                453
#define IDS_ThmB                454	  /* Spider8 */
#define IDS_ThmE                455	  /* Spider8 */
#define IDS_ThmR                456	  /* Spider8 */
#define IDS_ThmN                457	  /* ML801 7.8.2000 P5.06 */

#define IDS_Resi                475
#define IDS_500_OHM             476     /* ML35 */
#define IDS_5000_OHM            477     /* ML35, AP835 Sonder */
#define IDS_2500_OHM            478     /* AP835 Sonder */
#define IDS_50_OHM              479     /* AP835 Sonder */

#define IDS_PT10                500     /* ML35 */
#define IDS_PT100               501
#define IDS_PT500               502
#define IDS_PT1000              503

#define IDS_ThmI                510

#define IDS_Freq                520
#define IDS_FuD                 521
#define IDS_2P1F                522
#define IDS_2P2F                523
#define IDS_DURATION            524     // ML460 Mu
#define IDS_Cnt                 525
#define IDS_kCnt                526     /* ML60B */
#define IDS_PWM                 527     // ML460 Mu

#define IDS_DigIO16             528

#define IDS_FREQ_2KHZ           530     /* ML60 */
#define IDS_FREQ_20KHZ          531     /* ML60 */
#define IDS_FREQ_200KHZ         532     /* ML60 */
#define IDS_FREQ_1MHz		        533
#define IDS_FREQ_100kHz		     	534
#define IDS_FREQ_10kHz 		    	535
#define IDS_FREQ_1kHz 			    536
#define IDS_FREQ_2MHZ           537     /* ML60B */
#define IDS_FREQ_500KHZ         538    //ML460 Mu

#define IDS_DTRON_0p1           550     /* AP18 */
#define IDS_DTRON_1p0           551     /* AP18 */
#define IDS_DTRON_10            552     /* AP18 */
#define IDS_DELTATRON           555     // generic

#define IDS_LADUNG              570
#define IDS_Q_0p1NC             571     /* AP08 */
#define IDS_Q_1NC               572     /* AP08 */
#define IDS_Q_10NC              573     /* AP08 */
#define IDS_Q_100NC             574     /* AP08 */

#define IDS_SSI                 580     //MP85 SSI Geber
#define IDS_Time                581     //TimeChannnel MP85
#define IDS_noAP                599     /* noAP -> keine Aufnehmerart */

/*******************************************************
* SSI Aufnehmer  reserved til 699 rh MP85
*******************************************************/
#define IDS_SSI_SingleTurn      680
#define IDS_SSI_MultiTurn       681
#define IDS_SSI_GrayCode        687
#define IDS_SSI_DualCode        688
#define IDS_SSI_Resolution_12   690
#define IDS_SSI_Resolution_13   691
#define IDS_SSI_Resolution_24   692
#define IDS_SSI_Resolution_25   693

/*************************************************************************
* ASA Meßbereiche
*************************************************************************/
#define IDS_3mV                 700
#define IDS_12mV                701
#define IDS_125mV               702
#define IDS_500mV               703

#define IDS_0V1                 710
#define IDS_1V0                 711
#define IDS_10V0                712

#define IDS_20mA                720
#define IDS_200mA               721

#define IDS_0KO4                730
#define IDS_4KO0                731

#define IDS_F1MHz               740
#define IDS_F0MHz1              741
#define IDS_F10kHz              742
#define IDS_F1kHz               743
#define IDS_F0kHz1              744

#define IDS_T10ms               750
#define IDS_T100ms              751
#define IDS_T1s                 752
#define IDS_T10s                753
#define IDS_T100s               754

#define IDS_Count               760
#define IDS_Cd100               761

#define IDS_Bit1                765

#define IDS_Temp                770

#define IDS_6mV                 771
#define IDS_15mV                772
#define IDS_50mV                773
#define IDS_100mV               774
#define IDS_250mV               775
#define IDS_1000mV              776
#define IDS_2500mV              777
#define IDS_4mV                 778  //rh MP85
#define IDS_10mV                779  //we. DigiClip

/*************************************************************************
* MSQ Status-Meldungen  30.5.2001 Ki
*************************************************************************/
#define IDS_MSQ_idle            850
#define IDS_MSQ_notapp          851
#define IDS_MSQ_aborted         852
#define IDS_MSQ_start           853
#define IDS_MSQ_mess1           854
#define IDS_MSQ_mess2           855
#define IDS_MSQ_mess3           856
#define IDS_MSQ_mess4           857
#define IDS_MSQ_done            858

/*************************************************************************
* ASF Tiefpass-Filterfrequenzen
*************************************************************************/
#define IDS_F0Hz010             901
#define IDS_F0Hz012             902
#define IDS_F0Hz015             903
#define IDS_F0Hz020             904
#define IDS_F0Hz025             905
#define IDS_F0Hz030             906
#define IDS_F0Hz040             907
#define IDS_F0Hz050             908
#define IDS_F0Hz060             909
#define IDS_F0Hz070             910
#define IDS_F0Hz075             911
#define IDS_F0Hz080             912
#define IDS_F0Hz090             913
#define IDS_F0Hz10              914
#define IDS_F0Hz12              915
#define IDS_F0Hz15              916
#define IDS_F0Hz20              917
#define IDS_F0Hz25              918
#define IDS_F0Hz30              919
#define IDS_F0Hz40              920
#define IDS_F0Hz50              921
#define IDS_F0Hz60              922
#define IDS_F0Hz70              923
#define IDS_F0Hz75              924
#define IDS_F0Hz80              925
#define IDS_F0Hz90              926
#define IDS_F1Hz00              927
#define IDS_F1Hz20              928
#define IDS_F1Hz25              929
#define IDS_F1Hz50              930
#define IDS_F2Hz00              931
#define IDS_F2Hz50              932
#define IDS_F003Hz              933
#define IDS_F004Hz              934
#define IDS_F005Hz              935
#define IDS_F006Hz              936
#define IDS_F007Hz              937
#define IDS_F007Hz5             938
#define IDS_F008Hz              939
#define IDS_F009Hz              940
#define IDS_F010Hz              941
#define IDS_F012Hz              942
#define IDS_F015Hz              943
#define IDS_F017Hz5             944
#define IDS_F020Hz              945
#define IDS_F025Hz              946
#define IDS_F030Hz              947
#define IDS_F040Hz              948
#define IDS_F050Hz              949
#define IDS_F060Hz              950
#define IDS_F070Hz              951
#define IDS_F075Hz              952
#define IDS_F080Hz              953
#define IDS_F090Hz              954
#define IDS_F100Hz              955
#define IDS_F120Hz              956
#define IDS_F150Hz              957
#define IDS_F200Hz              958
#define IDS_F250Hz              959
#define IDS_F300Hz              960
#define IDS_F400Hz              961
#define IDS_F500Hz              962
#define IDS_F550Hz              963
#define IDS_F600Hz              964
#define IDS_F700Hz              965
#define IDS_F750Hz              966
#define IDS_F800Hz              967
#define IDS_F900Hz              968
#define IDS_F1KHz0              969
#define IDS_F1KHz1              970
#define IDS_F1KHz2              971
#define IDS_F1KHz5              972
#define IDS_F2KHz0              973
#define IDS_F2KHz4              974
#define IDS_F2KHz5              975
#define IDS_F3KHz0              976
#define IDS_F4KHz0              977
#define IDS_F5KHz0              978
#define IDS_F6KHz0              979
#define IDS_F7KHz0              980
#define IDS_F7KHz5              981
#define IDS_F8KHz0              982
#define IDS_F9KHz0              983
#define IDS_F10KHz0             1100
#define IDS_F50KHz0             1140
#define IDS_F100KHz0            1150

#define IDS_F_unfilt            1199

/*************************************************************************
* HPS Hochpass-Filterfrequenzen
*************************************************************************/
#define IDS_HpsOff              1200
#define IDS_HpsF0Hz10           1201
#define IDS_HpsF1Hz00           1202
#define IDS_HpsF010Hz           1203
#define IDS_HpsF0Hz30           1204    //MP55F31 rh
#define IDS_HpsF0Hz01           1205    //MP55F31 rh
#define IDS_HpsF0Hz03           1206    //MP55F31 rh
#define IDS_HpsF2Hz00           1207    //MP55F31 rh
#define IDS_HpsF5Hz00           1208    //MP55F31 rh
#define IDS_HpsF10Hz0           1209    //MP55F31 rh


/*************************************************************************
* Messwertausgabeformat
*************************************************************************/
#define IDS_ASCII_CHN_STAT      1250
#define IDS_ASCII               1251
#define IDS_4B_BIN_MSB_LSB      1252
#define IDS_4B_BIN_LSB_MSB      1253
#define IDS_2B_BIN_MSB_LSB      1254
#define IDS_2B_BIN_LSB_MSB      1255
#define IDS_4B_FL_MSB_LSB       1256
#define IDS_4B_FL_LSB_MSB       1257


/*************************************************************************
* Schnittstelle
*************************************************************************/
#define IDS_Interf_Act          1300
#define IDS_RS232               1301
#define IDS_RS485               1302
#define IDS_IEEE488             1303
#define IDS_IEEE1284            1304
#define IDS_Ethernet            1305
#define IDS_Interlnk            1306
#define IDS_USBDevice           1307
#define IDS_USBHost             1308
#define IDS_Firewire            1309
#define IDS_Ethernet2           1310
#define IDS_Wireless            1311
#define IDS_Wireless2           1312

/*************************************************************************
* Schnittstellenformat
*************************************************************************/
#define IDS_No_Par              1350
#define IDS_Even_Par            1351
#define IDS_Odd_Par             1352


/*************************************************************************
* BDR Baudraten
*************************************************************************/
#define IDS_75Bd                1400
#define IDS_110Bd               1401
#define IDS_150Bd               1402
#define IDS_300Bd               1403
#define IDS_600Bd               1404
#define IDS_1KBd2               1405
#define IDS_2KBd4               1406
#define IDS_4KBd8               1407
#define IDS_9KBd6               1408
#define IDS_10KBd               1409
#define IDS_19KBd2              1410
#define IDS_20KBd               1411
#define IDS_38KBd4              1412
#define IDS_50KBd               1413
#define IDS_57KBd6              1414
#define IDS_76KBd8              1415
#define IDS_115KBd              1416
#define IDS_125KBd              1417
#define IDS_153KBd6             1418
#define IDS_250KBd              1419
#define IDS_307KBd2             1420
#define IDS_500KBd              1421
#define IDS_614KBd4             1422
#define IDS_800KBd              1423
#define IDS_1000KBd             1424
#define IDS_1288KBd             1425
#define IDS_2457KBd6            1426
#define IDS_100KBd              1427
#define IDS_14KBd4              1428
#define IDS_200KBd              1429  //rh mp85 ssi
#define IDS_47KBd619            1430  //Sr ML71 Scania
#define IDS_33KBd333            1431  //Sr CAN-Baudrate SAAB


/*************************************************************************
* Sprachen
*************************************************************************/
#define IDS_DEUTSCH             1500
#define IDS_ENGLISCH            1501
#define IDS_FRANZOESISCH        1502
#define IDS_ITALIENISCH         1503
#define IDS_SPANISCH            1504


/*************************************************************************
* phys. Einheiten
*************************************************************************/
#define IDS_mV_V                1600
#define IDS_V                   1601
#define IDS_mA                  1602
#define IDS_g                   1603
#define IDS_kg                  1604
#define IDS_T                   1605
#define IDS_kT                  1606
#define IDS_TON                 1607
#define IDS_lb                  1608
#define IDS_oz                  1609
#define IDS_N                   1610
#define IDS_kN                  1611
#define IDS_bar                 1612
#define IDS_mbar                1613
#define IDS_Pa                  1614
#define IDS_Pas                 1615
#define IDS_hPas                1616
#define IDS_kPas                1617
#define IDS_psi                 1618
#define IDS_um                  1619
#define IDS_mm                  1620
#define IDS_cm                  1621
#define IDS_m                   1622
#define IDS_inch                1623
#define IDS_Nm                  1624
#define IDS_kNm                 1625
#define IDS_FTLB                1626
#define IDS_INLB                1627
#define IDS_um_m                1628
#define IDS_m_s                 1629
#define IDS_m_ss                1630
#define IDS_prozent             1631
#define IDS_promille            1632
#define IDS_ppm                 1633
#define IDS_S                   1634
#define IDS_MPas                1635
#define IDS_MN                  1636
#define IDS_NoUnit              1637
#define IDS_Celsius             1638
#define IDS_Fahrenheit          1639
#define IDS_Kelvin              1640
#define IDS_Hz                  1641
#define IDS_kHz                 1642
#define IDS_1_s                 1643
#define IDS_rpm                 1644
#define IDS_U_min               1645
#define IDS_Imp                 1646
#define IDS_kImp                1647
#define IDS_deg                 1648
#define IDS_rad                 1649
#define IDS_rad_s               1650
#define IDS_km_h                1651
#define IDS_mph                 1652
#define IDS_ft_s                1653
#define IDS_inoz                1654
#define IDS_Ncm                 1655
#define IDS_l_h                 1656
#define IDS_l_min               1657
#define IDS_W                   1658
#define IDS_kW                  1659
#define IDS_A                   1660  //MP01
#define IDS_sec                 1661
#define IDS_ozfin               1662  //T12
#define IDS_ozfft               1663  //T12
#define IDS_lbfin               1664  //T12
#define IDS_lbfft               1665  //T12
#define IDS_1_min               1666  //T12
#define IDS_MW                  1667  //T12
#define IDS_min                 1668  //MP85
#define IDS_hp                  1669  //T12
#define IDS_Nmm                 1670  //MP85
/*************************************************************************
 *  Dateifunktionen ML70, ML71
 *************************************************************************/

#define IDS_FopenBin            1700   //Datei öffnen binär
#define IDS_FopenAsc            1701   //Datei öffnen ASCII
#define IDS_NewDB               1720   //Datanbasis anlegen ML71
#define IDS_DelDB               1721   //Datenbasis löschen ML71
#define IDS_NewDB_Parts         1722   //Datenbasis anlegen und häppchenweise über dbe?1 speichern
#define IDS_DB_NAME             1723   //Dateiname der Datenbasis
#define IDS_DB_DATE             1724   //Datum der Datenbasis
#define IDS_DB_COMMENT          1725   //Kommentar zur Datenbasis

/*************************************************************************
 *  Funktionen ML77
 *************************************************************************/

#define IDS_NO_DATA_EX_WITH_ERR 1730   //nicht in Data-Exchange, bei Fehler
#define IDS_DATA_EX_WITH_ERR    1731   //trotz Fehler in Data-Exchange gehen

/*************************************************************************
 *  Interpolationen
 *************************************************************************/
#define IDS_INTERPOLATION       1800
#define IDS_POLINT              1801   // Polynominterpolation
#define IDS_RATINT              1802   // rationale Funktionsinterpolation
#define IDS_SPLINEINT           1803   // Spline Interpolation


/*************************************************************************
 *       ML78 LED-Funktionen                                             *
 *************************************************************************/

#define IDS_LED_NOFKT           1850
#define IDS_LED_OVFL1           1851
#define IDS_LED_OVFL2           1852
#define IDS_LED_OVFL3           1853
#define IDS_LED_OVFL4           1854
#define IDS_LED_OVFL5           1855
#define IDS_LED_OVFL6           1856
#define IDS_LED_OVFL7           1857
#define IDS_LED_OVFL8           1858
#define IDS_LED_OVFL9           1859
#define IDS_LED_OVFL10          1860
#define IDS_LED_INP11           1861
#define IDS_LED_INP12           1862
#define IDS_LED_INP13           1863
#define IDS_LED_INP14           1864
#define IDS_LED_INP15           1865
#define IDS_LED_INP16           1866
#define IDS_LED_INP17           1867
#define IDS_LED_INP18           1868
#define IDS_LED_INP21           1871
#define IDS_LED_INP22           1872
#define IDS_LED_INP23           1873
#define IDS_LED_INP24           1874
#define IDS_LED_INP25           1875
#define IDS_LED_INP26           1876
#define IDS_LED_INP27           1877
#define IDS_LED_INP28           1878
#define IDS_LED_OUTP11          1881
#define IDS_LED_OUTP12          1882
#define IDS_LED_OUTP13          1883
#define IDS_LED_OUTP14          1884
#define IDS_LED_OUTP15          1885
#define IDS_LED_OUTP16          1886
#define IDS_LED_OUTP17          1887
#define IDS_LED_OUTP18          1888
#define IDS_LED_OUTP21          1891
#define IDS_LED_OUTP22          1892
#define IDS_LED_OUTP23          1893
#define IDS_LED_OUTP24          1894
#define IDS_LED_OUTP25          1895
#define IDS_LED_OUTP26          1896
#define IDS_LED_OUTP27          1897
#define IDS_LED_OUTP28          1898
#define IDS_RED                 1900
#define IDS_YELLOW              1901

/*************************************************************************
 *       ML78 OSP-Funktionen                                             *
 *************************************************************************/

#define IDS_ANASRC_NULL         1908     // ML78: Signal Null
#define IDS_ANASRC_EXT          1909     // ML78: Signal von ext. Schnittstellenbefehl
#define IDS_ANASRC_CHAN         1910     // ML78: Signal von MGC-Kanal
#define IDS_ANASRC_FUNC1        1911     // ML78: Signal von Funktionsgenerator1
#define IDS_ANASRC_FUNC2        1912    // ML78: Signal von Funktionsgenerator1
#define IDS_ANASRC_FUNC3        1913     // ML78: Signal von Funktionsgenerator1
#define IDS_ANASRC_FUNC4        1914     // ML78: Signal von Funktionsgenerator1
#define IDS_ANASRC_FUNC5        1915     // ML78: Signal von Funktionsgenerator1
#define IDS_ANASRC_FUNC6        1916     // ML78: Signal von Funktionsgenerator1
#define IDS_ANASRC_FUNC7        1917     // ML78: Signal von Funktionsgenerator1
#define IDS_ANASRC_FUNC8        1918     // ML78: Signal von Funktionsgenerator1
#define IDS_ANASRC_FUNC9        1919     // ML78: Signal von Funktionsgenerator1
#define IDS_ANASRC_FUNC10       1920     // ML78: Signal von Funktionsgenerator1


/*************************************************************************
 *       ML78 Eingangs-Funktionen                                        *
 *************************************************************************/

#define IDS_LOG_HIGH_AKTIV      1930
#define IDS_LOG_LOW_AKTIV       1931
#define IDS_VER_UND             1932
#define IDS_VER_ODER            1933
#define IDS_OUTFCT_LOGOP        1940
#define IDS_OUTFCT_HSHAKE       1941
#define IDS_OUTFCT_EXT          1942
#define IDS_OUTFCT_SIGNAL       1943
#define IDS_LEVEL_HIGH          1944
#define IDS_LEVEL_LOW           1945

/*************************************************************************
 *       ML78 Funktion Eingang                                           *
 *************************************************************************/

#define IDS_F_SYNC1             1951
#define IDS_F_SYNC2             1952
#define IDS_F_SYNC3             1953
#define IDS_F_SYNC4             1954
#define IDS_F_SYNC5             1955
#define IDS_F_SYNC6             1956
#define IDS_F_SYNC7             1957
#define IDS_F_SYNC8             1958
#define IDS_F_SYNC9             1959
#define IDS_F_SYNC10            1960

/*************************************************************************
 *       ML71Send CAN-Formate                                            *
 *************************************************************************/
#define IDS_CANFMT_FLOAT        1970
#define IDS_CANFMT_INT32        1971
#define IDS_CANFMT_INT16        1972
#define IDS_CANFMT_UNSCAL       1973

/*************************************************************************
 *       MP85 Press Fit Specifics  reserved from 2000-2099               *
 *************************************************************************/
//out
#define IDS_PRESS_BUSY          2000
#define IDS_PRESS_ALARM         2001
#define IDS_PRESS_OK            2002
#define IDS_PRESS_NOK           2003
#define IDS_PRESS_STARTED       2004
#define IDS_PRESS_RUNNING       2005
#define IDS_PRESS_READY         2006
#define IDS_PRESS_RESULTPROCESSED 2007
#define IDS_MMCNEARLYFULL       2008

#define IDS_TOLWIN1_OK          2011
#define IDS_TOLWIN2_OK          2012
#define IDS_TOLWIN3_OK          2013
#define IDS_TOLWIN4_OK          2014
#define IDS_TOLWIN5_OK          2015
#define IDS_TOLWIN6_OK          2016
#define IDS_TOLWIN7_OK          2017
#define IDS_TOLWIN8_OK          2018
#define IDS_TOLWIN9_OK          2019

//in
#define IDS_PRESS_START         2020
#define IDS_SENSORCHECK         2021

#define IDS_WINEVAL             2040
#define IDS_TOLERANCEBANDEVAL   2041
#define IDS_X_Y                 2042
#define IDS_X_T                 2043
#define IDS_Y_T                 2044

/*************************************************************************
 *       T12 Specifics  reserved from 2100-2199                          *
 *************************************************************************/
#define IDS_AVERAGEOVER1TURN    2110
#define IDS_AVERAGEOVER2TURN    2111
#define IDS_SHUNTCALVAL_10_PERCENT 2120
#define IDS_SHUNTCALVAL_50_PERCENT 2121
#define IDS_ZEROIX_INTERN       2122
#define IDS_ZEROIX_EXTERN       2123
#define IDS_LEDMODE_NORMAL      2130
#define IDS_LEDMODE_ADJUST      2131

/*************************************************************************
 *       TEDS Temnplates from 2200-2299                                  *
 *************************************************************************/
#define IDS_TEDSTMPL_BRIDGESENSOR             2201
#define IDS_TEDSTMPL_STRAINGAGE               2202
#define IDS_TEDSTMPL_FREQPULSE                2203
#define IDS_TEDSTMPL_HIGHLEVELVOLTAGEOUTPUT   2204

/*************************************************************************
* AID, AMT Meßverstärkertypen
*************************************************************************/
#define IDS_ML30                5000
#define IDS_ML50                5001
#define IDS_ML01                5002
#define IDS_ML55                5003
#define IDS_ML60                5004
#define IDS_ML35                5005
#define IDS_ML10                5006
#define IDS_ML51                5007
#define IDS_ML55S6              5008
#define IDS_ML38                5009
#define IDS_ML85_3              5010
#define IDS_ML85_1              5011
#define IDS_ML70                5012    //Sr
#define IDS_ML71                5013    //Sr
#define IDS_ML77                5014    //Sr
#define IDS_ML801               5015    //Ki Ml801 und ML801B
#define IDS_ML78                5016    //Ge
#define IDS_ML71S6              5017    //Mu
#define IDS_ML460               5018    //Mu
#define IDS_ML74                5019    //Mu
#define IDS_ML455               5020    //Ki ML455
#define IDS_ML855               5021    //Ki ML855

#define IDS_S8isno              5050
#define IDS_S8TFmF              5051
#define IDS_S8TFoF              5052
#define IDS_S8SR55              5053
#define IDS_S8SR01              5054
#define IDS_S8DigIO             5055
#define IDS_S8HChan             5056

#define IDS_T12                 5060
#define IDS_T12DP               5061

#define IDS_MPxx                5070
#define IDS_MP55                5071
#define IDS_MP01                5072
#define IDS_MP60                5073
#define IDS_MP55DP              5074
#define IDS_MP60DP              5075
#define IDS_MP09                5076
#define IDS_MP70DP              5077 //rh
#define IDS_MP70                5078 //rh
#define IDS_MP30                5079 //Sr
#define IDS_MP30DP              5080 //Sr
#define IDS_MP55IS              5081 //rh
#define IDS_MP30IS              5082 //rh
#define IDS_MP60IS              5083 //rh
#define IDS_MP85                5084 //rh
#define IDS_MP85DP              5085 //rh
#define IDS_MP80                5086 //rh
#define IDS_MP80DP              5087 //rh

//############# CanHead-Typen ##########
#define IDS_CANHEAD             5100              // CanHead
#define IDS_CA1030              5101              // pb MC16c6N
#define IDS_CB1014              5102              // pb	single strain gage 3L
#define IDS_CB1015              5103              // pb	single strain gage 4L
#define IDS_CB1010              5104              // pb	Halb- / Vollbrücke / DC 10V

/*                                                // Die folgenden nicht mehr benutzen
#define IDS_CHD_MC001           5101              // MC16c6N
#define IDS_CHD_SSG             5102              // Mu	single strain gage
#define IDS_CHD_SSG_3L          5102              // pb	single strain gage 3L
#define IDS_CHD_SSG_4L          5103              // pb	single strain gage 4L
#define IDS_CHD_BR              5104              // pb	Halb-/Vollbrücke/DC
*/
#define IDS_DF30                5150    //we. DigiClip

/*************************************************************************
* Anschlussplattentyp
*************************************************************************/
#define IDS_AP01                5500
#define IDS_AP0506              5501
#define IDS_AP08                5502
#define IDS_AP14                5503
#define IDS_AP18                5504
#define IDS_AP09                5505
#define IDS_AP801               5506
#define IDS_AP809               5507
#define IDS_AP835               5508
#define IDS_AP409               5509
#define IDS_AP4092              5510
#define IDS_AP810               5511
#define IDS_AP814               5512
#define IDS_AP71                5513
#define IDS_AP72                5514
#define IDS_AP75                5515
#define IDS_AP77                5516
#define IDS_AP78                5517
#define IDS_AP815               5518
#define IDS_AP401               5519
#define IDS_AP4012              5520
#define IDS_AP836               5521
#define IDS_AP460               5522    //Mu
#define IDS_AP801S6             5523
#define IDS_AP814Ent            5524    //Ki AP814entwicklung only
#define IDS_AP814B              5525    //Ki AP814neu ~ AP815
#define IDS_AP801S41            5526    //Ki AP801 mit 0.1V
#define IDS_AP418               5527    //Ki AP418: Piezos
#define IDS_AP4182              5528    //Ki 2xAP418: Piezos
#define IDS_AP17                5529
#define IDS_AP01i               5530    //uk AP01 mit ident
#define IDS_AP03i               5531    //uk AP03 mit ident
#define IDS_AP11i               5532    //uk AP11 mit ident
#define IDS_AP74                5533    //Mu
#define IDS_AP18i               5535    //uk AP18 mit ident
#define IDS_AP13i               5536    //uk AP13 mit ident
#define IDS_AP401S41            5537    //Ki AP401 mit x.x V
#define IDS_AP455               5538    //Ki AP455: 4 x TF
#define IDS_AP402               5539    //Ki AP402: universal in
#define IDS_AP403R              5540    //Ki AP403: future
#define IDS_AP836i              5541    //Ki intern; cbt -> AP836
#define IDS_AP_DATATEL          5549    //uk datatel telemetry
#define IDS_APTEST              5550
#define IDS_APEINMESS           5551
#define IDS_APWRONG             5555


/*************************************************************************
* DTR, TRE Triggermodi
*************************************************************************/
#define IDS_MGETr               6000
#define IDS_MLETr               6001
#define IDS_pEdge               6002
#define IDS_nEdge               6003
#define IDS_pStatic             6004
#define IDS_nStatic             6005
#define IDS_MV_LEV              6006
#define IDS_MV_WIN              6007
#define IDS_MV_GW1              6008
#define IDS_MV_GW2              6009
#define IDS_MV_GW3              6010
#define IDS_MV_GW4              6011
#define IDS_MV_TIME             6012

/*************************************************************************
* MSV Meßmodi
*************************************************************************/
#define IDS_sofort              6100
#define IDS_TRG                 6101
#define IDS_ExtTr               6102
#define IDS_IntTr               6103


/*************************************************************************
* ACT Kanal aktivieren
*************************************************************************/
#define IDS_Pass                6200
#define IDS_MeAkt               6201
#define IDS_NuAkt               6202
#define IDS_MeUNu               6203
#define IDS_MesAnz              6210
#define IDS_TarAnz              6211


/*************************************************************************
* ICR Meßraten
*************************************************************************/
#define IDS_M1Hz                6300
#define IDS_M2Hz                6301
#define IDS_M5Hz                6302
#define IDS_M10Hz               6303
#define IDS_M25Hz               6304
#define IDS_M50Hz               6305
#define IDS_M60Hz               6306
#define IDS_M75Hz               6307
#define IDS_M100Hz              6308
#define IDS_M150Hz              6309
#define IDS_M200Hz              6310
#define IDS_M300Hz              6311
#define IDS_M400Hz              6312
#define IDS_M600Hz              6313
#define IDS_M800Hz              6314
#define IDS_M1KHz2              6315
#define IDS_M1KHz6              6316
#define IDS_M2KHz4              6317
#define IDS_M3KHz2              6318
#define IDS_M4KHz8              6319
#define IDS_M9KHz6              6320
#define IDS_M3Hz                6321
#define IDS_M4Hz                6322
#define IDS_M6Hz                6323
#define IDS_M8Hz                6324
#define IDS_M15Hz               6325
#define IDS_M20Hz               6326
#define IDS_M30Hz               6327
#define IDS_M48Hz               6328
#define IDS_M64Hz               6329
#define IDS_M80Hz               6330
#define IDS_M96Hz               6331
#define IDS_M120Hz              6332
#define IDS_M160Hz              6333
#define IDS_M192Hz              6334
#define IDS_M240Hz              6335
#define IDS_M320Hz              6336
#define IDS_M384Hz              6337
#define IDS_M480Hz              6338
#define IDS_M640Hz              6339
#define IDS_M960Hz              6340
#define IDS_M1920Hz             6341
#define IDS_M19KHz2             6345    // AG
#define IDS_M38KHz4             6346    // AG
#define IDS_M76KHz8             6347    // AG
#define IDS_M37Hz5              6348    // AG / KI
#define IDS_M18Hz75             6349    // AG / KI
#define IDS_M2s                 6350
#define IDS_M5s                 6351
#define IDS_M10s                6352
#define IDS_M20s                6353
#define IDS_M50s                6354
#define IDS_M100s               6355
#define IDS_M200s               6356
#define IDS_M500s               6357
#define IDS_M1Ks                6358
#define IDS_M2Ks                6359
#define IDS_M5Ks                6360
#define IDS_M10Ks               6361


/*************************************************************************
* OMP Lesezeigerpositionierung
*************************************************************************/
#define IDS_BGN_BUF             6400
#define IDS_STRT_MEA            6401
#define IDS_STRT_nMEA           6402
#define IDS_STRT_nMEA_FREE      6403
#define IDS_TRIG_PNT            6404
#define IDS_END_MEA             6405
#define IDS_ACT_POS             6406
#define IDS_ACT_POS_FREE        6407
#define IDS_ACT_WRT             6408
#define IDS_ACT_POS_iFREE       6409


/*************************************************************************
* TRD Triggertyp
*************************************************************************/
#define IDS_STRT_TRIG           6500
#define IDS_STP_TRIG            6501
#define IDS_MR_TRIG             6502

/*************************************************************************
* Parametersätze
*************************************************************************/
#define IDS_WERKSEINST          6600
#define IDS_PARASATZ1           6601
#define IDS_PARASATZ2           6602
#define IDS_PARASATZ3           6603
#define IDS_PARASATZ4           6604
#define IDS_LADEN               6609
#define IDS_SPEICHERN           6610
#define IDS_FLUECHTIG           6611

//Storage Destination MP8x
#define IDS_STORE_FLASH         6620
#define IDS_STORE_MMC           6621
#define IDS_STORE_CAN           6622
#define IDS_STORE_DP            6623

#define IDS_NO_FILES            6640
#define IDS_ALL_FILES           6641
#define IDS_NOK_FILES           6642
#define IDS_OK_FILES            6643

#define IDS_10_FILES            6644
#define IDS_20_FILES            6645
#define IDS_50_FILES            6646

#define IDS_EXCEL               6660
#define IDS_QDAS                6661

#define IDS_NO_DATA_LOSS        6665
#define IDS_PROCESSOPTIMIZED    6666

#define IDS_HWSYNC_MASTER       6700
#define IDS_HWSYNC_SLAVE        6701

#define IDS_TRG_SWITCH          6710
#define IDS_TRG_MASTER          6711
#define IDS_TRG_SLAVE           6712
#define IDS_TRG_STANDALONE      6713

/****************************
* Mathematische Verküpfungen
****************************/
#define IDS_ADD                 6800
#define IDS_AVERAGING           6801
#define IDS_MULTIPLY            6802

/*************************************************************************
* FOM Fifo Operation Mode (Fifo Aufzeichnungsmodi)
*************************************************************************/
#define IDS_TRIG_NOOWR          6900    // getriggerte Aufzeichnung, kein Überschreiben
#define IDS_TRIG_OWR            6901    // getriggerte Aufzeichnung, Überschreiben der ältesten Daten
#define IDS_CONT_NOOWR          6904    // kontinuierl. Aufz. kein Überschr.
#define IDS_CONT_OWR            6905    // kontinuierl. Aufz. Überschr. der ältesten Daten

/*************************************************************************
* TCS Zeitkanal Formate
*************************************************************************/
#define IDS_TIME_OFF            0       // kein Zeitkanal
#define IDS_TIME_HBM_64         7000    // proprietärer HBM Zeitkanal (64 Bit)
#define IDS_TIME_HBM_32         7001    // proprietärer HBM Zeitkanal (32 Bit)
#define IDS_TIME_NTP            7002    // 64 Bit NTP Zeitkanal
#define IDS_TIME_USB            7003    // 16 bzw. 32 Bit USB Framecounter
#define IDS_TIME_IRIG           7004    // 64 Bit IRIG time channel (special ML01)

/************************************************************************
* alles wegen CAN
*************************************************************************/

#define IDS_DS401               7401
#define IDS_DS404               7404
#define IDS_OPERATIONAL         7420
#define IDS_PREOPERATIONAL      7421
#define IDS_SYNC_EVENT_DRIVEN   7430
#define IDS_SYNC_RTR            7431
#define IDS_SYNC_COMMANDED      7432

/*************************************************************************
* PME   Allgemeines
*************************************************************************/
#define IDS_SLOW                7601
#define IDS_MED                 7602
#define IDS_FAST                7603

/*************************************************************************
* Typen Anzeigeelemente
*************************************************************************/

//
//  Typen Dialog
//
#define IDS_NORMAL              8000
#define IDS_MODAL               8005



/************************************************************************
* Druckersprache
*************************************************************************/

#define IDS_LPR_PCL             9000    // PCL (HP)
#define IDS_LPR_EscP            9001    // Esc/P (Epson)
#define IDS_LPR_PDL             9002    // PDL (Canon)
#define IDS_LPR_XML             9003    // XML

/************************************************************************
* Druckersteuerung
*************************************************************************/

#define IDS_LPR_FF              9050    // Seitenvorschub
#define IDS_LPR_ML85B           9070    // ML85B wants to print the pressdata uk



/*******************************************************
* DMS Temperatur-Kompensation   CAN-Head
*******************************************************/
#define IDS_TCMP_DMS           9200  //Temperaturkompensation über Vergleichs-DMS
#define IDS_TCMP_POLY		   9201	 //Temperaturkompensation über Polynom




/************************************************************************
* EST Fehlernummern
*************************************************************************/
#define IDS_NoErr           0 /* -------------------------- kein Fehler */
#define IDS_Err_Reset   10000 /* -------------- Spider im Reset-Zustand */
#define IDS_Err_Trans   10001 /* -------- Übertragungsfehler, Parity... */
#define IDS_Err_SysFail 10002 /* ------------------------- Systemfehler */
#define IDS_Err_UnknIn  10003 /* ------------------- unbekannter Befehl */
#define IDS_Err_WrParms 10004 /* ---------------- falsche Parameterzahl */
#define IDS_Err_ParOutL 10005 /* --------------- falscher Parameterwert */
#define IDS_Err_fgNIO   10006 /* ---------- Fehler wegen Filterfrequenz */
#define IDS_Err_AmpOvr  10007 /* ------------- Verstärkerübertsteuerung */
#define IDS_Err_InsNIO  10008 /* -------------- Befehl nicht ausführbar */
#define IDS_Err_OMB     10009 /* ----------------------- Fehler bei OMB */
#define IDS_Err_ChanSel 10010 /* ---------------- Fehlerhafte Kanalwahl */
#define IDS_Err_Measure 10011 /* ------------------- Fehler beim Messen */
#define IDS_Err_Trig    10012 /* ----------------- Fehler beim Triggern */
#define IDS_Err_MeasRng 10013 /* --------------- Fehler beim Meßbereich */
#define IDS_Err_Tar     10014 /* ----------------- Fehler beim Tarieren */

#define IDS_Err_Flashup 10020 /* -------------- Spider im Flash-Zustand */
#define IDS_Err_fgNFI   10021 /* --------- Warnung wegen Filterfrequenz */
#define IDS_Err_TarNS   10022 /* ------------- Warnung wegen Tarastatus */


#define IDS_Ur1_Err         15001 // UrcalFehler 1
#define IDS_Ur2_Err         15002 // UrcalFehler 2
#define IDS_Ur3_Err         15003 // UrcalFehler 3
#define IDS_Ur4_Err         15004 // UrcalFehler 4
#define IDS_Ur5_Err         15005 // UrcalFehler 5
#define IDS_Ur6_Err         15006 // UrcalFehler 6
#define IDS_Ur7_Err         15007 // UrcalFehler 6
#define IDS_Ap_Wrong_Err    15010 // AP paßt nicht zu Amp
#define IDS_Ap_Err          15011 // Parameter passen nicht zu AP
#define IDS_Param_Err       15012 // Nach Einschalten Setup erforderlich
#define IDS_Transducer_Err  15015 // Kalibrierfehler, kein Aufnehmer
#define IDS_Kalibr_Err      15020 // Fehler in den Kalibriergeraden
#define IDS_ML10_Anlog_Err  15021 // Fehler in den Kalibriergeraden
#define IDS_TID_ACTIV_ERR   15022 // TID or TED activ, no measure possible
#define IDS_TEDS_ERR        15023 // TED settings not valid
#define IDS_HW_Overflow     15030
#define IDS_HW_Underflow    15031
#define IDS_Lin_Overflow    15035 // Linearisierung Overflow
#define IDS_Brutto_Overflow 15040
#define IDS_Netto_Overflow  15041
#define IDS_HZR_Sync_Err    15050 // keine Link möglich
#define IDS_More_Errors     15100 // weiter Fehler
#define IDS_ML77_ERR        15101 // zu dieser Fehlermeldung muß der Text
                                  // mit IDS? abgefragt werden!
#define IDS_ML71_ERR        15102 //

#define IDS_ML74_ERR        15103
#define IDS_ML78_SRCERR     15104 //Erroneous Source Signal

#define IDS_ERROR_0         15110 //ab hier bis 155200 für Fehlerlisten reserviert
#define IDS_ERROR_1         15111
#define IDS_ERROR_2         15112
#define IDS_ERROR_3         15113
#define IDS_ERROR_4         15114
#define IDS_ERROR_5         15115
#define IDS_ERROR_6         15116
#define IDS_ERROR_7         15117
#define IDS_ERROR_8         15118
#define IDS_ERROR_9         15119
#define IDS_ERROR_10        15120
#define IDS_ERROR_11        15121
#define IDS_ERROR_40        15150
#define IDS_ERROR_60        15170
#define IDS_ERROR_90        15200

#define IDS_CP32_ERR        16000 // Fehler in CP32
#define IDS_LINKRQST_ERR    16001 // angeforterte Linkdaten nicht verfügbar
#define IDS_TOOMUCHCHN_ERR  16002 // zu viele logische Kanäle im System
#define IDS_HDFULL_ERR      16003 // Festplatte ist voll
#define IDS_FALSEHD_ERR     16004 // falsche Festplatte im System
#define IDS_FAILRDCNF_ERR   16005 // autom. Kanalparametrierung fehlgeschlagen
#define IDS_RESNOTAVAIL_ERR 16006 // Resourcen sind nicht verfügbar
#define IDS_MEMOVL_ERR      16007 // FIFO Überlauf Messung gestoppt
#define IDS_WRONGSLOT_ERR   16008 // Slot 1-8 sind nicht belegt (bei CP32B keine messung möglich)
#define IDS_ROPEN_ERR       16009 // Fehler beim Öffnen einer Datei
#define IDS_ASYNCSYNCSLOT_ERR   16010 // Asynchron/Synchron zu wandelnde Kanäle müssen aus Performancegründen nebeneinander stecken
#define IDS_ASYNCSYNCMRG_ERR    16011 // Asynchron/Synchron zu wandelnde Kanäle dürfen aus Performancegründen nur in einer Messratengruppe (die erste) erfasst werden

#define IDS_PLL_ERR         16015 // Pll CP unlocked
#define IDS_SLAVEUNSYNC_ERR 16016 // Slave with no external sync
#define IDS_MOD75_ERR       16017 // Tick not in time or no tick
#define IDS_LINKSLOT_ERR    16018 // Sync with amplifiers broken
#define IDS_RECALL_ERR      16019 // Data in EEPROM or EEPROM malade
#define IDS_RSRD_ERR        16020 // interface rs232 to amplifiers down
#define IDS_RSAB_ERR        16021 // interface rs232 to AB down
#define IDS_RS232_ERR       16022 // interface rs232 down
#define IDS_RSDEBUG_ERR     16023 // interface debug rs232 down
#define IDS_USBDEV_ERR      16024 // interface usbdevice down
#define IDS_ETHERNET_ERR    16025 // interface ethernet down


#define IDS_TEMPL_AMP_INCOMPATIBLE          17000
#define IDS_TEMPL_ABOVELIMIT                17002
#define IDS_TEMPL_BELOWLIMIT                17003
#define IDS_TEMPL_OUTOFLIMIT                17004
#define IDS_TEMPL_NOTPOSSIBLE               17005
#define IDS_TEMPL_VALUECHANGED              17100
#define IDS_TEMPL_NOT_1451_CONFORM          17101

/************************************************************************
* EST Warnungen
*************************************************************************/

#define IDS_Change_Warn          20000   // Change
#define IDS_CDV_Warn             20010   // cdv erfolglos
#define IDS_TAR_Warn             20011   // tar erfolglos
#define IDS_UA1_Overflow_Warn    20020   //
#define IDS_UA2_Overflow_Warn    20021   //
#define IDS_ML71_ErrWarn1        20023
#define IDS_ML71_ErrWarn2        20024
#define IDS_ML71_WarnErrCnt1     20025
#define IDS_ML71_WarnErrCnt2     20026
#define IDS_ML71_WarnDB1         20027
#define IDS_ML71_WarnDB2         20028
#define IDS_UaKalibr_Warn        20030  // Fehler in den Kalibriergeraden Analogausgang P5.24
#define IDS_TEDS_WARNING         20031  // TED settings adapted
#define IDS_TEDS_READ_Warn       20032  // TEDS read corrupt, reseted

#define IDS_CP32_WARN            21000   // CP32 Warnung
#define IDS_NOHD_WARN            21001   // keine Festplatte im System
#define IDS_TOOMDATA_WARN        21002   // zu viele daten für Echtzeitverarbeitung
#define IDS_NOHZR_WARN           21003   // keine HZR Synchronisation möglich
#define IDS_NOAVERAGE_WARN       21004   // die Mittelwertbildung musste abgeschaltet werden


#define IDS_WILDCARD             0xFFFF	 //SM

#endif //_IDSDEF_H
