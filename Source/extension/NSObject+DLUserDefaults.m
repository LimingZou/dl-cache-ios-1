//
//  NSObject+DLUserDefaults.m
//  DLCache
//
//  Created by limingzou on 2017/5/18.
//  Copyright © 2017年 limingzou. All rights reserved.
//

#import "NSObject+DLUserDefaults.h"

@implementation NSObject (DLUserDefaults)
+ (NSString *)persistenceKey:(NSString *)key
{
    if ( key )
    {
        key = [NSString stringWithFormat:@"%@.%@", [self description], key];
    }
    else
    {
        key = [NSString stringWithFormat:@"%@", [self description]];
    }
    
    key = [key stringByReplacingOccurrencesOfString:@"." withString:@"_"];
    key = [key stringByReplacingOccurrencesOfString:@"-" withString:@"_"];
    key = [key stringByReplacingOccurrencesOfString:@"/" withString:@"_"];
    
    return key.uppercaseString;
}

+ (id)userDefaultsRead:(NSString *)key
{
    if ( nil == key )
        return nil;
    
    key = [self persistenceKey:key];
    
    return [[DLUserDefaults sharedInstance] objectForKey:key];
}

+ (void)userDefaultsWrite:(id)value forKey:(NSString *)key
{
    if ( nil == key || nil == value )
        return;
    
    key = [self persistenceKey:key];
    
    [[DLUserDefaults sharedInstance] setObject:value forKey:key];
}

+ (void)userDefaultsRemove:(NSString *)key
{
    if ( nil == key )
        return;
    
    key = [self persistenceKey:key];
    
    [[DLUserDefaults sharedInstance] removeObjectForKey:key];
}

- (id)userDefaultsRead:(NSString *)key
{
    return [[self class] userDefaultsRead:key];
}

- (void)userDefaultsWrite:(id)value forKey:(NSString *)key
{
    [[self class] userDefaultsWrite:value forKey:key];
}

- (void)userDefaultsRemove:(NSString *)key
{
    [[self class] userDefaultsRemove:key];
}

+ (id)readObject
{
    return [self readObjectForKey:nil];
}

+ (id)readObjectForKey:(NSString *)key
{
    key = [self persistenceKey:key];
    
    id value = [[DLUserDefaults sharedInstance] objectForKey:key];
    if ( value )
    {
        return [self objectFromAny:value];
    }
    
    return nil;
}

+ (void)saveObject:(id)obj
{
    [self saveObject:obj forKey:nil];
}

+ (void)saveObject:(id)obj forKey:(NSString *)key
{
    if ( nil == obj )
        return;
    
    key = [self persistenceKey:key];
    
    NSString * value = [obj objectToString];
    if ( value && value.length )
    {
        [[DLUserDefaults sharedInstance] setObject:value forKey:key];
    }
    else
    {
        [[DLUserDefaults sharedInstance] removeObjectForKey:key];
    }
}

+ (void)removeObject
{
    [self removeObjectForKey:nil];
}

+ (void)removeObjectForKey:(NSString *)key
{
    key = [self persistenceKey:key];
    
    [[DLUserDefaults sharedInstance] removeObjectForKey:key];
}


- (void)saveToUserDefaults:(NSString *)key
{
    if ( nil == key )
        return;
    
    NSString * jsonString = [self objectToString];
    if ( nil == jsonString || 0 == jsonString.length )
        return;
    
    [self userDefaultsWrite:jsonString forKey:key];
}

- (void)removeFromUserDefaults:(NSString *)key
{
    [[self class] userDefaultsRemove:key];
}


@end
