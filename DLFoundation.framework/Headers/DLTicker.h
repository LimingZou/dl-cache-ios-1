//
//  DLTicker.h
//  DLFoundation
//
//  Created by limingzou on 2017/5/12.
//  Copyright © 2017年 limingzou. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <QuartzCore/QuartzCore.h>
#import <DLFoundation/DLSingleton.h>
@interface DLTicker : NSObject

@property (nonatomic, readonly)	CADisplayLink *		timer;
@property (nonatomic, readonly)	NSTimeInterval		timestamp;
@property (nonatomic, assign) NSTimeInterval		interval;

AS_SINGLETON( DLTicker )

- (void)addReceiver:(NSObject *)obj;
- (void)removeReceiver:(NSObject *)obj;

@end
