//
//  NSObject+DLTicker.h
//  DLFoundation
//
//  Created by limingzou on 2017/5/12.
//  Copyright © 2017年 limingzou. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSObject (DLTicker)

- (void)observeTick;
- (void)unobserveTick;
- (void)handleTick:(NSTimeInterval)elapsed;

@end
