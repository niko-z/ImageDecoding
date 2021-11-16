//
//  Dynamsoft Camera Enhancer SDK
//
//  Copyright © 2021 Dynamsoft. All rights reserved.
//

NS_ASSUME_NONNULL_BEGIN
static NSString* _Nonnull const DCEErrorDomain = @"com.dynamsoft.cameraEnhancer.error";

/**
 * Describes the error codes.
 * @enum EnumDCEErrorCode
 */
typedef NS_ENUM(NSInteger, EnumDCEErrorCode)
{
    /** OK*/
    EnumDCEErrorCode_OK                             = 0,
    
    /** Unknown error. */
    EnumDCEErrorCode_UNKNOWN                        = -10000,
    
    /** The license is invalid. */
    EnumDCEErrorCode_LICENSE_INVALID                = -10001,
    
    /** The license has expired.*/
    EnumDCEErrorCode_LICENSE_EXPIRED                = -10002,
    
    /** The camera module is not exist. */
    EnumDCEErrorCode_CAMERA_MODULE_NOT_EXIST        = -10003,
    
    /** The file is not found.*/
    EnumDCEErrorCode_FILE_NOT_FOUND                 = -10004,
    
    /** The file format error. */
    EnumDCEErrorCode_FILE_FORMAT_ERROR              = -10005,
    
    /** The input value does not exist in the camera ID list. */
    EnumDCEErrorCode_CAMERA_ID_NOT_EXIST            = -10006,
    
    /** Failed to parse the JSON data. */
    EnumDCEErrorCode_JSON_PARSE_FAILED              = -10030,
    
    /** The input parameter is invalid. */
    EnumDCEErrorCode_PARAMETER_VALUE_INVALID        = -10038,
    
    /** Failed to request the license file. */
    EnumDCEErrorCode_REQUEST_FAILED                 = -10044,
    
    /** No license.*/
    EnumDCEErrorCode_NO_LICENSE                     = -20000,
    
    /** The handshake code is invalid. */
    EnumDCEErrorCode_HANDSHAKE_CODE_INVALID         = -20001,
    
    /** Failed to read or write license cache. */
    EnumDCEErrorCode_LICENSE_BUFFER_FAILED          = -20002,

    /** Falied to synchronize license info wirh license tracking server. */
    EnumDCEErrorCode_LICENSE_SYNC_FAILED            = -20003,
    
    /** Device does not match with license buffer. */
    EnumDCEErrorCode_DEVICE_NOT_MATCH               = -20004,

    /** Falied to bind device. */
    EnumDCEErrorCode_BIND_DEVICE_FAILED             = -20005,
    
    /** Interface InitLicenseFromDLS can not be used together with other license initiation interfaces. */
    EnumDCEErrorCode_LICENSE_INTERFACE_CONFLICT     = -20006,
    
    /** License Client dll is missing.*/
    EnumDCEErrorCode_LICENSE_CLIENT_DLL_MISSING     = -20007,
    
    /**Instance count is over limited.*/
    EnumDCEErrorCode_INSTANCE_COUNT_OVER_LIMITED    = -20008,

    /** Interface InitLicenseFromDLS has to be called before creating any SDK objects. */
    EnumDCEErrorCode_LICENSE_INIT_SEQUENCE_FAILED   = -20009,
    
    /** Trial License*/
    EnumDCEErrorCode_TRIAL_LICENSE                  = -20010,

    /** Failed to reach License Tracking Server.*/
    EnumDCEErrorCode_FAILED_TO_REACH_DLS            = -20200
};

typedef NS_ENUM(NSInteger, EnumResolution)
{
    EnumRESOLUTION_AUTO NS_SWIFT_NAME(EnumRESOLUTION_AUTO)   = 0,
    EnumRESOLUTION_480P NS_SWIFT_NAME(EnumRESOLUTION_480P)   = 1,
    EnumRESOLUTION_720P NS_SWIFT_NAME(EnumRESOLUTION_720P)   = 2,
    EnumRESOLUTION_1080P NS_SWIFT_NAME(EnumRESOLUTION_1080P) = 3,
    EnumRESOLUTION_4K NS_SWIFT_NAME(EnumRESOLUTION_4K)       = 5,
    EnumRESOLUTION_HIGH NS_SWIFT_NAME(EnumRESOLUTION_HIGH)   = 6,
    EnumRESOLUTION_MID NS_SWIFT_NAME(EnumRESOLUTION_MID)     = 7,
    EnumRESOLUTION_LOW NS_SWIFT_NAME(EnumRESOLUTION_LOW)     = 8
} NS_SWIFT_NAME(EnumResolution);

typedef NS_ENUM(NSInteger, EnumCameraState) {
    EnumCAMERA_STATE_OPENING NS_SWIFT_NAME(EnumCAMERA_STATE_OPENING)  = 0,
    EnumCAMERA_STATE_OPENED  NS_SWIFT_NAME(EnumCAMERA_STATE_OPENED)   = 1,
    EnumCAMERA_STATE_CLOSING  NS_SWIFT_NAME(EnumCAMERA_STATE_CLOSING)   = 2,
    EnumCAMERA_STATE_CLOSED  NS_SWIFT_NAME(EnumCAMERA_STATE_CLOSED)   = 3
} NS_SWIFT_NAME(EnumCameraState);

typedef NS_ENUM(NSInteger, EnumEnhancerFeatures) {
    EnumFRAME_FILTER NS_SWIFT_NAME(EnumFRAME_FILTER)   = 0X01,
    EnumSENSOR_CONTROL NS_SWIFT_NAME(EnumSENSOR_CONTROL) = 0X02,
    EnumENHANCED_FOCUS NS_SWIFT_NAME(EnumENHANCED_FOCUS) = 0X04,
    EnumFAST_MODE NS_SWIFT_NAME(EnumFAST_MODE) = 0X08,
    EnumAUTO_ZOOM NS_SWIFT_NAME(EnumAUTO_ZOOM) = 0X10,
} NS_SWIFT_NAME(EnumEnhancerFeatures);

typedef NS_ENUM(NSInteger, EnumFrameQuality) {
    EnumFRAME_QUALITY_HIGH NS_SWIFT_NAME(EnumFRAME_QUALITY_HIGH)   = 0,
    EnumFRAME_QUALITY_LOW NS_SWIFT_NAME(EnumFRAME_QUALITY_LOW) = 1,
    EnumFRAME_QUALITY_UNKNOWN NS_SWIFT_NAME(EnumFRAME_QUALITY_UNKNOWN) = 2
} NS_SWIFT_NAME(EnumFrameQuality);

/// Return the  decode results and additional information.
@interface DCEFrame : NSObject

@property (strong, nonatomic) NSData* imageData;
@property (nonatomic, assign) NSInteger width;
@property (nonatomic, assign) NSInteger height;
@property (nonatomic, assign) NSInteger stride;
@property (nonatomic, assign) NSInteger pixelFormat;
@property (nonatomic, assign) NSInteger frameID;
@property (nonatomic, assign) NSInteger fastFrameID;
@property (nonatomic, assign) NSInteger orientation;
@property (nonatomic, assign) EnumFrameQuality quality;
@property (nonatomic, assign) BOOL isCropped;
@property (nonatomic, assign) CGRect cropRegion;
@property (assign, nonatomic) CVImageBufferRef imageBuffer;

- (nullable UIImage *)toUIImage;

- (instancetype)initWithBuffer:(NSData*)imageData width:(NSInteger)width height:(NSInteger)height stride:(NSInteger)stride pixelFormat:(NSInteger)pixelFormat frameID:(NSInteger)frameID fastFrameID:(NSInteger)fastFrameID orientation:(NSInteger)orientation quality:(EnumFrameQuality)quality isCropped:(BOOL)isCropped cropRegion:(CGRect)cropRegion imageBuffer:(CVImageBufferRef)imageBuffer;
@end

@protocol DCEFrameListener <NSObject>

@required
- (void)frameOutPutCallback:(DCEFrame*)frame timeStamp:(NSTimeInterval)timeStamp;

@end

/**
 * Protocol for a delegate to handle callback when license verification message returned.
 */
@protocol DCELicenseVerificationListener <NSObject>

@required
/**
 * The callback of license server.
 *
 * @param [in,out] isSuccess Whether the license verification was successful.
 * @param [in,out] error The error message from license server.
 *
 * @par Code Snippet:
 * @code
 *    [DynamsoftCameraEnhancer initLicense:@"Your license key" verificationDelegate:self];
 *    DynamsoftCameraEnhancer *dce = [[DynamsoftCameraEnhancer alloc] init];
 *    - (void)DCELicenseVerificationCallback:(bool)isSuccess error:(NSError * _Nullable)error
 *    {
 *        //TODO add your code for license verification
 *    }
 * @endcode
 */

- (void)DCELicenseVerificationCallback:(bool)isSuccess error:(NSError * _Nullable)error;

@end

NS_ASSUME_NONNULL_END
