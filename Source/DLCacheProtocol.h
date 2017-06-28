//
//  DLCacheProtocol.h
//  DLCache
//
//  Created by limingzou on 2017/5/18.
//  Copyright © 2017年 limingzou. All rights reserved.
//

#import <DLFoundation/DLFoundation.h>

@protocol DLCacheProtocol <NSObject>

- (BOOL)hasObjectForKey:(id)key; //file exists at path

- (id)objectForKey:(id)key;
- (void)setObject:(id)object forKey:(id)key;

- (void)removeObjectForKey:(id)key;
- (void)removeAllObjects;

- (id)objectForKeyedSubscript:(id)key;
- (void)setObject:(id)obj forKeyedSubscript:(id)key;

@end
