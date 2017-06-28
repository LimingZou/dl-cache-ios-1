//
//  DLMemoryCache.h
//  DLCache
//
//  Created by limingzou on 2017/5/18.
//  Copyright © 2017年 limingzou. All rights reserved.
//

#import "DLCacheProtocol.h"

@interface DLMemoryCache : NSObject<DLCacheProtocol>

@property (nonatomic, assign) BOOL					clearWhenMemoryLow;
@property (nonatomic, assign) NSUInteger			maxCacheCount;
@property (nonatomic, assign) NSUInteger			cachedCount;
@property (atomic, retain) NSMutableArray *			cacheKeys;
@property (atomic, retain) NSMutableDictionary *	cacheObjs;

AS_SINGLETON( DLMemoryCache );

@end
