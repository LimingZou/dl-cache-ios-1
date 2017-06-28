//
//  DLUserDefaults.m
//  DLCache
//
//  Created by limingzou on 2017/5/18.
//  Copyright © 2017年 limingzou. All rights reserved.
//

#import "DLUserDefaults.h"

@implementation DLUserDefaults

DEF_SINGLETON( BeeUserDefaults )

- (BOOL)hasObjectForKey:(id)key
{
    id value = [[NSUserDefaults standardUserDefaults] objectForKey:key];
    return value ? YES : NO;
}

- (id)objectForKey:(NSString *)key
{
    if ( nil == key )
        return nil;
    
    id value = [[NSUserDefaults standardUserDefaults] objectForKey:key];
    return value;
}

- (void)setObject:(id)value forKey:(NSString *)key
{
    if ( nil == key || nil == value )
        return;
    
    [[NSUserDefaults standardUserDefaults] setObject:value forKey:key];
    [[NSUserDefaults standardUserDefaults] synchronize];
}

- (void)removeObjectForKey:(NSString *)key
{
    if ( nil == key )
        return;
    
    [[NSUserDefaults standardUserDefaults] removeObjectForKey:key];
    [[NSUserDefaults standardUserDefaults] synchronize];
}

- (void)removeAllObjects
{
    [NSUserDefaults resetStandardUserDefaults];
}

- (id)objectForKeyedSubscript:(id)key
{
    return [self objectForKey:key];
}

- (void)setObject:(id)obj forKeyedSubscript:(id)key
{
    if ( obj )
    {
        [self setObject:obj forKey:key];
    }
    else
    {
        [self removeObjectForKey:key];
    }
}

@end
