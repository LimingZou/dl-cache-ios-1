//
//  DLThread.h
//  DLFoundation
//
//  Created by limingzou on 2017/5/12.
//  Copyright © 2017年 limingzou. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <DLFoundation/DLSingleton.h>

#pragma mark -

@class DLThread;
@compatibility_alias DLTaskQueue DLThread;

typedef DLThread * (^DLThreadBlock)( dispatch_block_t block );

#pragma mark -

#define FOREGROUND_BEGIN		[DLThread enqueueForeground:^{
#define FOREGROUND_BEGIN_(x)	[DLThread enqueueForegroundWithDelay:(dispatch_time_t)x block:^{
#define FOREGROUND_COMMIT		}];

#define BACKGROUND_BEGIN		[DLThread enqueueBackground:^{
#define BACKGROUND_BEGIN_(x)	[DLThread enqueueBackgroundWithDelay:(dispatch_time_t)x block:^{
#define BACKGROUND_COMMIT		}];

#pragma mark -

@interface DLThread : NSObject

@property (nonatomic, readonly) DLThreadBlock	MAIN;
@property (nonatomic, readonly) DLThreadBlock	FORK;

AS_SINGLETON( DLThread )

+ (dispatch_queue_t)foreQueue;
+ (dispatch_queue_t)backQueue;

+ (void)enqueueForeground:(dispatch_block_t)block;
+ (void)enqueueBackground:(dispatch_block_t)block;
+ (void)enqueueForegroundWithDelay:(dispatch_time_t)ms block:(dispatch_block_t)block;
+ (void)enqueueBackgroundWithDelay:(dispatch_time_t)ms block:(dispatch_block_t)block;

@end

