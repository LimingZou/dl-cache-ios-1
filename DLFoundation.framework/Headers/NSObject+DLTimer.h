//
//  NSObject+DLTimer.h
//  DLFoundation
//
//  Created by limingzou on 2017/5/12.
//  Copyright © 2017年 limingzou. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSObject (DLTimer)

- (NSTimer *)timer:(NSTimeInterval)interval;
- (NSTimer *)timer:(NSTimeInterval)interval repeat:(BOOL)repeat;
- (NSTimer *)timer:(NSTimeInterval)interval repeat:(BOOL)repeat name:(NSString *)name;
- (void)cancelTimer:(NSString *)name;
- (void)cancelAllTimers;
- (void)handleTimer:(NSTimer *)timer;

@end
