//
//  NSObject+DLKeychain.m
//  DLCache
//
//  Created by limingzou on 2017/5/18.
//  Copyright © 2017年 limingzou. All rights reserved.
//

#import "NSObject+DLKeychain.h"

@implementation NSObject (DLKeychain)

+ (NSString *)keychainRead:(NSString *)key
{
    return [DLKeychain readValueForKey:key andDomain:[[self class] description]];
}

+ (void)keychainWrite:(NSString *)value forKey:(NSString *)key
{
    [DLKeychain writeValue:value forKey:key andDomain:[[self class] description]];
}

+ (void)keychainDelete:(NSString *)key
{
    [DLKeychain deleteValueForKey:key andDomain:[[self class] description]];
}

- (NSString *)keychainRead:(NSString *)key
{
    return [DLKeychain readValueForKey:key andDomain:[[self class] description]];
}

- (void)keychainWrite:(NSString *)value forKey:(NSString *)key
{
    [DLKeychain writeValue:value forKey:key andDomain:[[self class] description]];
}

- (void)keychainDelete:(NSString *)key
{
    [DLKeychain deleteValueForKey:key andDomain:[[self class] description]];
}

@end
