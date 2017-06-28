//
//  DLFileCache.h
//  DLCache
//
//  Created by limingzou on 2017/5/18.
//  Copyright © 2017年 limingzou. All rights reserved.
//

#import "DLCacheProtocol.h"

@interface DLFileCache : NSObject<DLCacheProtocol>

@property (nonatomic, retain) NSString *	cachePath;
@property (nonatomic, retain) NSString *	cacheUser;

AS_SINGLETON( DLFileCache );

- (NSString *)fileNameForKey:(NSString *)key; //if notfound and create folder
- (unsigned long long)fileSize:(NSString *)path error:(NSError *)error;
- (float)folderSize:(NSString*)path error:(NSError *)error;

@end
