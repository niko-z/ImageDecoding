//
//  Dynamsoft Camera Enhancer SDK
//
//  Copyright © 2021 Dynamsoft. All rights reserved.
//

#import <AVFoundation/AVFoundation.h>
#import <UIKit/UIKit.h>
#import "DCECameraView.h"
#import "DCEBase.h"

NS_ASSUME_NONNULL_BEGIN

@interface DynamsoftCameraEnhancer:NSObject

- (instancetype)initWithView:(DCECameraView *)view NS_SWIFT_NAME(init(view:));

+ (void)initLicense:(NSString*)license verificationDelegate:(id)connectionDelegate;

- (NSString*)getVersion;

- (EnumCameraState)getCameraState;

- (void)enableFeatures:(NSInteger)enumEnhancerFeatures error:(NSError * _Nullable * _Nullable)error;

- (void)disableFeatures:(NSInteger)enumEnhancerFeatures;

- (BOOL)isFeatureEnabled:(NSInteger)enumEnhancerFeatures;

- (DCEFrame*)getFrameFromBuffer:(BOOL)iskeep;

/// Resume camera
- (void)resume NS_SWIFT_NAME(resume());

/// Pause camera
- (void)pause NS_SWIFT_NAME(pause());

/// Add camera listener
/// @param listener Camera Listener
- (void)addListener:(nonnull id<DCEFrameListener>)listener NS_SWIFT_NAME(addListener(_:));

- (void)removeListener:(nonnull id<DCEFrameListener>)listener NS_SWIFT_NAME(removeListener(_:));

/// Set the torch state
- (void)turnOnTorch;

- (void)turnOffTorch;

/// Set zoom factor
/// @param factor set zoom factor
- (void)setZoom:(CGFloat)factor;

- (void)setFrameRate:(int)frameRate NS_SWIFT_NAME(setFrameRate(_:));

- (int)getFrameRate;

/// The value of this property is a CGPoint that determines the receiver's focus point of interest, if it has one. A value of (0,0) indicates that the camera should focus on the top left corner of the image, while a value of (1,1) indicates that it should focus on the bottom right. The default value is (0.5,0.5).
- (void)setFocus:(CGPoint)point NS_SWIFT_NAME(setFocus(_:));

- (NSArray<NSString*>*)getAllCameras;

- (void)selectCamera:(NSString*)cameraId error:(NSError * _Nullable * _Nullable)error;

- (NSString*)getSelectedCamera;

- (void)setResolution:(EnumResolution)resolution;

- (NSString*)getResolution;

- (void)updateAdvancedSettingsFromFile:(NSString*)filePath error:(NSError * _Nullable * _Nullable)error;

- (void)updateAdvancedSettingsFromString:(NSString*)params error:(NSError * _Nullable * _Nullable)error;

- (void)open;

- (void)close;

@end

NS_ASSUME_NONNULL_END
