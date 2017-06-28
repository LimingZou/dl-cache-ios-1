//
//  NSObject+DLKeychain.h
//  DLCache
//
//  Created by limingzou on 2017/5/18.
//  Copyright © 2017年 limingzou. All rights reserved.
//

#import "DLKeychain.h"

@interface NSObject (DLKeychain)

+ (NSString *)keychainRead:(NSString *)key;
+ (void)keychainWrite:(NSString *)value forKey:(NSString *)key;
+ (void)keychainDelete:(NSString *)key;

- (NSString *)keychainRead:(NSString *)key;
- (void)keychainWrite:(NSString *)value forKey:(NSString *)key;
- (void)keychainDelete:(NSString *)key;

@end
