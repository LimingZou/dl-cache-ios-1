//
//  ViewController.m
//  dl-cache-ios-1
//
//  Created by limingzou on 2017/6/28.
//  Copyright © 2017年 limingzou. All rights reserved.
//

#import "ViewController.h"
#import "DLCache.h"
@interface ViewController ()
{
    DLFileCache * _fileCache;

}
@property (atomic, retain) DLFileCache * fileCache;
@end


@implementation ViewController

@synthesize fileCache = _fileCache;

- (void)viewDidLoad {
    [super viewDidLoad];
    
    _fileCache = [[DLFileCache alloc] init];
    _fileCache.cachePath = [NSString stringWithFormat:@"%@/ImageCache", [DLSandbox libCachePath]];
    _fileCache.cacheUser = @"user1";
    
    [self saveData:[NSData dataFromResource:@"icon_moreOperation_shareYouTube@2x.png"] forURL:@"test1"];
    
    //[self deleteImageForURL:@"test1"];
    
    NSLog(@"imageCacheUrl:%@",[self pathImageForURL:@"test1"]);

}
- (void)saveData:(NSData *)data forURL:(NSString *)string
{
    PERF_ENTER
    
    NSString * cacheKey = [string MD5];
    [self.fileCache setObject:data forKey:cacheKey];
    
    PERF_LEAVE
}

- (void)deleteImageForURL:(NSString *)string
{
    PERF_ENTER
    
    NSString * cacheKey = [string MD5];
    [self.fileCache removeObjectForKey:cacheKey];
    
    PERF_LEAVE
}

- (NSString *)pathImageForURL:(NSString *)string{
    NSString * cacheKey = [string MD5];
    return [self.fileCache fileNameForKey:cacheKey];
}

@end
