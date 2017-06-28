//
//  DLFileCache.m
//  DLCache
//
//  Created by limingzou on 2017/5/18.
//  Copyright © 2017年 limingzou. All rights reserved.
//

#import "DLFileCache.h"
@interface DLFileCache()
{
    NSString *		_cachePath;
    NSString *		_cacheUser;
    NSFileManager *	_fileManager;
}
@end

@implementation DLFileCache

@synthesize cachePath = _cachePath;
@synthesize cacheUser = _cacheUser;

DEF_SINGLETON( DLFileCache );

- (id)init
{
    self = [super init];
    if ( self )
    {
        self.cacheUser = @"";
        self.cachePath = [NSString stringWithFormat:@"%@/%@/Cache/", [DLSandbox libCachePath], [DLVersion appVersion]];
        
        _fileManager = [[NSFileManager alloc] init];
    }
    return self;
}


- (NSString *)fileNameForKey:(NSString *)key
{
    NSString * pathName = nil;
    
    if ( self.cacheUser && [self.cacheUser length] )
    {
        pathName = [self.cachePath stringByAppendingFormat:@"/%@/", self.cacheUser];
    }
    else
    {
        pathName = self.cachePath;
    }
    
    if ( NO == [_fileManager fileExistsAtPath:pathName] )
    {
        [_fileManager createDirectoryAtPath:pathName
                withIntermediateDirectories:YES
                                 attributes:nil
                                      error:NULL];
    }
    
    return [pathName stringByAppendingString:key];
}

- (BOOL)hasObjectForKey:(id)key
{
    return [_fileManager fileExistsAtPath:[self fileNameForKey:key]];
}

- (id)objectForKey:(id)key
{
    return [NSData dataWithContentsOfFile:[self fileNameForKey:key]];
}

- (void)setObject:(id)object forKey:(id)key
{
    if ( nil == object )
    {
        [self removeObjectForKey:key];
    }
    else
    {
        NSData * data = [object asNSData];
        if ( data )
        {
            [data writeToFile:[self fileNameForKey:key]
                      options:NSDataWritingAtomic
                        error:NULL];
        }
    }
}

- (void)removeObjectForKey:(NSString *)key
{
    [_fileManager removeItemAtPath:[self fileNameForKey:key] error:nil];
}

- (void)removeAllObjects
{
    [_fileManager removeItemAtPath:_cachePath error:NULL];
    [_fileManager createDirectoryAtPath:_cachePath
            withIntermediateDirectories:YES
                             attributes:nil
                                  error:NULL];
}

- (id)objectForKeyedSubscript:(id)key
{
    return [self objectForKey:key];
}

- (void)setObject:(id)obj forKeyedSubscript:(id)key
{
    [self setObject:obj forKey:key];
}

- (unsigned long long)fileSize:(NSString *)path error:(NSError *)error
{
    if ([_fileManager fileExistsAtPath:path]){
        return [[_fileManager attributesOfItemAtPath:path error:nil] fileSize];
    }
    return 0;
}
- (float)folderSize:(NSString*)path error:(NSError *)error
{
    if ( NO == [_fileManager fileExistsAtPath:path]) return 0;
    NSEnumerator *childFilesEnumerator = [[_fileManager subpathsAtPath:path] objectEnumerator];
    NSString* fileName;
    long long folderSize = 0;
    while ((fileName = [childFilesEnumerator nextObject]) != nil){
        NSString* fileAbsolutePath = [path stringByAppendingPathComponent:fileName];
        folderSize += [self fileSize:fileAbsolutePath error:error];
    }
    return folderSize/(1024.0*1024.0);
}
@end
