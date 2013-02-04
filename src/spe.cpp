// This file is part of libspe, a C++ library to interface with spe files.
// Copyright (c) 2012 Karthik Periagaram <karthik.periagaram@gmail.com>
//
// libspe is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// libspe is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with libspe.  If not, see <http://www.gnu.org/licenses/>.

#include "spe.h"
#include "../spe.h"

// Byte offsets for header elements
const unsigned short OFFSET_CONTROLLERVERSION     = 0x0000;
const unsigned short OFFSET_LOGICOUTPUT           = 0x0002;
const unsigned short OFFSET_AMPHICAPLOWNOISE      = 0x0004;
const unsigned short OFFSET_XDIMDET               = 0x0006;
const unsigned short OFFSET_MODE                  = 0x0008;
const unsigned short OFFSET_EXP_SEC               = 0x000A;
const unsigned short OFFSET_VCHIPXDIM             = 0x000E;
const unsigned short OFFSET_VCHIPYDIM             = 0x0010;
const unsigned short OFFSET_YDIMDET               = 0x0012;
const unsigned short OFFSET_DATE                  = 0x0014;
const unsigned short OFFSET_VIRTUALCHIPFLAG       = 0x001E;
//const unsigned short OFFSET_SPARE_1               = 0x0020;
const unsigned short OFFSET_NOSCAN                = 0x0022;
const unsigned short OFFSET_DETTEMPERATURE        = 0x0024;
const unsigned short OFFSET_DETTYPE               = 0x0028;
const unsigned short OFFSET_XDIM                  = 0x002A;
const unsigned short OFFSET_STDIODE               = 0x002C;
const unsigned short OFFSET_DELAYTIME             = 0x002E;
const unsigned short OFFSET_SHUTTERCONTROL        = 0x0032;
const unsigned short OFFSET_ABSORBLIVE            = 0x0034;
const unsigned short OFFSET_ABSORBMODE            = 0x0036;
const unsigned short OFFSET_CANDOVIRTUALCHIPFLAG  = 0x0038;
const unsigned short OFFSET_THRESHOLDMINLIVE      = 0x003A;
const unsigned short OFFSET_THRESHOLDMINVAL       = 0x003C;
const unsigned short OFFSET_THRESHOLDMAXLIVE      = 0x0040;
const unsigned short OFFSET_THRESHOLDMAXVAL       = 0x0042;
const unsigned short OFFSET_SPECAUTOSPECTROMODE   = 0x0046;
const unsigned short OFFSET_SPECCENTERWLNM        = 0x0048;
const unsigned short OFFSET_SPECGLUEFLAG          = 0x004C;
const unsigned short OFFSET_SPECGLUESTARTWLNM     = 0x004E;
const unsigned short OFFSET_SPECGLUEENDWLNM       = 0x0052;
const unsigned short OFFSET_SPECGLUEMINOVRLPNM    = 0x0056;
const unsigned short OFFSET_SPECGLUEFINALRESNM    = 0x005A;
const unsigned short OFFSET_PULSERTYPE            = 0x005E;
const unsigned short OFFSET_CUSTOMCHIPFLAG        = 0x0060;
const unsigned short OFFSET_XPREPIXELS            = 0x0062;
const unsigned short OFFSET_XPOSTPIXELS           = 0x0064;
const unsigned short OFFSET_YPREPIXELS            = 0x0066;
const unsigned short OFFSET_YPOSTPIXELS           = 0x0068;
const unsigned short OFFSET_ASYNEN                = 0x006A;
const unsigned short OFFSET_DATATYPE              = 0x006C;
const unsigned short OFFSET_PULSERMODE            = 0x006E;
const unsigned short OFFSET_PULSERONCHIPACCUMS    = 0x0070;
const unsigned short OFFSET_PULSEREPEATEXP        = 0x0072;
const unsigned short OFFSET_PULSEREPWIDTH         = 0x0076;
const unsigned short OFFSET_PULSEREPDELAY         = 0x007A;
const unsigned short OFFSET_PULSESEQSTARTWIDTH    = 0x007E;
const unsigned short OFFSET_PULSESEQENDWIDTH      = 0x0082;
const unsigned short OFFSET_PULSESEQSTARTDELAY    = 0x0086;
const unsigned short OFFSET_PULSESEQENDDELAY      = 0x008A;
const unsigned short OFFSET_PULSESEQINCMODE       = 0x008E;
const unsigned short OFFSET_PIMAXUSED             = 0x0090;
const unsigned short OFFSET_PIMAXMODE             = 0x0092;
const unsigned short OFFSET_PIMAXGAIN             = 0x0094;
const unsigned short OFFSET_BACKGRNDAPPLIED       = 0x0096;
const unsigned short OFFSET_PIMAX2NSBRDUSED       = 0x0098;
const unsigned short OFFSET_MINBLK                = 0x009A;
const unsigned short OFFSET_NUMMINBLK             = 0x009C;
const unsigned short OFFSET_SPECMIRRORLOCATION    = 0x009E;
const unsigned short OFFSET_SPECSLITLOCATION      = 0x00A2;
const unsigned short OFFSET_CUSTOMTIMINGFLAG      = 0x00AA;
const unsigned short OFFSET_EXPERIMENTTIMELOCAL   = 0x00AC;
const unsigned short OFFSET_EXPERIMENTTIMEUTC     = 0x00B3;
const unsigned short OFFSET_EXPOSUNITS            = 0x00BA;
const unsigned short OFFSET_ADCOFFSET             = 0x00BC;
const unsigned short OFFSET_ADCRATE               = 0x00BE;
const unsigned short OFFSET_ADCTYPE               = 0x00C0;
const unsigned short OFFSET_ADCRESOLUTION         = 0x00C2;
const unsigned short OFFSET_ADCBITADJUST          = 0x00C4;
const unsigned short OFFSET_GAIN                  = 0x00C6;
const unsigned short OFFSET_COMMENTS              = 0x00C8;
const unsigned short OFFSET_GEOMETRIC             = 0x0258;
const unsigned short OFFSET_XLABEL                = 0x025A;
const unsigned short OFFSET_CLEANS                = 0x026A;
const unsigned short OFFSET_NUMSKPPERCLN          = 0x026C;
const unsigned short OFFSET_SPECMIRRORPOS         = 0x026E;
const unsigned short OFFSET_SPECSLITPOS           = 0x0272;
const unsigned short OFFSET_AUTOCLEANSACTIVE      = 0x0282;
const unsigned short OFFSET_USECONTCLEANSINST     = 0x0284;
const unsigned short OFFSET_ABSORBSTRIPNUM        = 0x0286;
const unsigned short OFFSET_SPECSLITPOSUNITS      = 0x0288;
const unsigned short OFFSET_SPECGROOVES           = 0x028A;
const unsigned short OFFSET_SRCCMP                = 0x028E;
const unsigned short OFFSET_YDIM                  = 0x0290;
const unsigned short OFFSET_SCRAMBLE              = 0x0292;
const unsigned short OFFSET_CONTINUOUSCLEANSFLAG  = 0x0294;
const unsigned short OFFSET_EXTERNALTRIGGERFLAG   = 0x0296;
const unsigned short OFFSET_LNOSCAN               = 0x0298;
const unsigned short OFFSET_LAVGEXP               = 0x029C;
const unsigned short OFFSET_READOUTTIME           = 0x02A0;
const unsigned short OFFSET_TRIGGEREDMODEFLAG     = 0x02A4;
//const unsigned short OFFSET_SPARE_2               = 0x02A6;
const unsigned short OFFSET_SW_VERSION            = 0x02B0;
const unsigned short OFFSET_TYPE                  = 0x02C0;
const unsigned short OFFSET_FLATFIELDAPPLIED      = 0x02C2;
//const unsigned short OFFSET_SPARE_3               = 0x02C4;
const unsigned short OFFSET_KIN_TRIG_MODE         = 0x02D4;
const unsigned short OFFSET_DLABEL                = 0x02D6;
//const unsigned short OFFSET_SPARE_4               = 0x02E6;
const unsigned short OFFSET_PULSEFILENAME         = 0x049A;
const unsigned short OFFSET_ABSORBFILENAME        = 0x0512;
const unsigned short OFFSET_NUMEXPREPEATS         = 0x058A;
const unsigned short OFFSET_NUMEXPACCUMS          = 0x058E;
const unsigned short OFFSET_YT_FLAG               = 0x0592;
const unsigned short OFFSET_CLKSPD_US             = 0x0594;
const unsigned short OFFSET_HWACCUMFLAG           = 0x0598;
const unsigned short OFFSET_STORESYNC             = 0x059A;
const unsigned short OFFSET_BLEMISHAPPLIED        = 0x059C;
const unsigned short OFFSET_COSMICAPPLIED         = 0x059E;
const unsigned short OFFSET_COSMICTYPE            = 0x05A0;
const unsigned short OFFSET_COSMICTHRESHOLD       = 0x05A2;
const unsigned short OFFSET_NUMFRAMES             = 0x05A6;
const unsigned short OFFSET_MAXINTENSITY          = 0x05AA;
const unsigned short OFFSET_MININTENSITY          = 0x05AE;
const unsigned short OFFSET_YLABEL                = 0x05B2;
const unsigned short OFFSET_SHUTTERTYPE           = 0x05C2;
const unsigned short OFFSET_SHUTTERCOMP           = 0x05C4;
const unsigned short OFFSET_READOUTMODE           = 0x05C8;
const unsigned short OFFSET_WINDOWSIZE            = 0x05CA;
const unsigned short OFFSET_CLKSPD                = 0x05CC;
const unsigned short OFFSET_INTERFACE_TYPE        = 0x05CE;
const unsigned short OFFSET_NUMROISINEXPERIMENT   = 0x05D0;
//const unsigned short OFFSET_SPARE_5               = 0x05D2;
const unsigned short OFFSET_CONTROLLERNUM         = 0x05E2;
const unsigned short OFFSET_SWMADE                = 0x05E4;
const unsigned short OFFSET_NUMROI                = 0x05E6;
const unsigned short OFFSET_ROIINFOBLK_1          = 0x05E8;
const unsigned short OFFSET_ROIINFOBLK_2          = 0x05F4;
const unsigned short OFFSET_ROIINFOBLK_3          = 0x0600;
const unsigned short OFFSET_ROIINFOBLK_4          = 0x060C;
const unsigned short OFFSET_ROIINFOBLK_5          = 0x0618;
const unsigned short OFFSET_ROIINFOBLK_6          = 0x0624;
const unsigned short OFFSET_ROIINFOBLK_7          = 0x0630;
const unsigned short OFFSET_ROIINFOBLK_8          = 0x063C;
const unsigned short OFFSET_ROIINFOBLK_9          = 0x0648;
const unsigned short OFFSET_ROIINFOBLK_10         = 0x0654;
const unsigned short OFFSET_FLATFIELD             = 0x0660;
const unsigned short OFFSET_BACKGROUND            = 0x06D8;
const unsigned short OFFSET_BLEMISH               = 0x0750;
const unsigned short OFFSET_FILE_HEADER_VER       = 0x07C8;
const unsigned short OFFSET_YT_INFO               = 0x07CC;
const unsigned short OFFSET_WINVIEW_ID            = 0x0BB4;
const unsigned short OFFSET_XCALIBRATION          = 0x0BB8;
const unsigned short OFFSET_YCALIBRATION          = 0x0DA1;
const unsigned short OFFSET_ISTRING               = 0x0F8A;
//const unsigned short OFFSET_SPARE_6               = 0x0FB2;
const unsigned short OFFSET_SPECTYPE              = 0x0FCB;
const unsigned short OFFSET_SPECMODEL             = 0x0FCC;
const unsigned short OFFSET_PULSEBURSTUSED        = 0x0FCD;
const unsigned short OFFSET_PULSEBURSTCOUNT       = 0x0FCE;
const unsigned short OFFSET_PULSEBURSTPERIOD      = 0x0FD2;
const unsigned short OFFSET_PULSEBRACKETUSED      = 0x0FDA;
const unsigned short OFFSET_PULSEBRACKETTYPE      = 0x0FDB;
const unsigned short OFFSET_PULSETIMECONSTFAST    = 0x0FDC;
const unsigned short OFFSET_PULSEAMPLITUDEFAST    = 0x0FE4;
const unsigned short OFFSET_PULSETIMECONSTSLOW    = 0x0FEC;
const unsigned short OFFSET_PULSEAMPLITUDESLOW    = 0x0FF4;
const unsigned short OFFSET_ANALOGGAIN            = 0x0FFC;
const unsigned short OFFSET_AVGAINUSED            = 0x0FFE;
const unsigned short OFFSET_AVGAIN                = 0x1000;
const unsigned short OFFSET_LASTVALUE             = 0x1002;
const unsigned short OFFSET_DATA                  = 0x1004;

speFile::speFile( const std::string& filePath )
{
  setFilePath( filePath );
}

speFile::~speFile()
{
  if( infile.is_open() ) infile.close();
}

bool speFile::setFilePath( const std::string& filePath )
{
  if( infile.is_open() ) infile.close();
  infile.open( filePath.c_str(), std::ios::in | std::ios::binary );
  if( infile.fail() ) infile.close();

  // Perform tests to make sure the file is a valid SPE file

  // Populate metadata
  retrieve( ControllerVersion, OFFSET_CONTROLLERVERSION );
  retrieve( LogicOutput, OFFSET_LOGICOUTPUT );
  retrieve( AmpHiCapLowNoise, OFFSET_AMPHICAPLOWNOISE );
  retrieve( xDimDet, OFFSET_XDIMDET );
  retrieve( mode, OFFSET_MODE );
  retrieve( exp_sec, OFFSET_EXP_SEC );
  retrieve( VChipXdim, OFFSET_VCHIPXDIM );
  retrieve( VChipYdim, OFFSET_VCHIPYDIM );
  retrieve( yDimDet, OFFSET_YDIMDET );
  retrieve( date, OFFSET_DATE );
  retrieve( VirtualChipFlag, OFFSET_VIRTUALCHIPFLAG );
  retrieve( noscan, OFFSET_NOSCAN );
  retrieve( DetTemperature, OFFSET_DETTEMPERATURE );
  retrieve( DetType, OFFSET_DETTYPE );
  retrieve( xdim, OFFSET_XDIM );
  retrieve( stdiode, OFFSET_STDIODE );
  retrieve( DelayTime, OFFSET_DELAYTIME );
  retrieve( ShutterControl, OFFSET_SHUTTERCONTROL );
  retrieve( AbsorbLive, OFFSET_ABSORBLIVE );
  retrieve( AbsorbMode, OFFSET_ABSORBMODE );
  retrieve( CanDoVirtualChipFlag, OFFSET_CANDOVIRTUALCHIPFLAG );
  retrieve( ThresholdMinLive, OFFSET_THRESHOLDMINLIVE );
  retrieve( ThresholdMinVal, OFFSET_THRESHOLDMINVAL );
  retrieve( ThresholdMaxLive, OFFSET_THRESHOLDMAXLIVE );
  retrieve( ThresholdMaxVal, OFFSET_THRESHOLDMAXVAL );
  retrieve( SpecAutoSpectroMode, OFFSET_SPECAUTOSPECTROMODE );
  retrieve( SpecCenterWlNm, OFFSET_SPECCENTERWLNM );
  retrieve( SpecGlueFlag, OFFSET_SPECGLUEFLAG );
  retrieve( SpecGlueStartWlNm, OFFSET_SPECGLUESTARTWLNM );
  retrieve( SpecGlueEndWlNm, OFFSET_SPECGLUEENDWLNM );
  retrieve( SpecGlueMinOvrlpNm, OFFSET_SPECGLUEMINOVRLPNM );
  retrieve( SpecGlueFinalResNm, OFFSET_SPECGLUEFINALRESNM );
  retrieve( PulserType, OFFSET_PULSERTYPE );
  retrieve( CustomChipFlag, OFFSET_CUSTOMCHIPFLAG );
  retrieve( XPrePixels, OFFSET_XPREPIXELS );
  retrieve( XPostPixels, OFFSET_XPOSTPIXELS );
  retrieve( YPrePixels, OFFSET_YPREPIXELS );
  retrieve( YPostPixels, OFFSET_YPOSTPIXELS );
  retrieve( asynen, OFFSET_ASYNEN );
  retrieve( datatype, OFFSET_DATATYPE );
  retrieve( PulserMode, OFFSET_PULSERMODE );
  retrieve( PulserOnChipAccums, OFFSET_PULSERONCHIPACCUMS );
  retrieve( PulseRepeatExp, OFFSET_PULSEREPEATEXP );
  retrieve( PulseRepWidth, OFFSET_PULSEREPWIDTH );
  retrieve( PulseRepDelay, OFFSET_PULSEREPDELAY );
  retrieve( PulseSeqStartWidth, OFFSET_PULSESEQSTARTWIDTH );
  retrieve( PulseSeqEndWidth, OFFSET_PULSESEQENDWIDTH );
  retrieve( PulseSeqStartDelay, OFFSET_PULSESEQSTARTDELAY );
  retrieve( PulseSeqEndDelay, OFFSET_PULSESEQENDDELAY );
  retrieve( PulseSeqIncMode, OFFSET_PULSESEQINCMODE );
  retrieve( PImaxUsed, OFFSET_PIMAXUSED );
  retrieve( PImaxMode, OFFSET_PIMAXMODE );
  retrieve( PImaxGain, OFFSET_PIMAXGAIN );
  retrieve( BackGrndApplied, OFFSET_BACKGRNDAPPLIED );
  retrieve( PImax2nsBrdUsed, OFFSET_PIMAX2NSBRDUSED );
  retrieve( minblk, OFFSET_MINBLK );
  retrieve( numminblk, OFFSET_NUMMINBLK );
  retrieve( SpecMirrorLocation, OFFSET_SPECMIRRORLOCATION );
  retrieve( SpecSlitLocation, OFFSET_SPECSLITLOCATION );
  retrieve( CustomTimingFlag, OFFSET_CUSTOMTIMINGFLAG );
  retrieve( ExperimentTimeLocal, OFFSET_EXPERIMENTTIMELOCAL );
  retrieve( ExperimentTimeUTC, OFFSET_EXPERIMENTTIMEUTC );
  retrieve( ExposUnits, OFFSET_EXPOSUNITS );
  retrieve( ADCoffset, OFFSET_ADCOFFSET );
  retrieve( ADCrate, OFFSET_ADCRATE );
  retrieve( ADCtype, OFFSET_ADCTYPE );
  retrieve( ADCresolution, OFFSET_ADCRESOLUTION );
  retrieve( ADCbitAdjust, OFFSET_ADCBITADJUST );
  retrieve( Comments[ 0 ], OFFSET_COMMENTS );
  retrieve( Comments[ 1 ], OFFSET_COMMENTS + COMMENTMAX * sizeof( char ) );
  retrieve( Comments[ 2 ], OFFSET_COMMENTS + 2 * COMMENTMAX * sizeof( char ) );
  retrieve( Comments[ 3 ], OFFSET_COMMENTS + 3 * COMMENTMAX * sizeof( char ) );
  retrieve( Comments[ 4 ], OFFSET_COMMENTS + 4 * COMMENTMAX * sizeof( char ) );
  retrieve( geometric, OFFSET_GEOMETRIC );
  retrieve( xlabel, OFFSET_XLABEL );
  retrieve( cleans, OFFSET_CLEANS );
  retrieve( NumSkpPerCln, OFFSET_NUMSKPPERCLN );
  retrieve( SpecMirrorPos, OFFSET_SPECMIRRORPOS );
  retrieve( SpecSlitPos, OFFSET_SPECSLITPOS );
  retrieve( AutoCleansActive, OFFSET_AUTOCLEANSACTIVE );
  retrieve( UseContCleansInst, OFFSET_USECONTCLEANSINST );
  retrieve( AbsorbStripNum, OFFSET_ABSORBSTRIPNUM );
  retrieve( SpecSlitPosUnits, OFFSET_SPECSLITPOSUNITS );
  retrieve( SpecGrooves, OFFSET_SPECGROOVES );
  retrieve( srccmp, OFFSET_SRCCMP );
  retrieve( ydim, OFFSET_YDIM );
  retrieve( scramble, OFFSET_SCRAMBLE );
  retrieve( ContinuousCleansFlag, OFFSET_CONTINUOUSCLEANSFLAG );
  retrieve( ExternalTriggerFlag, OFFSET_EXTERNALTRIGGERFLAG );
  retrieve( lnoscan, OFFSET_LNOSCAN );
  retrieve( lavgexp, OFFSET_LAVGEXP );
  retrieve( ReadOutTime, OFFSET_READOUTTIME );
  retrieve( TriggeredModeFlag, OFFSET_TRIGGEREDMODEFLAG );
  retrieve( sw_version, OFFSET_SW_VERSION );
  retrieve( type, OFFSET_TYPE );
  retrieve( flatFieldApplied, OFFSET_FLATFIELDAPPLIED );
  retrieve( kin_trig_mode, OFFSET_KIN_TRIG_MODE );
  retrieve( dlabel, OFFSET_DLABEL );
  retrieve( PulseFileName, OFFSET_PULSEFILENAME );
  retrieve( AbsorbFileName, OFFSET_ABSORBFILENAME );
  retrieve( NumExpRepeats, OFFSET_NUMEXPREPEATS );
  retrieve( NumExpAccums, OFFSET_NUMEXPACCUMS );
  retrieve( YT_Flag, OFFSET_YT_FLAG );
  retrieve( clkspd_us, OFFSET_CLKSPD_US );
  retrieve( HWaccumFlag, OFFSET_HWACCUMFLAG );
  retrieve( StoreSync, OFFSET_STORESYNC );
  retrieve( BlemishApplied, OFFSET_BLEMISHAPPLIED );
  retrieve( CosmicApplied, OFFSET_COSMICAPPLIED );
  retrieve( CosmicType, OFFSET_COSMICTYPE );
  retrieve( CosmicThreshold, OFFSET_COSMICTHRESHOLD );
  retrieve( NumFrames, OFFSET_NUMFRAMES );
  retrieve( MaxIntensity, OFFSET_MAXINTENSITY );
  retrieve( MinIntensity, OFFSET_MININTENSITY );
  retrieve( ylabel, OFFSET_YLABEL );
  retrieve( ShutterType, OFFSET_SHUTTERTYPE );
  retrieve( shutterComp, OFFSET_SHUTTERCOMP );
  retrieve( readoutMode, OFFSET_READOUTMODE );
  retrieve( WindowSize, OFFSET_WINDOWSIZE );
  retrieve( clkspd, OFFSET_CLKSPD );
  retrieve( interface_type, OFFSET_INTERFACE_TYPE );
  retrieve( NumROIsInExperiment, OFFSET_NUMROISINEXPERIMENT );
  retrieve( controllerNum, OFFSET_CONTROLLERNUM );
  retrieve( SWmade, OFFSET_SWMADE );
  retrieve( NumROI, OFFSET_NUMROI );
// TODO: Implement reading regions of interest
//for( int i = 0; i < ( ( NumROI == 0 )? 1 : ( NumROI > ROIMAX )? ROIMAX : NumROI ); i++ )
  retrieve( FlatField, OFFSET_FLATFIELD );
  retrieve( background, OFFSET_BACKGROUND );
  retrieve( blemish, OFFSET_BLEMISH );
  retrieve( file_header_ver, OFFSET_FILE_HEADER_VER );
  retrieve( YT_info, OFFSET_YT_INFO );
  retrieve( WinView_id, OFFSET_WINVIEW_ID );
  retrieve( xcalibration.offset, OFFSET_XCALIBRATION );
  retrieve( xcalibration.factor );
  retrieve( xcalibration.current_unit );
  retrieve( xcalibration.reserved1 );
  retrieve( xcalibration.string );
  retrieve( xcalibration.reserved2 );
  retrieve( xcalibration.calib_valid );
  retrieve( xcalibration.input_unit );
  retrieve( xcalibration.polynom_unit );
  retrieve( xcalibration.polynom_order );
  retrieve( xcalibration.calib_count );
  retrieve( xcalibration.pixel_position );
  retrieve( xcalibration.calib_value );
  retrieve( xcalibration.polynom_coeff );
  retrieve( xcalibration.laser_position );
  retrieve( xcalibration.reserved3 );
  retrieve( xcalibration.new_calib_flag );
  retrieve( xcalibration.calib_label );
  retrieve( xcalibration.expansion );
  retrieve( ycalibration.offset, OFFSET_YCALIBRATION );
  retrieve( ycalibration.factor );
  retrieve( ycalibration.current_unit );
  retrieve( ycalibration.reserved1 );
  retrieve( ycalibration.string );
  retrieve( ycalibration.reserved2 );
  retrieve( ycalibration.calib_valid );
  retrieve( ycalibration.input_unit );
  retrieve( ycalibration.polynom_unit );
  retrieve( ycalibration.polynom_order );
  retrieve( ycalibration.calib_count );
  retrieve( ycalibration.pixel_position );
  retrieve( ycalibration.calib_value );
  retrieve( ycalibration.polynom_coeff );
  retrieve( ycalibration.laser_position );
  retrieve( ycalibration.reserved3 );
  retrieve( ycalibration.new_calib_flag );
  retrieve( ycalibration.calib_label );
  retrieve( ycalibration.expansion );
  retrieve( Istring, OFFSET_ISTRING );
  retrieve( SpecType, OFFSET_SPECTYPE );
  retrieve( SpecModel, OFFSET_SPECMODEL );
  retrieve( PulseBurstUsed, OFFSET_PULSEBURSTUSED );
  retrieve( PulseBurstCount, OFFSET_PULSEBURSTCOUNT );
  retrieve( PulseBurstPeriod, OFFSET_PULSEBURSTPERIOD );
  retrieve( PulseBracketUsed, OFFSET_PULSEBRACKETUSED );
  retrieve( PulseBracketType, OFFSET_PULSEBRACKETTYPE );
  retrieve( PulseTimeConstFast, OFFSET_PULSETIMECONSTFAST );
  retrieve( PulseAmplitudeFast, OFFSET_PULSEAMPLITUDEFAST );
  retrieve( PulseTimeConstSlow, OFFSET_PULSETIMECONSTSLOW );
  retrieve( PulseAmplitudeSlow, OFFSET_PULSEAMPLITUDESLOW );
  retrieve( AnalogGain, OFFSET_ANALOGGAIN );
  retrieve( AvGainUsed, OFFSET_AVGAINUSED );
  retrieve( AvGain, OFFSET_AVGAIN );
  retrieve( lastvalue, OFFSET_LASTVALUE );
}

void speFile::printInfo() const
{
  if( !infile.is_open() ) return;

  std::cout << "Summary Information" << std::endl;
  std::cout << "-------------------" << std::endl;
  std::cout << "Dimensions: " << xdim << " rows x " << ydim << " cols" << std::endl;
  std::cout << "Number of frames: " << NumFrames << std::endl;
  std::cout << std::endl;
}

void speFile::printMetadata() const
{
  if( !infile.is_open() ) return;

  std::cout << "Detailed Information" << std::endl;
  std::cout << "--------------------" << std::endl;

  std::cout << "ControllerVersion (Hardware version): " << ControllerVersion << std::endl;
  std::cout << "LogicOutput (Definition of Output BNC): " << LogicOutput << std::endl;
  std::cout << "AmpHiCapLowNoise (Amp switching mode): " << AmpHiCapLowNoise << std::endl;
  std::cout << "xDimDet (Detector x dimension of chip): " << xDimDet << std::endl;
  std::cout << "mode (timing mode): " << mode << std::endl;
  std::cout << "exp_sec (alternative exposure, in sec): " << exp_sec << std::endl;
  std::cout << "VChipXdim (Virtual Chip X dim): " << VChipXdim << std::endl;
  std::cout << "VChipYdim (Virtual Chip Y dim): " << VChipYdim << std::endl;
  std::cout << "yDimDet (Detector y dimension of chip): " << yDimDet << std::endl;
  std::cout << "date (date): " << date << std::endl;
  std::cout << "VirtualChipFlag (On/Off): " << VirtualChipFlag << std::endl;
  std::cout << "noscan (Old number of scans, should be -1): " << noscan << std::endl;
  std::cout << "DetTemperature (Detector Temperature Set): " << DetTemperature << std::endl;
  std::cout << "DetType (CCD/DiodeArray type): " << DetType << std::endl;
  std::cout << "xdim (actual # of pixels on x axis): " << xdim << std::endl;
  std::cout << "stdiode (trigger diode): " << stdiode << std::endl;
  std::cout << "DelayTime (Used with Async Mode): " << DelayTime << std::endl;
  std::cout << "ShutterControl (Normal, Disabled Open, Disabled Closed): " << ShutterControl << std::endl;
  std::cout << "AbsorbLive (On/Off): " << AbsorbLive << std::endl;
  std::cout << "AbsorbMode (Reference Strip or File): " << AbsorbMode << std::endl;
  std::cout << "CanDoVirtualChipFlag (T/F Cont/Chip able to do Virtual Chip): " << CanDoVirtualChipFlag << std::endl;
  std::cout << "ThresholdMinLive (On/Off): " << ThresholdMinLive << std::endl;
  std::cout << "ThresholdMinVal (Threshold Minimum Value): " << ThresholdMinVal << std::endl;
  std::cout << "ThresholdMaxLive (On/Off): " << ThresholdMaxLive << std::endl;
  std::cout << "ThresholdMaxVal (Threshold Maximum Value): " << ThresholdMaxVal << std::endl;
  std::cout << "SpecAutoSpectroMode (T/F Spectrograph Used): " << SpecAutoSpectroMode << std::endl;
  std::cout << "SpecCenterWlNm (Center Wavelength in nm): "  << SpecCenterWlNm << std::endl;
  std::cout << "SpecGlueFlag (T/F File is Glued): " << SpecGlueFlag << std::endl;
  std::cout << "SpecGlueStartWlNm (Starting Wavelength in nm): " << SpecGlueStartWlNm << std::endl;
  std::cout << "SpecGlueEndWlNm (Ending Wavelength in nm): " << SpecGlueEndWlNm << std::endl;
  std::cout << "SpecGlueMinOvrlpNm (Minimum Overlap in nm): " << SpecGlueMinOvrlpNm << std::endl;
  std::cout << "SpecGlueFinalResNm (Final Resolution in nm): " << SpecGlueFinalResNm << std::endl;
  std::cout << "PulserType (0 = None, 1 = PG200, 2 = PTG, 3 = DG535): " << PulserType << std::endl;
  std::cout << "CustomChipFlag (T/F Custom Chip Used): " << CustomChipFlag << std::endl;
  std::cout << "XPrePixels (Pre Pixels in X direction): " << XPrePixels << std::endl;
  std::cout << "XPostPixels (Post Pixels in X direction): " << XPostPixels << std::endl;
  std::cout << "YPrePixels (Pre Pixels in Y direction): " << YPrePixels << std::endl;
  std::cout << "YPostPixels (Post Pixels in Y direction): " << YPostPixels << std::endl;
  std::cout << "asynen (asynchron enable flag 0 = off): " << asynen << std::endl;
  std::cout << "datatype (experiment datatype): " << datatype << std::endl;
  std::cout << "PulserMode (Repetitive/Sequential): " << PulserMode << std::endl;
  std::cout << "PulserOnChipAccums (Num PTG On-Chip Accums): " << PulserOnChipAccums << std::endl;
  std::cout << "PulseRepeatExp (Num Exp Repeats (Pulser SW Accum)): " << PulseRepeatExp << std::endl;
  std::cout << "PulseRepWidth (Width Value for Repetitive pulse (usec)): " << PulseRepWidth << std::endl;
  std::cout << "PulseRepDelay (Width Value for Repetitive pulse (usec)): " << PulseRepDelay << std::endl;
  std::cout << "PulseSeqStartWidth (Start Width for Sequential pulse (usec)): " << PulseSeqStartWidth << std::endl;
  std::cout << "PulseSeqEndWidth (End Width for Sequential pulse (usec)): " << PulseSeqEndWidth << std::endl;
  std::cout << "PulseSeqStartDelay (Start Delay for Sequential pulse (usec)): " << PulseSeqStartDelay << std::endl;
  std::cout << "PulseSeqEndDelay (End Delay for Sequential pulse (usec)): " << PulseSeqEndDelay << std::endl;
  std::cout << "PulseSeqIncMode (Increments: 1 = Fixed, 2 = Exponential): " << PulseSeqIncMode << std::endl;
  std::cout << "PImaxUsed (PI-Max type controller flag): " << PImaxUsed << std::endl;
  std::cout << "PImaxMode (PI-Max mode): " << PImaxMode << std::endl;
  std::cout << "PImaxGain (PI-Max Gain): "<< PImaxGain << std::endl;
  std::cout << "BackGrndApplied (1 if background subtraction done): " << BackGrndApplied << std::endl;
  std::cout << "PImax2nsBrdUsed (T/F PI-Max 2 ns Board Used): " << PImax2nsBrdUsed << std::endl;
  std::cout << "minblk (min. # of strips per skips): " << minblk << std::endl;
  std::cout << "numminblk (# of min-blocks before geo skps): " << numminblk << std::endl;
  std::cout << "SpecMirrorLocation (Spectro Mirror Location, 0 = Not Present): " << SpecMirrorLocation[ 0 ] << ", " << SpecMirrorLocation[ 1 ] << std::endl;
  std::cout << "SpecSlitLocation (Spectro Slit Location, 0 = Not Present): " << SpecSlitLocation[ 0 ] << ", " << SpecSlitLocation[ 1 ] << ", " << SpecSlitLocation[ 2 ] << ", " << SpecSlitLocation[ 3 ] << std::endl;
  std::cout << "CustomTimingFlag (T/F Custom Timing Used): " << CustomTimingFlag << std::endl;
  std::cout << "ExperimentTimeLocal (Experiment Local Time as hhmmss): " << ExperimentTimeLocal << std::endl;
  std::cout << "ExperimentTimeUTC (Experiment UTC Time as hhmmss): " << ExperimentTimeUTC << std::endl;
  std::cout << "ExposUnits (User Units for Exposure): " << ExposUnits << std::endl;
  std::cout << "ADCoffset (ADC offset): " << ADCoffset << std::endl;
  std::cout << "ADCrate (ADC rate): " << ADCrate << std::endl;
  std::cout << "ADCtype (ADC type): " << ADCtype << std::endl;
  std::cout << "ADCresolution (ADC resolution): " << ADCresolution << std::endl;
  std::cout << "ADCbitAdjust (ADC bit adjust): " << ADCbitAdjust << std::endl;
  std::cout << "Comments[ 0 ] (File Comments): " << Comments[ 0 ] << std::endl;
  std::cout << "Comments[ 1 ] (File Comments): " << Comments[ 1 ] << std::endl;
  std::cout << "Comments[ 2 ] (File Comments): " << Comments[ 2 ] << std::endl;
  std::cout << "Comments[ 3 ] (File Comments): " << Comments[ 3 ] << std::endl;
  std::cout << "Comments[ 4 ] (File Comments): " << Comments[ 4 ] << std::endl;
  std::cout << "geometric (geometric ops: 0x01 = rotate, 0x02 = reverse, 0x04 = flip): " << geometric << std::endl;
  std::cout << "xlabel (intensity display string): " << xlabel << std::endl;
  std::cout << "cleans (cleans): " << cleans << std::endl;
  std::cout << "NumSkpPerCln (number of skips per clean): " << NumSkpPerCln << std::endl;
  std::cout << "SpecMirrorPos (Spectrograph Mirror Positions): " << SpecMirrorPos[ 0 ] << ", " << SpecMirrorPos[ 1 ] << std::endl;
  std::cout << "SpecSlitPos (Spectrograph Slit Positions): " << SpecSlitPos[ 0 ] << ", " << SpecSlitPos[ 1 ] << ", " << SpecSlitPos[ 2 ] << ", " << SpecSlitPos[ 3 ] << std::endl;
  std::cout << "AutoCleansActive (T/F): " << AutoCleansActive << std::endl;
  std::cout << "UseContCleansInst (T/F): " << UseContCleansInst << std::endl;
  std::cout << "AbsorbStripNum (Absorbance Strip Number): " << AbsorbStripNum << std::endl;
  std::cout << "SpecSlitPosUnits (Spectrograph Slit Position Units): " << SpecSlitPosUnits << std::endl;
  std::cout << "SpecGrooves (Spectrograph Grating Grooves): " << SpecGrooves << std::endl;
  std::cout << "srccmp (number of source comp. diodes): " << srccmp << std::endl;
  std::cout << "ydim (y dimension of raw data): " << ydim << std::endl;
  std::cout << "scramble (0 = scrambled, 1 = unscrambled): " << scramble << std::endl;
  std::cout << "ContinuousCleansFlag (T/F Continuous Cleans Timing Option): " << ContinuousCleansFlag << std::endl;
  std::cout << "ExternalTriggerFlag (T/F External Trigger Timing Option): " << ExternalTriggerFlag << std::endl;
  std::cout << "lnoscan (Number of scans (Early WinX)): " << lnoscan << std::endl;
  std::cout << "lavgexp (Number of Accumulations): " << lavgexp << std::endl;
  std::cout << "ReadOutTime (Experiment readout time): " << ReadOutTime << std::endl;
  std::cout << "TriggeredModeFlag (T/F Triggered Timing Option): " << TriggeredModeFlag << std::endl;
  std::cout << "sw_version (Version of SW creating this file): " << sw_version << std::endl;
  std::cout << "type (1 = new120 (Type II), 2 = old120 (Type I), 3 = ST130, 4 = ST121, 5 = ST138, 6 = DC131 (PentaMax), 7 = ST133 (MicroMax/SpectroMax), 8 = ST135 (GPIB), 9 = VICCD, 10 = ST116 (GPIB), 11 = OMA3 (GPIB), 12 = OMA4): " << type << std::endl;
  std::cout << "flatFieldApplied (1 if flat field was applied): " << flatFieldApplied << std::endl;
  std::cout << "kin_trig_mode (Kinetics Trigger Mode): " << kin_trig_mode << std::endl;
  std::cout << "dlabel (Data label): " << dlabel << std::endl;
  std::cout << "PulseFileName (Name of Pulser File with Pulse Widths/Delays (for Z-Slice)): " << PulseFileName << std::endl;
  std::cout << "AbsorbFileName (Name of Absorbance File (if File Mode)): " << AbsorbFileName << std::endl;
  std::cout << "NumExpRepeats (Number of Times experiment repeated): " << NumExpRepeats << std::endl;
  std::cout << "NumExpAccums (Number of Times experiment accumulated): " << NumExpAccums << std::endl;
  std::cout << "YT_Flag (Set to 1 if this file contains YT data): " << YT_Flag << std::endl;
  std::cout << "clkspd_us (Vert Clock Speed in usec): " << clkspd_us << std::endl;
  std::cout << "HWaccumFlag (set to 1 if accum done by Hardware): " << HWaccumFlag << std::endl;
  std::cout << "StoreSync (set to 1 if store sync used): " << StoreSync << std::endl;
  std::cout << "BlemishApplied (set to 1 if blemish removal applied): " << BlemishApplied << std::endl;
  std::cout << "CosmicApplied (set to 1 if cosmic ray removal applied): " << CosmicApplied << std::endl;
  std::cout << "CosmicType (if cosmic ray applied, this is type): " << CosmicType << std::endl;
  std::cout << "CosmicThreshold (Threshold of cosmic ray removal): " << CosmicThreshold << std::endl;
  std::cout << "NumFrames (number of frames in file): " << NumFrames << std::endl;
  std::cout << "MaxIntensity (max intensity of data (future)): " << MaxIntensity << std::endl;
  std::cout << "MinIntensity (min intensity of data (future)): " << MinIntensity << std::endl;
  std::cout << "ylabel (y axis label): " << ylabel << std::endl;
  std::cout << "ShutterType (shutter type): " << ShutterType << std::endl;
  std::cout << "shutterComp (shutter compensation time): " << shutterComp << std::endl;
  std::cout << "readoutMode (readout mode, full, kinetics, etc): " << readoutMode << std::endl;
  std::cout << "WindowSize (window size for kinetics only): " << WindowSize << std::endl;
  std::cout << "clkspd (clock speed for kinetics & frame transfer): " << clkspd << std::endl;
  std::cout << "interface_type (computer interface (isa-taxi, pci, eisa, etc)): "  << interface_type << std::endl;
  std::cout << "NumROIsInExperiment (May be more than the 10 allowed in this header (if 0, assume 1)): " << NumROIsInExperiment << std::endl;
  std::cout << "controllerNum (if multiple controller system will have controller data came from, this is a future item): " << controllerNum << std::endl;
  std::cout << "SWmade (Which software package created this file): " << SWmade << std::endl;
  std::cout << "NumROI (number of ROIs used, if 0 assume 1): " << NumROI << std::endl;

/* TODO: Need to implement reading regions of interest
  struct ROI
  {
    WORD startx;                        // left x start value
    WORD endx;                          // right x value
    WORD groupx;                        // amount x is binned/grouped in hw
    WORD starty;                        // top y start value
    WORD endy;                          // bottom y value
    WORD groupy;                        // amount y is binned/grouped in hw
  } ROIinfoblk[ ROIMAX ];               // ROI info blocks
*/

  std::cout << "FlatField (Flat field file name): " << FlatField << std::endl;
  std::cout << "background (background sub file name): " << background << std::endl;
  std::cout << "blemish (blemish file name): " << blemish << std::endl;
  std::cout << "file_header_ver (version of this file header): " << file_header_ver << std::endl;
  std::cout << "YT_info (Reserved for YT information): " << YT_info << std::endl;
  std::cout << "WinView_id (0x01234567L if file created by WinX): " << WinView_id << std::endl;
  std::cout << "xcalibration.offset (offset for absolute data scaling): " << xcalibration.offset << std::endl;
  std::cout << "xcalibration.factor (factor for absolute data scaling): " << xcalibration.factor << std::endl;
  std::cout << "xcalibration.current_unit (selected scaling unit): " << xcalibration.current_unit << std::endl;
  std::cout << "xcalibration.reserved1 (reserved): " << xcalibration.reserved1 << std::endl;
  std::cout << "xcalibration.string (special string for scaling): " << xcalibration.string << std::endl;
  std::cout << "xcalibration.reserved2 (reserved): " << xcalibration.reserved2 << std::endl;
  std::cout << "xcalibration.calib_valid (flag if calibration is valid): " << xcalibration.calib_valid << std::endl;
  std::cout << "xcalibration.input_unit (current input units for \"calib_value\"): " << xcalibration.input_unit << std::endl;
  std::cout << "xcalibration.polynom_unit (linear unit and used in \"polynom_coeff\"): " << xcalibration.polynom_unit << std::endl;
  std::cout << "xcalibration.polynom_order (order of calibration polynom): " << xcalibration.polynom_order << std::endl;
  std::cout << "xcalibration.calib_count (valid calibration data pairs): " << xcalibration.calib_count << std::endl;
  std::cout << "xcalibration.pixel_position (pixel pos of calibration data): " << xcalibration.pixel_position[ 0 ] << ", " << xcalibration.pixel_position[ 1 ] << ", " << xcalibration.pixel_position[ 2 ] << ", " << xcalibration.pixel_position[ 3 ] << ", " << xcalibration.pixel_position[ 4 ] << ", " << xcalibration.pixel_position[ 5 ] << ", " << xcalibration.pixel_position[ 6 ] << ", " << xcalibration.pixel_position[ 7 ] << ", " << xcalibration.pixel_position[ 8 ] << ", " << xcalibration.pixel_position[ 9 ] << std::endl;
  std::cout << "xcalibration.calib_value (calibration value at above pos): " << xcalibration.calib_value[ 0 ] << ", " << xcalibration.calib_value[ 1 ] << ", " << xcalibration.calib_value[ 2 ] << ", " << xcalibration.calib_value[ 3 ] << ", " << xcalibration.calib_value[ 4 ] << ", " << xcalibration.calib_value[ 5 ] << ", " << xcalibration.calib_value[ 6 ] << ", " << xcalibration.calib_value[ 7 ] << ", " << xcalibration.calib_value[ 8 ] << ", " << xcalibration.calib_value[ 9 ] << std::endl;
  std::cout << "xcalibration.polynom_coeff (polynom coefficients): " << xcalibration.polynom_coeff[ 0 ] << ", " << xcalibration.polynom_coeff[ 1 ] << ", " << xcalibration.polynom_coeff[ 2 ] << ", " << xcalibration.polynom_coeff[ 3 ] << ", " << xcalibration.polynom_coeff[ 4 ] << ", " << xcalibration.polynom_coeff[ 5 ] << std::endl;
  std::cout << "xcalibration.laser_position (laser wavenumber for relative WN): " << xcalibration.laser_position << std::endl;
  std::cout << "xcalibration.reserved3 (reserved): " << xcalibration.reserved3 << std::endl;
  std::cout << "xcalibration.new_calib_flag (If set to 200, valid label below): " << xcalibration.new_calib_flag << std::endl;
  std::cout << "xcalibration.calib_label (calibration label): " << xcalibration.calib_label << std::endl;
  std::cout << "xcalibration.expansion (Calibration Expansion area): " << xcalibration.expansion << std::endl;
  std::cout << "ycalibration.offset (offset for absolute data scaling): " << ycalibration.offset << std::endl;
  std::cout << "ycalibration.factor (factor for absolute data scaling): " << ycalibration.factor << std::endl;
  std::cout << "ycalibration.current_unit (selected scaling unit): " << ycalibration.current_unit << std::endl;
  std::cout << "ycalibration.reserved1 (reserved): " << ycalibration.reserved1 << std::endl;
  std::cout << "ycalibration.string (special string for scaling): " << ycalibration.string << std::endl;
  std::cout << "ycalibration.reserved2 (reserved): " << ycalibration.reserved2 << std::endl;
  std::cout << "ycalibration.calib_valid (flag if calibration is valid): " << ycalibration.calib_valid << std::endl;
  std::cout << "ycalibration.input_unit (current input units for \"calib_value\"): " << ycalibration.input_unit << std::endl;
  std::cout << "ycalibration.polynom_unit (linear unit and used in \"polynom_coeff\"): " << ycalibration.polynom_unit << std::endl;
  std::cout << "ycalibration.polynom_order (order of calibration polynom): " << ycalibration.polynom_order << std::endl;
  std::cout << "ycalibration.calib_count (valid calibration data pairs): " << ycalibration.calib_count << std::endl;
  std::cout << "ycalibration.pixel_position (pixel pos of calibration data): " << ycalibration.pixel_position[ 0 ] << ", " << ycalibration.pixel_position[ 1 ] << ", " << ycalibration.pixel_position[ 2 ] << ", " << ycalibration.pixel_position[ 3 ] << ", " << ycalibration.pixel_position[ 4 ] << ", " << ycalibration.pixel_position[ 5 ] << ", " << ycalibration.pixel_position[ 6 ] << ", " << ycalibration.pixel_position[ 7 ] << ", " << ycalibration.pixel_position[ 8 ] << ", " << ycalibration.pixel_position[ 9 ] << std::endl;
  std::cout << "ycalibration.calib_value (calibration value at above pos): " << ycalibration.calib_value[ 0 ] << ", " << ycalibration.calib_value[ 1 ] << ", " << ycalibration.calib_value[ 2 ] << ", " << ycalibration.calib_value[ 3 ] << ", " << ycalibration.calib_value[ 4 ] << ", " << ycalibration.calib_value[ 5 ] << ", " << ycalibration.calib_value[ 6 ] << ", " << ycalibration.calib_value[ 7 ] << ", " << ycalibration.calib_value[ 8 ] << ", " << ycalibration.calib_value[ 9 ] << std::endl;
  std::cout << "ycalibration.polynom_coeff (polynom coefficients): " << ycalibration.polynom_coeff[ 0 ] << ", " << ycalibration.polynom_coeff[ 1 ] << ", " << ycalibration.polynom_coeff[ 2 ] << ", " << ycalibration.polynom_coeff[ 3 ] << ", " << ycalibration.polynom_coeff[ 4 ] << ", " << ycalibration.polynom_coeff[ 5 ] << std::endl;
  std::cout << "ycalibration.laser_position (laser wavenumber for relative WN): " << ycalibration.laser_position << std::endl;
  std::cout << "ycalibration.reserved3 (reserved): " << ycalibration.reserved3 << std::endl;
  std::cout << "ycalibration.new_calib_flag (If set to 200, valid label below): " << ycalibration.new_calib_flag << std::endl;
  std::cout << "ycalibration.calib_label (calibration label): " << ycalibration.calib_label << std::endl;
  std::cout << "ycalibration.expansion (Calibration Expansion area): " << ycalibration.expansion << std::endl;
  std::cout << "Istring (special intensity scaling string): " << Istring << std::endl;
  std::cout << "SpecType (spectrometer type (acton, spex, etc)): " << SpecType << std::endl;
  std::cout << "SpecModel (spectrometer model (type dependent)): " << SpecModel << std::endl;
  std::cout << "PulseBurstUsed (pulser burst mode on/off): " << PulseBurstUsed << std::endl;
  std::cout << "PulseBurstCount (pulser triggers per burst): " << PulseBurstCount << std::endl;
  std::cout << "PulseBurstPeriod (pulser burst period (in usec)): " << PulseBurstPeriod << std::endl;
  std::cout << "PulseBracketUsed (pulser bracket pulsing on/off): " << PulseBracketUsed << std::endl;
  std::cout << "PulseBracketType (pulser bracket pulsing type): " << PulseBracketType << std::endl;
  std::cout << "PulseTimeConstFast (pulser fast exponential time constant (in usec)): " << PulseTimeConstFast << std::endl;
  std::cout << "PulseAmplitudeFast (pulser fast exponential amplitude constant): " << PulseAmplitudeFast << std::endl;
  std::cout << "PulseTimeConstSlow (pulser slow exponential time constant (in usec): " << PulseTimeConstSlow << std::endl;
  std::cout << "PulseAmplitudeSlow (pulser slow exponential amplitude constant): " << PulseAmplitudeSlow << std::endl;
  std::cout << "AnalogGain (analog gain): " << AnalogGain << std::endl;
  std::cout << "AvGainUsed (avalanche gain was used): " << AvGainUsed << std::endl;
  std::cout << "AvGain (avalanche gain value): " << AvGain << std::endl;
  std::cout << "lastvalue (Always the last value in the header): " << lastvalue << std::endl;
  std::cout << std::endl;
}

