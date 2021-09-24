//
//  BPNetWorkAccessibilityUnity.h
//  XXXXXX
//
//  Created by Weiliam on 2021/9/16.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
extern NSString * const BPYNetworkAccessibilityChangedNotification;

typedef NS_ENUM(NSUInteger, BPYNetworkAccessibleState) {
    BPYNetworkChecking  = 0,
    BPYNetworkUnknown     ,
    BPYNetworkAccessible  ,
    BPYNetworkRestricted  ,
};

typedef void (^NetworkAccessibleStateNotifier)(BPYNetworkAccessibleState state);

@interface BPNetWorkAccessibilityUnity : NSObject

/**
 开启 BPNetWorkAccessibilityUnity
 */
+ (void)start;

/**
 停止 BPNetWorkAccessibilityUnity
 */
+ (void)stop;

/**
 当判断网络状态为 BPYNetworkRestricted 时，提示用户开启网络权限
 */
+ (void)setAlertEnable:(BOOL)setAlertEnable;

/**
  通过 block 方式监控网络权限变化。
 */
+ (void)setStateDidUpdateNotifier:(void (^)(BPYNetworkAccessibleState))block;

/**
 返回的是最近一次的网络状态检查结果，若距离上一次检测结果短时间内网络授权状态发生变化，该值可能会不准确。
 */
+ (BPYNetworkAccessibleState)currentState;

@end

NS_ASSUME_NONNULL_END
