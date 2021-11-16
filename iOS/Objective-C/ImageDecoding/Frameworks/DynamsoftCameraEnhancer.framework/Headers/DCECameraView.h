//
//  Dynamsoft Camera Enhancer SDK
//
//  Copyright © 2021 Dynamsoft. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <UIKit/UIView.h>
#import <UIKit/UIApplication.h>
#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

NS_ASSUME_NONNULL_BEGIN
@class DCECameraView;

@interface DCECameraView: UIView<CALayerDelegate>

@property (assign, nonatomic) BOOL overlayVisible;

@property (assign, nonatomic) BOOL viewfinderVisible;

+ (instancetype)cameraWithFrame:(CGRect)frame NS_SWIFT_NAME(init(frame:));

- (instancetype)initWithFrame:(CGRect)frame;

- (void)setOverlayColor:(UIColor *)stroke fill:(UIColor*)fill;

- (void)setViewfinder:(CGFloat)left top:(CGFloat)top right:(CGFloat)right bottom:(CGFloat)bottom error:(NSError * _Nullable * _Nullable)error;

@end
NS_ASSUME_NONNULL_END
