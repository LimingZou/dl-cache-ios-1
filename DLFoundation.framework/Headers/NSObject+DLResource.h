//
//  NSObject+DLResource.h
//  DLFoundation
//
//  Created by limingzou on 2017/5/12.
//  Copyright © 2017年 limingzou. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSObject (DLResource)

+ (NSString *)stringFromResource:(NSString *)resName;
- (NSString *)stringFromResource:(NSString *)resName;
+ (NSData *)dataFromResource:(NSString *)resName;
- (NSData *)dataFromResource:(NSString *)resName;
+ (id)objectFromResource:(NSString *)resName;

@end
